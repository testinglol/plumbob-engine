using System.Diagnostics;
using System.Globalization;
using System.Numerics;

namespace SimsSDL.UI;

public sealed partial class OriginalGameplayOverlay
{

    public bool ClickCareerSummary(CGPoint point, CGSize canvas)
    {
        Prepare(canvas);
        if (CurrentSubpanel != Subpanel.Career || State?.Selected?.Career is not { } career)
        {
            return false;
        }

        double top = canvas.Height - 150.0;
        var layout = OriginalGameplayLayout.GetCareerSubpanelLayout(_grid.Width, _asianInventoryLayout);
        var reportRect = Offset(layout.ReportCardRect, 0, top);
        if (career.IsSchool && career.ReportCardGrade is not null &&
            Contains(reportRect, point) &&
            _strings.ReportCardPopup() is (var reportTitle, var reportDesc))
        {
            if (_careerSummaryPopupIndex == 4)
            {
                ClearLivePopupState();
                return true;
            }

            ClearLivePopupState();
            _careerSummaryPopupIndex = 4;
            _livePopupAnchorMidX = MidX(reportRect);
            SetLivePopup(reportTitle, reportDesc);
            return true;
        }

        var targets = new List<(int Index, CGRect Rect)>
        {
            (0, Offset(layout.JobSummaryRect, 0, top)),
            (1, Offset(layout.SalaryRect, 0, top)),
            (2, Offset(layout.PerformanceRect, 0, top))
        };
        if (career.FriendsNeeded is not null)
        {
            targets.Add((3, Offset(layout.FriendsRect, 0, top)));
        }

        foreach (var target in targets)
        {
            if (!Contains(target.Rect, point))
            {
                continue;
            }

            if (_strings.CareerSummaryPopup(target.Index, career) is not (var summaryTitle, var summaryDesc))
            {
                return false;
            }

            if (_careerSummaryPopupIndex == target.Index)
            {
                ClearLivePopupState();
                return true;
            }

            ClearLivePopupState();
            _careerSummaryPopupIndex = target.Index;
            _livePopupAnchorMidX = MidX(target.Rect);
            SetLivePopup(summaryTitle, summaryDesc);
            return true;
        }

        return false;
    }

    public bool ClickHouseHint(CGPoint point, CGSize canvas)
    {
        Prepare(canvas);
        if (CurrentSubpanel != Subpanel.House || State?.House is not { } values)
        {
            return false;
        }

        double top = canvas.Height - 150.0;
        var layout = OriginalGameplayLayout.GetHouseSubpanelLayout(_grid.Width, _asianInventoryLayout);
        int?[] scores = [values.SizeScore, values.FurnishingsScore, values.YardScore, values.UpkeepScore, values.LayoutScore];
        string[] names = ["Size", "Furnishings", "Yard", "Upkeep", "Layout"];
        var targets = new List<(int Index, CGRect Rect)>();

        for (int index = 0; index < scores.Length; index++)
        {
            var label = Text(_strings.HouseLabel(index + 1, names[index]), _careerFont, Device);
            double labelX = layout.ScoreLabelRightXs[index] - label.Size.Width;
            double y = layout.ScoreLabelYs[index];
            var labelRect = Offset(new CGRect(labelX, y, label.Size.Width, label.Size.Height), 0, top);
            var barRect = Offset(layout.ScoreBars[index], 0, top);
            targets.Add((index, RectUnion(labelRect, barRect)));
        }

        (int Index, string? Text, CGRect Rect)[] details =
        [
            (5, values.SquareFeet is { } sqFt ? FormatHouseCount(_strings.HouseLabel(6, "Sq. Ft.: %d"), sqFt) : null, layout.InfoRects[0]),
            (6, values.Bedrooms is { } beds ? FormatHouseCount(_strings.HouseLabel(7, "Bedrooms: %d"), beds) : null, layout.InfoRects[1]),
            (7, values.Bathrooms is { } baths ? FormatHouseCount(_strings.HouseLabel(8, "Bathrooms: %d"), baths) : null, layout.InfoRects[2]),
            (8, values.LotSize is { } lotSize ? FormatHouseLot(lotSize) : null, layout.InfoRects[3])
        ];

        foreach (var (index, text, infoRect) in details)
        {
            if (text is null)
            {
                continue;
            }

            var label = Text(text, _careerFont, Device);
            var expanded = Offset(
                new CGRect(infoRect.X, infoRect.Y, Math.Max(infoRect.Width, label.Size.Width), Math.Max(15.0, label.Size.Height)),
                0,
                top);
            targets.Add((index, expanded));
        }

        foreach (var hit in targets)
        {
            if (!Contains(hit.Rect, point))
            {
                continue;
            }

            if (_strings.HouseHint(hit.Index) is not (var hintTitle, var hintDesc))
            {
                return false;
            }

            if (_housePopupIndex == hit.Index)
            {
                ClearLivePopupState();
            }
            else
            {
                ClearLivePopupState();
                _housePopupIndex = hit.Index;
                _livePopupAnchorMidX = MidX(hit.Rect);
                SetLivePopup(hintTitle, hintDesc);
            }

            return true;
        }

        return false;
    }

