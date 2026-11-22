using System.Collections.Concurrent;
using System.Diagnostics;

namespace SimsSDL;

internal sealed partial class LiveController
{
    // Must serialize: the simulation host writes every appearancePreview to the shared cas-preview/preview.json file.
    private void SyncFamilyPortraits()
    {
        if (Ui.HouseholdCreation is not { ShowsFamilyPage: true } creation || Bridge is not { } bridge)
        {
            return;
        }

        var wanted = creation.MemberPreviewSelections();
        foreach (int key in _familyPortraits.Keys.Where(k => !wanted.ContainsKey(k)).ToList())
        {
            _familyPortraits.Remove(key);
            Renderer.ClearAppearancePreview(key);
        }

        if (_pendingHouseholdPreviewRequest is not null || _pendingHouseholdAppearanceRequest is not null)
        {
            return;
        }

        foreach (var (key, selection) in wanted.OrderBy(static kv => kv.Key))
        {
            string sig = Signature(selection);
            if (_familyPortraits.TryGetValue(key, out string? existing)
                && string.Equals(existing, sig, StringComparison.Ordinal))
            {
                continue;
            }

            try
            {
                _pendingHouseholdPreviewRequest = bridge.Send(
                    "appearancePreview",
                    new Dictionary<string, object?>(StringComparer.Ordinal)
                    {
                        ["gender"] = selection.Gender,
                        ["age"] = selection.Age,
                        ["skin"] = selection.Skin,
                        ["headChoice"] = selection.HeadChoice,
                        ["bodyChoice"] = selection.BodyChoice,
                        ["portrait"] = true,
                    });
                _pendingHouseholdPreviewKey = key;
                _pendingHouseholdPreviewSignature = sig;
            }
            catch (Exception error)
            {
                _familyPortraits[key] = sig;
                Log($"Family member preview: {error}");
            }

            break;
        }
    }

    private static string Signature(
        (string Gender, string Age, string Skin, string HeadChoice, string BodyChoice) selection) =>
        $"{selection.Gender}|{selection.Age}|{selection.Skin}|{selection.HeadChoice}|{selection.BodyChoice}";

