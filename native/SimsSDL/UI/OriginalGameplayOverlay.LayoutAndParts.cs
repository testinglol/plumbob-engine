using System.Diagnostics;
using System.Globalization;
using System.Numerics;

namespace SimsSDL.UI;

public sealed partial class OriginalGameplayOverlay
{

    public IReadOnlyList<Part> Parts(CGSize canvas, bool panelMinimized = false)
    {
        TryPrepare(canvas);
        double top = canvas.Height - 150.0;
        var hoverTextures = _hoverTextures;
        if (hoverTextures is null)
        {
            hoverTextures = new HashSet<UITexture>(ReferenceEqualityComparer.Instance)
            {
                _people.Texture,
                _vectorPeople.Texture,
                _salaryButton.Texture,
                _vectorSalaryButton.Texture,
                _performanceButton.Texture,
                _jobFriendSmiley.Texture,
                _vectorJobFriendSmiley.Texture,
                _fameFriendSmiley.Texture,
                _vectorFameFriendSmiley.Texture,
                _jobIcons.Texture,
                _vectorJobIcons.Texture,
                _fameIcons.Texture,
                _vectorFameIcons.Texture
            };
            foreach (var img in ScrollArrows) hoverTextures.Add(img.Texture);
            foreach (var img in _interestArrows) hoverTextures.Add(img.Texture);
            foreach (var img in _buttons) hoverTextures.Add(img.Texture);
            foreach (var img in _vectorButtons)
            {
                if (img is { } vBtn) hoverTextures.Add(vBtn.Texture);
            }
            foreach (var img in _relationshipFilters) hoverTextures.Add(img.Texture);
            foreach (var img in _vectorRelationshipFilters) hoverTextures.Add(img.Texture);
            foreach (var img in _inventorySorts) hoverTextures.Add(img.Texture);
            foreach (var img in _vectorInventorySorts) hoverTextures.Add(img.Texture);
            _hoverTextures = hoverTextures;
        }

        CGPoint? panelHover = null;
        if (HoveredPanelPoint is { } raw)
        {
            if (raw.Y >= 0 && raw.Y < 150)
            {
                panelHover = raw;
            }
            else if (canvas.Height > 150 && raw.Y >= top && raw.Y < canvas.Height)
            {
                panelHover = new CGPoint(raw.X, raw.Y - top);
            }
        }

        var parts = new List<Part>(_body.Count + 64);
        foreach (var part in _body)
        {
            if (panelMinimized && part.Rect.X >= 220.0)
            {
                continue;
            }

            var uv = part.UV;
            if (panelHover is { } hovered &&
                hoverTextures.Contains(part.Image.Texture) &&
                Math.Abs(uv.X) < 0.001f &&
                Math.Abs(uv.Z - 0.25f) < 0.001f &&
                Contains(part.Rect, hovered))
            {
                uv.X = 0.50f;
            }

            parts.Add(new Part(part.Image, Offset(part.Rect, 0, top), uv, part.Opacity));
        }

        double now = MonotonicNowSeconds();
        if (_pluginToastBanner is { } toastBanner)
        {
            double remaining = toastBanner.ExpiresAt - now;
            if (remaining > 0.0)
            {
                float alpha = remaining < 1.0 ? (float)Math.Clamp(remaining, 0.0, 1.0) : 1f;
                var bannerImg = toastBanner.Image;
                parts.Add(new Part(
                    bannerImg,
                    new CGRect((canvas.Width - bannerImg.Size.Width) * 0.5, 14.0, bannerImg.Size.Width, bannerImg.Size.Height),
                    new Vector4(0f, 0f, 1f, 1f),
                    alpha));
            }
            else
            {
                _pluginToastBanner = null;
            }
        }
        if (!panelMinimized && CurrentSubpanel == Subpanel.Needs && State?.Selected is not null)
        {
            AppendNeedsDynamicParts(top, (ulong)(Math.Max(0.0, now) * 1000.0), parts);
        }

        int maxQueue = Math.Min(_queued.Count, Math.Max(0, (int)((canvas.Width - 32.0) / 50.0)));
        for (int index = 0; index < maxQueue; index++)
        {
            var (action, iconImg) = _queued[index];
            var actionRect = CurrentActionRect(index, now);
            if (iconImg is { } image && action.Icon is { } reference)
            {
                double width = image.Size.Width / reference.Columns;
                double height = image.Size.Height / reference.Rows;
                double scale = Math.Min(1.0, Math.Min(45.0 / width, 45.0 / height));
                bool isSimPortrait = reference.Columns == 3 || reference.Rows == 3 ||
                                     (reference.Columns == 4 && reference.Rows == 3) ||
                                     ((int)Math.Round(width, MidpointRounding.AwayFromZero) == 35 &&
                                      (int)Math.Round(height, MidpointRounding.AwayFromZero) == 41);
                if (isSimPortrait)
                {
                    parts.Add(new Part(ActivePeople, actionRect, new Vector4(0f, 0f, 0.25f, 1f)));
                }
                else if (width * scale < 45.0 || height * scale < 45.0)
                {
                    parts.Add(new Part(_thumbTemplate, actionRect, new Vector4(0f, 0f, 0.25f, 1f)));
                }

                // 1x3 portrait sheets store the neutral face in row 1; 4x3 fallback sheets use row 0.
                float row = reference.Columns == 1 && reference.Rows == 3 ? 1f : 0f;
                parts.Add(new Part(
                    image,
                    new CGRect(
                        MidX(actionRect) - width * scale / 2.0,
                        MidY(actionRect) - height * scale / 2.0,
                        width * scale,
                        height * scale),
                    new Vector4(0f, row / reference.Rows, 1f / reference.Columns, 1f / reference.Rows)));
            }
            else
            {
                parts.Add(new Part(_catalogUnknown, actionRect, new Vector4(0f, 0f, 0.5f, 1f)));
            }

            parts.Add(new Part(_iconFrame, actionRect, new Vector4(action.Active ? 0.5f : 0f, 0f, 0.5f, 1f)));
            if (IsActionCancelRequested(action))
            {
                parts.Add(new Part(_cancel, actionRect));
            }
        }

        AppendPluginHudWidgets(canvas, top, panelMinimized, parts);

        if (!panelMinimized &&
            (_motivePopupIndex is not null || _personalityPopupTrait is not null || _zodiacPopupActive ||
             RelationshipPopupId is not null || SkillPopupIndex is not null || _housePopupIndex is not null ||
             _careerSummaryPopupIndex is not null) &&
            _personalityPopupTitle is { } popupTitle)
        {
            var bodyFont = LivePopupBodyFont;
            int height = Math.Max(PersonalityPopup.MinimumHeight, 24 + Font.LineHeight + bodyFont.LineHeight * _personalityPopupLines.Length);
            double bottomOffset = RelationshipPopupId is null ? 100.0 : 150.0;
            double fallbackMidX = Math.Min(canvas.Width - PersonalityPopup.Width / 2.0 - 8.0, 620.0);
            double popupX = OriginalUIScalingLayout.LivePopupOriginX(
                _livePopupAnchorMidX ?? fallbackMidX,
                canvas.Width,
                PersonalityPopup.Width);
            var rect = new CGRect(popupX, canvas.Height - bottomOffset - height, PersonalityPopup.Width, height);
            if (SimsBitmapFont.SharpTextEnabled)
            {
                var vecPopup = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderPopupInfoFrame(
                    Math.Max(32, (int)Math.Round(rect.Width)),
                    Math.Max(32, (int)Math.Round(rect.Height)),
                    scale: 4));
                parts.Add(new Part(vecPopup, rect));
            }
            else
            {
                const double edge = 12.0;
                double[] xs = [rect.X, rect.X + edge, rect.X + rect.Width - edge, rect.X + rect.Width];
                double[] ys = [rect.Y, rect.Y + edge, rect.Y + rect.Height - edge, rect.Y + rect.Height];
                float[] uv = [0f, 1f / 3f, 2f / 3f, 1f];

                for (int row = 0; row < 3; row++)
                {
                    for (int column = 0; column < 3; column++)
                    {
                        parts.Add(new Part(
                            _livePopupBackground,
                            new CGRect(xs[column], ys[row], xs[column + 1] - xs[column], ys[row + 1] - ys[row]),
                            new Vector4(uv[column], uv[row], uv[column + 1] - uv[column], uv[row + 1] - uv[row])));
                    }
                }
            }

            if (_personalityPopupPortrait is (var portrait, var reference))
            {
                var frameRect = new CGRect(Math.Floor(rect.X + (168.0 - 45.0) / 2.0), Math.Floor(MidY(rect) - 22.5), 45, 45);
                parts.Add(new Part(ActivePeople, frameRect, new Vector4(0f, 0f, 0.25f, 1f)));
                var faceSize = new CGSize(portrait.Size.Width / reference.Columns, portrait.Size.Height / reference.Rows);
                int mood = State?.Selected?.Mood ?? 0;
                int expression = reference.Columns >= 3 ? (mood > 30 ? 1 : mood < -30 ? 2 : 0) : 0;
                parts.Add(new Part(
                    portrait,
                    new CGRect(
                        Math.Floor(MidX(frameRect) - faceSize.Width / 2.0),
                        Math.Floor(MidY(frameRect) - faceSize.Height / 2.0),
                        faceSize.Width,
                        faceSize.Height),
                    new Vector4((float)expression / reference.Columns, 0f, 1f / reference.Columns, 1f / reference.Rows)));
            }

            double textX = rect.X + (_personalityPopupPortrait is not null ? PersonalityPopup.TextLeft : 15);
            double bodyStartY = rect.Y + 12.0 + Font.LineHeight;
            parts.Add(new Part(popupTitle, new CGRect(textX, rect.Y + 12.0, popupTitle.Size.Width, popupTitle.Size.Height)));
            for (int index = 0; index < _personalityPopupLines.Length; index++)
            {
                var line = _personalityPopupLines[index];
                parts.Add(new Part(line, new CGRect(textX, bodyStartY + index * bodyFont.LineHeight, line.Size.Width, line.Size.Height)));
            }
        }

