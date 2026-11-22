using System.Collections.Concurrent;
using System.Diagnostics;
using StbImageWriteSharp;

namespace SimsSDL;

internal sealed partial class LiveController
{

    private async Task<(string Session, string Manifest)> FetchNeighborhoodManifest(
        int mode,
        string? edit = null,
        int neighborhood = 1,
        bool includeWebScenes = false)
    {
        if (_daemonMode && _bridgeConnected && Bridge is { } bridge)
        {
            if (edit is null
                && SimsSDL.Client.NeighborhoodExport.LookupCached(
                    Content,
                    Workspace,
                    Options.DataRoot,
                    mode,
                    Options.Profile,
                    neighborhood,
                    includeWebScenes) is { } hit)
            {
                return hit;
            }

            string storageRoot = Options.DataRoot ?? Workspace;
            string exportSession = Path.Combine(
                storageRoot,
                "runtime",
                "sessions",
                "neighborhood-" + Guid.NewGuid().ToString("D").ToUpperInvariant());
            Directory.CreateDirectory(exportSession);
            SessionSweeper.Claim(exportSession);
            var parameters = new Dictionary<string, object?>(StringComparer.Ordinal)
            {
                ["mode"] = mode,
                ["neighborhood"] = neighborhood,
                ["outputDirectory"] = exportSession,
            };
            if (!string.IsNullOrEmpty(edit))
            {
                parameters["edit"] = edit;
            }

            if (includeWebScenes)
            {
                parameters["webScenes"] = true;
            }

            var continuation = new TaskCompletionSource<(string Session, string Manifest)>(
                TaskCreationOptions.RunContinuationsAsynchronously);
            string requestId = bridge.Send("neighborhood", parameters);
            _pendingDaemonNeighborhoodRequests[requestId] = (exportSession, continuation);
            var exported = await continuation.Task.ConfigureAwait(false);
            if (edit is null)
            {
                SimsSDL.Client.NeighborhoodExport.StoreCached(
                    Content,
                    Workspace,
                    Options.DataRoot,
                    mode,
                    Options.Profile,
                    neighborhood,
                    includeWebScenes,
                    session: exported.Session,
                    manifest: exported.Manifest);
            }

            return exported;
        }

        return await SimsSDL.Client.NeighborhoodExport.Create(
            Content,
            Workspace,
            Options.DataRoot,
            mode,
            Options.Profile,
            edit,
            neighborhood,
            discardsContent: true,
            nativeEngine: UsesNativeEngine,
            includeWebScenes: includeWebScenes).ConfigureAwait(false);
    }

    public void LoadBaseNeighborhood(int mode = 1, bool reopenFamilyPicker = false)
    {
        if (_loadingNeighborhood || _editingNeighborhood)
        {
            return;
        }

        _neighborhoodLoadGeneration = unchecked(_neighborhoodLoadGeneration + 1);
        ulong requestGen = _neighborhoodLoadGeneration;
        int targetNeighborhood = _currentNeighborhood;
        _loadingNeighborhood = true;
        Renderer.LiveMode = false;
        if (!_hasCompletedInitialLoad && Ui.Neighborhood is null && Ui.HouseholdCreation is null)
        {
            Renderer.DrawsLot = false;
            BeginStartupSplash(startingAt: 3);
            if (Options.Audio && !_daemonMode && _startupLoadAudio is null && LoadLoopURL(Content) is { } loop)
            {
                try
                {
                    var player = new SDLAudioPlayer(Content.Root);
                    player.PlayLoadLoop(loop, LoadLoopVolume());
                    _startupLoadAudio = player;
                }
                catch
                {
                }
            }
        }
        else
        {
            Ui.Loading = false;
            if (Ui.Neighborhood is not null || Ui.HouseholdCreation is not null)
            {
                Renderer.DrawsLot = false;
            }
        }

        _ = LoadBaseNeighborhoodCoreAsync(mode, reopenFamilyPicker, requestGen, targetNeighborhood);
    }

