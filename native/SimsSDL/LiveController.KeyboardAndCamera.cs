using System.Collections.Concurrent;
using System.Diagnostics;

namespace SimsSDL;

internal sealed partial class LiveController
{
    private void CentreRelationshipIfPending()
    {
        if (_relationshipCenter is not { } position)
        {
            return;
        }

        if (position.Level != EffectiveViewLevel
            && position.Level >= 1
            && position.Level <= Renderer.StoryCount)
        {
            _pendingViewLevel = position.Level;
            _pendingRoofsVisible = false;
            _pendingViewSceneRevision = null;
            _pendingViewRequestID = Send(
                "level",
                new Dictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["value"] = position.Level,
                    ["roofs"] = false,
                });
            return;
        }

        if (position.Level != Renderer.ViewLevel)
        {
            return;
        }

        if (_relationshipCenterChangesLevel)
        {
            if (Renderer.CentreGroundTile((int)position.X, (int)position.Y, SimdCanvas) is null)
            {
                return;
            }

            _relationshipCenter = null;
            if (EffectiveRoofsVisible)
            {
                _pendingRoofsVisible = false;
                _pendingViewSceneRevision = null;
                _pendingViewRequestID = Send(
                    "roofs",
                    new Dictionary<string, object?>(StringComparer.Ordinal) { ["visible"] = false });
            }

            return;
        }

        if (Renderer.SceneViewport(SimdCanvas) is not { } viewport
            || Renderer.ScreenPoint(position.X, position.Y, SimdCanvas) is not { } point)
        {
            return;
        }

        _relationshipCenter = null;
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

    public bool RightScrollActive => _rightScrolling;
    public bool RightButtonHeld => _rightOrigin is not null;

    private Vector2? RightScrollVelocity =>
        _rightScrolling && _rightOrigin is { } origin && _rightCurrent is { } current
            ? new Vector2((float)(origin.X - current.X), (float)(origin.Y - current.Y)) * 5f
            : (Vector2?)null;

    public string RightScrollCursor
    {
        get
        {
            if (RightScrollVelocity is not { } velocity)
            {
                return "Pan";
            }

            float x = velocity.X;
            float y = velocity.Y;
            float limit = (float)Math.Tan(15.0 * Math.PI / 180.0);
            if (MathF.Sqrt(x * x + y * y) < 100f)
            {
                return "Pan";
            }

            if (MathF.Abs(y / x) < limit || (x == 0f && y == 0f))
            {
                return x < 0f ? "RIGHT" : "LEFT";
            }

            if (MathF.Abs(x / y) < limit)
            {
                return y < 0f ? "DOWN" : "UP";
            }

            return x < 0f
                ? (y < 0f ? "DOWNRIGHT" : "UPRIGHT")
                : (y < 0f ? "DOWNLEFT" : "UPLEFT");
        }
    }

    public void Wheel(float notches)
    {
        if (Ui.HelpVisible)
        {
            Ui.HelpOverlay.Scroll(notches > 0f ? -3 : notches < 0f ? 3 : 0);
            return;
        }

        if (!HasBlockingDialog && Ui.ModsOverlay is { } modsWheelOverlay)
        {
            modsWheelOverlay.ScrollWheel(notches);
            return;
        }

        if (!HasBlockingDialog && Ui.FamilyPicker is { } familyPicker)
        {
            familyPicker.Scroll(notches > 0f ? -1 : notches < 0f ? 1 : 0);
            return;
        }

        if (!HasBlockingDialog && Ui.GenericSimsCallPicker is { } callPicker)
        {
            callPicker.Scroll(notches > 0f ? -1 : notches < 0f ? 1 : 0, LogicalCanvas);
            return;
        }

        if (Ui.GameDialog is { } dialog
            && (dialog.Dialog.Blocking || dialog.Contains(Pointer ?? CGPoint.Zero, OverlayScale)))
        {
            if (Ui.ShowsLot)
            {
                DismissTransientMenu();
            }

            if (dialog.Dialog.Kind == 10)
            {
                dialog.ScrollPhoneBook(-notches * 20f, Pointer ?? CGPoint.Zero, OverlayScale);
            }
            else
            {
                dialog.ScrollMessage(-notches * 20f);
            }

            return;
        }

        if (!Ui.ShowsLot)
        {
            return;
        }

        DismissTransientMenu();
        int steps = notches > 0f ? 1 : notches < 0f ? -1 : 0;
        Renderer.SetZoom(Renderer.Zoom.Stepped(steps));
    }

    private bool WallpaperToolActive =>
        BuildToolsReady
        && Ui.Build.TerrainMode is null
        && Ui.Build.Kind == BuildCatalogPage.CatalogKind.Wall;