    public bool ClickPersonality(CGPoint point, CGSize canvas)
    {
        Prepare(canvas);
        if (CurrentSubpanel != Subpanel.Personality || State?.Selected is not { } selected || selected.Personality is not { } traits)
        {
            return false;
        }

        double top = canvas.Height - 150.0;
        bool isPet = ((selected.Gender ?? 0) & 6) != 0;
        var activeTraitLabels = isPet ? _petTraitLabels : _traitLabels;
        int labelWidth = MaxImageWidth(activeTraitLabels);
        var layout = OriginalGameplayLayout.PersonalitySubpanelLayout(_grid.Width, labelWidth, _asianInventoryLayout);
        var bay = OriginalGameplayLayout.CenteredBay(_grid.Width);

        if (!isPet && selected.Zodiac is { } stored)
        {
            int zodiac = OriginalGameplayLayout.Zodiac(traits, stored);
            int signIndex = zodiac - 1;
            if (signIndex >= 0 && signIndex < OriginalGameplayLayout.Signs.Count)
            {
                string signText = _strings.Sign(signIndex, OriginalGameplayLayout.Signs[signIndex]);
                double maxSignW = Math.Max(50.0, bay.Bay.MaxX - layout.ZodiacOrigin.X - 4.0);
                var chosenFont = layout.UsesBottomAlignedZodiac || _zodiacFont.TextWidth(signText) <= maxSignW ? _zodiacFont : Font;
                var signImg = Text(signText, chosenFont, Device);
                double signY = layout.UsesBottomAlignedZodiac ? layout.ZodiacOrigin.Y - signImg.Size.Height : layout.ZodiacOrigin.Y;
                var signRect = Offset(new CGRect(layout.ZodiacOrigin.X, signY, signImg.Size.Width, signImg.Size.Height), 0, top);
                if (Contains(signRect, point) && _strings.ZodiacPopup(zodiac) is (var zodiacTitle, var zodiacDesc))
                {
                    bool wasActive = _zodiacPopupActive;
                    ClearLivePopupState();
                    if (!wasActive)
                    {
                        _zodiacPopupActive = true;
                        _livePopupAnchorMidX = MidX(signRect);
                        SetLivePopup(zodiacTitle, zodiacDesc);
                    }

                    return true;
                }
            }
        }

        int hitTrait = -1;
        for (int i = 0; i < OriginalGameplayLayout.Traits.Count && i < layout.TraitRects.Count; i++)
        {
            if (Contains(Offset(layout.TraitRects[i], 0, top), point))
            {
                hitTrait = i;
                break;
            }
        }

        if (hitTrait < 0 ||
            !traits.TryGetValue(OriginalGameplayLayout.Traits[hitTrait], out int value) ||
            _strings.PersonalityPopup(hitTrait, value, isPet) is not (var traitName, var traitDesc))
        {
            return false;
        }

        int? nextTrait = PersonalityPopup.Selection(_personalityPopupTrait, hitTrait);
        ClearLivePopupState();
        _personalityPopupTrait = nextTrait;
        if (_personalityPopupTrait is not null)
        {
            _livePopupAnchorMidX = MidX(layout.TraitRects[hitTrait]);
            (Image, GameplayPanelState.Image)? portrait = null;
            if (selected.Portrait is { } reference && _resources.TryGetValue(reference.File, out var portraitImage))
            {
                portrait = (portraitImage, reference);
            }

            SetLivePopup(traitName, traitDesc, portrait);
        }

        return true;
    }