    private async Task LoadBaseNeighborhoodCoreAsync(
        int mode,
        bool reopenFamilyPicker,
        ulong requestGen,
        int targetNeighborhood)
    {
        var weakSelf = new WeakReference<LiveController>(this);
        try
        {
            AppLog.SetStage(FormattableString.Invariant($"Neighborhood: loading N{targetNeighborhood} (mode {mode})"));
            var exported = await FetchNeighborhoodManifest(
                mode: mode,
                edit: null,
                neighborhood: targetNeighborhood).ConfigureAwait(false);
            MainThreadDispatcher.Post(() =>
            {
                if (!weakSelf.TryGetTarget(out var self))
                {
                    return;
                }

                bool loaded = false;
                try
                {
                    if (self._neighborhoodLoadGeneration != requestGen
                        || (self.Bridge is not null && !(self._daemonMode && (self._currentHouse ?? 0) == 0)))
                    {
                        return;
                    }

                    var neighborhood = new OriginalNeighborhoodOverlay(
                        self.Content,
                        self.Ui.Device,
                        exported.Manifest,
                        exported.Session,
                        self.Ui.Font);
                    self.WireNeighborhoodOverlay(neighborhood);
                    self.Ui.Neighborhood = neighborhood;
                    self.Ui.Loading = false;
                    self._hasCompletedInitialLoad = true;
                    loaded = true;
                    self.Renderer.DrawsLot = false;
                    self._neighborhoodHouseSelected = house =>
                    {
                        if (weakSelf.TryGetTarget(out var target))
                        {
                            target.SelectNeighborhoodHouse(house);
                        }
                    };
                    Log($"neighborhood {targetNeighborhood} ({exported.Session})");
                    AppLog.SetStage(
                        FormattableString.Invariant($"Ready: Neighborhood N{targetNeighborhood} (mode {mode})"),
                        isSteadyState: true);
                    self._audio?.StopLoadLoop();
                    self._startupLoadAudio?.Close();
                    self._startupLoadAudio = null;
                    self.StartFrontendAudio();
                    self.StartNeighborhoodAudio(neighborhood);
                    if (self._daemonMode && self._bridgeConnected && !self._daemonWarmedUp)
                    {
                        self._daemonWarmedUp = true;
                        _ = self.Send("warmup", new Dictionary<string, object?>(StringComparer.Ordinal));
                    }

                    if (reopenFamilyPicker)
                    {
                        self.OpenFamilyPicker(house: 0, families: neighborhood.Families);
                    }
                    else if (self._safeModeBootError is { } bootErr)
                    {
                        self._safeModeBootError = null;
                        self.OpenModsOverlay(bootErr);
                    }
                }
                catch (Exception error)
                {
                    if (self._neighborhoodLoadGeneration == requestGen)
                    {
                        self.Renderer.DrawsLot = false;
                        Log($"Neighborhood: {error}");
                        self.HandleInitialOrNeighborhoodError(error);
                    }
                }
                finally
                {
                    if (self._neighborhoodLoadGeneration == requestGen)
                    {
                        self._loadingNeighborhood = false;
                        if (loaded || self.Ui.Neighborhood is not null || self._hasCompletedInitialLoad)
                        {
                            self.Ui.Loading = false;
                        }
                        self._audio?.StopLoadLoop();
                    }

                    self._startupLoadAudio?.Close();
                    self._startupLoadAudio = null;
                }
            });
        }
        catch (Exception error)
        {
            AppLog.Error($"Neighborhood load failed (N{targetNeighborhood}, mode {mode}): {error}");
            MainThreadDispatcher.Post(() =>
            {
                if (!weakSelf.TryGetTarget(out var self))
                {
                    return;
                }

                if (self._neighborhoodLoadGeneration == requestGen)
                {
                    self.Renderer.DrawsLot = false;
                    Log($"Neighborhood: {error}");
                    self._loadingNeighborhood = false;
                    self._audio?.StopLoadLoop();
                    self.HandleInitialOrNeighborhoodError(error);
                }

                self._startupLoadAudio?.Close();
                self._startupLoadAudio = null;
            });
        }
    }

    public void ReturnToNeighborhood(bool saving, int? mode = null)
    {
        try
        {
            int targetMode = mode ?? NeighborhoodModeForCurrentLot();
            if (saving)
            {
                var weakSelf = new WeakReference<LiveController>(this);
                SendSaveRequest(succeeded =>
                {
                    if (!succeeded || !weakSelf.TryGetTarget(out var self))
                    {
                        return;
                    }

                    self.ReturnToNeighborhood(saving: false, mode: targetMode);
                });
                return;
            }

            CloseCameraOverlay();
            CloseOptionsOverlay();
            DismissMenu();
            Ui.PanelMinimized = false;
            _lastAudioSceneRevision = -1;
            _lastAudioAnimationSequence = -1;
            Renderer.ResetSceneRevisionTracking();
            if (_daemonMode)
            {
                if ((_currentHouse ?? 0) > 0)
                {
                    _ = Send("closeLot", new Dictionary<string, object?>(StringComparer.Ordinal) { ["save"] = false });
                }

                _currentHouse = 0;
                _frontendMusic = null;
                _simulatorZoom = null;
                _simulatorMode = null;
                _simulatorViewScrolling = null;
            }
            else
            {
                _audio?.Close();
                _audio = null;
                Bridge?.Stop(save: false);
                Bridge = null;
            }

            HomeLotHouse = null;
            AwayBuyBuildLocked = false;
            EmergencyBuyBuildLocked = false;
            SimlessBuildMode = false;
            _simIDs = [];
            _lotSims.Clear();
            _placedObjectMeta.Clear();
            _pendingSaleRequests.Clear();
            _pendingDisposePreviewRequest = null;
            Ui.DisposePanel = null;
            ClosePictureInPicture();
            Ui.GameDialog = null;
            _localDialogToken = null;
            _localDialogResponse = null;
            Ui.BuyMode = false;
            Ui.BuildMode = false;
            Ui.SoundOptions.Dismiss();
            Ui.PluginPanel = null;
            CloseOutfitPicker();
            _activeNeighborhoodDialog = null;
            _pendingNeighborhood = null;
            _pendingNeighborhoodResponse = null;
            _pendingTravelSelection = null;
            _openingNeighborhoodLot = false;
            _switchingLot = false;
            _awaitingLotSwitchChange = false;
            Ui.Loading = false;
            Renderer.Pan = Vector2.Zero;
            LoadBaseNeighborhood(mode: targetMode);
        }
        finally
        {
            if (!saving)
            {
                LotSaveDisabled = false;
            }
        }
    }

