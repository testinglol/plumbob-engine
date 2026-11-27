using System.Diagnostics;
using System.Numerics;
using System.Text.Json.Serialization;
using SimsSDL;

namespace SimsSDL.UI;

public sealed class OriginalOptionsPanelOverlay
{
    public enum Button
    {
        Neighborhood,
        Save,
        Quit,
        Graphics,
        Sound,
        Play,
        ResetTutorial
    }

    public enum Page
    {
        None,
        Graphics,
        Sound,
        Play
    }

    public record struct PlayOptionsState
    {
        [JsonPropertyName("autoCenter")]
        public bool AutoCenter { get; set; } = true;

        [JsonPropertyName("freeWill")]
        public bool FreeWill { get; set; } = true;

        [JsonPropertyName("edgeScrolling")]
        public bool EdgeScrolling { get; set; } = true;

        [JsonPropertyName("quickTips")]
        public bool QuickTips { get; set; } = true;

        [JsonPropertyName("lighting")]
        public bool Lighting { get; set; } = true;

        [JsonPropertyName("simInBackground")]
        public bool SimInBackground { get; set; } = true;

        [JsonPropertyName("antiAlias")]
        public bool AntiAlias { get; set; } = true;

        [JsonPropertyName("shadows")]
        public bool Shadows { get; set; } = true;

        [JsonPropertyName("interfaceEffects")]
        public bool InterfaceEffects { get; set; } = true;

        [JsonPropertyName("autoSnapshot")]
        public bool AutoSnapshot { get; set; } = true;

        [JsonPropertyName("livePIP")]
        public bool LivePIP { get; set; } = true;

        [JsonPropertyName("exportHTML")]
        public bool ExportHTML { get; set; } = true;

        [JsonPropertyName("sharpText")]
        public bool SharpText { get; set; } = true;

        [JsonPropertyName("fullscreen")]
        public bool Fullscreen { get; set; } = false;

        [JsonPropertyName("uiScale")]
        public float? UIScale { get; set; } = null;

        [JsonPropertyName("terrainDetail")]
        public int TerrainDetail { get; set; } = 2;

        [JsonPropertyName("characterDetail")]
        public int CharacterDetail { get; set; } = 2;

        public PlayOptionsState() { }

        public readonly int Detail(DetailSetting setting) =>
            Math.Clamp(setting == DetailSetting.Terrain ? TerrainDetail : CharacterDetail, 0, 2);
    }

    public enum DetailSetting
    {
        Terrain,
        Character
    }

    public enum PlayOption
    {
        AutoCenter,
        FreeWill,
        EdgeScrolling,
        SimInBackground,
        QuickTips,
        AutoSnapshot,
        LivePIP,
        ExportHTML,
        AntiAlias,
        Shadows,
        Lighting,
        InterfaceEffects,
        SharpText,
        Fullscreen
    }

    private abstract record PopupTopic
    {
        public sealed record OptionTopic(PlayOption Option) : PopupTopic;
        public sealed record DetailTopic(DetailSetting Setting) : PopupTopic;
        public sealed record UIScaleTopic : PopupTopic;
        public sealed record SoundTopic(int Index) : PopupTopic;
        public sealed record ResetTutorialTopic : PopupTopic;
        public sealed record PluginItemTopic(string PackId, string PanelId, string Key) : PopupTopic;
    }

    private readonly struct SlidePopupEntry
    {
        public OriginalGameplayOverlay.Image Title { get; init; }
        public List<OriginalGameplayOverlay.Image> Body { get; init; }
        public OriginalGameplayOverlay.Image Detail { get; init; }
    }

    private struct RowLayout
    {
        public CGPoint Origin;
        public CGSize Size;
    }

    public sealed record PluginOptionsSubpage(
        string PackId,
        string PanelId,
        string Title,
        IReadOnlyList<PackOptionsItemDeclaration> Items);

    public sealed record PluginOptionHit(
        string PackId,
        string PanelId,
        string Key,
        string Action);

    public static readonly CGPoint SubpanelOrigin = new(220, 50);

    private const int BuiltinGraphicsSubpageCount = 2;
    private const int BuiltinPlaySubpageCount = 1;

    private static readonly Button[] AllButtons = Enum.GetValues<Button>();
    private static readonly DetailSetting[] AllDetailSettings = Enum.GetValues<DetailSetting>();
    private static readonly PlayOption[] AllPlayOptions = Enum.GetValues<PlayOption>();

    private RowLayout _playRows = new() { Origin = new CGPoint(275, 9), Size = new CGSize(200, 20) };
    private RowLayout _detailLabels = new() { Origin = new CGPoint(480, 30), Size = new CGSize(200, 26) };
    private CGSize _radioSize = new(80, 20);
    private RowLayout _radioRows = new() { Origin = new CGPoint(485, 30), Size = new CGSize(200, 26) };

    private readonly OriginalGameplayOverlay.Image _radio;
    private readonly OriginalGameplayOverlay.Image _checkbox;
    private OriginalGameplayOverlay.Image _vectorCheckbox;
    private OriginalGameplayOverlay.Image _vectorCheckbox18;
    private OriginalGameplayOverlay.Image _vectorRadio;
    private OriginalGameplayOverlay.Image _arrowLeft14;
    private OriginalGameplayOverlay.Image _arrowRight14;
    private OriginalGameplayOverlay.Image _arrowLeft16;
    private OriginalGameplayOverlay.Image _arrowRight16;
    private readonly Dictionary<(int W, int H), OriginalGameplayOverlay.Image> _recessedWells = new();
    private readonly Dictionary<(int W, int H), OriginalGameplayOverlay.Image> _vectorPopupFrames = new();

    private readonly GameContent _content;
    private readonly OriginalUIStrings _strings;
    private readonly UIDevice _device;
    private readonly SimsBitmapFont _tooltipFont;
    private readonly SimsBitmapFont _labelFont;
    private readonly SimsBitmapFont _levelFont;
    private readonly SimsBitmapFont _popupTitleFont;
    private readonly SimsBitmapFont _popupBodyFont;
    private readonly OriginalGameplayOverlay.Image _popupTiles;
    private readonly OriginalGameplayOverlay.Image _toothpickHoriz;
    private readonly OriginalGameplayOverlay.Image _toothpickVert;
    private readonly Dictionary<PopupTopic, SlidePopupEntry> _slidePopups = new();
    private readonly Dictionary<PopupTopic, string> _pluginPopupAbout = new();
    private PopupTopic? _activePopupTopic;
    private double? _popupOpenedAt;
    private (string Text, OriginalGameplayOverlay.Image Image)? _tooltipImage;
    private string? _tooltipText;
    private CGPoint _tooltipAnchor = CGPoint.Zero;
    private double? _tooltipStartedAt;
    private bool _tooltipQuickTips = true;
    private Button? _suppressedTooltipButton;
    private readonly Dictionary<DetailSetting, OriginalGameplayOverlay.Image> _detailTitles = new();
    private readonly Dictionary<DetailSetting, OriginalGameplayOverlay.Image> _detailHoverTitles = new();
    private readonly Dictionary<DetailSetting, string> _detailAbout = new();
    private readonly List<OriginalGameplayOverlay.Image> _levelLabels = [];
    private readonly Dictionary<PlayOption, OriginalGameplayOverlay.Image> _playLabels = new();
    private readonly Dictionary<PlayOption, OriginalGameplayOverlay.Image> _playHoverLabels = new();
    private readonly Dictionary<PlayOption, string> _playAbout = new();
    private readonly string _resetTutorialAbout;
    private readonly OriginalGameplayOverlay.Image _universal;
    private readonly OriginalGameplayOverlay.Image _vectorUniversal;
    private OriginalGameplayOverlay.Image ActiveUniversal => SimsBitmapFont.SharpTextEnabled ? _vectorUniversal : _universal;
    private readonly OriginalGameplayOverlay.Image _patch;
    private readonly OriginalGameplayOverlay.Image _vectorPatch;
    private OriginalGameplayOverlay.Image ActivePatch => SimsBitmapFont.SharpTextEnabled ? _vectorPatch : _patch;
    private readonly Dictionary<Button, OriginalGameplayOverlay.Image> _buttons = new();
    private readonly Dictionary<Button, OriginalGameplayOverlay.Image> _vectorButtons = new();
    private readonly Dictionary<Button, CGPoint> _positions = new();

    private readonly List<PluginOptionsSubpage> _graphicsPluginPages = [];
    private readonly List<PluginOptionsSubpage> _playPluginPages = [];
    private readonly Dictionary<(string PackId, string PanelId), Dictionary<string, string>> _pluginPageValues = new();
    private readonly Dictionary<string, OriginalGameplayOverlay.Image> _pluginItemLabels = new(StringComparer.Ordinal);
    private readonly Dictionary<string, OriginalGameplayOverlay.Image> _pluginItemHoverLabels = new(StringComparer.Ordinal);
    private readonly Dictionary<string, OriginalGameplayOverlay.Image> _pluginChoiceLabels = new(StringComparer.Ordinal);
    private readonly Dictionary<string, OriginalGameplayOverlay.Image> _pluginChoiceHoverLabels = new(StringComparer.Ordinal);
    private readonly Dictionary<string, OriginalGameplayOverlay.Image> _subpageTitleImages = new(StringComparer.Ordinal);
    private readonly Dictionary<string, OriginalGameplayOverlay.Image> _pageIndicatorLabels = new(StringComparer.Ordinal);
    private readonly Dictionary<string, OriginalGameplayOverlay.Image> _uiScaleValueLabels = new(StringComparer.Ordinal);
    private readonly Dictionary<string, OriginalGameplayOverlay.Image> _uiScaleValueHoverLabels = new(StringComparer.Ordinal);
    private readonly Dictionary<string, OriginalGameplayOverlay.Image> _uiScaleHintLabels = new(StringComparer.Ordinal);
    private OriginalGameplayOverlay.Image _uiScaleTitle;
    private OriginalGameplayOverlay.Image _uiScaleHoverTitle;
    private string _uiScaleAbout = string.Empty;

    private PlayOptionsState _playOptions = new();
    public float EffectiveUIScale { get; set; } = 1.15f;
    public int? HoveredUIScaleStep { get; private set; }
    public bool HoveredUIScaleRow { get; private set; }
    private bool _lotSaveDisabled;
    private double? _pageTransitionStarted;
    private double _pageFadeInDelay;
    private double _pageTransitionDuration = 0.333;
    private List<OriginalGameplayOverlay.Part>? _transitionFromParts;
    private List<OriginalGameplayOverlay.Part> _lastPageContent = [];

    public IReadOnlyDictionary<Button, string> Labels { get; }
    public Page CurrentPage { get; private set; } = Page.None;
    public bool HasPluginGraphicsSubpages => _graphicsPluginPages.Count > 0;
    public bool HasPluginPlaySubpages => _playPluginPages.Count > 0;
    public bool HasPluginSubpages(Page page) => page switch
    {
        Page.Graphics => _graphicsPluginPages.Count > 0,
        Page.Play => _playPluginPages.Count > 0,
        _ => false,
    };

    public int GraphicsSubpage { get; private set; }
    public int PlaySubpage { get; private set; }
    public int ActiveSubpage => CurrentPage switch
    {
        Page.Graphics => GraphicsSubpage,
        Page.Play => PlaySubpage,
        _ => 0,
    };

    public int TotalSubpages(Page page) => page switch
    {
        Page.Graphics => BuiltinGraphicsSubpageCount + _graphicsPluginPages.Count,
        Page.Play => BuiltinPlaySubpageCount + _playPluginPages.Count,
        Page.Sound => 1,
        _ => 0,
    };

    public string CurrentSubpageTitle => CurrentPage switch
    {
        Page.Graphics => GraphicsSubpage switch
        {
            0 => "Scene Graphics",
            1 => "Display & Interface",
            _ when ActivePluginSubpage is { } gp => gp.Title,
            _ => "Scene Graphics",
        },
        Page.Play => PlaySubpage switch
        {
            0 => "Gameplay",
            _ when ActivePluginSubpage is { } pp => pp.Title,
            _ => "Gameplay",
        },
        Page.Sound => "Sound",
        _ => string.Empty,
    };

    public int HoveredSubpageArrow { get; private set; }
    public int HoveredGraphicsArrow => CurrentPage == Page.Graphics ? HoveredSubpageArrow : 0;
    public string? HoveredPluginItemKey { get; private set; }
    public int HoveredPluginStepDirection { get; private set; }
    public Button? Hovered { get; private set; }
    public DetailSetting? HoveredDetail { get; private set; }
    public (DetailSetting Setting, int Level)? HoveredRadio { get; private set; }
    public PlayOption? HoveredOption { get; private set; }