    public Subpanel? SubpanelAt(CGPoint point, CGSize canvas)
    {
        TryPrepare(canvas);
        var reportRect = OriginalGameplayLayout.GetCareerSubpanelLayout(_grid.Width, _asianInventoryLayout).ReportCardRect;
        if (CurrentSubpanel == Subpanel.Career &&
            Contains(Offset(reportRect, 0, canvas.Height - 150.0), point) &&
            Supports(Subpanel.ReportCard, State))
        {
            return Subpanel.ReportCard;
        }

        foreach (var panel in MainTabSubpanels)
        {
            if (Supports(panel, State) && Contains(Offset(ButtonRect(panel.ButtonIndex()), 0, canvas.Height - 150.0), point))
            {
                return panel;
            }
        }

        return null;
    }

    public void ChooseInterestPage(int page)
    {
        if (CurrentSubpanel != Subpanel.Interests || State is not { } state || _resourceRoot is null || state.Selected?.Career is not { } career)
        {
            throw new ContentError("Invalid interest page");
        }

        int pageCount = _grid.PageCount(OriginalGameplayLayout.InterestIndices(career.Age).Count, StripInterestCapacity);
        if (page < 0 || page >= pageCount)
        {
            throw new ContentError("Invalid interest page");
        }

        InterestPage = page;
        Update(state, _resourceRoot);
    }

    public void ChooseRelationshipFilter(OriginalGameplayLayout.RelationshipFilter filter)
    {
        if (CurrentSubpanel != Subpanel.Relationships || State is not { } state || _resourceRoot is null)
        {
            throw new ContentError("Relationships panel is unavailable");
        }

        RelationshipFilter = filter;
        RelationshipPage = 0;
        Update(state, _resourceRoot);
    }

    public void ChooseRelationshipPage(int page)
    {
        if (CurrentSubpanel != Subpanel.Relationships || State is not { } state || _resourceRoot is null || state.Selected?.Relationships is not { } values)
        {
            throw new ContentError("Invalid relationship page");
        }

        int pageCount = _grid.PageCount(OriginalGameplayLayout.Relationships(values, RelationshipFilter).Count, StripRelationshipCapacity);
        if (page < 0 || page >= pageCount)
        {
            throw new ContentError("Invalid relationship page");
        }

        RelationshipPage = page;
        Update(state, _resourceRoot);
    }

    public bool RelationshipControl(CGPoint point, CGSize canvas)
    {
        Prepare(canvas);
        if (CurrentSubpanel != Subpanel.Relationships || State?.Selected?.Relationships is not { } values)
        {
            return false;
        }

        double offsetY = canvas.Height - 150.0;
        var allFilters = Enum.GetValues<OriginalGameplayLayout.RelationshipFilter>();
        for (int index = 0; index < allFilters.Length; index++)
        {
            if (Contains(Offset(RelationshipFilterRect(index), 0, offsetY), point))
            {
                ChooseRelationshipFilter(allFilters[index]);
                return true;
            }
        }

        ReadOnlySpan<bool> directions = [false, true];
        foreach (bool isNext in directions)
        {
            if (Contains(Offset(RelationshipArrowRect(isNext), 0, offsetY), point))
            {
                int page = RelationshipPage + (isNext ? 1 : -1);
                if (page >= 0 && page * StripRelationshipCapacity < OriginalGameplayLayout.Relationships(values, RelationshipFilter).Count)
                {
                    ChooseRelationshipPage(page);
                }

                return true;
            }
        }

        return false;
    }

