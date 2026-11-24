using System.Diagnostics;
using System.Globalization;
using System.Numerics;

namespace SimsSDL.UI;

public sealed partial class OriginalGameplayOverlay
{
    public enum Subpanel
    {
        Needs,
        Relationships,
        House,
        Personality,
        Career,
        Fame,
        PetSkills,
        Interests,
        Inventory,
        ReportCard
    }

    public readonly record struct Image(UITexture Texture, CGSize Size);

    public struct Part
    {
        public Image Image { get; init; }
        public CGRect Rect { get; init; }
        public Vector4 UV { get; set; }
        public float Opacity { get; set; }

        public Part(Image image, CGRect rect)
            : this(image, rect, new Vector4(0f, 0f, 1f, 1f), 1f)
        {
        }

        public Part(Image image, CGRect rect, Vector4 uv, float opacity = 1f)
        {
            Image = image;
            Rect = rect;
            UV = uv;
            Opacity = opacity;
        }
    }

    private struct ActionAnimation
    {
        public CGPoint StartOrigin;
        public CGPoint TargetOrigin;
        public double StartedAt;

        public readonly CGPoint CurrentOrigin(double now, double duration = 0.5)
        {
            double elapsed = now - StartedAt;
            if (elapsed >= duration || duration <= 0.0)
            {
                return TargetOrigin;
            }

            double t = Math.Max(0.0, Math.Min(1.0, elapsed / duration));
            return new CGPoint(
                Math.Truncate(StartOrigin.X + (TargetOrigin.X - StartOrigin.X) * t),
                Math.Truncate(StartOrigin.Y + (TargetOrigin.Y - StartOrigin.Y) * t));
        }
    }

    private readonly record struct MotiveBarCacheKey(int Width, uint GreenRgb, uint RedRgb);
    private readonly record struct MotiveArrowStripCacheKey(bool Rising, uint C0, uint C1, uint C2, uint C3, uint C4);

    private static readonly (byte R, byte G, byte B) LivePopupTextColor = (195, 205, 205);
    private static readonly Subpanel[] MainTabSubpanels =
    [
        Subpanel.Needs,
        Subpanel.Relationships,
        Subpanel.House,
        Subpanel.Personality,
        Subpanel.Career,
        Subpanel.Fame,
        Subpanel.PetSkills,
        Subpanel.Interests,
        Subpanel.Inventory
    ];

    public static readonly CGRect FundsRect = new(118, 123, 62, 14);
    private static readonly CGRect FamilyFriendsSmileyRect = new(67, 135, 10, 10);
    private const double FamilyFriendsLabelX = 80.0;
    private const double FamilyFriendsTextY = 132.5;

    private readonly OriginalUIStrings _strings;
    private readonly Image _patch;
    private readonly Image _vectorPatch;
    private readonly Image _universal;
    private readonly Image _vectorUniversal;
    private readonly Image _vectorLcdFriendSmiley;
    private readonly Image _gadget;
    private readonly Image _vectorGadget;
    private readonly Image _people;
    private readonly Image _vectorPeople;
    private readonly Image _unknown;

    private Image ActiveGadget => SimsBitmapFont.SharpTextEnabled ? _vectorGadget : _gadget;
    private Image ActivePatch => SimsBitmapFont.SharpTextEnabled ? _vectorPatch : _patch;
    private Image ActiveUniversal => SimsBitmapFont.SharpTextEnabled ? _vectorUniversal : _universal;
    private Image ActivePeople => SimsBitmapFont.SharpTextEnabled ? _vectorPeople : _people;
    private readonly Image _iconFrame;
    private readonly Image _thumbTemplate;
    private readonly Image _catalogUnknown;
    private readonly Image _cancel;
    private readonly Image _greenBars;
    private readonly Image _vectorGreenBars;
    private readonly Image _redBars;
    private readonly Image _vectorRedBars;
    private readonly Image[] _buttons;
    private readonly Image?[] _vectorButtons;

    private Image ActiveGreenBars => SimsBitmapFont.SharpTextEnabled ? _vectorGreenBars : _greenBars;
    private Image ActiveRedBars => SimsBitmapFont.SharpTextEnabled ? _vectorRedBars : _redBars;
    private Image[] _labels = [];
    private Image[] _petLabels = [];
    private Image[] _traitLabels = [];
    private Image[] _petTraitLabels = [];
    private readonly Image _personalityBackground;
    private readonly Image _personalityBars;
    private readonly Image _houseBarsOff;

    private readonly Image _livePopupBackground;
    private readonly Image _bevelDivider;
    private double? _livePopupAnchorMidX;
    private int? _personalityPopupTrait;
    private int? _housePopupIndex;
    private string? _relationshipPopupText;
    private int? _careerSummaryPopupIndex;
    private int? _motivePopupIndex;
    private bool _zodiacPopupActive;
    private Image? _personalityPopupTitle;
    private Image[] _personalityPopupLines = [];
    private (Image Image, GameplayPanelState.Image Reference)? _personalityPopupPortrait;
    private readonly SimsBitmapFont _careerFont;
    private readonly SimsBitmapFont _clockFont;
    private readonly SimsBitmapFont _zodiacFont;
    private Image[] _skillLabels = [];
    private Image[] _dogSkillLabels = [];
    private Image[] _catSkillLabels = [];
    private readonly Image _skillBars;
    private readonly Image _skillBarsOff;
    private readonly Image _skillHighlight;
    private readonly Image _jobIcons;
    private readonly Image _vectorJobIcons;
    private readonly Image _salaryButton;
    private readonly Image _vectorSalaryButton;
    private readonly Image _performanceButton;
    private readonly Image _jobFriendSmiley;
    private readonly Image _vectorJobFriendSmiley;
    private readonly Image _fameBars;
    private readonly Image _fameBarsOff;
    private readonly Image _fameIcons;
    private readonly Image _vectorFameIcons;
    private readonly Image _fameFriendSmiley;
    private readonly Image _vectorFameFriendSmiley;
    private Image ActiveJobIcons => SimsBitmapFont.SharpTextEnabled ? _vectorJobIcons : _jobIcons;
    private Image ActiveSalaryButton => SimsBitmapFont.SharpTextEnabled ? _vectorSalaryButton : _salaryButton;
    private Image ActiveJobFriendSmiley => SimsBitmapFont.SharpTextEnabled ? _vectorJobFriendSmiley : _jobFriendSmiley;
    private Image ActiveFameFriendSmiley => SimsBitmapFont.SharpTextEnabled ? _vectorFameFriendSmiley : _fameFriendSmiley;
    private readonly Image[] _interestIcons;
    private readonly Image _interestBars;
    private readonly Image _interestBackground;
    private readonly Image[] _interestArrows;
    private readonly Image _relationshipUnknown;
    private readonly Image[] _relationshipIcons;
    private readonly Image[] _relationshipFilters;
    private readonly Image[] _vectorRelationshipFilters;
    private readonly Image[] _inventorySorts;
    private readonly Image[] _vectorInventorySorts;
    private readonly Image _missingInventoryIcon;
    private readonly bool _asianInventoryLayout;
    private int? _hoveredInventoryTile;
    private double? _inventoryHoverStartedAt;
    private (string Text, Image Image)? _inventoryTooltipCache;
    private OriginalGameplayLayout.PanelGrid _grid = new(800);
    private Dictionary<string, Image> _resources = new(StringComparer.Ordinal);
    private List<Part> _body = [];
    private List<Part> _statusBody = [];
    private List<(GameplayPanelState.Action Action, Image? Icon)> _queued = [];
    private Dictionary<string, ActionAnimation> _actionAnimations = new(StringComparer.Ordinal);
    private readonly HashSet<string> _optimisticCancelledTokens = new(StringComparer.Ordinal);
    private CGPoint? _pendingPieChoiceOrigin;
    private Image? _needsTitleImage;
    private readonly Dictionary<int, OriginalGameplayLayout.MotiveRateTracker[]> _motiveTrackersBySim = [];
    private readonly Dictionary<int, int[]> _lastSampledMotivesBySim = [];
    private int? _lastSampledSimMinute;
    private HashSet<int> _trackedHouseholdSimIds = [];
    private int? _trackedSelectedSimId;
    private readonly OriginalGameplayLayout.MotiveArrowsState[] _motiveArrowsStates;
    private readonly OriginalGameplayLayout.MotiveBarState[] _motiveBarStates;
    private readonly (MotiveBarCacheKey Key, Image Image)?[] _cachedMotiveBars;
    private readonly (MotiveArrowStripCacheKey Key, Image Image)?[] _cachedMotiveArrowStrips;
    private string? _resourceRoot;
    private readonly Dictionary<string, (string Text, Image Image)> _pluginTooltips = new(StringComparer.Ordinal);
    private (Image Image, double ExpiresAt)? _pluginToastBanner;
    private (string PackId, string WidgetId)? _hoveredPluginWidget;
    private double? _pluginWidgetHoverStartedAt;
    private (int Index, CGRect Rect)? _panelTip;
    private readonly Dictionary<int, Image> _panelTips = [];
    private (string Text, CGRect Rect)? _hoveredPeopleTip;
    private readonly Dictionary<string, Image> _peopleTips = new(StringComparer.Ordinal);
    private int? _hoveredNeed;
    private (int Id, string Name, CGRect Rect)? _hoveredPerson;
    private double? _personHoverStartedAt;
    private readonly Dictionary<string, Image> _personTips = new(StringComparer.Ordinal);
    private string? _suppressedTooltipIdentity;
    private bool _quickTips = true;
    private HashSet<UITexture>? _hoverTextures;
    private (string Text, Image Image)? _cachedClockText;
    private (string Text, Image Image)? _cachedFriendsText;
    private (string Text, Image Image)? _cachedBudgetText;