    public PlayOptionsState PlayOptions
    {
        get => _playOptions;
        set => _playOptions = value;
    }

    public bool LotSaveDisabled
    {
        get => _lotSaveDisabled;
        set
        {
            _lotSaveDisabled = value;
            if (Hovered is { } hovered && !IsEnabled(hovered))
            {
                Hovered = null;
                _suppressedTooltipButton = null;
                _tooltipText = null;
                _tooltipStartedAt = null;
            }
            if (HoveredOption is { } hoveredOption && !IsEnabled(hoveredOption))
            {
                HoveredOption = null;
            }
        }
    }

    public bool IsTransitioning
    {
        get
        {
            if (!_playOptions.InterfaceEffects || _pageTransitionStarted is not { } started) return false;
            var totalDuration = CurrentPage != Page.None ? _pageFadeInDelay + _pageTransitionDuration : _pageTransitionDuration;
            return NowSeconds() - started < totalDuration;
        }
    }

    public static (CGPoint Origin, CGSize Size) SoundRows(OriginalUIStrings strings) =>
        (OriginalUIStrings.Point(strings.OptionString(42, "(305;13)")) ?? new CGPoint(305, 13),
         OriginalUIStrings.Point(strings.OptionString(43, "(200;28)")) is { } s ? new CGSize(s.X, s.Y) : new CGSize(200, 28));

