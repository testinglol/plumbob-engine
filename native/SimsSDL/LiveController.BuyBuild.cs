using System.Collections.Concurrent;
using System.Diagnostics;

namespace SimsSDL;

internal sealed partial class LiveController
{

    private void EditObject(CGPoint point)
    {
        if (!Ui.ObjectEditing || Renderer.Speed != 0 || HasBlockingDialog || OverPanelControls(point))
        {
            return;
        }

        if (Ui.Buy.Selection.Target is { } target
            && ResolveObjectPlacementTarget(point, target) is { } resolved)
        {
            GroundTile tile = resolved.Tile;
            int placementDirection = Ui.Buy.Direction;
            if (resolved.WallDirection is int wallDir)
            {
                if (_snappedPlacementDirection is { } snapped
                    && snapped.Key.Target == target
                    && snapped.Key.Tile == tile
                    && snapped.Key.WallDirection == wallDir)
                {
                    placementDirection = snapped.Direction;
                }
                else
                {
                    int primaryDir = wallDir switch { 1 => 1, 2 => 4, 3 => 16, _ => 64 };
                    int oppositeDir = wallDir switch { 1 => 16, 2 => 64, 3 => 1, _ => 4 };
                    if (placementDirection != primaryDir && placementDirection != oppositeDir)
                    {
                        placementDirection = primaryDir;
                    }
                }
            }

            if (!target.IsPlaced)
            {
                if (Ui.SelectedCatalogPrice is { } price && price <= (Ui.Gameplay.State?.Budget ?? 0))
                {
                    string? request = Send(
                        "buyObject",
                        new Dictionary<string, object?>(StringComparer.Ordinal)
                        {
                            ["guid"] = target.CatalogGuid,
                            ["x"] = tile.PlacementX,
                            ["y"] = tile.PlacementY,
                            ["level"] = Renderer.ViewLevel,
                            ["direction"] = placementDirection,
                        });
                    PlayUISoundOnResponse(request, "ui_buy_place");
                }
                else
                {
                    try
                    {
                        Ui.CatalogPopup.ShowPlacementError(
                            Strings.InsufficientFunds(),
                            new CGPoint(point.X / Scale, point.Y / Scale));
                    }
                    catch
                    {
                    }

                    PlayUISound("ui_error");
                }
            }
            else if (target.PlacedObject is { } obj && obj.Movable)
            {
                string? request = Send(
                    "moveObject",
                    new Dictionary<string, object?>(StringComparer.Ordinal)
                    {
                        ["objectID"] = obj.Id,
                        ["x"] = tile.PlacementX,
                        ["y"] = tile.PlacementY,
                        ["level"] = Renderer.ViewLevel,
                        ["direction"] = placementDirection,
                    });
                _pendingMoveRequest = request;
                PlayUISoundOnResponse(request, "ui_object_move_place");
            }
        }
        else if (Ui.Buy.Selection.Target is null
                 && Renderer.ObjectAt(Simd(point), SimdCanvas) is { } id
                 && _editableObjects.FirstOrDefault(candidate =>
                     candidate.Id == id
                     && (candidate.Level == Renderer.ViewLevel
                         || ((candidate.MultiTileMasterID ?? 0) != 0
                             && (candidate.CatalogCategory == 10 || candidate.CatalogCategory == 12)))
                     && CanEditBuildObject(candidate)) is { } obj)
        {
            Ui.Buy.Selection.ChooseObject(obj);
            PlayUISound("ui_object_move");
            SyncDisposePanel(markSaveDirtyOnPickup: obj.Movable);
            HoverCursor = CursorStem(point);
        }
    }