    public bool ClickSkill(CGPoint point, CGSize canvas)
    {
        Prepare(canvas);
        double top = canvas.Height - 150.0;
        var layout = OriginalGameplayLayout.GetCareerSubpanelLayout(_grid.Width, _asianInventoryLayout);
        if (CurrentSubpanel != Subpanel.Career || State?.Selected?.Skills is null || State.Selected.Career is null)
        {
            return false;
        }

        int hitIndex = -1;
        for (int i = 0; i < OriginalGameplayLayout.Skills.Count && i < layout.Skills.Count; i++)
        {
            if (Contains(Offset(layout.Skills[i].HitRect, 0, top), point))
            {
                hitIndex = i;
                break;
            }
        }

        if (hitIndex < 0 || _strings.SkillPopup(hitIndex) is not (var popupTitle, var popupDesc))
        {
            return false;
        }

        if (SkillPopupIndex == hitIndex)
        {
            ClearLivePopupState();
            return true;
        }

        ClearLivePopupState();
        SkillPopupIndex = hitIndex;
        _livePopupAnchorMidX = MidX(layout.Skills[hitIndex].HitRect);
        SetLivePopup(popupTitle, popupDesc);
        return true;
    }

    public bool ClickPetSkill(CGPoint point, CGSize canvas)
    {
        Prepare(canvas);
        double top = canvas.Height - 150.0;
        var (_, skillSlots) = OriginalGameplayLayout.PetSkillsSubpanelLayout(_grid.Width);
        bool isCat = ((State?.Selected?.Gender ?? 0) & 4) != 0;
        if (CurrentSubpanel != Subpanel.PetSkills || State?.Selected?.PetSkills is null)
        {
            return false;
        }

        int hitIndex = -1;
        for (int i = 0; i < OriginalGameplayLayout.PetSkills.Count && i < skillSlots.Count; i++)
        {
            if (Contains(Offset(skillSlots[i].HitRect, 0, top), point))
            {
                hitIndex = i;
                break;
            }
        }

        if (hitIndex < 0 || _strings.PetSkillPopup(hitIndex, isCat) is not (var popupTitle, var popupDesc))
        {
            return false;
        }

        if (SkillPopupIndex == hitIndex)
        {
            ClearLivePopupState();
            return true;
        }

        ClearLivePopupState();
        SkillPopupIndex = hitIndex;
        _livePopupAnchorMidX = MidX(skillSlots[hitIndex].HitRect);
        SetLivePopup(popupTitle, popupDesc);
        return true;
    }