    public OriginalOptionsPanelOverlay(GameContent content, UIDevice device, OriginalUIStrings strings, SimsBitmapFont font)
    {
        _content = content;
        _strings = strings;
        _device = device;
        var optFont = TryLoadFont(content, "UIGraphics/Fonts/variablesans_09.ffn") ?? font;
        var smallFont = TryLoadFont(content, "UIGraphics/Fonts/variablesans_08.ffn") ?? optFont;
        _tooltipFont = TryLoadFont(content, "UIGraphics/Fonts/variablesans_07.ffn") ?? smallFont;
        var titleFont = TryLoadFont(content, "UIGraphics/Fonts/variablesans_12.ffn") ?? font;
        _labelFont = optFont;
        _levelFont = smallFont;
        _popupTitleFont = titleFont;
        _popupBodyFont = optFont;

        OriginalGameplayOverlay.Image Bitmap(string path)
        {
            var image = new SimsBitmap(content.Read(path));
            return OriginalGameplayOverlay.CreateImage(device, image.Width, image.Height, image.Rgba, magenta: true);
        }

        var baseTga = new SimsTarga(content.Read("UIGraphics/cpanel/Backgrounds/UniversalBack.tga"));
        _universal = OriginalGameplayOverlay.CreateImage(device, baseTga.Width, baseTga.Height, baseTga.Rgba);
        try { _vectorUniversal = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderFittedPanel("universalback", scale: 8)); } catch { _vectorUniversal = _universal; }
        _patch = Bitmap("UIGraphics/cpanel/Backgrounds/OptionsPatch.bmp");
        try { _vectorPatch = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderControlPanelModePatch(SimsVectorUiKit.ModePatchKind.Options, scale: 8)); } catch { _vectorPatch = _patch; }
        _popupTiles = Bitmap("UIGraphics/CPanel/Backgrounds/PopupInfoTiles.bmp");
        _toothpickHoriz = Bitmap("UIGraphics/CPanel/Backgrounds/OptionsToothpkHoriz.bmp");
        _toothpickVert = Bitmap("UIGraphics/CPanel/Backgrounds/OptionsToothpkVert.bmp");

        var labels = new Dictionary<Button, string>();
        foreach (var button in AllButtons)
        {
            var image = Bitmap(button.Asset());
            _buttons[button] = image;
            int bw = Math.Max(1, (int)Math.Round(image.Size.Width / 4.0));
            int bh = Math.Max(1, (int)Math.Round(image.Size.Height));
            if (SimsVectorUiKit.TryRenderOptionsButtonStrip(button, bw, bh, scale: 4) is { } vecOpt)
                _vectorButtons[button] = SimsVectorUiKit.ToOverlayImage(vecOpt);
            var pos = button == Button.ResetTutorial
                ? null
                : OriginalUIStrings.Point(strings.OptionString(button.StringIndex(), string.Empty));
            _positions[button] = pos ?? (button == Button.ResetTutorial
                ? new CGPoint(580 - image.Size.Width / 4.0 - 3, 7)
                : button.FallbackPosition());
            labels[button] = strings.OptionString(button.StringIndex() + 1, button.FallbackLabel());
        }
        Labels = labels;

        CGPoint? Point(int index) => OriginalUIStrings.Point(strings.OptionString(index, string.Empty));
        CGSize? Size(int index) => Point(index) is { } p ? new CGSize(p.X, p.Y) : null;

        _checkbox = Bitmap("UIGraphics/cpanel/Buttons/optcheckbox.bmp");
        if (Point(54) is { } playOrigin) _playRows.Origin = playOrigin;
        if (Size(55) is { } playSize) _playRows.Size = playSize;

        _radio = Bitmap("UIGraphics/cpanel/Buttons/optradio.bmp");
        if (Point(26) is { } dlOrigin) _detailLabels.Origin = dlOrigin;
        if (Size(27) is { } dlSize) _detailLabels.Size = dlSize;
        if (Size(36) is { } rsSize) _radioSize = rsSize;
        if (Point(37) is { } rrOrigin) _radioRows.Origin = rrOrigin;
        if (Size(38) is { } rrSize) _radioRows.Size = rrSize;

        _resetTutorialAbout = strings.OptionString(71, string.Empty);
        RefreshText();
    }

    private void RebuildVectorChrome()
    {
        int s = SimsVectorUiKit.CurrentScale();
        _vectorCheckbox = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderCheckboxStrip(20, scale: s));
        _vectorCheckbox18 = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderCheckboxStrip(18, scale: s));
        _vectorRadio = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderRadioStrip(20, scale: s));
        _arrowLeft14 = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderSmallArrowButtonStrip(right: false, w1x: 14, h1x: 14, scale: s));
        _arrowRight14 = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderSmallArrowButtonStrip(right: true, w1x: 14, h1x: 14, scale: s));
        _arrowLeft16 = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderSmallArrowButtonStrip(right: false, w1x: 16, h1x: 18, scale: s));
        _arrowRight16 = SimsVectorUiKit.ToOverlayImage(SimsVectorUiKit.RenderSmallArrowButtonStrip(right: true, w1x: 16, h1x: 18, scale: s));
        _recessedWells.Clear();
        _vectorPopupFrames.Clear();
    }

    private OriginalGameplayOverlay.Image GetRecessedWell(int w, int h)
    {
        var key = (Math.Max(8, w), Math.Max(8, h));
        if (!_recessedWells.TryGetValue(key, out var img))
        {
            img = SimsVectorUiKit.ToOverlayImage(
                SimsVectorUiKit.RenderRecessedWell(key.Item1, key.Item2, cornerR: 3.5f, scale: SimsVectorUiKit.CurrentScale()));
            _recessedWells[key] = img;
        }
        return img;
    }

    private OriginalGameplayOverlay.Image GetVectorPopupFrame(int w, int h)
    {
        var key = (Math.Max(32, w), Math.Max(32, h));
        if (!_vectorPopupFrames.TryGetValue(key, out var img))
        {
            img = SimsVectorUiKit.ToOverlayImage(
                SimsVectorUiKit.RenderPopupInfoFrame(key.Item1, key.Item2, scale: 4));
            _vectorPopupFrames[key] = img;
        }
        return img;
    }

    public void RefreshText()
    {
        const string sharpTextTitle = "About Sharp Text";
        const string sharpTextBody = "Renders UI text, tooltips, dialogs, and pie menus at high resolution instead of stretching classic 800x600 bitmap fonts.";

        RebuildVectorChrome();
        _tooltipImage = null;
        _detailTitles.Clear();
        _detailHoverTitles.Clear();
        _detailAbout.Clear();
        _levelLabels.Clear();
        _playLabels.Clear();
        _playHoverLabels.Clear();
        _playAbout.Clear();
        _subpageTitleImages.Clear();

        OriginalGameplayOverlay.Image DetailBitmap(PopupTopic topic, string path)
        {
            if (_slidePopups.TryGetValue(topic, out var existing) && existing.Detail.Size.Width > 0)
            {
                return existing.Detail;
            }
            try
            {
                var image = new SimsBitmap(_content.Read(path));
                return OriginalGameplayOverlay.CreateImage(_device, image.Width, image.Height, image.Rgba, magenta: true);
            }
            catch
            {
                return new OriginalGameplayOverlay.Image(new UITexture(1, 1, [0, 0, 0, 0]), CGSize.Zero);
            }
        }

        OriginalGameplayOverlay.Image MakeText(string text, SimsBitmapFont f, (byte R, byte G, byte B) color) =>
            OriginalGameplayOverlay.CreateImage(_device, f.RasterizeHiDpi(text, color));

        List<OriginalGameplayOverlay.Image> MakeLines(string raw)
        {
            var normalized = raw.Replace("\r\n", "\n", StringComparison.Ordinal).Replace("\r", "\n", StringComparison.Ordinal);
            var wrapped = new List<string>();
            foreach (var paragraph in normalized.Split('\n'))
            {
                var lines = _popupBodyFont.WrappedLines(paragraph, 357);
                if (lines.Count == 0)
                {
                    wrapped.Add(string.Empty);
                }
                else
                {
                    wrapped.AddRange(lines);
                }
            }

            var result = new List<OriginalGameplayOverlay.Image>(wrapped.Count);
            foreach (var line in wrapped)
            {
                if (string.IsNullOrEmpty(line))
                {
                    result.Add(new OriginalGameplayOverlay.Image(new UITexture(1, 1, [0, 0, 0, 0]), CGSize.Zero));
                }
                else
                {
                    result.Add(MakeText(line, _popupBodyFont, (195, 205, 205)));
                }
            }
            return result;
        }

        SlidePopupEntry MakePopupText(PopupTopic topic, string rawTitle, string rawBody, string asset) => new()
        {
            Title = MakeText(rawTitle.Trim(), _popupTitleFont, (255, 255, 255)),
            Body = MakeLines(rawBody),
            Detail = DetailBitmap(topic, asset)
        };

        SlidePopupEntry MakePopup(PopupTopic topic, int titleIndex, int bodyIndex, string fallbackTitle, string asset)
        {
            var rawTitle = _strings.OptionString(titleIndex, fallbackTitle);
            var rawBody = _strings.OptionString(bodyIndex, string.Empty);
            return MakePopupText(topic, rawTitle, rawBody, asset);
        }

        foreach (var setting in AllDetailSettings)
        {
            var labelStr = _strings.OptionString(setting.StringIndex(), setting.FallbackLabel());
            _detailTitles[setting] = MakeText(labelStr, _labelFont, (195, 205, 205));
            _detailHoverTitles[setting] = MakeText(labelStr, _labelFont, (255, 255, 255));
            _detailAbout[setting] = _strings.OptionString(setting.StringIndex() + 2, string.Empty);
            var topic = new PopupTopic.DetailTopic(setting);
            _slidePopups[topic] = MakePopup(
                topic,
                setting.StringIndex() + 1,
                setting.StringIndex() + 2,
                setting.FallbackLabel(),
                setting.PopupAsset());
        }

        string[] levelFallbacks = ["Low", "Med", "High"];
        for (var i = 0; i < levelFallbacks.Length; i++)
        {
            _levelLabels.Add(MakeText(_strings.OptionString(39 + i, levelFallbacks[i]), _levelFont, (195, 205, 205)));
        }

        foreach (var option in AllPlayOptions)
        {
            var stringIndex = option.StringIndex();
            var labelStr = stringIndex >= 0
                ? _strings.OptionString(stringIndex, option.FallbackLabel())
                : option.FallbackLabel();
            _playLabels[option] = MakeText(labelStr, _labelFont, (195, 205, 205));
            _playHoverLabels[option] = MakeText(labelStr, _labelFont, (255, 255, 255));

            var topic = new PopupTopic.OptionTopic(option);
            if (option == PlayOption.SharpText)
            {
                _playAbout[option] = sharpTextBody;
                _slidePopups[topic] = MakePopupText(topic, sharpTextTitle, sharpTextBody, option.PopupAsset());
            }
            else if (option == PlayOption.Fullscreen)
            {
                const string fullscreenTitle = "About Fullscreen";
                const string fullscreenBody = "Switches between windowed mode and borderless desktop fullscreen. Shortcut: Alt+Enter.";
                _playAbout[option] = fullscreenBody;
                _slidePopups[topic] = MakePopupText(topic, fullscreenTitle, fullscreenBody, option.PopupAsset());
            }
            else
            {
                _playAbout[option] = _strings.OptionString(stringIndex + 2, string.Empty);
                _slidePopups[topic] = MakePopup(
                    topic,
                    stringIndex + 1,
                    stringIndex + 2,
                    option.FallbackLabel(),
                    option.PopupAsset());
            }
        }

        const string uiScaleTitle = "UI Scale";
        const string uiScalePopupTitle = "About UI Scale";
        const string uiScaleBody = "Adjusts interface and camera scale for high-resolution displays. Click the scale readout to reset to automatic scaling. Shortcuts: Ctrl/Cmd +/- and Ctrl/Cmd+0.";
        _uiScaleTitle = MakeText(uiScaleTitle, _labelFont, (195, 205, 205));
        _uiScaleHoverTitle = MakeText(uiScaleTitle, _labelFont, (255, 255, 255));
        _uiScaleAbout = uiScaleBody;
        _uiScaleValueLabels.Clear();
        _uiScaleValueHoverLabels.Clear();
        _uiScaleHintLabels.Clear();
        var scaleTopic = new PopupTopic.UIScaleTopic();
        _slidePopups[scaleTopic] = MakePopupText(scaleTopic, uiScalePopupTitle, uiScaleBody, "UIGraphics/CPanel/PopupOptTransUI.bmp");

        (int Index, int TitleIdx, string FallbackTitle, string Asset)[] soundSpecs =
        [
            (0, 45, "Sound Effects", "UIGraphics/CPanel/PopupOptSFX.bmp"),
            (1, 48, "Music", "UIGraphics/CPanel/PopupOptMusic.bmp"),
            (2, 51, "Vox", "UIGraphics/CPanel/PopupOptVox.bmp")
        ];
        foreach (var (idx, titleIdx, fallbackTitle, asset) in soundSpecs)
        {
            var topic = new PopupTopic.SoundTopic(idx);
            _slidePopups[topic] = MakePopup(topic, titleIdx, titleIdx + 1, fallbackTitle, asset);
        }

        var resetTopic = new PopupTopic.ResetTutorialTopic();
        _slidePopups[resetTopic] = MakePopup(
            resetTopic,
            70,
            71,
            "About Reset Tutorial",
            "UIGraphics/CPanel/PopupResetTutorial.bmp");

        _pluginItemLabels.Clear();
        _pluginItemHoverLabels.Clear();
        _pluginChoiceLabels.Clear();
        _pluginChoiceHoverLabels.Clear();
        _pageIndicatorLabels.Clear();
        SetPluginSubpagesFromContent(_content);
    }

    private OriginalGameplayOverlay.Image CreateTextImage(string text, SimsBitmapFont font, (byte R, byte G, byte B) color) =>
        OriginalGameplayOverlay.CreateImage(_device, font.RasterizeHiDpi(text, color));

    public void SetPluginSubpagesFromContent(GameContent content)
    {
        _graphicsPluginPages.Clear();
        _playPluginPages.Clear();
        _pluginPopupAbout.Clear();

        foreach (var pack in content.Packs.Ordered)
        {
            if (pack.Manifest.OptionsPages is not { Count: > 0 } pages)
                continue;
            foreach (var page in pages)
            {
                if (page.Items is not { Count: > 0 })
                    continue;

                bool isGraphics = string.Equals(page.Category, "graphics", StringComparison.OrdinalIgnoreCase);
                bool isPlay = string.Equals(page.Category, "play", StringComparison.OrdinalIgnoreCase);
                if (!isGraphics && !isPlay)
                    continue;

                string title = !string.IsNullOrWhiteSpace(page.Title) ? page.Title! : pack.Manifest.Name;
                var subpage = new PluginOptionsSubpage(pack.Manifest.Id, page.PanelId, title, page.Items);
                if (isGraphics)
                    _graphicsPluginPages.Add(subpage);
                else
                    _playPluginPages.Add(subpage);

                var key = (pack.Manifest.Id, page.PanelId);
                if (!_pluginPageValues.TryGetValue(key, out var map))
                {
                    map = new Dictionary<string, string>(StringComparer.Ordinal);
                    _pluginPageValues[key] = map;
                }

                foreach (var item in page.Items)
                {
                    if (!map.ContainsKey(item.Key))
                        map[item.Key] = item.DefaultValue;
                    EnsurePluginLabel(item.Label);
                    if (item.Choices is { Count: > 0 } choices)
                    {
                        foreach (var ch in choices)
                            EnsurePluginChoiceLabel(ch.Label);
                    }
                    RegisterPluginItemPopup(pack.Manifest.Id, page.PanelId, title, item, isGraphics);
                }
            }
        }

        if (GraphicsSubpage >= TotalSubpages(Page.Graphics))
            GraphicsSubpage = 0;
        if (PlaySubpage >= TotalSubpages(Page.Play))
            PlaySubpage = 0;
    }

    private void RegisterPluginItemPopup(
        string packId,
        string panelId,
        string pageTitle,
        PackOptionsItemDeclaration item,
        bool isGraphics)
    {
        string popupBody = !string.IsNullOrWhiteSpace(item.PopupBody)
            ? item.PopupBody!
            : $"Configures {item.Label} for {pageTitle}.";
        string popupTitle = !string.IsNullOrWhiteSpace(item.PopupTitle)
            ? item.PopupTitle!
            : $"About {item.Label}";
        string popupAsset = !string.IsNullOrWhiteSpace(item.PopupAsset)
            ? item.PopupAsset!
            : (isGraphics ? "UIGraphics/CPanel/PopupOptLighting.bmp" : "UIGraphics/CPanel/PopupOptFreeWill.bmp");

        var topic = new PopupTopic.PluginItemTopic(packId, panelId, item.Key);
        _pluginPopupAbout[topic] = popupBody;

        OriginalGameplayOverlay.Image detailImg;
        if (_slidePopups.TryGetValue(topic, out var existing) && existing.Detail.Size.Width > 0)
        {
            detailImg = existing.Detail;
        }
        else
        {
            try
            {
                var bmp = new SimsBitmap(_content.Read(popupAsset));
                detailImg = OriginalGameplayOverlay.CreateImage(_device, bmp.Width, bmp.Height, bmp.Rgba, magenta: true);
            }
            catch
            {
                detailImg = new OriginalGameplayOverlay.Image(new UITexture(1, 1, [0, 0, 0, 0]), CGSize.Zero);
            }
        }

        var wrapped = _popupBodyFont.WrappedLines(popupBody, 357);
        var bodyLines = new List<OriginalGameplayOverlay.Image>(wrapped.Count);
        foreach (var line in wrapped)
        {
            bodyLines.Add(string.IsNullOrEmpty(line)
                ? new OriginalGameplayOverlay.Image(new UITexture(1, 1, [0, 0, 0, 0]), CGSize.Zero)
                : CreateTextImage(line, _popupBodyFont, (195, 205, 205)));
        }

        _slidePopups[topic] = new SlidePopupEntry
        {
            Title = CreateTextImage(popupTitle.Trim(), _popupTitleFont, (255, 255, 255)),
            Body = bodyLines,
            Detail = detailImg,
        };
    }

    private void EnsurePluginLabel(string label)
    {
        if (_pluginItemLabels.ContainsKey(label))
            return;
        _pluginItemLabels[label] = CreateTextImage(label, _labelFont, (195, 205, 205));
        _pluginItemHoverLabels[label] = CreateTextImage(label, _labelFont, (255, 255, 255));
    }

    private void EnsurePluginChoiceLabel(string label)
    {
        if (_pluginChoiceLabels.ContainsKey(label))
            return;
        _pluginChoiceLabels[label] = CreateTextImage(label, _levelFont, (195, 205, 205));
        _pluginChoiceHoverLabels[label] = CreateTextImage(label, _levelFont, (255, 255, 255));
    }

    private OriginalGameplayOverlay.Image GetSubpageTitleImage(string title)
    {
        if (!_subpageTitleImages.TryGetValue(title, out var img))
        {
            img = CreateTextImage(title, _labelFont, (132, 232, 245));
            _subpageTitleImages[title] = img;
        }
        return img;
    }

    private OriginalGameplayOverlay.Image GetPageIndicatorLabel(int currentOneBased, int total)
    {
        string text = $"{currentOneBased}/{total}";
        if (!_pageIndicatorLabels.TryGetValue(text, out var img))
        {
            img = CreateTextImage(text, _levelFont, (195, 205, 205));
            _pageIndicatorLabels[text] = img;
        }
        return img;
    }

    private OriginalGameplayOverlay.Image GetUIScaleHintLabel(string text)
    {
        if (!_uiScaleHintLabels.TryGetValue(text, out var img))
        {
            img = CreateTextImage(text, _levelFont, SimsVectorUiKit.TextMuted);
            _uiScaleHintLabels[text] = img;
        }
        return img;
    }

    private static SimsBitmapFont? TryLoadFont(GameContent content, string path)
    {
        try
        {
            return new SimsBitmapFont(content.Read(path));
        }
        catch
        {
            return null;
        }
    }

    private static double NowSeconds() =>
        Stopwatch.GetTimestamp() / (double)Stopwatch.Frequency;

    public bool IsEnabled(Button button) =>
        !(_lotSaveDisabled && (button == Button.ResetTutorial || button == Button.Save));

    public bool IsEnabled(PlayOption option)
    {
        if (!option.IsImplemented()) return false;
        if (_lotSaveDisabled && option is PlayOption.LivePIP or PlayOption.AutoSnapshot or PlayOption.QuickTips)
        {
            return false;
        }
        return true;
    }

    public bool IsShown(Button button) =>
        button != Button.ResetTutorial || (CurrentPage == Page.Play && PlaySubpage == 0);

    public void Select(Page page)
    {
        if (Hovered is { } hovered) _suppressedTooltipButton = hovered;
        _tooltipText = null;
        _tooltipStartedAt = null;
        if (CurrentPage == page) return;
        var hadActivePage = CurrentPage != Page.None;
        _transitionFromParts = _playOptions.InterfaceEffects ? _lastPageContent : null;
        _pageFadeInDelay = _playOptions.InterfaceEffects && hadActivePage ? 0.333 : 0.0;
        _pageTransitionDuration = 0.333;
        CurrentPage = page;
        GraphicsSubpage = 0;
        PlaySubpage = 0;
        HoveredSubpageArrow = 0;
        HoveredPluginItemKey = null;
        HoveredPluginStepDirection = 0;
        _pageTransitionStarted = _playOptions.InterfaceEffects ? NowSeconds() : null;
        _activePopupTopic = null;
        _popupOpenedAt = null;
    }

    public void SelectSubpage(Page page, int subpage)
    {
        if (CurrentPage != page)
            Select(page);
        int total = TotalSubpages(page);
        if (total <= 0)
            return;
        int clamped = Math.Clamp(subpage, 0, total - 1);
        if (page == Page.Graphics)
            GraphicsSubpage = clamped;
        else if (page == Page.Play)
            PlaySubpage = clamped;
        ClearSubpageItemHover();
    }

    public void UpdatePluginPageValues(string packId, string panelId, IReadOnlyDictionary<string, string> values)
    {
        var pageKey = (packId, panelId);
        if (!_pluginPageValues.TryGetValue(pageKey, out var map))
        {
            map = new Dictionary<string, string>(StringComparer.Ordinal);
            _pluginPageValues[pageKey] = map;
        }
        foreach (var (key, value) in values)
        {
            map[key] = value;
        }
    }

    private void ClearSubpageItemHover()
    {
        HoveredOption = null;
        HoveredRadio = null;
        HoveredDetail = null;
        HoveredUIScaleStep = null;
        HoveredUIScaleRow = false;
        HoveredPluginItemKey = null;
        HoveredPluginStepDirection = 0;
        _activePopupTopic = null;
        _popupOpenedAt = null;
    }

    public void StepSubpage(int delta)
    {
        int totalPages = TotalSubpages(CurrentPage);
        if (totalPages <= 1 || CurrentPage is not (Page.Graphics or Page.Play))
            return;

        if (_playOptions.InterfaceEffects)
        {
            _transitionFromParts = _lastPageContent;
            _pageFadeInDelay = 0.0;
            _pageTransitionDuration = 0.16;
            _pageTransitionStarted = NowSeconds();
        }

        if (CurrentPage == Page.Graphics)
            GraphicsSubpage = ((GraphicsSubpage + delta) % totalPages + totalPages) % totalPages;
        else
            PlaySubpage = ((PlaySubpage + delta) % totalPages + totalPages) % totalPages;

        ClearSubpageItemHover();
    }

    public void StepGraphicsSubpage(int delta)
    {
        if (CurrentPage == Page.Graphics)
            StepSubpage(delta);
    }

    private OriginalGameplayOverlay.Image GetUIScaleValueLabel(string text, bool hover)
    {
        var dict = hover ? _uiScaleValueHoverLabels : _uiScaleValueLabels;
        if (!dict.TryGetValue(text, out var img))
        {
            img = CreateTextImage(text, _levelFont, hover ? ((byte)255, (byte)255, (byte)255) : ((byte)195, (byte)205, (byte)205));
            dict[text] = img;
        }
        return img;
    }

    public string CurrentUIScaleText =>
        _playOptions.UIScale is float explicitScale && explicitScale > 0f
            ? $"{(int)MathF.Round(explicitScale * 100f)}%"
            : "Auto";

    private string CurrentUIScaleHintText =>
        _playOptions.UIScale is float explicitScale && explicitScale > 0f
            ? "Click % for Auto"
            : $"Active: {(int)MathF.Round(Math.Clamp(EffectiveUIScale, 0.75f, 3.5f) * 100f)}%";

    private (CGRect Row, CGRect Minus, CGRect Value, CGRect Plus) UIScaleRects(double top)
    {
        const double yLocal = 36.0;
        const double h = 18.0;
        double titleW = _uiScaleTitle.Size.Width > 0 ? _uiScaleTitle.Size.Width : 54;
        double xStart = SubpanelOrigin.X + 468;
        double y = top + SubpanelOrigin.Y + yLocal;
        var minus = new CGRect(xStart, y, 16, h);
        var val = new CGRect(xStart + 18, y, 64, h);
        var plus = new CGRect(xStart + 84, y, 16, h);
        double rowLeft = SubpanelOrigin.X + 460 - titleW;
        var row = new CGRect(rowLeft, y - 2, (xStart + 100) - rowLeft, h + 18);
        return (row, minus, val, plus);
    }

    public int? UIScaleStepAt(CGPoint point, CGSize canvas)
    {
        if (CurrentPage != Page.Graphics || GraphicsSubpage != 1) return null;
        var (_, minus, val, plus) = UIScaleRects(canvas.Height - 150);
        if (Contains(minus, point)) return -1;
        if (Contains(plus, point)) return 1;
        if (Contains(val, point)) return 0;
        return null;
    }

    private string PluginValue(PluginOptionsSubpage page, string key, string defaultValue)
    {
        if (_pluginPageValues.TryGetValue((page.PackId, page.PanelId), out var map) && map.TryGetValue(key, out var val))
            return val;
        return defaultValue;
    }

    private bool PluginFlag(PluginOptionsSubpage page, string key, string defaultValue = "on") =>
        !string.Equals(PluginValue(page, key, defaultValue), "off", StringComparison.OrdinalIgnoreCase);

    private bool IsHostConditionSatisfied(string? hostCondition) => hostCondition switch
    {
        null or "" => true,
        "lighting" => _playOptions.Lighting,
        "shadows" => _playOptions.Lighting && _playOptions.Shadows,
        "freeWill" => _playOptions.FreeWill,
        "homeLot" => !_lotSaveDisabled,
        _ => true,
    };

    private bool IsPluginItemEnabled(PluginOptionsSubpage page, PackOptionsItemDeclaration item)
    {
        if (!IsHostConditionSatisfied(item.HostEnabledWhen))
            return false;
        if (!string.IsNullOrEmpty(item.EnabledWhen) && !PluginFlag(page, item.EnabledWhen))
            return false;
        return true;
    }

    private PluginOptionsSubpage? ActivePluginSubpage => CurrentPage switch
    {
        Page.Graphics when GraphicsSubpage >= BuiltinGraphicsSubpageCount
            && GraphicsSubpage - BuiltinGraphicsSubpageCount < _graphicsPluginPages.Count
            => _graphicsPluginPages[GraphicsSubpage - BuiltinGraphicsSubpageCount],
        Page.Play when PlaySubpage >= BuiltinPlaySubpageCount
            && PlaySubpage - BuiltinPlaySubpageCount < _playPluginPages.Count
            => _playPluginPages[PlaySubpage - BuiltinPlaySubpageCount],
        _ => null,
    };

    private bool ShowsSubpageHeader =>
        CurrentPage is Page.Graphics or Page.Play && TotalSubpages(CurrentPage) > 1;

    private (CGRect Left, CGRect Label, CGRect Right) SubpageNavRects(double top)
    {
        double navX = SubpanelOrigin.X + 504;
        double navY = top + SubpanelOrigin.Y + 2;
        var left = new CGRect(navX, navY, 14, 14);
        var label = new CGRect(navX + 15, navY, 36, 14);
        var right = new CGRect(navX + 52, navY, 14, 14);
        return (left, label, right);
    }

    public int SubpageArrowAt(CGPoint point, CGSize canvas)
    {
        if (!ShowsSubpageHeader) return 0;
        var (left, _, right) = SubpageNavRects(canvas.Height - 150);
        if (Contains(left, point)) return -1;
        if (Contains(right, point)) return 1;
        return 0;
    }

    public int GraphicsArrowAt(CGPoint point, CGSize canvas) =>
        CurrentPage == Page.Graphics ? SubpageArrowAt(point, canvas) : 0;

    private static bool IsStepperItem(PackOptionsItemDeclaration item) =>
        string.Equals(item.Kind, "stepper", StringComparison.OrdinalIgnoreCase)
        && item.Choices is { Count: > 0 };

    private static double CenteredRowY(int rowIndex, int rowCount) => rowCount switch
    {
        1 => 47.0,
        2 => 33.0 + rowIndex * 26.0,
        3 => 24.0 + rowIndex * 24.0,
        _ => 21.0 + rowIndex * 18.0,
    };

    private (double BoxX, double LabelX, double BoxY, double LabelY, double RowHeight) PluginCheckboxPlacement(
        int checkboxOrdinal,
        int checkboxCount,
        bool hasSteppers)
    {
        bool twoColumns = !hasSteppers && checkboxCount > 3;
        int rowsPerCol = twoColumns ? (checkboxCount + 1) / 2 : checkboxCount;
        int col = twoColumns ? checkboxOrdinal / rowsPerCol : 0;
        int row = twoColumns ? checkboxOrdinal % rowsPerCol : checkboxOrdinal;
        double boxX = col == 0 ? 245.0 : 418.0;
        double labelX = boxX + 26.0;
        double boxY = CenteredRowY(row, rowsPerCol);
        double boxH = rowsPerCol >= 4 ? 18.0 : 20.0;
        double labelY = boxY + Math.Floor((boxH - _labelFont.LineHeight) / 2.0);
        return (boxX, labelX, boxY, labelY, boxH);
    }

    private (CGRect HoverRow, CGRect TitleRect, CGRect Minus, CGRect Value, CGRect Plus, bool StackedTitle) PluginStepperRects(
        PackOptionsItemDeclaration item,
        int stepperOrdinal,
        int stepperCount,
        bool hasCheckboxes,
        double top)
    {
        double titleW = _pluginItemLabels.TryGetValue(item.Label, out var lblImg) ? lblImg.Size.Width : 70.0;
        double titleH = lblImg.Size.Height > 0 ? lblImg.Size.Height : _labelFont.LineHeight;
        double panelTop = top + SubpanelOrigin.Y;

        if (hasCheckboxes)
        {
            double blockY = stepperCount == 1
                ? panelTop + 33.0
                : panelTop + 23.0 + stepperOrdinal * 36.0;
            double xStart = SubpanelOrigin.X + 418.0;
            const double totalW = 150.0;
            const double h = 18.0;
            double titleX = xStart + Math.Floor((totalW - titleW) / 2.0);
            var titleRect = new CGRect(titleX, blockY, titleW, titleH);
            double stepY = blockY + titleH + 4.0;
            var minus = new CGRect(xStart, stepY, 16, h);
            var val = new CGRect(xStart + 18, stepY, 114, h);
            var plus = new CGRect(xStart + 134, stepY, 16, h);
            var hoverRow = new CGRect(xStart - 4, blockY - 1, totalW + 8, (stepY + h) - blockY + 2);
            return (hoverRow, titleRect, minus, val, plus, true);
        }
        else
        {
            double rowY = panelTop + CenteredRowY(stepperOrdinal, stepperCount);
            const double h = 18.0;
            double xStart = SubpanelOrigin.X + 386.0;
            var minus = new CGRect(xStart, rowY, 16, h);
            var val = new CGRect(xStart + 18, rowY, 108, h);
            var plus = new CGRect(xStart + 128, rowY, 16, h);
            double titleX = SubpanelOrigin.X + 376.0 - titleW;
            double titleY = rowY + Math.Floor((h - titleH) / 2.0);
            var titleRect = new CGRect(titleX, titleY, titleW, titleH);
            var hoverRow = new CGRect(titleX - 2, rowY - 1, (xStart + 144.0) - titleX + 4, h + 2);
            return (hoverRow, titleRect, minus, val, plus, false);
        }
    }

    private (int Index, PackOptionsChoiceDeclaration Choice) ActiveChoice(
        PluginOptionsSubpage page,
        PackOptionsItemDeclaration item)
    {
        var choices = item.Choices!;
        string raw = PluginValue(page, item.Key, item.DefaultValue);
        for (int i = 0; i < choices.Count; i++)
        {
            if (string.Equals(choices[i].Value, raw, StringComparison.OrdinalIgnoreCase))
                return (i, choices[i]);
        }
        return (0, choices[0]);
    }

    private CGRect PluginCheckboxRect(
        PackOptionsItemDeclaration item,
        int checkboxOrdinal,
        int checkboxCount,
        bool hasSteppers,
        double top)
    {
        var (boxX, labelX, boxY, _, rowH) = PluginCheckboxPlacement(checkboxOrdinal, checkboxCount, hasSteppers);
        double labelWidth = _pluginItemLabels.TryGetValue(item.Label, out var img) ? img.Size.Width : 90.0;
        double maxRight = boxX < 400.0 ? 406.0 : 574.0;
        double width = Math.Min(labelX - boxX + labelWidth, maxRight - boxX);
        return new CGRect(
            SubpanelOrigin.X + boxX,
            top + SubpanelOrigin.Y + boxY,
            Math.Max(26.0, width),
            rowH);
    }

    private (PluginOptionHit? Hit, string? HoverKey, int StepDir) ProbePluginPage(CGPoint point, CGSize canvas)
    {
        if (ActivePluginSubpage is not { } page)
            return (null, null, 0);

        var top = canvas.Height - 150;
        int checkboxCount = 0;
        int stepperCount = 0;
        foreach (var it in page.Items)
        {
            if (IsStepperItem(it)) stepperCount++;
            else checkboxCount++;
        }

        bool hasSteppers = stepperCount > 0;
        bool hasCheckboxes = checkboxCount > 0;
        int chkOrd = 0;
        int stpOrd = 0;

        foreach (var item in page.Items)
        {
            bool enabled = IsPluginItemEnabled(page, item);
            if (IsStepperItem(item))
            {
                var (hoverRow, _, minus, val, plus, _) = PluginStepperRects(item, stpOrd++, stepperCount, hasCheckboxes, top);
                if (Contains(hoverRow, point))
                {
                    if (!enabled)
                        return (null, item.Key, 0);
                    var choices = item.Choices!;
                    var (curIdx, _) = ActiveChoice(page, item);
                    if (Contains(minus, point))
                    {
                        int prev = (curIdx - 1 + choices.Count) % choices.Count;
                        return (new PluginOptionHit(page.PackId, page.PanelId, item.Key, choices[prev].Action), item.Key, -1);
                    }
                    if (Contains(plus, point))
                    {
                        int next = (curIdx + 1) % choices.Count;
                        return (new PluginOptionHit(page.PackId, page.PanelId, item.Key, choices[next].Action), item.Key, 1);
                    }
                    if (Contains(val, point))
                    {
                        int next = (curIdx + 1) % choices.Count;
                        return (new PluginOptionHit(page.PackId, page.PanelId, item.Key, choices[next].Action), item.Key, 2);
                    }
                    return (null, item.Key, 0);
                }
            }
            else
            {
                var rect = PluginCheckboxRect(item, chkOrd++, checkboxCount, hasSteppers, top);
                if (Contains(rect, point))
                {
                    if (!enabled)
                        return (null, item.Key, 0);
                    return (new PluginOptionHit(page.PackId, page.PanelId, item.Key, item.Action), item.Key, 0);
                }
            }
        }

        return (null, null, 0);
    }

    public PluginOptionHit? PluginOptionAt(CGPoint point, CGSize canvas) =>
        ProbePluginPage(point, canvas).Hit;

    private CGRect Rect(Button button, double top)
    {
        if (!_buttons.TryGetValue(button, out var image) || !_positions.TryGetValue(button, out var position))
        {
            return CGRect.Zero;
        }
        double w = image.Size.Width / 4.0;
        double h = image.Size.Height;
        if (button == Button.ResetTutorial && ShowsSubpageHeader)
        {
            return new CGRect(
                SubpanelOrigin.X + 548,
                top + SubpanelOrigin.Y + 44,
                w,
                h);
        }
        return new CGRect(
            SubpanelOrigin.X + position.X,
            top + SubpanelOrigin.Y + position.Y,
            w,
            h);
    }

    public Button? ButtonAt(CGPoint point, CGSize canvas)
    {
        var top = canvas.Height - 150;
        foreach (var button in AllButtons)
        {
            if (IsShown(button) && Contains(Rect(button, top), point))
            {
                return button;
            }
        }
        return null;
    }

    public void Hover(CGPoint point, CGSize canvas, int? hoveredSoundIndex = null)
    {
        var top = canvas.Height - 150;
        var hitButton = ButtonAt(point, canvas);
        Button? nextHovered = hitButton is { } b && IsEnabled(b) ? b : null;
        if (nextHovered != _suppressedTooltipButton)
        {
            _suppressedTooltipButton = null;
        }
        Hovered = nextHovered;
        HoveredOption = OptionAt(point, canvas);
        HoveredRadio = RadioAt(point, canvas);
        HoveredUIScaleStep = UIScaleStepAt(point, canvas);
        HoveredSubpageArrow = SubpageArrowAt(point, canvas);

        var (pluginHit, pluginHoverKey, pluginStepDir) = ProbePluginPage(point, canvas);
        HoveredPluginItemKey = pluginHit?.Key;
        HoveredPluginStepDirection = pluginStepDir;

        DetailSetting? detailHit = null;
        bool scaleRowHit = false;
        if (CurrentPage == Page.Graphics && GraphicsSubpage == 0)
        {
            foreach (var setting in AllDetailSettings)
            {
                if (Contains(DetailRowRect(setting, top), point))
                {
                    detailHit = setting;
                    break;
                }
            }
        }
        else if (CurrentPage == Page.Graphics && GraphicsSubpage == 1)
        {
            scaleRowHit = Contains(UIScaleRects(top).Row, point);
        }
        HoveredDetail = detailHit;
        HoveredUIScaleRow = scaleRowHit;

        PopupTopic? newTopic = null;
        if (OptionRowAt(point, canvas) is { } rowOption) newTopic = new PopupTopic.OptionTopic(rowOption);
        else if (HoveredDetail is { } detail) newTopic = new PopupTopic.DetailTopic(detail);
        else if (HoveredUIScaleRow) newTopic = new PopupTopic.UIScaleTopic();
        else if (pluginHoverKey is not null && ActivePluginSubpage is { } activePlugin)
            newTopic = new PopupTopic.PluginItemTopic(activePlugin.PackId, activePlugin.PanelId, pluginHoverKey);
        else if (CurrentPage == Page.Sound && hoveredSoundIndex is { } soundIdx) newTopic = new PopupTopic.SoundTopic(soundIdx);
        else if (hitButton == Button.ResetTutorial) newTopic = new PopupTopic.ResetTutorialTopic();

        if (newTopic is not null)
        {
            _popupOpenedAt ??= NowSeconds();
            _activePopupTopic = newTopic;
        }
        else if (point.Y < canvas.Height - 100 || (Hovered is not null && Hovered != Button.ResetTutorial))
        {
            _activePopupTopic = null;
            _popupOpenedAt = null;
        }

        Button? tipButton = Hovered is { } h && h != _suppressedTooltipButton ? h : null;
        var text = tipButton is { } tb && Labels.TryGetValue(tb, out var lbl) ? lbl : null;
        if (!string.Equals(text, _tooltipText, StringComparison.Ordinal))
        {
            _tooltipText = text;
            _tooltipStartedAt = null;
        }
        if (tipButton is { } activeBtn && text is not null)
        {
            var buttonRect = Rect(activeBtn, top);
            _tooltipAnchor = new CGPoint(point.X, Math.Min(point.Y, buttonRect.MinY - 1));
        }
    }

    public void ClearHover()
    {
        Hovered = null;
        _suppressedTooltipButton = null;
        HoveredOption = null;
        HoveredRadio = null;
        HoveredDetail = null;
        HoveredUIScaleStep = null;
        HoveredUIScaleRow = false;
        HoveredSubpageArrow = 0;
        HoveredPluginItemKey = null;
        HoveredPluginStepDirection = 0;
        _activePopupTopic = null;
        _popupOpenedAt = null;
        _tooltipText = null;
        _tooltipStartedAt = null;
    }

    public List<OriginalGameplayOverlay.Part> TooltipParts(CGSize canvas, bool enabled, bool quickTips = true)
    {
        if (_tooltipQuickTips != quickTips)
        {
            _tooltipStartedAt = null;
            _tooltipQuickTips = quickTips;
        }
        if (!enabled || _tooltipText is null)
        {
            _tooltipStartedAt = null;
            return [];
        }

        var progress = PlacementTooltip.Progress(ref _tooltipStartedAt, quickTips);
        if (progress is null) return [];

        try
        {
            OriginalGameplayOverlay.Image image;
            if (_tooltipImage is { } cached && string.Equals(cached.Text, _tooltipText, StringComparison.Ordinal))
            {
                image = cached.Image;
            }
            else
            {
                image = OriginalGameplayOverlay.CreateImage(_device, PlacementTooltip.RasterizeHiDpi(_tooltipText, _tooltipFont));
                _tooltipImage = (_tooltipText, image);
            }

            var rect = PlacementTooltip.Rect(image.Size, new CGPoint(_tooltipAnchor.X, _tooltipAnchor.Y - 1), canvas);
            if (rect.Height <= 0) return [];
            var lift = (1.0 - progress.Value) * 2.0;
            return
            [
                new OriginalGameplayOverlay.Part(
                    image,
                    new CGRect(rect.MinX, rect.MinY + lift, rect.Width, rect.Height),
                    new Vector4(0f, 0f, 1f, 1f),
                    (float)Math.Clamp(progress.Value, 0.0, 1.0))
            ];
        }
        catch
        {
            return [];
        }
    }

    private const double GraphicsDetailStartY = 39.0;
    private const double GraphicsDetailPitchY = 25.0;
    private const double GraphicsLeftStartY = 25.0;
    private const double GraphicsLeftPitchY = 24.0;

    private bool IsBuiltinOptionVisibleOnCurrentSubpage(PlayOption option)
    {
        if (option.Page() != CurrentPage)
            return false;
        if (CurrentPage == Page.Graphics)
            return option.GraphicsBuiltinSubpage() == GraphicsSubpage;
        if (CurrentPage == Page.Play)
            return PlaySubpage == 0;
        return false;
    }

    private (double BoxX, double LabelX, double BoxY, double LabelY, double BoxSize) BuiltinOptionPlacement(PlayOption option)
    {
        if (option.Page() == Page.Graphics)
        {
            int row = option.Row();
            double boxY = GraphicsLeftStartY + row * GraphicsLeftPitchY;
            double labelY = boxY + Math.Max(0.0, Math.Floor((20.0 - _labelFont.LineHeight) / 2.0));
            return (245.0, 271.0, boxY, labelY, 20.0);
        }

        if (ShowsSubpageHeader)
        {
            bool colB = option.IsColumnA();
            double boxX = colB ? 392.0 : 245.0;
            double labelX = boxX + 23.0;
            double boxY = 21.0 + option.Row() * 18.0;
            double labelY = boxY + Math.Max(0.0, Math.Floor((18.0 - _labelFont.LineHeight) / 2.0));
            return (boxX, labelX, boxY, labelY, 18.0);
        }

        var column = PlayColumnClassic(option);
        double classicLabelY = column.Y + option.Row() * _playRows.Size.Height;
        double classicBoxY = classicLabelY + (_labelFont.LineHeight - (int)_checkbox.Size.Height) / 2.0;
        return (column.Box, column.Label, classicBoxY, classicLabelY, 20.0);
    }

    private CGRect OptionRect(PlayOption option, double top)
    {
        var (boxX, labelX, boxY, _, boxSize) = BuiltinOptionPlacement(option);
        var labelWidth = _playLabels.TryGetValue(option, out var img)
            ? img.Size.Width
            : 90.0;
        double height = option.Page() == Page.Graphics
            ? 20.0
            : (ShowsSubpageHeader ? 18.0 : _playRows.Size.Height);
        return new CGRect(
            SubpanelOrigin.X + boxX,
            top + SubpanelOrigin.Y + boxY,
            labelX - boxX + labelWidth,
            Math.Min(height, Math.Max(boxSize, 100.0 - boxY)));
    }

    private (double Box, double Label, double Y) PlayColumnClassic(PlayOption option)
    {
        var inset = _checkbox.Size.Width / 4.0;
        var boxB = _playRows.Origin.X - inset;
        if (!option.IsColumnA()) return (boxB, _playRows.Origin.X, _playRows.Origin.Y);
        double widest = 0;
        foreach (var candidate in AllPlayOptions)
        {
            if (candidate.Page() == Page.Play && !candidate.IsColumnA() &&
                _playLabels.TryGetValue(candidate, out var lbl) && lbl.Size.Width > widest)
            {
                widest = lbl.Size.Width;
            }
        }
        var label = boxB + widest + 70;
        return (label - inset, label, _playRows.Origin.Y);
    }

    private PlayOption? OptionRowAt(CGPoint point, CGSize canvas)
    {
        if (CurrentPage is not (Page.Play or Page.Graphics)) return null;
        var top = canvas.Height - 150;
        foreach (var option in AllPlayOptions)
        {
            if (IsBuiltinOptionVisibleOnCurrentSubpage(option) && Contains(OptionRect(option, top), point))
            {
                return option;
            }
        }
        return null;
    }

    public PlayOption? OptionAt(CGPoint point, CGSize canvas) =>
        OptionRowAt(point, canvas) is { } opt && IsEnabled(opt) ? opt : null;

    public string? AboutText(CGPoint point, CGSize canvas)
    {
        var top = canvas.Height - 150;
        DetailSetting? detail = null;
        if (CurrentPage == Page.Graphics && GraphicsSubpage == 0)
        {
            foreach (var setting in AllDetailSettings)
            {
                if (Contains(DetailRowRect(setting, top), point))
                {
                    detail = setting;
                    break;
                }
            }
        }

        string? result = null;
        if (OptionRowAt(point, canvas) is { } opt && _playAbout.TryGetValue(opt, out var optAbout))
        {
            result = optAbout;
        }
        else if (detail is { } d && _detailAbout.TryGetValue(d, out var detAbout))
        {
            result = detAbout;
        }
        else if (CurrentPage == Page.Graphics && GraphicsSubpage == 1 && Contains(UIScaleRects(top).Row, point))
        {
            result = _uiScaleAbout;
        }
        else if (ActivePluginSubpage is { } activePlugin && ProbePluginPage(point, canvas).HoverKey is { } pluginKey &&
                 _pluginPopupAbout.TryGetValue(new PopupTopic.PluginItemTopic(activePlugin.PackId, activePlugin.PanelId, pluginKey), out var pluginAbout))
        {
            result = pluginAbout;
        }
        else if (ButtonAt(point, canvas) == Button.ResetTutorial)
        {
            result = _resetTutorialAbout;
        }

        return string.IsNullOrEmpty(result) ? null : result;
    }

    private List<OriginalGameplayOverlay.Part> SlidePopupParts(CGSize canvas)
    {
        if (_activePopupTopic is not { } topic || !_slidePopups.TryGetValue(topic, out var entry)) return [];
        var textHeight = (int)entry.Title.Size.Height + entry.Body.Count * _popupBodyFont.LineHeight;
        double height = Math.Max(127, textHeight + 24);
        const double width = 540;
        var panelBottom = canvas.Height - 100;
        var elapsed = _playOptions.InterfaceEffects
            ? (_popupOpenedAt is { } openedAt ? NowSeconds() - openedAt : 0.25)
            : 0.25;
        var progress = Math.Clamp(elapsed / 0.25, 0.0, 1.0);
        var visibleHeight = Math.Round(height * progress, MidpointRounding.AwayFromZero);
        if (visibleHeight <= 0) return [];

        var x = Math.Min(Math.Max(8, SubpanelOrigin.X + 580 - width), canvas.Width - width);
        var y = panelBottom - visibleHeight;
        var parts = new List<OriginalGameplayOverlay.Part>();

        if (SimsBitmapFont.SharpTextEnabled)
        {
            var vecPopup = GetVectorPopupFrame((int)width, (int)Math.Round(height));
            parts.Add(new OriginalGameplayOverlay.Part(
                vecPopup,
                new CGRect(x, y, width, visibleHeight),
                new Vector4(0f, 0f, 1f, (float)(visibleHeight / height))));
        }
        else
        {
            var tileW = _popupTiles.Size.Width / 3.0;
            var tileH = _popupTiles.Size.Height / 3.0;
            double[] xs = [x, x + tileW, x + width - tileW, x + width];
            double[] ys = [y, y + tileH, y + height - tileH, y + height];

            for (var row = 0; row < 3; row++)
            {
                for (var col = 0; col < 3; col++)
                {
                    var cell = new CGRect(xs[col], ys[row], xs[col + 1] - xs[col], ys[row + 1] - ys[row]);
                    if (cell.MinY >= panelBottom) continue;
                    var clippedH = Math.Min(cell.MaxY, panelBottom) - cell.MinY;
                    var vScale = (float)(clippedH / Math.Max(1.0, cell.Height)) / 3.0f;
                    parts.Add(new OriginalGameplayOverlay.Part(
                        _popupTiles,
                        new CGRect(cell.MinX, cell.MinY, cell.Width, clippedH),
                        new Vector4(col / 3.0f, row / 3.0f, 1.0f / 3.0f, vScale)));
                }
            }
        }

        var detail = entry.Detail;
        if (detail.Size.Width > 0 && detail.Size.Height > 0)
        {
            var detailX = x + Math.Floor((168 - detail.Size.Width) / 2.0);
            var detailY = y + Math.Floor((height - detail.Size.Height) / 2.0);
            if (detailY < panelBottom)
            {
                var clippedH = Math.Min(detail.Size.Height, panelBottom - detailY);
                parts.Add(new OriginalGameplayOverlay.Part(
                    detail,
                    new CGRect(detailX, detailY, detail.Size.Width, clippedH),
                    new Vector4(0f, 0f, 1f, (float)(clippedH / detail.Size.Height))));
            }
        }

        var titleY = y + 12;
        if (titleY + entry.Title.Size.Height <= panelBottom)
        {
            parts.Add(new OriginalGameplayOverlay.Part(
                entry.Title,
                new CGRect(x + 178, titleY, entry.Title.Size.Width, entry.Title.Size.Height)));
        }

        var lineY = titleY + _popupTitleFont.LineHeight;
        foreach (var line in entry.Body)
        {
            if (line.Size.Width > 0 && lineY + line.Size.Height <= panelBottom)
            {
                parts.Add(new OriginalGameplayOverlay.Part(
                    line,
                    new CGRect(x + 178, lineY, line.Size.Width, line.Size.Height)));
            }
            lineY += _popupBodyFont.LineHeight;
        }

        return parts;
    }

    private CGRect RadioRect(DetailSetting setting, int level, double top)
    {
        const double button = 20.0;
        var x = SubpanelOrigin.X + _radioRows.Origin.X + level * (_radioSize.Width - button) / 2.0;
        return new CGRect(
            Math.Floor(x),
            top + SubpanelOrigin.Y + GraphicsDetailStartY + (int)setting * GraphicsDetailPitchY,
            button,
            button);
    }

    private CGRect DetailRowRect(DetailSetting setting, double top)
    {
        double widest = 0;
        foreach (var img in _detailTitles.Values)
        {
            if (img.Size.Width > widest) widest = img.Size.Width;
        }
        var y = top + SubpanelOrigin.Y + GraphicsDetailStartY + (int)setting * GraphicsDetailPitchY;
        const double labelRightX = 478.0;
        return new CGRect(
            SubpanelOrigin.X + labelRightX - widest,
            y,
            widest + (_radioRows.Origin.X - labelRightX) + _radioSize.Width,
            20.0);
    }

    public (DetailSetting Setting, int Level)? RadioAt(CGPoint point, CGSize canvas)
    {
        if (CurrentPage != Page.Graphics || GraphicsSubpage != 0) return null;
        var top = canvas.Height - 150;
        foreach (var setting in AllDetailSettings)
        {
            for (var level = 0; level < 3; level++)
            {
                if (Contains(RadioRect(setting, level, top), point))
                {
                    return (setting, level);
                }
            }
        }
        return null;
    }

    public List<(string Label, CGRect Rect)> Controls(CGSize canvas)
    {
        var top = canvas.Height - 150;
        var result = new List<(string Label, CGRect Rect)>();
        foreach (var button in AllButtons)
        {
            if (IsEnabled(button) && IsShown(button))
            {
                result.Add((Labels.TryGetValue(button, out var lbl) ? lbl : button.FallbackLabel(), Rect(button, top)));
            }
        }

        if (CurrentPage is not (Page.Play or Page.Graphics)) return result;

        if (ShowsSubpageHeader)
        {
            var (left, _, right) = SubpageNavRects(top);
            string cat = CurrentPage == Page.Graphics ? "Graphics" : "Play";
            result.Add(($"Previous {cat} Page", left));
            result.Add(($"Next {cat} Page", right));
        }

        if (ActivePluginSubpage is { } activePage)
        {
            int checkboxCount = 0;
            int stepperCount = 0;
            foreach (var it in activePage.Items)
            {
                if (IsStepperItem(it)) stepperCount++;
                else checkboxCount++;
            }
            bool hasSteppers = stepperCount > 0;
            bool hasCheckboxes = checkboxCount > 0;
            int chkOrd = 0;
            int stpOrd = 0;

            foreach (var item in activePage.Items)
            {
                bool enabled = IsPluginItemEnabled(activePage, item);
                if (IsStepperItem(item))
                {
                    var (_, _, minus, val, plus, _) = PluginStepperRects(item, stpOrd++, stepperCount, hasCheckboxes, top);
                    if (!enabled) continue;
                    var (_, curChoice) = ActiveChoice(activePage, item);
                    result.Add(($"Previous {item.Label}", minus));
                    result.Add(($"{item.Label}: {curChoice.Label}", val));
                    result.Add(($"Next {item.Label}", plus));
                }
                else
                {
                    var rect = PluginCheckboxRect(item, chkOrd++, checkboxCount, hasSteppers, top);
                    if (!enabled) continue;
                    bool isOn = PluginFlag(activePage, item.Key, item.DefaultValue);
                    result.Add((item.Label + (isOn ? ", on" : ", off"), rect));
                }
            }
            return result;
        }

        foreach (var option in AllPlayOptions)
        {
            if (IsBuiltinOptionVisibleOnCurrentSubpage(option) && IsEnabled(option))
            {
                result.Add((LabelText(option) + (option.Value(_playOptions) ? ", on" : ", off"), OptionRect(option, top)));
            }
        }

        if (CurrentPage == Page.Graphics && GraphicsSubpage == 0)
        {
            string[] levels = ["Low", "Med", "High"];
            foreach (var setting in AllDetailSettings)
            {
                if (!setting.IsImplemented()) continue;
                for (var level = 0; level < 3; level++)
                {
                    var state = _playOptions.Detail(setting) == level ? ", on" : ", off";
                    result.Add(($"{setting.FallbackLabel()} {levels[level]}{state}", RadioRect(setting, level, top)));
                }
            }
        }
        else if (CurrentPage == Page.Graphics && GraphicsSubpage == 1)
        {
            var (_, minusRect, valRect, plusRect) = UIScaleRects(top);
            result.Add(("Decrease UI Scale", minusRect));
            result.Add(($"UI Scale {CurrentUIScaleText}", valRect));
            result.Add(("Increase UI Scale", plusRect));
        }

        return result;
    }

    private static string LabelText(PlayOption option) => option.FallbackLabel();

    private void AppendArrowButton(
        List<OriginalGameplayOverlay.Part> target,
        bool right,
        CGRect rect,
        bool hovered,
        bool enabled = true)
    {
        var strip = rect.Width <= 14.5
            ? (right ? _arrowRight14 : _arrowLeft14)
            : (right ? _arrowRight16 : _arrowLeft16);
        float state = !enabled ? 2f : hovered ? 1f : 0f;
        target.Add(new OriginalGameplayOverlay.Part(
            strip,
            rect,
            new Vector4(state / 3.0f, 0f, 1.0f / 3.0f, 1f)));
    }

    public List<OriginalGameplayOverlay.Part> Parts(CGSize canvas)
    {
        var top = canvas.Height - 150;
        var parts = SlidePopupParts(canvas);
        parts.Add(new OriginalGameplayOverlay.Part(ActiveUniversal, new CGRect(0, top - 33, _universal.Size.Width, _universal.Size.Height)));
        parts.Add(new OriginalGameplayOverlay.Part(ActivePatch, new CGRect(183, top - 33 + 83, _patch.Size.Width, _patch.Size.Height)));
        parts.Add(new OriginalGameplayOverlay.Part(
            _toothpickHoriz,
            new CGRect(SubpanelOrigin.X + 16, top + SubpanelOrigin.Y + 51, _toothpickHoriz.Size.Width, _toothpickHoriz.Size.Height)));
        parts.Add(new OriginalGameplayOverlay.Part(
            _toothpickVert,
            new CGRect(SubpanelOrigin.X + 222, top + SubpanelOrigin.Y + 6, _toothpickVert.Size.Width, _toothpickVert.Size.Height)));

        foreach (var button in AllButtons)
        {
            if (button == Button.ResetTutorial || !IsShown(button)) continue;
            if (!_buttons.TryGetValue(button, out var baseImage)) continue;
            var image = SimsBitmapFont.SharpTextEnabled && _vectorButtons.TryGetValue(button, out var vecImage)
                ? vecImage
                : baseImage;
            var selected = (button == Button.Sound && CurrentPage == Page.Sound) ||
                (button == Button.Graphics && CurrentPage == Page.Graphics) ||
                (button == Button.Play && CurrentPage == Page.Play);
            var frame = !IsEnabled(button) ? 3.0f : selected ? 1.0f : Hovered == button ? 2.0f : 0.0f;
            parts.Add(new OriginalGameplayOverlay.Part(image, Rect(button, top), new Vector4(frame / 4.0f, 0f, 0.25f, 1f)));
        }

        float effectOpacity;
        float? outgoingOpacity = null;
        if (_pageTransitionStarted is { } started && _playOptions.InterfaceEffects)
        {
            var elapsed = NowSeconds() - started;
            var outProgress = Math.Clamp((float)(elapsed / _pageTransitionDuration), 0f, 1f);
            if (outProgress < 1f)
            {
                outgoingOpacity = 1f - outProgress;
            }
            if (CurrentPage != Page.None)
            {
                var inProgress = elapsed > _pageFadeInDelay
                    ? Math.Clamp((float)((elapsed - _pageFadeInDelay) / _pageTransitionDuration), 0f, 1f)
                    : 0f;
                effectOpacity = inProgress;
                if (inProgress >= 1f)
                {
                    _pageTransitionStarted = null;
                    _transitionFromParts = null;
                    _pageFadeInDelay = 0.0;
                }
            }
            else
            {
                effectOpacity = 0f;
                if (outProgress >= 1f)
                {
                    _pageTransitionStarted = null;
                    _transitionFromParts = null;
                    _pageFadeInDelay = 0.0;
                }
            }
        }
        else
        {
            if (!_playOptions.InterfaceEffects)
            {
                _pageTransitionStarted = null;
                _transitionFromParts = null;
                _pageFadeInDelay = 0.0;
            }
            effectOpacity = 1f;
        }

        bool sharp = SimsBitmapFont.SharpTextEnabled;
        var checkboxImg20 = sharp ? _vectorCheckbox : _checkbox;
        var checkboxImg18 = sharp ? _vectorCheckbox18 : _checkbox;
        var radioImg = sharp ? _vectorRadio : _radio;

        var pageContent = new List<OriginalGameplayOverlay.Part>();

        if (ShowsSubpageHeader)
        {
            var titleImg = GetSubpageTitleImage(CurrentSubpageTitle);
            if (titleImg.Size.Width > 0 && titleImg.Size.Height > 0)
            {
                pageContent.Add(new OriginalGameplayOverlay.Part(
                    titleImg,
                    new CGRect(
                        SubpanelOrigin.X + 245,
                        top + SubpanelOrigin.Y + 2 + Math.Floor((14.0 - titleImg.Size.Height) / 2.0),
                        titleImg.Size.Width,
                        titleImg.Size.Height)));
            }

            var (leftRect, labelRect, rightRect) = SubpageNavRects(top);
            var pageImg = GetPageIndicatorLabel(ActiveSubpage + 1, TotalSubpages(CurrentPage));
            AppendArrowButton(pageContent, right: false, leftRect, hovered: HoveredSubpageArrow == -1);
            pageContent.Add(new OriginalGameplayOverlay.Part(
                pageImg,
                new CGRect(
                    labelRect.MinX + Math.Floor((labelRect.Width - pageImg.Size.Width) / 2.0),
                    labelRect.MinY + Math.Floor((labelRect.Height - pageImg.Size.Height) / 2.0),
                    pageImg.Size.Width,
                    pageImg.Size.Height)));
            AppendArrowButton(pageContent, right: true, rightRect, hovered: HoveredSubpageArrow == 1);

            pageContent.Add(new OriginalGameplayOverlay.Part(
                _toothpickHoriz,
                new CGRect(SubpanelOrigin.X + 242, top + SubpanelOrigin.Y + 18, 328, 2),
                new Vector4(0f, 0f, 1f, 1f),
                0.55f));
        }

        if (IsShown(Button.ResetTutorial) && _buttons.TryGetValue(Button.ResetTutorial, out var resetImg))
        {
            var frame = !IsEnabled(Button.ResetTutorial) ? 3.0f : Hovered == Button.ResetTutorial ? 2.0f : 0.0f;
            pageContent.Add(new OriginalGameplayOverlay.Part(
                resetImg,
                Rect(Button.ResetTutorial, top),
                new Vector4(frame / 4.0f, 0f, 0.25f, 1f)));
        }

        if (ActivePluginSubpage is { } pluginPage)
        {
            int checkboxCount = 0;
            int stepperCount = 0;
            foreach (var it in pluginPage.Items)
            {
                if (IsStepperItem(it)) stepperCount++;
                else checkboxCount++;
            }
            bool hasSteppers = stepperCount > 0;
            bool hasCheckboxes = checkboxCount > 0;
            int chkOrd = 0;
            int stpOrd = 0;

            foreach (var item in pluginPage.Items)
            {
                EnsurePluginLabel(item.Label);
                bool enabled = IsPluginItemEnabled(pluginPage, item);
                bool hovered = enabled && string.Equals(HoveredPluginItemKey, item.Key, StringComparison.Ordinal);

                if (IsStepperItem(item))
                {
                    var (_, titleRect, minusRect, valRect, plusRect, _) =
                        PluginStepperRects(item, stpOrd++, stepperCount, hasCheckboxes, top);
                    var titleImg = hovered
                        ? (_pluginItemHoverLabels.TryGetValue(item.Label, out var th) ? th : _pluginItemLabels.GetValueOrDefault(item.Label))
                        : _pluginItemLabels.GetValueOrDefault(item.Label);
                    if (titleImg.Size.Width > 0 && titleImg.Size.Height > 0)
                    {
                        pageContent.Add(new OriginalGameplayOverlay.Part(
                            titleImg,
                            titleRect,
                            new Vector4(0f, 0f, 1f, 1f),
                            enabled ? 1f : 0.45f));
                    }

                    var well = GetRecessedWell((int)valRect.Width, (int)valRect.Height);
                    pageContent.Add(new OriginalGameplayOverlay.Part(
                        well,
                        valRect,
                        new Vector4(0f, 0f, 1f, 1f),
                        enabled ? 1f : 0.5f));

                    AppendArrowButton(
                        pageContent,
                        right: false,
                        minusRect,
                        hovered: hovered && HoveredPluginStepDirection == -1,
                        enabled: enabled);
                    AppendArrowButton(
                        pageContent,
                        right: true,
                        plusRect,
                        hovered: hovered && HoveredPluginStepDirection == 1,
                        enabled: enabled);

                    var (_, curChoice) = ActiveChoice(pluginPage, item);
                    EnsurePluginChoiceLabel(curChoice.Label);
                    bool valHovered = hovered && HoveredPluginStepDirection == 2;
                    var choiceImg = valHovered
                        ? (_pluginChoiceHoverLabels.TryGetValue(curChoice.Label, out var chH) ? chH : _pluginChoiceLabels.GetValueOrDefault(curChoice.Label))
                        : _pluginChoiceLabels.GetValueOrDefault(curChoice.Label);
                    if (choiceImg.Size.Width > 0 && choiceImg.Size.Height > 0)
                    {
                        pageContent.Add(new OriginalGameplayOverlay.Part(
                            choiceImg,
                            new CGRect(
                                valRect.MinX + Math.Floor((valRect.Width - choiceImg.Size.Width) / 2.0),
                                valRect.MinY + Math.Floor((valRect.Height - choiceImg.Size.Height) / 2.0),
                                choiceImg.Size.Width,
                                choiceImg.Size.Height),
                            new Vector4(0f, 0f, 1f, 1f),
                            enabled ? 1f : 0.45f));
                    }
                }
                else
                {
                    bool isOn = PluginFlag(pluginPage, item.Key, item.DefaultValue);
                    var pair = !enabled ? 2.0f : hovered ? 1.0f : 0.0f;
                    var frame = pair * 2.0f + (isOn ? 1.0f : 0.0f);
                    var (boxX, labelX, boxY, labelY, rowH) = PluginCheckboxPlacement(chkOrd++, checkboxCount, hasSteppers);
                    var chkSprite = rowH < 19.0 ? checkboxImg18 : checkboxImg20;
                    double drawBoxW = rowH < 19.0 ? 18.0 : 20.0;
                    double drawBoxH = rowH < 19.0 ? 18.0 : (sharp ? 20.0 : _checkbox.Size.Height);

                    pageContent.Add(new OriginalGameplayOverlay.Part(
                        chkSprite,
                        new CGRect(SubpanelOrigin.X + boxX, top + SubpanelOrigin.Y + boxY, drawBoxW, drawBoxH),
                        new Vector4(frame / 6.0f, 0f, 1.0f / 6.0f, 1f)));

                    var labelImg = hovered
                        ? (_pluginItemHoverLabels.TryGetValue(item.Label, out var hImg) ? hImg : _pluginItemLabels.GetValueOrDefault(item.Label))
                        : _pluginItemLabels.GetValueOrDefault(item.Label);
                    if (labelImg.Size.Width > 0 && labelImg.Size.Height > 0)
                    {
                        pageContent.Add(new OriginalGameplayOverlay.Part(
                            labelImg,
                            new CGRect(SubpanelOrigin.X + labelX, top + SubpanelOrigin.Y + labelY, labelImg.Size.Width, labelImg.Size.Height),
                            new Vector4(0f, 0f, 1f, 1f),
                            enabled ? 1f : 0.45f));
                    }
                }
            }
        }
        else if (CurrentPage is Page.Play or Page.Graphics)
        {
            foreach (var option in AllPlayOptions)
            {
                if (!IsBuiltinOptionVisibleOnCurrentSubpage(option)) continue;
                var pair = !IsEnabled(option) ? 2.0f : HoveredOption == option ? 1.0f : 0.0f;
                var frame = pair * 2.0f + (option.Value(_playOptions) ? 1.0f : 0.0f);
                var label = HoveredOption == option
                    ? (_playHoverLabels.TryGetValue(option, out var hImg) ? hImg : _playLabels.GetValueOrDefault(option))
                    : _playLabels.GetValueOrDefault(option);
                var (boxX, labelX, boxY, labelY, boxSize) = BuiltinOptionPlacement(option);
                var chkImg = boxSize < 19.0 ? checkboxImg18 : checkboxImg20;
                double drawH = boxSize < 19.0 ? 18.0 : (sharp ? 20.0 : _checkbox.Size.Height);

                pageContent.Add(new OriginalGameplayOverlay.Part(
                    chkImg,
                    new CGRect(SubpanelOrigin.X + boxX, top + SubpanelOrigin.Y + boxY, boxSize, drawH),
                    new Vector4(frame / 6.0f, 0f, 1.0f / 6.0f, 1f)));

                if (label.Size.Width > 0 && label.Size.Height > 0)
                {
                    pageContent.Add(new OriginalGameplayOverlay.Part(
                        label,
                        new CGRect(
                            SubpanelOrigin.X + labelX,
                            top + SubpanelOrigin.Y + labelY,
                            label.Size.Width,
                            label.Size.Height),
                        new Vector4(0f, 0f, 1f, 1f),
                        IsEnabled(option) ? 1f : 0.55f));
                }
            }
        }

        if (CurrentPage == Page.Graphics && GraphicsSubpage == 0)
        {
            const double labelRightX = 478.0;
            foreach (var setting in AllDetailSettings)
            {
                var title = HoveredDetail == setting
                    ? (_detailHoverTitles.TryGetValue(setting, out var dh) ? dh : _detailTitles.GetValueOrDefault(setting))
                    : _detailTitles.GetValueOrDefault(setting);
                if (title.Size.Width > 0 && title.Size.Height > 0)
                {
                    double radioY = top + SubpanelOrigin.Y + GraphicsDetailStartY + (int)setting * GraphicsDetailPitchY;
                    pageContent.Add(new OriginalGameplayOverlay.Part(
                        title,
                        new CGRect(
                            SubpanelOrigin.X + labelRightX - title.Size.Width,
                            radioY + Math.Floor((20.0 - title.Size.Height) / 2.0),
                            title.Size.Width,
                            title.Size.Height)));
                }

                for (var level = 0; level < 3; level++)
                {
                    var isHovered = HoveredRadio is { } hr && hr.Setting == setting && hr.Level == level;
                    var pair = !setting.IsImplemented() ? 2.0f : isHovered ? 1.0f : 0.0f;
                    var frame = pair * 2.0f + (_playOptions.Detail(setting) == level ? 1.0f : 0.0f);
                    pageContent.Add(new OriginalGameplayOverlay.Part(
                        radioImg,
                        RadioRect(setting, level, top),
                        new Vector4(frame / 6.0f, 0f, 1.0f / 6.0f, 1f)));
                }
            }

            var first = RadioRect(DetailSetting.Terrain, 0, top);
            var spanMinX = first.MinX - 8;
            var spanWidth = _radioSize.Width + 13;
            var third = Math.Floor(spanWidth / 3.0);
            for (var level = 0; level < _levelLabels.Count; level++)
            {
                var label = _levelLabels[level];
                pageContent.Add(new OriginalGameplayOverlay.Part(
                    label,
                    new CGRect(
                        Math.Floor(spanMinX + level * third + (third - label.Size.Width) / 2.0),
                        top + SubpanelOrigin.Y + 23.0,
                        label.Size.Width,
                        label.Size.Height)));
            }
        }
        else if (CurrentPage == Page.Graphics && GraphicsSubpage == 1)
        {
            var (_, minusScaleRect, valScaleRect, plusScaleRect) = UIScaleRects(top);
            var scaleTitle = HoveredUIScaleRow ? _uiScaleHoverTitle : _uiScaleTitle;
            if (scaleTitle.Size.Width > 0 && scaleTitle.Size.Height > 0)
            {
                pageContent.Add(new OriginalGameplayOverlay.Part(
                    scaleTitle,
                    new CGRect(
                        SubpanelOrigin.X + 460 - scaleTitle.Size.Width,
                        minusScaleRect.MinY + Math.Floor((minusScaleRect.Height - scaleTitle.Size.Height) / 2.0),
                        scaleTitle.Size.Width,
                        scaleTitle.Size.Height)));
            }

            var well = GetRecessedWell((int)valScaleRect.Width, (int)valScaleRect.Height);
            pageContent.Add(new OriginalGameplayOverlay.Part(well, valScaleRect));

            AppendArrowButton(pageContent, right: false, minusScaleRect, hovered: HoveredUIScaleStep == -1);
            AppendArrowButton(pageContent, right: true, plusScaleRect, hovered: HoveredUIScaleStep == 1);

            var valImg = GetUIScaleValueLabel(CurrentUIScaleText, HoveredUIScaleStep == 0);
            pageContent.Add(new OriginalGameplayOverlay.Part(
                valImg,
                new CGRect(
                    valScaleRect.MinX + Math.Floor((valScaleRect.Width - valImg.Size.Width) / 2.0),
                    valScaleRect.MinY + Math.Floor((valScaleRect.Height - valImg.Size.Height) / 2.0),
                    valImg.Size.Width,
                    valImg.Size.Height)));

            var hintImg = GetUIScaleHintLabel(CurrentUIScaleHintText);
            if (hintImg.Size.Width > 0 && hintImg.Size.Height > 0)
            {
                double spanCenter = (minusScaleRect.MinX + plusScaleRect.MaxX) * 0.5;
                pageContent.Add(new OriginalGameplayOverlay.Part(
                    hintImg,
                    new CGRect(
                        Math.Floor(spanCenter - hintImg.Size.Width * 0.5),
                        valScaleRect.MaxY + 5.0,
                        hintImg.Size.Width,
                        hintImg.Size.Height)));
            }
        }

        _lastPageContent = pageContent;
        if (_transitionFromParts is { } outgoing && outgoingOpacity is { } outAlpha && outAlpha > 0f)
        {
            foreach (var p in outgoing)
            {
                parts.Add(new OriginalGameplayOverlay.Part(p.Image, p.Rect, p.UV, p.Opacity * outAlpha));
            }
        }

        if (effectOpacity > 0f)
        {
            foreach (var p in pageContent)
            {
                parts.Add(new OriginalGameplayOverlay.Part(p.Image, p.Rect, p.UV, p.Opacity * effectOpacity));
            }
        }

        return parts;
    }

    private static bool Contains(CGRect rect, CGPoint point) =>
        point.X >= rect.X && point.X < rect.X + rect.Width &&
        point.Y >= rect.Y && point.Y < rect.Y + rect.Height;
}

