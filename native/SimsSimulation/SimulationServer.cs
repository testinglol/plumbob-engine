using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text.Json;
using System.Threading.Channels;
using FSO.Content;
using FSO.Files.Formats.IFF;
using FSO.SimAntics;
using FSO.SimAntics.Engine.TSOTransaction;
using FSO.SimAntics.Engine;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics.Entities;
using FSO.SimAntics.Marshals;
using FSO.SimAntics.Model;
using FSO.SimAntics.Primitives;
using FSO.SimAntics.NetPlay.Drivers;
using FSO.SimAntics.NetPlay.Model;
using FSO.SimAntics.NetPlay.Model.Commands;
using FSO.SimAntics.Utils;
using FSO.LotView.Model;

internal sealed class SimulationServer
{
    private VM vm;
    private readonly StreamWriter output;
    private readonly string session;
    private readonly string profile;
    private readonly string packFingerprint;
    private short house;
    private readonly NativeLotTravel travel;
    private readonly NativeArchitectureHistory architectureHistory = new();
    private long updates;
    private long revision;
    private long animationSequence;
    private bool streaming;
    private bool resetTiming;
    private int architecturePending;
    private bool architectureHistoryPending;
    private FAMI? historyFamily;
    private LotSceneExporter exporter;
    private readonly PanelResources panelResources;
    private readonly NativeAudio audio;
    private short selectedSim;
    private bool running = true;
    private bool wallsUp;
    private string wallMode = "down";
    private bool editingView;
    private readonly NativeCutaway cutaway = new();
    private sbyte viewLevel = 1;
    private int cameraOrientation;
    private bool roofsVisible;
    private long dialogSequence;
    private bool dialogsChanged;
    private readonly List<DialogSnapshot> dialogs = [];
    private static readonly JsonSerializerOptions Json = new() { PropertyNamingPolicy = JsonNamingPolicy.CamelCase };
    private record PhoneBookContact(short NeighborId, string Name);
    private record PhoneBookFamily(short FamilyId, string Name, PhoneBookContact[] Contacts);
    private record DialogSnapshot(string Token, bool Blocking, short Caller, short Icon, byte Kind, string Title, string Message, string? Yes, string? No, string? Cancel, PhoneBookFamily[]? PhoneBook = null);
    private record SaveEnvelope(int SchemaVersion, string Engine, string PackFingerprint, short House, long Updates, string State, DialogSnapshot[]? Dialogs = null, int ResumeSpeed = 0, NativeLotTravel.Snapshot? Travel = null,
        NativeSaveCompatibility.PackRecord[]? Packs = null, Dictionary<string, NativePluginHost.PluginSaveRecord>? Plugins = null, int Neighborhood = 1);
    private const int SaveSchemaVersion = 2;
    private readonly NativePluginHost plugins;
    private bool freeWillEnabled = true;
    private readonly Dictionary<short, short> savedAutonomy = [];
    private const string EngineVersion = "freeso-f86bbd34-native-v2";

    public SimulationServer(VM vm, StreamWriter output, string session, string profile, string game, short house)
    {
        this.vm = vm;
        this.output = output;
        this.session = session;
        this.profile = profile;
        this.house = house;
        travel = new NativeLotTravel(NativeNeighborhoods.UserData(profile), house);
        exporter = new LotSceneExporter(vm, Path.Combine(session, "scene"));
        panelResources = new PanelResources(Path.Combine(session, "scene"));
        audio = new NativeAudio(Path.Combine(session, "audio"), profile, Write);
        vm.OnDialog += CaptureDialog;
        vm.OnRequestLotSwitch += RequestLotSwitch;
        Directory.CreateDirectory(session);
        var metadata = Path.Combine(game, ".native-pack-stack.json");
        packFingerprint = File.Exists(metadata) ? JsonDocument.Parse(File.ReadAllText(metadata)).RootElement.GetProperty("fingerprint").GetString()! : "unmounted-base-1.90";
        // Profiles live at DATA_ROOT/runtime/native-profiles/ID; the plugin trust store is under DATA_ROOT/Settings.
        var dataRoot = Path.GetFullPath(Path.Combine(profile, "..", "..", ".."));
        plugins = NativePluginHost.Create(game, dataRoot, Write, () => this.vm, () => this.house);
        selectedSim = vm.Entities.OfType<VMAvatar>().FirstOrDefault(IsHousehold)?.ObjectID ?? 0;
    }

    internal static VM CreateVM()
    {
        var vm = new VM(new VMContext(null), new VMServerDriver(new VMTS1GlobalLinkStub()), new VMNullHeadlineProvider());
        vm.Init();
        return vm;
    }

    public static VM LoadHouse(string userData, short house, bool activateFamily)
    {
        var vm = CreateVM();
        var family = Content.Get().Neighborhood.GetFamilyForHouse(house);
        var iff = new IffFile(NativeHouseSave.HousePath(userData, house));
        if (NativeHouseSave.Restore(vm, iff, family, activateFamily)) return vm;
        if (activateFamily)
        {
            family?.SelectWholeFamily();
            vm.TS1State.ActivateFamily(vm, family);
        }
        new VMTS1Activator(vm, null, house).LoadFromIff(iff);
        return vm;
    }

    public async Task Run()
    {
        EnsureAvatarIdentifiers();
        historyFamily = vm.TS1State.CurrentFamily;
        vm.SpeedMultiplier = 0;
        for (var index = 0; index < 2; index++) { if (vm.GlobalBlockingDialog != null) break; vm.SpeedMultiplier = 1; vm.Update(); updates++; }
        if (vm.GlobalBlockingDialog == null) vm.SpeedMultiplier = 0;
        else vm.LastSpeedMultiplier = 0;
        selectedSim = vm.Entities.OfType<VMAvatar>().FirstOrDefault(IsHousehold)?.ObjectID ?? 0;
        if (selectedSim != 0) vm.MyUID = SelectedAvatar().PersistID;
        Write(new { type = "hello", protocolVersion = 1, architecture = RuntimeInformation.ProcessArchitecture.ToString(), engine = EngineVersion,
            packFingerprint, languageCode = (byte)STR.DefaultLangCode, saveSchemaVersion = SaveSchemaVersion,
            plugins = plugins.Statuses, pluginPanels = plugins.Panels.Select(panel => new { panel.PackId, panel.Id, panel.Path }).ToArray(),
            commands = new[] { "state", "audio", "audioEvent", "audioStopOwner", "audioEnded", "audioState", "audioVolume", "catalog", "catalogPage", "buildCatalogPage", "stream", "sceneAck", "speed", "step", "scene", "view", "cameraOrientation", "walls", "cutaway", "level", "roofs", "roof", "undo", "redo", "selectSim", "menu", "interact", "cancelAction", "dialogResponse", "appearanceCatalog", "appearancePreview", "outfitChoices", "outfitPreview", "createHousehold", "moveInFamily", "save", "load", "freeWill", "saveBackups", "restoreBackup", "plugins", "pluginPanels", "pluginAction", "neighborhood", "architecture", "architectureBatch", "buyObject", "moveObject", "sellObject", "previewObject", "quit" } });
        ExportScene();
        var channel = Channel.CreateBounded<string>(new BoundedChannelOptions(128) { SingleReader = true, SingleWriter = true });
        var read = Task.Run(async () =>
        {
            try
            {
                while (await Console.In.ReadLineAsync() is { } line)
                {
                    if (line.Length > 1_048_576) line = "{\"op\":\"invalidOversizedRequest\"}";
                    await channel.Writer.WriteAsync(line);
                }
            }
            finally { channel.Writer.TryComplete(); }
        });
        var watch = Stopwatch.StartNew();
        var nextUpdate = watch.Elapsed.TotalSeconds;
        var nextScene = nextUpdate + 1;
        var nextAnimation = nextUpdate;
        var nextStaticScene = nextUpdate + 5;
        while (running)
        {
            while (channel.Reader.TryRead(out var line)) Handle(line);
            if (channel.Reader.Completion.IsCompleted) break;
            EnsureHistoryFamily();
            var now = watch.Elapsed.TotalSeconds;
            if (resetTiming) { nextUpdate = now; nextAnimation = now; resetTiming = false; }
            if (now >= nextUpdate)
            {
                var advancing = vm.SpeedMultiplier > 0;
                vm.Update();
                ApplyLotSwitch();
                ReconcileSelection();
                audio.Tick(vm);
                if (advancing) { updates++; plugins.Tick(updates); }
                if (architecturePending > 0 && --architecturePending == 0)
                {
                    if (architectureHistoryPending)
                    {
                        InvalidateArchitectureHistory();
                    }
                    ExportScene();
                }
                nextUpdate += 1.0 / 60;
                if (now - nextUpdate > 0.25) nextUpdate = now;
            }
            if (dialogsChanged)
            {
                dialogsChanged = false;
                Write(new { type = "state", state = State() });
            }
            if (now >= nextScene)
            {
                if (vm.SpeedMultiplier > 0) { if (streaming) Write(new { type = "state", state = State() }); else ExportScene(); }
                nextScene = now + 1;
            }
            if (streaming && vm.SpeedMultiplier > 0 && now >= nextStaticScene)
            {
                ExportScene();
                nextStaticScene = now + 5;
            }
            if (streaming && now >= nextAnimation)
            {
                if (vm.SpeedMultiplier > 0)
                    Write(new { type = "animation", frame = exporter.Animation(revision, ++animationSequence, updates) });
                nextAnimation += 1.0 / 30;
                if (now - nextAnimation > 0.1) nextAnimation = now;
            }
            await Task.Delay(2);
        }
        vm.NativeAudioEnabled = false;
        audio.Dispose();
        plugins.Dispose();
        Write(new { type = "stopped" });
    }

