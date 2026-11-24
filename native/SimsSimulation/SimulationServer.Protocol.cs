using System.Buffers.Binary;
using System.Diagnostics;
using System.Security.Cryptography;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Text.Json.Serialization;
using System.Text.RegularExpressions;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;

namespace SimsSimulation;

internal sealed partial class SimulationServer
{

    private bool HandleCore(JsonElement request, string id, string op)
    {
        object? result = null;
        string? error = null;
        switch (op)
        {
            case "state": result = State(); break;
            case "cursorObjectCreated":
            {
                var markDirty = !request.TryGetProperty("dirty", out var dirtyValue) || dirtyValue.ValueKind != JsonValueKind.False;
                if (markDirty) saveDirty = true;
                if (world is { } cursorWorld &&
                    request.TryGetProperty("objectID", out var cursorIdValue) &&
                    cursorIdValue.TryGetInt16(out var cursorObjectId) &&
                    cursorWorld.ObjectById(cursorObjectId) is { } cursorObject)
                {
                    result = new
                    {
                        dirty = saveDirty,
                        objectID = (int)cursorObjectId,
                        preview = ObjectDisposePreview(cursorWorld, cursorObject),
                    };
                }
                else
                {
                    result = new { dirty = saveDirty };
                }
                break;
            }
            case "tutorialResetState": result = new { requiresSave = saveDirty && house != 0 }; break;
            case "blockSimulator":
                simulatorBlocked = request.TryGetProperty("blocked", out var blockedValue) && blockedValue.ValueKind == JsonValueKind.True;
                result = new { blocked = simulatorBlocked };
                break;
            case "tutorialInfo":
            {
                var owner = world?.TutorialOwner;
                if (owner?.TypeRecord?.BehaviorScope is BehaviorScope scope)
                {
                    var tree = scope.FindNamedTree("show situation info");
                    if (tree != 0) TreeRunner.RunWithParameters(world!, owner, scope, tree, 0, []);
                }
                result = State();
                break;
            }
            case "uiButton":
                lastButtonImage = request.TryGetProperty("image", out var imageValue) && imageValue.TryGetInt32(out var image) ? image : null;
                lastButtonPerson = request.TryGetProperty("objectID", out var buttonSimValue) && buttonSimValue.TryGetInt16(out var buttonSim) ? buttonSim : (short)0;
                if (world is not null) world[SimulationGlobal.LastGZButtonID] = (short)(lastButtonImage ?? 0);
                result = new { recorded = true };
                break;
            case "relationshipPopup":
            {
                var current = world ?? throw new InvalidOperationException("No lot is loaded");
                var neighborId = request.GetProperty("neighborID").GetInt16();
                if (!current.Neighbors.TryGetValue(neighborId, out var neighbor)) throw new ArgumentException("Unknown neighbor");
                var selected = current.WalkOrder.OfType<XPerson>().FirstOrDefault(person => person.Id == selectedSim);
                if (selected is null || !current.Neighbors.TryGetValue(selected[PersonData.NeighborId], out var owner) ||
                    !owner.Relationships.Snapshot().ContainsKey(neighborId)) throw new ArgumentException("Neighbor is not in the selected Sim's relationships");
                var selector = registry?.Find(unchecked((uint)neighbor.TypeRecordKey));
                var liveTarget = current.WalkOrder.OfType<XPerson>().FirstOrDefault(person => person[PersonData.NeighborId] == neighbor.Id);
                var name = !string.IsNullOrWhiteSpace(liveTarget?.Name) ? liveTarget.Name
                    : !IsInternalUserLabel(neighbor.Name) ? neighbor.Name!
                    : selector?.CatalogString(0, language) ?? neighbor.Name ?? "";
                var zodiac = current.InitializeRelationshipZodiac(neighbor, !string.IsNullOrEmpty(name),
                    data => (short)(Neighborhoods.ComputeExportZodiac(data) ?? 0));
                result = new { zodiac = (int)zodiac };
                break;
            }
            case "mode":
                viewerMode = request.GetProperty("mode").GetString() switch
                {
                    "live" => 0, "build" => 1, "buy" => 2, "options" or "camera" => 3,
                    _ => throw new ArgumentException("mode must be live, build, buy, options or camera"),
                };
                if ((IsVisitingAwayLot || IsEmergencyBuyBuildLocked) && viewerMode is 1 or 2)
                    viewerMode = 0;
                if (world is not null && world[SimulationGlobal.SimlessBuildMode] != 0 && viewerMode == 0)
                    viewerMode = 2;
                if (world is not null) world[SimulationGlobal.Mode] = viewerMode;
                if (viewerMode != 2) RemoveTileCursor();
                result = new { mode = viewerMode };
                break;
            case "zoom":
                viewerScale = request.TryGetProperty("scale", out var scaleValue) && scaleValue.TryGetInt16(out var scale) && scale is >= 1 and <= 3
                    ? scale : throw new ArgumentException("scale must be 1, 2 or 3");
                if (world is not null) world[SimulationGlobal.ZoomLevelSML] = viewerScale;
                result = new { scale = viewerScale };
                break;
            case "viewScrolling":
                var viewScrolling = request.TryGetProperty("value", out var scrollingValue) &&
                    scrollingValue.ValueKind is JsonValueKind.True or JsonValueKind.False
                    ? scrollingValue.GetBoolean()
                    : throw new ArgumentException("view scrolling state (value) must be a boolean");
                result = new { scrolling = viewScrolling };
                break;
            case "tutorialPanelCheck":
            {
                var live = request.TryGetProperty("live", out var liveValue) && liveValue.ValueKind == JsonValueKind.True;
                var popup = request.TryGetProperty("popup", out var popupValue) && popupValue.ValueKind == JsonValueKind.String
                    ? popupValue.GetString() : null;
                var scrolls = request.TryGetProperty("scrolls", out var scrollsValue) && scrollsValue.TryGetInt32(out var scrollCount) ? scrollCount : 0;
                var rotation = request.TryGetProperty("rotation", out var rotationValue) && rotationValue.TryGetInt32(out var rotationCount)
                    ? rotationCount : cameraOrientation;
                var setButtons = request.TryGetProperty("setButtons", out var setValue) && setValue.ValueKind == JsonValueKind.Array
                    ? setValue.EnumerateArray().Where(item => item.ValueKind == JsonValueKind.Number).Select(item => item.GetInt32()).ToArray() : [];
                var delivered = world is not null && tutorialEvents.Check(world, new TutorialUiState
                {
                    Live = live, Popup = popup, LastButtonImage = lastButtonImage, LastButtonPerson = lastButtonPerson,
                    Rotation = rotation, Scrolls = scrolls, SetButtons = setButtons,
                });
                result = delivered ? State() : new { delivered = false };
                break;
            }
            case "speed":
                var requestedSpeed = request.TryGetProperty("value", out var speedValue) && speedValue.ValueKind == JsonValueKind.Number && speedValue.TryGetInt32(out var requested) ? requested : 0;
                if (!testFixtureEnabled && (world is null || world[SimulationGlobal.SimlessBuildMode] != 0) && requestedSpeed > 0)
                    requestedSpeed = 0;
                if (autoSpeedSaved > -1)
                    autoSpeedSaved = requestedSpeed > 0 ? requestedSpeed : -1;
                if (HasBlockingDialog(world))
                {
                    dialogResumeSpeed = Math.Clamp(requestedSpeed, 0, 1000);
                    if (dialogResumeSpeed > 0) lastRunningSpeed = dialogResumeSpeed;
                    SetSimulationSpeed(0, blockingDialog: true);
                }
                else
                {
                    SetSimulationSpeed(requestedSpeed);
                    dialogResumeSpeed = 0;
                    if (speed > 0) lastRunningSpeed = speed;
                }
                result = State();
                break;
            case "step":
            {
                var count = request.TryGetProperty("count", out var cVal) && cVal.TryGetInt32(out var parsedCount) ? parsedCount : 1;
                if (count is < 1 or > 10000) throw new ArgumentException("Step count must be 1..10000");
                var previous = speed;
                try
                {
                    if (previous == 0) SetSimulationSpeed(1);
                    for (var i = 0; i < count; i++)
                    {
                        if (world is not null && AdvanceOneTick(allowAutoSpeed: previous > 0))
                        {
                            updates++;
                            plugins?.Tick(updates);
                            if (audio is { } activeAudio && world is { } activeWorld) activeAudio.Tick(activeWorld);
                            else audio?.Tick();
                        }
                        if (HasBlockingDialog(world)) break;
                    }
                }
                finally
                {
                    if (previous == 0)
                    {
                        SetSimulationSpeed(0);
                        dialogResumeSpeed = 0;
                    }
                }
                Export();
                result = State();
                break;
            }
            case "stream":
                streaming = (request.TryGetProperty("enabled", out var streamValue) || request.TryGetProperty("value", out streamValue)) && streamValue.ValueKind == JsonValueKind.True;
                nextAnimation = 0;
                result = new { enabled = streaming, framesPerSecond = 120 };
                if (streaming && world is not null)
                    Write(new { type = "state", state = State() });
                break;
            case "scene":
                var exportedPath = Export();
                result = IsExplicitNativeEnv ? new { revision } : exportedPath;
                break;
            case "pieHeadPreview":
            {
                var yaw = request.TryGetProperty("yaw", out var yv) && yv.TryGetSingle(out var y) ? y : 0f;
                var pitch = request.TryGetProperty("pitch", out var pv) && pv.TryGetSingle(out var p) ? p : 0f;
                var person = SelectedPerson();
                if (person is null) throw new InvalidOperationException("No Sim is selected for pie-head preview.");
                var avatarGeometry = AvatarSceneGeometry.For(game, registry ?? throw new InvalidOperationException("There is no loaded native object catalog."));
                if (pieHead is null || pieHead.Value.Sim != person.Id || pieHead.Value.Tick != updates)
                {
                    var built = avatarGeometry.BuildHeadMeshes(person, viewLevel, cameraOrientation, (x, y) => 0f, new LotCamera(cameraOrientation, LotWidth, LotHeight));
                    pieHead = (person.Id, updates, built);
                }
                var rgba = SimPortrait.PieHeadPreview(pieHead.Value.Meshes, yaw, pitch);
                result = new
                {
                    width = SimPortrait.PieHeadWidth,
                    height = SimPortrait.PieHeadHeight,
                    pixels = Convert.ToBase64String(rgba)
                };
                break;
            }
            case "sceneAck":
            {
                var acknowledged = request.GetProperty("revision").GetInt64();
                if (acknowledged < 1 || acknowledged > revision) throw new ArgumentException("Invalid scene acknowledgement");
                SimsSimulation.InMemorySessionAssets.PruneOldScenes(SceneDirectory, acknowledged - 1);
                if (Directory.Exists(SceneDirectory))
                {
                    foreach (var path in Directory.EnumerateFiles(SceneDirectory, "scene-*.json"))
                        if (long.TryParse(Path.GetFileNameWithoutExtension(path).AsSpan(6), out var number) && number < acknowledged - 1)
                            File.Delete(path);
                }
                result = new { ack = true };
                break;
            }
            case "level":
                var previousViewLevel = viewLevel;
                var previousLevelRoofs = roofsVisible;
                var previousLevelDw = doorWindowBuildToolActive;
                viewLevel = request.TryGetProperty("value", out var levelValue) && levelValue.ValueKind == JsonValueKind.Number && levelValue.TryGetInt32(out var requestedLevel)
                    ? Math.Clamp(requestedLevel, 1, Stories)
                    : 1;
                if (viewLevel != previousViewLevel) ClearCutaway();
                if (request.TryGetProperty("roofs", out var levelRoofsValue) && levelRoofsValue.ValueKind is JsonValueKind.True or JsonValueKind.False)
                    roofsVisible = levelRoofsValue.GetBoolean();
                else if (!IsExplicitNativeEnv)
                    roofsVisible = false;
                if (request.TryGetProperty("doorWindowTool", out var levelDwValue) && levelDwValue.ValueKind is JsonValueKind.True or JsonValueKind.False)
                    doorWindowBuildToolActive = editingView && levelDwValue.GetBoolean();
                if (request.TryGetProperty("wallpaperTool", out var levelWtValue) && levelWtValue.ValueKind is JsonValueKind.True or JsonValueKind.False)
                    wallpaperBuildToolActive = editingView && levelWtValue.GetBoolean();
                var levelChanged = viewLevel != previousViewLevel || roofsVisible != previousLevelRoofs || doorWindowBuildToolActive != previousLevelDw;
                if (!streaming || revision == 0 || levelChanged ||
                    (wallMode == "cutaway" && world is not null && lot is not null && !SceneExporter.CutawayMaskMatches(world, animationState, revision, viewLevel, wallMode, cameraOrientation,
                        cutawayTile, cutawayRooms, CutawaySimTile(), cutawayZoom, raiseHoveredWalls: wallpaperBuildToolActive)))
                    Export();
                result = State();
                break;
            case "view":
                var requestedEditingView = request.TryGetProperty("editing", out var editingValue) &&
                    editingValue.ValueKind is JsonValueKind.True or JsonValueKind.False
                    ? editingValue.GetBoolean()
                    : throw new ArgumentException("editing must be a boolean");
                var requestedDoorWindowView = requestedEditingView &&
                    (request.TryGetProperty("doorWindowTool", out var dwValue) && dwValue.ValueKind is JsonValueKind.True or JsonValueKind.False
                        ? dwValue.GetBoolean()
                        : doorWindowBuildToolActive);
                var requestedWallpaperView = requestedEditingView &&
                    (request.TryGetProperty("wallpaperTool", out var wtValue) && wtValue.ValueKind is JsonValueKind.True or JsonValueKind.False
                        ? wtValue.GetBoolean()
                        : wallpaperBuildToolActive);
                if (IsVisitingAwayLot || IsEmergencyBuyBuildLocked)
                {
                    requestedEditingView = false;
                    requestedDoorWindowView = false;
                    requestedWallpaperView = false;
                }
                var viewChanged = editingView != requestedEditingView || doorWindowBuildToolActive != requestedDoorWindowView;
                var wallpaperViewChanged = wallpaperBuildToolActive != requestedWallpaperView;
                if (viewChanged || wallpaperViewChanged)
                {
                    editingView = requestedEditingView;
                    doorWindowBuildToolActive = requestedDoorWindowView;
                    wallpaperBuildToolActive = requestedWallpaperView;
                    if (viewChanged ||
                        !streaming || revision == 0 ||
                        (wallMode == "cutaway" && world is not null && lot is not null && !SceneExporter.CutawayMaskMatches(world, animationState, revision, viewLevel, wallMode, cameraOrientation,
                            cutawayTile, cutawayRooms, CutawaySimTile(), cutawayZoom, raiseHoveredWalls: wallpaperBuildToolActive)))
                        Export();
                }
                result = State();
                break;
            case "walls":
                var previousWallMode = wallMode;
                var previousWallsRoofs = roofsVisible;
                var previousWallsDw = doorWindowBuildToolActive;
                if (request.TryGetProperty("mode", out var wallModeValue) && wallModeValue.ValueKind == JsonValueKind.String)
                    wallMode = wallModeValue.GetString() is { } requestedMode && requestedMode is "up" or "down" or "cutaway"
                        ? requestedMode : throw new ArgumentException("Wall mode must be up, down, or cutaway.");
                else if (request.TryGetProperty("up", out var wallsUpValue) && wallsUpValue.ValueKind is JsonValueKind.True or JsonValueKind.False)
                    wallMode = wallsUpValue.GetBoolean() ? "up" : "down";
                else throw new ArgumentException("Wall mode is required.");
                roofsVisible = false;
                if (wallMode != "cutaway")
                {
                    ClearCutaway();
                }
                else if (request.TryGetProperty("x", out _) && request.TryGetProperty("y", out _))
                {
                    ApplyCutawayTarget(request);
                }
                if (request.TryGetProperty("doorWindowTool", out var wallsDwValue) && wallsDwValue.ValueKind is JsonValueKind.True or JsonValueKind.False)
                    doorWindowBuildToolActive = editingView && wallsDwValue.GetBoolean();
                if (request.TryGetProperty("wallpaperTool", out var wallsWtValue) && wallsWtValue.ValueKind is JsonValueKind.True or JsonValueKind.False)
                    wallpaperBuildToolActive = editingView && wallsWtValue.GetBoolean();
                var wallsChanged = wallMode != previousWallMode || roofsVisible != previousWallsRoofs || doorWindowBuildToolActive != previousWallsDw;
                if (!streaming || revision == 0 || wallsChanged ||
                    (wallMode == "cutaway" && world is not null && lot is not null && !SceneExporter.CutawayMaskMatches(world, animationState, revision, viewLevel, wallMode, cameraOrientation,
                        cutawayTile, cutawayRooms, CutawaySimTile(), cutawayZoom, raiseHoveredWalls: wallpaperBuildToolActive)))
                    Export();
                result = State();
                break;
            case "roofs":
                var previousRoofsVisible = roofsVisible;
                var previousRoofsWallMode = wallMode;
                var previousRoofsLevel = viewLevel;
                var previousRoofsDw = doorWindowBuildToolActive;
                if (!request.TryGetProperty("visible", out var roofsValue) || roofsValue.ValueKind is not (JsonValueKind.True or JsonValueKind.False))
                    throw new ArgumentException("Roof visibility (visible) is required.");
                roofsVisible = roofsValue.GetBoolean();
                if (roofsVisible)
                {
                    wallMode = "up";
                    if (request.TryGetProperty("level", out var roofsLevelValue) && roofsLevelValue.ValueKind == JsonValueKind.Number && roofsLevelValue.TryGetInt32(out var requestedRoofsLevel))
                        viewLevel = Math.Clamp(requestedRoofsLevel, 1, Stories);
                    else if (!IsExplicitNativeEnv)
                        viewLevel = Stories;
                    ClearCutaway();
                }
                if (request.TryGetProperty("doorWindowTool", out var roofsDwValue) && roofsDwValue.ValueKind is JsonValueKind.True or JsonValueKind.False)
                    doorWindowBuildToolActive = editingView && roofsDwValue.GetBoolean();
                if (request.TryGetProperty("wallpaperTool", out var roofsWtValue) && roofsWtValue.ValueKind is JsonValueKind.True or JsonValueKind.False)
                    wallpaperBuildToolActive = editingView && roofsWtValue.GetBoolean();
                var roofsChanged = roofsVisible != previousRoofsVisible || wallMode != previousRoofsWallMode ||
                    viewLevel != previousRoofsLevel || doorWindowBuildToolActive != previousRoofsDw;
                if (!streaming || revision == 0 || roofsChanged ||
                    (wallMode == "cutaway" && world is not null && lot is not null && !SceneExporter.CutawayMaskMatches(world, animationState, revision, viewLevel, wallMode, cameraOrientation,
                        cutawayTile, cutawayRooms, CutawaySimTile(), cutawayZoom, raiseHoveredWalls: wallpaperBuildToolActive)))
                    Export();
                result = State();
                break;
            case "cutaway":
                if (wallMode != "cutaway") { result = new { ignored = true }; break; }
                ApplyCutawayTarget(request);
                if (world is null || lot is null || !SceneExporter.CutawayMaskMatches(world, animationState, revision, viewLevel, wallMode, cameraOrientation,
                        cutawayTile, cutawayRooms, CutawaySimTile(), cutawayZoom, raiseHoveredWalls: wallpaperBuildToolActive))
                    Export();
                result = State(includeArchitectureGrids: !streaming,
                    includeObjects: !streaming || editingView || ComputeObjectsSignature() != lastStreamedObjectsSignature);
                break;
            case "cameraOrientation":
                var previousCameraOrientation = cameraOrientation;
                var requestedOrientation = request.TryGetProperty("value", out var orientationValue) && orientationValue.TryGetInt32(out var orientation)
                    ? orientation : throw new ArgumentException("Camera orientation must be an integer.");
                cameraOrientation = ((requestedOrientation % 4) + 4) % 4;
                if (!streaming || revision == 0 || cameraOrientation != previousCameraOrientation)
                    Export();
                result = State();
                break;
            case "selectSim":
                var requestedSim = request.TryGetProperty("objectID", out var simValue) && simValue.ValueKind == JsonValueKind.Number && simValue.TryGetInt16(out var sim)
                    ? sim : throw new ArgumentException("objectID must be a person object ID.");
                if (world?.ObjectById(requestedSim) is not XPerson requestedPerson || !IsHouseholdPerson(requestedPerson))
                    throw new ArgumentException("Select a Sim in the active household");
                var selectionChanged = selectedSim != requestedSim;
                selectedSim = requestedSim;
                if (world is not null) SyncSelectedSimFlags(world, selectedSim);
                if (selectionChanged)
                {
                    world?.DispatchNotice(0xe4, requestedSim);
                    RefreshDynamicOrExport();
                }
                result = State();
                break;
            case "setMotive":
            {
                var actor = request.TryGetProperty("objectID", out var objIdVal) && objIdVal.TryGetInt16(out var oid) && world?.ObjectById(oid) is XPerson p
                    ? p : SelectedPerson();
                if (actor is null) throw new InvalidOperationException("No target Sim found.");
                var motiveName = request.TryGetProperty("motive", out var mVal) && mVal.ValueKind == JsonValueKind.String
                    ? mVal.GetString() : throw new ArgumentException("motive name required.");
                var motiveValue = request.TryGetProperty("value", out var vVal) && vVal.TryGetSingle(out var v)
                    ? v : throw new ArgumentException("motive value required.");
                if (!Enum.TryParse<Motive>(motiveName, true, out var motiveEnum))
                    throw new ArgumentException($"Unknown motive: {motiveName}");
                actor[motiveEnum] = Math.Clamp(motiveValue, -100f, 100f);
                if (motiveEnum == Motive.Mood && speed == 0) RefreshDynamicOrExport();
                result = State();
                break;
            }
            case "setTestPersonTile":
            {
                if (!testFixtureEnabled)
                    throw new InvalidOperationException("setTestPersonTile is available only in SIMS_NATIVE_TEST_FIXTURE=1 sessions");
                if (testFixtureStartPositionUsed)
                    throw new InvalidOperationException("The native test fixture start position can be set only once per session");
                if (speed != 0) throw new InvalidOperationException("The native test fixture requires speed 0");
                var actor = SelectedPerson();
                if (!ReferenceEquals(actor, RequestObject(request, "objectID")))
                    throw new ArgumentException("Test fixture placement must name the selected Sim");
                var queuedCount = unchecked(actor.ActionQueueEnd - actor.ActionQueueCurrent);
                if (actor.CurrentActionRecord is { Owner: not null } || queuedCount != 0 || actor.ActionQueue.Any(action => action.Owner is not null))
                    throw new InvalidOperationException("The native test fixture requires no started or queued action");
                if ((actor[ObjectData.ParentId] != 0 && actor[ObjectData.SlotHierNumber] > 0) || actor[ObjectData.ContainerId] != 0)
                    throw new InvalidOperationException("The native test fixture cannot reposition a parented or contained Sim");
                var tileX = request.TryGetProperty("tileX", out var tileXValue) && tileXValue.TryGetInt32(out var parsedTileX)
                    ? parsedTileX : throw new ArgumentException("tileX must be an integer lot tile");
                var tileY = request.TryGetProperty("tileY", out var tileYValue) && tileYValue.TryGetInt32(out var parsedTileY)
                    ? parsedTileY : throw new ArgumentException("tileY must be an integer lot tile");
                var height = request.TryGetProperty("height", out var heightValue) && heightValue.TryGetByte(out var parsedHeight)
                    ? parsedHeight : throw new ArgumentException("height must be a lot level byte");
                if (tileX < 0 || tileX >= LotWidth || tileY < 0 || tileY >= LotHeight)
                    throw new ArgumentException("Test fixture start tile is outside the lot");
                var destination = new ObjectPosition(tileX * 16 + 8, tileY * 16 + 8, height);
                var current = world ?? throw new InvalidOperationException("There is no loaded native lot");
                if (!current.CanPlaceObject(actor, destination))
                    throw new InvalidOperationException($"Native placement rejected test fixture start tile ({tileX},{tileY},{height}); error=0x{current.LastPlacementFailureCode:X2}");
                var originalPosition = actor.Position;
                current.PlaceObject(actor, destination);
                testFixtureStartPositionUsed = true;
                Console.Error.WriteLine($"Native test fixture start: sim={actor.Id} original=({originalPosition.X},{originalPosition.Y},{originalPosition.Height}) " +
                    $"placed=({actor.Position.X},{actor.Position.Y},{actor.Position.Height}) tile=({tileX},{tileY},{height}) actions=0");
                Export();
                result = new { objectID = actor.Id, tileX, tileY, height, x = actor.Position.X, y = actor.Position.Y,
                    room = actor.RoomWord84, actions = queuedCount };
                break;
            }
            case "testTileContents":
            {
                if (!testFixtureEnabled)
                    throw new InvalidOperationException("testTileContents is available only in SIMS_NATIVE_TEST_FIXTURE=1 sessions");
                var tileX = request.TryGetProperty("tileX", out var tileXValue) && tileXValue.TryGetInt32(out var parsedTileX)
                    ? parsedTileX : throw new ArgumentException("tileX must be an integer lot tile");
                var tileY = request.TryGetProperty("tileY", out var tileYValue) && tileYValue.TryGetInt32(out var parsedTileY)
                    ? parsedTileY : throw new ArgumentException("tileY must be an integer lot tile");
                var level = request.TryGetProperty("level", out var tileLevelValue) && tileLevelValue.TryGetInt32(out var parsedLevel)
                    ? parsedLevel : throw new ArgumentException("level must be an integer lot level");
                if (tileX < 0 || tileX >= LotWidth || tileY < 0 || tileY >= LotHeight || level < 1 || level > Stories)
                    throw new ArgumentException("Tile coordinates or level are outside the active lot");
                var current = world ?? throw new InvalidOperationException("There is no loaded native lot");
                result = new { tileX, tileY, level, objectIDs = current.ObjectsAtTile(tileX, tileY, level).Select(item => item.Id).ToArray() };
                break;
            }
            case "menu":
            {
                var actor = SelectedPerson();
                var clicked = RequestObject(request, "objectID");
                var target = InteractionMenus.Target(world!, clicked);
                var describedTarget = pluginWorld?.Describe(target);
                var nativeEntries = InteractionMenus.Read(world!, actor, clicked)
                    .Select(choice => (choice, interaction: MenuIndex(choice)))
                    .Where(item => plugins is null || describedTarget is null ||
                        plugins.AllowInteraction(actor.Id, describedTarget, new(item.interaction, item.choice.ActionText ?? "", item.choice.Parameters[0], false)))
                    .Select(item => (object)new
                    {
                        name = item.choice.ActionText ?? throw new NotSupportedException("Native interaction name is unavailable."),
                        interaction = item.interaction,
                        param0 = item.choice.Parameters[0],
                        global = false,
                        objectID = item.choice.Owner?.Id,
                    });
                var pluginEntries = (plugins is not null && describedTarget is not null && IsHouseholdPerson(actor)
                    ? plugins.MenuEntries(actor.Id, describedTarget)
                    : [])
                    .Select(entry => (object)new
                    {
                        name = entry.Name,
                        interaction = 0,
                        param0 = 0,
                        global = false,
                        plugin = entry.PackId,
                        entry = entry.Entry,
                    });
                result = nativeEntries.Concat(pluginEntries).ToArray();
                break;
            }
            case "groundMenu":
            {
                var actor = SelectedPerson();
                var (position, target) = GroundPreview(request);
                try
                {
                    var choices = InteractionMenus.Read(world!, actor, target)
                        .Select(choice => (object)new
                        {
                            name = choice.ActionText ?? throw new NotSupportedException("Native interaction name is unavailable."),
                            interaction = MenuIndex(choice),
                            param0 = choice.Parameters[0],
                            global = false,
                            objectID = choice.Owner?.Id,
                        }).ToList();
                    if (IsHouseholdPerson(actor) && plugins is not null)
                    {
                        var point = GroundPoint(world!, position);
                        foreach (var entry in plugins.GroundMenuEntries(actor.Id, point))
                        {
                            choices.Add(new
                            {
                                name = entry.Name,
                                interaction = (byte)0,
                                param0 = (short)0,
                                global = false,
                                objectID = (int?)0,
                                plugin = entry.PackId,
                                entry = entry.Entry,
                            });
                        }
                    }
                    result = choices.ToArray();
                }
                finally { world!.Remove(target.Id); }
                break;
            }
            case "groundInteract":
            {
                var actor = SelectedPerson();
                if (request.TryGetProperty("plugin", out var groundPack) && groundPack.ValueKind == JsonValueKind.String)
                {
                    if (!IsHouseholdPerson(actor)) throw new InvalidOperationException("Plugin menu entries are for household Sims");
                    if (plugins is null || pluginWorld is null) throw new InvalidOperationException("No pack plugins are loaded.");
                    var (pluginPos, pluginTarget) = GroundPreview(request, persistent: false);
                    try
                    {
                        var point = GroundPoint(world!, pluginPos);
                        result = plugins.ChooseGroundMenuEntry(actor.Id, point, groundPack.GetString() ?? "",
                            request.GetProperty("entry").GetString() ?? "");
                    }
                    finally { world!.Remove(pluginTarget.Id); }
                    break;
                }
                var (position, target) = GroundPreview(request, persistent: true);
                var retained = false;
                try
                {
                    var interactionId = request.TryGetProperty("interaction", out var interactionValue) && interactionValue.TryGetByte(out var parsedInteraction)
                        ? parsedInteraction : throw new ArgumentException("Interaction must be an unsigned 8-bit index.");
                    var param0 = request.TryGetProperty("param0", out var parameterValue) && parameterValue.TryGetInt16(out var parsedParameter)
                        ? parsedParameter : (short)0;
                    var choice = InteractionMenus.Read(world!, actor, target).FirstOrDefault(choice =>
                        MenuIndex(choice) == interactionId && choice.Parameters[0] == param0);
                    if (choice is null) throw new ArgumentException("Ground interaction is not currently available.");
                    if (world!.IsImmediateMenuInteraction(choice))
                    {
                        world.RunImmediateMenuInteraction(actor, choice);
                    }
                    else if (!world.EnqueueInteractionAction(actor, choice))
                    {
                        throw new InvalidOperationException("Native action queue rejected the ground interaction.");
                    }
                    retained = true;
                    result = new { queued = true, state = State() };
                }
                finally { if (!retained) world!.Remove(target.Id); }
                break;
            }
            case "interact":
            {
                var actor = SelectedPerson();
                var clicked = RequestObject(request, "objectID");
                var target = InteractionMenus.Target(world!, clicked);
                if (request.TryGetProperty("plugin", out var menuPack))
                {
                    if (!IsHouseholdPerson(actor)) throw new InvalidOperationException("Plugin menu entries are for household Sims");
                    if (plugins is null || pluginWorld is null) throw new InvalidOperationException("No pack plugins are loaded.");
                    result = plugins.ChooseMenuEntry(actor.Id, pluginWorld.Describe(target), menuPack.GetString() ?? "",
                        request.GetProperty("entry").GetString() ?? "");
                    break;
                }
                var interactionId = request.TryGetProperty("interaction", out var interactionValue) && interactionValue.TryGetByte(out var parsedInteraction)
                    ? parsedInteraction : throw new ArgumentException("Interaction must be an unsigned 8-bit index.");
                var param0 = request.TryGetProperty("param0", out var parameterValue) && parameterValue.TryGetInt16(out var parsedParameter) ? parsedParameter : (short)0;
                var global = request.TryGetProperty("global", out var globalValue) && globalValue.ValueKind == JsonValueKind.True;
                if (global) throw new NotSupportedException("Global interaction choices are not yet represented by the native menu engine.");
                var choice = InteractionMenus.Read(world!, actor, clicked).FirstOrDefault(candidate =>
                    MenuIndex(candidate) == interactionId && candidate.Parameters[0] == param0 &&
                    (plugins is null || pluginWorld is null || plugins.AllowInteraction(actor.Id, pluginWorld.Describe(target),
                        new(interactionId, candidate.ActionText ?? "", candidate.Parameters[0], false))));
                if (choice is null) throw new ArgumentException("Interaction is not currently available");
                if (world!.IsImmediateMenuInteraction(choice))
                {
                    world.RunImmediateMenuInteraction(actor, choice);
                }
                else if (!world.EnqueueInteractionAction(actor, choice))
                {
                    throw new InvalidOperationException("Native action queue is full or rejected the interaction.");
                }
                result = State();
                break;
            }
            case "catalog":
                if (registry is null) throw new InvalidOperationException("There is no loaded native object catalog.");
                result = new
                {
                    floors = FloorCatalogPage.All(game, language),
                    walls = WallCatalogPage.All(game, language),
                    objects = ObjectCatalog.All(registry, language),
                };
                break;
            case "buyCatalogViews":
            {
                if (registry is null) throw new InvalidOperationException("There is no loaded native object catalog.");
                var views = ResolveBuyCatalogViews();
                result = new
                {
                    views = views.Select(v => new
                    {
                        packId = v.PackId,
                        tabId = v.View.TabId,
                        tabLabel = v.View.TabLabel,
                        hotkey = v.View.Hotkey,
                        hideMatchedFromStandardCatalog = v.View.HideMatchedFromStandardCatalog,
                        collections = v.View.Collections.Select(c => new
                        {
                            id = c.Id,
                            label = c.Label,
                            tooltip = c.Tooltip,
                            count = c.Guids.Length,
                        }).ToArray(),
                    }).ToArray(),
                };
                break;
            }
            case "catalogPage":
            {
                if (registry is null) throw new InvalidOperationException("There is no loaded native object catalog.");
                var offset = request.TryGetProperty("offset", out var offsetValue) && offsetValue.TryGetInt32(out var parsedOffset)
                    ? parsedOffset : throw new ArgumentException("offset must be an integer");
                var count = request.TryGetProperty("count", out var countValue) && countValue.TryGetInt32(out var parsedCount)
                    ? parsedCount : throw new ArgumentException("count must be an integer");
                var pluginPackId = request.TryGetProperty("pluginPackId", out var ppEl) && ppEl.ValueKind == JsonValueKind.String ? ppEl.GetString() : null;
                var pluginTabId = request.TryGetProperty("pluginTabId", out var ptEl) && ptEl.ValueKind == JsonValueKind.String ? ptEl.GetString() : null;
                var pluginCollectionId = request.TryGetProperty("pluginCollectionId", out var pcEl) && pcEl.ValueKind == JsonValueKind.String ? pcEl.GetString() : null;
                if (!string.IsNullOrEmpty(pluginPackId) && !string.IsNullOrEmpty(pluginTabId) && !string.IsNullOrEmpty(pluginCollectionId))
                {
                    var views = ResolveBuyCatalogViews();
                    var collection = views
                        .FirstOrDefault(v => string.Equals(v.PackId, pluginPackId, StringComparison.Ordinal)
                            && string.Equals(v.View.TabId, pluginTabId, StringComparison.Ordinal))
                        ?.View.Collections
                        .FirstOrDefault(c => string.Equals(c.Id, pluginCollectionId, StringComparison.Ordinal));
                    var guids = collection?.Guids ?? [];
                    result = ObjectCatalog.PageByGuids(registry, language, guids, offset, count, SceneDirectory, game, CurrentCatalogLotType());
                    var previousPluginWt = wallpaperBuildToolActive;
                    wallpaperBuildToolActive = false;
                    if (doorWindowBuildToolActive)
                    {
                        doorWindowBuildToolActive = false;
                        Export();
                    }
                    else if (previousPluginWt && wallMode == "cutaway" && world is not null && lot is not null &&
                        !SceneExporter.CutawayMaskMatches(world, animationState, revision, viewLevel, wallMode, cameraOrientation,
                            cutawayTile, cutawayRooms, CutawaySimTile(), cutawayZoom, raiseHoveredWalls: false))
                    {
                        Export();
                    }
                    break;
                }
                var category = request.TryGetProperty("category", out var categoryValue) && categoryValue.TryGetInt32(out var parsedCategory)
                    ? parsedCategory : throw new ArgumentException("category must be an integer from 0 through 12");
                var room = request.TryGetProperty("room", out var roomValue) && roomValue.TryGetInt32(out var parsedRoom) ? parsedRoom : (int?)null;
                int? subsort = null;
                if (request.TryGetProperty("subsort", out var subsortValue))
                    subsort = subsortValue.TryGetInt32(out var parsedSubsort)
                        ? parsedSubsort : throw new ArgumentException("subsort must be an integer from 0 through 7");
                var hiddenGuids = ResolveHiddenCatalogGuids();
                result = ObjectCatalog.Page(registry, language, category, offset, count, SceneDirectory, room, subsort, game, CurrentCatalogLotType(), hiddenGuids);
                var requestedDoorWindowTool = editingView && category is 8 or 9;
                var previousBuyWt = wallpaperBuildToolActive;
                wallpaperBuildToolActive = false;
                if (doorWindowBuildToolActive != requestedDoorWindowTool)
                {
                    doorWindowBuildToolActive = requestedDoorWindowTool;
                    Export();
                }
                else if (previousBuyWt && wallMode == "cutaway" && world is not null && lot is not null &&
                    !SceneExporter.CutawayMaskMatches(world, animationState, revision, viewLevel, wallMode, cameraOrientation,
                        cutawayTile, cutawayRooms, CutawaySimTile(), cutawayZoom, raiseHoveredWalls: false))
                {
                    Export();
                }
                break;
            }
            case "buildCatalogPage":
            {
                var kind = request.TryGetProperty("kind", out var kindValue) ? kindValue.GetString() : null;
                if (kind is not ("floor" or "wall" or "wallStyle" or "roof" or "water")) throw new NotSupportedException($"The native build catalog does not support '{kind}' patterns");
                var requestedWallpaperTool = editingView && string.Equals(kind, "wall", StringComparison.OrdinalIgnoreCase);
                var wallpaperToolChanged = wallpaperBuildToolActive != requestedWallpaperTool;
                wallpaperBuildToolActive = requestedWallpaperTool;
                if (doorWindowBuildToolActive)
                {
                    doorWindowBuildToolActive = false;
                    Export();
                }
                else if (wallpaperToolChanged && wallMode == "cutaway" && world is not null && lot is not null &&
                    !SceneExporter.CutawayMaskMatches(world, animationState, revision, viewLevel, wallMode, cameraOrientation,
                        cutawayTile, cutawayRooms, CutawaySimTile(), cutawayZoom, raiseHoveredWalls: wallpaperBuildToolActive))
                {
                    Export();
                }
                var offset = request.TryGetProperty("offset", out var offsetValue) && offsetValue.TryGetInt32(out var parsedOffset)
                    ? parsedOffset : throw new ArgumentException("offset must be an integer");
                var count = request.TryGetProperty("count", out var countValue) && countValue.TryGetInt32(out var parsedCount)
                    ? parsedCount : throw new ArgumentException("count must be an integer");
                result = kind switch
                {
                    "floor" => FloorCatalogPage.Page(game, language, offset, count, SceneDirectory),
                    "water" => registry is null
                        ? throw new InvalidOperationException("There is no loaded native object catalog.")
                        : FloorCatalogPage.WaterPage(game, registry, language, offset, count, SceneDirectory),
                    "wallStyle" => registry is null
                        ? throw new InvalidOperationException("There is no loaded native object catalog.")
                        : SpecialBuildCatalogPage.WallStyles(game, registry, language, offset, count, SceneDirectory),
                    "roof" => SpecialBuildCatalogPage.Roofs(game, offset, count, SceneDirectory),
                    _ => WallCatalogPage.Page(game, language, offset, count, SceneDirectory),
                };
                break;
            }
            case "previewObject":
                result = PreviewObject(request);
                break;
            case "buildCursor":
                result = PreviewObject(request, cursor: true);
                break;
            case "buyObject":
            {
                EnsureLotEditingAllowed();
                RemoveTileCursor();
                var item = BuyObject(request, out var boughtPrice);
                saveDirty = true;
                Export();
                result = new
                {
                    bought = true,
                    objectID = item.Id,
                    guid = unchecked((uint)(item.TypeRecord?.Key ?? 0)),
                    price = boughtPrice,
                    budget = world!.FamilyBudget!.ReadFamilyBudget(),
                };
                break;
            }
            case "sellObject":
            {
                EnsureLotEditingAllowed();
                result = SellObject(request);
                MarkSaveDirtyIfChanged(result);
                Export();
                break;
            }
            case "moveObject":
            {
                EnsureLotEditingAllowed();
                result = MoveObject(request);
                MarkSaveDirtyIfChanged(result);
                Export();
                break;
            }
            case "architecture":
            {
                EnsureLotEditingAllowed();
                result = Architecture(request);
                MarkSaveDirtyIfChanged(result);
                var archCmd = request.TryGetProperty("command", out var archCmdValue) ? archCmdValue.GetString() : null;
                var skipNoOpPatternExport = streaming &&
                    archCmd is "PATTERN_DOT" or "PATTERN_ERASE" or "PATTERN_FILL" or "PATTERN_FILL_ERASE" &&
                    result?.GetType().GetProperty("changed")?.GetValue(result) is int changedCount &&
                    changedCount == 0;
                if (!skipNoOpPatternExport)
                    Export();
                break;
            }
            case "architectureBatch":
            {
                EnsureLotEditingAllowed();
                result = ArchitectureBatch(request);
                MarkSaveDirtyIfChanged(result);
                Export();
                break;
            }
            case "roof":
            {
                EnsureLotEditingAllowed();
                result = RoofSettings(request);
                MarkSaveDirtyIfChanged(result);
                Export();
                break;
            }
            case "undo":
            case "redo":
            {
                EnsureLotEditingAllowed();
                result = ArchitectureHistory(request.GetProperty("op").GetString() == "undo");
                MarkSaveDirtyIfChanged(result);
                Export();
                break;
            }
            case "cancelAction":
            {
                var actor = SelectedPerson();
                var requestedActor = RequestObject(request, "objectID");
                if (!ReferenceEquals(actor, requestedActor)) throw new ArgumentException("Action belongs to another Sim");
                var token = request.TryGetProperty("token", out var tokenValue) && tokenValue.ValueKind == JsonValueKind.String
                    ? tokenValue.GetString() : null;
                var prefix = $"native-{actor.Id}-";
                if (token is null || !token.StartsWith(prefix, StringComparison.Ordinal) ||
                    !int.TryParse(token.AsSpan(prefix.Length), out var sequence))
                    throw new ArgumentException("Action is no longer cancellable");
                ActionQueueSlot? matchedCancel = null;
                if (actor.CurrentActionRecord is { Owner: not null } curRec && curRec.Sequence == sequence)
                    matchedCancel = curRec;
                else
                    matchedCancel = actor.ActionQueue.FirstOrDefault(slot => slot.Owner is not null && slot.Sequence == sequence);
                var cancelTargetId = matchedCancel?.Owner is { } cancelOwner
                    ? InteractionMenus.Target(world!, cancelOwner).Id
                    : (short)0;
                var cancelActionId = matchedCancel?.RawDword10 ?? -1;
                if (!world!.CancelInteractionAction(actor, sequence))
                    throw new ArgumentException("Action is no longer cancellable");
                if (cancelTargetId != 0 && cancelActionId >= 0)
                    plugins?.NotifyPlayerCancelledAction(actor.Id, cancelTargetId, cancelActionId);
                result = State();
                break;
            }
            case "dialogResponse":
            {
                if (world is null) throw new InvalidOperationException("There is no loaded native lot.");
                var token = request.TryGetProperty("token", out var tokenValue) && tokenValue.ValueKind == JsonValueKind.String
                    ? tokenValue.GetString() : null;
                var code = request.TryGetProperty("code", out var codeValue) && codeValue.TryGetByte(out var responseCode)
                    ? responseCode : throw new ArgumentException("Dialog response code must be a byte.");
                var responseText = request.TryGetProperty("text", out var textValue)
                    ? textValue.ValueKind == JsonValueKind.String ? textValue.GetString() : throw new ArgumentException("Dialog response text must be a string.")
                    : null;
                if (token is null) throw new ArgumentException("Dialog response token is required.");
                world.RespondMessageDialog(token, code, responseText);
                if (HasBlockingDialog(world))
                {
                    SetSimulationSpeed(0, blockingDialog: true);
                }
                else
                {
                    if (dialogResumeSpeed > 0) SetSimulationSpeed(dialogResumeSpeed);
                    dialogResumeSpeed = 0;
                }
                result = State();
                RefreshDynamicOrExport();
                break;
            }
            case "genericSimsCallPersonPicker":
            {
                var current = world ?? throw new InvalidOperationException("There is no loaded native lot.");
                if (request.TryGetProperty("requestID", out var requestIDValue))
                {
                    if (!requestIDValue.TryGetInt64(out var requestID))
                        throw new ArgumentException("GenericSimsCall requestID must be an integer.");
                    var rowIndex = request.TryGetProperty("personRecordIndex", out var rowIndexValue) &&
                                   rowIndexValue.TryGetInt32(out var parsedRowIndex)
                        ? parsedRowIndex : throw new ArgumentException("personRecordIndex must be an integer.");
                    var accepted = current.TryChooseGenericSimsCallPerson(requestID, rowIndex);
                    result = new { accepted, state = State() };
                    break;
                }

                var pendingRequests = current.GenericSimsCallRequests.Snapshot();
                var pending = pendingRequests.FirstOrDefault(candidate =>
                    candidate.Status == 0 && candidate.Kind == GenericSimsCallRequestKind.Second &&
                    pendingRequests.FirstOrDefault(first => first.PersonKey == candidate.PersonKey).Id == candidate.Id);
                if (pending.Id == 0 ||
                    current.WalkOrder.OfType<XPerson>().FirstOrDefault(person => person.StackObjectKey == pending.Temporary0) is not { } owner)
                {
                    result = null;
                    break;
                }

                int? viewerCenterX = request.TryGetProperty("centerX", out var centerXValue) && centerXValue.TryGetInt32(out var parsedCenterX)
                    ? parsedCenterX : null;
                int? viewerCenterY = request.TryGetProperty("centerY", out var centerYValue) && centerYValue.TryGetInt32(out var parsedCenterY)
                    ? parsedCenterY : null;
                if (viewerCenterX.HasValue != viewerCenterY.HasValue)
                    throw new ArgumentException("GenericSimsCall chooser viewer center requires both coordinates.");
                var personCountBefore = current.WalkOrder.OfType<XPerson>().Count();
                var candidates = current.GenericSimsCallChooserCandidates(owner, viewerCenterX, viewerCenterY);
                if (current.WalkOrder.OfType<XPerson>().Count() != personCountBefore) Export();

                result = new
                {
                    requestID = pending.Id,
                    personKey = pending.PersonKey,
                    requestTarget = pending.Temporary0,
                    candidates,
                };
                break;
            }
            case "appearanceCatalog":
            {
                var reg = EnsureRegistry();
                var gender = request.GetProperty("gender").GetString()!;
                var age = request.GetProperty("age").GetString()!;
                var skin = request.GetProperty("skin").GetString()!;
                var catalog = HouseholdAppearance.Catalog(game, reg, gender, age, skin);
                result = catalog;
                break;
            }
            case "appearancePreview":
            {
                var reg = EnsureRegistry();
                var gender = request.GetProperty("gender").GetString()!;
                var age = request.GetProperty("age").GetString()!;
                var skin = request.GetProperty("skin").GetString()!;
                var headChoice = request.GetProperty("headChoice").GetString()!;
                var bodyChoice = request.GetProperty("bodyChoice").GetString()!;
                var portrait = request.TryGetProperty("portrait", out var portraitProp) && portraitProp.ValueKind is JsonValueKind.True;
                result = HouseholdAppearancePreview.Export(session, game, reg, gender, age, skin, headChoice, bodyChoice, portrait);
                break;
            }
            case "createHousehold":
                result = CreateHousehold(request);
                break;
            case "moveInFamily":
                result = MoveInFamily(request);
                break;
            case "warmup":
            {
                var reg = EnsureRegistry();
                _ = WorldBootstrap.GetOrLoadGlobalLibrary(game);
                _ = WorldBootstrap.GetOrLoadCareers(game);
                AvatarAnimations.GetSharedIndex(game, reg);
                _ = AvatarSceneGeometry.For(game, reg);
                result = new { warmed = true, entries = reg.Entries.Count };
                break;
            }
            case "openLot":
            {
                var requestedHouse = request.TryGetProperty("house", out var houseProp) && houseProp.TryGetInt16(out var hVal) && hVal > 0
                    ? hVal : throw new ArgumentException("house must be a positive integer");
                ushort? moveInFamily = request.TryGetProperty("moveInFamily", out var moveInFamProp) && moveInFamProp.ValueKind != JsonValueKind.Null
                    ? (moveInFamProp.TryGetUInt16(out var parsedMoveInFam) ? parsedMoveInFam : throw new ArgumentException("moveInFamily must be an unsigned 16-bit family id"))
                    : null;
                ushort? activeFamilyOverride = request.TryGetProperty("activeFamily", out var activeFamProp) && activeFamProp.ValueKind != JsonValueKind.Null
                    ? (activeFamProp.TryGetUInt16(out var parsedActiveFam) ? parsedActiveFam : throw new ArgumentException("activeFamily must be an unsigned 16-bit family id"))
                    : null;
                int? centerX = request.TryGetProperty("centerX", out var cxProp) && cxProp.TryGetInt32(out var cxVal) ? cxVal : null;
                int? centerY = request.TryGetProperty("centerY", out var cyProp) && cyProp.TryGetInt32(out var cyVal) ? cyVal : null;
                result = OpenLotInternal(requestedHouse, moveInFamily, activeFamilyOverride, (centerX, centerY));
                break;
            }
            case "closeLot":
            {
                var saveBeforeClose = request.TryGetProperty("save", out var saveProp) && saveProp.ValueKind == JsonValueKind.True;
                result = CloseLotInternal(saveBeforeClose);
                Write(new { type = "state", state = State() });
                break;
            }
            case "neighborhood":
            {
                var neighborhoodMode = request.TryGetProperty("mode", out var modeValue) ? modeValue.GetInt32() : 1;
                if (request.TryGetProperty("neighborhood", out var neighborhoodValue) &&
                    neighborhoodValue.ValueKind == JsonValueKind.Number &&
                    neighborhoodValue.TryGetInt32(out var requestedNeighborhood))
                {
                    if (requestedNeighborhood is < 1 or > Neighborhoods.Maximum)
                        throw new ArgumentException("neighborhood must be a neighborhood number from 1 through 99");
                    if (requestedNeighborhood != Neighborhoods.Current)
                    {
                        Neighborhoods.Current = requestedNeighborhood;
                        var folderName = Neighborhoods.DirectoryName(requestedNeighborhood);
                        var installRoot = ResolveInstallRoot();
                        if (!Directory.Exists(Path.Combine(profile, folderName)) || Directory.Exists(Path.Combine(installRoot, folderName)))
                            ProfileBootstrap.EnsureNeighborhoodImported(installRoot, profile, Neighborhoods.Current);
                        var nghDir = Neighborhoods.UserData(profile);
                        if (!File.Exists(Path.Combine(nghDir, "Neighborhood.iff")))
                            throw new InvalidOperationException($"Neighborhood {Neighborhoods.Current} is not installed in this profile");
                        this.neighborhood = null;
                        this.neighborhoodPath = null;
                        world?.ClearAllRemovedNeighbors();
                        if (registry is not null)
                            registry = registry.WithRefreshedPeople(Path.Combine(nghDir, "Characters"));
                    }
                }
                if (request.TryGetProperty("edit", out var editValue) &&
                    editValue.ValueKind == JsonValueKind.String &&
                    editValue.GetString() is { Length: > 0 } editSpec)
                {
                    var installRoot = ResolveInstallRoot();
                    foreach (var singleEdit in editSpec.Split(';', StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries))
                        NeighborhoodEdits.Apply(singleEdit, installRoot, profile, language, neighborhoodMode);
                    world?.ClearAllRemovedNeighbors();
                    var nghDiskPath = Path.Combine(Neighborhoods.UserData(profile), "Neighborhood.iff");
                    if (world is null)
                    {
                        this.neighborhood = null;
                        this.neighborhoodPath = null;
                    }
                    else if (File.Exists(nghDiskPath))
                    {
                        this.neighborhoodPath = nghDiskPath;
                        this.neighborhood = IffFile.Open(nghDiskPath);
                    }
                    if (registry is not null)
                        registry = registry.WithRefreshedPeople(Path.Combine(Neighborhoods.UserData(profile), "Characters"));
                }
                var outputDirectory = request.TryGetProperty("outputDirectory", out var outDirValue) &&
                    outDirValue.ValueKind == JsonValueKind.String &&
                    outDirValue.GetString() is { Length: > 0 } customDir
                    ? Path.GetFullPath(customDir)
                    : session;
                Directory.CreateDirectory(outputDirectory);
                var webScenes = request.TryGetProperty("webScenes", out var webScenesValue) && webScenesValue.ValueKind == JsonValueKind.True;
                var exportInstallRoot = ResolveInstallRoot();
                NeighborhoodExport.GameRoot = game;
                if (neighborhoodMode is 2 or 3 or 4 or 5 or 7)
                    lastTravelNeighborhoodMode = neighborhoodMode;
                result = NeighborhoodExport.Export(outputDirectory, neighborhoodMode, profile, language, dataRoot, exportInstallRoot,
                    includeRenderScenes: webScenes, existingRegistry: registry, mountRoot: game, packOverlay: packOverlay);
                if (neighborhoodMode is 2 or 3 or 5 or 7)
                {
                    var manifestPath = Path.Combine(outputDirectory, "neighborhood.json");
                    var slot = TravelFilterSlotForMode(neighborhoodMode);
                    var fallback = neighborhoodMode is 5 or 7 ? 0x400 : 2;
                    var filter = TravelFilter.Load(Neighborhoods.UserData(profile), slot, language, fallback);
                    if (File.Exists(manifestPath) && JsonNode.Parse(File.ReadAllBytes(manifestPath)) is JsonObject manifestObj)
                    {
                        manifestObj["travelFilter"] = filter;
                        if (neighborhoodMode is 2 or 3 or 5 && manifestObj["entries"] is JsonArray entriesArray)
                        {
                            foreach (var node in entriesArray)
                            {
                                if (node is not JsonObject entryObj) continue;
                                var house = entryObj["house"]?.GetValue<int>() ?? 0;
                                var residential = entryObj["residential"]?.GetValue<bool>() == true;
                                var isExpansionCommunity = !residential && (
                                    (neighborhoodMode == 2 && house is >= 21 and <= 30) ||
                                    (neighborhoodMode == 3 && house is >= 40 and <= 49) ||
                                    (neighborhoodMode == 5 && house is >= 81 and <= 89));
                                if (isExpansionCommunity && entryObj["community"]?.GetValue<bool>() != true)
                                    entryObj["community"] = true;
                            }
                        }
                        WriteReplace(manifestPath, JsonSerializer.SerializeToUtf8Bytes(manifestObj, new JsonSerializerOptions { WriteIndented = true }));
                        result = manifestObj;
                    }
                }
                break;
            }
            case "saveBackups":
            {
                var backupSlot = Slot(request);
                result = new { slot = backupSlot, backups = SaveCompatibility.List(profile, Neighborhoods.StorageSlot(backupSlot, Neighborhoods.Current)) };
                break;
            }
            case "restoreBackup":
            {
                var restoreSlot = Slot(request);
                var storageSlot = Neighborhoods.StorageSlot(restoreSlot, Neighborhoods.Current);
                var envelopePath = SaveEnvelopePath(restoreSlot);
                var restored = SaveCompatibility.Restore(profile, storageSlot, envelopePath, request.GetProperty("backup").GetString() ?? "");
                if (File.Exists(envelopePath) &&
                    JsonSerializer.Deserialize<SaveEnvelope>(File.ReadAllBytes(envelopePath), Json) is { State.Length: > 0 } restoredEnvelope)
                {
                    Directory.CreateDirectory(Saves);
                    WriteReplace(SavePath(restoreSlot), Convert.FromBase64String(restoredEnvelope.State));
                    if (restoredEnvelope.Runtime is not null)
                        WriteReplace(SaveRuntimePath(restoreSlot), JsonSerializer.SerializeToUtf8Bytes(restoredEnvelope.Runtime, Json));
                    if (!string.IsNullOrEmpty(restoredEnvelope.NeighborhoodState))
                        WriteReplace(SaveNeighborhoodPath(restoreSlot), Convert.FromBase64String(restoredEnvelope.NeighborhoodState));
                }
                result = restored;
                break;
            }

            case "outfitChoices":
            {
                if (world is null) throw new InvalidOperationException("No lot is loaded.");
                var outfits = engineOutfits ??= new SimOutfits(game, registry ?? throw new InvalidOperationException("There is no loaded native object catalog."), language);
                var context = outfits.Find(world);
                var choices = outfits.Choices(context);
                result = new
                {
                    pet = context.Pet,
                    choices = choices.Select(c => new { name = c.Appearance }).ToArray()
                };
                break;
            }
            case "outfitPreview":
            {
                if (world is null) throw new InvalidOperationException("No lot is loaded.");
                var index = request.GetProperty("index").GetInt32();
                var outfits = engineOutfits ??= new SimOutfits(game, registry ?? throw new InvalidOperationException("There is no loaded native object catalog."), language);
                var context = outfits.Find(world);
                result = outfits.Preview(session, context, index);
                break;
            }
            case "freeWill":
            {
                if (!request.TryGetProperty("enabled", out var enabledValue) ||
                    enabledValue.ValueKind is not (JsonValueKind.True or JsonValueKind.False))
                    throw new ArgumentException("Free Will requires a boolean enabled value.");
                if (world is not null)
                {
                    world.AutonomyForced = enabledValue.GetBoolean();
                }
                if (world?.AutonomyForced == false && simulationError?.Contains("opcode 0x3", StringComparison.Ordinal) == true)
                    simulationError = null;
                result = State();
                break;
            }
            case "cheat":
            {
                var rawCode = request.TryGetProperty("code", out var codeValue) && codeValue.ValueKind == JsonValueKind.String
                    ? codeValue.GetString()?.Trim() : null;
                if (string.IsNullOrEmpty(rawCode))
                {
                    result = new { applied = false, code = "" };
                    break;
                }

                string[] knownCheats =
                [
                    "rosebud", "klapaucius", "motherlode", "move_objects", "autonomy", "set_hour",
                    "water_tool", "map_edit", "magic_tokens", "nessie", "cars",
                    .. (plugins?.CheatCommands ?? []),
                    "help"
                ];

                var rawSegments = rawCode.Split(';')
                    .Select(s => s.Trim())
                    .Where(s => s.Length > 0)
                    .ToArray();
                if (rawSegments.Length == 0)
                {
                    result = new { applied = false, code = "" };
                    break;
                }

                object? lastResult = null;
                foreach (var rawSegment in rawSegments)
                {
                    var tokens = rawSegment.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                    if (tokens[0] == "!")
                    {
                        if (string.IsNullOrEmpty(lastCheatCommand))
                            throw new ArgumentException("Sorry: No previous cheat.");
                        if (tokens.Length == 1)
                        {
                            tokens = lastCheatCommand.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                        }
                        else
                        {
                            var prevCmd = lastCheatCommand.Split(' ', StringSplitOptions.RemoveEmptyEntries)[0];
                            tokens = [prevCmd, .. tokens[1..]];
                        }
                    }

                    var segment = string.Join(' ', tokens);
                    var cmd = tokens[0].ToLowerInvariant();
                    switch (cmd)
                    {
                        case "rosebud":
                        case "klapaucius":
                        {
                            if (world?.FamilyBudget is not FamilyBudget budget || budget.ActiveFamily is null)
                                throw new InvalidOperationException("Rosebud requires an active family on a lot.");
                            budget.AlterFamilyBudget(0, -1000);
                            Export();
                            lastResult = new { applied = true, code = cmd, amount = 1000, budget = budget.ReadFamilyBudget() };
                            break;
                        }
                        case "motherlode":
                        {
                            if (world?.FamilyBudget is not FamilyBudget budget || budget.ActiveFamily is null)
                                throw new InvalidOperationException("Motherlode requires an active family on a lot.");
                            budget.AlterFamilyBudget(0, -100000);
                            Export();
                            lastResult = new { applied = true, code = cmd, amount = 100000, budget = budget.ReadFamilyBudget() };
                            break;
                        }
                        case "move_objects":
                        {
                            if (tokens.Length != 2 ||
                                (!string.Equals(tokens[1], "on", StringComparison.OrdinalIgnoreCase) &&
                                 !string.Equals(tokens[1], "off", StringComparison.OrdinalIgnoreCase)))
                                throw new ArgumentException("Cheat Error: Usage: move_objects <on|off>");
                            if (world is null) throw new InvalidOperationException("There is no loaded native lot.");
                            var enabled = string.Equals(tokens[1], "on", StringComparison.OrdinalIgnoreCase);
                            world.FindLocationWaterOverride = enabled;
                            Export();
                            lastResult = new { applied = true, code = enabled ? "move_objects on" : "move_objects off", moveObjects = enabled };
                            break;
                        }
                        case "autonomy":
                        {
                            if (tokens.Length != 2 || !int.TryParse(tokens[1], out var level) || level is < 0 or > 100)
                                throw new ArgumentException("Cheat Error: Usage: autonomy <0-100>");
                            if (world is null) throw new InvalidOperationException("There is no loaded native lot.");
                            world.AutonomyForced = level > 0;
                            Export();
                            lastResult = new { applied = true, code = $"autonomy {level}", autonomy = level, freeWill = world.AutonomyForced };
                            break;
                        }
                        case "set_hour":
                        {
                            if (tokens.Length != 2 || !int.TryParse(tokens[1], out var parsedHour) || parsedHour is < 1 or > 24)
                                throw new ArgumentException("Cheat Error: Usage: set_hour <1-24>");
                            if (world is null) throw new InvalidOperationException("There is no loaded native lot.");
                            var normalizedHour = parsedHour == 24 ? 0 : parsedHour;
                            static void SyncWorldClockAndRooms(SimulationWorld targetWorld, int hour, int minute, int second)
                            {
                                targetWorld.Clock.Restore(hour, minute, second);
                                targetWorld[SimulationGlobal.Hour] = checked((short)targetWorld.Clock.Hour);
                                targetWorld[SimulationGlobal.Minute] = checked((short)targetWorld.Clock.Minute);
                                targetWorld[SimulationGlobal.Second] = checked((short)targetWorld.Clock.Second);
                                targetWorld[SimulationGlobal.TimeOfDay] = checked((short)targetWorld.Clock.TimeOfDay);
                                if (targetWorld.RoomManagerRecordsLoaded)
                                {
                                    foreach (var roomId in targetWorld.PersonRoomMotiveEntries.Keys.ToArray())
                                        targetWorld.RefreshRoomRecord(roomId);
                                    targetWorld.RefreshDirtyRoomRecords();
                                }
                            }
                            SyncWorldClockAndRooms(world, normalizedHour, world.Clock.Minute, world.Clock.Second);
                            Export();
                            lastResult = new { applied = true, code = $"set_hour {parsedHour}", hour = world.Clock.Hour };
                            break;
                        }
                        case "water_tool":
                        {
                            if (tokens.Length > 1)
                                throw new ArgumentException("Cheat Error: Usage: water_tool");
                            lastResult = new { applied = true, code = "water_tool" };
                            break;
                        }
                        case "map_edit":
                        {
                            if (tokens.Length != 2 ||
                                (!string.Equals(tokens[1], "on", StringComparison.OrdinalIgnoreCase) &&
                                 !string.Equals(tokens[1], "off", StringComparison.OrdinalIgnoreCase)))
                                throw new ArgumentException("Cheat Error: Usage: map_edit <on|off>");
                            var enabled = string.Equals(tokens[1], "on", StringComparison.OrdinalIgnoreCase);
                            lastResult = new { applied = true, code = enabled ? "map_edit on" : "map_edit off", mapEdit = enabled };
                            break;
                        }
                        case "magic_tokens":
                        {
                            if (tokens.Length > 2)
                                throw new ArgumentException("Cheat Error: Usage: magic_tokens [0-10000]");
                            var amount = 1000;
                            if (tokens.Length == 2 && (!int.TryParse(tokens[1], out amount) || amount is < 0 or > 10000))
                                throw new ArgumentException("Cheat Error: Usage: magic_tokens [0-10000]");
                            var targetPerson = SelectedPerson();
                            if (world is null || targetPerson is null)
                                throw new InvalidOperationException("magic_tokens requires a selected Sim on a loaded lot.");
                            var neighborId = targetPerson[PersonData.NeighborId];
                            var inv = world.NeighborInventory(neighborId);
                            inv.Add(7, unchecked((int)NeighborhoodExport.MagiCoinTokenGuid), checked((short)amount));
                            Export();
                            lastResult = new { applied = true, code = "magic_tokens", amount, neighborId };
                            break;
                        }
                        case "nessie":
                        {
                            Write(new { type = "neighborhoodCheat", code = "nessie" });
                            lastResult = new { applied = true, code = "nessie" };
                            break;
                        }
                        case "cars":
                        {
                            var carSpeed = tokens.Length >= 2 && int.TryParse(tokens[1], out var parsedSpeed) && parsedSpeed is >= 1 and <= 2 ? parsedSpeed : 1;
                            var carCount = tokens.Length >= 3 && int.TryParse(tokens[2], out var parsedCount) && parsedCount > 0 ? Math.Min(parsedCount, 40) : 1;
                            Write(new { type = "neighborhoodCheat", code = "cars", speed = carSpeed, count = carCount });
                            lastResult = new { applied = true, code = "cars", speed = carSpeed, count = carCount };
                            break;
                        }
                        case "help":
                        {
                            if (tokens.Length > 2)
                                throw new ArgumentException("Cheat Error: Usage: help [search]");
                            var filter = tokens.Length == 2 ? tokens[1] : null;
                            var matches = string.IsNullOrEmpty(filter)
                                ? knownCheats
                                : knownCheats.Where(c => c.Contains(filter, StringComparison.OrdinalIgnoreCase)).ToArray();
                            var text = matches.Length > 0
                                ? string.Join(", ", matches)
                                : "Sorry, no cheats match the search string.";
                            lastResult = new { applied = true, code = segment, cheats = matches, message = text };
                            break;
                        }
                        default:
                        {
                            var cheatArgs = tokens.Length > 1 ? tokens[1..] : [];
                            if (plugins is not null && plugins.TryHandleCheat(cmd, cheatArgs, out var cheatMessage))
                            {
                                plugins.FlushClientStates();
                                if (world is not null)
                                {
                                    Export();
                                }
                                lastResult = new { applied = true, code = segment, message = cheatMessage };
                                break;
                            }
                            throw new ArgumentException("Sorry: No such cheat.");
                        }
                    }
                    lastCheatCommand = segment;
                }
                result = lastResult;
                break;
            }
            case "pictureInPicture":
            {
                if (!request.TryGetProperty("live", out var liveValue) ||
                    liveValue.ValueKind is not (JsonValueKind.True or JsonValueKind.False))
                    throw new ArgumentException("Picture-in-picture requires a boolean live value.");
                pictureInPicture.Live = liveValue.GetBoolean();
                result = State();
                break;
            }
            case "audio":
                audio!.Enable(request.GetProperty("enabled").GetBoolean());
                if (house > 0 && world is not null)
                    audio.PlayLotAmbience(house);
                result = new { enabled = audio.Enabled };
                break;
            case "audioEvent":
            {
                if (!audio!.Enabled)
                {
                    result = new { played = false };
                    break;
                }
                var name = request.GetProperty("name").GetString()!;
                int? owner = request.TryGetProperty("ownerID", out var ov) ? ov.GetInt32() : null;
                result = new { played = audio.Play(name, owner) };
                break;
            }
            case "audioStopOwner":
                audio!.RemoveOwner(request.GetProperty("ownerID").GetInt32());
                result = new { removed = true };
                break;
            case "modeMusic":
            {
                var mode = request.GetProperty("mode").GetString()!;
                audio!.StopModeMusic();
                var isLive = mode.Equals("live", StringComparison.OrdinalIgnoreCase);
                audio.SetMusicModeActive(!isLive);
                var track = ModeMusic(mode);
                var played = !string.IsNullOrEmpty(track) && audio.Play(track, -1);
                result = new { name = track, played };
                break;
            }
            case "audioEnded":
                audio!.End(request.GetProperty("voice").GetInt64());
                result = new { accepted = true };
                break;
            case "audioVolume":
                audio!.SetVolume(request.GetProperty("group").GetString()!, request.GetProperty("volume").GetSingle());
                result = audio.State();
                break;
            case "audioState": result = audio!.State(); break;
            case "save":
            {
                var slot = Slot(request);
                var isCanonical = string.Equals(slot, "canonical", StringComparison.OrdinalIgnoreCase) ||
                    (request.TryGetProperty("canonical", out var cVal) &&
                     (cVal.ValueKind == JsonValueKind.True ||
                      (cVal.ValueKind == JsonValueKind.String && bool.TryParse(cVal.GetString(), out var cb) && cb)));
                var saveLot = isCanonical ||
                    (request.TryGetProperty("lot", out var lotProp) &&
                     (lotProp.ValueKind == JsonValueKind.True ||
                      (lotProp.ValueKind == JsonValueKind.String && bool.TryParse(lotProp.GetString(), out var lb) && lb)));
                result = SaveLotToSlot(slot, isCanonical, saveLot);
                break;
            }
            case "load":
            {
                var slot = Slot(request);
                var storageSlot = Neighborhoods.StorageSlot(slot, Neighborhoods.Current);
                var envelopePath = SaveEnvelopePath(slot);
                var path = SavePath(slot);
                if (!File.Exists(envelopePath) && !File.Exists(path))
                    throw new InvalidOperationException($"No native save '{slot}' exists.");
                var activeRegistry = EnsureRegistry();
                SaveEnvelope? envelope = null;
                SaveCompatibility.Result? compatibility = null;
                Dictionary<string, PluginHost.PluginSaveRecord>? savedPlugins = null;
                string? migrationBackup = null;
                if (File.Exists(envelopePath))
                {
                    envelope = JsonSerializer.Deserialize<SaveEnvelope>(File.ReadAllBytes(envelopePath), Json)
                        ?? throw new InvalidDataException("Save file is empty.");
                    if (envelope.House > 0)
                        house = envelope.House;
                    var removePacks = request.TryGetProperty("removePacks", out var removeValue) && removeValue.ValueKind == JsonValueKind.True;
                    compatibility = SaveCompatibility.Check(envelope.PackFingerprint, envelope.Packs,
                        packFingerprint, plugins?.MigratedPacks ?? [], removePacks,
                        envelope.CorePackFingerprint, corePackFingerprint);
                    var removedPackIds = compatibility.Removed
                        .Select(item => item.Split('@', 2)[0])
                        .ToHashSet(StringComparer.OrdinalIgnoreCase);
                    savedPlugins = envelope.Plugins is null
                        ? null
                        : envelope.Plugins.Where(entry => !removedPackIds.Contains(entry.Key))
                            .ToDictionary(entry => entry.Key, entry => entry.Value, StringComparer.OrdinalIgnoreCase);
                    plugins?.ValidateSaved(savedPlugins);
                    if (compatibility.Migrated)
                        migrationBackup = SaveCompatibility.Backup(profile, storageSlot, envelopePath);
                }
                var userData = Neighborhoods.UserData(profile);
                var snapshotNghPath = SaveNeighborhoodPath(slot);
                if (!string.IsNullOrEmpty(envelope?.NeighborhoodState))
                {
                    var targetNghPath = neighborhoodPath ?? Path.Combine(userData, "Neighborhood.iff");
                    WriteReplace(targetNghPath, Convert.FromBase64String(envelope.NeighborhoodState));
                }
                else if (File.Exists(snapshotNghPath))
                {
                    var targetNghPath = neighborhoodPath ?? Path.Combine(userData, "Neighborhood.iff");
                    WriteReplace(targetNghPath, File.ReadAllBytes(snapshotNghPath));
                }
                var lotBytes = !string.IsNullOrEmpty(envelope?.State)
                    ? Convert.FromBase64String(envelope.State)
                    : File.ReadAllBytes(path);
                var runtime = envelope?.Runtime ?? ReadSavedRuntimeMetadata(SaveRuntimePath(slot), lotBytes);
                var lotSourcePath = File.Exists(path) ? path : Path.Combine(userData, "Houses", $"House{house:D2}.iff");
                registry = activeRegistry.WithRefreshedPeople(Path.Combine(userData, "Characters"));
                var setup = WorldBootstrap.Load(game, lotSourcePath, language, () => speed == 0, house,
                    userDataPath: userData,
                    activeFamilyChunkId: envelope?.SuspendedHome?.HomeFamilyChunkId ?? runtime.SuspendedHome?.HomeFamilyChunkId,
                    preloadedLot: new IffFile(lotBytes, lotSourcePath),
                    scoreAutonomy: ScoreAutonomyChoice,
                    objectMigrations: compatibility?.Objects,
                    stripMissingObjects: compatibility?.Migrated == true,
                    existingRegistry: registry,
                    directsAutonomy: DirectsAutonomyForPerson,
                    selectAutonomy: SelectAutonomyChoice);
                refreshedPersonFiles.Clear();
                setup.World.AutonomyForced = world?.AutonomyForced;
                ResetAppearanceTransitions();
                lot = setup.Lot;
                ClearBuildHistory();
                world = setup.World;
                if (envelope is not null)
                {
                    updates = envelope.Updates;
                    plugins?.Restore(savedPlugins);
                    plugins?.CommitNeighborhood();
                }
                ResetLotValuationBaseline();
                var migrationRefund = setup.LotMigration?.Refund ?? 0;
                if (runtime.Budget is { } savedBudget &&
                    world.FamilyBudget is FamilyBudget restoredBudget &&
                    restoredBudget.ActiveFamily is { } restoredFamily)
                {
                    var effectiveBudget = checked(savedBudget + migrationRefund);
                    restoredBudget.ActiveFamily = restoredFamily.WithBudget(effectiveBudget);
                    world[SimulationGlobal.BudgetMod10000] = unchecked((short)(effectiveBudget % 10000));
                    world[SimulationGlobal.BudgetDiv10000] = unchecked((short)(effectiveBudget / 10000));
                }
                var animationsToRestore = setup.LotMigration is { ResetEntityIds.Count: > 0 } mig
                    ? runtime.PersonAnimations?.Where(a => !mig.ResetEntityIds.Contains(a.PersonId)).ToArray()
                    : runtime.PersonAnimations;
                RestorePersonAnimationRuntime(world, animationsToRestore);
                RestoreDialogRecords(world, runtime.Dialogs);
                if (runtime.ClockTicks is { } loadedClockTicks)
                    world.Clock.RestoreProgress(loadedClockTicks, runtime.ClockDay ?? 0);
                if (viewerScale != 0) world[SimulationGlobal.ZoomLevelSML] = viewerScale;
                viewerMode = 0;
                tileCursor = null;
                world[SimulationGlobal.Mode] = viewerMode;
                InitializeFameCallbackTarget(world);
                neighborhoodPath = setup.NeighborhoodPath;
                neighborhood = setup.Neighborhood;
                activeFamilyChunkId = setup.ActiveFamilyChunkId;
                if (activeFamilyChunkId is null && !WorldBootstrap.HasResidentHouseholdSim(world))
                    world[SimulationGlobal.SimlessBuildMode] = 1;
                else if (activeFamilyChunkId is not null)
                    world[SimulationGlobal.SimlessBuildMode] = 0;
                RestoreTravelRuntimeState(world, userData, house, activeFamilyChunkId, setup.ActiveFamily, runtime, envelope);
                HydrateTypeAttributesFromNeighborhood(world, lot, neighborhood);
                world.UiTextFile ??= registry?.UiText;
                AttachTutorialFlash(world);
                ClampAwayLotEditingState();
                if (!IsValidSelectedSim(world, selectedSim))
                {
                    selectedSim = DefaultSelectedSimId();
                }
                SyncSelectedSimFlags(world, selectedSim);
                simulationError = null;
                saveDirty = false;
                viewLevel = 1;
                autoSpeedSaved = -1;
                SetSimulationSpeed(0);
                lastRunningSpeed = runtime.Speed;
                dialogResumeSpeed = HasBlockingDialog(world) && runtime.Speed > 0 ? runtime.Speed : 0;
                AttachNoticeListener(setup.World);
                audio?.Reset();
                if (audio?.Enabled == true)
                    audio.PlayLotAmbience(house);
                Export();
                if (compatibility is { Migrated: true } && setup.LotMigration is { } lotMigration)
                {
                    static uint ParseHexGuid(string value) =>
                        value.StartsWith("0x", StringComparison.OrdinalIgnoreCase) && uint.TryParse(value.AsSpan(2), System.Globalization.NumberStyles.HexNumber, null, out var parsed)
                            ? parsed
                            : uint.TryParse(value, out var dec) ? dec : 0;
                    Write(new
                    {
                        type = "saveMigrated",
                        slot,
                        upgraded = compatibility.Upgraded,
                        added = compatibility.Added,
                        removed = compatibility.Removed,
                        removedObjects = lotMigration.RemovedObjects.Select(item => new { guid = ParseHexGuid(item.Guid), objectId = (int)item.ObjectId, name = item.Name, refund = item.Refund }).ToArray(),
                        migratedObjects = lotMigration.MigratedObjects.Select(item => new { from = ParseHexGuid(item.From), to = ParseHexGuid(item.To), objectId = (int)item.ObjectId }).ToArray(),
                        refund = lotMigration.Refund,
                        resetObjects = lotMigration.ResetEntityIds.Count,
                        backup = migrationBackup,
                    });
                }
                result = State();
                break;
            }
            case "travelFilter":
            {
                var filterMode = request.TryGetProperty("mode", out var modeValue) && modeValue.ValueKind == JsonValueKind.Number
                    ? modeValue.GetInt32()
                    : (lastTravelNeighborhoodMode ?? 4);
                var slot = TravelFilterSlotForMode(filterMode);
                TravelFilter.Save(Neighborhoods.UserData(profile), slot,
                    request.GetProperty("filter").GetInt32(), language);
                result = new { saved = true, mode = filterMode, slot };
                break;
            }
            case "plugins": result = new { plugins = plugins?.Statuses ?? [], panels = plugins?.Panels ?? [] }; break;
            case "pluginPanels": result = new { panels = plugins?.PanelState() ?? [] }; break;
            case "pluginClientStates": result = plugins?.ClientStateSnapshot() ?? new { states = Array.Empty<object>(), blackboard = new Dictionary<string, float>() }; break;
            case "pluginAction":
                result = (plugins ?? throw new InvalidOperationException("No pack plugins are loaded.")).PanelAction(
                    request.GetProperty("packId").GetString() ?? "", request.GetProperty("panelId").GetString() ?? "", request.GetProperty("action").GetString() ?? "");
                plugins.FlushClientStates();
                break;
            case "pluginClientCommand":
            {
                var payload = request.TryGetProperty("payload", out var payloadEl) && payloadEl.ValueKind == JsonValueKind.String
                    ? payloadEl.GetString()
                    : null;
                result = (plugins ?? throw new InvalidOperationException("No pack plugins are loaded.")).ClientCommand(
                    request.GetProperty("packId").GetString() ?? "",
                    request.GetProperty("command").GetString() ?? "",
                    payload);
                plugins.FlushClientStates();
                break;
            }
            case "quit":
                ReconcileCommittedVacationFieldOnDisk();
                running = false;
                result = new { quit = true };
                break;
            default:
                error = $"native engine does not implement '{op}'";
                break;
        }
        if (error is not null) Write(new { type = "response", id, operation = op, ok = false, error });
        else Write(new { type = "response", id, operation = op, ok = true, result });
        return running;
    }
}
