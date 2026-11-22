using System.Text.Json;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;
using SdlSceneLighting = SimsSDL.Core.SceneLighting;

namespace SimsEngine.Tests;

public sealed class FireLightingTests
{
    private static XObject MakeObject(
        uint guid,
        short lightingContribution = 0,
        bool generatesLight = true,
        bool lightSource = true,
        bool hidden = false,
        ushort buildModeType = 0,
        short tileX = 20,
        short tileY = 20,
        short level = 1)
    {
        var def = new short[XObject.DefinitionCount];
        def[(int)ObjdField.Guid1] = unchecked((short)(ushort)(guid & 0xFFFF));
        def[(int)ObjdField.Guid2] = unchecked((short)(ushort)(guid >> 16));
        def[(int)ObjdField.BuildModeType] = unchecked((short)buildModeType);

        var obj = new XObject(101, def)
        {
            Position = new ObjectPosition((short)(tileX * 16 + 8), (short)(tileY * 16 + 8), level),
            RoomWord84 = 1,
        };
        obj[ObjectData.LightingContribution0100] = lightingContribution;
        obj[ObjectData.FlagField2] = generatesLight ? (short)0x0400 : (short)0;
        obj[ObjectData.LightSource] = lightSource ? (short)1 : (short)0;
        obj[ObjectData.Hidden] = hidden ? (short)1 : (short)0;
        return obj;
    }

    [Fact]
    public void HouseFire_IsClassifiedAndAlwaysEmitsStrongLowFlameLightWhenVisible()
    {
        var fire = MakeObject(
            unchecked((uint)BurnPrimitive.FireType),
            lightingContribution: 0,
            generatesLight: false,
            lightSource: false);

        var kind = SceneLighting.FireKind(fire);
        Assert.Equal(SceneLighting.FireLightKind.Flame, kind);
        Assert.True(SceneLighting.IsLightSource(fire));
        Assert.True(SceneLighting.LightStrength(fire, kind) >= 95);
        Assert.True(SceneLighting.LightLiftFor(kind) < SceneLighting.LightLift);

        var hiddenFire = MakeObject(
            unchecked((uint)BurnPrimitive.FireType),
            lightingContribution: 25,
            hidden: true);
        Assert.False(SceneLighting.IsLightSource(hiddenFire));
    }

    [Fact]
    public void Fireplaces_OnlyEmitWhenLitAndUseBoostedHearthStrengthAndLowLift()
    {
        const uint expensiveSubTileGuid = 0x72E724C8u; // Fireplace - Expensive - Left
        var unlitBuildMode5 = MakeObject(0x70001234u, lightingContribution: 0, buildModeType: 5);
        var litBuildMode5 = MakeObject(0x70001234u, lightingContribution: 25, buildModeType: 5);
        var litSubTile = MakeObject(expensiveSubTileGuid, lightingContribution: 25);

        Assert.Equal(SceneLighting.FireLightKind.Fireplace, SceneLighting.FireKind(unlitBuildMode5));
        Assert.False(SceneLighting.IsLightSource(unlitBuildMode5));

        var kind = SceneLighting.FireKind(litBuildMode5);
        Assert.Equal(SceneLighting.FireLightKind.Fireplace, kind);
        Assert.True(SceneLighting.IsLightSource(litBuildMode5));
        Assert.True(SceneLighting.LightStrength(litBuildMode5, kind) >= 85);
        Assert.True(SceneLighting.LightLiftFor(kind) < SceneLighting.LightLift);

        var subKind = SceneLighting.FireKind(litSubTile);
        Assert.Equal(SceneLighting.FireLightKind.Fireplace, subKind);
        Assert.True(SceneLighting.IsLightSource(litSubTile));
        Assert.True(SceneLighting.LightStrength(litSubTile, subKind) >= 85);
    }