public static class OriginalOptionsPanelOverlayExtensions
{
    public static string Asset(this OriginalOptionsPanelOverlay.Button button) => button switch
    {
        OriginalOptionsPanelOverlay.Button.Neighborhood => "UIGraphics/cpanel/Buttons/OptNbhd.bmp",
        OriginalOptionsPanelOverlay.Button.Save => "UIGraphics/cpanel/Buttons/OptSave.BMP",
        OriginalOptionsPanelOverlay.Button.Quit => "UIGraphics/cpanel/Buttons/OptExit.bmp",
        OriginalOptionsPanelOverlay.Button.Graphics => "UIGraphics/cpanel/Buttons/optgraphics.bmp",
        OriginalOptionsPanelOverlay.Button.Sound => "UIGraphics/cpanel/Buttons/optsound.bmp",
        OriginalOptionsPanelOverlay.Button.Play => "UIGraphics/cpanel/Buttons/optplay.bmp",
        OriginalOptionsPanelOverlay.Button.ResetTutorial => "UIGraphics/cpanel/Buttons/opttutreset.BMP",
        _ => throw new ArgumentOutOfRangeException(nameof(button), button, null)
    };

    public static int StringIndex(this OriginalOptionsPanelOverlay.Button button) => (int)button switch
    {
        0 => 0,
        1 => 2,
        2 => 4,
        3 => 6,
        4 => 8,
        5 => 10,
        6 => 68,
        _ => throw new ArgumentOutOfRangeException(nameof(button), button, null)
    };