    private void ShowNeighborhoodError(Exception error)
    {
        AppLog.Error($"Neighborhood/session error: {error}");
        string summary = $"{error.GetType().Name}: {error.Message}";
        if (AppLog.CurrentLogPath is { Length: > 0 } logPath)
        {
            summary += $"\n\nLog saved to:\n{logPath}";
        }

        PresentLocalFeedback(Strings.MoveInErrorTitle(), summary);
    }

    private void HandleInitialOrNeighborhoodError(Exception error)
    {
        AppLog.Error($"Startup/neighborhood failure: {error}");
        AppLog.SetStage($"Error: {error.GetType().Name}", isSteadyState: true);
        if (!_hasCompletedInitialLoad && Ui.Neighborhood is null && (_currentHouse ?? 0) == 0)
        {
            // Keep Loading = true so LiveUI renders the dialog over the splash screen rather than
            // flipping ShowsLot to true over an empty black void with an hourglass cursor.
            Ui.Loading = true;
            string summary = $"{error.GetType().Name}: {error.Message}";
            string? logPath = AppLog.CurrentLogPath;
            string? logsDir = AppLog.CurrentLogsDirectory;
            if (!string.IsNullOrEmpty(logPath))
            {
                summary += $"\n\nLog saved to:\n{logPath}";
            }

            if (!Options.AnswerDialogs && !string.IsNullOrEmpty(logsDir) && Directory.Exists(logsDir))
            {
                var weakSelf = new WeakReference<LiveController>(this);
                PresentLocalConfirmation(
                    Strings.MoveInErrorTitle(),
                    summary,
                    "Open Logs",
                    "Quit",
                    response: choice =>
                    {
                        if (choice == 0)
                        {
                            AppLog.Flush();
                            AppLog.RevealLogInFileManager(logPath, logsDir);
                        }

                        if (weakSelf.TryGetTarget(out var self))
                        {
                            self.QuitRequested = true;
                        }
                    });
                return;
            }

            var weakFallback = new WeakReference<LiveController>(this);
            PresentLocalConfirmation(
                Strings.MoveInErrorTitle(),
                summary,
                Strings.OkButton(),
                "Quit",
                response: _ =>
                {
                    if (weakFallback.TryGetTarget(out var self))
                    {
                        self.QuitRequested = true;
                    }
                });
            return;
        }

        Ui.Loading = false;
        ShowNeighborhoodError(error);
    }

    private (string Title, string Message) MagicTownStrings(
        ushort table,
        int titleIndex,
        int messageIndex,
        string fallbackTitle,
        string fallbackMessage)
    {
        byte[]? data = null;
        try
        {
            data = Content.Read("GameData/UIText.iff");
        }
        catch
        {
            try
            {
                data = Content.Read("UIText.iff");
            }
            catch
            {
                data = null;
            }
        }

        if (data is null
            || OriginalStringResource.TryParse(data, Content.Language.Code, new HashSet<ushort> { table }) is not { } resource
            || !resource.Tables.TryGetValue(table, out IReadOnlyList<string>? entries))
        {
            return (fallbackTitle, fallbackMessage);
        }

        string title = titleIndex >= 0 && titleIndex < entries.Count && entries[titleIndex].Length > 0
            ? entries[titleIndex]
            : fallbackTitle;
        string message = messageIndex >= 0 && messageIndex < entries.Count && entries[messageIndex].Length > 0
            ? entries[messageIndex]
            : fallbackMessage;
        return (title, message);
    }

    private void SelectNeighborhoodHouse(int house)
    {
        if (Ui.Neighborhood is not { } neighborhood || Ui.FamilyPicker is not null || Ui.ModsOverlay is not null || Ui.Credits is not null)
        {
            return;
        }

        PlayUISound("ui_nhood_click");
        if (_rezoneMode)
        {
            _rezoneMode = false;
            neighborhood.SetRezoneMode(false);
            BeginRezone(house);
            return;
        }

        if (_evictMode)
        {
            _evictMode = false;
            neighborhood.SetEvictMode(false);
            ConfirmEvict(house, neighborhood);
            return;
        }

        if (FamilyPlacement is { } family)
        {
            if (!neighborhood.IsVacantResidential(house))
            {
                PlayUISound("ui_nhood_error");
                return;
            }

            FamilyPlacement = null;
            OfferLot(house, family, neighborhood);
            return;
        }

        if (neighborhood.IsVacantResidential(house))
        {
            if (neighborhood.Mode == 7 && house is >= 90 and <= 92)
            {
                var (title, message) = MagicTownStrings(
                    table: 133,
                    titleIndex: 0,
                    messageIndex: 1,
                    fallbackTitle: "No one lives here!",
                    fallbackMessage: "You must pick a family and move them in first.");
                PresentLocalFeedback(title, message);
                return;
            }

            OpenFamilyPicker(house: house, families: neighborhood.Families);
            return;
        }

        OpenNeighborhoodHouse(house, createHousehold: false);
    }

