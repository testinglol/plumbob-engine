using System.Collections.Concurrent;
using System.Diagnostics;

namespace SimsSDL;

internal sealed partial class LiveController
{

    private void HandlePictureInPicture(IReadOnlyDictionary<string, JsonElement> evt)
    {
        int objectID = evt.JsonInt("objectId") ?? 0;
        var playOptions = Ui.OptionsPanel.PlayOptions;
        int sizeIndex = evt.JsonInt("size") ?? evt.JsonInt("byte2") ?? 0;
        int zoom = evt.JsonInt("zoom") ?? evt.JsonInt("byte3") ?? 0;
        string? text = evt.JsonString("text") is { Length: > 0 } rawText ? rawText : null;
        bool insideLotEdge = evt.JsonBool("insideLotEdge") ?? true;
        bool snapshotRequested = evt.JsonBool("snapshot") == true && playOptions.AutoSnapshot && insideLotEdge;
        if (evt.JsonBool("force") == true && objectID != 0)
        {
            bool snapshot = snapshotRequested;
            if (playOptions.AutoCenter)
            {
                CentreView(objectID);
            }
            else
            {
                PlayUISound("ui_error");
                snapshot = false;
            }

            if (snapshot && !Ui.Camera.Visible && PendingPhoto is null && EventRect(objectID) is { } rect)
            {
                PendingPhoto = rect;
                _pendingPhotoIsAutomatic = true;
                _pendingPhotoCaption = text;
            }
        }
        else if (evt.JsonBool("open") == true && objectID != 0)
        {
            OpenPictureInPicture(
                objectID,
                milliseconds: evt.JsonInt("durationMs") ?? 0,
                zoom: zoom,
                sizeIndex: sizeIndex,
                checkOffScreen: evt.JsonBool("checkOffScreen") ?? true,
                insideLotEdge: insideLotEdge,
                snapshot: snapshotRequested,
                text: text);
        }
        else if (objectID == 0 || _pictureInPicture?.ObjectID == objectID)
        {
            ClosePictureInPicture();
        }
    }

    private void OpenPictureInPicture(
        int objectID,
        int milliseconds,
        int zoom,
        int sizeIndex,
        bool checkOffScreen,
        bool insideLotEdge,
        bool snapshot,
        string? text)
    {
        if (_pictureInPicture is { } open && open.ObjectID != objectID)
        {
            return;
        }

        if (!insideLotEdge)
        {
            return;
        }

        if (checkOffScreen
            && (TargetPosition(objectID)?.Level ?? EffectiveViewLevel) == EffectiveViewLevel
            && Renderer.ScreenBounds(objectID, SimdCanvas) is { } bounds
            && Renderer.SceneViewport(SimdCanvas) is { } viewport)
        {
            double panelTop = Math.Max(0.0, viewport.Size.Y - (Ui.PanelMinimized ? 0.0 : 100.0 * Scale));
            if (viewport.Size.X > 0.0
                && panelTop > 0.0
                && !bounds.IsEmpty
                && bounds.MinX >= 0.0
                && bounds.MinY >= 0.0
                && bounds.MaxX <= viewport.Size.X
                && bounds.MaxY <= panelTop)
            {
                return;
            }
        }

        Ui.PictureInPictureLogicalSize = LiveUI.PictureInPictureSize(sizeIndex);
        Ui.PictureInPictureCaption = text;
        _pictureInPicture = new PictureInPictureWindow
        {
            ObjectID = objectID,
            Expires = milliseconds > 0 ? DateTime.UtcNow.AddSeconds(milliseconds / 1000.0) : null,
            SizeIndex = sizeIndex,
            Zoom = zoom,
            Text = text,
            SnapshotPending = snapshot,
            Built = false,
        };
    }

    private void ClosePictureInPicture()
    {
        _pictureInPicture = null;
        _pipNeedsCapture = false;
        _pipCloseTracking = false;
        Ui.PictureInPicture = null;
        Ui.PictureInPictureCaption = null;
        Ui.PictureInPictureCloseHovered = false;
        Ui.PictureInPictureClosePressed = false;
    }