    private (int X, int Y)? ResolveCutawayTile(CGPoint point)
    {
        if (WallpaperToolActive
            && Renderer.WallAt(Simd(point), SimdCanvas) is { EdgeBit: not null } wall)
        {
            return (wall.X, wall.Y);
        }

        return Renderer.GroundTileAt(Simd(point), SimdCanvas) is { } tile
            ? (tile.X, tile.Y)
            : null;
    }

    private string CutawayKey((int X, int Y) tile, bool wallpaperTool, int? viewLevel = null, int? zoom = null) =>
        $"{viewLevel ?? Renderer.ViewLevel}:{zoom ?? (int)Renderer.Zoom.AssetZoom()}:{tile.X}:{tile.Y}:{(wallpaperTool ? 1 : 0)}";

    private void UpdateCutaway(CGPoint point)
    {
        if (!string.Equals(Ui.WallMode, "cutaway", StringComparison.Ordinal))
        {
            _lastCutawayTile = null;
            _desiredCutaway = null;
            return;
        }

        if (HasBlockingDialog || Ui.PieMenu is not null)
        {
            ClearCutawayTracking();
            return;
        }

        bool wallpaperTool = WallpaperToolActive;
        if (_rightOrigin is not null
            || Renderer.IsZoomInterpolating
            || (wallpaperTool && OverPanelControls(point))
            || (Ui.OptionsPanel.PlayOptions.EdgeScrolling && Ui.ShowsLot && EdgeScrollRegion(point) is not null))
        {
            return;
        }

        if (ResolveCutawayTile(point) is not { } tile)
        {
            ClearCutawayTracking();
            return;
        }

        int cutawayZoom = (int)Renderer.Zoom.AssetZoom();
        string key = CutawayKey(tile, wallpaperTool, zoom: cutawayZoom);
        if (string.Equals(_lastCutawayTile, key, StringComparison.Ordinal))
        {
            _desiredCutaway = null;
            return;
        }

        if (_lastCutawayTile is null)
        {
            _desiredCutaway = null;
            if (Send(
                "cutaway",
                new Dictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["x"] = tile.X,
                    ["y"] = tile.Y,
                    ["zoom"] = cutawayZoom,
                    ["wallpaperTool"] = wallpaperTool,
                }) is not null)
            {
                _lastCutawayTile = key;
            }
        }
        else
        {
            _desiredCutaway = (key, tile.X, tile.Y, cutawayZoom, wallpaperTool, CurrentUptime() * 1000.0);
        }
    }

    public void OnSmoothZoomSettled()
    {
        if (Pointer is { } pointer && string.Equals(Ui.WallMode, "cutaway", StringComparison.Ordinal))
        {
            UpdateCutaway(pointer);
        }
    }

    private void ClearCutawayTracking()
    {
        _desiredCutaway = null;
        if (_lastCutawayTile is not null)
        {
            _ = Send(
                "cutaway",
                new Dictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["x"] = -1,
                    ["y"] = -1,
                });
        }

        _lastCutawayTile = null;
    }

    public abstract record Key
    {
        public sealed record Escape : Key;
        public sealed record Enter : Key;
        public sealed record Backspace : Key;
        public sealed record Left : Key;
        public sealed record Right : Key;
        public sealed record Up : Key;
        public sealed record Down : Key;
        public sealed record PageUp : Key;
        public sealed record PageDown : Key;
        public sealed record Home : Key;
        public sealed record End : Key;
        public sealed record Delete : Key;
        public sealed record Tab : Key;
        public sealed record Function(int Value) : Key;
        public sealed record Character(string Value) : Key;
    }

    public bool HandleKeyDown(Key key)
    {
        if (Ui.BudgetReportVisible)
        {
            if (key is Key.Escape or Key.Enter)
            {
                PlayUISound("ui_click");
                Ui.BudgetReportVisible = false;
                Ui.BudgetReport.ClearHover();
            }

            return true;
        }

        if (Ui.HelpVisible)
        {
            switch (key)
            {
                case Key.Escape or Key.Enter:
                    SetHelpVisible(false);
                    break;
                case Key.Up:
                    Ui.HelpOverlay.MoveSelection(-1);
                    break;
                case Key.Down:
                    Ui.HelpOverlay.MoveSelection(1);
                    break;
                case Key.PageUp:
                    Ui.HelpOverlay.MovePage(-1);
                    break;
                case Key.PageDown:
                    Ui.HelpOverlay.MovePage(1);
                    break;
                case Key.Home:
                    Ui.HelpOverlay.SelectFirst();
                    break;
                case Key.End:
                    Ui.HelpOverlay.SelectLast();
                    break;
            }

            return true;
        }

        if (DialogKey(key))
        {
            return true;
        }

        if (key is Key.Character { Value: "c" } && IsCheatShortcutHeld())
        {
            ToggleCheatConsole();
            return true;
        }

        if (Ui.CheatConsole.Visible)
        {
            return HandleCheatConsoleKeyDown(key);
        }

        if (Ui.Album.Visible)
        {
            if (Ui.Album.EditingCaption)
            {
                switch (key)
                {
                    case Key.Escape or Key.Enter:
                        _ = Ui.Album.ClickCaption(CGPoint.Zero, LogicalCanvas);
                        break;
                    case Key.Backspace:
                        try
                        {
                            Ui.Album.UpdateCaption(DropLastCharacter(Ui.Album.CurrentCaption));
                        }
                        catch
                        {
                        }
                        break;
                }

                return true;
            }

            switch (key)
            {
                case Key.Escape or Key.Enter:
                    AlbumAction(OriginalPhotoAlbumOverlay.Action.Done);
                    break;
                case Key.Left:
                    AlbumAction(OriginalPhotoAlbumOverlay.Action.Previous);
                    break;
                case Key.Right:
                    AlbumAction(OriginalPhotoAlbumOverlay.Action.Next);
                    break;
                case Key.Home:
                    AlbumAction(OriginalPhotoAlbumOverlay.Action.First);
                    break;
                case Key.End:
                    AlbumAction(OriginalPhotoAlbumOverlay.Action.Last);
                    break;
                case Key.Delete or Key.Backspace:
                    AlbumAction(OriginalPhotoAlbumOverlay.Action.Delete);
                    break;
            }

            return true;
        }

        if (Ui.Camera.Visible)
        {
            if (key is Key.Escape)
            {
                LeaveCameraMode();
                return true;
            }

            if (DeleteModifier || ScriptDeleteModifier)
            {
                switch (key)
                {
                    case Key.Left:
                        Ui.Camera.ResizeCustomFrame(-1, 0);
                        return true;
                    case Key.Right:
                        Ui.Camera.ResizeCustomFrame(1, 0);
                        return true;
                    case Key.Up:
                        Ui.Camera.ResizeCustomFrame(0, -1);
                        return true;
                    case Key.Down:
                        Ui.Camera.ResizeCustomFrame(0, 1);
                        return true;
                }
            }
        }

        if (Ui.GenericSimsCallPicker is { } picker)
        {
            switch (key)
            {
                case Key.Escape:
                    break;
                case Key.Up:
                    picker.MoveSelection(-1);
                    break;
                case Key.Down:
                    picker.MoveSelection(1);
                    break;
                case Key.Enter:
                    if (picker.SelectedPersonRecordIndex is { } row)
                    {
                        ChooseGenericSimsCallPerson(row);
                    }
                    break;
            }

            return true;
        }

        if (ScreenKey(key) is { } screen)
        {
            return screen;
        }

        if (Ui.PluginPanel is not null && !Ui.SoundOptions.IsVisible)
        {
            switch (key)
            {
                case Key.Escape or Key.Enter:
                    Ui.PluginPanel = null;
                    PlayUISound("ui_click");
                    break;
            }

            return true;
        }

        switch (key)
        {
            case Key.Escape:
            {
                bool hasMenuOrSelection = Ui.PieMenu is not null
                    || Ui.Buy.Selection.Target is not null
                    || Ui.Build.Selected is not null
                    || Ui.Build.SelectedObjectGUID is not null;
                if (!hasMenuOrSelection && _pictureInPicture is not null)
                {
                    ClosePictureInPicture();
                }
                else
                {
                    DismissMenu();
                }
                break;
            }

            case Key.Enter:
                if (HasBlockingDialog || !Ui.ShowsLot || Ui.BuyMode || Ui.BuildMode || Ui.OptionsMode || Ui.Camera.Visible || _selectedSim == 0)
                {
                    break;
                }

                _centresOnSelectedSim = true;
                CentreOnSelectedSimIfPending();
                break;

            case Key.Left when (SDL_GetModState() & SDL_KMOD_SHIFT) != 0:
                if (HasBlockingDialog || Ui.Album.Visible || !Ui.ShowsLot)
                {
                    return false;
                }

                RotateCamera(-1);
                break;

            case Key.Right when (SDL_GetModState() & SDL_KMOD_SHIFT) != 0:
                if (HasBlockingDialog || Ui.Album.Visible || !Ui.ShowsLot)
                {
                    return false;
                }

                RotateCamera(1);
                break;

            case Key.Character { Value: "`" or "~" or "0" }:
                SendSpeed(0);
                break;

            case Key.Character { Value: "p" }:
            {
                bool paused = IsInLiveMode ? Renderer.Speed == 0 : _liveModePaused;
                SendSpeed(paused ? _lastRunningSpeed : 0);
                break;
            }

            case Key.Character { Value: " " }:
                NextSim();
                break;

            case Key.Character { Value: "1" }:
                SendSpeed(1);
                break;

            case Key.Character { Value: "2" }:
                SendSpeed(3);
                break;

            case Key.Character { Value: "3" }:
                SendSpeed(10);
                break;

            case Key.Character { Value: "z" or "x" } ch:
            {
                if (HasBlockingDialog)
                {
                    break;
                }

                bool next = string.Equals(ch.Value, "x", StringComparison.Ordinal);
                if (Ui.BuyMode && Ui.Buy.Page is { } buyPage)
                {
                    int capacity = OriginalBuyLayout.Capacity(LogicalCanvas, Ui.Buy.PluginViews.Count);
                    int? offset = next
                        ? buyPage.NextOffset(capacity)
                        : (buyPage.Offset > 0 ? Math.Max(0, buyPage.Offset - capacity) : (int?)null);
                    if (offset is { } nextBuyOffset)
                    {
                        PlayUISound("ui_click");
                        if (Ui.Buy.ActivePluginView is { } activePv && Ui.Buy.ActivePluginCollectionId is { } activeColId)
                        {
                            RequestPluginCatalog(activePv.PackId, activePv.TabId, activeColId, nextBuyOffset);
                        }
                        else
                        {
                            RequestCatalog(
                                category: Ui.Buy.Category,
                                room: Ui.Buy.RoomMode ? Ui.Buy.Room : (int?)null,
                                subsort: Ui.Buy.FunctionSubSorting ? Ui.Buy.FunctionSubsort : (int?)null,
                                offset: nextBuyOffset);
                        }
                    }
                }
                else if (Ui.BuildMode && Ui.Build.TerrainMode is null)
                {
                    int capacity = Ui.Build.VisibleCapacity(LogicalCanvas);
                    int? offset;
                    if (Ui.Build.ObjectPage is { } objectPage)
                    {
                        offset = next
                            ? objectPage.NextOffset(capacity)
                            : (objectPage.Offset > 0 ? Math.Max(0, objectPage.Offset - capacity) : (int?)null);
                    }
                    else if (Ui.Build.Page is { } buildPage)
                    {
                        offset = next
                            ? buildPage.NextOffset(capacity)
                            : (buildPage.Offset > 0 ? Math.Max(0, buildPage.Offset - capacity) : (int?)null);
                    }
                    else
                    {
                        offset = null;
                    }

                    if (offset is { } nextBuildOffset)
                    {
                        PlayUISound("ui_click");
                        RequestBuildCatalog(offset: nextBuildOffset);
                    }
                }
                break;
            }

            case Key.Tab:
                if (Ui.PieMenu is { } menu)
                {
                    bool advanced;
                    try
                    {
                        advanced = menu.NextPage();
                    }
                    catch
                    {
                        advanced = false;
                    }

                    if (advanced)
                    {
                        menu.Prepare(_canvas, Scale);
                        if (Pointer is { } pointer)
                        {
                            menu.Hover(pointer, Scale);
                        }

                        if (menu.Highlighted is { } highlighted && highlighted != _lastPieHighlight)
                        {
                            PlayUISound("ui_piemenu_highlight");
                        }

                        _lastPieHighlight = menu.Highlighted;
                        RequestPieHeadPreview();
                    }
                }
                else
                {
                    NextSim();
                }
                break;

            case Key.Character { Value: "w" }:
                ToggleWalls();
                break;

            case Key.PageUp:
                SelectStory(EffectiveViewLevel + 1);
                break;

            case Key.PageDown:
                SelectStory(EffectiveViewLevel - 1);
                break;

            case Key.Character { Value: "b" }:
                BrowseBuyCatalog();
                break;

            case Key.Character { Value: "f" }:
                BrowseBuildCatalog();
                break;

            case Key.Character { Value: "r" }:
                if (!Ui.ObjectEditing
                    || Ui.Buy.Selection.Target is not { } rotateTarget
                    || (rotateTarget.IsPlaced && rotateTarget.PlacedObject?.Movable == false)
                    || HasBlockingDialog)
                {
                    break;
                }

                Ui.Buy.Rotate();
                _snappedPlacementDirection = null;
                PlayUISound("ui_object_rotate");
                if (Pointer is { } rotatePointer)
                {
                    UpdatePlacement(rotatePointer);
                }
                break;

            case Key.Character { Value: "," or "<" or "." or ">" } mark:
            {
                int steps = mark.Value is "," or "<" ? -1 : 1;
                if (!Ui.ObjectEditing || Ui.Buy.Selection.Target is not { } stepRotateTarget || HasBlockingDialog)
                {
                    RotateCamera(steps);
                    break;
                }

                if (stepRotateTarget.IsPlaced && stepRotateTarget.PlacedObject?.Movable == false)
                {
                    break;
                }

                Ui.Buy.Rotate(steps);
                _snappedPlacementDirection = null;
                PlayUISound("ui_object_rotate");
                if (Pointer is { } stepRotatePointer)
                {
                    UpdatePlacement(stepRotatePointer);
                }
                break;
            }

            case Key.Character { Value: "[" }:
                RotateCamera(-1);
                break;

            case Key.Character { Value: "]" }:
                RotateCamera(1);
                break;

            case Key.Character { Value: "=" or "+" }:
                UniversalControl(OriginalUniversalControl.Action.ZoomIn);
                break;

            case Key.Character { Value: "-" }:
                UniversalControl(OriginalUniversalControl.Action.ZoomOut);
                break;

            case Key.Home:
                StepWallView(1);
                break;

            case Key.End:
                StepWallView(-1);
                break;

            case Key.Function { Value: 1 }:
                UniversalControl(OriginalUniversalControl.Action.Live);
                break;

            case Key.Function { Value: 2 }:
                UniversalControl(OriginalUniversalControl.Action.Buy);
                break;

            case Key.Function { Value: 3 }:
                UniversalControl(OriginalUniversalControl.Action.Build);
                break;

            case Key.Function { Value: 4 }:
                EnterCameraMode();
                break;

            case Key.Function { Value: 5 }:
                UniversalControl(OriginalUniversalControl.Action.Options);
                break;

            case Key.Character { Value: "s" }:
                SaveGame();
                break;

            case Key.Character { Value: "l" }:
                LoadGame();
                break;

            case Key.Delete or Key.Backspace:
                DeleteOrCancelHeldObject();
                break;

            case Key.Character pluginKey when Ui.BuyMode && !HasBlockingDialog && Ui.Buy.PluginViews.Count > 0:
            {
                var matchedView = Ui.Buy.PluginViews.FirstOrDefault(v =>
                    !string.IsNullOrWhiteSpace(v.Hotkey)
                    && string.Equals(v.Hotkey, pluginKey.Value, StringComparison.OrdinalIgnoreCase));
                if (matchedView is null)
                {
                    return false;
                }

                PlayUISound("ui_click");
                if (Ui.Buy.ActivePluginView is { } cur
                    && string.Equals(cur.PackId, matchedView.PackId, StringComparison.Ordinal)
                    && string.Equals(cur.TabId, matchedView.TabId, StringComparison.Ordinal))
                {
                    Ui.Buy.ExitPluginView();
                    Ui.Buy.ClearCategory(0);
                    RequestCatalog(category: 0, offset: 0);
                }
                else if (Ui.Buy.EnterPluginView(matchedView.PackId, matchedView.TabId)
                    && Ui.Buy.ActivePluginCollectionId is { } firstColId)
                {
                    RequestPluginCatalog(matchedView.PackId, matchedView.TabId, firstColId, offset: 0);
                }
                break;
            }

            default:
                return false;
        }

        return true;
    }

    private static GameDialog.Button? FirstButtonWithCode(IReadOnlyList<GameDialog.Button> buttons, byte code)
    {
        for (int i = 0; i < buttons.Count; i++)
        {
            if (buttons[i].Code == code)
            {
                return buttons[i];
            }
        }

        return null;
    }

    private static string DropLastCharacter(string text)
    {
        if (string.IsNullOrEmpty(text))
        {
            return string.Empty;
        }

        int[] starts = StringInfo.ParseCombiningCharacters(text);
        return starts.Length <= 1 ? string.Empty : text[..starts[^1]];
    }

    private bool DialogKey(Key key)
    {
        if (Ui.GameDialog is not { } dialog || dialog.Submitting)
        {
            return false;
        }

        if (dialog.TutorialCloseBox is not null && dialog.Dialog.Buttons.Count == 0)
        {
            switch (key)
            {
                case Key.Enter or Key.Escape or Key.Character { Value: " " }:
                    RespondDialog(dialog, code: 0);
                    return true;
                default:
                    return dialog.Dialog.Blocking;
            }
        }

        if (string.Equals(_localDialogToken, dialog.Dialog.Token, StringComparison.Ordinal))
        {
            if (dialog.Dialog.IsBookScreen)
            {
                switch (key)
                {
                    case Key.Enter:
                        RespondDialog(dialog, code: 0);
                        break;
                    case Key.Escape:
                        RespondDialog(dialog, code: 0);
                        break;
                    case Key.Up:
                        dialog.MoveBookSelection(-1);
                        break;
                    case Key.Down:
                        dialog.MoveBookSelection(1);
                        break;
                    case Key.Left:
                        dialog.MoveBookPage(-1);
                        break;
                    case Key.Right:
                        dialog.MoveBookPage(1);
                        break;
                }
            }
            else if (key is Key.Enter && FirstButtonWithCode(dialog.Dialog.Buttons, 0) is { } firstZero)
            {
                RespondDialog(dialog, code: firstZero.Code);
            }
            else if (key is Key.Character { Value: " " }
                     && dialog.Dialog.Buttons.Count == 1
                     && dialog.Dialog.Kind != 3
                     && !dialog.Dialog.IsBookScreen)
            {
                RespondDialog(dialog, code: dialog.Dialog.Buttons[0].Code);
            }
            else if (key is Key.Escape
                     && (FirstButtonWithCode(dialog.Dialog.Buttons, 2)
                         ?? FirstButtonWithCode(dialog.Dialog.Buttons, 1)
                         ?? FirstButtonWithCode(dialog.Dialog.Buttons, 0)) is { } dismiss)
            {
                RespondDialog(dialog, code: dismiss.Code);
            }

            return true;
        }

        if (!dialog.Dialog.Blocking)
        {
            switch (key)
            {
                case Key.Enter:
                    if (dialog.Dialog.Buttons.Count > 0)
                    {
                        RespondDialog(dialog, code: dialog.Dialog.Buttons[0].Code);
                    }
                    return true;

                case Key.Character { Value: " " }
                    when dialog.Dialog.Buttons.Count == 1 && dialog.Dialog.Kind != 3 && !dialog.Dialog.IsBookScreen:
                    RespondDialog(dialog, code: dialog.Dialog.Buttons[0].Code);
                    return true;

                case Key.Escape:
                    if ((FirstButtonWithCode(dialog.Dialog.Buttons, 2)
                         ?? FirstButtonWithCode(dialog.Dialog.Buttons, 1)
                         ?? FirstButtonWithCode(dialog.Dialog.Buttons, 0)) is { } dismiss)
                    {
                        RespondDialog(dialog, code: dismiss.Code);
                    }
                    return true;

                case Key.Backspace when dialog.AcceptsTextInput:
                    try
                    {
                        dialog.UpdateText(DropLastCharacter(dialog.Text));
                    }
                    catch (Exception error)
                    {
                        Log($"Game dialog: {error}");
                    }
                    return true;

                default:
                    return false;
            }
        }

        try
        {
            if (dialog.Dialog.Kind == 10)
            {
                switch (key)
                {
                    case Key.Enter:
                        if (dialog.SelectedPhoneBookContact() is { } neighbor)
                        {
                            RespondDialog(dialog, code: 1, responseText: neighbor.ToString(CultureInfo.InvariantCulture));
                        }
                        break;
                    case Key.Escape:
                        RespondDialog(dialog, code: 0, responseText: "-1");
                        break;
                    case Key.Up:
                        dialog.MovePhoneBookSelection(-1);
                        break;
                    case Key.Down:
                        dialog.MovePhoneBookSelection(1);
                        break;
                    case Key.Left:
                        dialog.MovePhoneBookFamily(-1);
                        break;
                    case Key.Right:
                        dialog.MovePhoneBookFamily(1);
                        break;
                }

                return true;
            }

            switch (key)
            {
                case Key.Enter:
                    if (dialog.Dialog.Buttons.Count > 0)
                    {
                        RespondDialog(dialog, code: dialog.Dialog.Buttons[0].Code);
                    }
                    break;

                case Key.Character { Value: " " }
                    when dialog.Dialog.Buttons.Count == 1 && dialog.Dialog.Kind != 3 && !dialog.Dialog.IsBookScreen:
                    RespondDialog(dialog, code: dialog.Dialog.Buttons[0].Code);
                    break;

                case Key.Escape when dialog.Dialog.IsBookScreen:
                    RespondDialog(dialog, code: 0);
                    break;
                case Key.Up when dialog.Dialog.IsBookScreen:
                    dialog.MoveBookSelection(-1);
                    break;
                case Key.Down when dialog.Dialog.IsBookScreen:
                    dialog.MoveBookSelection(1);
                    break;
                case Key.Left when dialog.Dialog.IsBookScreen:
                    dialog.MoveBookPage(-1);
                    break;
                case Key.Right when dialog.Dialog.IsBookScreen:
                    dialog.MoveBookPage(1);
                    break;

                case Key.Escape:
                    if ((FirstButtonWithCode(dialog.Dialog.Buttons, 2)
                         ?? FirstButtonWithCode(dialog.Dialog.Buttons, 1)
                         ?? FirstButtonWithCode(dialog.Dialog.Buttons, 0)) is { } dismiss)
                    {
                        RespondDialog(dialog, code: dismiss.Code);
                    }
                    break;

                case Key.Backspace when dialog.Dialog.Kind == 3 && !dialog.Submitting:
                    dialog.UpdateText(DropLastCharacter(dialog.Text));
                    break;
            }
        }
        catch (Exception error)
        {
            Log($"Game dialog: {error}");
        }

        return true;
    }

    public void Text(string text)
    {
        if (Ui.Album.Visible && Ui.Album.EditingCaption)
        {
            try
            {
                Ui.Album.UpdateCaption(Ui.Album.CurrentCaption + text);
            }
            catch
            {
            }

            return;
        }

        if (Ui.GameDialog is null && Ui.CheatConsole.Visible)
        {
            Ui.CheatConsole.TextInput(text);
            return;
        }

        if (Ui.GameDialog is null && Ui.ModsOverlay is { EditingOrderNumber: true } modsTextOverlay)
        {
            modsTextOverlay.TextInput(text);
            return;
        }

        if (Ui.GameDialog is null && Ui.HouseholdCreation is { } creation)
        {
            var weakSelf = new WeakReference<LiveController>(this);
            var enumerator = StringInfo.GetTextElementEnumerator(text);
            while (enumerator.MoveNext())
            {
                string character = (string)enumerator.Current;
                _ = creation.Key(character, () =>
                {
                    if (weakSelf.TryGetTarget(out var self))
                    {
                        self.ConfirmCancelHouseholdCreation();
                    }
                });
            }

            return;
        }

        if (Ui.GameDialog is not { } dialog
            || !dialog.AcceptsTextInput
            || string.Equals(_localDialogToken, dialog.Dialog.Token, StringComparison.Ordinal))
        {
            return;
        }

        try
        {
            dialog.UpdateText(dialog.Text + text);
        }
        catch (Exception error)
        {
            Log($"Game dialog: {error}");
        }
    }

    public bool AcceptsText =>
        (Ui.Album.Visible && Ui.Album.EditingCaption)
        || (Ui.GameDialog is null && Ui.CheatConsole.Visible)
        || (Ui.ModsOverlay?.EditingOrderNumber == true)
        || Ui.HouseholdCreation is not null
        || (Ui.GameDialog?.AcceptsTextInput == true
            && !string.Equals(_localDialogToken, Ui.GameDialog?.Dialog.Token, StringComparison.Ordinal));

    private void ResolvePluginTrust(string dataRoot, bool allowInteractivePrompt)
    {
        ModManager.TrustBundledPlugins(Content, dataRoot);
        if (ModManager.ShouldAutoTrustDevPlugins(Workspace))
        {
            ModManager.TrustAllPlugins(Content, dataRoot);
        }
        else if (allowInteractivePrompt)
        {
            ReviewPluginTrust();
        }

        ReloadClientPlugins(dataRoot);
    }

    private void ReloadClientPlugins(string dataRoot)
    {
        Renderer.SetClientPlugins(null);
        _clientPlugins?.Dispose();
        _clientPlugins = new ClientPluginHost(
            Content,
            dataRoot,
            (packId, command, payload) => _ = Send(
                "pluginClientCommand",
                new Dictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["packId"] = packId,
                    ["command"] = command,
                    ["payload"] = payload,
                }));
        Renderer.SetClientPlugins(_clientPlugins);
    }

    private void ReviewPluginTrust()
    {
        string dataRoot = Options.DataRoot ?? Workspace;
        foreach (var (plugin, name) in PackTool.UntrustedPlugins(Content, dataRoot))
        {
            string title = $"Allow “{name}” to run code?";
            string message = $"The pack {plugin.PackID} {plugin.Version} includes a gameplay plugin that runs with your user account's permissions. "
                + $"Only allow packs from authors you trust.\n\nFiles digest: {plugin.Sha256}";
            bool allowed = ShowPluginTrustMessageBox(title, message);
            if (!allowed)
            {
                Log($"plugin {plugin.PackID} left disabled");
                continue;
            }

            try
            {
                PackTool.Trust(plugin, dataRoot);
            }
            catch (Exception error)
            {
                Log($"Plugin trust: {error}");
            }
        }
    }

    private static unsafe bool ShowPluginTrustMessageBox(string title, string message)
    {
        nint titlePtr = Marshal.StringToCoTaskMemUTF8(title);
        nint messagePtr = Marshal.StringToCoTaskMemUTF8(message);
        nint keepPtr = Marshal.StringToCoTaskMemUTF8("Keep Disabled");
        nint allowPtr = Marshal.StringToCoTaskMemUTF8("Allow");
        try
        {
            var buttons = new SDL_MessageBoxButtonData[2];
            buttons[0] = new SDL_MessageBoxButtonData
            {
                flags = SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT | SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT,
                buttonID = 0,
                text = keepPtr,
            };
            buttons[1] = new SDL_MessageBoxButtonData
            {
                flags = 0,
                buttonID = 1,
                text = allowPtr,
            };

            fixed (SDL_MessageBoxButtonData* buttonsPtr = buttons)
            {
                var data = new SDL_MessageBoxData
                {
                    flags = SDL_MESSAGEBOX_WARNING,
                    window = nint.Zero,
                    title = titlePtr,
                    message = messagePtr,
                    numbuttons = buttons.Length,
                    buttons = (nint)buttonsPtr,
                    colorScheme = nint.Zero,
                };
                return SDL_ShowMessageBox(in data, out int choice) && choice == 1;
            }
        }
        finally
        {
            Marshal.FreeCoTaskMem(titlePtr);
            Marshal.FreeCoTaskMem(messagePtr);
            Marshal.FreeCoTaskMem(keepPtr);
            Marshal.FreeCoTaskMem(allowPtr);
        }
    }

    private List<(string PackID, PanelDescription Description)> PluginPanels =>
        Content.Packs.PanelDescriptions()
            .OrderBy(static pack => pack.Key, StringComparer.Ordinal)
            .SelectMany(static pack => pack.Value
                .OrderBy(static panel => panel.Key, StringComparer.Ordinal)
                .Select(panel => (pack.Key, panel.Value)))
            .ToList();

    private void OpenPluginPanel(string packID, PanelDescription description, int? anchorID = null)
    {
        try
        {
            var panel = new OriginalPluginPanelOverlay(
                packId: packID,
                description: description,
                content: Content,
                font: Ui.Font,
                device: Ui.Device,
                closeLabel: Strings.OkButton(),
                anchorId: anchorID);
            Dictionary<string, string>? values =
                _pluginPanelValues.TryGetValue(packID, out var packPanels)
                && packPanels.TryGetValue(description.Id, out var panelValues)
                    ? panelValues
                    : null;
            panel.Update(values ?? new Dictionary<string, string>(StringComparer.Ordinal));
            Ui.PluginPanel = panel;
            FollowPanelAnchor();
            _ = Send("pluginPanels");
        }
        catch (Exception error)
        {
            Log($"Plugin panel: {error}");
        }
    }

    private void FollowPanelAnchor()
    {
        if (Ui.PluginPanel is not { } panel || panel.AnchorId is not int id)
        {
            return;
        }

        if (!Renderer.ContainsObject(id))
        {
            Ui.PluginPanel = null;
            return;
        }

        panel.LotHeight = LogicalCanvas.Height - 150.0;
        if (Renderer.ScreenBounds(id, SimdCanvas) is not { } bounds)
        {
            return;
        }

        panel.Anchor = new CGRect(
            bounds.MinX / Scale,
            bounds.MinY / Scale,
            bounds.Width / Scale,
            bounds.Height / Scale);
    }

    private void ApplyPluginPanelValues(List<Dictionary<string, JsonElement>> panels)
    {
        var updated = new Dictionary<string, Dictionary<string, Dictionary<string, string>>>(StringComparer.Ordinal);
        foreach (var panel in panels)
        {
            if (panel.JsonString("packId") is not { } packID
                || panel.JsonString("panelId") is not { } panelID
                || panel.JsonDict("values") is not { } rawValues)
            {
                continue;
            }

            var values = new Dictionary<string, string>(rawValues.Count, StringComparer.Ordinal);
            bool allStrings = true;
            foreach (var (key, element) in rawValues)
            {
                if (element.ValueKind != JsonValueKind.String || element.GetString() is not { } stringValue)
                {
                    allStrings = false;
                    break;
                }

                values[key] = stringValue;
            }

            if (!allStrings)
            {
                continue;
            }

            if (!updated.TryGetValue(packID, out var packPanels))
            {
                packPanels = new Dictionary<string, Dictionary<string, string>>(StringComparer.Ordinal);
                updated[packID] = packPanels;
            }

            packPanels[panelID] = values;
        }

        _pluginPanelValues = updated;
        foreach (var (packId, packPanels) in updated)
        {
            foreach (var (panelId, values) in packPanels)
            {
                Ui.OptionsPanel.UpdatePluginPageValues(packId, panelId, values);
            }
        }
        if (Ui.PluginPanel is { } openPanel)
        {
            Dictionary<string, string>? values =
                updated.TryGetValue(openPanel.PackId, out var packPanels)
                && packPanels.TryGetValue(openPanel.Description.Id, out var panelValues)
                    ? panelValues
                    : null;
            openPanel.Update(values ?? new Dictionary<string, string>(StringComparer.Ordinal));
        }
    }

    private bool CanEditBuildObject(EditableLotObject obj)
    {
        if (!Ui.BuildMode)
        {
            return true;
        }

        if (Ui.Build.ObjectTool is { } tool)
        {
            return tool == OriginalBuildObjectTool.Hand || obj.CatalogCategory == tool.Category();
        }

        if (Ui.Build.TerrainMode is not null)
        {
            return false;
        }

        return Ui.Build.Kind switch
        {
            BuildCatalogPage.CatalogKind.WallStyle => obj.CatalogCategory == 13,
            BuildCatalogPage.CatalogKind.Water => obj.CatalogCategory == 14,
            _ => false,
        };
    }
}