    private void BeginRezone(int house)
    {
        if (Ui.Neighborhood is not { } neighborhood || !neighborhood.HasLot(house))
        {
            return;
        }

        int mode = neighborhood.Mode;
        string yes = Strings.YesButton();
        string no = Strings.NoButton();
        var weakSelf = new WeakReference<LiveController>(this);
        if (neighborhood.IsOnVacation(house))
        {
            PresentLocalFeedback(Strings.VacationEvictTitle(), Strings.VacationEvictMessage());
        }
        else if (neighborhood.Occupant(house) is { } family)
        {
            string message = OriginalUIStrings.Format(
                Strings.RezoneEvictMessage(),
                [family.Name, OriginalUIStrings.Simoleons(family.NetWorth)]);
            PresentLocalConfirmation(
                Strings.RezoneEvictTitle(),
                message,
                yes,
                no,
                response: code =>
                {
                    if (code != 0 || !weakSelf.TryGetTarget(out var self))
                    {
                        return;
                    }

                    self.PlayUISound("ui_nhood_bdoze_evict");
                    self.ReloadNeighborhood(
                        edit: $"evict:{house}",
                        mode: mode,
                        completion: () => self.BeginRezone(house));
                });
        }
        else if (!neighborhood.IsBulldozed(house))
        {
            PresentLocalConfirmation(
                Strings.RezoneBulldozeTitle(),
                Strings.RezoneBulldozeMessage(),
                yes,
                no,
                response: code =>
                {
                    if (code != 0 || !weakSelf.TryGetTarget(out var self))
                    {
                        return;
                    }

                    self.PlayUISound("ui_nhood_bdoze_demolish");
                    self.ReloadNeighborhood(
                        edit: $"bulldoze:{house}",
                        mode: mode,
                        completion: () => self.BeginRezone(house));
                });
        }
        else
        {
            string current = Strings.ZoningType(neighborhood.ZoningIndex(house));
            string message = OriginalUIStrings.Format(Strings.RezoneMessage(), [current]);
            PresentLocalConfirmation(
                Strings.RezoneTitle(),
                message,
                Strings.ZoningType(0),
                Strings.ZoningType(1),
                Strings.CancelButton(),
                response: code =>
                {
                    if ((code != 0 && code != 1)
                        || code == neighborhood.ZoningIndex(house)
                        || !weakSelf.TryGetTarget(out var self))
                    {
                        return;
                    }

                    self.ReloadNeighborhood(edit: $"rezone:{house}:{code}", mode: mode);
                });
        }
    }

    private void ConfirmEvict(int house, OriginalNeighborhoodOverlay neighborhood)
    {
        int mode = neighborhood.Mode;
        if (neighborhood.IsOnVacation(house))
        {
            PresentLocalFeedback(Strings.VacationEvictTitle(), Strings.VacationEvictMessage());
            return;
        }

        bool hasHouse = !neighborhood.IsBulldozed(house);
        if (neighborhood.Occupant(house) is not { } family)
        {
            if (hasHouse)
            {
                ConfirmBulldoze(house, mode, evictFirst: false);
                return;
            }

            PlayUISound("ui_nhood_error");
            PresentLocalFeedback(Strings.NothingToBulldozeTitle(), Strings.NothingToBulldozeMessage());
            return;
        }

        string message = OriginalUIStrings.Format(
            Strings.EvictMessage(),
            [family.Name, OriginalUIStrings.Simoleons(family.NetWorth)]);
        var weakSelf = new WeakReference<LiveController>(this);
        PresentLocalConfirmation(
            Strings.EvictTitle(),
            message,
            Strings.YesButton(),
            Strings.NoButton(),
            response: code =>
            {
                if (code != 0 || !weakSelf.TryGetTarget(out var self))
                {
                    return;
                }

                self.PlayUISound("ui_nhood_bdoze_evict");
                if (hasHouse)
                {
                    self.ConfirmBulldoze(house, mode, evictFirst: true);
                }
                else
                {
                    self.ReloadNeighborhood(edit: $"evict:{house}", mode: mode);
                }
            });
    }

    private void ConfirmBulldoze(int house, int mode, bool evictFirst = false)
    {
        var weakSelf = new WeakReference<LiveController>(this);
        PresentLocalConfirmation(
            Strings.BulldozeTitle(),
            Strings.BulldozeMessage(),
            Strings.YesButton(),
            Strings.NoButton(),
            response: code =>
            {
                if (!weakSelf.TryGetTarget(out var self))
                {
                    return;
                }

                if (code == 0)
                {
                    self.PlayUISound("ui_nhood_bdoze_demolish");
                    if (evictFirst)
                    {
                        if (self._daemonMode)
                        {
                            self.ReloadNeighborhood(edit: $"evict:{house};bulldoze:{house}", mode: mode);
                        }
                        else
                        {
                            self.ReloadNeighborhood(
                                edit: $"evict:{house}",
                                mode: mode,
                                completion: () =>
                                {
                                    if (weakSelf.TryGetTarget(out var target))
                                    {
                                        target.ReloadNeighborhood(edit: $"bulldoze:{house}", mode: mode);
                                    }
                                });
                        }
                    }
                    else
                    {
                        self.ReloadNeighborhood(edit: $"bulldoze:{house}", mode: mode);
                    }
                }
                else if (evictFirst)
                {
                    self.ReloadNeighborhood(edit: $"evict:{house}", mode: mode);
                }
            });
    }