    private void UpdatePictureInPictureCaptureState()
    {
        _pipNeedsCapture = false;
        if (_pictureInPicture is not { } window)
        {
            return;
        }

        if (window.Expires is { } expires && DateTime.UtcNow >= expires)
        {
            ClosePictureInPicture();
            return;
        }

        bool objectExists = _placedObjectMeta.ContainsKey(window.ObjectID)
            || _lotSims.ContainsKey(window.ObjectID)
            || Renderer.ContainsObject(window.ObjectID);
        if (!objectExists)
        {
            ClosePictureInPicture();
            return;
        }

        if (Renderer.Scene is null)
        {
            return;
        }

        if (!Ui.OptionsPanel.PlayOptions.LivePIP && window.Built)
        {
            return;
        }

        _pipNeedsCapture = true;
    }

    private void CapturePictureInPictureFrame()
    {
        if (_pictureInPicture is not { } window || Renderer.Scene is null)
        {
            return;
        }

        CGSize logicalSize = LiveUI.PictureInPictureSize(window.SizeIndex);
        int pipW = Math.Max(1, (int)Math.Round(logicalSize.Width * Scale, MidpointRounding.AwayFromZero));
        int pipH = Math.Max(1, (int)Math.Round(logicalSize.Height * Scale, MidpointRounding.AwayFromZero));
        var pipCanvas = new Vector2(pipW, pipH);
        LotZoom targetZoom = window.Zoom is >= (int)LotZoom.Far and <= (int)LotZoom.Near
            ? (LotZoom)window.Zoom
            : Renderer.Zoom;

        (LotZoom Zoom, float VisualFactor) savedZoomState = Renderer.SaveVisualZoom();
        Vector2 savedPan = Renderer.Pan;
        bool savedLiveMode = Renderer.LiveMode;
        bool savedSuppressInset = Renderer.SuppressControlPanelInset;
        List<UIDraw> savedOverlay = Renderer.Overlay;
        (int Index, Dictionary<int, Vector4> Rects)? savedPreviewPlacement = Renderer.PreviewPlacement;
        bool savedShowsPlacement = Renderer.ShowsPlacement;
        bool savedShowsGhost = Renderer.ShowsGhost;
        bool savedShowsBuildCursor = Renderer.ShowsBuildCursor;
        bool savedDrawsLot = Renderer.DrawsLot;
        int panBefore = Renderer.PanAssignments;

        byte[]? renderedPixels;
        try
        {
            Renderer.SnapVisualZoom(targetZoom);
            Renderer.Pan = Vector2.Zero;
            Renderer.LiveMode = savedLiveMode;
            Renderer.SuppressControlPanelInset = true;
            Renderer.Overlay = [];
            Renderer.PreviewPlacement = null;
            Renderer.ShowsPlacement = false;
            Renderer.ShowsGhost = false;
            Renderer.ShowsBuildCursor = false;
            Renderer.DrawsLot = true;

            if (Renderer.ScreenBounds(window.ObjectID, pipCanvas) is { } bounds)
            {
                Renderer.Pan += pipCanvas / 2f - new Vector2((float)bounds.MidX, (float)bounds.MidY);
            }
            else if (TargetPosition(window.ObjectID) is { } pos
                && Renderer.ScreenPoint(pos.X, pos.Y, pipCanvas) is { } point)
            {
                float lift = 8f * MathF.Sqrt(6f) * targetZoom.Factor() * Renderer.UIScale;
                Renderer.Pan += pipCanvas / 2f - (point - new Vector2(0f, lift));
            }

            if (_pipRenderTargets?.Color.Width != pipW || _pipRenderTargets?.Color.Height != pipH)
            {
                _pipRenderTargets?.Dispose();
                _pipRenderTargets = new RenderTargets(Renderer.GPU, pipW, pipH);
            }

            RenderTargets? targets = _pipRenderTargets;
            nint command = targets is not null ? SDL_AcquireGPUCommandBuffer(Renderer.GPU.Device) : nint.Zero;
            if (targets is null || command == nint.Zero)
            {
                return;
            }

            Renderer.Encode(command, targets.Color, targets.Depth);
            if (!SDL_SubmitGPUCommandBuffer(command))
            {
                return;
            }

            renderedPixels = Renderer.GPU.ReadPixels(targets.Color);
        }
        catch (Exception error)
        {
            Log($"Picture-in-picture: {error}");
            return;
        }
        finally
        {
            Renderer.RestoreVisualZoom(savedZoomState);
            Renderer.Pan = savedPan;
            Renderer.LiveMode = savedLiveMode;
            Renderer.SuppressControlPanelInset = savedSuppressInset;
            Renderer.Overlay = savedOverlay;
            Renderer.PreviewPlacement = savedPreviewPlacement;
            Renderer.ShowsPlacement = savedShowsPlacement;
            Renderer.ShowsGhost = savedShowsGhost;
            Renderer.ShowsBuildCursor = savedShowsBuildCursor;
            Renderer.DrawsLot = savedDrawsLot;
            unchecked
            {
                _pipPanAssignmentsBias += Renderer.PanAssignments - panBefore;
            }
        }

        if (renderedPixels is not { } pipPixels)
        {
            return;
        }

        Ui.PictureInPictureLogicalSize = logicalSize;
        Ui.PictureInPictureCaption = window.Text;
        Ui.PictureInPicture = new OriginalGameplayOverlay.Image(
            new UITexture(pipW, pipH, pipPixels),
            new CGSize(pipW, pipH));
        if (_pictureInPicture is not null)
        {
            _pictureInPicture.Built = true;
        }

        if (window.SnapshotPending)
        {
            if (_pictureInPicture is not null)
            {
                _pictureInPicture.SnapshotPending = false;
            }

            try
            {
                int snapW = Math.Max(1, (int)Math.Round(logicalSize.Width, MidpointRounding.AwayFromZero));
                int snapH = Math.Max(1, (int)Math.Round(logicalSize.Height, MidpointRounding.AwayFromZero));
                byte[] snapPixels = ScaleRGBA(pipPixels, pipW, pipH, snapW, snapH);
                var album = new PhotoAlbum(Path.Combine(NeighborhoodUserData, "PhotoAlbum"));
                float[] qualities = [0.2f, 0.5f, 0.9f];
                float quality = qualities[Math.Clamp(Ui.Camera.Quality, 0, qualities.Length - 1)];
                _ = album.Capture(
                    snapPixels,
                    snapW,
                    snapH,
                    quality,
                    window.Text ?? Strings.AlbumDescription());
            }
            catch (Exception error)
            {
                Log($"Picture-in-picture snapshot: {error}");
            }
        }
    }