    private void Handle(string line)
    {
        string? id = null;
        string? operation = null;
        try
        {
            EnsureHistoryFamily();
            using var document = JsonDocument.Parse(line);
            var request = document.RootElement;
            id = request.TryGetProperty("id", out var requestID) ? requestID.ToString() : null;
            operation = request.GetProperty("op").GetString();
            EnsureAvatarIdentifiers();
            object? result = null;
            switch (operation)
            {
                case "audio":
                    audio.Enable(request.GetProperty("enabled").GetBoolean());
                    vm.NativeAudioEnabled = audio.Enabled;
                    foreach (var entity in vm.SoundEntities) entity.SoundThreads.Clear();
                    vm.SoundEntities.Clear();
                    result = new { enabled = audio.Enabled };
                    break;
                case "audioEvent":
                    var audioOwnerID = request.TryGetProperty("ownerID", out var audioOwnerValue) ? audioOwnerValue.GetInt16() : (short?)null;
                    VMEntity? soundOwner = null;
                    int? externalAudioOwner = null;
                    if (audioOwnerID == NativeAudio.NeighborhoodOwnerID) externalAudioOwner = audioOwnerID;
                    else if (audioOwnerID.HasValue)
                    {
                        soundOwner = vm.GetObjectById(audioOwnerID.Value);
                        if (soundOwner == null || soundOwner.Dead || soundOwner.Thread == null) throw new ArgumentException("Invalid audio owner");
                    }
                    result = new { played = audio.Play(request.GetProperty("name").GetString()!, soundOwner, externalAudioOwner) };
                    break;
                case "audioStopOwner":
                    var audioOwnerToStop = request.GetProperty("ownerID").GetInt16();
                    if (audioOwnerToStop != NativeAudio.NeighborhoodOwnerID) throw new ArgumentException("Invalid external audio owner");
                    audio.RemoveOwner(audioOwnerToStop);
                    result = new { removed = true };
                    break;
                case "audioVolume": audio.SetVolume(request.GetProperty("group").GetString()!, request.GetProperty("volume").GetSingle()); result = audio.State(); break;
                case "audioState": result = audio.State(); break;
                case "audioEnded": audio.End(request.GetProperty("voice").GetInt64()); result = new { accepted = true }; break;
                case "state": result = State(); break;
                case "freeWill":
                    freeWillEnabled = request.GetProperty("enabled").GetBoolean();
                    ApplyFreeWill();
                    result = new { enabled = freeWillEnabled };
                    break;
                case "plugins": result = new { plugins = plugins.Statuses, panels = plugins.Panels }; break;
                case "pluginPanels": result = new { panels = plugins.PanelState() }; break;
                case "pluginAction":
                    result = plugins.PanelAction(request.GetProperty("packId").GetString() ?? "", request.GetProperty("panelId").GetString() ?? "",
                        request.GetProperty("action").GetString() ?? "");
                    break;
                case "saveBackups":
                    var backupSlot = request.GetProperty("slot").GetString() ?? "";
                    SavePath(backupSlot);
                    result = new { slot = backupSlot, backups = NativeSaveCompatibility.List(profile, StorageSlot(backupSlot)) };
                    break;
                case "restoreBackup":
                    var restoreSlot = request.GetProperty("slot").GetString() ?? "";
                    result = NativeSaveCompatibility.Restore(profile, StorageSlot(restoreSlot), SavePath(restoreSlot), request.GetProperty("backup").GetString() ?? "");
                    break;
                case "stream":
                    streaming = request.GetProperty("enabled").GetBoolean();
                    resetTiming = true;
                    ExportScene();
                    result = new { enabled = streaming, framesPerSecond = 30 };
                    break;
                case "catalog":
                    result = new { floors = Content.Get().WorldFloors.Entries.OrderBy(pair => pair.Key).Select(pair => new { id = pair.Key, file = pair.Value.FileName, pair.Value.Name, pair.Value.Price }).ToArray(),
                        walls = Content.Get().WorldWalls.Entries.OrderBy(pair => pair.Key).Select(pair => new { id = pair.Key, file = pair.Value.FileName, pair.Value.Name, pair.Value.Price }).ToArray(),
                        objects = Content.Get().WorldCatalog.All().Select(item => new { guid = item.GUID, item.Name, item.CatalogName, item.Price, item.Category }).ToArray() };
                    break;
                case "catalogPage": result = CatalogPage(request); break;
                case "buildCatalogPage": result = BuildCatalogPage(request); break;
                case "sceneAck":
                    var acknowledged = request.GetProperty("revision").GetInt64();
                    if (acknowledged < 1 || acknowledged > revision) throw new ArgumentException("Invalid scene acknowledgement");
                    foreach (var snapshot in Directory.EnumerateFiles(Path.Combine(session, "scene"), "scene-*.json"))
                        if (long.TryParse(Path.GetFileNameWithoutExtension(snapshot).AsSpan(6), out var number) && number < acknowledged - 1) File.Delete(snapshot);
                    break;
                case "speed":
                    var speed = request.GetProperty("value").GetInt32();
                    if (speed is not (0 or 1 or 3 or 10)) throw new ArgumentException("Speed must be 0, 1, 3 or 10");
                    if (vm.GlobalBlockingDialog != null) throw new InvalidOperationException("Answer the active game dialog before changing speed");
                    vm.SpeedMultiplier = speed;
                    resetTiming = true;
                    result = State();
                    break;
                case "step":
                    var count = request.GetProperty("count").GetInt32();
                    if (count is < 1 or > 10000) throw new ArgumentException("Step count must be 1..10000");
                    if (vm.GlobalBlockingDialog != null) throw new InvalidOperationException("Answer the active game dialog before stepping");
                    var previous = vm.SpeedMultiplier;
                    resetTiming = true;
                    try { vm.SpeedMultiplier = 1; for (var i = 0; i < count; i++) { vm.Update(); audio.Tick(vm); updates++; if (travel.Pending || vm.GlobalBlockingDialog != null) break; } }
                    finally { if (vm.GlobalBlockingDialog == null) vm.SpeedMultiplier = previous; else vm.LastSpeedMultiplier = previous; }
                    ApplyLotSwitch();
                    ReconcileSelection();
                    result = State();
                    ExportScene();
                    break;
                case "scene": result = ExportScene(); break;
                case "roofs":
                    roofsVisible = request.GetProperty("visible").GetBoolean();
                    if (roofsVisible)
                    {
                        for (int story = 0; story < vm.Context.Architecture.Stories; story++)
                            if (vm.Context.Architecture.Floors[story].Any(tile => tile.Pattern != 0) || vm.Context.Architecture.Walls[story].Any(tile => tile.Segments != 0)) viewLevel = (sbyte)(story + 1);
                        wallsUp = true;
                        wallMode = "up";
                    }
                    ExportScene();
                    result = State();
                    break;
                case "roof":
                    EnsureObjectEditing();
                    var roofStyle = request.GetProperty("style").GetUInt32();
                    var roofPitch = request.GetProperty("pitch").GetSingle();
                    if (!float.IsFinite(roofPitch) || roofPitch < 0 || roofPitch > 1.25f || roofStyle >= Content.Get().WorldRoofs.Count) throw new ArgumentException("Invalid roof style or pitch");
                    architectureHistory.Begin(vm);
                    try
                    {
                        if (!new VMNetSetRoofCmd { Style = roofStyle, Pitch = roofPitch }.Execute(vm, SelectedAvatar())) throw new InvalidOperationException("Simulation rejected roof settings");
                        architectureHistory.Commit(vm);
                    }
                    catch { architectureHistory.Invalidate(); throw; }
                    ExportScene();
                    result = State();
                    break;
                case "level":
                    var requestedLevel = request.GetProperty("value").GetSByte();
                    if (requestedLevel < 1 || requestedLevel > vm.Context.Architecture.Stories) throw new ArgumentException("Story is outside the lot");
                    viewLevel = requestedLevel;
                    cutaway.Reset();
                    roofsVisible = false;
                    ExportScene();
                    result = State();
                    break;
                case "view":
                    var editing = request.GetProperty("editing").GetBoolean();
                    if (editingView != editing) { editingView = editing; ExportScene(); }
                    result = State();
                    break;
                case "cameraOrientation":
                    var requestedOrientation = request.GetProperty("value").GetInt32();
                    if (requestedOrientation < 0 || requestedOrientation > 3) throw new ArgumentException("Invalid camera orientation");
                    if (cameraOrientation != requestedOrientation)
                    {
                        cameraOrientation = requestedOrientation;
                        cutaway.Reset();
                        ExportScene();
                    }
                    result = State();
                    break;
                case "walls":
                    var mode = request.TryGetProperty("mode", out var requestedMode) ? requestedMode.GetString() : request.GetProperty("up").GetBoolean() ? "up" : "down";
                    if (mode is not ("up" or "down" or "cutaway")) throw new ArgumentException("Invalid wall mode");
                    wallMode = mode;
                    wallsUp = mode == "up";
                    roofsVisible = false;
                    if (mode == "cutaway")
                    {
                        var avatarPosition = SelectedAvatar().Position;
                        cutaway.Hover(vm, viewLevel, Math.Clamp(avatarPosition.TileX, 0, vm.Context.Architecture.Width - 1), Math.Clamp(avatarPosition.TileY, 0, vm.Context.Architecture.Height - 1));
                    }
                    ExportScene();
                    result = State();
                    break;
                case "cutaway":
                    if (wallMode != "cutaway") throw new InvalidOperationException("Select cutaway wall mode first");
                    var hoverX = request.GetProperty("x").GetInt32();
                    var hoverY = request.GetProperty("y").GetInt32();
                    if (hoverX < 0 || hoverY < 0 || hoverX >= vm.Context.Architecture.Width || hoverY >= vm.Context.Architecture.Height) throw new ArgumentException("Cutaway hover is outside the lot");
                    var priorCuts = cutaway.Mask(vm, viewLevel, wallMode, (FSO.LotView.WorldRotation)cameraOrientation);
                    cutaway.Hover(vm, viewLevel, hoverX, hoverY);
                    if (!priorCuts.SequenceEqual(cutaway.Mask(vm, viewLevel, wallMode, (FSO.LotView.WorldRotation)cameraOrientation))) ExportScene();
                    result = State();
                    break;
                case "selectSim":
                    var selection = vm.GetObjectById(request.GetProperty("objectID").GetInt16()) as VMAvatar;
                    if (selection == null || !IsHousehold(selection)) throw new ArgumentException("Select a Sim in the active household");
                    selectedSim = selection.ObjectID;
                    vm.MyUID = SelectedAvatar().PersistID;
                    vm.SetGlobalValue(3, selectedSim);
                    result = State();
                    break;
                case "menu":
                    var target = Target(request);
                    result = target.GetPieMenu(vm, SelectedAvatar(), false, true).Select(entry => new { entry.Name, interaction = entry.ID, entry.Param0, entry.Global }).ToArray();
                    break;
                case "interact":
                    if (vm.GlobalBlockingDialog != null) throw new InvalidOperationException("Answer the active game dialog before queuing an interaction");
                    var callee = Target(request);
                    var avatar = SelectedAvatar();
                    var interaction = request.GetProperty("interaction").GetByte();
                    var param0 = request.TryGetProperty("param0", out var param) ? param.GetInt16() : (short)0;
                    var global = request.TryGetProperty("global", out var isGlobal) && isGlobal.GetBoolean();
                    var offered = callee.GetPieMenu(vm, avatar, false, true);
                    if (!offered.Any(entry => entry.ID == interaction && entry.Param0 == param0 && entry.Global == global)) throw new ArgumentException("Interaction is not currently available");
                    vm.SendCommand(new VMNetInteractionCmd { CallerID = avatar.ObjectID, CalleeID = callee.ObjectID, Interaction = interaction, Param0 = param0, Global = global });
                    result = new { queued = true };
                    break;
                case "dialogResponse": result = RespondDialog(request); resetTiming = true; break;
                case "appearanceCatalog": result = AppearanceCatalog(request); break;
                case "outfitChoices":
                    var outfitContext = NativeOutfitPicker.Find(vm) ?? throw new InvalidOperationException("No wardrobe or pet choice is waiting");
                    result = new { pet = outfitContext.Pet, outfitType = outfitContext.OutfitType, choices = NativeOutfitPicker.Choices(outfitContext) };
                    break;
                case "outfitPreview":
                    result = NativeOutfitPicker.Preview(session, NativeOutfitPicker.Find(vm) ?? throw new InvalidOperationException("No wardrobe or pet choice is waiting"),
                        request.GetProperty("index").GetInt32());
                    break;
                case "appearancePreview": result = NativeHouseholdAppearancePreview.Export(
                    session,
                    request.GetProperty("gender").GetString() ?? "",
                    request.GetProperty("age").GetString() ?? "",
                    request.GetProperty("skin").GetString() ?? "",
                    request.GetProperty("headChoice").GetString() ?? "",
                    request.GetProperty("bodyChoice").GetString() ?? ""); break;
                case "createHousehold": result = CreateHousehold(request); resetTiming = true; break;
                case "moveInFamily": result = MoveInFamily(request); resetTiming = true; break;
                case "cancelAction":
                    if (vm.GlobalBlockingDialog != null) throw new InvalidOperationException("Answer the active game dialog before cancelling an action");
                    var caller = SelectedAvatar();
                    if (request.GetProperty("objectID").GetInt16() != caller.ObjectID) throw new ArgumentException("Action belongs to another Sim");
                    var token = request.GetProperty("token").GetString();
                    var action = caller.Thread.Queue.SingleOrDefault(item => panelResources.Token(item) == token);
                    if (action == null || !CanCancel(action)) throw new ArgumentException("Action is no longer cancellable");
                    if (!new VMNetInteractionCancelCmd { ActionUID = action.UID }.Execute(vm, caller)) throw new InvalidOperationException("Simulation rejected action cancellation");
                    result = State();
                    break;
                case "architecture":
                    EnsureObjectEditing();
                    var typeName = request.GetProperty("command").GetString();
                    if (!Enum.TryParse<VMArchitectureCommandType>(typeName, false, out var type) || !Enum.IsDefined(type)) throw new ArgumentException("Unknown architecture command");
                    var command = new VMArchitectureCommand { Type = type, x = request.GetProperty("x").GetInt32(), y = request.GetProperty("y").GetInt32(), level = request.GetProperty("level").GetSByte(),
                        x2 = request.GetProperty("x2").GetInt32(), y2 = request.GetProperty("y2").GetInt32(), pattern = request.GetProperty("pattern").GetUInt16(), style = request.GetProperty("style").GetUInt16() };
                    if (command.x < 0 || command.y < 0 || command.x >= vm.Context.Architecture.Width || command.y >= vm.Context.Architecture.Height || command.level < 1 || command.level > vm.Context.Architecture.Stories || Math.Abs((long)command.x2) > 128 || Math.Abs((long)command.y2) > 128) throw new ArgumentException("Architecture command is outside the lot");
                    if (vm.Context.Architecture.OutsideClip((short)command.x, (short)command.y, command.level)) throw new ArgumentException("Architecture command starts outside the buildable area");
                    ValidateArchitectureCommands([command]);
                    architectureHistory.Begin(vm);
                    try
                    {
                        vm.SendCommand(new VMNetArchitectureCmd { Commands = [command], OnExecuted = CompleteArchitectureHistory });
                        architectureHistoryPending = true;
                    }
                    catch { architectureHistory.Invalidate(); throw; }
                    architecturePending = 120;
                    result = new { queued = true };
                    break;
                case "architectureBatch":
                    EnsureObjectEditing();
                    var commandsElement = request.GetProperty("commands");
                    var maximumCommands = Math.Min(4096, vm.Context.Architecture.Width * vm.Context.Architecture.Height);
                    if (commandsElement.ValueKind != JsonValueKind.Array || commandsElement.GetArrayLength() < 1 || commandsElement.GetArrayLength() > maximumCommands) throw new ArgumentException($"Architecture batch must contain 1 to {maximumCommands} commands");
                    var commands = new List<VMArchitectureCommand>();
                    foreach (var batchItem in commandsElement.EnumerateArray())
                    {
                        var batchTypeName = batchItem.GetProperty("command").GetString();
                        if (!Enum.TryParse<VMArchitectureCommandType>(batchTypeName, false, out var batchType) || !Enum.IsDefined(batchType)) throw new ArgumentException("Unknown architecture command");
                        var batchCommand = new VMArchitectureCommand { Type = batchType, x = batchItem.GetProperty("x").GetInt32(), y = batchItem.GetProperty("y").GetInt32(), level = batchItem.GetProperty("level").GetSByte(),
                            x2 = batchItem.GetProperty("x2").GetInt32(), y2 = batchItem.GetProperty("y2").GetInt32(), pattern = batchItem.GetProperty("pattern").GetUInt16(), style = batchItem.GetProperty("style").GetUInt16() };
                        if (batchCommand.x < 0 || batchCommand.y < 0 || batchCommand.x >= vm.Context.Architecture.Width || batchCommand.y >= vm.Context.Architecture.Height || batchCommand.level < 1 || batchCommand.level > vm.Context.Architecture.Stories || Math.Abs((long)batchCommand.x2) > 128 || Math.Abs((long)batchCommand.y2) > 128) throw new ArgumentException("Architecture command is outside the lot");
                        if (vm.Context.Architecture.OutsideClip((short)batchCommand.x, (short)batchCommand.y, batchCommand.level)) throw new ArgumentException("Architecture command starts outside the buildable area");
                        commands.Add(batchCommand);
                    }
                    ValidateArchitectureCommands(commands);
                    architectureHistory.Begin(vm);
                    try
                    {
                        vm.SendCommand(new VMNetArchitectureCmd { Commands = commands, OnExecuted = CompleteArchitectureHistory });
                        architectureHistoryPending = true;
                    }
                    catch { architectureHistory.Invalidate(); throw; }
                    architecturePending = 120;
                    result = new { queued = true, count = commands.Count };
                    break;
                case "previewObject":
                    EnsureObjectEditing();
                    var previewPosition = ObjectPosition(request);
                    var hasGuid = request.TryGetProperty("guid", out var previewGuid);
                    var hasObject = request.TryGetProperty("objectID", out var previewObject);
                    if (hasGuid == hasObject) throw new ArgumentException("Supply either a catalog GUID or an object ID");
                    uint? checkedGuid = null;
                    short? checkedObject = null;
                    if (hasGuid)
                    {
                        checkedGuid = previewGuid.GetUInt32();
                        var previewItem = Content.Get().WorldCatalog.GetItemByGUID(checkedGuid.Value);
                        if (previewItem == null || Content.Get().WorldObjects.Get(checkedGuid.Value) == null) throw new ArgumentException("Object is not in the loaded catalog");
                        if (previewItem.Value.Price > vm.TS1State.CurrentFamily!.Budget) throw new InvalidOperationException("Insufficient family funds");
                    }
                    else checkedObject = EditableObject(request, false).ObjectID;
                    result = NativePlacementPreview.Evaluate(vm, checkedGuid, checkedObject, new LotTilePos(previewPosition.X, previewPosition.Y, previewPosition.Level), previewPosition.Direction, exporter);
                    break;
                case "buyObject":
                    EnsureObjectEditing();
                    var guid = request.GetProperty("guid").GetUInt32();
                    var item = Content.Get().WorldCatalog.GetItemByGUID(guid);
                    if (item == null || Content.Get().WorldObjects.Get(guid) == null) throw new ArgumentException("Object is not in the loaded catalog");
                    if (item.Value.Price > vm.TS1State.CurrentFamily!.Budget) throw new InvalidOperationException("Insufficient family funds");
                    var buyPosition = ObjectPosition(request);
                    InvalidateArchitectureHistory();
                    vm.SendCommand(new VMNetBuyObjectCmd { GUID = guid, x = buyPosition.X, y = buyPosition.Y, level = buyPosition.Level, dir = buyPosition.Direction });
                    architecturePending = 30;
                    result = new { queued = true };
                    break;
                case "moveObject":
                    EnsureObjectEditing();
                    var movable = EditableObject(request, false);
                    var movePosition = ObjectPosition(request);
                    InvalidateArchitectureHistory();
                    vm.SendCommand(new VMNetMoveObjectCmd { ObjectID = movable.ObjectID, x = movePosition.X, y = movePosition.Y, level = movePosition.Level, dir = movePosition.Direction });
                    architecturePending = 2;
                    result = new { queued = true };
                    break;
                case "sellObject":
                    EnsureObjectEditing();
                    var sellable = EditableObject(request, true);
                    InvalidateArchitectureHistory();
                    vm.SendCommand(new VMNetDeleteObjectCmd { ObjectID = sellable.ObjectID, CleanupAll = true });
                    architecturePending = 30;
                    result = new { queued = true };
                    break;
                case "save": result = Save(request.GetProperty("slot").GetString()!, request.TryGetProperty("lot", out var saveLot) && saveLot.GetBoolean()); break;
                case "neighborhood":
                    var neighborhoodMode = request.TryGetProperty("mode", out var modeValue) ? modeValue.GetInt32() : 1;
                    result = NativeNeighborhoodExport.Export(session, neighborhoodMode);
                    break;
                case "undo":
                case "redo":
                    EnsureObjectEditing();
                    var changed = operation == "undo" ? architectureHistory.Undo(vm) : architectureHistory.Redo(vm);
                    if (changed) ExportScene();
                    result = new { changed };
                    break;
                case "load": InvalidateArchitectureHistory(); result = Load(request.GetProperty("slot").GetString()!, request.TryGetProperty("removePacks", out var removePacks) && removePacks.GetBoolean()); resetTiming = true; ExportScene(); break;
                case "quit": running = false; break;
                default: throw new ArgumentException("Unknown operation");
            }
            Write(new { type = "response", id, operation, ok = true, result });
        }
        catch (NativeSaveCompatibility.MissingPacksException error) { Write(new { type = "response", id, operation, ok = false, error = error.Message, missingPacks = error.Packs }); }
        catch (Exception error) { Console.Error.WriteLine(error); Write(new { type = "response", id, operation, ok = false, error = error.Message }); }
    }