    private void SyncDisposePanel(bool? markSaveDirtyOnPickup = null)
    {
        if (Ui.Buy.Selection.Target is not { IsPlaced: true, PlacedObject: { } obj })
        {
            Ui.DisposePanel = null;
            _pendingDisposePreviewRequest = null;
            return;
        }

        bool hasMeta = _placedObjectMeta.TryGetValue(obj.Id, out var meta);
        OriginalGameplayOverlay.Image? existingPreview =
            Ui.DisposePanel?.ObjectID == obj.Id ? Ui.DisposePanel.Preview : null;
        var nextState = new LiveUI.DisposePanelState(
            objectID: obj.Id,
            catalogName: hasMeta ? meta.CatalogName : string.Empty,
            resaleValue: hasMeta ? meta.ResaleValue : 0,
            sellable: obj.Sellable,
            buildModeType: hasMeta ? meta.BuildModeType : (obj.CatalogCategory is { } category ? Math.Max(0, category - 7) : 0),
            preview: existingPreview);

        if (Ui.DisposePanel?.ObjectID != nextState.ObjectID
            || !string.Equals(Ui.DisposePanel?.CatalogName, nextState.CatalogName, StringComparison.Ordinal)
            || Ui.DisposePanel?.ResaleValue != nextState.ResaleValue
            || Ui.DisposePanel?.Sellable != nextState.Sellable
            || Ui.DisposePanel?.BuildModeType != nextState.BuildModeType)
        {
            Ui.DisposePanel = nextState;
        }

        if (markSaveDirtyOnPickup is { } markDirty)
        {
            if (Send(
                "cursorObjectCreated",
                new Dictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["objectID"] = obj.Id,
                    ["dirty"] = markDirty,
                }) is { } reqID)
            {
                _pendingDisposePreviewRequest = (reqID, obj.Id);
            }
        }
        else if (existingPreview is null && _pendingDisposePreviewRequest?.ObjectID != obj.Id)
        {
            if (Send(
                "cursorObjectCreated",
                new Dictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["objectID"] = obj.Id,
                    ["dirty"] = false,
                }) is { } reqID)
            {
                _pendingDisposePreviewRequest = (reqID, obj.Id);
            }
        }
    }

    private void SellHeldObject()
    {
        if (!Ui.ObjectEditing
            || Renderer.Speed != 0
            || HasBlockingDialog
            || Ui.Buy.Selection.Target is not { IsPlaced: true, PlacedObject: { } obj })
        {
            return;
        }

        if (!obj.Sellable)
        {
            PlayUISound("ui_error");
            return;
        }

        if (Send(
            "sellObject",
            new Dictionary<string, object?>(StringComparer.Ordinal) { ["objectID"] = obj.Id }) is { } request)
        {
            _pendingSaleRequests.Add(request);
        }

        if (_placementAnchor is not null)
        {
            PrimaryGesture = false;
        }

        _placementAnchor = null;
        _pendingMoveClearRevision = null;
        Ui.Buy.CancelSelection();
        SyncDisposePanel();
        Ui.CatalogPopup.ShowPlacementError(null);
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

        if (Pointer is { } pointer)
        {
            HoverCursor = CursorStem(pointer);
        }
    }

    private bool CancelHeldEditSelection()
    {
        bool hasBuyTarget = Ui.Buy.Selection.Target is not null;
        bool hasBuildObject = Ui.BuildMode && Ui.Build.SelectedObjectGUID is not null;
        bool hasBuildPattern = Ui.BuildMode
            && Ui.Build.Selected is not null
            && Ui.Build.Kind != BuildCatalogPage.CatalogKind.Roof;
        if (!hasBuyTarget && !hasBuildObject && !hasBuildPattern)
        {
            return false;
        }

        if (_placementAnchor is not null)
        {
            PrimaryGesture = false;
        }

        _placementAnchor = null;
        _pendingMoveClearRevision = null;
        Ui.Buy.CancelSelection();
        if (hasBuildObject || hasBuildPattern)
        {
            Ui.Build.CancelSelection();
        }

        SyncDisposePanel();
        Ui.CatalogPopup.ShowPlacementError(null);
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

        ClearBuildCursor();
        if (Pointer is { } pointer)
        {
            UpdateBuildPreview(pointer);
            HoverCursor = CursorStem(pointer);
        }

        return true;
    }

    private void DeleteOrCancelHeldObject()
    {
        if (!Ui.ObjectEditing || Renderer.Speed != 0 || HasBlockingDialog)
        {
            return;
        }

        if (Ui.Buy.Selection.Target is { IsPlaced: true })
        {
            SellHeldObject();
            return;
        }

        if (Ui.Buy.Selection.Target is { IsCatalog: true }
            || (Ui.BuildMode && Ui.Build.SelectedObjectGUID is not null))
        {
            _ = CancelHeldEditSelection();
        }
    }

    private bool DeleteBuildObject(CGPoint point)
    {
        if (!Ui.BuildMode
            || !(Ui.Build.ObjectTool is not null
                 || (Ui.Build.TerrainMode is null
                     && (Ui.Build.Kind == BuildCatalogPage.CatalogKind.WallStyle
                         || Ui.Build.Kind == BuildCatalogPage.CatalogKind.Water)))
            || Renderer.Speed != 0
            || HasBlockingDialog
            || OverPanelControls(point)
            || OriginalGameplayOverlay.ContainsPanel(Local(point), LogicalCanvas, panelMinimized: IsLivePanelMinimized)
            || Renderer.ObjectAt(Simd(point), SimdCanvas) is not { } id
            || _editableObjects.FirstOrDefault(candidate =>
                candidate.Id == id
                && (candidate.Level == Renderer.ViewLevel
                    || ((candidate.MultiTileMasterID ?? 0) != 0
                        && (candidate.CatalogCategory == 10 || candidate.CatalogCategory == 12)))) is not { } obj
            || !CanEditBuildObject(obj))
        {
            return false;
        }

        if (!obj.Sellable)
        {
            PlayUISound("ui_error");
            return true;
        }

        if (Send(
            "sellObject",
            new Dictionary<string, object?>(StringComparer.Ordinal) { ["objectID"] = obj.Id }) is { } request)
        {
            _pendingSaleRequests.Add(request);
        }

        return true;
    }

    private OriginalUniversalControl? HitUniversalControl(CGPoint point)
    {
        var hit = OriginalUniversalControl.Hit(point, _canvas, Scale, Ui.HelpButtonSize);
        if (hit is not null && Ui.StoryCount > 2 && hit.Kind is OriginalUniversalControl.Action.Story1 or OriginalUniversalControl.Action.Story2)
        {
            return null;
        }

        return hit;
    }

    private bool OverPanelControls(CGPoint point)
    {
        CGPoint lp = Local(point);
        return OriginalGameplayOverlay.ContainsPanel(lp, LogicalCanvas, panelMinimized: IsLivePanelMinimized)
            || ((Ui.BuyMode || Ui.BuildMode || Ui.OptionsMode) && lp.Y >= LogicalCanvas.Height - 150.0)
            || (!Ui.Album.Visible
                && !Ui.Camera.Visible
                && Ui.PictureInPictureRect(LogicalCanvas, Scale)?.Contains(lp) == true)
            || Ui.StorySliceAt(lp, LogicalCanvas) is not null
            || HitUniversalControl(point) is not null
            || OriginalSpeedControl.Hit(point, _canvas, Scale) is not null
            || Ui.Camera.ModeRect(LogicalCanvas).Contains(lp)
            || (Ui.BuildMode && (!Ui.ShowsDisposePanel || lp.X < 220.0) && Ui.Build.ActionAt(lp, LogicalCanvas) is not null)
            || (Ui.BuyMode && (!Ui.ShowsDisposePanel || lp.X < 220.0) && Ui.Buy.ActionAt(lp, LogicalCanvas) is not null);
    }

    private FloorTileHit? FloorHit(CGPoint point) =>
        OverPanelControls(point) ? null : Renderer.FloorHitAt(Simd(point), SimdCanvas);

    private bool BuildToolsReady =>
        Ui.BuildMode
        && Ui.Build.ObjectTool is null
        && Ui.Build.SelectedObjectGUID is null
        && Ui.Buy.Selection.Target is null
        && Renderer.Speed == 0
        && !HasBlockingDialog;

    private bool FillRoom(CGPoint point, bool removing)
    {
        if (!BuildToolsReady
            || Ui.Build.TerrainMode is not null
            || !(removing || Ui.Build.SelectedItem is not null)
            || OverPanelControls(point))
        {
            return false;
        }

        FloorTileHit? hit = Renderer.FloorHitAt(Simd(point), SimdCanvas);
        if (BuildRoomFill.Create(
                kind: Ui.Build.Kind,
                pattern: Ui.Build.SelectedItem?.Id ?? 0,
                tile: hit?.Tile,
                wall: Renderer.WallAt(Simd(point), SimdCanvas),
                half: hit?.Half ?? 0,
                removing: removing,
                selectedLevel: Renderer.ViewLevel) is not { } fill)
        {
            return false;
        }

        _floorStroke = null;
        _floorBrush = null;
        try
        {
            Renderer.UpdateFloorBrush(null);
        }
        catch
        {
        }

        _ = SendWithBuildSound(
            "architecture",
            new Dictionary<string, object?>(StringComparer.Ordinal)
            {
                ["command"] = fill.Command,
                ["x"] = fill.X,
                ["y"] = fill.Y,
                ["level"] = fill.Level,
                ["x2"] = 0,
                ["y2"] = 0,
                ["pattern"] = (int)fill.Pattern,
                ["style"] = 0,
                ["half"] = fill.Half,
            });
        return true;
    }

    private void UpdateBuildPreview(CGPoint point)
    {
        if (Ui.ObjectEditing)
        {
            UpdatePlacement(point);
            return;
        }

        if (Ui.Build.TerrainMode is not null)
        {
            if (_terrainStrokeMode is null)
            {
                UpdateBuildCursor(point);
            }

            return;
        }

        switch (Ui.Build.Kind)
        {
            case BuildCatalogPage.CatalogKind.WallStyle:
                UpdateWallPreview(point);
                break;

            case BuildCatalogPage.CatalogKind.Wall:
                if (_floorBrush is not null)
                {
                    _floorBrush = null;
                    _floorBrushDeleting = false;
                    _floorBrushTexture = null;
                    try
                    {
                        Renderer.UpdateFloorBrush(null);
                    }
                    catch
                    {
                    }
                }

                UpdateBuildCursor(point);
                break;

            default:
                ClearBuildCursor();
                UpdateFloorPreview(point);
                break;
        }
    }

    private void UpdateBuildCursor(CGPoint point)
    {
        TerrainBrushMode? terrain = Ui.Build.TerrainMode;
        ushort mods = SDL_GetModState();
        bool deleting = (mods & (SDL_KMOD_ALT | SDL_KMOD_CTRL)) != 0;
        if (BuildToolsReady
            && !OverPanelControls(point)
            && terrain is null
            && Ui.Build.Kind == BuildCatalogPage.CatalogKind.Wall
            && (deleting || Ui.Build.SelectedItem is not null))
        {
            LotScene.WallSide? wall = Renderer.WallAt(Simd(point), SimdCanvas);
            SimsSDL.Core.GroundTile? hitTile = FloorHit(point)?.Tile;
            int tileX;
            int tileY;
            int level;
            if (wall is not null && wall.EdgeBit is not null)
            {
                tileX = wall.X;
                tileY = wall.Y;
                level = wall.Level;
            }
            else if (hitTile is { } hit)
            {
                tileX = hit.X;
                tileY = hit.Y;
                level = Renderer.ViewLevel;
            }
            else
            {
                ClearBuildCursor();
                return;
            }

            ushort? pattern = wall is not null && wall.EdgeBit is not null
                ? (deleting ? (ushort)0 : Ui.Build.SelectedItem?.Id)
                : (ushort?)null;
            int cursorDirection;
            if (wall is not null && wall.EdgeBit is not null)
            {
                cursorDirection = LotCameraExtensions.WallpaperCursorDirection(wall.Direction);
                _lastWallpaperCursorDirection = cursorDirection;
            }
            else
            {
                cursorDirection = _lastWallpaperCursorDirection ?? (1 << (((4 - (int)Renderer.CameraOrientation) % 4) * 2));
            }
            bool fill = (mods & SDL_KMOD_SHIFT) != 0;
            _desiredBuildCursor = new BuildCursorKey
            {
                Guid = 0x439u,
                Graphic = 2,
                Vertex = new SimsSDL.Core.LotVertex(tileX, tileY),
                Level = level,
                Direction = cursorDirection,
                Orientation = Renderer.CameraOrientation,
                Centered = true,
                Pattern = pattern,
                WallDirection = wall?.Direction ?? 0,
                WallEdge = wall?.EdgeBit,
                WallSide = wall?.Side,
                Fill = fill,
                Revision = Renderer.SceneRevisionNumber,
            };
            RequestBuildCursor();
            return;
        }

        if (!BuildToolsReady
            || OverPanelControls(point)
            || !(terrain is not null
                 || (Ui.Build.Kind == BuildCatalogPage.CatalogKind.WallStyle
                     && (Ui.Build.SelectedItem is not null || deleting)))
            || FloorHit(point) is null
            || Renderer.LotVertexAt(Simd(point), SimdCanvas) is not { } vertex)
        {
            ClearBuildCursor();
            return;
        }

        int graphic = terrain is { } mode
            ? mode switch
            {
                TerrainBrushMode.Raise => 0,
                TerrainBrushMode.Lower => 1,
                TerrainBrushMode.Grass => 2,
                _ => 3,
            }
            : (deleting ? 1 : (mods & SDL_KMOD_SHIFT) != 0 ? 3 : 0);

        _desiredBuildCursor = new BuildCursorKey
        {
            Guid = terrain is not null ? 0x2F39B7A6u : 0x439u,
            Graphic = graphic,
            Vertex = vertex,
            Level = Renderer.ViewLevel,
            Orientation = Renderer.CameraOrientation,
            Revision = Renderer.SceneRevisionNumber,
        };
        RequestBuildCursor();
    }

    private void RequestBuildCursor()
    {
        if (_pendingBuildCursor is not null
            || _desiredBuildCursor is not { } key
            || key == _checkedBuildCursor)
        {
            return;
        }

        var parameters = new Dictionary<string, object?>(StringComparer.Ordinal)
        {
            ["guid"] = key.Guid,
            ["graphic"] = key.Graphic,
            ["x"] = key.Vertex.X,
            ["y"] = key.Vertex.Y,
            ["level"] = key.Level,
            ["direction"] = key.Direction,
        };
        if (key.Centered)
        {
            parameters["centered"] = true;
        }

        if (key.Pattern is { } pattern)
        {
            parameters["pattern"] = (int)pattern;
            parameters["wallDirection"] = key.WallDirection;
            if (key.WallEdge is { } wallEdge)
            {
                parameters["wallEdge"] = wallEdge;
            }

            if (key.WallSide is { } wallSide)
            {
                parameters["wallSide"] = wallSide;
            }

            parameters["fill"] = key.Fill;
        }

        if (Send("buildCursor", parameters) is { } id)
        {
            _pendingBuildCursor = (id, key);
        }
    }

    private void ClearBuildCursor()
    {
        _desiredBuildCursor = null;
        _checkedBuildCursor = null;
        _lastWallpaperCursorDirection = null;
        if (Renderer.BuildCursor is not null)
        {
            try
            {
                Renderer.UpdateBuildCursor(null);
            }
            catch
            {
            }
        }

        if (Renderer.WallPaintPreview is not null)
        {
            try
            {
                Renderer.UpdateWallPaintPreview(null);
            }
            catch
            {
            }
        }
    }

    private (SimsSDL.Core.GroundTile Point, bool Buildable)? TerrainStrokePoint(CGPoint point, TerrainBrushMode mode)
    {
        if (!BuildToolsReady || OverPanelControls(point))
        {
            return null;
        }

        switch (mode)
        {
            case TerrainBrushMode.Raise:
            case TerrainBrushMode.Lower:
            {
                int w = Renderer.Scene?.LotWidth ?? 0;
                int h = Renderer.Scene?.LotHeight ?? 0;
                if (FloorHit(point) is null
                    || Renderer.LotVertexAt(Simd(point), SimdCanvas) is not { } vertex
                    || vertex.X < 0 || vertex.X >= w
                    || vertex.Y < 0 || vertex.Y >= h)
                {
                    return null;
                }

                return (new SimsSDL.Core.GroundTile(vertex), _buildable?.Contains(vertex) != false);
            }

            case TerrainBrushMode.Level:
            case TerrainBrushMode.Grass:
            {
                if (Renderer.GroundTileAt(Simd(point), SimdCanvas) is not { } tile)
                {
                    return null;
                }

                return (tile, _buildable?.Contains(tile) != false);
            }

            default:
                return null;
        }
    }

    private void RefuseBuild()
    {
        ulong now = SDL_GetTicks();
        if (now < _lastBuildRefusal + 400UL)
        {
            return;
        }

        _lastBuildRefusal = now;
        PlayUISound("ui_error");
    }

    private bool StartTerrainStroke(CGPoint point)
    {
        if (Ui.Build.TerrainMode is not { } mode
            || TerrainStrokePoint(point, mode) is not { } sampled)
        {
            return false;
        }

        if (!sampled.Buildable)
        {
            RefuseBuild();
            return true;
        }

        string strokeID = System.Guid.NewGuid().ToString("D").ToUpperInvariant();
        _terrainStrokeMode = mode;
        _terrainStrokeStartPoint = point;
        _terrainStrokeID = strokeID;
        _lastStreamedTerrainDelta = null;
        _terrainStrokePlayedSound = false;
        _terrainStrokeBaseHeight = null;
        if ((mode == TerrainBrushMode.Raise || mode == TerrainBrushMode.Lower)
            && Renderer.Scene is { } scene
            && scene.LotWidth is { } width
            && scene.LotHeight is { } height
            && scene.TerrainHeights is { } heights
            && sampled.Point.X >= 0 && sampled.Point.X < width
            && sampled.Point.Y >= 0 && sampled.Point.Y < height
            && heights.Count == width * height)
        {
            _terrainStrokeBaseHeight = (byte)Math.Clamp((int)heights[sampled.Point.Y * width + sampled.Point.X], 0, 255);
        }

        _terrainGesture = new TerrainBrushGesture();
        _terrainGesture.Begin(sampled.Point);
        if (mode == TerrainBrushMode.Grass)
        {
            FlushPendingGrassStroke(strokeID);
        }
        else if (mode == TerrainBrushMode.Level)
        {
            UpdateTerrainLevelPreview();
        }

        return true;
    }

    private void UpdateTerrainStroke(CGPoint point)
    {
        if (_terrainStrokeMode is not { } mode || _terrainStrokeID is not { } strokeID)
        {
            return;
        }

        if (mode == TerrainBrushMode.Raise || mode == TerrainBrushMode.Lower)
        {
            if (_terrainGesture.Start is not { } vertex
                || _terrainStrokeBaseHeight is not { } baseHeight
                || _terrainStrokeStartPoint is not { } startPoint
                || Renderer.Scene is not { } scene
                || scene.LotWidth is not { } width
                || scene.LotHeight is not { } height
                || Renderer.SceneViewport(SimdCanvas) is not { } viewport)
            {
                return;
            }

            try
            {
                short rawDelta = TerrainHeightDrag.Delta(
                    startPoint.Y,
                    point.Y,
                    viewport.Scale,
                    mode);
                if (rawDelta == 0 || rawDelta == _lastStreamedTerrainDelta)
                {
                    return;
                }

                ushort mods = SDL_GetModState();
                bool ctrlHeld = (mods & SDL_KMOD_CTRL) != 0 || ScriptDeleteModifier;
                ArchitectureCommandRequest request = TerrainBrushRequest.MakeLiveRaise(
                    mode: mode,
                    vertex: vertex,
                    baseHeight: baseHeight,
                    level: Renderer.ViewLevel,
                    lotWidth: width,
                    lotHeight: height,
                    stories: scene.Stories ?? LotScene.MaxSupportedStories,
                    heightDelta: rawDelta,
                    smooth: ctrlHeld);
                _lastStreamedTerrainDelta = rawDelta;
                SendTerrainBatch([request], strokeID);
            }
            catch (Exception error)
            {
                Log($"Terrain editing: {error}");
            }

            return;
        }

        if (TerrainStrokePoint(point, mode) is not { } sampled)
        {
            return;
        }

        if (!sampled.Buildable)
        {
            RefuseBuild();
            return;
        }

        _terrainGesture.Move(sampled.Point);
        if (mode == TerrainBrushMode.Grass)
        {
            FlushPendingGrassStroke(strokeID);
        }
        else if (mode == TerrainBrushMode.Level)
        {
            UpdateTerrainLevelPreview();
        }
    }

    private void FlushPendingGrassStroke(string strokeID)
    {
        if (Renderer.Scene is not { } scene)
        {
            return;
        }

        List<SimsSDL.Core.GroundTile> pending = _terrainGesture.DrainPendingGrassSamples();
        if (pending.Count == 0)
        {
            return;
        }

        ushort mods = SDL_GetModState();
        bool shiftHeld = (mods & SDL_KMOD_SHIFT) != 0 || ScriptShiftModifier;
        bool ctrlHeld = (mods & SDL_KMOD_CTRL) != 0 || ScriptDeleteModifier;
        short grassStep = (shiftHeld || ctrlHeld) ? (short)32 : (short)-32;
        try
        {
            List<ArchitectureCommandRequest> requests = TerrainBrushRequest.MakeStroke(
                mode: TerrainBrushMode.Grass,
                start: pending[0],
                end: null,
                samples: pending,
                level: Renderer.ViewLevel,
                scene: scene,
                grassStep: grassStep);
            if (requests.Count == 0)
            {
                return;
            }

            SendTerrainBatch(requests, strokeID);
        }
        catch (Exception error)
        {
            Log($"Terrain editing: {error}");
        }
    }

    private void SendTerrainBatch(IReadOnlyList<ArchitectureCommandRequest> requests, string strokeID)
    {
        var payload = new Dictionary<string, object?>(StringComparer.Ordinal)
        {
            ["commands"] = requests.Select(static request => request.Payload).ToList(),
            ["strokeId"] = strokeID,
        };
        if (!_terrainStrokePlayedSound)
        {
            _terrainStrokePlayedSound = true;
            _ = SendWithBuildSound("architectureBatch", payload);
        }
        else
        {
            _ = Send("architectureBatch", payload);
        }
    }

    private void UpdateTerrainLevelPreview()
    {
        if (_terrainGesture.Start is not { } start
            || FloorBrushRectangle.Create(start, _terrainGesture.End ?? start) is not { } rectangle
            || FloorBrushSelection.Create(rectangle, half: 0) is not { } selection)
        {
            ClearTerrainLevelPreview();
            return;
        }

        if (selection == _floorBrush && !_floorBrushDeleting && _floorBrushTexture is null)
        {
            return;
        }

        try
        {
            Renderer.UpdateFloorBrush(selection, deleting: false, textureFile: null);
            _floorBrush = selection;
            _floorBrushDeleting = false;
            _floorBrushTexture = null;
        }
        catch (Exception error)
        {
            Log($"Terrain level brush: {error}");
        }
    }

    private void ClearTerrainLevelPreview()
    {
        if (_floorBrush is null)
        {
            return;
        }

        _floorBrush = null;
        _floorBrushDeleting = false;
        _floorBrushTexture = null;
        try
        {
            Renderer.UpdateFloorBrush(null);
        }
        catch
        {
        }
    }

    private void FinishTerrainStroke(CGPoint point)
    {
        if (_terrainStrokeMode is not { } mode)
        {
            return;
        }

        string strokeID = _terrainStrokeID ?? System.Guid.NewGuid().ToString("D").ToUpperInvariant();
        byte? baseHeight = _terrainStrokeBaseHeight;
        short? previousDelta = _lastStreamedTerrainDelta;
        bool playedSound = _terrainStrokePlayedSound;
        _terrainStrokeMode = null;
        CGPoint? startPoint = _terrainStrokeStartPoint;
        _terrainStrokeStartPoint = null;
        _terrainStrokeID = null;
        _terrainStrokeBaseHeight = null;
        _lastStreamedTerrainDelta = null;
        _terrainStrokePlayedSound = false;
        try
        {
            if (Renderer.Scene is not { } scene
                || Renderer.SceneViewport(SimdCanvas) is not { } viewport
                || _terrainGesture.Start is not { } startTile)
            {
                _terrainGesture = new TerrainBrushGesture();
                return;
            }

            if (mode != TerrainBrushMode.Raise
                && mode != TerrainBrushMode.Lower
                && TerrainStrokePoint(point, mode) is { Buildable: true } sampled)
            {
                _terrainGesture.Move(sampled.Point);
            }

            try
            {
                ushort mods = SDL_GetModState();
                bool shiftHeld = (mods & SDL_KMOD_SHIFT) != 0 || ScriptShiftModifier;
                bool ctrlHeld = (mods & SDL_KMOD_CTRL) != 0 || ScriptDeleteModifier;
                short grassStep = (shiftHeld || ctrlHeld) ? (short)32 : (short)-32;
                bool smooth = (mode == TerrainBrushMode.Raise || mode == TerrainBrushMode.Lower) && ctrlHeld;
                List<ArchitectureCommandRequest> requests;
                if ((mode == TerrainBrushMode.Raise || mode == TerrainBrushMode.Lower)
                    && previousDelta is { } streamedDelta
                    && baseHeight is { } initialHeight
                    && scene.LotWidth is { } width
                    && scene.LotHeight is { } height)
                {
                    _terrainGesture.Cancel();
                    short rawDelta = TerrainHeightDrag.Delta(
                        startPoint?.Y ?? point.Y,
                        point.Y,
                        viewport.Scale,
                        mode);
                    if (rawDelta == streamedDelta)
                    {
                        return;
                    }

                    requests =
                    [
                        TerrainBrushRequest.MakeLiveRaise(
                            mode: mode,
                            vertex: startTile,
                            baseHeight: initialHeight,
                            level: Renderer.ViewLevel,
                            lotWidth: width,
                            lotHeight: height,
                            stories: scene.Stories ?? LotScene.MaxSupportedStories,
                            heightDelta: rawDelta,
                            smooth: smooth),
                    ];
                }
                else
                {
                    short? heightDelta;
                    if (mode == TerrainBrushMode.Raise || mode == TerrainBrushMode.Lower)
                    {
                        short rawDelta = TerrainHeightDrag.Delta(
                            startPoint?.Y ?? point.Y,
                            point.Y,
                            viewport.Scale,
                            mode);
                        int shiftInvert = shiftHeld ? -1 : 1;
                        short clickDelta = (short)((mode == TerrainBrushMode.Raise ? 1 : -1) * shiftInvert);
                        heightDelta = rawDelta == 0 ? clickDelta : rawDelta;
                    }
                    else
                    {
                        heightDelta = null;
                    }

                    requests = _terrainGesture.FinishStroke(
                        mode: mode,
                        level: Renderer.ViewLevel,
                        scene: scene,
                        heightDelta: heightDelta,
                        grassStep: grassStep,
                        smooth: smooth);
                }

                if (requests.Count == 0)
                {
                    return;
                }

                var payload = new Dictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["commands"] = requests.Select(static request => request.Payload).ToList(),
                    ["strokeId"] = strokeID,
                };
                if (!playedSound)
                {
                    _ = SendWithBuildSound("architectureBatch", payload);
                }
                else
                {
                    _ = Send("architectureBatch", payload);
                }
            }
            catch (Exception error)
            {
                _terrainGesture = new TerrainBrushGesture();
                Log($"Terrain editing: {error}");
            }
        }
        finally
        {
            if (mode == TerrainBrushMode.Level)
            {
                ClearTerrainLevelPreview();
            }
        }
    }

    private bool StartWallStroke(CGPoint point, bool rectangle, bool deleting)
    {
        ushort? style = deleting ? (Ui.Build.SelectedItem?.Id ?? (ushort)1) : Ui.Build.SelectedItem?.Id;
        ushort? pattern = deleting ? (Ui.Build.SelectedItem?.Pattern ?? (ushort)0) : Ui.Build.SelectedItem?.Pattern;
        if (!BuildToolsReady
            || Ui.Build.Kind != BuildCatalogPage.CatalogKind.WallStyle
            || style is not { } styleValue
            || pattern is not { } patternValue
            || FloorHit(point) is null
            || Renderer.LotVertexAt(Simd(point), SimdCanvas) is not { } vertex)
        {
            return false;
        }

        if (_buildable?.Contains(vertex) == false)
        {
            RefuseBuild();
            return true;
        }

        _wallStroke = new WallStroke
        {
            Start = vertex,
            Style = styleValue,
            Pattern = patternValue,
            Mode = new WallStrokeMode(Rectangle: rectangle, Deleting: deleting),
        };
        PlayUISound("ui_bld_dragtool_mousedown");
        return true;
    }

    private WallBrushSelection? WallLine(CGPoint point)
    {
        if (!BuildToolsReady
            || Ui.Build.Kind != BuildCatalogPage.CatalogKind.WallStyle
            || _wallStroke is not { } stroke
            || (!stroke.Mode.Deleting && Ui.Build.SelectedItem?.Id != stroke.Style)
            || FloorHit(point) is null
            || Renderer.LotVertexAt(Simd(point), SimdCanvas) is not { } vertex)
        {
            return null;
        }

        if (_buildable?.Contains(vertex) == false)
        {
            RefuseBuild();
            return _wallBrush;
        }

        ushort modifiers = SDL_GetModState();
        var mode = new WallStrokeMode(
            Rectangle: (modifiers & SDL_KMOD_SHIFT) != 0,
            Deleting: (modifiers & SDL_KMOD_CTRL) != 0 || (modifiers & SDL_KMOD_ALT) != 0);
        if (mode != stroke.Mode)
        {
            if (WallBrushSelection.Create(
                    stroke.Start,
                    vertex,
                    stroke.Mode.Rectangle,
                    stroke.Mode.Deleting) is { } previous)
            {
                stroke.Completed.Add(new WallStrokeSegment(previous, stroke.Style, stroke.Pattern));
            }

            stroke.Start = vertex;
            stroke.Mode = mode;
        }

        return WallBrushSelection.Create(
            stroke.Start,
            vertex,
            stroke.Mode.Rectangle,
            stroke.Mode.Deleting);
    }

    private void UpdateWallPreview(CGPoint point)
    {
        if (WallLine(point) is not { } line)
        {
            if (_wallBrush is not null)
            {
                _wallBrush = null;
                try
                {
                    Renderer.UpdateWallBrush(null);
                }
                catch
                {
                }
            }

            if (_wallStroke is null)
            {
                UpdateBuildCursor(point);
            }

            return;
        }

        if (line == _wallBrush)
        {
            return;
        }

        try
        {
            Renderer.UpdateWallBrush(line);
            _wallBrush = line;
        }
        catch (Exception error)
        {
            Log($"Wall brush: {error}");
        }
    }

    private void FinishWallStroke(CGPoint point)
    {
        if (_wallStroke is null)
        {
            return;
        }

        WallBrushSelection? line = WallLine(point);
        if (_wallStroke is not { } stroke)
        {
            return;
        }

        PlayUISound("ui_bld_dragtool_mouseup");
        _wallStroke = null;
        _wallBrush = null;
        try
        {
            Renderer.UpdateWallBrush(null);
        }
        catch
        {
        }

        List<WallStrokeSegment> segments = [.. stroke.Completed];
        if (line is not null)
        {
            segments.Add(new WallStrokeSegment(line, stroke.Style, stroke.Pattern));
        }

        if (segments.Count == 0)
        {
            return;
        }

        var requests = segments.Select(segment =>
        {
            var arguments = segment.Selection.Arguments;
            return new Dictionary<string, object?>(StringComparer.Ordinal)
            {
                ["command"] = segment.Selection.Command,
                ["x"] = arguments.X,
                ["y"] = arguments.Y,
                ["x2"] = arguments.X2,
                ["y2"] = arguments.Y2,
                ["pattern"] = (int)segment.Pattern,
                ["style"] = (int)segment.Style,
            };
        }).ToList();

        _ = SendWithBuildSound(
            "architecture",
            new Dictionary<string, object?>(StringComparer.Ordinal)
            {
                ["command"] = "WALL_STROKE",
                ["level"] = Renderer.ViewLevel,
                ["segments"] = requests,
            });
    }

    private bool StartWallpaperStroke(CGPoint point, bool deleting)
    {
        if (!BuildToolsReady
            || Ui.Build.Kind != BuildCatalogPage.CatalogKind.Wall
            || OverPanelControls(point)
            || (deleting ? (ushort)0 : Ui.Build.SelectedItem?.Id) is not ushort pattern)
        {
            return false;
        }

        LotScene.WallSide? wall = Renderer.WallAt(Simd(point), SimdCanvas);
        GroundTile? hitTile = FloorHit(point)?.Tile;
        if ((wall is null || wall.EdgeBit is null) && hitTile is null)
        {
            return false;
        }

        _wallpaperStroke = (deleting, pattern, new HashSet<LotScene.WallSide>());
        UpdateBuildCursor(point);
        if (wall is { EdgeBit: not null })
        {
            ApplyWallpaperAtWall(wall, deleting, pattern);
        }

        return true;
    }

    private void UpdateWallpaperStroke(CGPoint point)
    {
        if (_wallpaperStroke is not { } stroke || OverPanelControls(point))
        {
            return;
        }

        UpdateCutaway(point);
        if (Renderer.WallAt(Simd(point), SimdCanvas) is { EdgeBit: not null } wall)
        {
            ApplyWallpaperAtWall(wall, stroke.Deleting, stroke.Pattern);
        }
    }

    private void FinishWallpaperStroke()
    {
        _wallpaperStroke = null;
    }

    private void ApplyWallpaperAtWall(LotScene.WallSide wall, bool deleting, ushort pattern)
    {
        if (wall.EdgeBit is not int edge)
        {
            return;
        }

        if (_wallpaperStroke is { } activeStroke && !activeStroke.Visited.Add(wall))
        {
            return;
        }

        if (deleting)
        {
            _ = SendWithBuildSound(
                "architecture",
                new Dictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["command"] = "PATTERN_ERASE",
                    ["x"] = wall.X,
                    ["y"] = wall.Y,
                    ["level"] = wall.Level,
                    ["edge"] = edge,
                    ["side"] = wall.Side ?? 0,
                    ["pattern"] = 0,
                },
                successSound: "ui_archtool_delete");
        }
        else
        {
            _ = SendWithBuildSound(
                "architecture",
                new Dictionary<string, object?>(StringComparer.Ordinal)
                {
                    ["command"] = "PATTERN_DOT",
                    ["x"] = wall.X,
                    ["y"] = wall.Y,
                    ["level"] = wall.Level,
                    ["edge"] = edge,
                    ["side"] = wall.Side ?? 0,
                    ["x2"] = wall.Direction,
                    ["y2"] = wall.Direction,
                    ["pattern"] = (int)pattern,
                    ["style"] = 0,
                });
        }
    }

    private bool FloorToolReady =>
        BuildToolsReady
        && Ui.Build.SelectedObjectGUID is null
        && (Ui.Build.Kind == BuildCatalogPage.CatalogKind.Floor || Ui.Build.Kind == BuildCatalogPage.CatalogKind.Water);

    private bool StartFloorStroke(CGPoint point, bool deleting)
    {
        if (!FloorToolReady
            || (deleting ? (ushort)0 : Ui.Build.SelectedItem?.Id) is not ushort pattern
            || FloorHit(point)?.Tile is not { } tile)
        {
            return false;
        }

        if (_buildable is { } area && !area.Contains(tile))
        {
            RefuseBuild();
            return true;
        }

        _floorStroke = (tile, pattern, Ui.Build.SelectedItem?.Id, deleting);
        if (!deleting)
        {
            PlayUISound("ui_bld_dragtool_mousedown");
        }

        _floorBrush = null;
        UpdateFloorPreview(point);
        return true;
    }

    private (FloorBrushRectangle Rectangle, FloorBrushSelection Selection)? FloorSelection(CGPoint point)
    {
        ushort mods = SDL_GetModState();
        bool shiftRoomFill = _floorStroke is null
            && Ui.Build.Kind == BuildCatalogPage.CatalogKind.Floor
            && ((mods & SDL_KMOD_SHIFT) != 0 || ScriptShiftModifier);
        bool modDeleting = _floorStroke?.Deleting ?? ((mods & (SDL_KMOD_ALT | SDL_KMOD_CTRL)) != 0 || ScriptDeleteModifier);
        if (!FloorToolReady
            || (Ui.Build.SelectedItem is null && !modDeleting)
            || FloorHit(point) is not { } hit
            || FloorBrushRectangle.Create(_floorStroke?.Start ?? hit.Tile, hit.Tile) is not { } rectangle
            || FloorBrushSelection.Create(
                rectangle,
                hit.Half,
                water: Ui.Build.Kind == BuildCatalogPage.CatalogKind.Water && !modDeleting,
                roomFill: shiftRoomFill) is not { } selection)
        {
            return null;
        }

        return (rectangle, selection);
    }

    private void UpdateFloorPreview(CGPoint point)
    {
        if (FloorSelection(point) is not { } selected)
        {
            if (_floorBrush is not null)
            {
                _floorBrush = null;
                _floorBrushDeleting = false;
                _floorBrushTexture = null;
                try
                {
                    Renderer.UpdateFloorBrush(null);
                }
                catch
                {
                }
            }

            return;
        }

        FloorBrushSelection selection = selected.Selection;
        bool deleting = _floorStroke?.Deleting ?? ((SDL_GetModState() & (SDL_KMOD_ALT | SDL_KMOD_CTRL)) != 0 || ScriptDeleteModifier);
        string? textureFile = !deleting && Ui.Build.Kind == BuildCatalogPage.CatalogKind.Floor
            ? (Ui.Build.SelectedItem?.Preview?.File ?? Ui.Build.SelectedItem?.Icon?.File)
            : null;
        if (Equals(selection, _floorBrush)
            && deleting == _floorBrushDeleting
            && string.Equals(textureFile, _floorBrushTexture, StringComparison.Ordinal))
        {
            return;
        }

        try
        {
            Renderer.UpdateFloorBrush(selection, deleting: deleting, textureFile: textureFile);
            _floorBrush = selection;
            _floorBrushDeleting = deleting;
            _floorBrushTexture = textureFile;
        }
        catch (Exception error)
        {
            Log($"Floor brush: {error}");
        }
    }

    private void FinishFloorStroke(CGPoint point)
    {
        if (_floorStroke is not { } stroke)
        {
            return;
        }

        var selected = FloorSelection(point);
        PlayUISound("ui_bld_dragtool_mouseup");
        _floorStroke = null;
        _floorBrush = null;
        try
        {
            Renderer.UpdateFloorBrush(null);
        }
        catch
        {
        }

        if ((!stroke.Deleting && Ui.Build.SelectedItem?.Id != stroke.Selection)
            || selected is not { } hit)
        {
            return;
        }

        var (rectangle, selection) = hit;
        string command;
        if (Ui.Build.Kind == BuildCatalogPage.CatalogKind.Water && stroke.Selection == 65535)
        {
            command = stroke.Deleting ? "POOL_ERASE" : "POOL_RECT";
        }
        else if (Ui.Build.Kind == BuildCatalogPage.CatalogKind.Water && stroke.Selection == 65534)
        {
            command = stroke.Deleting ? "WATER_ERASE" : "WATER_RECT";
        }
        else
        {
            command = "FLOOR_RECT";
        }

        _ = SendWithBuildSound(
            "architecture",
            new Dictionary<string, object?>(StringComparer.Ordinal)
            {
                ["command"] = command,
                ["x"] = rectangle.X,
                ["y"] = rectangle.Y,
                ["level"] = Renderer.ViewLevel,
                ["x2"] = rectangle.Width,
                ["y2"] = rectangle.Height,
                ["pattern"] = (int)stroke.Pattern,
                ["style"] = (int)selection.Style,
                ["half"] = selection.Half,
            });
        UpdateFloorPreview(point);
    }

    private bool IsWallPortalPlacementTarget(BuySelection.SelectionTarget target) =>
        (Ui.BuildMode && Ui.Build.ObjectTool is OriginalBuildObjectTool.Door or OriginalBuildObjectTool.Window or OriginalBuildObjectTool.Fireplace)
        || (target.IsPlaced && target.PlacedObject?.CatalogCategory is 8 or 9 or 12);

    private (GroundTile Tile, int? WallDirection)? ResolveObjectPlacementTarget(CGPoint point, BuySelection.SelectionTarget target)
    {
        if (IsWallPortalPlacementTarget(target)
            && Renderer.WallAt(Simd(point), SimdCanvas) is { } wall
            && wall.Level == Renderer.ViewLevel
            && wall.Edge is null
            && wall.Direction is >= 0 and <= 3)
        {
            return (new GroundTile(wall.X, wall.Y), wall.Direction);
        }

        return Renderer.GroundTileAt(Simd(point), SimdCanvas) is { } ground
            ? (ground, null)
            : null;
    }

    private void UpdatePlacement(CGPoint point)
    {
        var currentTarget = Ui.Buy.Selection.Target;
        var resolvedTarget = currentTarget is { } activeTarget
            ? ResolveObjectPlacementTarget(point, activeTarget)
            : (Renderer.GroundTileAt(Simd(point), SimdCanvas) is { } fallbackTile ? (fallbackTile, (int?)null) : null);

        bool insufficientFunds = Ui.Buy.Selected is not null
            && (Ui.SelectedCatalogPrice ?? 0) > (Ui.Gameplay.State?.Budget ?? 0);
        if (!insufficientFunds || resolvedTarget is null)
        {
            Ui.CatalogPopup.ShowPlacementError(null);
        }

        if (Ui.BuildMode && !Ui.ObjectEditing)
        {
            UpdateBuildPreview(point);
            return;
        }

        if (!Ui.ObjectEditing
            || Renderer.Speed != 0
            || HasBlockingDialog
            || OverPanelControls(point)
            || currentTarget is not { } target
            || resolvedTarget is not { } resolved)
        {
            bool preserveDeferredMoveClear = _pendingMoveClearRevision is not null
                && currentTarget is null
                && Ui.ObjectEditing
                && !OverPanelControls(point)
                && Renderer.Speed == 0
                && !HasBlockingDialog;
            if (!preserveDeferredMoveClear)
            {
                bool hadDeferredClear = _pendingMoveClearRevision is not null;
                _pendingMoveClearRevision = null;
                if (_desiredPlacement is not null || hadDeferredClear)
                {
                    try
                    {
                        Renderer.UpdatePlacement(null);
                    }
                    catch
                    {
                    }
                }
            }

            _desiredPlacement = null;
            _checkedPlacement = null;
            _snappedPlacementDirection = null;
            return;
        }

        bool unavailable = target.IsPlaced && !(target.PlacedObject?.Movable ?? false);
        if (unavailable)
        {
            _pendingMoveClearRevision = null;
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

            return;
        }

        _pendingMoveClearRevision = null;

        if (resolved.WallDirection is int wallDir)
        {
            int primaryDir = wallDir switch { 1 => 1, 2 => 4, 3 => 16, _ => 64 };
            int oppositeDir = wallDir switch { 1 => 16, 2 => 64, 3 => 1, _ => 4 };
            if (Ui.Buy.Direction != primaryDir && Ui.Buy.Direction != oppositeDir)
            {
                int snappedDir = _desiredPlacement is { WallDirection: { } prevWall }
                    && prevWall == wallDir
                    && _desiredPlacement.Value.Direction == primaryDir
                    ? oppositeDir
                    : primaryDir;
                Ui.Buy.Selection.SetDirection(snappedDir);
            }
        }

        var key = new PlacementKey(
            target,
            resolved.Tile,
            Ui.Buy.Direction,
            Renderer.SceneRevisionNumber,
            Renderer.ViewLevel,
            Renderer.CameraOrientation,
            resolved.WallDirection);
        if (_desiredPlacement != key)
        {
            _snappedPlacementDirection = null;
            if (_desiredPlacement is { } previous
                && (previous.Target != key.Target
                    || previous.Level != key.Level
                    || previous.Orientation != key.Orientation))
            {
                try
                {
                    Renderer.UpdatePlacement(null);
                }
                catch
                {
                }
            }
        }

        _desiredPlacement = key;
        RequestPlacement();
    }

    private void RequestPlacement()
    {
        if (_pendingPlacement is not null
            || _desiredPlacement is not { } key
            || _desiredPlacement == _checkedPlacement)
        {
            return;
        }

        var parameters = new Dictionary<string, object?>(StringComparer.Ordinal)
        {
            ["x"] = key.Tile.PlacementX,
            ["y"] = key.Tile.PlacementY,
            ["level"] = key.Level,
            ["direction"] = key.Direction,
        };
        if (key.WallDirection is int wallDir)
        {
            parameters["wallDirection"] = wallDir;
        }
        if (key.Target.IsPlaced && key.Target.PlacedObject is { } obj)
        {
            parameters["objectID"] = obj.Id;
        }
        else
        {
            parameters["guid"] = key.Target.CatalogGuid;
        }

        if (Send("previewObject", parameters) is { } id)
        {
            _pendingPlacement = (id, key);
        }
    }

    public void PrepareFrame()
    {
        Ui.StoryCount = Renderer.StoryCount;
        bool wasStoryAnimating = Ui.StoryStackIsAnimating;
        Ui.AdvanceStoryStackAnimation();
        if ((wasStoryAnimating || Ui.StoryStackIsAnimating)
            && Pointer is { } animPointer
            && !Ui.HelpVisible
            && !Ui.Album.Visible
            && !Ui.BudgetReportVisible)
        {
            Hover(animPointer, _canvas);
        }

        SyncDisposePanel();
        if (Ui.BuildMode && !Ui.ObjectEditing)
        {
            ushort mods = SDL_GetModState();
            if (ScriptShiftModifier)
            {
                mods |= SDL_KMOD_SHIFT;
            }
            if (ScriptDeleteModifier)
            {
                mods |= SDL_KMOD_CTRL;
            }
            if (mods != _lastBuildModifiers)
            {
                _lastBuildModifiers = mods;
                if (Pointer is { } pointer)
                {
                    UpdateBuildPreview(pointer);
                }
            }
        }

        Renderer.ShowsPlacement = Ui.BuyMode || Ui.BuildMode;
        Renderer.ShowsGhost = Ui.ObjectEditing;
        Renderer.ShowsBuildCursor = Ui.BuildMode
            && !Ui.ObjectEditing
            && (Ui.Build.TerrainMode is not null
                || Ui.Build.Kind == BuildCatalogPage.CatalogKind.WallStyle
                || Ui.Build.Kind == BuildCatalogPage.CatalogKind.Wall);
        Renderer.DrawsLot = Ui.ShowsLot;
        SyncFamilyPortraits();
    }
}