    private CGRect? EventRect(int id)
    {
        if (Renderer.ScreenBounds(id, SimdCanvas) is not { } bounds)
        {
            return null;
        }

        double zoomScale = Renderer.Zoom.Factor() / LotZoom.Near.Factor();
        var size = new CGSize(200.0 * zoomScale * Scale, 300.0 * zoomScale * Scale);
        double left = Math.Max(0.0, bounds.MidX - size.Width / 2.0);
        double top = Math.Max(0.0, bounds.MidY - size.Height / 2.0);
        double right = Math.Min(_canvas.Width, bounds.MidX + size.Width / 2.0);
        double bottom = Math.Min(_canvas.Height, bounds.MidY + size.Height / 2.0);
        if (right <= left || bottom <= top)
        {
            return null;
        }

        double minX = Math.Floor(left);
        double minY = Math.Floor(top);
        double maxX = Math.Ceiling(right);
        double maxY = Math.Ceiling(bottom);
        return new CGRect(minX, minY, maxX - minX, maxY - minY);
    }

    private void CentreView(int id)
    {
        if (TargetPosition(id) is { } pos
            && pos.Level != EffectiveViewLevel
            && pos.Level >= 1
            && pos.Level <= Renderer.StoryCount)
        {
            _pendingPipCenterObjectID = id;
            _pendingPipCenterChangesLevel = true;
            _pendingViewLevel = pos.Level;
            _pendingRoofsVisible = false;
            _pendingViewSceneRevision = null;
            _pendingViewRequestID = Send(
                "level",
                new Dictionary<string, object?> { ["value"] = pos.Level, ["roofs"] = false });
            return;
        }

        _pendingPipCenterObjectID = null;
        _pendingPipCenterChangesLevel = false;
        if (Renderer.ScreenBounds(id, SimdCanvas) is { } bounds
            && Renderer.SceneViewport(SimdCanvas) is { } viewport)
        {
            Renderer.Pan += viewport.Size / 2f - new Vector2((float)bounds.MidX, (float)bounds.MidY);
        }
        else if (TargetPosition(id) is { } targetPos
            && Renderer.SceneViewport(SimdCanvas) is { } fallbackViewport
            && Renderer.ScreenPoint(targetPos.X, targetPos.Y, SimdCanvas) is { } point)
        {
            float lift = targetPos.IsSim ? 8f * MathF.Sqrt(6f) * Renderer.Zoom.Factor() * Renderer.UIScale : 0f;
            Renderer.Pan += fallbackViewport.Size / 2f - (point - new Vector2(0f, lift));
        }

        if (EffectiveRoofsVisible)
        {
            _pendingRoofsVisible = false;
            _pendingViewSceneRevision = null;
            _pendingViewRequestID = Send("roofs", new Dictionary<string, object?> { ["visible"] = false });
        }
    }