    private VMAvatar SelectedAvatar() => vm.GetObjectById(selectedSim) as VMAvatar ?? throw new InvalidOperationException("Select an active Sim first");
    private bool CanUseArchitectureHistory(bool undo) => vm.TS1 && vm.GlobalBlockingDialog == null && vm.SpeedMultiplier == 0 && architecturePending == 0 && !architectureHistoryPending && vm.TS1State.CurrentFamily != null && vm.GetObjectById(selectedSim) is VMAvatar avatar && IsHousehold(avatar) && (undo ? architectureHistory.CanUndo(vm) : architectureHistory.CanRedo(vm));
    private object CatalogPage(JsonElement request)
    {
        var category = request.GetProperty("category").GetInt32();
        var offset = request.GetProperty("offset").GetInt32();
        var count = request.GetProperty("count").GetInt32();
        if (category is < 0 or > 12 || offset is < 0 or > 1000000 || count is < 1 or > 64) throw new ArgumentException("Invalid object catalog page");
        var items = Content.Get().WorldCatalog.All().Where(item => item.Category == category).OrderBy(item => item.Price).ThenBy(item => item.GUID).ToArray();
        var page = items.Skip(offset).Take(count).Select(item =>
        {
            var definition = Content.Get().WorldObjects.Get(item.GUID);
            var strings = definition?.Resource.Get<CTSS>(definition.OBJ.CatalogStringsID);
            return new { guid = item.GUID, name = strings?.GetString(0) ?? item.Name ?? "", description = strings?.GetString(1) ?? "", price = item.Price,
                category = item.Category, icon = definition == null ? null : panelResources.CatalogIcon(definition) };
        }).ToArray();
        return new { schemaVersion = 1, category, offset, total = items.Length, items = page };
    }
    private object BuildCatalogPage(JsonElement request)
    {
        var kind = request.GetProperty("kind").GetString();
        var offset = request.GetProperty("offset").GetInt32();
        var count = request.GetProperty("count").GetInt32();
        if (kind is not ("floor" or "wall" or "wallStyle" or "water" or "roof") || offset is < 0 or > 1000000 || count is < 1 or > 64) throw new ArgumentException("Invalid build catalog page");
        var content = Content.Get();
        if (kind == "roof")
        {
            var roofs = Enumerable.Range(0, content.WorldRoofs.Count).Skip(offset).Take(count).Select(index => new {
                id = index, name = Path.GetFileNameWithoutExtension(content.WorldRoofs.IDToName(index)), description = "", price = 0,
                file = content.WorldRoofs.IDToName(index), icon = panelResources.RoofPattern((uint)index) }).ToArray();
            return new { schemaVersion = 1, kind, offset, total = content.WorldRoofs.Count, items = roofs };
        }
        if (kind == "water")
        {
            var waterItems = new List<(ushort ID, uint? GUID, string Name, string Description, int Price, string File, PanelResources.Image? Icon)>();
            foreach (var entry in content.WorldFloors.Entries.Where(pair => pair.Key >= 65534 && pair.Value.Price >= 0))
                waterItems.Add((entry.Key, null, entry.Value.Name ?? "", entry.Value.Description ?? "", entry.Value.Price, entry.Value.FileName ?? "", panelResources.FloorPattern(entry.Key)));
            foreach (var item in content.WorldCatalog.All().Where(item => item.Category == 14 && item.Price >= 0))
            {
                var definition = content.WorldObjects.Get(item.GUID);
                var strings = definition?.Resource.Get<CTSS>(definition.OBJ.CatalogStringsID);
                waterItems.Add((0, item.GUID, strings?.GetString(0) ?? item.Name ?? "", strings?.GetString(1) ?? "", checked((int)item.Price), "objects/" + item.GUID.ToString("X8"), definition == null ? null : panelResources.CatalogIcon(definition)));
            }
            var waterPage = waterItems.OrderBy(item => item.Price).ThenBy(item => item.GUID.HasValue).ThenBy(item => item.GUID ?? item.ID).Skip(offset).Take(count)
                .Select(item => new { id = item.ID, guid = item.GUID, name = item.Name, description = item.Description, price = item.Price, file = item.File, icon = item.Icon }).ToArray();
            return new { schemaVersion = 1, kind, offset, total = waterItems.Count, items = waterPage };
        }
        if (kind == "wallStyle")
        {
            var styles = content.WorldWalls.WallStyleIDs.Select((id, index) => new { id, pattern = content.WorldWalls.WallStylePatterns[index], style = content.WorldWalls.GetWallStyle(id) })
                .Where(item => item.style != null && item.style.Price >= 0).OrderBy(item => item.style.Price).ThenBy(item => item.id).ToArray();
            var stylePage = styles.Skip(offset).Take(count).Select(item => new { item.id, item.pattern, name = item.style.Name ?? "", description = item.style.Description ?? "", price = item.style.Price,
                file = "wallstyles/" + item.id, icon = panelResources.WallStyle(item.id) }).ToArray();
            return new { schemaVersion = 1, kind, offset, total = styles.Length, items = stylePage };
        }
        var items = kind is "floor" or "water"
            ? content.WorldFloors.Entries.Where(pair => (kind == "water" ? pair.Key >= 65534 : pair.Key is > 0 and < 65534) && pair.Value.Price >= 0).Select(pair => new { id = pair.Key, name = pair.Value.Name ?? "", description = pair.Value.Description ?? "", price = pair.Value.Price, file = pair.Value.FileName ?? "" }).ToArray()
            : content.WorldWalls.Entries.Where(pair => pair.Key is > 0 and < 65534 && pair.Value.Price >= 0).Select(pair => new { id = pair.Key, name = pair.Value.Name ?? "", description = pair.Value.Description ?? "", price = pair.Value.Price, file = pair.Value.FileName ?? "" }).ToArray();
        var page = items.OrderBy(item => item.price).ThenBy(item => item.id).Skip(offset).Take(count).Select(item => new {
            item.id, item.name, item.description, item.price, item.file, icon = kind is "floor" or "water" ? panelResources.FloorPattern(item.id) : panelResources.WallPattern(item.id) }).ToArray();
        return new { schemaVersion = 1, kind, offset, total = items.Length, items = page };
    }