    public static CGPoint FallbackPosition(this OriginalOptionsPanelOverlay.Button button) => (int)button switch
    {
        0 => new CGPoint(88, 6),
        1 => new CGPoint(29, 6),
        2 => new CGPoint(159, 6),
        3 => new CGPoint(29, 58),
        4 => new CGPoint(89, 58),
        5 => new CGPoint(151, 58),
        6 => new CGPoint(555, 7),
        _ => throw new ArgumentOutOfRangeException(nameof(button), button, null)
    };

    public static string FallbackLabel(this OriginalOptionsPanelOverlay.Button button) => (int)button switch
    {
        0 => "Neighborhood",
        1 => "Save",
        2 => "Quit",
        3 => "Graphics Options",
        4 => "Sound Options",
        5 => "Play Options",
        6 => "Reset Tutorial",
        _ => throw new ArgumentOutOfRangeException(nameof(button), button, null)
    };

    public static int StringIndex(this OriginalOptionsPanelOverlay.DetailSetting setting) =>
        setting == OriginalOptionsPanelOverlay.DetailSetting.Terrain ? 28 : 31;

    public static string FallbackLabel(this OriginalOptionsPanelOverlay.DetailSetting setting) =>
        setting == OriginalOptionsPanelOverlay.DetailSetting.Terrain ? "Terrain Detail" : "Character Detail";