    private void CentrePipObjectIfPending()
    {
        if (_pendingPipCenterObjectID is not int id)
        {
            return;
        }

        if (TargetPosition(id) is { } pos)
        {
            if (pos.Level != EffectiveViewLevel && pos.Level >= 1 && pos.Level <= Renderer.StoryCount)
            {
                _pendingViewLevel = pos.Level;
                _pendingRoofsVisible = false;
                _pendingViewSceneRevision = null;
                _pendingViewRequestID = Send(
                    "level",
                    new Dictionary<string, object?> { ["value"] = pos.Level, ["roofs"] = false });
                return;
            }

            if (pos.Level != Renderer.ViewLevel)
            {
                return;
            }
        }

        if (Renderer.ScreenBounds(id, SimdCanvas) is { } bounds
            && Renderer.SceneViewport(SimdCanvas) is { } viewport)
        {
            _pendingPipCenterObjectID = null;
            _pendingPipCenterChangesLevel = false;
            Renderer.Pan += viewport.Size / 2f - new Vector2((float)bounds.MidX, (float)bounds.MidY);
            if (EffectiveRoofsVisible)
            {
                _pendingRoofsVisible = false;
                _pendingViewSceneRevision = null;
                _pendingViewRequestID = Send("roofs", new Dictionary<string, object?> { ["visible"] = false });
            }
        }
        else if (TargetPosition(id) is { } fallbackPos
            && _pendingPipCenterChangesLevel
            && Renderer.CentreGroundTile((int)fallbackPos.X, (int)fallbackPos.Y, SimdCanvas) is not null)
        {
            _pendingPipCenterObjectID = null;
            _pendingPipCenterChangesLevel = false;
            if (EffectiveRoofsVisible)
            {
                _pendingRoofsVisible = false;
                _pendingViewSceneRevision = null;
                _pendingViewRequestID = Send("roofs", new Dictionary<string, object?> { ["visible"] = false });
            }
        }
    }

    private readonly Queue<string> _pendingCheatQueue = new();
    private (string Id, string Command)? _pendingCheatRequest;

    private static readonly (string Name, string Description)[] CheatHelpEntries =
    [
        ("rosebud", "Adds 1000 Simoleons to household funds"),
        ("klapaucius", "Adds 1000 Simoleons to household funds"),
        ("motherlode", "Adds 100000 Simoleons to household funds"),
        ("move_objects on|off", "Allows moving/deleting normally locked objects"),
        ("autonomy <0-100>", "Sets Sim autonomy level"),
        ("set_hour <0-23>", "Sets current hour of day"),
        ("water_tool", "Activates pond water terrain tool"),
        ("map_edit on|off", "Allows editing lot perimeter tiles"),
        ("nessie", "Summons Nessie in neighborhood view"),
        ("cars [speed] [count]", "Spawns neighborhood road cars"),
        ("weather <clear|cloud|rain|thunder|snow|auto>", "Overrides current weather"),
        ("season <spring|summer|fall|winter> [day]", "Switches the current season"),
        ("help [filter]", "Lists available cheat commands"),
    ];