    private void ChooseGenericSimsCallPerson(int personRecordIndex)
    {
        if (_pendingGenericSimsCallChoice is not null
            || _activeGenericSimsCallRequest is not long requestID)
        {
            return;
        }

        if (Send(
                "genericSimsCallPersonPicker",
                new Dictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["requestID"] = requestID,
                    ["personRecordIndex"] = personRecordIndex,
                }) is { } id)
        {
            _pendingGenericSimsCallChoice = id;
        }
    }

    private void SimulationEvent(IReadOnlyDictionary<string, JsonElement> evt)
    {
        try
        {
            string? type = evt.JsonString("type");
            string? id = evt.JsonString("id");
            bool ok = evt.JsonBool("ok") == true;

            if (type == "response" && id is not null && HandleCheatResponse(id, ok, evt))
            {
                return;
            }

            if (type == "neighborhoodCheat")
            {
                HandleNeighborhoodCheatEvent(evt);
                return;
            }

            if (type == "response" && id is not null && id == _pendingGenericSimsCallPoll)
            {
                _pendingGenericSimsCallPoll = null;
                if (ok
                    && evt.JsonDict("result") is { } result
                    && result.JsonInt64("requestID") is long requestID
                    && result.TryGetValue("candidates", out JsonElement candidatesElement)
                    && candidatesElement.ValueKind == JsonValueKind.Array)
                {
                    List<GenericSimsCallChooserOverlay.Candidate>? candidates = null;
                    try
                    {
                        candidates = JsonSerializer.Deserialize<List<GenericSimsCallChooserOverlay.Candidate>>(
                            candidatesElement.GetRawText(),
                            PackContentPaths.JsonReadOptions);
                    }
                    catch
                    {
                        candidates = null;
                    }

                    if (candidates is { Count: > 0 })
                    {
                        _activeGenericSimsCallRequest = requestID;
                        string? sceneDirectory = Renderer.SceneRoot
                            ?? (Bridge is { } b ? Path.Combine(b.Session, "scene") : null);
                        Ui.GenericSimsCallPicker = new GenericSimsCallChooserOverlay(
                            candidates,
                            Ui.Font,
                            Ui.Device,
                            Ui.Content,
                            Ui.Strings,
                            Ui.Gameplay.State?.Sims ?? [],
                            sceneDirectory);
                    }
                }
            }

            if (type == "response" && id is not null && id == _pendingGenericSimsCallChoice)
            {
                _pendingGenericSimsCallChoice = null;
                bool accepted = ok && evt.JsonDict("result")?.JsonBool("accepted") == true;
                if (accepted)
                {
                    Ui.GenericSimsCallPicker = null;
                    _activeGenericSimsCallRequest = null;
                }
                else if (evt.JsonString("error") is { } reason)
                {
                    Log($"GenericSimsCall chooser: {reason}");
                }
            }

            if (type == "response" && id is not null && _pendingScriptTileTraversals.Remove(id))
            {
                if (ok
                    && evt.JsonDict("result") is { } result
                    && result.JsonIntArray("objectIDs") is { } objectIDs)
                {
                    _scriptTileTraversalResults[id] = (objectIDs, null);
                    string tileX = result.JsonInt("tileX")?.ToString(CultureInfo.InvariantCulture) ?? "?";
                    string tileY = result.JsonInt("tileY")?.ToString(CultureInfo.InvariantCulture) ?? "?";
                    string level = result.JsonInt("level")?.ToString(CultureInfo.InvariantCulture) ?? "?";
                    Log($"tile traversal {tileX} {tileY} level {level}: [{string.Join(", ", objectIDs)}]");
                }
                else
                {
                    string error = evt.JsonString("error") ?? "tile traversal returned no object IDs";
                    _scriptTileTraversalResults[id] = (null, error);
                    Log($"tile traversal failed: {error}");
                }
            }

            if (type == "response"
                && id is not null
                && _pendingDaemonNeighborhoodRequests.Remove(id, out var daemonNeighborhoodEntry))
            {
                if (ok)
                {
                    string manifest = Path.Combine(daemonNeighborhoodEntry.Session, "neighborhood.json");
                    daemonNeighborhoodEntry.Continuation.TrySetResult((daemonNeighborhoodEntry.Session, manifest));
                }
                else
                {
                    daemonNeighborhoodEntry.Continuation.TrySetException(
                        new ContentError(evt.JsonString("error") ?? "The neighborhood could not be loaded."));
                }

                return;
            }

            if (type == "response"
                && id is not null
                && _pendingDaemonOpenLotRequests.Remove(id, out var openLotContinuation))
            {
                if (ok)
                {
                    var result = evt.JsonDict("result");
                    bool simless = result?.JsonBool("simless") ?? false;
                    bool away = result?.JsonBool("away") ?? false;
                    int? homeHouse = result?.JsonInt("homeHouse") is int hh && hh > 0 ? hh : null;
                    openLotContinuation.TrySetResult(new DaemonOpenLotResult(simless, away, homeHouse));
                }
                else
                {
                    openLotContinuation.TrySetException(
                        new ContentError(evt.JsonString("error") ?? "The lot could not be opened."));
                }

                return;
            }

            if (type == "response" && id is not null && _pendingSaveRequests.Remove(id))
            {
                _pendingSaveCompletions.Remove(id, out Action<bool>? completion);
                if (!ok)
                {
                    if (evt.JsonString("error") is { } reason)
                    {
                        Log($"Save: {reason}");
                    }

                    PresentLocalFeedback(Strings.SaveHouseTitle(), Strings.SaveFailedMessage());
                }
                else if (Ui.OptionsPanel.PlayOptions.ExportHTML
                    && !_simlessBuildMode
                    && !AwayBuyBuildLocked
                    && _currentHouse is int house
                    && ((house >= 1 && house <= 19) || (house >= 90 && house <= 92)))
                {
                    ExportNeighborhoodWebPages(open: false, fallbackMode: NeighborhoodModeForCurrentLot());
                }

                completion?.Invoke(ok);
            }

            if (type == "response" && id is not null && id == _pendingResetTutorialState)
            {
                _pendingResetTutorialState = null;
                if (!ok)
                {
                    Log("Reset Tutorial: could not read save state");
                    return;
                }

                bool requiresSave = evt.JsonDict("result")?.JsonBool("requiresSave") == true;
                if (requiresSave)
                {
                    OfferResetTutorialSave();
                }
                else
                {
                    FinishResetTutorial();
                }
            }

            if (type == "response" && id is not null && _pendingLoadRequests.Remove(id) && !ok)
            {
                if (evt.JsonString("error") is { } reason)
                {
                    Log($"Load: {reason}");
                }

                if (evt.JsonStringArray("missingPacks") is { Count: > 0 } missing)
                {
                    ConfirmPackRemoval(missing);
                }
                else
                {
                    PresentLocalFeedback(Strings.LoadHouseTitle(), Strings.LoadFailedMessage());
                }
            }

            if (type == "response" && id is not null)
            {
                NeighborhoodResponse(id, ok, evt);
            }

            if (type == "pluginPanels" && evt.JsonArray("panels") is { } directPanels)
            {
                ApplyPluginPanelValues(directPanels);
            }

            if (type == "response"
                && evt.JsonDict("result")?.JsonArray("panels") is { } resultPanels
                && resultPanels.All(static p => p.TryGetValue("values", out JsonElement v) && v.ValueKind != JsonValueKind.Null))
            {
                ApplyPluginPanelValues(resultPanels);
            }

            if (type == "pluginPanelShow"
                && evt.JsonString("packId") is { } packID
                && evt.JsonString("panelId") is { } panelID
                && Ui.ShowsLot
                && !HasBlockingDialog
                && Ui.OutfitPicker is null)
            {
                PanelDescription? description = null;
                foreach (var (candidatePackID, candidateDescription) in PluginPanels)
                {
                    if (string.Equals(candidatePackID, packID, StringComparison.Ordinal)
                        && string.Equals(candidateDescription.Id, panelID, StringComparison.Ordinal))
                    {
                        description = candidateDescription;
                        break;
                    }
                }

                if (description is not null)
                {
                    DismissMenu();
                    Ui.SoundOptions.Dismiss();
                    OpenPluginPanel(packID, description, evt.JsonInt("anchorId"));
                }
            }

            if (type == "plugin"
                && evt.JsonString("packId") is { } pluginPackID
                && evt.JsonString("state") is { } pluginState)
            {
                string reasonSuffix = string.Empty;
                if (evt.TryGetValue("reason", out JsonElement reasonElement) && reasonElement.ValueKind != JsonValueKind.Null)
                {
                    reasonSuffix = $" — {(reasonElement.ValueKind == JsonValueKind.String ? reasonElement.GetString() : reasonElement.GetRawText())}";
                }

                Log($"Plugin {pluginPackID}: {pluginState}{reasonSuffix}");
                if (string.Equals(pluginState, "failed", StringComparison.Ordinal)
                    && string.Equals(Ui.PluginPanel?.PackId, pluginPackID, StringComparison.Ordinal))
                {
                    Ui.PluginPanel = null;
                }
            }

            if (type == "saveMigrated")
            {
                var removedObjects = evt.JsonArray("removedObjects") ?? [];
                var upgraded = evt.JsonStringArray("upgraded") ?? [];
                var removed = evt.JsonStringArray("removed") ?? [];
                string backup = evt.JsonString("backup") ?? "none";
                Log($"Save migrated: {string.Join(", ", upgraded)}; removed {string.Join(", ", removed)}; {removedObjects.Count} objects; backup {backup}");
                if (removed.Count > 0)
                {
                    int refund = evt.JsonInt("refund") ?? 0;
                    string plural = removedObjects.Count == 1 ? string.Empty : "s";
                    string refundText = refund > 0 ? $" and refunded {refund} Simoleons" : string.Empty;
                    PresentLocalFeedback(
                        Strings.LoadHouseTitle(),
                        $"Removed {removedObjects.Count} object{plural} from content that is no longer installed{refundText}. A backup of the save was kept.");
                }
            }

            if (type == "tutorialFlash"
                && evt.JsonString("target") is { } flashTarget
                && evt.JsonInt("value") is int flashValue
                && evt.JsonBool("on") is bool flashOn)
            {
                Ui.TutorialFlash(flashTarget, flashValue, flashOn);
                string highlightText = Ui.TutorialHighlight is { } highlight ? $"{highlight.Button}" : "hidden";
                Log($"tutorial flash {flashTarget} {flashValue} {flashOn}: {highlightText}");
            }

            if (type == "lotSwitching")
            {
                int? fromHouse = evt.JsonInt("fromHouse") ?? _currentHouse;
                int? destination = evt.JsonInt("house");
                bool isReturnHome = evt.JsonBool("returnHome") ?? (evt.JsonBool("away") == false);
                int? sourceStateClass = evt.JsonInt("sourceStateClass") ?? _lastHouseStateClass;
                int? destinationStateClass = evt.JsonInt("destinationStateClass");
                int transitInfo = evt.JsonInt("lotTransitInfo") ?? _lastLotTransitInfo;
                _lotSims.TryGetValue(_selectedSim, out LotSimInfo? selectedLotSim);
                int fameScore = evt.JsonInt("fameScore") ?? (selectedLotSim?.FameScore ?? 0);
                int jobType = evt.JsonInt("jobType") ?? (selectedLotSim?.JobType ?? 0);
                _awaitingLotSwitchChange = true;
                _switchingLot = true;
                if (destination is int dest
                    && OriginalTravelLoadScreenExtensions.Select(
                        fromHouse,
                        dest,
                        sourceStateClass,
                        destinationStateClass,
                        fameScore,
                        jobType,
                        transitInfo,
                        isReturnHome) is { } screen)
                {
                    Ui.TravelLoadScreen = screen;
                    Ui.Loading = true;
                }
                else
                {
                    Ui.TravelLoadScreen = null;
                    Ui.Loading = false;
                }
            }

            if (type == "lotChanged")
            {
                int? previousHouse = _currentHouse;
                if (evt.JsonInt("house") is int destination)
                {
                    bool? awayFlag = evt.JsonBool("away");
                    bool isReturnHome = awayFlag == false;
                    if (evt.JsonBool("simless") is bool simlessChanged)
                    {
                        SimlessBuildMode = simlessChanged;
                    }
                    else if (awayFlag == true)
                    {
                        SimlessBuildMode = false;
                    }

                    _lotSims.TryGetValue(_selectedSim, out LotSimInfo? selectedLotSim);
                    if (!_awaitingLotSwitchChange
                        && !_switchingLot
                        && OriginalTravelLoadScreenExtensions.Select(
                            previousHouse,
                            destination,
                            _lastHouseStateClass,
                            destinationStateClass: null,
                            travellerFameScore: selectedLotSim?.FameScore ?? 0,
                            travellerJobType: selectedLotSim?.JobType ?? 0,
                            lotTransitInfo: _lastLotTransitInfo,
                            isReturnHome: isReturnHome) is { } fallbackScreen)
                    {
                        Ui.TravelLoadScreen = fallbackScreen;
                        Ui.Loading = true;
                    }

                    _switchingLot = true;
                    _currentHouse = destination;
                    EmergencyBuyBuildLocked = false;
                    if (SimlessBuildMode)
                    {
                        AwayBuyBuildLocked = false;
                    }
                    else
                    {
                        UpdateAwayLotLocks(destination, awayFlag);
                    }
                }

                _awaitingLotSwitchChange = false;
                _minimumSceneRevisionToFinishLoading = _highestReceivedSceneRevision + 1;
                _lastHouseStateClass = null;
                _lastLotTransitInfo = 0;
                DismissMenu();
                Ui.PluginPanel = null;
                Ui.SoundOptions.Dismiss();
                Ui.CheatConsole.Close();
                Ui.GameDialog = null;
                _answeredDialogs.Clear();
                Ui.BuyMode = false;
                Ui.BuildMode = false;
                Ui.PanelMinimized = false;
                _tutorialLiveModeClicked = false;
                Renderer.Pan = Vector2.Zero;
                _centresOnSelectedSim = Ui.OptionsPanel.PlayOptions.AutoCenter;
                _pendingCatalog = null;
                _pendingBuildCatalog = null;
                ClearPendingViewState();
                _latestQueuedSceneRevision = 0;
                _pendingPlacement = null;
                _pendingBuildCursor = null;
                _lastWallpaperCursorDirection = null;
                _editableObjects = [];
                _placedObjectMeta.Clear();
                _pendingSaleRequests.Clear();
                _pendingDisposePreviewRequest = null;
                Ui.DisposePanel = null;
                _pendingPipCenterObjectID = null;
                ClosePictureInPicture();
                EnsureSimlessEditingMode();
            }

            if (type == "response" && _pendingBuildCursor is { } pendingCursor && id == pendingCursor.Id)
            {
                _pendingBuildCursor = null;
                _checkedBuildCursor = pendingCursor.Key;
                if (_desiredBuildCursor is { } desired
                    && Ui.BuildMode
                    && pendingCursor.Key.Guid == desired.Guid
                    && pendingCursor.Key.Revision == desired.Revision)
                {
                    Dictionary<string, JsonElement>? result = ok ? evt.JsonDict("result") : null;
                    PlacementPreview.GhostData? decodedGhost = null;
                    if (result is not null
                        && result.TryGetValue("ghost", out JsonElement ghostEl)
                        && ghostEl.ValueKind == JsonValueKind.Object)
                    {
                        decodedGhost = JsonSerializer.Deserialize<PlacementPreview.GhostData>(
                            ghostEl.GetRawText(),
                            PackContentPaths.JsonReadOptions);
                    }

                    PlacementPreview.GhostData? decodedWallPreview = null;
                    if (result is not null
                        && result.TryGetValue("wallPreview", out JsonElement wallPreviewEl)
                        && wallPreviewEl.ValueKind == JsonValueKind.Object)
                    {
                        decodedWallPreview = JsonSerializer.Deserialize<PlacementPreview.GhostData>(
                            wallPreviewEl.GetRawText(),
                            PackContentPaths.JsonReadOptions);
                    }

                    Renderer.UpdateBuildCursor(decodedGhost);
                    Renderer.UpdateWallPaintPreview(decodedWallPreview);
                }

                RequestBuildCursor();
            }

            if (type == "response" && _pendingPlacement is { } pendingPlacement && id == pendingPlacement.Id)
            {
                _pendingPlacement = null;
                _checkedPlacement = pendingPlacement.Key;
                if (_desiredPlacement == pendingPlacement.Key
                    && Ui.ObjectEditing
                    && ok
                    && evt.TryGetValue("result", out JsonElement placeResultEl)
                    && placeResultEl.ValueKind == JsonValueKind.Object)
                {
                    var preview = JsonSerializer.Deserialize<PlacementPreview>(
                        placeResultEl.GetRawText(),
                        PackContentPaths.JsonReadOptions);
                    if (preview is not null)
                    {
                        if (pendingPlacement.Key.WallDirection is not null
                            && preview.Direction is int snappedDir and (1 or 4 or 16 or 64))
                        {
                            _snappedPlacementDirection = (pendingPlacement.Key, snappedDir);
                        }
                        else
                        {
                            _snappedPlacementDirection = null;
                        }

                        Renderer.UpdatePlacement(preview);
                    }
                }

                RequestPlacement();
            }

            if (type == "response" && id is not null && id == _pendingBuildCatalog)
            {
                _pendingBuildCatalog = null;
                if (ok
                    && Ui.BuildMode
                    && evt.TryGetValue("result", out JsonElement buildCatEl)
                    && buildCatEl.ValueKind == JsonValueKind.Object
                    && Renderer.SceneRoot is { } buildRoot)
                {
                    string rawJson = buildCatEl.GetRawText();
                    if (Ui.Build.ObjectTool is { } tool && tool.Category() is int category)
                    {
                        var page = JsonSerializer.Deserialize<BuyCatalogPage>(rawJson, PackContentPaths.JsonReadOptions)
                            ?? throw new ContentError("Buy catalog page decoded to null");
                        if (page.Category == category)
                        {
                            Ui.Build.UpdateObjects(page, buildRoot);
                            Ui.Buy.Update(page, buildRoot, buildObjects: true);
                        }
                    }
                    else
                    {
                        var page = JsonSerializer.Deserialize<BuildCatalogPage>(rawJson, PackContentPaths.JsonReadOptions)
                            ?? throw new ContentError("Build catalog page decoded to null");
                        Ui.Build.Update(page, buildRoot);
                        if (page.Kind == BuildCatalogPage.CatalogKind.Roof)
                        {
                            Ui.Build.Choose(Ui.RoofStyle);
                        }

                        if (page.Kind == BuildCatalogPage.CatalogKind.Water && Ui.Build.SelectedObjectGUID is null)
                        {
                            Ui.Buy.CancelSelection();
                        }
                    }

                    if (Pointer is { } pointer)
                    {
                        Hover(pointer, _canvas);
                    }
                }
            }

            if (type == "response" && id is not null && id == _pendingBuyCatalogViews)
            {
                _pendingBuyCatalogViews = null;
                if (ok
                    && evt.TryGetValue("result", out JsonElement viewsEl)
                    && viewsEl.ValueKind == JsonValueKind.Object)
                {
                    var resp = JsonSerializer.Deserialize<BuyCatalogPluginViewsResponse>(
                        viewsEl.GetRawText(),
                        PackContentPaths.JsonReadOptions);
                    int prevCapacity = OriginalBuyLayout.Capacity(LogicalCanvas, Ui.Buy.PluginViews.Count);
                    Ui.Buy.SetPluginViews(resp?.Views ?? []);
                    int newCapacity = OriginalBuyLayout.Capacity(LogicalCanvas, Ui.Buy.PluginViews.Count);
                    if (Ui.BuyMode && newCapacity != prevCapacity && _pendingCatalog is null)
                    {
                        if (Ui.Buy.ActivePluginView is { } activePv && Ui.Buy.ActivePluginCollectionId is { } activeColId)
                        {
                            RequestPluginCatalog(activePv.PackId, activePv.TabId, activeColId, Ui.Buy.Page?.Offset ?? 0);
                        }
                        else
                        {
                            RequestCatalog(
                                category: Ui.Buy.Category,
                                room: Ui.Buy.RoomMode ? Ui.Buy.Room : (int?)null,
                                subsort: Ui.Buy.FunctionSubSorting ? Ui.Buy.FunctionSubsort : (int?)null,
                                offset: Ui.Buy.Page?.Offset ?? 0);
                        }
                    }
                }
            }

            if (type == "response" && id is not null && id == _pendingCatalog)
            {
                _pendingCatalog = null;
                if (ok
                    && Ui.BuyMode
                    && evt.TryGetValue("result", out JsonElement buyCatEl)
                    && buyCatEl.ValueKind == JsonValueKind.Object
                    && (Renderer.SceneRoot ?? Bridge?.Session) is { } buyRoot)
                {
                    var page = JsonSerializer.Deserialize<BuyCatalogPage>(
                        buyCatEl.GetRawText(),
                        PackContentPaths.JsonReadOptions)
                        ?? throw new ContentError("Buy catalog page decoded to null");
                    Ui.Buy.Update(page, buyRoot, pluginCollection: Ui.Buy.PluginViewMode);
                    if (Pointer is { } pointer)
                    {
                        Hover(pointer, _canvas);
                    }
                }
            }

            if (type == "response" && _pendingMenu is { } pendingMenu && id == pendingMenu.Id)
            {
                _pendingMenu = null;
                if (ok
                    && _selectedSim == pendingMenu.Caller
                    && (pendingMenu.Ground is not null || Renderer.ContainsObject(pendingMenu.Object))
                    && evt.TryGetValue("result", out JsonElement menuResultEl)
                    && menuResultEl.ValueKind == JsonValueKind.Array)
                {
                    var entries = JsonSerializer.Deserialize<List<SimInteraction>>(
                        menuResultEl.GetRawText(),
                        PackContentPaths.JsonReadOptions) ?? [];
                    if (entries.Count > 0)
                    {
                        _pieGround = pendingMenu.Ground;
                        PlayUISound("ui_piemenu_appear");
                        var pieMenu = new OriginalPieOverlay(
                            entries,
                            pendingMenu.Object,
                            pendingMenu.Caller,
                            pendingMenu.Anchor,
                            Ui.Font,
                            Ui.Device);
                        Ui.PieMenu = pieMenu;
                        pieMenu.Prepare(_canvas, Scale);
                        if (pieMenu.Layout?.Center is { } center)
                        {
                            var target = new CGPoint(center.X * Scale, center.Y * Scale);
                            double dx = center.X - pendingMenu.Anchor.X;
                            double dy = center.Y - pendingMenu.Anchor.Y;
                            if (Math.Sqrt((dx * dx) + (dy * dy)) > 0.5)
                            {
                                _pendingPieMenuWarp = target;
                                WarpPointer?.Invoke(target);
                                Hover(target, _canvas);
                            }
                            else
                            {
                                pieMenu.Hover(target, Scale);
                            }
                        }

                        RequestPieHeadPreview();
                    }
                    else
                    {
                        PlayUISound("ui_error");
                    }
                }
                else if (_selectedSim == pendingMenu.Caller)
                {
                    PlayUISound("ui_error");
                }
            }

            if (type == "response" && _pendingPieHead is { } pendingPieHead && id == pendingPieHead.Id)
            {
                _pendingPieHead = null;
                _checkedPieHead = pendingPieHead.Key;
                if (Ui.PieMenu is { } menu
                    && ReferenceEquals(menu, pendingPieHead.Key.Menu)
                    && menu.SelectedSim == _selectedSim
                    && ok
                    && evt.JsonDict("result") is { } pieResult)
                {
                    Ui.UpdatePieHeadPreview(pieResult);
                }

                RequestPieHeadPreview();
            }

            if (type == "response" && id is not null && id == _pendingAudioState)
            {
                _pendingAudioState = null;
                if (ok && evt.JsonDict("result")?.JsonDict("volumes") is { } volumes)
                {
                    var converted = new Dictionary<string, object?>(volumes.Count, StringComparer.Ordinal);
                    foreach (var (key, value) in volumes)
                    {
                        converted[key] = value;
                    }

                    Ui.SoundOptions.UpdateVolumes(converted);
                    if (Ui.SoundOptions.Volumes.TryGetValue("AMBIENCE", out float ambienceVolume))
                    {
                        _audio?.SetAmbientMasterVolume(ambienceVolume);
                    }
                }
            }

            if (type == "response" && id is not null && _pendingAudioVolumes.Remove(id, out var change))
            {
                if (_latestAudioVolumeRequest.TryGetValue(change.Group, out string? latestRequestId)
                    && latestRequestId == id)
                {
                    _latestAudioVolumeRequest.Remove(change.Group);
                    if (!ok)
                    {
                        Ui.SoundOptions.Restore(change);
                        if (string.Equals(change.Group, "AMBIENCE", StringComparison.OrdinalIgnoreCase))
                        {
                            _audio?.SetAmbientMasterVolume(change.PreviousVolume);
                        }
                    }
                }
            }

            if (type == "hello")
            {
                _bridgeConnected = true;
                var waitingHello = _pendingHelloContinuations.ToList();
                _pendingHelloContinuations.Clear();
                foreach (var continuation in waitingHello)
                {
                    continuation.TrySetResult();
                }

                SimlessBuildMode = evt.JsonBool("simless") ?? false;
                if (evt.JsonInt("homeHouse") is int hh && hh > 0)
                {
                    HomeLotHouse = hh;
                }

                EmergencyBuyBuildLocked = false;
                if (SimlessBuildMode)
                {
                    AwayBuyBuildLocked = false;
                }
                else if (evt.JsonBool("away") is bool away
                    && (evt.JsonInt("house") ?? _currentHouse) is int activeHouse
                    && activeHouse > 0)
                {
                    UpdateAwayLotLocks(activeHouse, away);
                }

                _ = Send("audio", new Dictionary<string, object?>(StringComparer.Ordinal) { ["enabled"] = _audio is not null });
                _ = Send("stream", new Dictionary<string, object?>(StringComparer.Ordinal) { ["enabled"] = true });
                ApplyPlayOptions();
                EnsureSimlessEditingMode();
                if (_pendingHouseholdCreation is not null)
                {
                    PrewarmHouseholdAppearanceCatalog();
                }

                if ((_currentHouse ?? 0) > 0
                    && Options.Speed is int speed
                    && _pendingHouseholdCreation is null
                    && evt.JsonBool("simless") != true)
                {
                    _liveModePaused = speed == 0;
                    if (speed > 0)
                    {
                        _lastRunningSpeed = speed;
                    }

                    _ = Send("speed", new Dictionary<string, object?>(StringComparer.Ordinal) { ["value"] = speed });
                }
            }

            if (type == "response" && id is not null && _pendingResponseSounds.Remove(id, out var sounds))
            {
                if (ok)
                {
                    PlayUISound(sounds.Success);
                }
                else if (sounds.Failure is { } failure)
                {
                    PlayUISound(failure);
                }
            }

            if (type == "response" && id is not null && _pendingSaleRequests.Remove(id))
            {
                if (ok)
                {
                    int refund = evt.JsonDict("result")?.JsonInt("refund") ?? 0;
                    PlayUISound(refund == 0 ? "ui_archtool_delete" : "ui_object_moneyback");
                }
                else
                {
                    PlayUISound("ui_error");
                }
            }

            if (type == "response" && _pendingDisposePreviewRequest is { } pendingDispose && id == pendingDispose.Id)
            {
                _pendingDisposePreviewRequest = null;
                string? disposeRoot = Renderer.SceneRoot
                    ?? (Bridge is { } b ? Path.Combine(b.Session, "scene") : null);
                if (ok
                    && evt.JsonDict("result")?.JsonDict("preview") is { } previewRef
                    && disposeRoot is not null
                    && Ui.DisposePanel is { } disposePanel
                    && disposePanel.ObjectID == pendingDispose.ObjectID)
                {
                    disposePanel.Preview = Ui.LoadDisposePreview(previewRef, disposeRoot);
                }
            }

            if (type == "response" && evt.JsonString("operation") == "moveObject" && ok)
            {
                Ui.Buy.CancelSelection();
                SyncDisposePanel();
                _desiredPlacement = null;
                _checkedPlacement = null;
                _snappedPlacementDirection = null;
                try
                {
                    Renderer.UpdatePlacement(null);
                }
                catch
                {
                }
            }

            if (type == "response" && evt.JsonString("operation") == "dialogResponse" && ok)
            {
                _checkedPlacement = null;
            }

            if (!UsesNativeEngine
                && type == "response"
                && evt.JsonString("operation") == "dialogResponse"
                && ok
                && Options.Speed is int dialogSpeed
                && !Ui.BuyMode
                && !Ui.BuildMode)
            {
                _ = Send("speed", new Dictionary<string, object?>(StringComparer.Ordinal) { ["value"] = dialogSpeed });
            }

            if (type == "response" && id is not null && id == _pendingViewRequestID)
            {
                _pendingViewRequestID = null;
                if (!ok || Renderer.SceneRevisionNumber >= _latestQueuedSceneRevision)
                {
                    ClearPendingViewState();
                }
                else
                {
                    _pendingViewSceneRevision = _latestQueuedSceneRevision;
                }
            }

            if (evt.JsonString("scene") is { } scene)
            {
                long revision = evt.JsonInt64("revision") ?? 0;
                _latestQueuedSceneRevision = Math.Max(_latestQueuedSceneRevision, revision);
                _highestReceivedSceneRevision = Math.Max(_highestReceivedSceneRevision, revision);
                var weakSelf = new WeakReference<LiveController>(this);
                Renderer.LoadSceneInBackground(scene, revision, error => RunOnMainThread(() =>
                {
                    if (!weakSelf.TryGetTarget(out var self))
                    {
                        return;
                    }

                    if (error is not null)
                    {
                        Log($"scene {revision}: {error}");
                        return;
                    }

                    if (self._pendingViewRequestID is null
                        && self._pendingViewSceneRevision is long targetRevision
                        && revision >= targetRevision)
                    {
                        self.ClearPendingViewState();
                    }

                    if (self._stateAwaitingScene is { } waitingState && self.Renderer.SceneRoot is { } sceneRoot)
                    {
                        self._stateAwaitingScene = null;
                        try
                        {
                            self.Ui.Update(waitingState, sceneRoot);
                        }
                        catch (Exception stateError)
                        {
                            Log($"state: {stateError}");
                        }
                    }

                    if (!self._awaitingLotSwitchChange && revision >= self._minimumSceneRevisionToFinishLoading)
                    {
                        bool wasOpeningOrLoading = self._openingNeighborhoodLot || self._switchingLot || self.Ui.Loading;
                        self._hasCompletedInitialLoad = true;
                        self._switchingLot = false;
                        if (self._openingNeighborhoodLot)
                        {
                            self._openingNeighborhoodLot = false;
                            if (self._pendingHouseholdCreation is null && self.Renderer.Scene is not null)
                                self.Ui.Neighborhood = null;
                        }
                        if (self.Ui.Loading && self.Bridge is not null && self.Renderer.Scene is not null)
                        {
                            self.Ui.Loading = false;
                            self._audio?.StopLoadLoop();
                        }
                        self.EnsureSimlessEditingMode();

                        if (wasOpeningOrLoading)
                        {
                            AppLog.SetStage(
                                FormattableString.Invariant($"Ready: Lot {self._currentHouse ?? 0} (scene revision {revision})"),
                                isSteadyState: true);
                        }
                    }

                    if (self.Pointer is { } pointer)
                    {
                        self.UpdatePlacement(pointer);
                        if (self._lastCutawayTile is null)
                        {
                            self.UpdateCutaway(pointer);
                        }
                    }

                    self.CentreOnSelectedSimIfPending();
                    self.CentreRelationshipIfPending();
                    self.CentrePipObjectIfPending();
                    if (revision > 0)
                    {
                        _ = self.Send("sceneAck", new Dictionary<string, object?>(StringComparer.Ordinal) { ["revision"] = revision });
                    }
                }));
            }

            Dictionary<string, JsonElement>? state = evt.JsonDict("state") ?? evt.JsonDict("result");
            if (state is not null && state.JsonInt("speed") is int stateSpeed)
            {
                ApplyState(state, stateSpeed);
            }

            if (type == "audio" && _audio is { } audio)
            {
                try
                {
                    var audioEvent = JsonSerializer.Deserialize<AudioEvent>(
                        JsonSerializer.SerializeToUtf8Bytes(evt),
                        PackContentPaths.JsonReadOptions);
                    if (audioEvent is not null)
                    {
                        audio.Receive(audioEvent);
                    }
                }
                catch (Exception audioError)
                {
                    Log($"audio: {audioError}");
                }
            }

            if (type == "environment")
            {
                PluginEnvironment? environment = null;
                if (evt.TryGetValue("environment", out JsonElement envEl) && envEl.ValueKind == JsonValueKind.Object)
                {
                    environment = JsonSerializer.Deserialize<PluginEnvironment>(
                        envEl.GetRawText(),
                        PackContentPaths.JsonReadOptions);
                }

                Renderer.ApplyEnvironment(environment);
                Ui.Gameplay.Environment = environment;
            }

            if (type == "audioError")
            {
                string audioErr = evt.JsonString("error")
                    ?? (evt.TryGetValue("error", out JsonElement errEl) && errEl.ValueKind != JsonValueKind.Null
                        ? errEl.GetRawText()
                        : "unknown sound error");
                Log($"audio: {audioErr}");
            }

            if (type == "error")
            {
                Log($"host error {JsonSerializer.Serialize(evt)}");
                Ui.Loading = false;
                _switchingLot = false;
                _openingNeighborhoodLot = false;
                _awaitingLotSwitchChange = false;
                _audio?.StopLoadLoop();
            }

            if (evt.JsonBool("ok") == false && evt.JsonString("operation") != "audioEvent")
            {
                if (Ui.GameDialog is not null)
                {
                    Ui.GameDialog.Submitting = false;
                }

                string opName = evt.JsonString("operation") ?? "request";
                string errText = evt.JsonString("error") ?? string.Empty;
                Log($"{opName} failed: {errText}");
            }
        }
        catch (Exception error)
        {
            Log($"{error}");
        }
    }

    private void UpdateAwayLotLocks(int house, bool? awayFlag = null)
    {
        var locks = AwayLotLocks.Compute(
            house: house,
            homeHouse: HomeLotHouse,
            simlessBuildMode: _simlessBuildMode,
            awayFlag: awayFlag);
        AwayBuyBuildLocked = locks.BuyBuildLocked;
        if (locks.BuyBuildLocked)
        {
            Ui.BuyMode = false;
            Ui.BuildMode = false;
        }

        if (locks.LotSaveDisabled is bool saveDisabled)
        {
            LotSaveDisabled = saveDisabled;
        }
    }

    private void ApplyState(IReadOnlyDictionary<string, JsonElement> state, int speed)
    {
        _lastHouseStateClass = state.JsonInt("houseStateClass");
        _lastLotTransitInfo = state.JsonInt("lotTransitInfo") ?? 0;
        if (state.JsonInt("homeHouse") is int hh && hh > 0)
        {
            HomeLotHouse = hh;
        }

        if (state.JsonBool("simlessBuildMode") is bool simless)
        {
            SimlessBuildMode = simless;
        }

        int stateHouse = state.JsonInt("house") ?? _currentHouse ?? 0;
        if (SimlessBuildMode)
        {
            AwayBuyBuildLocked = false;
            EmergencyBuyBuildLocked = false;
            EnsureSimlessEditingMode();
        }
        else
        {
            if (state.JsonBool("away") is bool away && stateHouse > 0)
            {
                UpdateAwayLotLocks(stateHouse, away);
            }

            if (state.JsonBool("emergencyBuyBuildLocked") is bool emergencyLocked)
            {
                bool wasEditing = Ui.BuyMode || Ui.BuildMode;
                EmergencyBuyBuildLocked = emergencyLocked;
                if (emergencyLocked && wasEditing)
                {
                    DismissMenu();
                    Ui.BuyMode = false;
                    Ui.BuildMode = false;
                    _pendingCatalog = null;
                    _pendingBuyCatalogViews = null;
                    _pendingBuildCatalog = null;
                    EditingViewChanged();
                    ResumeLiveMode();
                }
            }
        }

        if (state.TryGetValue("simulationError", out JsonElement simErrEl) && simErrEl.ValueKind == JsonValueKind.String)
        {
            Ui.Loading = false;
            _switchingLot = false;
            _openingNeighborhoodLot = false;
            _awaitingLotSwitchChange = false;
            _audio?.StopLoadLoop();
        }

        ScriptFreeWill = state.JsonBool("freeWill");
        PluginEnvironment? environment = null;
        if (state.TryGetValue("environment", out JsonElement stateEnvEl) && stateEnvEl.ValueKind == JsonValueKind.Object)
        {
            environment = JsonSerializer.Deserialize<PluginEnvironment>(
                stateEnvEl.GetRawText(),
                PackContentPaths.JsonReadOptions);
        }

        Renderer.ApplyEnvironment(environment);
        Ui.Gameplay.Environment = environment;
        ApplyHouseholdState(state);

        if (state.TryGetValue("dialogs", out JsonElement dialogsEl) && dialogsEl.ValueKind == JsonValueKind.Array)
        {
            var pending = JsonSerializer.Deserialize<List<GameDialog>>(
                dialogsEl.GetRawText(),
                PackContentPaths.JsonReadOptions) ?? [];
            GameDialog? travel = pending.FirstOrDefault(static d => OriginalNeighborhoodOverlay.ModeForDialogKind(d.Kind) is not null);
            if (travel is not null && OriginalNeighborhoodOverlay.ModeForDialogKind(travel.Kind) is int mode)
            {
                if (_localDialogToken is null)
                {
                    Ui.GameDialog = null;
                }

                if (_activeNeighborhoodDialog?.Token != travel.Token
                    && _pendingNeighborhood?.Dialog.Token != travel.Token
                    && !_failedNeighborhoodTokens.Contains(travel.Token))
                {
                    LoadTravelNeighborhood(travel, mode);
                }
            }
            else if (pending.FirstOrDefault() is { } firstOutfit && (firstOutfit.Kind == 6 || firstOutfit.Kind == 9))
            {
                if (_localDialogToken is null)
                {
                    Ui.GameDialog = null;
                }

                if (!_answeredDialogs.Contains(firstOutfit.Token)
                    && Ui.OutfitPicker?.Token != firstOutfit.Token
                    && _pendingOutfitChoices?.Dialog.Token != firstOutfit.Token)
                {
                    OpenOutfitPicker(firstOutfit);
                }
            }
            else if (Ui.HouseholdCreation is not null)
            {
                // Suppress queued host help prompts until household creation completes.
                if (_localDialogToken is null)
                {
                    Ui.GameDialog = null;
                }
            }
            else if ((pending.FirstOrDefault(static d => d.Blocking) ?? pending.FirstOrDefault()) is { } first)
            {
                if (Ui.GameDialog?.Dialog.Token != first.Token && _localDialogToken is null)
                {
                    if (first.Blocking)
                    {
                        if (_awaitingLotSwitchChange)
                        {
                            Ui.Loading = false;
                            _switchingLot = false;
                            _awaitingLotSwitchChange = false;
                        }

                        BuySelection.SelectionTarget? heldTarget = Ui.Buy.Selection.Target;
                        int heldDirection = Ui.Buy.Selection.Direction;
                        DismissMenu();
                        if (heldTarget is { } savedTarget)
                        {
                            if (savedTarget.IsPlaced && savedTarget.PlacedObject is { } savedObject)
                            {
                                Ui.Buy.Selection.ChooseObject(savedObject);
                            }
                            else if (savedTarget.CatalogGuid != 0)
                            {
                                Ui.Buy.Selection.ChooseCatalog(savedTarget.CatalogGuid);
                            }

                            int[] directions = [1, 4, 16, 64];
                            int currentDirectionIndex = Array.IndexOf(directions, Ui.Buy.Selection.Direction);
                            int heldDirectionIndex = Array.IndexOf(directions, heldDirection);
                            if (currentDirectionIndex >= 0
                                && heldDirectionIndex >= 0
                                && currentDirectionIndex != heldDirectionIndex)
                            {
                                Ui.Buy.Selection.Rotate(heldDirectionIndex - currentDirectionIndex);
                            }
                        }
                    }

                    string? sceneDirectory = Renderer.SceneRoot
                        ?? (Bridge is { } b ? Path.Combine(b.Session, "scene") : null);
                    Ui.GameDialog = new OriginalDialogOverlay(first, Ui.Font, Ui.Device, Ui.Content, sceneDirectory);
                    string choices = string.Join(", ", first.Buttons.Select(static button => button.Label));
                    Log($"dialog \"{first.Title}\": {first.Message} [{choices}]");
                }

                if (ScriptDialogStop is { } stop
                    && (first.Message.Contains(stop, StringComparison.CurrentCultureIgnoreCase)
                        || first.Title.Contains(stop, StringComparison.CurrentCultureIgnoreCase)
                        || (first.Kind == 10 && "Phone Book".Contains(stop, StringComparison.CurrentCultureIgnoreCase))
                        || (first.IsBookScreen && first.Kind == 12 && "Spellbook".Contains(stop, StringComparison.CurrentCultureIgnoreCase))
                        || (first.IsBookScreen
                            && first.Kind == 15
                            && ("Cookbook".Contains(stop, StringComparison.CurrentCultureIgnoreCase)
                                || "Recipes".Contains(stop, StringComparison.CurrentCultureIgnoreCase)))))
                {
                    ScriptAnswersDialogs = false;
                    ScriptDialogStop = null;
                }

                if ((Options.AnswerDialogs || ScriptAnswersDialogs)
                    && !_answeredDialogs.Contains(first.Token)
                    && Ui.GameDialog is { } dialog
                    && dialog.Dialog.Token == first.Token)
                {
                    _answeredDialogs.Add(first.Token);
                    byte code = first.Kind == 10
                        ? (byte)0
                        : (first.Buttons.Count > 0 ? first.Buttons[0].Code : (byte)0);
                    RespondDialog(dialog, code, responseText: first.Kind == 10 ? "-1" : null);
                }
            }
            else
            {
                if (_localDialogToken is null)
                {
                    Ui.GameDialog = null;
                }

                if (Ui.OutfitPicker is not null)
                {
                    CloseOutfitPicker();
                }
            }
        }

        bool buildableChanged = false;
        if (BuildableArea.Create(state) is { } area)
        {
            if (!Equals(_buildable, area))
            {
                _buildable = area;
                buildableChanged = true;
            }
        }

        if (BuildableArea.Create(state, "buildableLevel2") is { } area2)
        {
            if (!Equals(_buildableLevel2, area2))
            {
                _buildableLevel2 = area2;
                buildableChanged = true;
            }
        }

        if (buildableChanged)
        {
            Renderer.SetBuildableAreas(_buildable, _buildableLevel2);
        }

        var sims = state.JsonArray("sims") ?? [];
        if (state.JsonArray("objects") is { } objects)
        {
            var simEntries = sims
                .Where(static sim => sim.JsonInt("id").HasValue)
                .Select(static sim => (Id: sim.JsonInt("id")!.Value, Name: sim.JsonString("name") ?? string.Empty));
            var nonAvatars = objects.Where(static obj => obj.JsonBool("avatar") != true).ToList();
            ScriptObjects = nonAvatars
                .Where(static obj => obj.JsonInt("id").HasValue)
                .Select(static obj => (Id: obj.JsonInt("id")!.Value, Name: obj.JsonString("name") ?? string.Empty))
                .Concat(simEntries)
                .OrderBy(static entry => entry.Id)
                .ToList();
            var editableObjects = new List<EditableLotObject>(nonAvatars.Count);
            var nextMeta = new Dictionary<int, PlacedObjectMeta>(nonAvatars.Count);
            foreach (var obj in nonAvatars)
            {
                if (obj.JsonInt("id") is not int objId)
                {
                    continue;
                }

                float x = (float)(obj.JsonDouble("x") ?? 0.0);
                float y = (float)(obj.JsonDouble("y") ?? 0.0);
                int level = obj.JsonInt("level") ?? 1;
                int? catalogCategory = obj.JsonInt("catalogCategory");
                int buildModeType = obj.JsonInt("buildModeType")
                    ?? (catalogCategory is int category ? Math.Max(0, category - 7) : 0);
                int resaleValue = obj.JsonInt("resaleValue") ?? 0;
                string catalogName = obj.JsonString("catalogName") ?? string.Empty;
                nextMeta[objId] = new PlacedObjectMeta(x, y, level, buildModeType, resaleValue, catalogName);

                uint guid = (uint)(obj.JsonInt64("guid") ?? 0);
                int direction = obj.JsonInt("direction") ?? 0;
                bool movable = obj.JsonBool("movable") ?? false;
                bool sellable = obj.JsonBool("sellable") ?? false;
                int? multiTileMasterId = obj.JsonInt("multiTileMasterID");
                editableObjects.Add(new EditableLotObject(
                    objId, guid, level, direction, movable, sellable, catalogCategory, multiTileMasterId));
            }

            _editableObjects = editableObjects;
            _placedObjectMeta = nextMeta;
            Ui.Buy.Selection.Reconcile(_editableObjects);
            SyncDisposePanel();
        }

        Renderer.Speed = speed;
        if (speed > 0)
        {
            _lastRunningSpeed = speed;
            _liveModePaused = false;
        }

        float pitch = (float)(state.JsonDouble("roofPitch") ?? 0.66);
        Ui.RoofPitch = pitch;
        Ui.Build.SelectedRoofPitch = pitch;
        if ((state.JsonInt("roofStyleIndex") ?? state.JsonInt("roofStyle")) is int roofStyle
            && roofStyle is >= 0 and <= ushort.MaxValue)
        {
            ushort style = (ushort)roofStyle;
            Ui.RoofStyle = style;
            if (Ui.Build.Kind == BuildCatalogPage.CatalogKind.Roof)
            {
                Ui.Build.Choose(style);
            }
        }

        // State updates arriving before the target lot's scene has loaded must wait for scene completion,
        // both for paused initial loads and during non-adjacent lot switches while the prior SceneRoot is still mounted.
        int effectiveStateHouse = state.JsonInt("house")
            ?? (state.TryGetValue("connectedNeighborhood", out var cnHouseEl)
                && cnHouseEl.ValueKind == JsonValueKind.Object
                && cnHouseEl.TryGetProperty("focusedHouse", out var fhHouseEl)
                && fhHouseEl.TryGetInt32(out int fhHouse) ? fhHouse : 0);
        bool awaitingTargetScene = _switchingLot
            || _awaitingLotSwitchChange
            || Renderer.IsLoadingScene
            || (effectiveStateHouse > 0 && Renderer.Scene is { House: > 0 } currentScene && currentScene.House != effectiveStateHouse);
        if (!awaitingTargetScene && Renderer.SceneRoot is { } root)
        {
            try
            {
                Ui.Update(state, root);
            }
            catch (Exception stateError)
            {
                Log($"state: {stateError}");
            }
            _stateAwaitingScene = null;
        }
        else
        {
            _stateAwaitingScene = new Dictionary<string, JsonElement>(state, StringComparer.Ordinal);
        }

        if (Pointer is { } pointer)
        {
            UpdatePlacement(pointer);
            if (_lastCutawayTile is null)
            {
                UpdateCutaway(pointer);
            }
        }

        _selectedSim = state.JsonInt("selectedSim") ?? 0;
        if (Ui.PieMenu is { } menu
            && (menu.SelectedSim != _selectedSim || (menu.ObjectID > 0 && !Renderer.ContainsObject(menu.ObjectID))))
        {
            DismissMenu();
        }

        _simIDs = sims
            .Where(static s => s.JsonBool("household") == true && s.JsonInt("id").HasValue)
            .Select(static s => s.JsonInt("id")!.Value)
            .ToList();
        var nextLotSims = new Dictionary<int, LotSimInfo>();
        foreach (var entry in sims)
        {
            if (entry.JsonInt("id") is not int simId)
            {
                continue;
            }

            string? rawTooltipName = entry.JsonString("tooltipName");
            string tooltipName = !string.IsNullOrEmpty(rawTooltipName)
                ? rawTooltipName
                : (entry.JsonString("name") ?? string.Empty);
            int gender = entry.JsonInt("gender") ?? 0;
            uint guid = (uint)(entry.JsonInt64("guid") ?? 0);
            bool hideHover = entry.JsonBool("hideHover") ?? false;
            int fameScore = entry.JsonInt("fameScore") ?? 0;
            int jobType = entry.JsonInt("jobType") ?? 0;
            float x = (float)(entry.JsonDouble("x") ?? 0.0);
            float y = (float)(entry.JsonDouble("y") ?? 0.0);
            int level = entry.JsonInt("level") ?? 1;
            bool winterClothes = entry.JsonBool("winterClothes") ?? false;
            bool outfitChanging = entry.JsonBool("outfitChanging") ?? false;
            nextLotSims[simId] = new LotSimInfo
            {
                TooltipName = tooltipName,
                Gender = gender,
                Guid = guid,
                HideHover = hideHover,
                FameScore = fameScore,
                JobType = jobType,
                X = x,
                Y = y,
                Level = level,
                WinterClothes = winterClothes,
                OutfitChanging = outfitChanging,
            };
        }

        _lotSims = nextLotSims;
        _simAnimations = sims
            .Select(static s => s.JsonString("animation"))
            .OfType<string>()
            .ToList();

        Dictionary<string, JsonElement>? selected = null;
        foreach (var entry in sims)
        {
            if (entry.JsonInt("id") == _selectedSim)
            {
                selected = entry;
                break;
            }
        }

        if (selected is not null
            && selected.JsonDouble("x") is double simX
            && selected.JsonDouble("y") is double simY)
        {
            var actions = selected.JsonArray("actions") ?? [];
            ScriptSimPosition = new CGPoint(simX, simY);
            ScriptSimIdle = !actions.Any(static a => a.JsonBool("visible") == true);
            ScriptSimActions = actions
                .Select(static a => a.JsonString("name"))
                .OfType<string>()
                .ToList();
            _scriptSimLevel = selected.JsonInt("level");
        }
        else
        {
            ScriptSimPosition = null;
            _scriptSimLevel = null;
            ScriptSimIdle = false;
        }

        ApplyPictureInPicture(state);
        CentreOnSelectedSimIfPending();
        CentreRelationshipIfPending();
        CentrePipObjectIfPending();
    }

    private void CentreOnSelectedSimIfPending()
    {
        if (!_centresOnSelectedSim
            || _selectedSim == 0
            || ScriptSimPosition is not { } position
            || _scriptSimLevel is not int level)
        {
            return;
        }

        if (level != EffectiveViewLevel && level >= 1 && level <= Renderer.StoryCount)
        {
            _pendingViewLevel = level;
            _pendingRoofsVisible = false;
            _pendingViewSceneRevision = null;
            _pendingViewRequestID = Send(
                "level",
                new Dictionary<string, object?>(StringComparer.Ordinal) { ["value"] = level, ["roofs"] = false });
            return;
        }

        if (level != Renderer.ViewLevel)
        {
            return;
        }

        if (Renderer.SceneViewport(SimdCanvas) is not { } viewport
            || Renderer.ScreenPoint((float)position.X, (float)position.Y, SimdCanvas) is not { } point)
        {
            return;
        }

        _centresOnSelectedSim = false;
        float lift = 8f * MathF.Sqrt(6f) * Renderer.Zoom.Factor() * Renderer.UIScale;
        Renderer.Pan += viewport.Size / 2f - (point - new Vector2(0f, lift));
        if (EffectiveRoofsVisible)
        {
            _pendingRoofsVisible = false;
            _pendingViewSceneRevision = null;
            _pendingViewRequestID = Send(
                "roofs",
                new Dictionary<string, object?>(StringComparer.Ordinal) { ["visible"] = false });
        }
    }

    private string NeighborhoodSettingPath =>
        Path.Combine(
            Options.DataRoot ?? Workspace,
            "runtime",
            "profiles",
            Options.Profile,
            "Settings",
            "current-neighborhood.txt");

    private void StoreNeighborhood(int number)
    {
        string path = NeighborhoodSettingPath;
        try
        {
            string? directory = Path.GetDirectoryName(path);
            if (!string.IsNullOrEmpty(directory))
            {
                Directory.CreateDirectory(directory);
            }

            File.WriteAllText(path, number.ToString(CultureInfo.InvariantCulture), Encoding.UTF8);
        }
        catch (Exception error)
        {
            Log($"Neighborhood setting: {error}");
        }
    }

    private int NeighborhoodModeForCurrentLot() =>
        AwayLotLocks.ReturnNeighborhoodMode(
            _currentHouse ?? Options.House ?? 0,
            HomeLotHouse,
            _simlessBuildMode,
            Ui.Neighborhood?.Mode ?? _lastNeighborhoodMode);

    private void BeginStartupSplash(int startingAt)
    {
        Ui.TravelLoadScreen = null;
        Ui.Loading = true;
        _splashProgressQueue = Strings.SplashProgressSequence(startingAt).ToList();
        if (_splashProgressQueue.Count == 0)
        {
            Ui.LoadingText = Strings.SplashProgress(startingAt);
        }
        else
        {
            Ui.LoadingText = _splashProgressQueue[0];
            _splashProgressQueue.RemoveAt(0);
        }

        _lastSplashProgressStep = CurrentUptime();
    }
}