    public bool ClickFameSkill(CGPoint point, CGSize canvas)
    {
        Prepare(canvas);
        if (CurrentSubpanel != Subpanel.Fame || State?.Selected?.Fame is not { } fame)
        {
            return false;
        }

        double top = canvas.Height - 150.0;
        var layout = OriginalGameplayLayout.GetFameSubpanelLayout(_grid.Width, _asianInventoryLayout);
        CGRect[] levelTargets =
        [
            Offset(layout.TitleRect, 0, top),
            Offset(layout.StarBar, 0, top)
        ];
        foreach (var target in levelTargets)
        {
            if (Contains(target, point) && _strings.FameLevelPopup(fame.Level) is (var levelTitle, var levelDesc))
            {
                if (_careerSummaryPopupIndex == 0)
                {
                    ClearLivePopupState();
                    return true;
                }

                ClearLivePopupState();
                _careerSummaryPopupIndex = 0;
                _livePopupAnchorMidX = MidX(target);
                SetLivePopup(levelTitle, levelDesc);
                return true;
            }
        }

        var friendsRect = Offset(layout.FriendsRect, 0, top);
        CGRect[] friendsTargets =
        [
            friendsRect,
            new CGRect(friendsRect.X, friendsRect.Y - 2.0, Math.Max(100.0, friendsRect.Width), 22.0)
        ];
        foreach (var target in friendsTargets)
        {
            if (Contains(target, point) && _strings.FameFriendsPopup() is (var friendsTitle, var friendsDesc))
            {
                if (_careerSummaryPopupIndex == 1)
                {
                    ClearLivePopupState();
                    return true;
                }

                ClearLivePopupState();
                _careerSummaryPopupIndex = 1;
                _livePopupAnchorMidX = MidX(target);
                SetLivePopup(friendsTitle, friendsDesc);
                return true;
            }
        }

        int hitIndex = -1;
        for (int i = 0; i < OriginalGameplayLayout.Skills.Count && i < layout.Skills.Count; i++)
        {
            if (Contains(Offset(layout.Skills[i].HitRect, 0, top), point))
            {
                hitIndex = i;
                break;
            }
        }

        if (hitIndex < 0 || _strings.SkillPopup(hitIndex) is not (var popupTitle, var popupDesc))
        {
            return false;
        }

        if (SkillPopupIndex == hitIndex)
        {
            ClearLivePopupState();
            return true;
        }

        ClearLivePopupState();
        SkillPopupIndex = hitIndex;
        _livePopupAnchorMidX = MidX(layout.Skills[hitIndex].HitRect);
        SetLivePopup(popupTitle, popupDesc);
        return true;
    }

    public GameplayPanelState.Relationship? RelationshipAt(CGPoint point, CGSize canvas)
    {
        TryPrepare(canvas);
        if (CurrentSubpanel != Subpanel.Relationships || State?.Selected?.Relationships is not { } values)
        {
            return null;
        }

        int capacity = StripRelationshipCapacity;
        double top = canvas.Height - 150.0;
        int slot = 0;
        foreach (var rel in OriginalGameplayLayout.Relationships(values, RelationshipFilter).Skip(RelationshipPage * capacity).Take(capacity))
        {
            if (Contains(Offset(RelationshipSlotRect(slot), 0, top), point))
            {
                return rel;
            }

            slot++;
        }

        return null;
    }

    public bool ClickRelationship(CGPoint point, CGSize canvas)
    {
        Prepare(canvas);
        if (CurrentSubpanel != Subpanel.Relationships || State?.Selected?.Relationships is not { } values)
        {
            return false;
        }

        int capacity = StripRelationshipCapacity;
        double top = canvas.Height - 150.0;
        int hitSlot = -1;
        GameplayPanelState.Relationship? hitTarget = null;
        int slot = 0;
        foreach (var rel in OriginalGameplayLayout.Relationships(values, RelationshipFilter).Skip(RelationshipPage * capacity).Take(capacity))
        {
            if (Contains(Offset(RelationshipSlotRect(slot), 0, top), point))
            {
                hitSlot = slot;
                hitTarget = rel;
                break;
            }

            slot++;
        }

        if (hitTarget is null || _strings.RelationshipPopup(hitTarget) is null)
        {
            return false;
        }

        if (RelationshipPopupId == hitTarget.NeighborId)
        {
            ClearLivePopupState();
        }
        else
        {
            ClearLivePopupState();
            RelationshipPopupId = hitTarget.NeighborId;
            _livePopupAnchorMidX = MidX(RelationshipSlotRect(hitSlot));
            UpdateRelationshipPopup(hitTarget);
        }

        return true;
    }