    private void EnsureObjectEditing()
    {
        if (vm.GlobalBlockingDialog != null) throw new InvalidOperationException("Answer the active game dialog before editing objects");
        if (vm.SpeedMultiplier != 0) throw new InvalidOperationException("Pause the simulation before editing objects");
        if (architecturePending != 0) throw new InvalidOperationException("Wait for the active construction command to finish");
        if (vm.TS1State.CurrentFamily == null || !IsHousehold(SelectedAvatar())) throw new InvalidOperationException("Object editing requires an active household");
    }

    private void EnsureHistoryFamily()
    {
        var current = vm.TS1State.CurrentFamily;
        if (ReferenceEquals(historyFamily, current)) return;
        InvalidateArchitectureHistory();
        historyFamily = current;
    }

    private void InvalidateArchitectureHistory()
    {
        architectureHistory.Invalidate();
        architectureHistoryPending = false;
    }
    private void CompleteArchitectureHistory()
    {
        if (!architectureHistoryPending) return;
        architectureHistoryPending = false;
        architecturePending = 0;
        architectureHistory.Commit(vm);
        ExportScene();
    }
    private void ValidateArchitectureCommands(List<VMArchitectureCommand> commands)
    {
        var architecture = vm.Context.Architecture;
        var previousFailReason = architecture.LastFailReason;
        var callerUID = SelectedAvatar().PersistID;
        var validationCommands = commands.Select(command =>
        {
            command.CallerUID = callerUID;
            return command;
        }).ToList();
        int cost;
        int failReason;
        try
        {
            architecture.LastFailReason = 0;
            cost = architecture.SimulateCommands(validationCommands, false);
            failReason = architecture.LastFailReason;
        }
        finally { architecture.LastFailReason = previousFailReason; }
        if (failReason != 0) throw new InvalidOperationException("The architecture command failed its terrain or geometry checks");
        var budget = vm.TS1State.CurrentFamily?.Budget ?? 0;
        if (cost > budget) throw new InvalidOperationException("Insufficient family funds for the architecture command");
    }
    private VMEntity EditableObject(JsonElement request, bool selling)
    {
        var entity = Target(request);
        if (entity is not VMGameObject || entity.Position == LotTilePos.OUT_OF_WORLD) throw new ArgumentException("Select a placed household object");
        var error = entity.IsUserMovable(vm.Context, selling);
        if (error != VMPlacementError.Success) throw new InvalidOperationException($"Object cannot be edited: {error}");
        return entity;
    }
    private (short X, short Y, sbyte Level, Direction Direction) ObjectPosition(JsonElement request)
    {
        var x = request.GetProperty("x").GetInt16();
        var y = request.GetProperty("y").GetInt16();
        var level = request.GetProperty("level").GetSByte();
        var direction = request.GetProperty("direction").GetByte();
        if (direction is not (1 or 4 or 16 or 64)) throw new ArgumentException("Object direction must be 1, 4, 16 or 64");
        if (x < 0 || y < 0 || x >= vm.Context.Architecture.Width * 16 || y >= vm.Context.Architecture.Height * 16 || level < 1 || level > vm.Context.Architecture.Stories)
            throw new ArgumentException("Object position is outside the lot");
        if (vm.Context.Architecture.OutsideClip((short)(x / 16), (short)(y / 16), level)) throw new ArgumentException("Object position is outside the buildable area");
        return (x, y, level, (Direction)direction);
    }
    private bool IsHousehold(VMAvatar avatar) => vm.TS1State.CurrentFamily != null && avatar.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == vm.TS1State.CurrentFamily.ChunkID;
    private static bool CanCancel(VMQueuedAction action) => action.Mode is VMQueueMode.Normal or VMQueueMode.ParentIdle && (action.Flags & TTABFlags.MustRun) == 0;
    private void EnsureAvatarIdentifiers()
    {
        foreach (var avatar in vm.Entities.OfType<VMAvatar>())
        {
            if (avatar.PersistID != 0) continue;
            var identity = 0x10000u + (ushort)avatar.GetPersonData(VMPersonDataVariable.NeighborId);
            if (vm.Entities.Any(entity => entity != avatar && entity.PersistID == identity)) identity = 0x20000000u + (ushort)avatar.ObjectID;
            avatar.PersistID = identity;
            vm.Context.ObjectQueries.RegisterAvatarPersist(avatar, identity);
        }
    }
    private VMEntity Target(JsonElement request) => vm.GetObjectById(request.GetProperty("objectID").GetInt16()) ?? throw new ArgumentException("Object no longer exists");
    private object State() => new { house, cameraOrientation, updates, wallsUp, wallMode, editingView, roofsVisible, roofStyle = vm.Context.Architecture.RoofStyle, roofPitch = vm.Context.Architecture.RoofPitch, viewLevel, stories = vm.Context.Architecture.Stories, dialogs = dialogs.ToArray(), width = vm.Context.Architecture.Width, height = vm.Context.Architecture.Height, speed = vm.SpeedMultiplier, canUndo = CanUseArchitectureHistory(true), canRedo = CanUseArchitectureHistory(false), selectedSim, hours = vm.Context.Clock.Hours, minutes = vm.Context.Clock.Minutes, seconds = vm.Context.Clock.Seconds, houseStatus = NativeHouseStatus.Read(vm),
        family = vm.TS1State.CurrentFamily?.ChunkID, budget = vm.TS1State.CurrentFamily?.Budget,
        terrainSloped = vm.Context.Architecture.Terrain.Sloped,
        floors = vm.Context.Architecture.Floors[viewLevel - 1].Select(tile => tile.Pattern).ToArray(),
        walls = vm.Context.Architecture.Walls[viewLevel - 1].Select(tile => new { segments = (byte)tile.Segments, tile.TopLeftStyle, tile.TopRightStyle, tile.TopLeftPattern, tile.TopRightPattern, tile.BottomLeftPattern, tile.BottomRightPattern }).ToArray(),
        buildable = Enumerable.Range(0, vm.Context.Architecture.Width * vm.Context.Architecture.Height).Select(index => !vm.Context.Architecture.OutsideClip((short)(index % vm.Context.Architecture.Width), (short)(index / vm.Context.Architecture.Width), viewLevel)).ToArray(),
        objects = vm.Entities.Select(entity => new { id = entity.ObjectID, entity.Name, guid = entity.Object.OBJ.GUID, x = entity.Position.x / 16f, y = entity.Position.y / 16f, level = entity.Position.Level, direction = (byte)entity.Direction, avatar = entity is VMAvatar,
            movable = entity is VMGameObject && entity.Position != LotTilePos.OUT_OF_WORLD && entity.IsUserMovable(vm.Context, false) == VMPlacementError.Success,
            sellable = entity is VMGameObject && entity.Position != LotTilePos.OUT_OF_WORLD && entity.IsUserMovable(vm.Context, true) == VMPlacementError.Success }).ToArray(),
        sims = vm.Entities.OfType<VMAvatar>().Select(avatar => new { id = avatar.ObjectID, avatar.Name, neighborID = avatar.GetPersonData(VMPersonDataVariable.NeighborId), household = IsHousehold(avatar), portrait = panelResources.Portrait(avatar), mood = avatar.GetMotiveData(VMMotive.Mood), posture = avatar.GetPersonData(VMPersonDataVariable.Posture), swimming = avatar.GetPersonData(VMPersonDataVariable.IsSwimming) != 0, x = avatar.Position.x / 16f, y = avatar.Position.y / 16f, level = avatar.Position.Level, personType = avatar.GetPersonData(VMPersonDataVariable.PersonType), zodiac = avatar.GetPersonData(VMPersonDataVariable.TS1Zodiac), personality = Personality(avatar), skills = Skills(avatar), interests = Interests(avatar), relationships = NativeRelationships.Read(vm, avatar, panelResources), career = Career(avatar), bodyTexture = avatar.BodyOutfit?.GetContent()?.TS1TextureID, headTexture = avatar.HeadOutfit?.GetContent()?.TS1TextureID, actions = avatar.Thread.Queue.Select((action, index) => new { action.Name, callee = action.Callee?.ObjectID, token = panelResources.Token(action), active = index == avatar.Thread.ActiveQueueBlock, visible = action.Mode != VMQueueMode.Idle && (action.Mode != VMQueueMode.ParentExit || index == avatar.Thread.ActiveQueueBlock), cancellable = CanCancel(action), cancelRequested = action.NotifyIdle, icon = panelResources.Icon(action.IconOwner) }).ToArray(), motives = new[] { VMMotive.Hunger, VMMotive.Comfort, VMMotive.Hygiene, VMMotive.Bladder, VMMotive.Energy, VMMotive.Fun, VMMotive.Social, VMMotive.Room }.ToDictionary(motive => motive.ToString(), motive => avatar.GetMotiveData(motive)) }).ToArray() };