    public static string PopupAsset(this OriginalOptionsPanelOverlay.DetailSetting setting) => setting switch
    {
        OriginalOptionsPanelOverlay.DetailSetting.Terrain => "UIGraphics/CPanel/PopupOptTerrainDetail.bmp",
        OriginalOptionsPanelOverlay.DetailSetting.Character => "UIGraphics/CPanel/PopupOptCharDetail.bmp",
        _ => throw new ArgumentOutOfRangeException(nameof(setting), setting, null)
    };

    public static bool IsImplemented(this OriginalOptionsPanelOverlay.DetailSetting _) => true;

    public static OriginalOptionsPanelOverlay.Page Page(this OriginalOptionsPanelOverlay.PlayOption option) =>
        (int)option < 8 ? OriginalOptionsPanelOverlay.Page.Play : OriginalOptionsPanelOverlay.Page.Graphics;

    public static int GraphicsBuiltinSubpage(this OriginalOptionsPanelOverlay.PlayOption option) => option switch
    {
        OriginalOptionsPanelOverlay.PlayOption.AntiAlias => 0,
        OriginalOptionsPanelOverlay.PlayOption.Shadows => 0,
        OriginalOptionsPanelOverlay.PlayOption.Lighting => 0,
        OriginalOptionsPanelOverlay.PlayOption.Fullscreen => 1,
        OriginalOptionsPanelOverlay.PlayOption.SharpText => 1,
        OriginalOptionsPanelOverlay.PlayOption.InterfaceEffects => 1,
        _ => 0,
    };