    private void ChooseBannerAction(BannerAction action)
    {
        if (_activeNeighborhoodDialog is not null && action != BannerAction.ReturnHome)
        {
            PlayUISound("ui_nhood_error");
            return;
        }

        PlayUISound("ui_nhood_click");
        switch (action)
        {
            case BannerAction.ReturnHome:
                if (_activeNeighborhoodDialog is not null)
                {
                    RespondToNeighborhood(-1);
                }
                else
                {
                    ReloadNeighborhood(edit: null, mode: 1);
                }

                break;

            case BannerAction.Downtown:
            case BannerAction.Vacation:
            case BannerAction.StudioTown:
            case BannerAction.MagicTown:
                if (action.MapMode() is int mode)
                {
                    ReloadNeighborhood(edit: null, mode: mode);
                }

                break;

            case BannerAction.Rezone:
                FamilyPlacement = null;
                _rezoneMode = !_rezoneMode;
                if (_rezoneMode)
                {
                    _evictMode = false;
                    Ui.Neighborhood?.SetEvictMode(false);
                }

                Ui.Neighborhood?.SetRezoneMode(_rezoneMode);
                break;

            case BannerAction.Bulldoze:
                FamilyPlacement = null;
                _evictMode = !_evictMode;
                if (_evictMode)
                {
                    _rezoneMode = false;
                    Ui.Neighborhood?.SetRezoneMode(false);
                }

                Ui.Neighborhood?.SetEvictMode(_evictMode);
                break;

            case BannerAction.Quit:
                ConfirmQuit();
                break;

            case BannerAction.ImportFamily:
                OfferImport(0);
                break;

            case BannerAction.Previous:
            case BannerAction.Next:
                SwitchNeighborhood(forward: action == BannerAction.Next);
                break;

            case BannerAction.Mods:
                OpenModsOverlay();
                break;

            case BannerAction.Internet:
                ExportNeighborhoodWebPages();
                break;

            case BannerAction.Credits:
            case BannerAction.SimsLogo:
                OpenCredits();
                break;

            case BannerAction.SelectFamily:
            {
                if (Ui.Neighborhood is not { } neighborhood || (neighborhood.Mode != 1 && neighborhood.Mode != 7))
                {
                    PlayUISound("ui_nhood_error");
                    return;
                }

                FamilyPlacement = null;
                _rezoneMode = false;
                _evictMode = false;
                neighborhood.SetRezoneMode(false);
                neighborhood.SetEvictMode(false);
                OpenFamilyPicker(house: 0, families: neighborhood.Families);
                break;
            }

            default:
                break;
        }
    }

    private void OfferImport(int index)
    {
        if (Ui.Neighborhood is not { } neighborhood || index < 0 || index >= neighborhood.Imports.Count)
        {
            if (index == 0)
            {
                PlayUISound("ui_nhood_error");
            }

            return;
        }

        var family = neighborhood.Imports[index];
        static string Truncate32(string s) => s.Length <= 32 ? s : s[..32];
        string members = string.Join(", ", family.Members.Take(8).Select(Truncate32));
        string message = Truncate32(family.FamilyName) + (members.Length == 0 ? string.Empty : "\n" + members);
        var weakSelf = new WeakReference<LiveController>(this);
        PresentLocalConfirmation(
            Strings.ImportFamilyTitle(),
            message,
            Strings.YesButton(),
            Strings.NoButton(),
            response: code =>
            {
                if (!weakSelf.TryGetTarget(out var self))
                {
                    return;
                }

                if (code == 0)
                {
                    self.ReloadNeighborhood(
                        edit: $"import:{index}",
                        mode: neighborhood.Mode,
                        errorMessage: ("Error", "Couldn't import the family"));
                }
                else
                {
                    self.OfferImport(index + 1);
                }
            });
    }

    private void SwitchNeighborhood(bool forward)
    {
        if (Ui.Neighborhood is not { } neighborhood || neighborhood.Mode != 1)
        {
            PlayUISound("ui_nhood_error");
            return;
        }

        int @base = _pendingNeighborhoodTarget ?? _currentNeighborhood;
        if (OriginalNeighborhoodOverlay.NeighborhoodAfter(@base, neighborhood.Neighborhoods, forward) is not int target
            || target == @base)
        {
            PlayUISound("ui_nhood_error");
            return;
        }

        _pendingNeighborhoodTarget = target;
        _rezoneMode = false;
        var weakSelf = new WeakReference<LiveController>(this);
        ReloadNeighborhood(
            edit: null,
            mode: 1,
            targetNeighborhood: target,
            completion: () =>
            {
                if (!weakSelf.TryGetTarget(out var self))
                {
                    return;
                }

                self._currentNeighborhood = target;
                if (self._pendingNeighborhoodTarget == target)
                {
                    self._pendingNeighborhoodTarget = null;
                }

                self.StoreNeighborhood(target);
            },
            failure: () =>
            {
                if (!weakSelf.TryGetTarget(out var self))
                {
                    return;
                }

                if (self._pendingNeighborhoodTarget == target)
                {
                    self._pendingNeighborhoodTarget = null;
                }
            });
    }