    public void ChooseInventorySort(OriginalGameplayLayout.InventorySort sort)
    {
        if (CurrentSubpanel != Subpanel.Inventory || State is not { } state || _resourceRoot is null)
        {
            throw new ContentError("Inventory panel is unavailable");
        }

        InventorySort = sort;
        InventoryPage = 0;
        _hoveredInventoryTile = null;
        _inventoryHoverStartedAt = null;
        Update(state, _resourceRoot);
    }

    public bool InventoryControl(CGPoint point, CGSize canvas)
    {
        Prepare(canvas);
        if (CurrentSubpanel != Subpanel.Inventory || State?.Selected?.Inventory is not { } values || State is not { } state || _resourceRoot is null)
        {
            return false;
        }

        double offset = canvas.Height - 150.0;
        var allSorts = Enum.GetValues<OriginalGameplayLayout.InventorySort>();
        for (int index = 0; index < allSorts.Length; index++)
        {
            if (Contains(Offset(InventorySortRect(index), 0, offset), point))
            {
                ChooseInventorySort(allSorts[index]);
                return true;
            }
        }

        int capacity = StripInventoryCapacity;
        ReadOnlySpan<bool> directions = [false, true];
        foreach (bool isNext in directions)
        {
            if (Contains(Offset(InventoryArrowRect(isNext), 0, offset), point))
            {
                int page = InventoryPage + (isNext ? 1 : -1);
                if (page >= 0 && page * capacity < OriginalGameplayLayout.InventoryItems(values, InventorySort).Count)
                {
                    InventoryPage = page;
                    _hoveredInventoryTile = null;
                    _inventoryHoverStartedAt = null;
                    Update(state, _resourceRoot);
                }

                return true;
            }
        }

        return false;
    }

    public bool HoverInventory(CGPoint point, CGSize canvas)
    {
        TryPrepare(canvas);
        int? nextTile = null;
        if (CurrentSubpanel == Subpanel.Inventory && State?.Selected?.Inventory is { } values)
        {
            var items = OriginalGameplayLayout.InventoryItems(values, InventorySort);
            int capacity = StripInventoryCapacity;
            double top = canvas.Height - 150.0;
            int visibleCount = Math.Min(capacity, Math.Max(0, items.Count - InventoryPage * capacity));
            for (int slot = 0; slot < visibleCount; slot++)
            {
                if (Contains(Offset(InventoryTileRect(slot), 0, top), point))
                {
                    nextTile = slot;
                    break;
                }
            }
        }

        if (nextTile != _hoveredInventoryTile)
        {
            _hoveredInventoryTile = nextTile;
            _inventoryHoverStartedAt = null;
        }

        return nextTile is not null;
    }

    public void ClearInventoryHover()
    {
        _hoveredInventoryTile = null;
        _inventoryHoverStartedAt = null;
        _hoveredPerson = null;
        _hoveredPeopleTip = null;
        HoveredPanelPoint = null;
        _panelTip = null;
        _indicatorHovered = null;
        _hoveredNeed = null;
        HoveredAction = null;
        _suppressedTooltipIdentity = null;
    }

    public void DismissTooltips()
    {
        _suppressedTooltipIdentity = CurrentTooltipIdentity;
        _inventoryHoverStartedAt = null;
        _indicatorHoverStartedAt = null;
        _personHoverStartedAt = null;
    }