        return parts;
    }

    public IReadOnlyList<Part> TooltipParts(CGSize canvas)
    {
        string? currentIdentity = CurrentTooltipIdentity;
        if (_suppressedTooltipIdentity is { } suppressed)
        {
            if (string.Equals(currentIdentity, suppressed, StringComparison.Ordinal))
            {
                return [];
            }

            _suppressedTooltipIdentity = null;
        }

        double top = canvas.Height - 150.0;
        if (_hoveredInventoryTile is { } invIndex && State?.Selected?.Inventory is { } values)
        {
            var items = OriginalGameplayLayout.InventoryItems(values, InventorySort);
            int capacity = StripInventoryCapacity;
            int itemIndex = InventoryPage * capacity + invIndex;
            if (itemIndex < 0 || itemIndex >= items.Count || invIndex >= capacity)
            {
                return [];
            }

            var item = items[itemIndex];
            string itemTitle = item.Name ?? $"Unknown Item ({item.Guid})";
            string itemDesc = item.Description ?? string.Empty;
            string text;
            if (HasVisibleTooltipText(itemTitle) && HasVisibleTooltipText(itemDesc))
            {
                text = $"{itemTitle}\n{itemDesc}";
            }
            else if (HasVisibleTooltipText(itemTitle))
            {
                text = itemTitle;
            }
            else if (HasVisibleTooltipText(itemDesc))
            {
                text = itemDesc;
            }
            else
            {
                return [];
            }

            if (PlacementTooltip.Progress(ref _inventoryHoverStartedAt, _quickTips) is not { } progress)
            {
                return [];
            }

            Image tooltip;
            if (_inventoryTooltipCache is { } cached && string.Equals(cached.Text, text, StringComparison.Ordinal))
            {
                tooltip = cached.Image;
            }
            else
            {
                try
                {
                    tooltip = CreateImage(Device, PlacementTooltip.RasterizeHiDpi(text, _careerFont));
                    _inventoryTooltipCache = (text, tooltip);
                }
                catch
                {
                    return [];
                }
            }

            var tileRect = Offset(InventoryTileRect(invIndex), 0, top);
            return
            [
                Grown(new Part(tooltip, PlacementTooltip.Rect(tooltip.Size, new CGPoint(MidX(tileRect), tileRect.Y - 1.0), canvas)), progress)
            ];
        }

        if (_hoveredPeopleTip is { } peopleTip && HasVisibleTooltipText(peopleTip.Text))
        {
            if (PlacementTooltip.Progress(ref _pluginWidgetHoverStartedAt, _quickTips) is not { } progress)
            {
                return [];
            }

            if (CachedTooltipImage(_peopleTips, peopleTip.Text) is not { } tooltip)
            {
                return [];
            }

            return
            [
                Grown(new Part(tooltip, PlacementTooltip.Rect(tooltip.Size, new CGPoint(MidX(peopleTip.Rect), peopleTip.Rect.Y - 1.0), canvas)), progress)
            ];
        }

        if (_hoveredPerson is { } person && HasVisibleTooltipText(person.Name))
        {
            if (PlacementTooltip.Progress(ref _personHoverStartedAt, _quickTips) is not { } progress)
            {
                return [];
            }

            if (CachedTooltipImage(_personTips, person.Name) is not { } tooltip)
            {
                return [];
            }

            return
            [
                Grown(new Part(tooltip, PlacementTooltip.Rect(tooltip.Size, new CGPoint(MidX(person.Rect), person.Rect.Y - 1.0), canvas)), progress)
            ];
        }

        if (_panelTip is { } panelTip)
        {
            string text = _strings.PanelTip(panelTip.Index, string.Empty);
            if (!HasVisibleTooltipText(text))
            {
                return [];
            }

            if (PlacementTooltip.Progress(ref _pluginWidgetHoverStartedAt, _quickTips) is not { } progress)
            {
                return [];
            }

            if (!_panelTips.TryGetValue(panelTip.Index, out var tooltip))
            {
                try
                {
                    tooltip = CreateImage(Device, PlacementTooltip.RasterizeHiDpi(text, _careerFont));
                    _panelTips[panelTip.Index] = tooltip;
                }
                catch
                {
                    return [];
                }
            }

            return
            [
                Grown(new Part(tooltip, PlacementTooltip.Rect(tooltip.Size, new CGPoint(MidX(panelTip.Rect), panelTip.Rect.Y - 1.0), canvas)), progress)
            ];
        }

        if (_hoveredPluginWidget is { } hoveredWidget &&
            FindPluginHudWidget(hoveredWidget.PackId, hoveredWidget.WidgetId) is { Tooltip.Length: > 0 } widget)
        {
            if (PlacementTooltip.Progress(ref _pluginWidgetHoverStartedAt, _quickTips) is { } progress)
            {
                string cacheKey = $"{widget.PackId}:{widget.WidgetId}";
                if (!_pluginTooltips.TryGetValue(cacheKey, out var cached) ||
                    !string.Equals(cached.Text, widget.Tooltip, StringComparison.Ordinal))
                {
                    cached = (widget.Tooltip!, CreateImage(Device, PlacementTooltip.RasterizeHiDpi(widget.Tooltip!, _careerFont)));
                    _pluginTooltips[cacheKey] = cached;
                }
                var control = ResolvePluginWidgetRect(widget, canvas, top);
                return
                [
                    Grown(new Part(cached.Image, PlacementTooltip.Rect(cached.Image.Size, new CGPoint(MidX(control), control.Y - 1.0), canvas)), progress)
                ];
            }
        }

        return [];
    }

    public IReadOnlyList<(string Label, CGRect Rect)> Controls(CGSize canvas, bool panelMinimized = false)
    {
        TryPrepare(canvas);
        double now = MonotonicNowSeconds();
        int maxQueue = Math.Min(_queued.Count, Math.Max(0, (int)((canvas.Width - 32.0) / 50.0)));
        var queueControls = new List<(string Label, CGRect Rect)>();
        for (int index = 0; index < maxQueue; index++)
        {
            var action = _queued[index].Action;
            if (!IsActionCancelRequested(action) && action.Cancellable)
            {
                queueControls.Add(("Cancel " + (action.Name ?? "action"), CurrentActionRect(index, now)));
            }
        }

        if (panelMinimized)
        {
            return queueControls;
        }

        double top = canvas.Height - 150.0;
        var controls = new List<(string Label, CGRect Rect)>();

        if (State?.Household is { } household)
        {
            int count = Math.Min(OriginalGameplayLayout.MaxHouseholdPortraits, household.Count);
            for (int offset = 0; offset < count; offset++)
            {
                var sim = household[offset];
                var portraitRect = Offset(OriginalGameplayLayout.Portrait(offset), 0, top);
                controls.Add(("Select " + sim.Name, portraitRect));
                if (!string.IsNullOrEmpty(sim.InternalName) &&
                    !string.Equals(sim.InternalName, sim.Name, StringComparison.OrdinalIgnoreCase))
                {
                    controls.Add(("Select " + sim.InternalName, portraitRect));
                }
            }
        }

        controls.AddRange(queueControls);

        var supportedPanels = new List<Subpanel>();
        foreach (var panel in MainTabSubpanels)
        {
            if (Supports(panel, State))
            {
                supportedPanels.Add(panel);
            }
        }

        foreach (var panel in supportedPanels)
        {
            controls.Add((_strings.PeoplePanelTip(panel.ButtonIndex(), State?.Selected, panel.Label()), Offset(ButtonRect(panel.ButtonIndex()), 0, top)));
        }

        foreach (var panel in supportedPanels)
        {
            controls.Add(("Show " + panel.Label(), Offset(ButtonRect(panel.ButtonIndex()), 0, top)));
        }

        if (CurrentSubpanel == Subpanel.Career && Supports(Subpanel.ReportCard, State))
        {
            var careerLayout = OriginalGameplayLayout.GetCareerSubpanelLayout(_grid.Width, _asianInventoryLayout);
            controls.Add((_strings.ReportCardLabel(), Offset(careerLayout.ReportCardRect, 0, top)));
        }

        if (CurrentSubpanel == Subpanel.Career && State?.Selected?.Career is { } career)
        {
            var careerLayout = OriginalGameplayLayout.GetCareerSubpanelLayout(_grid.Width, _asianInventoryLayout);
            controls.Add(("Job summary", Offset(careerLayout.JobSummaryRect, 0, top)));
            controls.Add(("Salary summary", Offset(careerLayout.SalaryRect, 0, top)));
            controls.Add(("Performance summary", Offset(careerLayout.PerformanceRect, 0, top)));
            if (career.FriendsNeeded is not null)
            {
                controls.Add(("Friends needed summary", Offset(careerLayout.FriendsRect, 0, top)));
            }

            for (int index = 0; index < OriginalGameplayLayout.Skills.Count && index < careerLayout.Skills.Count; index++)
            {
                controls.Add(("Skill " + OriginalGameplayLayout.Skills[index], Offset(careerLayout.Skills[index].Label, 0, top)));
            }
        }
        else if (CurrentSubpanel == Subpanel.House)
        {
            var houseLayout = OriginalGameplayLayout.GetHouseSubpanelLayout(_grid.Width, _asianInventoryLayout);
            string[] scoreNames = ["Size", "Furnishings", "Yard", "Upkeep", "Layout"];
            for (int index = 0; index < scoreNames.Length && index < houseLayout.ScoreBars.Count; index++)
            {
                controls.Add(("House " + scoreNames[index], Offset(houseLayout.ScoreBars[index], 0, top)));
            }

            string[] infoNames = ["Sq. Ft.", "Bedrooms", "Bathrooms", "Lot"];
            for (int index = 0; index < infoNames.Length && index < houseLayout.InfoRects.Count; index++)
            {
                controls.Add(("House " + infoNames[index], Offset(houseLayout.InfoRects[index], 0, top)));
            }
        }
        else if (CurrentSubpanel == Subpanel.Fame)
        {
            var fameLayout = OriginalGameplayLayout.GetFameSubpanelLayout(_grid.Width, _asianInventoryLayout);
            controls.Add(("Fame level", Offset(fameLayout.StarBar, 0, top)));
            controls.Add(("Fame friends", Offset(fameLayout.FriendsRect, 0, top)));
            for (int index = 0; index < OriginalGameplayLayout.Skills.Count && index < fameLayout.Skills.Count; index++)
            {
                controls.Add(("Skill " + OriginalGameplayLayout.Skills[index], Offset(fameLayout.Skills[index].Label, 0, top)));
            }
        }
        else if (CurrentSubpanel == Subpanel.PetSkills)
        {
            var (_, petSkillSlots) = OriginalGameplayLayout.PetSkillsSubpanelLayout(_grid.Width);
            for (int index = 0; index < OriginalGameplayLayout.PetSkills.Count && index < petSkillSlots.Count; index++)
            {
                controls.Add(("Pet skill " + OriginalGameplayLayout.PetSkills[index], Offset(petSkillSlots[index].Label, 0, top)));
            }
        }
        else if (CurrentSubpanel == Subpanel.Personality && State?.Selected is { } selected && selected.Personality is not null)
        {
            bool isPet = ((selected.Gender ?? 0) & 6) != 0;
            var activeTraitLabels = isPet ? _petTraitLabels : _traitLabels;
            int labelWidth = MaxImageWidth(activeTraitLabels);
            var personalityLayout = OriginalGameplayLayout.PersonalitySubpanelLayout(_grid.Width, labelWidth, _asianInventoryLayout);
            for (int index = 0; index < OriginalGameplayLayout.Traits.Count && index < personalityLayout.TraitRects.Count; index++)
            {
                controls.Add(("Trait " + OriginalGameplayLayout.Traits[index], Offset(personalityLayout.TraitRects[index], 0, top)));
            }
        }

        if (CurrentSubpanel == Subpanel.Relationships)
        {
            var allFilters = Enum.GetValues<OriginalGameplayLayout.RelationshipFilter>();
            for (int index = 0; index < allFilters.Length; index++)
            {
                controls.Add((_strings.RelationshipFilterTip(index, string.Empty), Offset(RelationshipFilterRect(index), 0, top)));
            }

            for (int index = 0; index < allFilters.Length; index++)
            {
                controls.Add(($"Filter {RelationshipFilterName(allFilters[index])} relationships", Offset(RelationshipFilterRect(index), 0, top)));
            }

            var relationships = OriginalGameplayLayout.Relationships(State?.Selected?.Relationships ?? [], RelationshipFilter);
            int capacity = StripRelationshipCapacity;
            int slot = 0;
            foreach (var rel in relationships.Skip(RelationshipPage * capacity).Take(capacity))
            {
                controls.Add((rel.Name, Offset(RelationshipSlotRect(slot++), 0, top)));
            }

            if (RelationshipPage > 0)
            {
                var arrowRect = Offset(RelationshipArrowRect(false), 0, top);
                controls.Add((_strings.PeoplePageTip(0, "Previous relationships page"), arrowRect));
                controls.Add(("Previous relationships page", arrowRect));
            }

            if ((RelationshipPage + 1) * capacity < relationships.Count)
            {
                var arrowRect = Offset(RelationshipArrowRect(true), 0, top);
                controls.Add((_strings.PeoplePageTip(1, "Next relationships page"), arrowRect));
                controls.Add(("Next relationships page", arrowRect));
            }
        }
        else if (CurrentSubpanel == Subpanel.Inventory && State?.Selected?.Inventory is { } invValues)
        {
            var allSorts = Enum.GetValues<OriginalGameplayLayout.InventorySort>();
            for (int index = 0; index < allSorts.Length; index++)
            {
                int tipIndex = allSorts[index] switch
                {
                    OriginalGameplayLayout.InventorySort.Gift => 0,
                    OriginalGameplayLayout.InventorySort.Magic => 1,
                    _ => 2
                };
                controls.Add((_strings.InventorySortTip(tipIndex, "Show " + InventorySortName(allSorts[index]) + " inventory"), Offset(InventorySortRect(index), 0, top)));
            }

            for (int index = 0; index < allSorts.Length; index++)
            {
                controls.Add(("Show " + InventorySortName(allSorts[index]) + " inventory", Offset(InventorySortRect(index), 0, top)));
            }

            var items = OriginalGameplayLayout.InventoryItems(invValues, InventorySort);
            int capacity = StripInventoryCapacity;
            int slot = 0;
            foreach (var item in items.Skip(InventoryPage * capacity).Take(capacity))
            {
                controls.Add(($"{item.Name ?? "Item"} x{item.Count}", Offset(InventoryTileRect(slot++), 0, top)));
            }

            if (InventoryPage > 0)
            {
                var arrowRect = Offset(InventoryArrowRect(false), 0, top);
                controls.Add((_strings.PeoplePageTip(0, "Previous inventory page"), arrowRect));
                controls.Add(("Previous inventory page", arrowRect));
            }

            if ((InventoryPage + 1) * capacity < items.Count)
            {
                var arrowRect = Offset(InventoryArrowRect(true), 0, top);
                controls.Add((_strings.PeoplePageTip(1, "Next inventory page"), arrowRect));
                controls.Add(("Next inventory page", arrowRect));
            }
        }
        else if (CurrentSubpanel == Subpanel.Interests && State?.Selected?.Career is { } interestCareer)
        {
            var indices = OriginalGameplayLayout.InterestIndices(interestCareer.Age);
            int capacity = StripInterestCapacity;
            int slot = 0;
            foreach (int interestIndex in indices.Skip(InterestPage * capacity).Take(capacity))
            {
                controls.Add((_strings.InterestTip(interestIndex, OriginalGameplayLayout.Interests[interestIndex]), Offset(InterestSlotRect(slot++), 0, top)));
            }

            if (InterestPage > 0)
            {
                var arrowRect = Offset(InterestArrowRect(false), 0, top);
                controls.Add((_strings.PeoplePageTip(0, "Previous interests page"), arrowRect));
                controls.Add(("Previous interests page", arrowRect));
            }

            if ((InterestPage + 1) * capacity < indices.Count)
            {
                var arrowRect = Offset(InterestArrowRect(true), 0, top);
                controls.Add((_strings.PeoplePageTip(1, "Next interests page"), arrowRect));
                controls.Add(("Next interests page", arrowRect));
            }
        }

        for (int i = 0; i < PluginHudWidgets.Count; i++)
        {
            var widget = PluginHudWidgets[i];
            if (panelMinimized && widget.Anchor == SimsNative.Plugins.PluginHudAnchor.ControlPanel && widget.Rect.X >= 220.0)
                continue;
            controls.Add((widget.WidgetId, ResolvePluginWidgetRect(widget, canvas, top)));
        }

        return controls;
    }

    public CGRect? TutorialButtonForImage(int imageId, CGSize canvas)
    {
        foreach (var panel in MainTabSubpanels)
        {
            if (panel.ImageId() == imageId && Supports(panel, State))
            {
                return Offset(ButtonRect(panel.ButtonIndex()), 0, canvas.Height - 150.0);
            }
        }

        return null;
    }

    public CGRect? TutorialButtonForSim(int simId, CGSize canvas)
    {
        if (State?.Household is not { } household)
        {
            return null;
        }

        int count = Math.Min(OriginalGameplayLayout.MaxHouseholdPortraits, household.Count);
        for (int index = 0; index < count; index++)
        {
            if (household[index].Id == simId)
            {
                return Offset(OriginalGameplayLayout.Portrait(index), 0, canvas.Height - 150.0);
            }
        }

        return null;
    }

    public CGRect? TutorialButtonForRelationship(int neighborId, CGSize canvas)
    {
        TryPrepare(canvas);
        if (CurrentSubpanel != Subpanel.Relationships)
        {
            return null;
        }

        var relationships = OriginalGameplayLayout.Relationships(State?.Selected?.Relationships ?? [], RelationshipFilter);
        int capacity = StripRelationshipCapacity;
        int slot = 0;
        foreach (var relationship in relationships.Skip(RelationshipPage * capacity).Take(capacity))
        {
            if (relationship.NeighborId == neighborId)
            {
                return Offset(RelationshipSlotRect(slot), 0, canvas.Height - 150.0);
            }

            slot++;
        }

        return null;
    }

    public int? Selection(CGPoint point, CGSize canvas)
    {
        if (State?.Household is not { } household)
        {
            return null;
        }

        double top = canvas.Height - 150.0;
        int count = Math.Min(OriginalGameplayLayout.MaxHouseholdPortraits, household.Count);
        for (int index = 0; index < count; index++)
        {
            if (Contains(Offset(OriginalGameplayLayout.Portrait(index), 0, top), point))
            {
                return household[index].Id;
            }
        }

        return null;
    }

    public void UpdatePersonHover(CGPoint point, CGSize canvas)
    {
        if (State?.Household is not { } household)
        {
            HoveredPerson = null;
            return;
        }

        double top = canvas.Height - 150.0;
        int count = Math.Min(OriginalGameplayLayout.MaxHouseholdPortraits, household.Count);
        for (int index = 0; index < count; index++)
        {
            var rect = Offset(OriginalGameplayLayout.Portrait(index), 0, top);
            if (Contains(rect, point))
            {
                var sim = household[index];
                string tip = sim.TooltipName ?? sim.Name;
                HoveredPerson = (sim.Id, tip, rect);
                return;
            }
        }

        HoveredPerson = null;
    }

    public CGRect CurrentActionRect(int index, double? now = null)
    {
        var slotRect = OriginalGameplayLayout.Action(index);
        if (index < 0 || index >= _queued.Count || !InterfaceEffects ||
            !_actionAnimations.TryGetValue(_queued[index].Action.Token, out var anim))
        {
            return slotRect;
        }

        var origin = anim.CurrentOrigin(now ?? MonotonicNowSeconds());
        return new CGRect(origin.X, origin.Y, slotRect.Width, slotRect.Height);
    }

    public void MarkActionCancelRequested(string token)
    {
        ArgumentNullException.ThrowIfNull(token);
        _optimisticCancelledTokens.Add(token);
    }

    public int? HoveredActionIndex(CGPoint point, CGSize canvas)
    {
        double now = MonotonicNowSeconds();
        int maxQueue = Math.Min(_queued.Count, Math.Max(0, (int)((canvas.Width - 32.0) / 50.0)));
        for (int index = 0; index < maxQueue; index++)
        {
            if (Contains(CurrentActionRect(index, now), point))
            {
                return index;
            }
        }

        return null;
    }

    public string? Cancellation(CGPoint point, CGSize canvas)
    {
        double now = MonotonicNowSeconds();
        int maxQueue = Math.Min(_queued.Count, Math.Max(0, (int)((canvas.Width - 32.0) / 50.0)));
        for (int index = 0; index < maxQueue; index++)
        {
            var action = _queued[index].Action;
            if (!IsActionCancelRequested(action) && action.Cancellable && Contains(CurrentActionRect(index, now), point))
            {
                return action.Token;
            }
        }

        return null;
    }

    public bool HasUncancellableAction(CGPoint point, CGSize canvas)
    {
        double now = MonotonicNowSeconds();
        int maxQueue = Math.Min(_queued.Count, Math.Max(0, (int)((canvas.Width - 32.0) / 50.0)));
        for (int index = 0; index < maxQueue; index++)
        {
            var action = _queued[index].Action;
            if (!IsActionCancelRequested(action) && !action.Cancellable && Contains(CurrentActionRect(index, now), point))
            {
                return true;
            }
        }

        return false;
    }

    public double ActivePanelRightEdge(CGSize canvas) => canvas.Width;

    public static bool ContainsPanel(CGPoint point, CGSize canvas, bool panelMinimized = false)
    {
        if (panelMinimized)
        {
            return Contains(new CGRect(0, canvas.Height - 183, 220, 183), point);
        }

        return (point.Y >= canvas.Height - 100 && point.X >= 0 && point.X <= canvas.Width) ||
               Contains(new CGRect(0, canvas.Height - 183, 220, 183), point) ||
               Contains(new CGRect(220, canvas.Height - 150, 193, 150), point);
    }

    public bool ContainsPanelPoint(CGPoint point, CGSize canvas, bool panelMinimized = false) =>
        ContainsPanel(point, canvas, panelMinimized);

    private double ClassicStripOffset => 0.0;

    private SimsSDL.Client.ClientPluginHost.HudWidget? FindPluginHudWidget(string packId, string widgetId)
    {
        for (int i = 0; i < PluginHudWidgets.Count; i++)
        {
            var w = PluginHudWidgets[i];
            if (string.Equals(w.PackId, packId, StringComparison.Ordinal) &&
                string.Equals(w.WidgetId, widgetId, StringComparison.Ordinal))
                return w;
        }
        return null;
    }

    private static CGRect ResolvePluginWidgetRect(SimsSDL.Client.ClientPluginHost.HudWidget widget, CGSize canvas, double panelTop) =>
        widget.Anchor switch
        {
            SimsNative.Plugins.PluginHudAnchor.ControlPanel => Offset(widget.Rect, 0, panelTop),
            SimsNative.Plugins.PluginHudAnchor.ScreenTopRight => new CGRect(canvas.Width - widget.Rect.X - widget.Rect.Width, widget.Rect.Y, widget.Rect.Width, widget.Rect.Height),
            SimsNative.Plugins.PluginHudAnchor.ScreenTopCenter => new CGRect((canvas.Width - widget.Rect.Width) * 0.5 + widget.Rect.X, widget.Rect.Y, widget.Rect.Width, widget.Rect.Height),
            _ => widget.Rect,
        };

    public (string PackId, string WidgetId)? PluginWidgetAt(CGPoint point, CGSize canvas, bool panelMinimized = false)
    {
        double top = canvas.Height - 150.0;
        for (int i = PluginHudWidgets.Count - 1; i >= 0; i--)
        {
            var w = PluginHudWidgets[i];
            if (panelMinimized && w.Anchor == SimsNative.Plugins.PluginHudAnchor.ControlPanel && w.Rect.X >= 220.0)
                continue;
            if (Contains(ResolvePluginWidgetRect(w, canvas, top), point))
                return (w.PackId, w.WidgetId);
        }
        return null;
    }

    private string? CurrentTooltipIdentity
    {
        get
        {
            if (_hoveredInventoryTile is { } index)
            {
                return $"inv:{InventorySortName(InventorySort)}:{InventoryPage}:{index}";
            }

            if (_hoveredPeopleTip is { } tip && HasVisibleTooltipText(tip.Text))
            {
                return $"people:{tip.Text}:{(int)Math.Round(tip.Rect.X, MidpointRounding.AwayFromZero)}:{(int)Math.Round(tip.Rect.Y, MidpointRounding.AwayFromZero)}";
            }

            if (_hoveredPerson is { } person && HasVisibleTooltipText(person.Name))
            {
                return $"person:{person.Id}";
            }

            if (_panelTip is { } panelTip && HasVisibleTooltipText(_strings.PanelTip(panelTip.Index, string.Empty)))
            {
                return $"panel:{panelTip.Index}";
            }

            if (_hoveredPluginWidget is { } hw && FindPluginHudWidget(hw.PackId, hw.WidgetId) is { Tooltip.Length: > 0 })
            {
                return $"plugin:{hw.PackId}:{hw.WidgetId}";
            }

            return null;
        }
    }

    private CGPoint StripHeaderOrigin() => OriginalGameplayLayout.InventoryTitle(_asianInventoryLayout);
    private CGRect RelationshipFilterRect(int index) => OriginalGameplayLayout.RelationshipFilterRect(index);
    private CGRect RelationshipSlotRect(int index) => OriginalGameplayLayout.Relationship(index);
    private CGRect RelationshipArrowRect(bool next) => _grid.RelationshipArrow(next);
    private CGRect InventorySortRect(int index) => OriginalGameplayLayout.InventorySortButton(index, _asianInventoryLayout);
    private CGRect InventoryTileRect(int index) => OriginalGameplayLayout.InventoryTile(index, _asianInventoryLayout);
    private CGRect InventoryArrowRect(bool next) => OriginalGameplayLayout.InventoryArrow(next, _grid.Width, _asianInventoryLayout);
    private CGRect InterestSlotRect(int index) => _grid.Interest(index);
    private CGRect InterestArrowRect(bool next) => _grid.InterestArrow(next);
    private CGRect ButtonRect(int index) => new(_buttonPositions[index].X, _buttonPositions[index].Y, _buttons[index].Size.Width / 4.0, _buttons[index].Size.Height);

    private bool IsActionCancelRequested(GameplayPanelState.Action action) =>
        action.CancelRequested || _optimisticCancelledTokens.Contains(action.Token);

    private void TryPrepare(CGSize canvas)
    {
        try
        {
            Prepare(canvas);
        }
        catch
        {
        }
    }

    private void AppendBevelDivider(double x, List<Part> parts) =>
        parts.Add(new Part(_bevelDivider, new CGRect(x, 55, 2, 89)));

    private void AppendBayDividers(OriginalGameplayLayout.CenteredSubpanelBay bay, List<Part> parts)
    {
        if (bay.DividerLeftX is { } leftX)
        {
            AppendBevelDivider(leftX, parts);
        }

        if (bay.DividerRightX is { } rightX)
        {
            AppendBevelDivider(rightX, parts);
        }
    }

    private void AppendHouseParts(GameplayPanelState.HousePanel values, List<Part> parts)
    {
        var layout = OriginalGameplayLayout.GetHouseSubpanelLayout(_grid.Width, _asianInventoryLayout);
        var header = Text(_strings.HouseLabel(0, "House"), _careerFont, Device);
        parts.Add(new Part(header, new CGRect(layout.HeaderOrigin.X, layout.HeaderOrigin.Y, header.Size.Width, header.Size.Height)));

        int?[] scores = [values.SizeScore, values.FurnishingsScore, values.YardScore, values.UpkeepScore, values.LayoutScore];
        string[] fallbacks = ["Size", "Furnishings", "Yard", "Upkeep", "Layout"];
        for (int index = 0; index < scores.Length; index++)
        {
            var label = Text(_strings.HouseLabel(index + 1, fallbacks[index]), _careerFont, Device);
            double y = layout.ScoreLabelYs[index];
            double labelX = layout.ScoreLabelRightXs[index] - label.Size.Width;
            parts.Add(new Part(label, new CGRect(labelX, y, label.Size.Width, label.Size.Height)));
            var barRect = layout.ScoreBars[index];
            parts.Add(new Part(_houseBarsOff, barRect));
            if (scores[index] is { } score)
            {
                int barW = Math.Min(10, Math.Max(0, score / 10)) * 4;
                if (barW > 0)
                {
                    parts.Add(new Part(_personalityBars, new CGRect(barRect.X, barRect.Y, barW, barRect.Height), new Vector4(0f, 0f, barW / 40f, 1f)));
                }
            }
        }

        if (values.SquareFeet is { } squareFeet)
        {
            var textImg = Text(FormatHouseCount(_strings.HouseLabel(6, "Sq. Ft.: %d"), squareFeet), _careerFont, Device);
            parts.Add(new Part(textImg, new CGRect(layout.InfoRects[0].X, layout.InfoRects[0].Y, textImg.Size.Width, textImg.Size.Height)));
        }

        if (values.Bedrooms is { } bedrooms)
        {
            var textImg = Text(FormatHouseCount(_strings.HouseLabel(7, "Bedrooms: %d"), bedrooms), _careerFont, Device);
            parts.Add(new Part(textImg, new CGRect(layout.InfoRects[1].X, layout.InfoRects[1].Y, textImg.Size.Width, textImg.Size.Height)));
        }

        if (values.Bathrooms is { } bathrooms)
        {
            var textImg = Text(FormatHouseCount(_strings.HouseLabel(8, "Bathrooms: %d"), bathrooms), _careerFont, Device);
            parts.Add(new Part(textImg, new CGRect(layout.InfoRects[2].X, layout.InfoRects[2].Y, textImg.Size.Width, textImg.Size.Height)));
        }

        if (values.LotSize is { } lotSize)
        {
            var textImg = Text(FormatHouseLot(lotSize), _careerFont, Device);
            parts.Add(new Part(textImg, new CGRect(layout.InfoRects[3].X, layout.InfoRects[3].Y, textImg.Size.Width, textImg.Size.Height)));
        }
    }

    private string FormatHouseLot(int lotSize)
    {
        string[] fallbackSizes = ["Small", "Medium", "Large"];
        string fallback = lotSize >= 0 && lotSize < fallbackSizes.Length ? fallbackSizes[lotSize] : "Large";
        string sizeName = _strings.HouseLotSize(lotSize, fallback);
        string format = _strings.HouseLabel(9, "Lot: %@");
        return format.Replace("%s", sizeName, StringComparison.Ordinal).Replace("%@", sizeName, StringComparison.Ordinal);
    }

    private static string FormatHouseCount(string format, int value) =>
        format.Replace("%d", value.ToString(CultureInfo.InvariantCulture), StringComparison.Ordinal);

    private void AppendPluginHudWidgets(CGSize canvas, double top, bool panelMinimized, List<Part> parts)
    {
        for (int i = 0; i < PluginHudWidgets.Count; i++)
        {
            var widget = PluginHudWidgets[i];
            if (panelMinimized && widget.Anchor == SimsNative.Plugins.PluginHudAnchor.ControlPanel && widget.Rect.X >= 220.0)
                continue;
            var rect = ResolvePluginWidgetRect(widget, canvas, top);
            parts.Add(new Part(widget.Image, rect, new Vector4(0f, 0f, 1f, 1f), widget.Opacity));
        }
    }

    private void UpdateMotiveTracking(GameplayPanelState next, string resolvedRoot, ulong nowMs)
    {
        int motiveCount = OriginalGameplayLayout.Motives.Count;
        var nextHouseholdIds = new HashSet<int>();
        foreach (var sim in next.Household)
        {
            nextHouseholdIds.Add(sim.Id);
        }

        int simMinute = next.Hours * 60 + next.Minutes;
        bool clockReset = _lastSampledSimMinute is { } prevMin && (simMinute - prevMin + 1440) % 1440 > 60;

        if ((_resourceRoot is not null && !PathsEqual(_resourceRoot, resolvedRoot)) ||
            nextHouseholdIds.Count == 0 ||
            (_trackedHouseholdSimIds.Count > 0 && !_trackedHouseholdSimIds.Overlaps(nextHouseholdIds)) ||
            clockReset)
        {
            _motiveTrackersBySim.Clear();
            _lastSampledMotivesBySim.Clear();
            _lastSampledSimMinute = null;
            _trackedHouseholdSimIds.Clear();
            _trackedSelectedSimId = null;
            for (int index = 0; index < motiveCount; index++)
            {
                _motiveArrowsStates[index].Reset(hasTracker: false, nowMs: nowMs);
                _motiveBarStates[index] = new OriginalGameplayLayout.MotiveBarState();
            }
        }

        foreach (int id in _motiveTrackersBySim.Keys.ToArray())
        {
            if (!nextHouseholdIds.Contains(id))
            {
                _motiveTrackersBySim.Remove(id);
            }
        }

        foreach (int id in _lastSampledMotivesBySim.Keys.ToArray())
        {
            if (!nextHouseholdIds.Contains(id))
            {
                _lastSampledMotivesBySim.Remove(id);
            }
        }

        _trackedHouseholdSimIds = nextHouseholdIds;

        int[] MotiveVector(GameplayPanelState.Sim sim)
        {
            var vec = new int[motiveCount];
            for (int i = 0; i < motiveCount; i++)
            {
                int raw = sim.Motives.TryGetValue(OriginalGameplayLayout.Motives[i], out var v) ? v : 0;
                vec[i] = Math.Min(100, Math.Max(-100, raw));
            }

            return vec;
        }

        bool didSample = false;
        if (_lastSampledSimMinute is { } previousMinute)
        {
            int elapsedMinutes = (simMinute - previousMinute + 1440) % 1440;
            if (elapsedMinutes > 0)
            {
                int steps = Math.Min(elapsedMinutes, 10);
                foreach (var sim in next.Household)
                {
                    var current = MotiveVector(sim);
                    if (_motiveTrackersBySim.TryGetValue(sim.Id, out var trackers))
                    {
                        var previous = _lastSampledMotivesBySim.TryGetValue(sim.Id, out var prevVec) ? prevVec : current;
                        for (int step = 1; step <= steps; step++)
                        {
                            for (int index = 0; index < motiveCount; index++)
                            {
                                int sample = step == steps
                                    ? current[index]
                                    : OriginalGameplayLayout.MotiveRateTracker.RoundHalfAwayFromZero(
                                        previous[index] + (current[index] - previous[index]) * ((float)step / steps));
                                trackers[index].Record(sample);
                            }
                        }
                    }
                    else
                    {
                        trackers = new OriginalGameplayLayout.MotiveRateTracker[motiveCount];
                        for (int index = 0; index < motiveCount; index++)
                        {
                            trackers[index] = new OriginalGameplayLayout.MotiveRateTracker();
                            trackers[index].Record(current[index]);
                        }

                        _motiveTrackersBySim[sim.Id] = trackers;
                    }

                    _lastSampledMotivesBySim[sim.Id] = current;
                }

                _lastSampledSimMinute = simMinute;
                didSample = true;
            }
            else
            {
                foreach (var sim in next.Household)
                {
                    if (_motiveTrackersBySim.ContainsKey(sim.Id))
                    {
                        continue;
                    }

                    var current = MotiveVector(sim);
                    var trackers = new OriginalGameplayLayout.MotiveRateTracker[motiveCount];
                    for (int index = 0; index < motiveCount; index++)
                    {
                        trackers[index] = new OriginalGameplayLayout.MotiveRateTracker();
                        trackers[index].Record(current[index]);
                    }

                    _motiveTrackersBySim[sim.Id] = trackers;
                    _lastSampledMotivesBySim[sim.Id] = current;
                }
            }
        }
        else if (next.Household.Count > 0)
        {
            foreach (var sim in next.Household)
            {
                var current = MotiveVector(sim);
                var trackers = new OriginalGameplayLayout.MotiveRateTracker[motiveCount];
                for (int index = 0; index < motiveCount; index++)
                {
                    trackers[index] = new OriginalGameplayLayout.MotiveRateTracker();
                    trackers[index].Record(current[index]);
                }

                _motiveTrackersBySim[sim.Id] = trackers;
                _lastSampledMotivesBySim[sim.Id] = current;
            }

            _lastSampledSimMinute = simMinute;
            didSample = true;
        }

        if (next.Selected is { } selected)
        {
            var current = MotiveVector(selected);
            bool simChanged = _trackedSelectedSimId != selected.Id;
            _trackedSelectedSimId = selected.Id;
            _motiveTrackersBySim.TryGetValue(selected.Id, out var trackers);
            for (int index = 0; index < motiveCount; index++)
            {
                if (simChanged)
                {
                    _motiveBarStates[index].Reset(current[index], nowMs, InterfaceEffects);
                    _motiveArrowsStates[index].Reset(hasTracker: trackers is not null, nowMs: nowMs);
                    if (trackers is not null)
                    {
                        _motiveArrowsStates[index].Update(trackers[index].Rate, nowMs, InterfaceEffects);
                    }
                }
                else
                {
                    _motiveBarStates[index].SetValue(current[index], nowMs, InterfaceEffects);
                    if (didSample && trackers is not null)
                    {
                        _motiveArrowsStates[index].Update(trackers[index].Rate, nowMs, InterfaceEffects);
                    }
                }
            }
        }
        else if (_trackedSelectedSimId is not null)
        {
            _trackedSelectedSimId = null;
            for (int index = 0; index < motiveCount; index++)
            {
                _motiveArrowsStates[index].Reset(hasTracker: false, nowMs: nowMs);
            }
        }
    }

    private void AppendNeedsDynamicParts(double top, ulong nowMs, List<Part> dynamic)
    {
        const ulong pulseCacheIntervalMs = 33UL;
        ulong sampledMs = (nowMs / pulseCacheIntervalMs) * pulseCacheIntervalMs;
        int motiveCount = OriginalGameplayLayout.Motives.Count;
        for (int index = 0; index < motiveCount; index++)
        {
            var needRect = OriginalGameplayLayout.NeedRect(index, _grid.Width);
            var barEval = _motiveBarStates[index].Evaluate(sampledMs);
            int width = OriginalGameplayLayout.BarWidth(_motiveBarStates[index].Value);
            var barKey = new MotiveBarCacheKey(width, barEval.GreenRgb, barEval.RedRgb);
            Image? barImage;
            if (_cachedMotiveBars[index] is { } cachedBar && cachedBar.Key == barKey)
            {
                barImage = cachedBar.Image;
            }
            else
            {
                var green = OriginalGameplayLayout.MotiveColorRamp.UnpackRgb(barEval.GreenRgb);
                var red = OriginalGameplayLayout.MotiveColorRamp.UnpackRgb(barEval.RedRgb);
                var pixels = new byte[60 * 5 * 4];
                for (int y = 0; y < 5; y++)
                {
                    for (int x = 0; x < 60; x++)
                    {
                        var color = x < width ? green : red;
                        bool isDivider = (60 - width > 1) && (x == width - 1);
                        int offset = (y * 60 + x) * 4;
                        pixels[offset] = isDivider ? (byte)0 : color.X;
                        pixels[offset + 1] = isDivider ? (byte)0 : color.Y;
                        pixels[offset + 2] = isDivider ? (byte)0 : color.Z;
                        pixels[offset + 3] = 255;
                    }
                }

                try
                {
                    var created = CreateImage(Device, 60, 5, pixels);
                    _cachedMotiveBars[index] = (barKey, created);
                    barImage = created;
                }
                catch
                {
                    barImage = _cachedMotiveBars[index]?.Image;
                }
            }

            if (barImage is { } resolvedBar)
            {
                dynamic.Add(new Part(resolvedBar, new CGRect(needRect.X + 20.0, needRect.Y + 12.0 + top, 60.0, 5.0)));
            }

            var arrowEval = _motiveArrowsStates[index].Evaluate(sampledMs);
            if (!arrowEval.Visible || arrowEval.Colors.Count != 5)
            {
                continue;
            }

            var stripKey = new MotiveArrowStripCacheKey(
                arrowEval.Rising,
                arrowEval.Colors[0],
                arrowEval.Colors[1],
                arrowEval.Colors[2],
                arrowEval.Colors[3],
                arrowEval.Colors[4]);
            Image? stripImage;
            if (_cachedMotiveArrowStrips[index] is { } cachedStrip && cachedStrip.Key == stripKey)
            {
                stripImage = cachedStrip.Image;
            }
            else
            {
                var pixels = new byte[19 * 5 * 4];
                var localStrip = OriginalGameplayLayout.MotiveArrowStripRect(new CGRect(0, 0, 0, 0), arrowEval.Rising);
                for (int arrowIndex = 0; arrowIndex < 5; arrowIndex++)
                {
                    uint colorRgb = arrowEval.Colors[arrowIndex];
                    if (colorRgb == OriginalGameplayLayout.MotiveArrowBackgroundRgb)
                    {
                        continue;
                    }

                    var rgb = OriginalGameplayLayout.MotiveColorRamp.UnpackRgb(colorRgb);
                    var origin = OriginalGameplayLayout.MotiveArrowOrigin(new CGRect(0, 0, 0, 0), arrowEval.Rising, arrowIndex);
                    int baseX = (int)(origin.X - localStrip.X);
                    for (int py = 0; py < 5; py++)
                    {
                        for (int px = 0; px < 3; px++)
                        {
                            if (!OriginalGameplayLayout.MotiveArrowMaskPixel(arrowEval.Rising, px, py))
                            {
                                continue;
                            }

                            int offset = (py * 19 + baseX + px) * 4;
                            pixels[offset] = rgb.X;
                            pixels[offset + 1] = rgb.Y;
                            pixels[offset + 2] = rgb.Z;
                            pixels[offset + 3] = 255;
                        }
                    }
                }

                try
                {
                    var created = CreateImage(Device, 19, 5, pixels);
                    _cachedMotiveArrowStrips[index] = (stripKey, created);
                    stripImage = created;
                }
                catch
                {
                    stripImage = _cachedMotiveArrowStrips[index]?.Image;
                }
            }

            if (stripImage is { } resolvedStrip)
            {
                var stripRect = Offset(OriginalGameplayLayout.MotiveArrowStripRect(needRect, arrowEval.Rising), 0, top);
                dynamic.Add(new Part(resolvedStrip, stripRect));
            }
        }
    }

    private void SetLivePopup(string title, string description, (Image, GameplayPanelState.Image)? portrait = null)
    {
        int leftInset = portrait is not null ? PersonalityPopup.TextLeft : 15;
        int wrapWidth = Math.Max(120, PersonalityPopup.TextRight - leftInset);
        var bodyFont = LivePopupBodyFont;
        _personalityPopupTitle = Text(title, Font, Device, LivePopupTextColor);
        var wrapped = bodyFont.WrappedLines(description, wrapWidth);
        var lineImages = new Image[wrapped.Count];
        for (int i = 0; i < wrapped.Count; i++)
        {
            lineImages[i] = Text(wrapped[i], bodyFont, Device, LivePopupTextColor);
        }

        _personalityPopupLines = lineImages;
        _personalityPopupPortrait = portrait;
    }

    private void UpdateMotivePopup()
    {
        bool isPet = ((State?.Selected?.Gender ?? 0) & 6) != 0;
        if (CurrentSubpanel != Subpanel.Needs ||
            _hoveredNeed is not { } index ||
            _strings.MotiveHelp(index, isPet) is not { } description)
        {
            if (_motivePopupIndex is null)
            {
                return;
            }

            _motivePopupIndex = null;
            _livePopupAnchorMidX = null;
            _personalityPopupTitle = null;
            _personalityPopupLines = [];
            _personalityPopupPortrait = null;
            return;
        }

        string title = _strings.MotiveLabel(index, isPet, OriginalGameplayLayout.Motives[index]);
        _personalityPopupTrait = null;
        _zodiacPopupActive = false;
        SkillPopupIndex = null;
        _housePopupIndex = null;
        RelationshipPopupId = null;
        _relationshipPopupText = null;
        _careerSummaryPopupIndex = null;
        _motivePopupIndex = index;
        _livePopupAnchorMidX = MidX(OriginalGameplayLayout.NeedRect(index, _grid.Width));
        try
        {
            SetLivePopup(title, description);
        }
        catch
        {
        }
    }

    private void ClearLivePopupState()
    {
        _motivePopupIndex = null;
        _personalityPopupTrait = null;
        _zodiacPopupActive = false;
        SkillPopupIndex = null;
        _housePopupIndex = null;
        RelationshipPopupId = null;
        _relationshipPopupText = null;
        _careerSummaryPopupIndex = null;
        _livePopupAnchorMidX = null;
        _personalityPopupTitle = null;
        _personalityPopupLines = [];
        _personalityPopupPortrait = null;
    }

    internal static bool Supports(Subpanel panel, GameplayPanelState? state) => panel switch
    {
        Subpanel.Needs => state?.Selected is not null,
        Subpanel.House => state?.House is not null,
        Subpanel.Relationships => state?.Selected?.Relationships is not null,
        Subpanel.Personality => state?.Selected?.Personality is not null,
        Subpanel.Career => state?.Selected?.HasHumanCareer == true && state.Selected.Fame is null,
        Subpanel.PetSkills => state?.Selected?.HasPetSkills == true,
        Subpanel.Fame => state?.Selected?.Fame is not null,
        Subpanel.Interests => state?.Selected?.HasHumanInterests == true && ((state.Selected.Gender ?? 0) & 6) == 0,
        Subpanel.Inventory => state?.Selected?.Inventory is not null && ((state.Selected.Gender ?? 0) & 6) == 0,
        Subpanel.ReportCard => state?.Selected?.Career is { IsSchool: true } c && c.ReportCardGrade is not null,
        _ => false
    };

    private void UpdateRelationshipPopup(GameplayPanelState.Relationship target)
    {
        if (_strings.RelationshipPopup(target) is not (var title, var description))
        {
            RelationshipPopupId = null;
            return;
        }

        string key = $"{title}\0{description}";
        if (string.Equals(_relationshipPopupText, key, StringComparison.Ordinal))
        {
            return;
        }

        SetLivePopup(title, description);
        _relationshipPopupText = key;
    }

    private Image? CachedTooltipImage(Dictionary<string, Image> cache, string text)
    {
        if (cache.TryGetValue(text, out var existing))
        {
            return existing;
        }

        try
        {
            var created = CreateImage(Device, PlacementTooltip.RasterizeHiDpi(text, _careerFont));
            cache[text] = created;
            return created;
        }
        catch
        {
            return null;
        }
    }

    private static Part Grown(Part part, double progress)
    {
        if (progress >= 1.0 || part.Rect.Height <= 0.0)
        {
            return part;
        }

        double lift = (1.0 - progress) * 2.0;
        return new Part(
            part.Image,
            new CGRect(part.Rect.X, part.Rect.Y + lift, part.Rect.Width, part.Rect.Height),
            part.UV,
            part.Opacity * (float)Math.Clamp(progress, 0.0, 1.0));
    }

    private static Image? TryBitmap(Func<string, Image> loader, string asset)
    {
        try
        {
            return loader(asset);
        }
        catch
        {
            return null;
        }
    }

    private static int MaxImageWidth(Image[] images)
    {
        int max = 0;
        foreach (var img in images)
        {
            int w = (int)img.Size.Width;
            if (w > max)
            {
                max = w;
            }
        }

        return max;
    }

    private static bool HasVisibleTooltipText(string text) => !string.IsNullOrWhiteSpace(text);

    private static string RelationshipFilterName(OriginalGameplayLayout.RelationshipFilter filter) => filter switch
    {
        OriginalGameplayLayout.RelationshipFilter.Family => "family",
        OriginalGameplayLayout.RelationshipFilter.Friends => "friends",
        OriginalGameplayLayout.RelationshipFilter.Famous => "famous",
        OriginalGameplayLayout.RelationshipFilter.All => "all",
        _ => "all"
    };

    private static string InventorySortName(OriginalGameplayLayout.InventorySort sort) => sort switch
    {
        OriginalGameplayLayout.InventorySort.Magic => "magic",
        OriginalGameplayLayout.InventorySort.Other => "other",
        OriginalGameplayLayout.InventorySort.Gift => "gift",
        _ => "gift"
    };

    private static double MidX(CGRect rect) => rect.X + rect.Width / 2.0;
    private static double MidY(CGRect rect) => rect.Y + rect.Height / 2.0;

    private static CGRect Offset(CGRect rect, double dx, double dy) =>
        new(rect.X + dx, rect.Y + dy, rect.Width, rect.Height);

    private static CGRect Inset(CGRect rect, double dx, double dy) =>
        new(rect.X + dx, rect.Y + dy, rect.Width - 2.0 * dx, rect.Height - 2.0 * dy);

    private static CGRect RectUnion(CGRect a, CGRect b)
    {
        double minX = Math.Min(a.X, b.X);
        double minY = Math.Min(a.Y, b.Y);
        double maxX = Math.Max(a.X + a.Width, b.X + b.Width);
        double maxY = Math.Max(a.Y + a.Height, b.Y + b.Height);
        return new CGRect(minX, minY, maxX - minX, maxY - minY);
    }

    private static bool Contains(CGRect rect, CGPoint point) =>
        rect.Width > 0 && rect.Height > 0 &&
        point.X >= rect.X && point.X < rect.X + rect.Width &&
        point.Y >= rect.Y && point.Y < rect.Y + rect.Height;

    private static bool PathsEqual(string? lhs, string? rhs) =>
        string.Equals(
            lhs,
            rhs,
            OperatingSystem.IsWindows() ? StringComparison.OrdinalIgnoreCase : StringComparison.Ordinal);

    private static string ResolveRealPath(string path) => LotScene.ResolveRealPath(path);

    private static double MonotonicNowSeconds() =>
        Stopwatch.GetTimestamp() / (double)Stopwatch.Frequency;
}