    private void ReloadNeighborhood(
        string? edit,
        int mode = 1,
        int? targetNeighborhood = null,
        (string Title, string Message)? errorMessage = null,
        Action? completion = null,
        Action? failure = null)
    {
        if (edit is not null)
        {
            if (_loadingNeighborhood || _editingNeighborhood)
            {
                return;
            }

            _editingNeighborhood = true;
        }
        else
        {
            if (_editingNeighborhood)
            {
                return;
            }

            if (targetNeighborhood is null)
            {
                _pendingNeighborhoodTarget = null;
            }
        }

        _evictMode = false;
        _neighborhoodLoadGeneration = unchecked(_neighborhoodLoadGeneration + 1);
        ulong requestGen = _neighborhoodLoadGeneration;
        int requestedNeighborhood = targetNeighborhood ?? _currentNeighborhood;
        _loadingNeighborhood = true;
        _ = ReloadNeighborhoodCoreAsync(
            edit,
            mode,
            requestGen,
            requestedNeighborhood,
            errorMessage,
            completion,
            failure);
    }

    private async Task ReloadNeighborhoodCoreAsync(
        string? edit,
        int mode,
        ulong requestGen,
        int requestedNeighborhood,
        (string Title, string Message)? errorMessage,
        Action? completion,
        Action? failure)
    {
        var weakSelf = new WeakReference<LiveController>(this);
        try
        {
            var exported = await FetchNeighborhoodManifest(
                mode: mode,
                edit: edit,
                neighborhood: requestedNeighborhood).ConfigureAwait(false);
            MainThreadDispatcher.Post(() =>
            {
                if (!weakSelf.TryGetTarget(out var self))
                {
                    return;
                }

                try
                {
                    if (self._neighborhoodLoadGeneration != requestGen)
                    {
                        return;
                    }

                    int? previousMode = self.Ui.Neighborhood?.Mode;
                    var neighborhood = new OriginalNeighborhoodOverlay(
                        self.Content,
                        self.Ui.Device,
                        exported.Manifest,
                        exported.Session,
                        self.Ui.Font);
                    self.WireNeighborhoodOverlay(neighborhood);
                    self.Ui.Neighborhood = neighborhood;
                    self._neighborhoodHouseSelected = house =>
                    {
                        if (weakSelf.TryGetTarget(out var target))
                        {
                            target.SelectNeighborhoodHouse(house);
                        }
                    };
                    if (neighborhood.Mode != previousMode)
                    {
                        self.StopNeighborhoodAmbientAudio();
                        self.StartNeighborhoodAudio(neighborhood);
                    }

                    if (edit is not null)
                    {
                        self._editingNeighborhood = false;
                    }

                    self._loadingNeighborhood = false;
                    self.Ui.Loading = false;
                    completion?.Invoke();
                }
                catch (Exception error)
                {
                    FailNeighborhoodReload(self, requestGen, errorMessage, failure, error);
                }
                finally
                {
                    FinishNeighborhoodReload(self, edit, requestGen);
                }
            });
        }
        catch (Exception error)
        {
            AppLog.Error($"Neighborhood reload failed (N{requestedNeighborhood}, mode {mode}): {error}");
            MainThreadDispatcher.Post(() =>
            {
                if (!weakSelf.TryGetTarget(out var self))
                {
                    return;
                }

                try
                {
                    FailNeighborhoodReload(self, requestGen, errorMessage, failure, error);
                }
                finally
                {
                    FinishNeighborhoodReload(self, edit, requestGen);
                }
            });
        }
    }

    private static void FailNeighborhoodReload(
        LiveController self,
        ulong requestGen,
        (string Title, string Message)? errorMessage,
        Action? failure,
        Exception error)
    {
        if (self._neighborhoodLoadGeneration != requestGen)
        {
            return;
        }

        self._loadingNeighborhood = false;
        self.Ui.Loading = false;
        failure?.Invoke();
        self.PlayUISound("ui_nhood_error");
        self.PresentLocalFeedback(
            errorMessage?.Title ?? self.Strings.MoveInErrorTitle(),
            errorMessage?.Message ?? self.Strings.EvictFailedMessage());
        Log($"Neighborhood edit: {error}");
    }

    private static void FinishNeighborhoodReload(LiveController self, string? edit, ulong requestGen)
    {
        if (edit is not null)
        {
            self._editingNeighborhood = false;
        }

        if (self._neighborhoodLoadGeneration == requestGen)
        {
            self._loadingNeighborhood = false;
            self.Ui.Loading = false;
        }
    }

    private void ExportNeighborhoodWebPages(bool open = true, int? fallbackMode = null)
    {
        if (_exportingWebPages)
        {
            return;
        }

        int mode = Ui.Neighborhood?.Mode ?? fallbackMode ?? 1;
        if (mode is not (1 or 2 or 3 or 5))
        {
            return;
        }

        if (Ui.Neighborhood is { } neighborhood && neighborhood.WebHouseRenderRequests.Count > 0)
        {
            WriteNeighborhoodWebPages(neighborhood, open);
            return;
        }

        _exportingWebPages = true;
        int requestedNeighborhood = _currentNeighborhood;
        _ = ExportNeighborhoodWebPagesCoreAsync(mode, requestedNeighborhood, open);
    }