    public (string Text, CGRect Rect)? PeopleTooltip(CGPoint point, CGSize canvas, bool panelMinimized = false)
    {
        TryPrepare(canvas);

        static (string Text, CGRect Rect)? NonEmpty(string text, CGRect rect) =>
            HasVisibleTooltipText(text) ? (text, rect) : null;

        double now = MonotonicNowSeconds();
        int maxQueue = Math.Min(_queued.Count, Math.Max(0, (int)((canvas.Width - 32.0) / 50.0)));
        for (int index = 0; index < maxQueue; index++)
        {
            var rect = CurrentActionRect(index, now);
            if (Contains(rect, point) && _queued[index].Action.Name is { } name && NonEmpty(name, rect) is { } valid)
            {
                return valid;
            }
        }

        if (panelMinimized)
        {
            return null;
        }

        double top = canvas.Height - 150.0;
        ReadOnlySpan<bool> segments = [true, false];
        foreach (bool positive in segments)
        {
            var rect = Offset(OriginalGameplayLayout.MoodRatingSegment(positive), 0, top);
            if (Contains(rect, point))
            {
                return NonEmpty(_strings.PeopleRatingTip(15, "Mood"), rect);
            }
        }

        foreach (var panel in MainTabSubpanels)
        {
            if (!Supports(panel, State))
            {
                continue;
            }

            var rect = Offset(ButtonRect(panel.ButtonIndex()), 0, top);
            if (Contains(rect, point))
            {
                return NonEmpty(_strings.PeoplePanelTip(panel.ButtonIndex(), State?.Selected, panel.Label()), rect);
            }
        }

        if (CurrentSubpanel == Subpanel.Relationships)
        {
            int filterCount = Enum.GetValues<OriginalGameplayLayout.RelationshipFilter>().Length;
            for (int index = 0; index < filterCount; index++)
            {
                var rect = Offset(RelationshipFilterRect(index), 0, top);
                if (Contains(rect, point))
                {
                    return NonEmpty(_strings.RelationshipFilterTip(index, string.Empty), rect);
                }
            }

            var relationships = OriginalGameplayLayout.Relationships(State?.Selected?.Relationships ?? [], RelationshipFilter);
            int capacity = StripRelationshipCapacity;
            int slot = 0;
            foreach (var relationship in relationships.Skip(RelationshipPage * capacity).Take(capacity))
            {
                var rect = Offset(RelationshipSlotRect(slot++), 0, top);
                if (Contains(rect, point) && NonEmpty(relationship.Name, rect) is { } valid)
                {
                    return valid;
                }
            }

            if (RelationshipPage > 0)
            {
                var rect = Offset(RelationshipArrowRect(false), 0, top);
                if (Contains(rect, point))
                {
                    return NonEmpty(_strings.PeoplePageTip(0, "Previous"), rect);
                }
            }

            if ((RelationshipPage + 1) * capacity < relationships.Count)
            {
                var rect = Offset(RelationshipArrowRect(true), 0, top);
                if (Contains(rect, point))
                {
                    return NonEmpty(_strings.PeoplePageTip(1, "Next"), rect);
                }
            }
        }
        else if (CurrentSubpanel == Subpanel.Interests && State?.Selected?.Career is { } career)
        {
            var indices = OriginalGameplayLayout.InterestIndices(career.Age);
            int capacity = StripInterestCapacity;
            int slot = 0;
            foreach (int interestIndex in indices.Skip(InterestPage * capacity).Take(capacity))
            {
                var rect = Offset(InterestSlotRect(slot++), 0, top);
                if (Contains(rect, point) && interestIndex >= 0 && interestIndex < OriginalGameplayLayout.Interests.Count)
                {
                    string fallback = OriginalGameplayLayout.Interests[interestIndex];
                    return NonEmpty(_strings.InterestTip(interestIndex, fallback), rect);
                }
            }

            if (InterestPage > 0)
            {
                var rect = Offset(InterestArrowRect(false), 0, top);
                if (Contains(rect, point))
                {
                    return NonEmpty(_strings.PeoplePageTip(0, "Previous"), rect);
                }
            }

            if ((InterestPage + 1) * capacity < indices.Count)
            {
                var rect = Offset(InterestArrowRect(true), 0, top);
                if (Contains(rect, point))
                {
                    return NonEmpty(_strings.PeoplePageTip(1, "Next"), rect);
                }
            }
        }
        else if (CurrentSubpanel == Subpanel.Inventory && State?.Selected?.Inventory is { } values)
        {
            var allSorts = Enum.GetValues<OriginalGameplayLayout.InventorySort>();
            for (int index = 0; index < allSorts.Length; index++)
            {
                var rect = Offset(InventorySortRect(index), 0, top);
                if (Contains(rect, point))
                {
                    int tipIndex = allSorts[index] switch
                    {
                        OriginalGameplayLayout.InventorySort.Gift => 0,
                        OriginalGameplayLayout.InventorySort.Magic => 1,
                        _ => 2
                    };
                    return NonEmpty(_strings.InventorySortTip(tipIndex, string.Empty), rect);
                }
            }

            var items = OriginalGameplayLayout.InventoryItems(values, InventorySort);
            int capacity = StripInventoryCapacity;
            if (InventoryPage > 0)
            {
                var rect = Offset(InventoryArrowRect(false), 0, top);
                if (Contains(rect, point))
                {
                    return NonEmpty(_strings.PeoplePageTip(0, "Previous"), rect);
                }
            }

            if ((InventoryPage + 1) * capacity < items.Count)
            {
                var rect = Offset(InventoryArrowRect(true), 0, top);
                if (Contains(rect, point))
                {
                    return NonEmpty(_strings.PeoplePageTip(1, "Next"), rect);
                }
            }
        }

        return null;
    }