    internal void WireNeighborhoodOverlay(OriginalNeighborhoodOverlay neighborhood)
    {
        var weakSelf = new WeakReference<LiveController>(this);
        neighborhood.PlaySound = name =>
        {
            if (weakSelf.TryGetTarget(out var self))
            {
                self.PlayUISound(name);
            }
        };
    }

    private bool IsCtrlHeld() =>
        (SDL_GetModState() & SDL_KMOD_CTRL) != 0 || ScriptCtrlModifier;

    private bool IsShiftHeld() =>
        (SDL_GetModState() & SDL_KMOD_SHIFT) != 0 || ScriptShiftModifier;

    private bool IsCheatShortcutHeld() => IsCtrlHeld() && IsShiftHeld();

    private bool CanOpenCheatConsole() =>
        !Ui.Loading
        && Ui.GameDialog is null
        && !Ui.HelpVisible
        && !Ui.BudgetReportVisible
        && !Ui.Album.Visible
        && Ui.HouseholdCreation is null
        && Ui.ModsOverlay is null
        && Ui.FamilyPicker is null
        && Ui.Credits is null
        && Ui.OutfitPicker is null
        && Ui.GenericSimsCallPicker is null
        && (Ui.ShowsLot || Ui.Neighborhood is not null);

    private void ToggleCheatConsole()
    {
        if (Ui.CheatConsole.Visible)
        {
            _pendingCheatQueue.Clear();
            _pendingCheatRequest = null;
            Ui.CheatConsole.Close();
        }
        else if (CanOpenCheatConsole())
        {
            Ui.CheatConsole.Open();
        }
    }

    private bool HandleCheatConsoleKeyDown(Key key)
    {
        switch (key)
        {
            case Key.Character { Value: "c" } when IsCheatShortcutHeld():
            case Key.Escape:
                _pendingCheatQueue.Clear();
                _pendingCheatRequest = null;
                Ui.CheatConsole.Close();
                return true;
            case Key.Enter:
                SubmitCheatConsole();
                return true;
            case Key.Backspace:
                Ui.CheatConsole.Backspace();
                return true;
            case Key.Delete:
                Ui.CheatConsole.Delete();
                return true;
            case Key.Left:
                Ui.CheatConsole.MoveLeft(word: IsCtrlHeld(), select: IsShiftHeld());
                return true;
            case Key.Right:
                Ui.CheatConsole.MoveRight(word: IsCtrlHeld(), select: IsShiftHeld());
                return true;
            case Key.Home:
                Ui.CheatConsole.MoveHome(select: IsShiftHeld());
                return true;
            case Key.End:
                Ui.CheatConsole.MoveEnd(select: IsShiftHeld());
                return true;
            case Key.Up:
                Ui.CheatConsole.HistoryUp();
                return true;
            case Key.Down:
                Ui.CheatConsole.HistoryDown();
                return true;
            case Key.Character { Value: "a" } when IsCtrlHeld():
                Ui.CheatConsole.SelectAll();
                return true;
            default:
                return true;
        }
    }

    private void SubmitCheatConsole()
    {
        if (string.IsNullOrWhiteSpace(Ui.CheatConsole.Text))
        {
            Ui.CheatConsole.Close();
            return;
        }

        if (!Ui.CheatConsole.TryPrepareSegments(out var segments, out var errorTitle, out var errorMessage))
        {
            PresentLocalFeedback(errorTitle ?? Strings.SorryTitle(), errorMessage ?? "No previous cheat.");
            return;
        }

        if (segments.Count == 0)
        {
            Ui.CheatConsole.Close();
            return;
        }

        _pendingCheatQueue.Clear();
        foreach (var seg in segments)
        {
            _pendingCheatQueue.Enqueue(seg);
        }

        DispatchNextCheatCommand();
    }