    private async Task ExportNeighborhoodWebPagesCoreAsync(int mode, int requestedNeighborhood, bool open)
    {
        var weakSelf = new WeakReference<LiveController>(this);
        try
        {
            var exported = await FetchNeighborhoodManifest(
                mode: mode,
                edit: null,
                neighborhood: requestedNeighborhood,
                includeWebScenes: true).ConfigureAwait(false);
            MainThreadDispatcher.Post(() =>
            {
                if (!weakSelf.TryGetTarget(out var self))
                {
                    return;
                }

                try
                {
                    var webOverlay = new OriginalNeighborhoodOverlay(
                        self.Content,
                        self.Ui.Device,
                        exported.Manifest,
                        exported.Session,
                        self.Ui.Font);
                    self.WriteNeighborhoodWebPages(webOverlay, open);
                }
                catch (Exception error)
                {
                    ReportWebExportFailure(self, error);
                }
                finally
                {
                    self._exportingWebPages = false;
                }
            });
        }
        catch (Exception error)
        {
            AppLog.Error($"Neighborhood web export failed (N{requestedNeighborhood}, mode {mode}): {error}");
            MainThreadDispatcher.Post(() =>
            {
                if (!weakSelf.TryGetTarget(out var self))
                {
                    return;
                }

                try
                {
                    ReportWebExportFailure(self, error);
                }
                finally
                {
                    self._exportingWebPages = false;
                }
            });
        }
    }

    private static void ReportWebExportFailure(LiveController self, Exception error)
    {
        self.PlayUISound("ui_nhood_error");
        self.PresentLocalFeedback(
            self.Strings.SorryTitle(),
            $"The web pages could not be written: {error.Message}");
    }

    private void WriteNeighborhoodWebPages(OriginalNeighborhoodOverlay neighborhood, bool open)
    {
        string destination = Path.Combine(
            Options.DataRoot ?? Workspace,
            "runtime",
            "profiles",
            Options.Profile,
            "Web Pages");
        try
        {
            var houseViews = RenderWebHouseViews(neighborhood.WebHouseRenderRequests);
            string page = WebExport.Export(
                Content.Root,
                neighborhood.WebFamilies(houseViews),
                destination,
                Content.Language);
            Log($"Web pages written to {destination}");
            if (!open || Options.Script is not null)
            {
                return;
            }

            _ = SDL_OpenURL(new Uri(Path.GetFullPath(page)).AbsoluteUri);
        }
        catch (Exception error)
        {
            ReportWebExportFailure(this, error);
        }
    }

    private Dictionary<int, NeighborhoodWebExport.HouseViews> RenderWebHouseViews(
        IReadOnlyList<(int House, string Thumbnail, string Exterior, string Floor1, string? Floor2)> requests)
    {
        if (requests.Count == 0)
        {
            return new Dictionary<int, NeighborhoodWebExport.HouseViews>();
        }

        byte[] Jpeg(string scenePath, int house)
        {
            var snapshot = new LotRenderer(Renderer.GPU);
            snapshot.LoadScene(scenePath);
            snapshot.Zoom = LotZoom.Far;
            if (snapshot.Scene is { } scene)
            {
                float fit = MathF.Min(432f / MathF.Max(1f, scene.Width), 288f / MathF.Max(1f, scene.Height));
                snapshot.UIScale = fit / snapshot.Zoom.Factor();
            }

            using var targets = new RenderTargets(Renderer.GPU, 432, 288);
            nint command = SDL_AcquireGPUCommandBuffer(Renderer.GPU.Device);
            if (command == nint.Zero)
            {
                throw new SDLError("SDL_AcquireGPUCommandBuffer");
            }

            snapshot.Encode(command, targets.Color, targets.Depth);
            if (!SDL_SubmitGPUCommandBuffer(command))
            {
                throw new SDLError("SDL_SubmitGPUCommandBuffer");
            }

            byte[] rgba = Renderer.GPU.ReadPixels(targets.Color);
            using var stream = new MemoryStream();
            var writer = new ImageWriter();
            writer.WriteJpg(rgba, 432, 288, ColorComponents.RedGreenBlueAlpha, stream, 90);
            byte[] output = stream.ToArray();
            if (output.Length == 0)
            {
                throw new ContentError($"Could not encode the lot snapshot for house {house}.");
            }

            return output;
        }

        var result = new Dictionary<int, NeighborhoodWebExport.HouseViews>(requests.Count);
        foreach (var request in requests)
        {
            result[request.House] = new NeighborhoodWebExport.HouseViews(
                Thumbnail: Jpeg(request.Thumbnail, request.House),
                Exterior: Jpeg(request.Exterior, request.House),
                Floor1: Jpeg(request.Floor1, request.House),
                Floor2: request.Floor2 is { } floor2 ? Jpeg(floor2, request.House) : null);
        }

        return result;
    }

    private void OpenCredits()
    {
        try
        {
            Ui.Credits = new OriginalCreditsOverlay(Content, Ui.Font, Ui.Device, Strings);
        }
        catch (Exception error)
        {
            ShowNeighborhoodError(error);
            return;
        }

        if (Bridge is null || _daemonMode)
        {
            PlayFrontendMusic(OriginalCreditsOverlay.MusicForNeighborhoodMode(Ui.Neighborhood?.Mode ?? 1));
        }
    }