    [Fact]
    public void CampfireTorchesCandlesAndElectricLamps_AreClassifiedWithExpectedStrengthsAndLifts()
    {
        const uint campfireGuid = 0xF0D9AE7Fu;
        const uint tikiTorchGuid = 0xDA746262u;
        const uint unleashedCandleGuid = 0xEA50C82Fu;
        const uint electricLampGuid = 0x70009999u;

        var unlitCampfire = MakeObject(campfireGuid, lightingContribution: 0);
        var litCampfire = MakeObject(campfireGuid, lightingContribution: 100);
        Assert.Equal(SceneLighting.FireLightKind.Campfire, SceneLighting.FireKind(unlitCampfire));
        Assert.False(SceneLighting.IsLightSource(unlitCampfire));
        Assert.True(SceneLighting.IsLightSource(litCampfire));
        Assert.True(SceneLighting.LightStrength(litCampfire, SceneLighting.FireLightKind.Campfire) >= 95);
        Assert.True(SceneLighting.LightLiftFor(SceneLighting.FireLightKind.Campfire) < SceneLighting.LightLift);

        var tiki = MakeObject(tikiTorchGuid, lightingContribution: 50);
        Assert.Equal(SceneLighting.FireLightKind.Torch, SceneLighting.FireKind(tiki));
        Assert.True(SceneLighting.IsLightSource(tiki));
        Assert.Equal(52, SceneLighting.LightStrength(tiki, SceneLighting.FireLightKind.Torch));
        Assert.True(SceneLighting.LightLiftFor(SceneLighting.FireLightKind.Torch) < SceneLighting.LightLift);

        var candle = MakeObject(unleashedCandleGuid, lightingContribution: 5);
        Assert.Equal(SceneLighting.FireLightKind.Candle, SceneLighting.FireKind(candle));
        Assert.True(SceneLighting.IsLightSource(candle));
        Assert.Equal(28, SceneLighting.LightStrength(candle, SceneLighting.FireLightKind.Candle));
        Assert.True(SceneLighting.LightLiftFor(SceneLighting.FireLightKind.Candle) < SceneLighting.LightLift);

        var electric = MakeObject(electricLampGuid, lightingContribution: 70);
        Assert.Equal(SceneLighting.FireLightKind.None, SceneLighting.FireKind(electric));
        Assert.True(SceneLighting.IsLightSource(electric));
        Assert.Equal(70, SceneLighting.LightStrength(electric, SceneLighting.FireLightKind.None));
        Assert.Equal(SceneLighting.LightLift, SceneLighting.LightLiftFor(SceneLighting.FireLightKind.None));
    }

    [Fact]
    public void Campfire_AttributeStateBlocksUnlitAndAshesEvenIfContributionStale()
    {
        const uint campfireGuid = 0xF0D9AE7Fu;

        var campfire = MakeObject(campfireGuid, lightingContribution: 100);
        campfire.Attributes = new short[8];

        // Attributes[0]=0 (off/unlit wood): never emits light even if LightingContribution0100 is non-zero.
        campfire.Attributes[0] = 0;
        campfire.Attributes[1] = 0;
        Assert.False(SceneLighting.IsLightSource(campfire));

        // Attributes[0]=1, Attributes[1]=0 (unlit wood) or 6 (burnt-out ashes): never emits light.
        campfire.Attributes[0] = 1;
        campfire.Attributes[1] = 0;
        Assert.False(SceneLighting.IsLightSource(campfire));
        campfire.Attributes[1] = 6;
        Assert.False(SceneLighting.IsLightSource(campfire));

        // Actively burning states (Attributes[0]=1, Attributes[1] in 1..5): emits light.
        campfire.Attributes[1] = 3;
        Assert.True(SceneLighting.IsLightSource(campfire));
    }

    [Fact]
    public void SceneLightingLight_JsonDeserializationDefaultsFireFalseAndParsesTrue()
    {
        var legacyJson = """{"x":120.5,"y":240.25,"toward":12.5,"strength":65,"level":1}""";
        var legacy = JsonSerializer.Deserialize<SdlSceneLighting.Light>(legacyJson);
        Assert.False(legacy.Fire);
        Assert.Equal(65, legacy.Strength);

        var fireJson = """{"x":120.5,"y":240.25,"toward":12.5,"strength":95,"level":1,"fire":true}""";
        var fire = JsonSerializer.Deserialize<SdlSceneLighting.Light>(fireJson);
        Assert.True(fire.Fire);
        Assert.Equal(95, fire.Strength);
    }
}