    private static Dictionary<string, short> Personality(VMAvatar avatar) => new[]
    {
        ("Neat", VMPersonDataVariable.NeatPersonality), ("Outgoing", VMPersonDataVariable.OutgoingPersonality),
        ("Active", VMPersonDataVariable.ActivePersonality), ("Playful", VMPersonDataVariable.PlayfulPersonality),
        ("Nice", VMPersonDataVariable.NicePersonality)
    }.ToDictionary(trait => trait.Item1, trait => avatar.GetPersonData(trait.Item2));

    private static Dictionary<string, short> Skills(VMAvatar avatar) => new[]
    {
        ("Cooking", VMPersonDataVariable.CookingSkill), ("Mechanical", VMPersonDataVariable.MechanicalSkill),
        ("Charisma", VMPersonDataVariable.CharismaSkill), ("Body", VMPersonDataVariable.BodySkill),
        ("Logic", VMPersonDataVariable.LogicSkill), ("Creativity", VMPersonDataVariable.CreativitySkill)
    }.ToDictionary(skill => skill.Item1, skill => avatar.GetPersonData(skill.Item2));

    private static short[] Interests(VMAvatar avatar)
    {
        int[] fields = [46, 47, 48, 49, 50, 51, 52, 53, 46, 47, 48, 49, 13, 14, 16, 20, 26, 54, 55];
        var data = avatar.GetPersonDataClone();
        return fields.Select(field => data[field]).ToArray();
    }