    private readonly CGPoint[] _buttonPositions =
    [
        new(421, 81),
        new(489, 54),
        new(489, 85),
        new(489, 116),
        new(457, 85),
        new(457, 54),
        OriginalGameplayLayout.InventoryButton
    ];

    public UIDevice Device { get; }
    public SimsBitmapFont Font { get; }
    public int? SkillPopupIndex { get; private set; }
    public int? RelationshipPopupId { get; private set; }
    public int InventoryPage { get; private set; }
    public OriginalGameplayLayout.InventorySort InventorySort { get; private set; } = OriginalGameplayLayout.InventorySort.Gift;
    public int RelationshipPage { get; private set; }
    public OriginalGameplayLayout.RelationshipFilter RelationshipFilter { get; private set; } = OriginalGameplayLayout.RelationshipFilter.All;
    public int InterestPage { get; private set; }
    public Image? PieHead { get; private set; }
    public bool InterfaceEffects { get; set; } = true;
    public GameplayPanelState? State { get; private set; }
    public Subpanel CurrentSubpanel { get; private set; } = Subpanel.Needs;
    public int? HoveredAction { get; set; }
    public CGPoint? HoveredPanelPoint { get; set; }
    public IReadOnlyList<SimsSDL.Client.ClientPluginHost.HudWidget> PluginHudWidgets { get; set; } = [];

    public void ShowPluginToastBanner(string text, double durationSeconds)
    {
        if (string.IsNullOrWhiteSpace(text))
            return;
        _pluginToastBanner = (CreateImage(Device, PlacementTooltip.RasterizeHiDpi(text, _careerFont)), MonotonicNowSeconds() + durationSeconds);
    }

    // Tutorial triggers match the active popup client name (e.g. "per.ity") rather than the selected subpanel.
    public string? TutorialPopupName
    {
        get
        {
            if (RelationshipPopupId is not null) return "rel";
            if (_motivePopupIndex is not null || CurrentSubpanel == Subpanel.Needs) return "motives";
            if (_careerSummaryPopupIndex == 0) return "job";
            if (_careerSummaryPopupIndex == 2) return "perf";
            if (_careerSummaryPopupIndex is 1 or 3) return "summary";
            if (_personalityPopupTrait is not null || _zodiacPopupActive || CurrentSubpanel == Subpanel.Personality) return "per.ity";
            if (SkillPopupIndex is not null) return "skill";
            if (_housePopupIndex is not null) return "house";
            if (CurrentSubpanel == Subpanel.Career) return "job";
            return null;
        }
    }

    public (string PackId, string WidgetId)? HoveredPluginWidget
    {
        get => _hoveredPluginWidget;
        set
        {
            if (_hoveredPluginWidget != value)
            {
                _pluginWidgetHoverStartedAt = null;
            }

            _hoveredPluginWidget = value;
        }
    }

    public (int Index, CGRect Rect)? PanelTip
    {
        get => _panelTip;
        set
        {
            if (_panelTip?.Index != value?.Index)
            {
                _pluginWidgetHoverStartedAt = null;
            }

            _panelTip = value;
        }
    }

    public (string Text, CGRect Rect)? HoveredPeopleTip
    {
        get => _hoveredPeopleTip;
        set
        {
            if (!string.Equals(_hoveredPeopleTip?.Text, value?.Text, StringComparison.Ordinal))
            {
                _pluginWidgetHoverStartedAt = null;
            }

            _hoveredPeopleTip = value;
        }
    }

    public int? HoveredNeed
    {
        get => _hoveredNeed;
        set
        {
            if (_hoveredNeed == value)
            {
                return;
            }

            _hoveredNeed = value;
            _pluginWidgetHoverStartedAt = null;
            UpdateMotivePopup();
        }
    }

    public (int Id, string Name, CGRect Rect)? HoveredPerson
    {
        get => _hoveredPerson;
        set
        {
            if (_hoveredPerson?.Id != value?.Id || !string.Equals(_hoveredPerson?.Name, value?.Name, StringComparison.Ordinal))
            {
                _personHoverStartedAt = null;
            }

            _hoveredPerson = value;
        }
    }

    public bool QuickTips
    {
        get => _quickTips;
        set
        {
            if (_quickTips == value)
            {
                return;
            }

            _quickTips = value;
            _inventoryHoverStartedAt = null;
            _pluginWidgetHoverStartedAt = null;
            _personHoverStartedAt = null;
        }
    }

    public bool ExpandsControlPanelToCanvas => true;

    private Image[] ScrollArrows => _interestArrows;
    private SimsBitmapFont LivePopupBodyFont => _asianInventoryLayout ? Font : _clockFont;
    private int StripRelationshipCapacity => _grid.RelationshipCapacity;
    private int StripInventoryCapacity => OriginalGameplayLayout.InventoryCapacity(_grid.Width);
    private int StripInterestCapacity => _grid.InterestCapacity;