    public bool PageInterests(CGPoint point, CGSize canvas)
    {
        Prepare(canvas);
        if (CurrentSubpanel != Subpanel.Interests || State?.Selected?.Career is not { } career)
        {
            return false;
        }

        double offset = canvas.Height - 150.0;
        ReadOnlySpan<bool> directions = [false, true];
        foreach (bool isNext in directions)
        {
            if (Contains(Offset(InterestArrowRect(isNext), 0, offset), point))
            {
                int page = InterestPage + (isNext ? 1 : -1);
                if (page >= 0 && page * StripInterestCapacity < OriginalGameplayLayout.InterestIndices(career.Age).Count)
                {
                    ChooseInterestPage(page);
                }

                return true;
            }
        }

        return false;
    }

    public void Prepare(CGSize canvas)
    {
        var next = new OriginalGameplayLayout.PanelGrid(canvas.Width);
        if (Equals(next, _grid))
        {
            return;
        }

        var previous = _grid;
        int previousRelationshipPage = RelationshipPage;
        int previousInterestPage = InterestPage;
        _grid = next;

        if (State is not { } state || _resourceRoot is not { } root)
        {
            return;
        }

        var relationships = OriginalGameplayLayout.Relationships(state.Selected?.Relationships ?? [], RelationshipFilter);
        RelationshipPage = next.ResizedPage(RelationshipPage, previous.RelationshipCapacity, next.RelationshipCapacity, relationships.Count);
        int interests = state.Selected?.Career is { } career ? OriginalGameplayLayout.InterestIndices(career.Age).Count : 0;
        InterestPage = next.ResizedPage(InterestPage, previous.InterestCapacity, next.InterestCapacity, interests);

        try
        {
            Update(state, root);
        }
        catch
        {
            _grid = previous;
            RelationshipPage = previousRelationshipPage;
            InterestPage = previousInterestPage;
            throw;
        }
    }

    public IReadOnlyList<Part> UniversalStatusParts(CGSize canvas)
    {
        double top = canvas.Height - 150.0;
        var parts = new List<Part>(_statusBody.Count + 4);
        if (SimsBitmapFont.SharpTextEnabled && ActiveUniversal.Texture != _universal.Texture)
        {
            parts.Add(new Part(_vectorLcdFriendSmiley, Offset(FamilyFriendsSmileyRect, 0, top)));
        }
        foreach (var part in _statusBody)
        {
            parts.Add(new Part(part.Image, Offset(part.Rect, 0, top), part.UV, part.Opacity));
        }

        AppendReelParts(top, parts);
        return parts;
    }
}