    private object Career(VMAvatar avatar)
    {
        var type = avatar.GetPersonData(VMPersonDataVariable.JobType);
        var level = avatar.GetPersonData(VMPersonDataVariable.JobPromotionLevel);
        var job = Content.Get().Jobs.GetJob(unchecked((ushort)type));
        var entry = job?.JobLevels != null && level >= 0 && level < job.JobLevels.Length ? job.JobLevels[level] : null;
        var age = avatar.GetPersonData(VMPersonDataVariable.PersonsAge);
        var school = age < 18;
        var displayedJob = school ? Content.Get().Jobs.GetJob(ushort.MaxValue) : job;
        var displayedLevel = school ? 0 : level;
        var displayedEntry = displayedJob?.JobLevels != null && displayedLevel >= 0 && displayedLevel < displayedJob.JobLevels.Length ? displayedJob.JobLevels[displayedLevel] : null;
        var next = !school && type != 0 && job?.JobLevels != null && level >= 0 && level + 1 < job.JobLevels.Length ? job.JobLevels[level + 1] : null;
        var performance = avatar.GetPersonData(VMPersonDataVariable.JobPerformance);
        var ratingIndex = school ? Math.Clamp((int)level, 0, 15) : performance < -60 ? 0 : performance < -30 ? 1 : performance < 30 ? 2 : performance < 60 ? 3 : 4;
        var ratings = Content.Get().Jobs.JobResource.Get<STR>(school ? (ushort)4097 : (ushort)4096);
        return new
        {
            type, level,
            performance, age, school,
            atWorkSchool = avatar.GetPersonData(VMPersonDataVariable.TS1AtWorkSchool),
            track = displayedJob?.Name, title = displayedEntry?.JobName, salary = displayedEntry?.Salary,
            startHour = displayedEntry?.StartTime, endHour = displayedEntry?.EndTime,
            currentLevelRequirements = entry?.MinRequired.ToArray(),
            nextLevelRequirements = next?.MinRequired.ToArray(),
            performanceLabel = ratings?.GetString(ratingIndex),
            familyFriends = vm.TS1State.CurrentFamily is { } currentFamily ? Content.Get().Neighborhood.RecountFamilyFriends(currentFamily) : 0
        };
    }

    /// Original Free Will option: with it off, household Sims stop acting on their own (person-data AutonomyLevel 0);
    /// turning it on restores each Sim's earlier value. Visitors always keep free will. The Sims 1 meaning of this
    /// field is inferred from the option text and has not been confirmed against the executable.
    private void ApplyFreeWill()
    {
        var household = vm.Entities.OfType<VMAvatar>().Where(IsHousehold).ToArray();
        var ids = household.Select(avatar => avatar.ObjectID).ToHashSet();
        foreach (var id in savedAutonomy.Keys.Where(id => !ids.Contains(id)).ToArray()) savedAutonomy.Remove(id);
        foreach (var avatar in household)
        {
            if (freeWillEnabled)
            {
                if (savedAutonomy.Remove(avatar.ObjectID, out var level)) avatar.SetPersonData(VMPersonDataVariable.AutonomyLevel, level);
            }
            else
            {
                if (!savedAutonomy.ContainsKey(avatar.ObjectID)) savedAutonomy[avatar.ObjectID] = avatar.GetPersonData(VMPersonDataVariable.AutonomyLevel);
                avatar.SetPersonData(VMPersonDataVariable.AutonomyLevel, 0);
            }
        }
    }

    private string ExportScene()
    {
        if (!freeWillEnabled || savedAutonomy.Count > 0) ApplyFreeWill();
        var path = exporter.Snapshot(house, checked((int)Math.Min(updates, int.MaxValue)), wallsUp, ++revision, viewLevel, roofsVisible, wallMode, cutaway.Mask(vm, viewLevel, wallMode, (FSO.LotView.WorldRotation)cameraOrientation), editingView, cameraOrientation: cameraOrientation);
        Write(new { type = "frame", revision, scene = path, state = State() });
        return path;
    }

    private string SavePath(string slot)
    {
        if (string.IsNullOrWhiteSpace(slot) || slot.Length > 64 || slot.Any(character => !char.IsAsciiLetterOrDigit(character) && character != '-' && character != '_')) throw new ArgumentException("Invalid save slot");
        var saves = Path.Combine(profile, "Saves");
        Directory.CreateDirectory(saves);
        return Path.Combine(saves, StorageSlot(slot) + ".json");
    }

    private static string StorageSlot(string slot) => NativeNeighborhoods.StorageSlot(slot, NativeNeighborhoods.Current);

    private void RequestLotSwitch(uint destination)
    {
        InvalidateArchitectureHistory();
        travel.Request(vm, destination);
    }