    public void ConfirmQuit()
    {
        if (Ui.GameDialog is not null)
        {
            return;
        }

        if (Ui.Credits is not null)
        {
            CloseCredits();
            return;
        }

        var weakSelf = new WeakReference<LiveController>(this);
        if (HasActiveLot && Ui.ShowsLot && !LotSaveDisabled)
        {
            PresentLocalConfirmation(
                Strings.QuitSaveTitle(),
                Strings.SaveBeforeQuitMessage(),
                Strings.YesButton(),
                Strings.NoButton(),
                Strings.CancelButton(),
                response: code =>
                {
                    if (!weakSelf.TryGetTarget(out var self))
                    {
                        return;
                    }

                    switch (code)
                    {
                        case 0:
                            self.SendSaveRequest(succeeded =>
                            {
                                if (succeeded && weakSelf.TryGetTarget(out var target))
                                {
                                    target.QuitRequested = true;
                                }
                            });
                            break;
                        case 1:
                            self.QuitRequested = true;
                            break;
                    }
                });
        }
        else
        {
            PresentLocalConfirmation(
                Strings.QuitTitle(),
                Strings.QuitMessage(),
                Strings.YesButton(),
                Strings.NoButton(),
                response: code =>
                {
                    if (code == 0 && weakSelf.TryGetTarget(out var self))
                    {
                        self.QuitRequested = true;
                    }
                });
        }
    }

    private void CloseCredits()
    {
        Ui.Credits = null;
        if ((Bridge is null || _daemonMode) && Ui.Neighborhood?.Music is { Length: > 0 } music)
        {
            PlayFrontendMusic(music);
        }
    }

    private void OpenModsOverlay(string? safeModeNotice = null)
    {
        try
        {
            FamilyPlacement = null;
            _rezoneMode = false;
            _evictMode = false;
            Ui.Neighborhood?.SetRezoneMode(false);
            Ui.Neighborhood?.SetEvictMode(false);
            Ui.Neighborhood?.UpdateBannerHover(new CGPoint(-1000, -1000), _canvas, quickTips: false, uiScale: Renderer.UIScale);

            string dataRoot = Options.DataRoot ?? Workspace;
            string gameRoot = Options.Game ?? Content.Root;
            Ui.ModsOverlay = new OriginalModsOverlay(
                content: Content,
                device: Ui.Device,
                gameRoot: gameRoot,
                workspace: Workspace,
                dataRoot: dataRoot,
                cliPacks: Options.Packs,
                safeModeNotice: safeModeNotice);
        }
        catch (Exception error)
        {
            ShowNeighborhoodError(error);
        }
    }

    public void FileDropped(string path)
    {
        if (Ui.ModsOverlay is not null)
        {
            Ui.ModsOverlay.HandleDroppedFile(path);
            PlayUISound("ui_click");
        }
    }

    private void HandleModsOverlay(OriginalModsOverlay.Action action)
    {
        PlayUISound("ui_click");
        switch (action)
        {
            case OriginalModsOverlay.Action.Cancel:
                Ui.ModsOverlay = null;
                break;

            case OriginalModsOverlay.Action.OpenModsFolder:
                break;

            case OriginalModsOverlay.Action.ApplyAndReload(var settings, var hasChanges):
                ReloadWithUpdatedMods(settings, hasChanges);
                break;
        }
    }

    private void ReloadWithUpdatedMods(ModManager.ModSettingsFile settings, bool hasChanges)
    {
        string dataRoot = Options.DataRoot ?? Workspace;
        string gameRoot = Options.Game ?? Content.Root;
        try
        {
            ModManager.SaveSettings(dataRoot, settings);
        }
        catch (Exception error)
        {
            ShowNeighborhoodError(error);
            return;
        }

        Ui.ModsOverlay = null;
        if (!hasChanges)
        {
            return;
        }

        GameContent nextContent;
        try
        {
            nextContent = ModManager.LoadConfiguredContent(gameRoot, Workspace, dataRoot, Options.Packs);
        }
        catch (Exception error)
        {
            ShowNeighborhoodError(error);
            return;
        }

        _neighborhoodLoadGeneration++;
        _safeModeBootError = null;
        StopFrontendAudio();
        _audio?.Close();
        _audio = null;

        if (Bridge is { } oldBridge)
        {
            Bridge = null;
            _bridgeConnected = false;
            _daemonWarmedUp = false;
            oldBridge.Stop(save: false);
            _ = Task.Run(() => oldBridge.WaitForExit(5));
        }

        Content = nextContent;
        Ui = new LiveUI(Content);
        LoadPlayOptions();
        ResolvePluginTrust(dataRoot, allowInteractivePrompt: !Options.AnswerDialogs);

        if (UsesNativeEngine)
        {
            _daemonMode = true;
            StartWarmDaemon();
        }
        else
        {
            LoadBaseNeighborhood(mode: 1);
        }
    }

    private void OpenFamilyPicker(int house, IReadOnlyList<OriginalFamilyPickerOverlay.Family> families)
    {
        try
        {
            Ui.FamilyPicker = new OriginalFamilyPickerOverlay(
                house: house,
                families: families,
                content: Content,
                font: Ui.Font,
                device: Ui.Device,
                strings: Strings,
                isMagicTown: Ui.Neighborhood?.Mode == 7,
                quickTips: Ui.OptionsPanel.PlayOptions.QuickTips);
        }
        catch (Exception error)
        {
            ShowNeighborhoodError(error);
            return;
        }

        if (Bridge is null || _daemonMode)
        {
            PlayFrontendMusic("bkground_family");
        }
    }

    private void CloseFamilyPicker(bool returnsToMap = true)
    {
        Ui.FamilyPicker = null;
        if (returnsToMap && (Bridge is null || _daemonMode) && Ui.Neighborhood?.Music is { Length: > 0 } music)
        {
            PlayFrontendMusic(music);
        }
    }
}