    public static int Row(this OriginalOptionsPanelOverlay.PlayOption option) => option switch
    {
        OriginalOptionsPanelOverlay.PlayOption.AntiAlias => 0,
        OriginalOptionsPanelOverlay.PlayOption.Shadows => 1,
        OriginalOptionsPanelOverlay.PlayOption.Lighting => 2,
        OriginalOptionsPanelOverlay.PlayOption.Fullscreen => 0,
        OriginalOptionsPanelOverlay.PlayOption.SharpText => 1,
        OriginalOptionsPanelOverlay.PlayOption.InterfaceEffects => 2,
        _ => (int)option % 4,
    };

    public static bool IsColumnA(this OriginalOptionsPanelOverlay.PlayOption option) =>
        (int)option is >= 4 and < 8;

    public static int StringIndex(this OriginalOptionsPanelOverlay.PlayOption option) => (int)option switch
    {
        0 => 56,
        1 => 59,
        2 => 62,
        3 => 65,
        4 => 72,
        5 => 75,
        6 => 78,
        7 => 81,
        8 => 14,
        9 => 17,
        10 => 20,
        11 => 23,
        12 => -1,
        13 => -1,
        _ => throw new ArgumentOutOfRangeException(nameof(option), option, null)
    };

    public static string FallbackLabel(this OriginalOptionsPanelOverlay.PlayOption option) => (int)option switch
    {
        0 => "Auto-Centering",
        1 => "Free Will",
        2 => "Edge Scrolling",
        3 => "Sim In Background",
        4 => "Quick Tips",
        5 => "Auto Snapshot",
        6 => "Live PIP",
        7 => "Export HTML",
        8 => "Anti-alias",
        9 => "Shadows",
        10 => "Lighting",
        11 => "Interface Effects",
        12 => "Sharp Text",
        13 => "Fullscreen",
        _ => throw new ArgumentOutOfRangeException(nameof(option), option, null)
    };