    private void ReconcileSelection()
    {
        var controlled = vm.GetObjectById(vm.GetGlobalValue(3)) as VMAvatar;
        var selected = vm.GetObjectById(selectedSim) as VMAvatar;
        var next = controlled != null && IsHousehold(controlled) ? controlled :
            selected != null && IsHousehold(selected) ? selected : vm.Entities.OfType<VMAvatar>().FirstOrDefault(IsHousehold);
        if (next == null) { selectedSim = 0; return; }
        if (next.ObjectID == selectedSim && next.PersistID == vm.MyUID && next.PersistID != 0) return;
        EnsureAvatarIdentifiers();
        selectedSim = next.ObjectID;
        vm.MyUID = next.PersistID;
        vm.SetGlobalValue(3, selectedSim);
    }

    private void ApplyLotSwitch()
    {
        if (!travel.Pending) return;
        InvalidateArchitectureHistory();
        var previous = vm;
        var next = travel.Apply(previous);
        previous.OnDialog -= CaptureDialog;
        previous.OnRequestLotSwitch -= RequestLotSwitch;
        previous.NativeAudioEnabled = false;
        foreach (var entity in previous.SoundEntities) entity.SoundThreads.Clear();
        previous.SoundEntities.Clear();
        previous.SuppressBHAVChanges();
        audio.Reset();
        vm = next;
        historyFamily = vm.TS1State.CurrentFamily;
        house = travel.House;
        vm.NativeAudioEnabled = audio.Enabled;
        vm.OnDialog += CaptureDialog;
        vm.OnRequestLotSwitch += RequestLotSwitch;
        exporter = new LotSceneExporter(vm, Path.Combine(session, "scene"));
        cutaway.Reset();
        dialogs.Clear();
        dialogsChanged = true;
        architecturePending = 0;
        viewLevel = 1;
        editingView = false;
        resetTiming = true;
        EnsureAvatarIdentifiers();
        selectedSim = vm.Entities.OfType<VMAvatar>().FirstOrDefault(IsHousehold)?.ObjectID ?? 0;
        if (selectedSim != 0) vm.MyUID = SelectedAvatar().PersistID;
        Write(new { type = "lotChanged", house, away = travel.Away });
        ExportScene();
    }

    private object Save(string slot, bool lot = false)
    {
        // Saving the house writes the lot back into its house file, as the original game does, so the next visit to the
        // lot starts where it was left. Only the household's own lot is written: a trip away or a pending dialog keeps
        // the save in its slot alone.
        string? lotSkipped = !lot ? null : travel.Away || travel.Pending ? "away" : vm.GlobalBlockingDialog != null ? "dialog" : null;
        int? lotBytes = null;
        if (lot && lotSkipped == null)
        {
            lotBytes = NativeHouseSave.Write(NativeNeighborhoods.UserData(profile), house, vm);
            Content.Get().Neighborhood.SaveNeighbourhood(true);
        }
        using var data = new MemoryStream();
        using (var writer = new BinaryWriter(data, System.Text.Encoding.UTF8, true)) vm.Save().SerializeInto(writer);
        var envelope = new SaveEnvelope(SaveSchemaVersion, EngineVersion, packFingerprint, house, updates, Convert.ToBase64String(data.ToArray()), dialogs.ToArray(), vm.LastSpeedMultiplier, travel.Save(vm),
            plugins.Packs.Select(pack => new NativeSaveCompatibility.PackRecord(pack.Id, pack.Version)).ToArray(), plugins.Save(), NativeNeighborhoods.Current);
        var path = SavePath(slot);
        var temporary = path + ".tmp";
        string? backup = null;
        try
        {
            File.WriteAllText(temporary, JsonSerializer.Serialize(envelope, Json));
            backup = NativeSaveCompatibility.Backup(profile, StorageSlot(slot), path);
            File.Move(temporary, path, true);
        }
        finally
        {
            if (File.Exists(temporary)) File.Delete(temporary);
        }
        return new { slot, path, bytes = data.Length, backup, lot = lotBytes != null, lotBytes, lotSkipped };
    }

    private object CreateHousehold(JsonElement request)
    {
        if (vm.SpeedMultiplier != 0 || vm.GlobalBlockingDialog != null || travel.Pending)
            throw new InvalidOperationException("Household creation requires a paused residential lot without a blocking dialog or active trip");
        var membersElement = request.GetProperty("members");
        if (membersElement.ValueKind != JsonValueKind.Array || membersElement.GetArrayLength() is < 1 or > 8)
            throw new ArgumentException("A household must contain one to eight Sims");
        var members = membersElement.EnumerateArray().Select(member =>
        {
            var personality = member.GetProperty("personality").EnumerateArray().Select(value => checked((short)value.GetInt32())).ToArray();
            return new NativeHouseholdMember(
                member.GetProperty("name").GetString() ?? "",
                member.TryGetProperty("bio", out var bio) ? bio.GetString() ?? "" : "",
                member.GetProperty("code").GetString() ?? "",
                member.GetProperty("skin").GetString() ?? "",
                personality,
                member.TryGetProperty("headChoice", out var headChoice) ? headChoice.GetString() : null,
                member.TryGetProperty("bodyChoice", out var bodyChoice) ? bodyChoice.GetString() : null);
        }).ToArray();
        var family = NativeHouseholdCreation.Create(house, request.GetProperty("familyName").GetString() ?? "", members);
        ReloadHousehold();
        return new { family = family.ChunkID, house, budget = family.Budget, members = family.FamilyGUIDs.Length };
    }

    private object MoveInFamily(JsonElement request)
    {
        if (vm.SpeedMultiplier != 0 || vm.GlobalBlockingDialog != null || travel.Pending)
            throw new InvalidOperationException("Moving in requires a paused residential lot without a blocking dialog or active trip");
        var family = NativeHouseholdCreation.MoveIn(house, checked((ushort)request.GetProperty("family").GetInt32()));
        ReloadHousehold();
        return new { family = family.ChunkID, house, budget = family.Budget, members = family.FamilyGUIDs.Length };
    }

    private static object AppearanceCatalog(JsonElement request)
    {
        var catalog = NativeHouseholdAppearance.Catalog(
            request.GetProperty("gender").GetString() ?? "",
            request.GetProperty("age").GetString() ?? "",
            request.GetProperty("skin").GetString() ?? "");
        return new
        {
            catalog.Gender,
            catalog.Age,
            catalog.Skin,
            heads = catalog.Heads.Select(choice => new { choice.Id, choice.Texture }).ToArray(),
            bodies = catalog.Bodies.Select(choice => new { choice.Id, choice.Texture, choice.BodyType }).ToArray()
        };
    }

    private void ReloadHousehold()
    {
        InvalidateArchitectureHistory();
        var previous = vm;
        previous.OnDialog -= CaptureDialog;
        previous.OnRequestLotSwitch -= RequestLotSwitch;
        previous.NativeAudioEnabled = false;
        foreach (var entity in previous.SoundEntities) entity.SoundThreads.Clear();
        previous.SoundEntities.Clear();
        previous.SuppressBHAVChanges();
        audio.Reset();
        vm = LoadHouse(NativeNeighborhoods.UserData(profile), house, true);
        vm.SpeedMultiplier = 0;
        vm.LastSpeedMultiplier = 0;
        vm.NativeAudioEnabled = audio.Enabled;
        vm.OnDialog += CaptureDialog;
        vm.OnRequestLotSwitch += RequestLotSwitch;
        exporter = new LotSceneExporter(vm, Path.Combine(session, "scene"));
        historyFamily = vm.TS1State.CurrentFamily;
        dialogs.Clear();
        cutaway.Reset();
        architecturePending = 0;
        architectureHistoryPending = false;
        viewLevel = 1;
        editingView = false;
        roofsVisible = false;
        wallMode = "down";
        wallsUp = false;
        resetTiming = true;
        EnsureAvatarIdentifiers();
        selectedSim = vm.Entities.OfType<VMAvatar>().FirstOrDefault(IsHousehold)?.ObjectID ?? 0;
        if (selectedSim != 0) vm.MyUID = SelectedAvatar().PersistID;
        dialogsChanged = true;
        ExportScene();
    }