    public OriginalGameplayOverlay(GameContent content, SimsBitmapFont font, UIDevice device, OriginalUIStrings strings)
    {
        ArgumentNullException.ThrowIfNull(content);
        ArgumentNullException.ThrowIfNull(font);
        ArgumentNullException.ThrowIfNull(strings);

        Device = device;
        Font = font;
        _strings = strings;
        _asianInventoryLayout = OriginalGameplayLayout.UsesAsianInventoryLayout(content.Language.Code);

        int motiveCount = OriginalGameplayLayout.Motives.Count;
        _motiveArrowsStates = new OriginalGameplayLayout.MotiveArrowsState[motiveCount];
        _motiveBarStates = new OriginalGameplayLayout.MotiveBarState[motiveCount];
        for (int i = 0; i < motiveCount; i++)
        {
            _motiveArrowsStates[i] = new OriginalGameplayLayout.MotiveArrowsState();
            _motiveBarStates[i] = new OriginalGameplayLayout.MotiveBarState();
        }

        _cachedMotiveBars = new (MotiveBarCacheKey, Image)?[motiveCount];
        _cachedMotiveArrowStrips = new (MotiveArrowStripCacheKey, Image)?[motiveCount];

        Image Bitmap(string asset)
        {
            var bmp = new SimsBitmap(content.Read("UIGraphics/cpanel/" + asset));
            return CreateImage(device, bmp.Width, bmp.Height, bmp.Rgba, magenta: true);
        }

        _patch = Bitmap("Backgrounds/LivePatch.bmp");
        try { _vectorPatch = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderFittedPanel("livepatch", scale: 8)); } catch { _vectorPatch = _patch; }
        var baseTarga = new SimsTarga(content.Read("UIGraphics/cpanel/Backgrounds/UniversalBack.tga"));
        _universal = CreateImage(device, baseTarga.Width, baseTarga.Height, baseTarga.Rgba);
        try { _vectorUniversal = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderFittedPanel("universalback", scale: 8)); } catch { _vectorUniversal = _universal; }
        _vectorLcdFriendSmiley = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderLcdGreenSmiley(10, scale: 4));
        _gadget = Bitmap("Backgrounds/LiveGadget.bmp");
        _vectorGadget = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderLiveGadget(scale: 8));
        _people = Bitmap("People/PeopleTemplate.bmp");
        _vectorPeople = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderPeopleTemplateStrip(45, scale: 4));
        _unknown = Bitmap("Buttons/UnknownFace.bmp");

        var iconFrameBitmap = new SimsBitmap(content.Read("UIGraphics/cpanel/Buttons/IconFrame.bmp"));
        _iconFrame = CreateImage(device, iconFrameBitmap.Width, iconFrameBitmap.Height, iconFrameBitmap.Rgba, magenta: true, blue: true);

        var thumbTemplateBitmap = new SimsBitmap(content.Read("UIGraphics/cpanel/Catalog/ThumbTemplate.bmp"));
        _thumbTemplate = CreateImage(
            device,
            thumbTemplateBitmap.Width,
            thumbTemplateBitmap.Height,
            MaskIconFrameCorners(thumbTemplateBitmap.Rgba, thumbTemplateBitmap.Width, thumbTemplateBitmap.Height, 4, 1),
            magenta: true);

        var catalogUnknownBitmap = new SimsBitmap(content.Read("UIGraphics/cpanel/CatalogUnknown.bmp"));
        _catalogUnknown = CreateImage(
            device,
            catalogUnknownBitmap.Width,
            catalogUnknownBitmap.Height,
            MaskIconFrameCorners(catalogUnknownBitmap.Rgba, catalogUnknownBitmap.Width, catalogUnknownBitmap.Height, 2, 1),
            magenta: true);

        var cancelBitmap = new SimsBitmap(content.Read("UIGraphics/Other/QueueCancel.bmp"));
        _cancel = CreateImage(device, cancelBitmap.Width, cancelBitmap.Height, cancelBitmap.Rgba, magenta: true);

        _greenBars = Bitmap("Greenbars.bmp");
        _vectorGreenBars = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderLiveGadgetMoodBars(isGreen: true, scale: 8));
        _redBars = Bitmap("Redbars.bmp");
        _vectorRedBars = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderLiveGadgetMoodBars(isGreen: false, scale: 8));

        string[] buttonAssets = ["Mood", "Relationship", "Job", "House", "Personality", "Interest", "Gift"];
        _buttons = new Image[buttonAssets.Length];
        _vectorButtons = new Image?[buttonAssets.Length];
        for (int i = 0; i < buttonAssets.Length; i++)
        {
            var rawBmp = new SimsBitmap(content.Read("UIGraphics/cpanel/Buttons/" + buttonAssets[i] + ".bmp"));
            _buttons[i] = CreateImage(device, rawBmp.Width, rawBmp.Height, rawBmp.Rgba, magenta: true);
            int bw = Math.Max(1, rawBmp.Width / 4);
            int bh = Math.Max(1, rawBmp.Height);
            if (SimsVectorUiKit.TryRenderSubpanelTabStrip(buttonAssets[i], bw, bh, scale: 4) is { } vecTab)
            {
                _vectorButtons[i] = SimsVectorUiKit.ToOverlayImage(vecTab);
            }
            else
            {
                byte[] trimmed = MaskSubpanelOuterFringe(rawBmp.Rgba, rawBmp.Width, rawBmp.Height, columns: 4);
                _vectorButtons[i] = CreateImage(device, rawBmp.Width, rawBmp.Height, trimmed, magenta: false);
            }
        }

        _careerFont = new SimsBitmapFont(content.Read("UIGraphics/Fonts/variablesans_07.ffn"));
        _clockFont = new SimsBitmapFont(content.Read("UIGraphics/Fonts/variablesans_08.ffn"));
        _zodiacFont = new SimsBitmapFont(content.Read("UIGraphics/Fonts/variablesans_12.ffn"));

        RebuildStaticLabels();

        _personalityBackground = Bitmap("Backgrounds/PersBkg.bmp");
        _personalityBars = Bitmap("HouseSubBars.bmp");
        _houseBarsOff = Bitmap("Backgrounds/HouseSubBarsOff.BMP");
        _livePopupBackground = Bitmap("Backgrounds/PopupInfoTiles.bmp");
        _bevelDivider = TryBitmap(Bitmap, "Backgrounds/OptionsToothpkVert.bmp")
            ?? CreateImage(device, 2, 1, [0, 0, 42, 255, 74, 90, 148, 255]);

        _skillBars = Bitmap("JobSubBars.bmp");
        _skillBarsOff = Bitmap("Backgrounds/JobSubBarsOff.bmp");
        _skillHighlight = CreateImage(device, 1, 1, [0xc3, 0xcd, 0xcd, 0xff]);
        _jobIcons = Bitmap("Buttons/JobIconMultiButton.BMP");
        _vectorJobIcons = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderJobIconMultiButton(scale: 4));
        _salaryButton = Bitmap("Buttons/SalaryButton.bmp");
        _vectorSalaryButton = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderSalaryButtonStrip(scale: 4));
        _performanceButton = Bitmap("Buttons/PerformanceButton.bmp");
        _jobFriendSmiley = Bitmap("Buttons/JobFriendSmiley.bmp");
        _vectorJobFriendSmiley = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderFriendSmileyStrip(10, 11, scale: 4));
        _fameBars = Bitmap("FameSubBars.bmp");
        _fameBarsOff = Bitmap("Backgrounds/FameSubBarsOff.bmp");
        _fameIcons = Bitmap("Buttons/FameIconMultiButton.BMP");
        _vectorFameIcons = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderFameIconMultiButton(scale: 4));
        _fameFriendSmiley = Bitmap("Buttons/FameFriendSmiley.bmp");
        _vectorFameFriendSmiley = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderFriendSmileyStrip(22, 20, scale: 4));

        _interestIcons = new Image[OriginalGameplayLayout.Interests.Count];
        for (int i = 0; i < OriginalGameplayLayout.Interests.Count; i++)
        {
            _interestIcons[i] = Bitmap("Buttons/Interest" + OriginalGameplayLayout.Interests[i] + ".bmp");
        }

        _interestBars = Bitmap("InterestBars.bmp");
        _interestBackground = Bitmap("Backgrounds/InterestBarsBackground.bmp");
        _interestArrows = SimsBitmapFont.SharpTextEnabled
            ? [
                SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderScrollArrowStrip(right: false, scale: 4)),
                SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderScrollArrowStrip(right: true, scale: 4))
              ]
            : [Bitmap("Buttons/ScrollLeft.bmp"), Bitmap("Buttons/ScrollRight.bmp")];
        _relationshipUnknown = Bitmap("People/UnknownRel.bmp");
        _relationshipIcons = [Bitmap("Buttons/Smiley.bmp"), Bitmap("Buttons/Heart.bmp"), Bitmap("Buttons/HeartDeep.bmp")];
        _inventorySorts =
        [
            Bitmap("Buttons/InventoryMagicSort.bmp"),
            Bitmap("Buttons/InventoryOtherSort.bmp"),
            Bitmap("Buttons/InventoryGiftSort.bmp")
        ];
        _vectorInventorySorts =
        [
            SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderInventorySortStrip(0, scale: 4)),
            SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderInventorySortStrip(1, scale: 4)),
            SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderInventorySortStrip(2, scale: 4)),
        ];
        _relationshipFilters =
        [
            Bitmap("Buttons/RelFamilySort.bmp"),
            Bitmap("Buttons/RelFriendSort.bmp"),
            Bitmap("Buttons/RelStarSort.bmp"),
            Bitmap("Buttons/RelAllSort.bmp")
        ];
        _vectorRelationshipFilters =
        [
            SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderRelationshipFilterStrip(0, scale: 4)),
            SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderRelationshipFilterStrip(1, scale: 4)),
            SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderRelationshipFilterStrip(2, scale: 4)),
            SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderRelationshipFilterStrip(3, scale: 4)),
        ];
        _missingInventoryIcon = Bitmap("Catalog/BackButtons/BackCTwo.bmp");
    }

    private void RebuildStaticLabels()
    {
        int motiveCount = OriginalGameplayLayout.Motives.Count;
        _labels = new Image[motiveCount];
        _petLabels = new Image[motiveCount];
        for (int i = 0; i < motiveCount; i++)
        {
            string name = OriginalGameplayLayout.Motives[i];
            _labels[i] = Text(_strings.MotiveLabel(i, false, name), _clockFont, Device);
            _petLabels[i] = Text(_strings.MotiveLabel(i, true, name), _clockFont, Device);
        }

        int traitCount = OriginalGameplayLayout.Traits.Count;
        _traitLabels = new Image[traitCount];
        _petTraitLabels = new Image[traitCount];
        for (int i = 0; i < traitCount; i++)
        {
            string name = OriginalGameplayLayout.Traits[i];
            _traitLabels[i] = Text(_strings.PersonalityTraitLabel(i, false, name), _clockFont, Device);
            string petFallback = i == 4 ? "Friendly" : name;
            _petTraitLabels[i] = Text(_strings.PersonalityTraitLabel(i, true, petFallback), _clockFont, Device);
        }

        _skillLabels = new Image[OriginalGameplayLayout.Skills.Count];
        for (int i = 0; i < OriginalGameplayLayout.Skills.Count; i++)
        {
            _skillLabels[i] = Text(_strings.CareerSkill(OriginalGameplayLayout.Skills[i]), _careerFont, Device);
        }

        string[] dogFallbacks = ["House Breaking", "Obedience", "Tricks"];
        string[] catFallbacks = ["Hunting", "Obedience", "Tricks"];
        _dogSkillLabels = new Image[OriginalGameplayLayout.PetSkills.Count];
        _catSkillLabels = new Image[OriginalGameplayLayout.PetSkills.Count];
        for (int i = 0; i < OriginalGameplayLayout.PetSkills.Count; i++)
        {
            _dogSkillLabels[i] = Text(_strings.PetSkillTitle(i, false, dogFallbacks[i]), _careerFont, Device);
            _catSkillLabels[i] = Text(_strings.PetSkillTitle(i, true, catFallbacks[i]), _careerFont, Device);
        }
    }

    public void RefreshText()
    {
        RebuildStaticLabels();
        _pluginTooltips.Clear();
        _panelTips.Clear();
        _peopleTips.Clear();
        _personTips.Clear();
        _inventoryTooltipCache = null;
        _needsTitleImage = null;
        _cachedClockText = null;
        _cachedFriendsText = null;
        _cachedBudgetText = null;
        _personalityPopupTitle = null;
        _personalityPopupLines = [];

        if (_motivePopupIndex is not null)
        {
            UpdateMotivePopup();
        }
        else if (RelationshipPopupId is not null &&
                 State?.Selected?.Relationships is { } rels &&
                 rels.FirstOrDefault(r => r.NeighborId == RelationshipPopupId) is { } target)
        {
            _relationshipPopupText = null;
            UpdateRelationshipPopup(target);
        }

        if (State is not null && !string.IsNullOrEmpty(_resourceRoot))
        {
            Update(State, _resourceRoot);
        }
    }

    public static Image CreateImage(UIDevice device, SimsBitmapFont.HiDpiRaster raster) =>
        CreateImage(device, raster.PixelWidth, raster.PixelHeight, raster.Rgba, new CGSize(raster.LogicalWidth, raster.LogicalHeight));

    public static Image CreateImage(
        UIDevice device,
        int width,
        int height,
        byte[] pixels,
        bool magenta = false,
        bool blue = false,
        bool decontaminateEdges = false) =>
        CreateImage(device, width, height, pixels, new CGSize(width, height), magenta, blue, decontaminateEdges);

    public static Image CreateImage(
        UIDevice device,
        int width,
        int height,
        byte[] pixels,
        CGSize logicalSize,
        bool magenta = false,
        bool blue = false,
        bool decontaminateEdges = false)
    {
        _ = device;
        ArgumentNullException.ThrowIfNull(pixels);
        if (width <= 0 || height <= 0)
        {
            throw new ContentError("Cannot allocate gameplay panel texture");
        }

        var rgba = SpritePixels.PremultipliedSRGB(
            pixels,
            removeMagenta: magenta,
            removeBlue: blue,
            decontaminateEdges: decontaminateEdges,
            width: width,
            height: height);
        return new Image(new UITexture(width, height, rgba), logicalSize);
    }

    // Original 1x subpanel BMPs bake LiveGadget.bmp perimeter fringe into their outer 2px; mask pixels whose G-R delta stays invariant between State 0 (silver) and State 1 (selected cyan).
    private static byte[] MaskSubpanelOuterFringe(byte[] pixels, int width, int height, int columns)
    {
        var masked = (byte[])pixels.Clone();
        int cols = Math.Max(1, columns);
        if (cols < 2)
            return masked;

        int cellW = width / cols;
        for (int cy = 0; cy < height; cy++)
        {
            for (int cx = 0; cx < cellW; cx++)
            {
                if (cx > 1 && cx < cellW - 2 && cy > 1 && cy < height - 2)
                    continue;

                int i0 = (cy * width + cx) * 4;
                int i1 = (cy * width + cellW + cx) * 4;
                int cyanDelta0 = masked[i0 + 1] - masked[i0];
                int cyanDelta1 = masked[i1 + 1] - masked[i1];
                if (Math.Abs(cyanDelta1 - cyanDelta0) <= 10)
                {
                    for (int col = 0; col < cols; col++)
                    {
                        int off = (cy * width + col * cellW + cx) * 4;
                        masked[off] = 0;
                        masked[off + 1] = 0;
                        masked[off + 2] = 0;
                        masked[off + 3] = 0;
                    }
                }
            }
        }

        return masked;
    }

    public static byte[] MaskIconFrameCorners(byte[] pixels, int width, int height, int columns, int rows)
    {
        ArgumentNullException.ThrowIfNull(pixels);
        int cols = Math.Max(1, columns);
        int rws = Math.Max(1, rows);
        int cellWidth = width / cols;
        int cellHeight = height / rws;

        if (cellWidth == 35 && cellHeight == 41)
        {
            var masked = (byte[])pixels.Clone();
            (int X, int Y)[] corners = [(0, 0), (34, 0), (0, 40), (34, 40)];
            for (int row = 0; row < rws; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    foreach (var (cx, cy) in corners)
                    {
                        int offset = ((row * 41 + cy) * width + (col * 35 + cx)) * 4;
                        if (offset >= 0 && offset + 3 < masked.Length)
                        {
                            masked[offset] = 0;
                            masked[offset + 1] = 0;
                            masked[offset + 2] = 0;
                            masked[offset + 3] = 0;
                        }
                    }
                }
            }

            return masked;
        }

        if (cellWidth != 45 || cellHeight != 45)
        {
            return pixels;
        }

        var maskedCell = (byte[])pixels.Clone();
        for (int y = 0; y < height; y++)
        {
            int cy = y % 45;
            int dy = Math.Min(cy, 44 - cy);
            if (dy >= 3)
            {
                continue;
            }

            for (int x = 0; x < width; x++)
            {
                int cx = x % 45;
                if (dy + Math.Min(cx, 44 - cx) < 3)
                {
                    int offset = (y * width + x) * 4;
                    if (offset >= 0 && offset + 3 < maskedCell.Length)
                    {
                        maskedCell[offset] = 0;
                        maskedCell[offset + 1] = 0;
                        maskedCell[offset + 2] = 0;
                        maskedCell[offset + 3] = 0;
                    }
                }
            }
        }

        return maskedCell;
    }

    public static string Grouped(int value)
    {
        string digits = Math.Abs((long)value).ToString(CultureInfo.InvariantCulture);
        int lead = digits.Length % 3;
        string result = lead > 0 ? digits[..lead] : string.Empty;
        for (int index = lead; index < digits.Length; index += 3)
        {
            if (result.Length > 0)
            {
                result += ",";
            }

            result += digits.Substring(index, 3);
        }

        return (value < 0 ? "-" : string.Empty) + (result.Length == 0 ? "0" : result);
    }

    public static Image Text(string value, SimsBitmapFont font, UIDevice device) =>
        Text(value, font, device, (255, 255, 255));

    public static Image Text(string value, SimsBitmapFont font, UIDevice device, byte r, byte g, byte b) =>
        Text(value, font, device, (r, g, b));

    public static Image Text(string value, SimsBitmapFont font, UIDevice device, (byte R, byte G, byte B) color)
    {
        ArgumentNullException.ThrowIfNull(font);
        return CreateImage(device, font.RasterizeHiDpi(value, color, logicalMargin: 0));
    }

    public CGRect FamilyFriendsRect(int count)
    {
        double textWidth = _clockFont.TextWidth(count.ToString(CultureInfo.InvariantCulture));
        double fontHeight = _clockFont.LineHeight;
        return OriginalGameplayLayout.FamilyFriendsButton(FundsRect, fontHeight, textWidth);
    }

    public void RecordPieChoice(CGPoint point)
    {
        _pendingPieChoiceOrigin = new CGPoint(point.X - 16, point.Y - 16);
    }

    public void Update(GameplayPanelState next, string root)
    {
        ArgumentNullException.ThrowIfNull(next);
        ArgumentException.ThrowIfNullOrEmpty(root);

        next.Validate();
        if (State?.SelectedSim != next.SelectedSim)
        {
            ClearLivePopupState();
        }

        if (!Supports(CurrentSubpanel, next))
        {
            CurrentSubpanel = Subpanel.Needs;
        }

        string resolvedRoot = ResolveRealPath(root);
        double now = MonotonicNowSeconds();
        UpdateMotiveTracking(next, resolvedRoot, (ulong)(Math.Max(0.0, now) * 1000.0));

        var used = new HashSet<string>(StringComparer.Ordinal);
        Image? LoadResource(GameplayPanelState.Image? reference)
        {
            if (reference is null)
            {
                return null;
            }

            reference.Validate();
            used.Add(reference.File);
            if (_resources.TryGetValue(reference.File, out var cached))
            {
                return cached;
            }

            string resolvedFile = ResolveRealPath(Path.Combine(resolvedRoot, reference.File));
            string? parentDir = Path.GetDirectoryName(resolvedFile);
            var fileInfo = new FileInfo(resolvedFile);
            if (!PathsEqual(parentDir, resolvedRoot) || !fileInfo.Exists || fileInfo.Length > 4L * 1024 * 1024)
            {
                throw new ContentError("Gameplay image escapes resource directory or exceeds size limit");
            }

            var bitmap = new SimsBitmap(File.ReadAllBytes(resolvedFile));
            if (bitmap.Width > 512 || bitmap.Height > 512 ||
                reference.Columns <= 0 || reference.Rows <= 0 ||
                bitmap.Width % reference.Columns != 0 || bitmap.Height % reference.Rows != 0)
            {
                throw new ContentError("Invalid gameplay image dimensions");
            }

            var masked = bitmap.HasAlpha
                ? bitmap.Rgba
                : MaskIconFrameCorners(bitmap.Rgba, bitmap.Width, bitmap.Height, reference.Columns, reference.Rows);
            var image = CreateImage(
                Device,
                bitmap.Width,
                bitmap.Height,
                masked,
                magenta: !bitmap.HasAlpha,
                decontaminateEdges: bitmap.HasAlpha);
            _resources[reference.File] = image;
            return image;
        }

        var parts = new List<Part>
        {
            new(ActiveUniversal, new CGRect(0, -33, 220, 183)),
            new(ActivePatch, new CGRect(7, -3, _patch.Size.Width, _patch.Size.Height)),
            new(ActiveGadget, new CGRect(413, 50, 108, 100))
        };
        if (SimsBitmapFont.SharpTextEnabled && ActiveUniversal.Texture != _universal.Texture)
        {
            parts.Add(new Part(_vectorLcdFriendSmiley, FamilyFriendsSmileyRect));
        }

        bool selectedIsPet = ((next.Selected?.Gender ?? 0) & 6) != 0;
        for (int index = 0; index < _buttons.Length; index++)
        {
            if ((selectedIsPet || next.Selected is null) && index is 5 or 6)
            {
                continue;
            }

            var image = SimsBitmapFont.SharpTextEnabled && _vectorButtons[index] is { } vBtn ? vBtn : _buttons[index];
            bool enabled = false;
            foreach (var panel in MainTabSubpanels)
            {
                if (panel.ButtonIndex() == index && Supports(panel, next))
                {
                    enabled = true;
                    break;
                }
            }

            float column = !enabled ? 0.75f : index == CurrentSubpanel.ButtonIndex() ? 0.25f : 0f;
            parts.Add(new Part(image, ButtonRect(index), new Vector4(column, 0f, 0.25f, 1f)));
        }

        int householdCount = Math.Min(OriginalGameplayLayout.MaxHouseholdPortraits, next.Household.Count);
        for (int index = 0; index < householdCount; index++)
        {
            var sim = next.Household[index];
            var portraitRect = OriginalGameplayLayout.Portrait(index);
            parts.Add(new Part(ActivePeople, portraitRect, new Vector4(sim.Id == next.SelectedSim ? 0.25f : 0f, 0f, 0.25f, 1f)));
            if (sim.Portrait is { } reference && LoadResource(reference) is { } portraitImage)
            {
                var faceSize = new CGSize(portraitImage.Size.Width / reference.Columns, portraitImage.Size.Height / reference.Rows);
                int expression = 0;
                parts.Add(new Part(
                    portraitImage,
                    new CGRect(
                        portraitRect.X + portraitRect.Width / 2.0 - faceSize.Width / 2.0,
                        portraitRect.Y + portraitRect.Height / 2.0 - faceSize.Height / 2.0,
                        faceSize.Width,
                        faceSize.Height),
                    new Vector4((float)expression / reference.Columns, 0f, 1f / reference.Columns, 1f / reference.Rows)));
            }
            else
            {
                parts.Add(new Part(_unknown, portraitRect, new Vector4(0f, 0f, 0.25f, 1f / 3f)));
            }
        }

        var bay = OriginalGameplayLayout.CenteredBay(_grid.Width);
        if (next.Selected is not null || (CurrentSubpanel == Subpanel.House && next.House is not null))
        {
            AppendBayDividers(bay, parts);
        }

        if (next.Selected is { } selected)
        {
            int mood = Math.Min(5, Math.Max(-5, (int)((selected.Mood + 100) * 0.05472637f - 5f)));
            bool vecBars = SimsBitmapFont.SharpTextEnabled;
            double barTexH = vecBars ? 26.0 : 25.0;
            if (mood > 0)
            {
                double topOff = (5 - mood) * 5.0;
                double drawH = barTexH - topOff;
                parts.Add(new Part(ActiveGreenBars, new CGRect(425, 53 + topOff, 27, drawH), new Vector4(0f, (float)(topOff / barTexH), 1f, (float)(drawH / barTexH))));
            }
            else if (mood < 0)
            {
                double extraTop = vecBars ? 1.0 : 0.0;
                double drawH = -mood * 5.0 + extraTop;
                parts.Add(new Part(ActiveRedBars, new CGRect(425, 123 - extraTop, 27, drawH), new Vector4(0f, 0f, 1f, (float)(drawH / barTexH))));
            }
            else
            {
                double gH = vecBars ? 3.0 : 2.0;
                double rH = vecBars ? 3.0 : 2.0;
                parts.Add(new Part(ActiveGreenBars, new CGRect(425, 76, 27, gH), new Vector4(0f, (float)((barTexH - gH) / barTexH), 1f, (float)(gH / barTexH))));
                parts.Add(new Part(ActiveRedBars, new CGRect(425, 123 - (vecBars ? 1.0 : 0.0), 27, rH), new Vector4(0f, 0f, 1f, (float)(rH / barTexH))));
            }

            if (CurrentSubpanel == Subpanel.Needs)
            {
                if (_needsTitleImage is not { } title)
                {
                    title = Text(_strings.NeedsTitle, Font, Device);
                    _needsTitleImage = title;
                }

                var titlePoint = OriginalGameplayLayout.NeedsHeaderOrigin(_grid.Width, _asianInventoryLayout);
                parts.Add(new Part(title, new CGRect(titlePoint.X, titlePoint.Y, title.Size.Width, title.Size.Height)));
                var activeLabels = ((selected.Gender ?? 0) & 6) != 0 ? _petLabels : _labels;
                for (int index = 0; index < activeLabels.Length; index++)
                {
                    var label = activeLabels[index];
                    var needRect = OriginalGameplayLayout.NeedRect(index, _grid.Width);
                    parts.Add(new Part(
                        label,
                        new CGRect(
                            needRect.X + needRect.Width / 2.0 - label.Size.Width / 2.0,
                            needRect.Y + (10 - _clockFont.LineHeight) / 2.0,
                            label.Size.Width,
                            label.Size.Height)));
                }
            }
            else if (CurrentSubpanel == Subpanel.House && next.House is { } houseValues)
            {
                AppendHouseParts(houseValues, parts);
            }
            else if (CurrentSubpanel == Subpanel.Relationships && selected.Relationships is { } relValues)
            {
                var title = Text(_strings.RelationshipsTitle, _careerFont, Device);
                var titlePoint = StripHeaderOrigin();
                parts.Add(new Part(title, new CGRect(titlePoint.X, titlePoint.Y, title.Size.Width, title.Size.Height)));
                var relationships = OriginalGameplayLayout.Relationships(relValues, RelationshipFilter);
                int capacity = StripRelationshipCapacity;
                RelationshipPage = Math.Min(RelationshipPage, _grid.PageCount(relationships.Count, capacity) - 1);

                var allFilters = Enum.GetValues<OriginalGameplayLayout.RelationshipFilter>();
                var activeRelFilters = SimsBitmapFont.SharpTextEnabled ? _vectorRelationshipFilters : _relationshipFilters;
                for (int index = 0; index < allFilters.Length; index++)
                {
                    parts.Add(new Part(
                        activeRelFilters[index],
                        RelationshipFilterRect(index),
                        new Vector4(allFilters[index] == RelationshipFilter ? 0.25f : 0f, 0f, 0.25f, 1f)));
                }

                int slot = 0;
                foreach (var relationship in relationships.Skip(RelationshipPage * capacity).Take(capacity))
                {
                    var slotRect = RelationshipSlotRect(slot++);
                    var image = LoadResource(relationship.Portrait) ?? _relationshipUnknown;
                    int columns = relationship.Portrait?.Columns ?? 5;
                    var faceSize = new CGSize(image.Size.Width / columns, image.Size.Height);
                    int expression = Math.Min(columns - 1, OriginalGameplayLayout.RelationshipExpression(relationship.Lifetime));
                    parts.Add(new Part(
                        image,
                        new CGRect(slotRect.X + slotRect.Width / 2.0 - faceSize.Width / 2.0, slotRect.Y, faceSize.Width, faceSize.Height),
                        new Vector4((float)expression / columns, 0f, 1f / columns, 1f)));

                    var daily = Text(Math.Min(100, Math.Max(-100, relationship.Daily)).ToString(CultureInfo.InvariantCulture), _careerFont, Device);
                    parts.Add(new Part(daily, new CGRect(slotRect.X, slotRect.Y + faceSize.Height - 2.0, daily.Size.Width, daily.Size.Height)));

                    double barY = slotRect.Y + faceSize.Height - 2.0 + _careerFont.LineHeight;
                    (int Value, double Y, int Height)[] bars =
                    [
                        (relationship.Daily, barY, 2),
                        (relationship.Lifetime, barY + 4.0, 4)
                    ];
                    foreach (var (value, y, height) in bars)
                    {
                        var barColors = OriginalGameplayLayout.BarColors(value);
                        int barW = OriginalGameplayLayout.RelationshipWidth(value);
                        var pixels = new byte[40 * height * 4];
                        for (int row = 0; row < height; row++)
                        {
                            for (int column = 0; column < 40; column++)
                            {
                                var rgb = column < barW ? barColors.Green : barColors.Red;
                                bool divider = (40 - barW > 1) && (column == barW - 1);
                                int offset = (row * 40 + column) * 4;
                                pixels[offset] = divider ? (byte)0 : rgb.X;
                                pixels[offset + 1] = divider ? (byte)0 : rgb.Y;
                                pixels[offset + 2] = divider ? (byte)0 : rgb.Z;
                                pixels[offset + 3] = 255;
                            }
                        }

                        var barImg = CreateImage(Device, 40, height, pixels);
                        parts.Add(new Part(barImg, new CGRect(slotRect.X + 2.0, y, 40.0, height)));
                    }

                    var lifetime = Text(Math.Min(100, Math.Max(-100, relationship.Lifetime)).ToString(CultureInfo.InvariantCulture), _careerFont, Device);
                    double valueY = barY + 10.0;
                    parts.Add(new Part(lifetime, new CGRect(slotRect.X + 2.0, valueY, lifetime.Size.Width, lifetime.Size.Height)));

                    double iconY = valueY - 2.0 + _careerFont.LineHeight;
                    if (relationship.Friend)
                    {
                        parts.Add(new Part(_relationshipIcons[0], new CGRect(slotRect.X + 2.0, iconY, 9, 9)));
                    }

                    if (relationship.Love || relationship.Crush)
                    {
                        parts.Add(new Part(_relationshipIcons[relationship.Love ? 2 : 1], new CGRect(slotRect.X + 14.0, iconY, 9, 9)));
                    }
                }

                for (int direction = 0; direction <= 1; direction++)
                {
                    bool available = direction == 0 ? RelationshipPage > 0 : (RelationshipPage + 1) * capacity < relationships.Count;
                    if (available)
                    {
                        parts.Add(new Part(ScrollArrows[direction], RelationshipArrowRect(direction == 1), new Vector4(0f, 0f, 0.25f, 1f)));
                    }
                }
            }
            else if (CurrentSubpanel == Subpanel.Inventory && selected.Inventory is { } invValues)
            {
                var items = OriginalGameplayLayout.InventoryItems(invValues, InventorySort);
                int capacity = StripInventoryCapacity;
                InventoryPage = Math.Min(InventoryPage, _grid.PageCount(items.Count, capacity) - 1);
                var title = Text(_strings.InventoryTitle, _careerFont, Device);
                var titlePoint = StripHeaderOrigin();
                parts.Add(new Part(title, new CGRect(titlePoint.X, titlePoint.Y, title.Size.Width, title.Size.Height)));

                var allSorts = Enum.GetValues<OriginalGameplayLayout.InventorySort>();
                var activeInvSorts = SimsBitmapFont.SharpTextEnabled ? _vectorInventorySorts : _inventorySorts;
                for (int index = 0; index < allSorts.Length; index++)
                {
                    parts.Add(new Part(
                        activeInvSorts[index],
                        InventorySortRect(index),
                        new Vector4(allSorts[index] == InventorySort ? 0.25f : 0f, 0f, 0.25f, 1f)));
                }

                int tileIndex = 0;
                foreach (var item in items.Skip(InventoryPage * capacity).Take(capacity))
                {
                    var tileRect = InventoryTileRect(tileIndex++);
                    double iconHeight;
                    if (item.Icon is { } reference && LoadResource(reference) is { } iconImage)
                    {
                        var iconSize = new CGSize(iconImage.Size.Width / reference.Columns, iconImage.Size.Height / reference.Rows);
                        iconHeight = iconSize.Height;
                        parts.Add(new Part(
                            iconImage,
                            new CGRect(tileRect.X + Math.Floor((tileRect.Width - iconSize.Width) / 2.0), tileRect.Y, iconSize.Width, iconSize.Height),
                            new Vector4(0f, 0f, 1f / reference.Columns, 1f / reference.Rows)));
                    }
                    else
                    {
                        var iconSize = new CGSize(_missingInventoryIcon.Size.Width / 2.0, _missingInventoryIcon.Size.Height);
                        iconHeight = iconSize.Height;
                        parts.Add(new Part(
                            _missingInventoryIcon,
                            new CGRect(tileRect.X + Math.Floor((tileRect.Width - iconSize.Width) / 2.0), tileRect.Y, iconSize.Width, iconSize.Height),
                            new Vector4(0f, 0f, 0.5f, 1f)));
                    }

                    var countImg = Text(item.Count.ToString(CultureInfo.InvariantCulture), _careerFont, Device);
                    parts.Add(new Part(
                        countImg,
                        new CGRect(tileRect.X + Math.Floor((tileRect.Width - countImg.Size.Width) / 2.0), tileRect.Y + iconHeight + 3.0, countImg.Size.Width, countImg.Size.Height)));
                }

                for (int direction = 0; direction <= 1; direction++)
                {
                    bool available = direction == 0 ? InventoryPage > 0 : (InventoryPage + 1) * capacity < items.Count;
                    if (available)
                    {
                        parts.Add(new Part(ScrollArrows[direction], InventoryArrowRect(direction == 1), new Vector4(0f, 0f, 0.25f, 1f)));
                    }
                }
            }
            else if (CurrentSubpanel == Subpanel.Personality && selected.Personality is { } traits)
            {
                bool isPet = ((selected.Gender ?? 0) & 6) != 0;
                var activeTraitLabels = isPet ? _petTraitLabels : _traitLabels;
                int labelWidth = MaxImageWidth(activeTraitLabels);
                var layout = OriginalGameplayLayout.PersonalitySubpanelLayout(_grid.Width, labelWidth, _asianInventoryLayout);
                var header = Text(_strings.PersonalityTitle, Font, Device);
                var headerPoint = OriginalGameplayLayout.InventoryTitle(_asianInventoryLayout);
                parts.Add(new Part(header, new CGRect(layout.HeaderX, headerPoint.Y, header.Size.Width, header.Size.Height)));

                double lw = labelWidth;
                for (int index = 0; index < activeTraitLabels.Length && index < layout.TraitRects.Count; index++)
                {
                    var label = activeTraitLabels[index];
                    var traitRect = layout.TraitRects[index];
                    double barX = traitRect.X + lw + 6.0;
                    double barY = traitRect.Y + Math.Max(0, (_clockFont.LineHeight - 14) / 2);
                    parts.Add(new Part(
                        label,
                        new CGRect(traitRect.X + lw + 3.0 - label.Size.Width, traitRect.Y + Math.Max(0, (14 - _clockFont.LineHeight) / 2), label.Size.Width, label.Size.Height)));
                    parts.Add(new Part(_personalityBackground, new CGRect(barX, barY, 40, 14)));
                    int traitVal = traits.TryGetValue(OriginalGameplayLayout.Traits[index], out var tv) ? tv : 0;
                    double barW = OriginalGameplayLayout.PersonalityWidth(traitVal);
                    if (barW > 0.0)
                    {
                        parts.Add(new Part(_personalityBars, new CGRect(barX, barY - 1.0, barW, 16.0), new Vector4(0f, 0f, (float)barW / 40f, 1f)));
                    }
                }

                if (!isPet && selected.Zodiac is { } stored)
                {
                    int zodiac = OriginalGameplayLayout.Zodiac(traits, stored);
                    int signIndex = zodiac - 1;
                    if (signIndex >= 0 && signIndex < OriginalGameplayLayout.Signs.Count)
                    {
                        string signName = _strings.Sign(signIndex, OriginalGameplayLayout.Signs[signIndex]);
                        double maxSignW = Math.Max(50.0, bay.Bay.MaxX - layout.ZodiacOrigin.X - 4.0);
                        var chosenFont = layout.UsesBottomAlignedZodiac || _zodiacFont.TextWidth(signName) <= maxSignW ? _zodiacFont : Font;
                        var signImg = Text(signName, chosenFont, Device);
                        double signY = layout.UsesBottomAlignedZodiac ? layout.ZodiacOrigin.Y - signImg.Size.Height : layout.ZodiacOrigin.Y;
                        parts.Add(new Part(signImg, new CGRect(layout.ZodiacOrigin.X, signY, signImg.Size.Width, signImg.Size.Height)));
                    }
                }
            }
            else if (CurrentSubpanel == Subpanel.Interests && selected.Interests is { } interestValues && selected.Career is { } interestCareer)
            {
                var indices = OriginalGameplayLayout.InterestIndices(interestCareer.Age);
                int capacity = StripInterestCapacity;
                InterestPage = Math.Min(InterestPage, _grid.PageCount(indices.Count, capacity) - 1);
                var title = Text(_strings.InterestsTitle(), _careerFont, Device);
                parts.Add(new Part(title, new CGRect(525 + ClassicStripOffset, 50, title.Size.Width, title.Size.Height)));

                int slot = 0;
                foreach (int index in indices.Skip(InterestPage * capacity).Take(capacity))
                {
                    var slotRect = InterestSlotRect(slot++);
                    var icon = _interestIcons[index];
                    parts.Add(new Part(icon, new CGRect(slotRect.X, slotRect.Y, icon.Size.Width, icon.Size.Height)));
                    var barRect = new CGRect(slotRect.X + icon.Size.Width + 5.0, slotRect.Y + 5.0, 40.0, 16.0);
                    parts.Add(new Part(_interestBackground, barRect));
                    int val = index < interestValues.Count ? interestValues[index] : 0;
                    double barW = OriginalGameplayLayout.PersonalityWidth(val);
                    if (barW > 0.0)
                    {
                        parts.Add(new Part(_interestBars, new CGRect(barRect.X, barRect.Y, barW, barRect.Height), new Vector4(0f, 0f, (float)barW / 40f, 1f)));
                    }
                }

                for (int direction = 0; direction <= 1; direction++)
                {
                    bool available = direction == 0 ? InterestPage > 0 : (InterestPage + 1) * capacity < indices.Count;
                    if (available)
                    {
                        parts.Add(new Part(_interestArrows[direction], InterestArrowRect(direction == 1), new Vector4(0f, 0f, 0.25f, 1f)));
                    }
                }
            }
            else if (CurrentSubpanel == Subpanel.PetSkills && selected.PetSkills is { } petSkillValues)
            {
                var (headerOrigin, skillSlots) = OriginalGameplayLayout.PetSkillsSubpanelLayout(_grid.Width);
                var header = Text(_strings.PetSkillsTitle(), _careerFont, Device);
                parts.Add(new Part(header, new CGRect(headerOrigin.X, headerOrigin.Y, header.Size.Width, header.Size.Height)));
                bool isCat = ((selected.Gender ?? 0) & 4) != 0;
                var activePetLabels = isCat ? _catSkillLabels : _dogSkillLabels;
                for (int index = 0; index < activePetLabels.Length && index < skillSlots.Count; index++)
                {
                    var label = activePetLabels[index];
                    var slot = skillSlots[index];
                    parts.Add(new Part(label, new CGRect(slot.Label.X + slot.Label.Width - label.Size.Width, slot.Label.Y, label.Size.Width, label.Size.Height)));
                    var barRect = slot.Bar;
                    parts.Add(new Part(_skillBarsOff, barRect));
                    int skillVal = petSkillValues.TryGetValue(OriginalGameplayLayout.PetSkills[index], out var sv) ? sv : 0;
                    double barW = OriginalGameplayLayout.PetSkillWidth(skillVal);
                    if (barW > 0.0)
                    {
                        parts.Add(new Part(_skillBars, new CGRect(barRect.X, barRect.Y, barW, barRect.Height), new Vector4(0f, 0f, (float)barW / 40f, 1f)));
                    }
                }
            }
            else if (CurrentSubpanel == Subpanel.Career && selected.Skills is { } skills && selected.Career is { } career)
            {
                var layout = OriginalGameplayLayout.GetCareerSubpanelLayout(_grid.Width, _asianInventoryLayout);
                for (int index = 0; index < _skillLabels.Length && index < layout.Skills.Count; index++)
                {
                    var label = _skillLabels[index];
                    var slot = layout.Skills[index];
                    parts.Add(new Part(label, new CGRect(slot.Label.X + slot.Label.Width - label.Size.Width, slot.Label.Y, label.Size.Width, label.Size.Height)));
                    var barRect = slot.Bar;
                    parts.Add(new Part(_skillBarsOff, barRect));
                    int value = skills.TryGetValue(OriginalGameplayLayout.Skills[index], out var sv) ? sv : 0;
                    double barW = OriginalGameplayLayout.PersonalityWidth(value);
                    if (barW > 0.0)
                    {
                        parts.Add(new Part(_skillBars, new CGRect(barRect.X, barRect.Y, barW, barRect.Height), new Vector4(0f, 0f, (float)barW / 40f, 1f)));
                    }

                    if (OriginalGameplayLayout.RequiredSkillWidth(index, value, career) is { } required)
                    {
                        double marker = required;
                        parts.Add(new Part(_skillHighlight, new CGRect(barRect.X + marker - 1.0, barRect.Y, _skillHighlight.Size.Width, barRect.Height)));
                        parts.Add(new Part(_skillHighlight, new CGRect(barRect.X - 16.0, barRect.Y + barRect.Height - 1.0, marker + 16.0, 1.0)));
                    }
                }

                double sx = layout.JobIconOrigin.X;
                double summaryW = layout.JobSummaryRect.Width;
                int jobIconRow = career.HasJob && !career.IsSchool ? Math.Min(21, Math.Max(0, career.Type)) : 0;
                var activeJobIcons = ActiveJobIcons;
                double jobIconHeight = activeJobIcons.Size.Height / 22.0;
                double jobIconWidth = activeJobIcons.Size.Width / 4.0;
                parts.Add(new Part(
                    activeJobIcons,
                    new CGRect(sx, layout.JobIconOrigin.Y, jobIconWidth, jobIconHeight),
                    new Vector4(0f, jobIconRow / 22f, 0.25f, 1f / 22f)));

                var jobHeader = Text(_strings.CareerJobLabel(), _careerFont, Device);
                parts.Add(new Part(jobHeader, new CGRect(layout.HeaderOrigin.X, layout.HeaderOrigin.Y, jobHeader.Size.Width, jobHeader.Size.Height)));

                string titleText;
                if (!career.HasJob)
                {
                    titleText = _strings.CareerUnemployed();
                }
                else if (!string.IsNullOrEmpty(career.Title))
                {
                    titleText = career.Title;
                }
                else
                {
                    titleText = career.IsSchool ? _strings.CareerSchool() : string.Empty;
                }

                var wrappedLines = _careerFont.WrappedLines(titleText, Math.Max(40, (int)summaryW));
                int titleTop = 54 + (int)jobIconHeight;
                int maxLines = Math.Max(1, (45 - (int)jobIconHeight) / Math.Max(1, _careerFont.LineHeight));
                int lineCount = Math.Min(maxLines, wrappedLines.Count);
                for (int index = 0; index < lineCount; index++)
                {
                    var lineImage = Text(wrappedLines[index], _careerFont, Device);
                    parts.Add(new Part(lineImage, new CGRect(sx, titleTop + index * _careerFont.LineHeight, lineImage.Size.Width, lineImage.Size.Height)));
                }

                var activeSalaryBtn = ActiveSalaryButton;
                double salaryIconW = activeSalaryBtn.Size.Width / 4.0;
                double salaryIconH = activeSalaryBtn.Size.Height;
                parts.Add(new Part(
                    activeSalaryBtn,
                    new CGRect(sx, layout.SalaryRect.Y + Math.Floor((15.0 - salaryIconH) / 2.0), salaryIconW, salaryIconH),
                    new Vector4(0f, 0f, 0.25f, 1f)));

                string salary = career.HasJob && !career.IsSchool
                    ? "§" + (career.Salary ?? 0).ToString(CultureInfo.InvariantCulture)
                    : _strings.CareerUnavailable(false);
                var salaryImage = Text(salary, _careerFont, Device);
                double salaryTextW = Math.Min(Math.Max(1.0, summaryW - (salaryIconW + 3.0)), salaryImage.Size.Width);
                parts.Add(new Part(
                    salaryImage,
                    new CGRect(sx + salaryIconW + 3.0, layout.SalaryRect.Y, salaryTextW, salaryImage.Size.Height),
                    new Vector4(0f, 0f, (float)(salaryTextW / Math.Max(1.0, salaryImage.Size.Width)), 1f)));

                double perfIconW = _performanceButton.Size.Width / 4.0;
                double perfIconH = _performanceButton.Size.Height;
                parts.Add(new Part(
                    _performanceButton,
                    new CGRect(sx, layout.PerformanceRect.Y, perfIconW, perfIconH),
                    new Vector4(0f, 0f, 0.25f, 1f)));

                string rating = career.HasJob
                    ? career.PerformanceLabel ?? _strings.CareerUnavailable(true)
                    : _strings.CareerUnavailable(true);
                var ratingImage = Text(rating, _careerFont, Device);
                double ratingTextW = Math.Min(Math.Max(1.0, summaryW - (perfIconW + 3.0)), ratingImage.Size.Width);
                parts.Add(new Part(
                    ratingImage,
                    new CGRect(sx + perfIconW + 3.0, layout.PerformanceRect.Y, ratingTextW, ratingImage.Size.Height),
                    new Vector4(0f, 0f, (float)(ratingTextW / Math.Max(1.0, ratingImage.Size.Width)), 1f)));

                if (career.FriendsNeeded is { } requiredFriends)
                {
                    var friendsImage = Text(_strings.CareerNeedFriends(requiredFriends), _careerFont, Device);
                    parts.Add(new Part(friendsImage, new CGRect(sx, layout.FriendsRect.Y, friendsImage.Size.Width, friendsImage.Size.Height)));
                    var activeJobSmiley = ActiveJobFriendSmiley;
                    double friendIconW = activeJobSmiley.Size.Width / 4.0;
                    double friendIconH = activeJobSmiley.Size.Height;
                    parts.Add(new Part(
                        activeJobSmiley,
                        new CGRect(sx + friendsImage.Size.Width + 3.0, layout.FriendsRect.Y + 2.0, friendIconW, friendIconH),
                        new Vector4(0f, 0f, 0.25f, 1f)));
                }

                if (career.IsSchool && career.ReportCardGrade is not null)
                {
                    var reportLabel = Text(_strings.ReportCardLabel(), _careerFont, Device);
                    parts.Add(new Part(reportLabel, new CGRect(layout.ReportCardRect.X, layout.ReportCardRect.Y, reportLabel.Size.Width, reportLabel.Size.Height)));
                }
            }
            else if (CurrentSubpanel == Subpanel.ReportCard &&
                     selected.Career is { IsSchool: true, ReportCardGrade: { } grade })
            {
                var titleImg = Text(_strings.ReportCardLabel(), _careerFont, Device);
                var gradeImg = Text(grade, _zodiacFont, Device);
                double headerX = bay.Bay.MinX + (bay.IsFramed ? 24.0 : 5.0);
                var headerOrigin = _asianInventoryLayout ? new CGPoint(headerX, 55) : new CGPoint(headerX, 50);
                parts.Add(new Part(titleImg, new CGRect(headerOrigin.X, headerOrigin.Y, titleImg.Size.Width, titleImg.Size.Height)));
                parts.Add(new Part(
                    gradeImg,
                    new CGRect(
                        bay.Bay.MinX + Math.Floor((bay.Bay.Width - gradeImg.Size.Width) / 2.0),
                        50.0 + Math.Floor((100.0 - gradeImg.Size.Height) / 2.0),
                        gradeImg.Size.Width,
                        gradeImg.Size.Height)));
            }
            else if (CurrentSubpanel == Subpanel.Fame && selected.Fame is { } fame)
            {
                var layout = OriginalGameplayLayout.GetFameSubpanelLayout(_grid.Width, _asianInventoryLayout);
                var header = Text(_strings.FameHeader(), _careerFont, Device);
                parts.Add(new Part(header, new CGRect(layout.HeaderOrigin.X, layout.HeaderOrigin.Y, header.Size.Width, header.Size.Height)));
                var fameTrack = layout.StarBar;
                parts.Add(new Part(_fameBarsOff, fameTrack));
                double fameWidth = Math.Min(10, Math.Max(0, fame.Level)) * 8.0;
                if (fameWidth > 0.0)
                {
                    parts.Add(new Part(_fameBars, new CGRect(fameTrack.X, fameTrack.Y, fameWidth, fameTrack.Height), new Vector4(0f, 0f, (float)(fameWidth / 80.0), 1f)));
                }

                var titleImg = Text(fame.Title, _careerFont, Device);
                var titleBounds = layout.TitleRect;
                parts.Add(new Part(titleImg, new CGRect(titleBounds.X, titleBounds.Y, Math.Min(titleBounds.Width, titleImg.Size.Width), titleImg.Size.Height)));

                for (int index = 0; index < _skillLabels.Length && index < layout.Skills.Count; index++)
                {
                    var label = _skillLabels[index];
                    var slot = layout.Skills[index];
                    parts.Add(new Part(label, new CGRect(slot.Label.X + slot.Label.Width - label.Size.Width, slot.Label.Y, label.Size.Width, label.Size.Height)));
                    var barRect = slot.Bar;
                    parts.Add(new Part(_skillBarsOff, barRect));
                    int fameSkill = index < fame.Skills.Count ? fame.Skills[index] : 0;
                    double barW = OriginalGameplayLayout.PersonalityWidth(fameSkill);
                    if (barW > 0.0)
                    {
                        parts.Add(new Part(_skillBars, new CGRect(barRect.X, barRect.Y, barW, barRect.Height), new Vector4(0f, 0f, (float)(barW / 40.0), 1f)));
                    }

                    int requirement = index < fame.SkillRequirements.Count ? fame.SkillRequirements[index] : 0;
                    if (requirement > 0)
                    {
                        double marker = requirement * 4.0;
                        parts.Add(new Part(_skillHighlight, new CGRect(barRect.X + marker - 1.0, barRect.Y, _skillHighlight.Size.Width, barRect.Height)));
                        parts.Add(new Part(_skillHighlight, new CGRect(barRect.X - 16.0, barRect.Y + barRect.Height - 1.0, marker + 16.0, 1.0)));
                    }
                }

                var friendBounds = layout.FriendsRect;
                var activeFameSmiley = ActiveFameFriendSmiley;
                double friendIconW = activeFameSmiley.Size.Width / 4.0;
                double friendIconH = activeFameSmiley.Size.Height;
                parts.Add(new Part(activeFameSmiley, new CGRect(friendBounds.X, friendBounds.Y, friendIconW, friendIconH), new Vector4(0f, 0f, 0.25f, 1f)));

                string starPowerString = (fame.FriendStarPower * 0.5).ToString("0.0", CultureInfo.InvariantCulture);
                string friendLabel = fame.FriendStarPower < fame.FriendsNeeded * 2
                    ? _strings.FameNeedFriends(starPowerString, fame.FriendsNeeded)
                    : starPowerString;
                var friendText = Text(friendLabel, _careerFont, Device);
                parts.Add(new Part(friendText, new CGRect(friendBounds.X + friendIconW + 3.0, friendBounds.Y, friendText.Size.Width, friendText.Size.Height)));
            }
        }
        else if (CurrentSubpanel == Subpanel.House && next.House is { } unownedHouse)
        {
            AppendHouseParts(unownedHouse, parts);
        }

        int hour = next.Hours % 12 == 0 ? 12 : next.Hours % 12;
        string meridiem = _strings.PanelTip(next.Hours < 12 ? 21 : 22, next.Hours < 12 ? "AM" : "PM");
        var statusParts = new List<Part>();
        string clockText = $"{hour}:{next.Minutes:D2} {meridiem}";
        if (_cachedClockText is not { } cachedClock || !string.Equals(cachedClock.Text, clockText, StringComparison.Ordinal))
        {
            cachedClock = (clockText, Text(clockText, _clockFont, Device, (0x29, 0xe6, 0x5e)));
            _cachedClockText = cachedClock;
        }
        var clockImg = cachedClock.Image;
        statusParts.Add(new Part(clockImg, new CGRect(123.0 - clockImg.Size.Width / 2.0, 85.0, clockImg.Size.Width, clockImg.Size.Height)));

        if (next.FamilyFriends is { } familyFriends)
        {
            string friendsText = familyFriends.ToString(CultureInfo.InvariantCulture);
            if (_cachedFriendsText is not { } cachedFriends || !string.Equals(cachedFriends.Text, friendsText, StringComparison.Ordinal))
            {
                cachedFriends = (friendsText, Text(friendsText, _clockFont, Device, (0x29, 0xe6, 0x5e)));
                _cachedFriendsText = cachedFriends;
            }
            var countLabel = cachedFriends.Image;
            statusParts.Add(new Part(
                countLabel,
                new CGRect(FamilyFriendsLabelX, FamilyFriendsTextY, countLabel.Size.Width, countLabel.Size.Height)));
        }

        if (next.Budget is { } budget)
        {
            string budgetText = "§" + Grouped(budget);
            if (_cachedBudgetText is not { } cachedBudget || !string.Equals(cachedBudget.Text, budgetText, StringComparison.Ordinal))
            {
                cachedBudget = (budgetText, Text(budgetText, Font, Device, (0x29, 0xe6, 0x5e)));
                _cachedBudgetText = cachedBudget;
            }
            var money = cachedBudget.Image;
            statusParts.Add(new Part(money, new CGRect(178.0 - money.Size.Width, 125.0, money.Size.Width, money.Size.Height)));
        }

        parts.AddRange(statusParts);

        var actions = new List<(GameplayPanelState.Action Action, Image? Icon)>();
        if (next.Selected?.Actions is { } rawActions)
        {
            foreach (var action in rawActions)
            {
                if (action.Visible)
                {
                    actions.Add((action, LoadResource(action.Icon)));
                }
            }
        }

        if (next.Selected?.Id != State?.Selected?.Id)
        {
            _actionAnimations.Clear();
            _optimisticCancelledTokens.Clear();
            _pendingPieChoiceOrigin = null;
        }

        var nextAnimations = new Dictionary<string, ActionAnimation>(StringComparer.Ordinal);
        var visibleTokens = new HashSet<string>(StringComparer.Ordinal);
        for (int index = 0; index < actions.Count; index++)
        {
            string token = actions[index].Action.Token;
            visibleTokens.Add(token);
            var targetRect = OriginalGameplayLayout.Action(index);
            var target = new CGPoint(targetRect.X, targetRect.Y);
            if (_actionAnimations.TryGetValue(token, out var existing))
            {
                if (existing.TargetOrigin.X != target.X || existing.TargetOrigin.Y != target.Y)
                {
                    var current = InterfaceEffects ? existing.CurrentOrigin(now) : target;
                    nextAnimations[token] = new ActionAnimation
                    {
                        StartOrigin = current,
                        TargetOrigin = target,
                        StartedAt = InterfaceEffects ? now : 0.0
                    };
                }
                else
                {
                    nextAnimations[token] = existing;
                }
            }
            else if (_pendingPieChoiceOrigin is { } start && InterfaceEffects)
            {
                _pendingPieChoiceOrigin = null;
                nextAnimations[token] = new ActionAnimation
                {
                    StartOrigin = start,
                    TargetOrigin = target,
                    StartedAt = now
                };
            }
            else
            {
                nextAnimations[token] = new ActionAnimation
                {
                    StartOrigin = target,
                    TargetOrigin = target,
                    StartedAt = 0.0
                };
            }
        }

        _actionAnimations = nextAnimations;
        _optimisticCancelledTokens.IntersectWith(visibleTokens);
        PieHead = LoadResource(next.Selected?.PieHead);
        _body = parts;
        _statusBody = statusParts;
        _queued = actions;
        State = next;
        _resourceRoot = resolvedRoot;

        var staleKeys = new List<string>();
        foreach (var key in _resources.Keys)
        {
            if (!used.Contains(key))
            {
                staleKeys.Add(key);
            }
        }

        foreach (var key in staleKeys)
        {
            _resources.Remove(key);
        }

        if (RelationshipPopupId is { } relId)
        {
            var target = next.Selected?.Relationships?.FirstOrDefault(r => r.NeighborId == relId);
            if (target is not null)
            {
                UpdateRelationshipPopup(target);
            }
            else
            {
                RelationshipPopupId = null;
            }
        }
    }

    public void Choose(Subpanel panel)
    {
        if (State is not { } state || _resourceRoot is null || !Supports(panel, state))
        {
            return;
        }

        var previous = CurrentSubpanel;
        if (panel != CurrentSubpanel)
        {
            _personalityPopupTrait = null;
            _zodiacPopupActive = false;
            RelationshipPopupId = null;
            SkillPopupIndex = null;
            _housePopupIndex = null;
            _careerSummaryPopupIndex = null;
            _livePopupAnchorMidX = null;
            if (_motivePopupIndex is not null)
            {
                _motivePopupIndex = null;
                _personalityPopupTitle = null;
                _personalityPopupLines = [];
                _personalityPopupPortrait = null;
            }
        }

        CurrentSubpanel = panel;
        _hoveredInventoryTile = null;
        _inventoryHoverStartedAt = null;

        try
        {
            Update(state, _resourceRoot);
        }
        catch
        {
            CurrentSubpanel = previous;
            throw;
        }
    }

    public int? NeedIndexAtPanelPoint(CGPoint panel, CGSize canvas)
    {
        TryPrepare(canvas);
        if (CurrentSubpanel != Subpanel.Needs || State?.Selected is null)
        {
            return null;
        }

        for (int i = 0; i < 8; i++)
        {
            if (Contains(OriginalGameplayLayout.NeedRect(i, _grid.Width), panel))
            {
                return i;
            }
        }

        return null;
    }

    public void ClearHoverPopups()
    {
        ClearLivePopupState();
        ClearInventoryHover();
    }
}