    public static string PopupAsset(this OriginalOptionsPanelOverlay.PlayOption option) => option switch
    {
        OriginalOptionsPanelOverlay.PlayOption.AutoCenter => "UIGraphics/CPanel/PopupOptAutoCenter.bmp",
        OriginalOptionsPanelOverlay.PlayOption.FreeWill => "UIGraphics/CPanel/PopupOptFreeWill.bmp",
        OriginalOptionsPanelOverlay.PlayOption.EdgeScrolling => "UIGraphics/CPanel/PopupOptEdgeScroll.bmp",
        OriginalOptionsPanelOverlay.PlayOption.SimInBackground => "UIGraphics/CPanel/PopupOptSimInBack.bmp",
        OriginalOptionsPanelOverlay.PlayOption.QuickTips => "UIGraphics/CPanel/PopupOptQuickTips.bmp",
        OriginalOptionsPanelOverlay.PlayOption.AutoSnapshot => "UIGraphics/CPanel/PopupOptAutoSnap.bmp",
        OriginalOptionsPanelOverlay.PlayOption.LivePIP => "UIGraphics/CPanel/PopupOptLivePIP.bmp",
        OriginalOptionsPanelOverlay.PlayOption.ExportHTML => "UIGraphics/CPanel/PopupExportHTML.bmp",
        OriginalOptionsPanelOverlay.PlayOption.AntiAlias => "UIGraphics/CPanel/PopupOptAntiAlias.bmp",
        OriginalOptionsPanelOverlay.PlayOption.Shadows => "UIGraphics/CPanel/PopupOptShadows.bmp",
        OriginalOptionsPanelOverlay.PlayOption.Lighting => "UIGraphics/CPanel/PopupOptLighting.bmp",
        OriginalOptionsPanelOverlay.PlayOption.InterfaceEffects => "UIGraphics/CPanel/PopupOptTransUI.bmp",
        OriginalOptionsPanelOverlay.PlayOption.SharpText => "UIGraphics/CPanel/PopupOptAntiAlias.bmp",
        OriginalOptionsPanelOverlay.PlayOption.Fullscreen => "UIGraphics/CPanel/PopupOptTransUI.bmp",
        _ => throw new ArgumentOutOfRangeException(nameof(option), option, null)
    };

    public static bool IsImplemented(this OriginalOptionsPanelOverlay.PlayOption _) => true;

    public static bool Value(
        this OriginalOptionsPanelOverlay.PlayOption option,
        OriginalOptionsPanelOverlay.PlayOptionsState options) => option switch
    {
        OriginalOptionsPanelOverlay.PlayOption.AutoCenter => options.AutoCenter,
        OriginalOptionsPanelOverlay.PlayOption.FreeWill => options.FreeWill,
        OriginalOptionsPanelOverlay.PlayOption.EdgeScrolling => options.EdgeScrolling,
        OriginalOptionsPanelOverlay.PlayOption.QuickTips => options.QuickTips,
        OriginalOptionsPanelOverlay.PlayOption.Lighting => options.Lighting,
        OriginalOptionsPanelOverlay.PlayOption.SimInBackground => options.SimInBackground,
        OriginalOptionsPanelOverlay.PlayOption.AntiAlias => options.AntiAlias,
        OriginalOptionsPanelOverlay.PlayOption.Shadows => options.Shadows,
        OriginalOptionsPanelOverlay.PlayOption.InterfaceEffects => options.InterfaceEffects,
        OriginalOptionsPanelOverlay.PlayOption.ExportHTML => options.ExportHTML,
        OriginalOptionsPanelOverlay.PlayOption.AutoSnapshot => options.AutoSnapshot,
        OriginalOptionsPanelOverlay.PlayOption.LivePIP => options.LivePIP,
        OriginalOptionsPanelOverlay.PlayOption.SharpText => options.SharpText,
        OriginalOptionsPanelOverlay.PlayOption.Fullscreen => options.Fullscreen,
        _ => throw new ArgumentOutOfRangeException(nameof(option), option, null)
    };

    public static OriginalOptionsPanelOverlay.PlayOptionsState Toggled(
        this OriginalOptionsPanelOverlay.PlayOption option,
        OriginalOptionsPanelOverlay.PlayOptionsState options)
    {
        var copy = options;
        switch (option)
        {
            case OriginalOptionsPanelOverlay.PlayOption.Lighting:
                copy.Lighting = !copy.Lighting;
                break;
            case OriginalOptionsPanelOverlay.PlayOption.AutoCenter:
                copy.AutoCenter = !copy.AutoCenter;
                break;
            case OriginalOptionsPanelOverlay.PlayOption.FreeWill:
                copy.FreeWill = !copy.FreeWill;
                break;
            case OriginalOptionsPanelOverlay.PlayOption.EdgeScrolling:
                copy.EdgeScrolling = !copy.EdgeScrolling;
                break;
            case OriginalOptionsPanelOverlay.PlayOption.QuickTips:
                copy.QuickTips = !copy.QuickTips;
                break;
            case OriginalOptionsPanelOverlay.PlayOption.SimInBackground:
                copy.SimInBackground = !copy.SimInBackground;
                break;
            case OriginalOptionsPanelOverlay.PlayOption.ExportHTML:
                copy.ExportHTML = !copy.ExportHTML;
                break;
            case OriginalOptionsPanelOverlay.PlayOption.AntiAlias:
                copy.AntiAlias = !copy.AntiAlias;
                break;
            case OriginalOptionsPanelOverlay.PlayOption.Shadows:
                copy.Shadows = !copy.Shadows;
                break;
            case OriginalOptionsPanelOverlay.PlayOption.InterfaceEffects:
                copy.InterfaceEffects = !copy.InterfaceEffects;
                break;
            case OriginalOptionsPanelOverlay.PlayOption.AutoSnapshot:
                copy.AutoSnapshot = !copy.AutoSnapshot;
                break;
            case OriginalOptionsPanelOverlay.PlayOption.LivePIP:
                copy.LivePIP = !copy.LivePIP;
                break;
            case OriginalOptionsPanelOverlay.PlayOption.SharpText:
                copy.SharpText = !copy.SharpText;
                break;
            case OriginalOptionsPanelOverlay.PlayOption.Fullscreen:
                copy.Fullscreen = !copy.Fullscreen;
                break;
        }
        return copy;
    }
}