    private object Load(string slot, bool removePacks = false)
    {
        var envelope = JsonSerializer.Deserialize<SaveEnvelope>(File.ReadAllText(SavePath(slot)), Json) ?? throw new InvalidDataException("Invalid save");
        if (envelope.SchemaVersion is < 1 or > SaveSchemaVersion || envelope.Engine != EngineVersion) throw new InvalidDataException("Save requires the same engine and content pack stack");
        if (envelope.Neighborhood != NativeNeighborhoods.Current)
            throw new InvalidDataException($"This save belongs to neighborhood {envelope.Neighborhood}");
        var compatibility = NativeSaveCompatibility.Check(envelope.PackFingerprint, envelope.Packs, packFingerprint, plugins.Packs, removePacks);
        // A removed pack's plugin state is dropped with its content.
        var removedPacks = compatibility.Removed.Select(pack => pack[..pack.LastIndexOf('@')]).ToHashSet(StringComparer.Ordinal);
        var savedPlugins = envelope.Plugins?.Where(pair => !removedPacks.Contains(pair.Key)).ToDictionary(pair => pair.Key, pair => pair.Value);
        plugins.ValidateSaved(savedPlugins);
        travel.Validate(envelope.Travel, envelope.House);
        var migrationBackup = compatibility.Migrated ? NativeSaveCompatibility.Backup(profile, StorageSlot(slot), SavePath(slot)) : null;
        using var data = new MemoryStream(Convert.FromBase64String(envelope.State));
        using var reader = new BinaryReader(data);
        if (data.Length < 9 || new string(reader.ReadChars(4)) != "FSOv") throw new InvalidDataException("Invalid simulation snapshot");
        data.Position = 0;
        var marshal = new VMMarshal();
        marshal.Deserialize(reader);
        var removal = removedPacks.Count == 0 ? null : NativePackRemoval.Strip(marshal, guid => Content.Get().WorldObjects.Get(guid) != null);
        InvalidateArchitectureHistory();
        audio.Reset();
        foreach (var entity in vm.SoundEntities) entity.SoundThreads.Clear();
        vm.SoundEntities.Clear();
        var savedFamily = (marshal.PlatformState as FSO.SimAntics.Model.TS1Platform.VMTS1LotState)?.CurrentFamily;
        vm.Load(marshal);
        cutaway.Reset();
        vm.TS1State.CurrentFamily = savedFamily;
        if (savedFamily != null) vm.TS1State.ActivateFamily(vm, savedFamily);
        historyFamily = vm.TS1State.CurrentFamily;
        vm.TS1State.CurrentFamily?.SelectWholeFamily();
        if (removal != null)
        {
            foreach (var id in removal.ResetEntities) vm.GetObjectById(id)?.Reset(vm.Context);
            var family = vm.TS1State.CurrentFamily;
            if (family != null && removal.Refund > 0) family.Budget = (int)Math.Min(int.MaxValue, (long)family.Budget + removal.Refund);
        }
        travel.Restore(envelope.Travel, envelope.House, vm);
        var changingLot = house != envelope.House;
        house = envelope.House;
        if (changingLot)
        {
            viewLevel = 1;
            editingView = false;
            Write(new { type = "lotChanged", house, away = travel.Away });
        }
        dialogs.Clear();
        // Dialogs raised by or about removed objects, or by a Sim whose thread was reset, went away with them.
        HashSet<short> droppedDialogs = removal == null ? [] : removal.Objects.Select(item => item.ObjectId).Concat(removal.ResetEntities).ToHashSet();
        dialogs.AddRange((envelope.Dialogs ?? []).Where(dialog => !droppedDialogs.Contains(dialog.Caller) && !droppedDialogs.Contains(dialog.Icon)).Select(dialog =>
        {
            var token = (++dialogSequence).ToString();
            if (dialog.Kind == (byte)VMDialogType.TS1PhoneBook && dialog.PhoneBook == null)
                return dialog with { Token = token, PhoneBook = ReadPhoneBook(vm.GetObjectById(dialog.Caller) as VMAvatar) };
            return dialog with { Token = token };
        }));
        var blocking = dialogs.SingleOrDefault(dialog => dialog.Blocking);
        vm.GlobalBlockingDialog = blocking == null ? null : vm.GetObjectById(blocking.Caller);
        if (blocking != null && vm.GlobalBlockingDialog?.Thread.BlockingState is not VMDialogResult) throw new InvalidDataException("Saved dialog has no matching simulation state");
        vm.LastSpeedMultiplier = 0;
        vm.SpeedMultiplier = 0;
        if (blocking != null) { vm.SpeedMultiplier = -2; vm.LastSpeedMultiplier = envelope.ResumeSpeed; ((VMDialogResult)vm.GlobalBlockingDialog!.Thread.BlockingState).HasDisplayed = true; }
        dialogsChanged = true;
        updates = envelope.Updates;
        selectedSim = vm.Entities.OfType<VMAvatar>().FirstOrDefault(IsHousehold)?.ObjectID ?? 0;
        EnsureAvatarIdentifiers();
        if (selectedSim != 0) vm.MyUID = SelectedAvatar().PersistID;
        plugins.Restore(savedPlugins);
        if (compatibility.Migrated)
            Write(new
            {
                type = "saveMigrated", slot, upgraded = compatibility.Upgraded, added = compatibility.Added, removed = compatibility.Removed,
                removedObjects = removal?.Objects.Select(item => new { guid = item.Guid, objectId = item.ObjectId, name = item.Name, refund = item.Refund }).ToArray() ?? [],
                refund = removal?.Refund ?? 0, resetObjects = removal?.ResetEntities.Length ?? 0, backup = migrationBackup
            });
        return State();
    }

    private void Write(object value) => output.WriteLine(JsonSerializer.Serialize(value, Json));

    private void CaptureDialog(VMDialogInfo? info)
    {
        if (info == null) return;
        if (dialogs.Count >= 64) throw new InvalidOperationException("Too many pending game dialogs");
        dialogs.Add(new DialogSnapshot((++dialogSequence).ToString(), info.Block, info.Caller?.ObjectID ?? 0, info.Icon?.ObjectID ?? 0,
            (byte)info.Operand.Type, info.Title ?? "", info.Message ?? "", info.Yes, info.No, info.Cancel,
            info.Operand.Type == VMDialogType.TS1PhoneBook ? ReadPhoneBook(info) : null));
        dialogsChanged = true;
    }

    private static PhoneBookFamily[] ReadPhoneBook(VMDialogInfo info)
    {
        return ReadPhoneBook(info.Caller as VMAvatar);
    }

    private static PhoneBookFamily[] ReadPhoneBook(VMAvatar? avatar)
    {
        if (avatar == null) return [];
        var neighborhood = Content.Get().Neighborhood;
        var caller = neighborhood.GetNeighborByID(avatar.GetPersonData(VMPersonDataVariable.NeighborId));
        if (caller == null) return [];
        var families = new List<(short Id, List<PhoneBookContact> Contacts)>();
        foreach (var relation in caller.Relationships.Keys)
        {
            if (relation is <= 0 or > short.MaxValue || relation == caller.NeighbourID) continue;
            var contact = neighborhood.GetNeighborByID((short)relation);
            if (contact?.PersonData == null) continue;
            var familyId = contact.PersonData.ElementAtOrDefault((int)VMPersonDataVariable.TS1FamilyNumber);
            var gender = contact.PersonData.ElementAtOrDefault((int)VMPersonDataVariable.Gender);
            if (familyId <= 0 || gender >= 2) continue;
            var groupIndex = families.FindIndex(group => group.Id == familyId);
            if (groupIndex < 0)
            {
                families.Add((familyId, []));
                groupIndex = families.Count - 1;
            }
            var definition = Content.Get().WorldObjects.Get(contact.GUID);
            var name = definition?.Resource.Get<CTSS>(definition.OBJ.CatalogStringsID)?.GetString(0) ?? contact.Name ?? "";
            families[groupIndex].Contacts.Add(new PhoneBookContact(contact.NeighbourID, name));
        }
        return families.Select(group => new PhoneBookFamily(group.Id,
            neighborhood.GetFamilyString((ushort)group.Id)?.GetString(0) ?? group.Id.ToString(), group.Contacts.ToArray())).ToArray();
    }

    private object RespondDialog(JsonElement request)
    {
        var token = request.GetProperty("token").GetString();
        var dialog = dialogs.SingleOrDefault(item => item.Token == token) ?? throw new ArgumentException("Dialog is no longer active");
        var code = request.GetProperty("code").GetByte();
        var text = request.TryGetProperty("text", out var value) ? value.GetString() ?? "" : "";
        if (text.Length > 1024 || text.Contains('\0')) throw new ArgumentException("Invalid dialog response text");
        if (dialog.Kind is 0 or 4 && code != 0 || dialog.Kind == 1 && code > 1 || dialog.Kind == 2 && code > 2 || dialog.Kind == 3 && code != 0 || dialog.Kind == 10 && code > 1) throw new ArgumentException("Invalid dialog response choice");
        if (dialog.Kind == 10)
        {
            if (!int.TryParse(text, out var neighborId) || (code == 0 && neighborId != -1) ||
                (code == 1 && dialog.PhoneBook?.Any(family => family.Contacts.Any(contact => contact.NeighborId == neighborId)) != true))
                throw new ArgumentException("Invalid phone-book response");
        }
        if (dialog.Blocking)
        {
            var owner = vm.GlobalBlockingDialog;
            if (owner?.ObjectID != dialog.Caller || owner.Thread.BlockingState is not VMDialogResult state || state.Responded || (byte)state.Type != dialog.Kind) throw new InvalidOperationException("Dialog does not match the blocked simulation");
            if (!new VMNetDialogResponseCmd { ResponseCode = code, ResponseText = text }.Execute(vm, SelectedAvatar())) throw new InvalidOperationException("Simulation rejected dialog response");
        }
        dialogs.Remove(dialog);
        dialogsChanged = true;
        return State();
    }
}