public static class OriginalGameplayOverlaySubpanelExtensions
{
    public static int ButtonIndex(this OriginalGameplayOverlay.Subpanel subpanel) => subpanel switch
    {
        OriginalGameplayOverlay.Subpanel.Needs => 0,
        OriginalGameplayOverlay.Subpanel.Relationships => 1,
        OriginalGameplayOverlay.Subpanel.House => 3,
        OriginalGameplayOverlay.Subpanel.Personality => 4,
        OriginalGameplayOverlay.Subpanel.Career => 2,
        OriginalGameplayOverlay.Subpanel.Fame => 2,
        OriginalGameplayOverlay.Subpanel.PetSkills => 2,
        OriginalGameplayOverlay.Subpanel.Interests => 5,
        OriginalGameplayOverlay.Subpanel.Inventory => 6,
        OriginalGameplayOverlay.Subpanel.ReportCard => 2,
        _ => 0
    };

    public static int ImageId(this OriginalGameplayOverlay.Subpanel subpanel) =>
        subpanel.ButtonIndex() switch
        {
            0 => 4500,
            1 => 4504,
            2 => 4503,
            3 => 4502,
            4 => 4501,
            5 => 4505,
            6 => 4507,
            _ => 4500
        };

    public static string Label(this OriginalGameplayOverlay.Subpanel subpanel) => subpanel switch
    {
        OriginalGameplayOverlay.Subpanel.Needs => "Needs",
        OriginalGameplayOverlay.Subpanel.Relationships => "Relationships",
        OriginalGameplayOverlay.Subpanel.House => "House",
        OriginalGameplayOverlay.Subpanel.Personality => "Personality",
        OriginalGameplayOverlay.Subpanel.Career => "Career",
        OriginalGameplayOverlay.Subpanel.Fame => "Fame",
        OriginalGameplayOverlay.Subpanel.PetSkills => "Pet Skills",
        OriginalGameplayOverlay.Subpanel.Interests => "Interests",
        OriginalGameplayOverlay.Subpanel.Inventory => "Inventory",
        OriginalGameplayOverlay.Subpanel.ReportCard => "Report Card",
        _ => string.Empty
    };
}