    private void DispatchNextCheatCommand()
    {
        if (_pendingCheatRequest is not null)
        {
            return;
        }

        while (_pendingCheatQueue.Count > 0)
        {
            string cmd = _pendingCheatQueue.Dequeue();
            string[] tokens = cmd.Split((char[]?)null, StringSplitOptions.RemoveEmptyEntries);
            if (tokens.Length == 0)
            {
                continue;
            }

            if (string.Equals(tokens[0], "help", StringComparison.OrdinalIgnoreCase))
            {
                _pendingCheatQueue.Clear();
                string? filter = tokens.Length > 1 ? tokens[1] : null;
                var matches = string.IsNullOrEmpty(filter)
                    ? CheatHelpEntries
                    : CheatHelpEntries.Where(e => e.Name.Contains(filter, StringComparison.OrdinalIgnoreCase)).ToArray();
                if (matches.Length == 0)
                {
                    PresentLocalFeedback(Strings.SorryTitle(), "Sorry, no cheats match the search string.");
                }
                else
                {
                    string body = string.Join("\n", matches.Select(m => $"{m.Name} - {m.Description}"));
                    PresentLocalFeedback("Cheat Help", body);
                }

                return;
            }

            if (Bridge is not null)
            {
                if (Send("cheat", new Dictionary<string, object?> { ["code"] = cmd }) is { } id)
                {
                    _pendingCheatRequest = (id, cmd);
                    return;
                }
            }
            else if (Ui.Neighborhood is { } neighborhood)
            {
                if (string.Equals(tokens[0], "nessie", StringComparison.OrdinalIgnoreCase))
                {
                    neighborhood.TriggerNessie();
                    Ui.CheatConsole.RecordExecutedCommand(cmd);
                    continue;
                }

                if (string.Equals(tokens[0], "cars", StringComparison.OrdinalIgnoreCase))
                {
                    int speed = tokens.Length > 1 && int.TryParse(tokens[1], out int parsedSpeed) ? parsedSpeed : 1;
                    int count = tokens.Length > 2 && int.TryParse(tokens[2], out int parsedCount) ? parsedCount : 1;
                    neighborhood.TriggerCars(speed, count);
                    Ui.CheatConsole.RecordExecutedCommand(cmd);
                    continue;
                }

                _pendingCheatQueue.Clear();
                PresentLocalFeedback(Strings.SorryTitle(), "No such cheat.");
                return;
            }
        }

        if (_pendingCheatQueue.Count == 0 && _pendingCheatRequest is null)
        {
            Ui.CheatConsole.Close();
        }
    }

    private bool HandleCheatResponse(string id, bool ok, IReadOnlyDictionary<string, JsonElement> evt)
    {
        if (_pendingCheatRequest is not { } pending || !string.Equals(pending.Id, id, StringComparison.Ordinal))
        {
            return false;
        }

        _pendingCheatRequest = null;
        if (ok)
        {
            Ui.CheatConsole.RecordExecutedCommand(pending.Command);
            DispatchNextCheatCommand();
        }
        else
        {
            _pendingCheatQueue.Clear();
            string? error = evt.JsonString("error");
            if (string.IsNullOrEmpty(error)
                || error.Contains("Unknown cheat", StringComparison.OrdinalIgnoreCase)
                || error.Contains("No such cheat", StringComparison.OrdinalIgnoreCase))
            {
                PresentLocalFeedback(Strings.SorryTitle(), "No such cheat.");
            }
            else if (error.Contains("No previous cheat", StringComparison.OrdinalIgnoreCase))
            {
                PresentLocalFeedback(Strings.SorryTitle(), "No previous cheat.");
            }
            else
            {
                PresentLocalFeedback("Cheat Error", error);
            }
        }

        return true;
    }

    private void HandleNeighborhoodCheatEvent(IReadOnlyDictionary<string, JsonElement> evt)
    {
        string? code = evt.JsonString("code");
        if (string.Equals(code, "nessie", StringComparison.OrdinalIgnoreCase))
        {
            Ui.Neighborhood?.TriggerNessie();
        }
        else if (string.Equals(code, "cars", StringComparison.OrdinalIgnoreCase))
        {
            int speed = evt.JsonInt("speed") ?? 1;
            int count = evt.JsonInt("count") ?? 1;
            Ui.Neighborhood?.TriggerCars(speed, count);
        }
    }
}
