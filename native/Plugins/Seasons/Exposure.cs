using SimsNative.Plugins;
using System.Text.Json;

namespace Local.Seasons;

// Simulates weather exposure and motive degradation for outdoor characters, tracking wetness and
// temperature chills. Rain comfort loss is recovered when drying indoors, whereas cold or heat discomfort
// recovers over time indoors at a steady rate.
public sealed partial class SeasonsPlugin
{
    private const int Comfort = 6, Hygiene = 8;
    private const float ComfortFloor = -50, HygieneFloor = -30, WarmUp = 12;
    private int? exposedAt;
    private readonly Dictionary<short, (float Comfort, float Hygiene)> exposure = [];
    private HashSet<short> outdoors = [];
    private float outdoorAppeal = 1, shelteredAppeal = 1;
    private HashSet<short> sheltered = [];
    private readonly Dictionary<short, (float Wetness, float Soaked, float Chilled, float Owed)> wet = [];
    private readonly Dictionary<short, float> bodyTemp = [];
    private readonly Dictionary<short, bool> simWearingWinterCoat = [];

    private void ResetExposure()
    {
        exposedAt = null;
        exposure.Clear();
        wet.Clear();
        bodyTemp.Clear();
        lastDone.Clear();
        manualWinterCoat.Clear();
        simWearingWinterCoat.Clear();
        outdoors = [];
        sheltered = [];
        objectNames = [];
        outdoorAppeal = shelteredAppeal = 1;
    }

    private float GetBodyTemp(short simId) => bodyTemp.GetValueOrDefault(simId, 0f);
    private void AdjustBodyTemp(short simId, float delta) => bodyTemp[simId] = Math.Clamp(GetBodyTemp(simId) + delta, -100f, 100f);

    private sealed record ExposureSave(int House, ExposureSim[] Sims);
    private sealed record ExposureSim(short Neighbor, float Comfort, float Hygiene,
        float Wetness, float Soaked, float Chilled, float Owed,
        [property: System.Text.Json.Serialization.JsonIgnore(Condition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingDefault)]
        float BodyTemp = 0f);

    private bool restoreNeighborhoodExposure = true;

    private void RestoreNeighborhoodExposure()
    {
        if (!restoreNeighborhoodExposure) return;
        restoreNeighborhoodExposure = false;
        var house = context.Simulation.House;
        if (context.NeighborhoodValues.TryGetValue(ExposureKey(house), out var data))
            RestoreExposure(2, System.Text.Encoding.UTF8.GetBytes(data));
    }

    private static string ExposureKey(int house) => $"exposure-{house}";

    private byte[] SaveExposure()
    {
        RestoreNeighborhoodExposure();
        var lot = context.Simulation;
        var sims = lot.HouseholdSims.Where(sim => sim.NeighborId > 0 &&
            (exposure.ContainsKey(sim.ObjectId) || wet.ContainsKey(sim.ObjectId) || Math.Abs(bodyTemp.GetValueOrDefault(sim.ObjectId)) >= 0.5f)).Select(sim =>
        {
            var loss = exposure.GetValueOrDefault(sim.ObjectId);
            var water = wet.GetValueOrDefault(sim.ObjectId);
            return new ExposureSim(sim.NeighborId, loss.Comfort, loss.Hygiene,
                water.Wetness, water.Soaked, water.Chilled, water.Owed, bodyTemp.GetValueOrDefault(sim.ObjectId));
        }).ToArray();
        var data = JsonSerializer.SerializeToUtf8Bytes(new ExposureSave(lot.House, sims));
        if (Seasonal(lot.House))
            context.NeighborhoodValues[ExposureKey(lot.House)] = System.Text.Encoding.UTF8.GetString(data);
        return data;
    }

    private void RestoreExposure(int version, byte[] data)
    {
        if (data.Length == 0) return;
        if (version != 2) throw new InvalidDataException("Unsupported Seasons exposure state");
        var saved = JsonSerializer.Deserialize<ExposureSave>(data)
            ?? throw new InvalidDataException("Missing Seasons exposure state");
        if (saved.Sims == null || saved.Sims.Length > 64 ||
            saved.Sims.Select(sim => sim.Neighbor).Distinct().Count() != saved.Sims.Length ||
            saved.Sims.Any(sim => sim.Neighbor <= 0 ||
                !float.IsFinite(sim.Comfort) || sim.Comfort is < 0 or >= 1 ||
                !float.IsFinite(sim.Hygiene) || sim.Hygiene is < 0 or >= 1 ||
                !float.IsFinite(sim.Wetness) || sim.Wetness is < 0 or > 1 ||
                !float.IsFinite(sim.Soaked) || sim.Soaked < 0 ||
                !float.IsFinite(sim.Chilled) || sim.Chilled < 0 ||
                !float.IsFinite(sim.Owed) || sim.Owed is < 0 or >= 1 ||
                !float.IsFinite(sim.BodyTemp) || sim.BodyTemp is < -100 or > 100))
            throw new InvalidDataException("Invalid Seasons exposure state");
        var lot = context.Simulation;
        if (saved.House != lot.House) return;
        // Neighbor IDs persistently identify characters across sessions, whereas object IDs are reassigned
        // upon loading a lot.
        foreach (var sim in lot.HouseholdSims)
        {
            var value = saved.Sims.FirstOrDefault(item => item.Neighbor == sim.NeighborId);
            if (value == null) continue;
            exposure[sim.ObjectId] = (value.Comfort, value.Hygiene);
            wet[sim.ObjectId] = (value.Wetness, value.Soaked, value.Chilled, value.Owed);
            if (Math.Abs(value.BodyTemp) >= 0.01f) bodyTemp[sim.ObjectId] = value.BodyTemp;
        }
        // Initializes exposure timing to current lot time on load so skipped or offline elapsed time is not
        // penalized.
        exposedAt = lot.Hours * 60 + lot.Minutes;
    }

    private (float Comfort, float Hygiene, float Appeal, float Rain) Exposure(float time, bool covered = false)
    {
        var day = (int)MathF.Floor(time / 24);
        var hour = time - day * 24;
        var rain = covered ? 0 : Precipitation(time);
        var snowing = rain > 0.05f && FallingAt(time) == "snow";
        var degrees = Temperature(time, true);
        var (comfort, hygiene, appeal) = (0f, 0f, 1f);
        if (rain > 0.05f && snowing) { comfort += 4 * rain; appeal *= 0.7f; }
        else if (rain > 0.05f) { comfort += 6 + 10 * rain; hygiene += 6 * rain; appeal *= Storm(time) ? 0.3f : 0.4f; }
        if (!snowing && degrees < 40) { comfort += Math.Min(6, (40 - degrees) / 4); appeal *= 0.7f; }
        var (rise, set) = Daylight(time / 24, true);
        if (degrees > 88 && hour >= rise && hour < set && CloudCover(time) < 0.55f) { comfort += Math.Min(4, (degrees - 88) / 3); appeal *= 0.8f; }
        if (appeal == 1 && rain <= 0.05f && degrees is >= 60 and <= 85 && hour >= rise && hour < set && CloudCover(time) < 0.55f) appeal = 1.25f;
        if (Holiday(day) != null && hour >= rise && hour < set && (appeal >= 1 || snowing && rain <= 0.6f)) appeal = 1.5f;
        return (comfort, hygiene, Math.Max(0.3f, appeal), rain > 0.05f && !snowing ? rain : 0);
    }

    private Dictionary<short, string> objectNames = [];

    private static bool NameMatches(string name, params string[] tokens) =>
        tokens.Any(token => name.Contains(token, StringComparison.OrdinalIgnoreCase));

    private static bool IsNativeWarmthObject(string name) =>
        NameMatches(name, "fireplace", "campfire", "bonfire", "hot tub", "love tub", "jacuzzi");

    private static bool IsNativeCoolingObject(string name) =>
        NameMatches(name, "pool", "sprinkler");

    private static bool IsWarmingAnimation(string? animation) =>
        animation is { Length: > 0 } && NameMatches(animation, "coffee", "espresso", "bath", "shower", "hottub", "fireplace", "warm");

    private static bool IsSwimmingAnimation(string? animation) =>
        animation is { Length: > 0 } && NameMatches(animation, "swim", "pool");

    private static float Distance2D(PluginObject a, PluginObject b)
    {
        var dx = a.X - b.X;
        var dy = a.Y - b.Y;
        return MathF.Sqrt(dx * dx + dy * dy);
    }

    private int? lastWateredSlot;
    private int? snowDayRewardedDay;

    private bool IsSnowDay(int house, int day, float hour)
    {
        if (!Seasonal(house) || Season(day) != 3) return false;
        if (hour is < 6.5f or > 10.5f) return false;
        return SnowPack(day, hour) >= 0.85f && Precipitation(day * 24 + hour) >= 0.25f;
    }

    public void OnTick(long update)
    {
        SyncWeatherAndClientState();
        RestoreNeighborhoodExposure();
        var lot = context.Simulation;
        UpdateSnowmanWeather();
        AdvanceSnowballFights(update);
        if (!Seasonal(lot.House) || lot.House is >= 40 and <= 42) { ResetExposure(); return; }
        UpdateWinterOuterwear(lot);
        if (lot.Paused) return;
        var minute = lot.Hours * 60 + lot.Minutes;
        if (exposedAt == minute) return;
        var passed = exposedAt is int last ? (minute - last + 1440) % 1440 : 0;
        exposedAt = minute;
        var hourNow = minute / 60f;
        var timeNow = Day * 24 + hourNow;
        var (comfortRate, hygieneRate, appeal, rain) = Exposure(timeNow);
        var protectedRates = Exposure(timeNow, true);
        var degrees = Temperature(timeNow, true);
        var snowNow = rain > 0.05f && FallingAt(timeNow) == "snow";
        if (rain > 0.15f && !snowNow)
        {
            var slot = Day * 48 + minute / 30;
            if (lastWateredSlot != slot)
            {
                lastWateredSlot = slot;
                WaterOutdoorPlants(lot);
            }
        }
        // Snow Day morning: household children get a real Fun & Comfort boost while school is cancelled.
        if (IsSnowDay(lot.House, Day, hourNow) && snowDayRewardedDay != Day)
        {
            snowDayRewardedDay = Day;
            foreach (var sim in lot.HouseholdSims.Where(s => s.Child))
            {
                lot.ChangeMotive(sim.ObjectId, 15, 20); // Fun
                lot.ChangeMotive(sim.ObjectId, 6, 10);  // Comfort
            }
        }
        var objects = lot.Objects;
        outdoors = objects.Where(item => item.Outside).Select(item => item.ObjectId).ToHashSet();
        sheltered = objects.Where(item => item.Sheltered).Select(item => item.ObjectId).ToHashSet();
        objectNames = objects.ToDictionary(item => item.ObjectId, item => item.Name);
        var warmthSources = objects.Where(o => IsNativeWarmthObject(o.Name)).ToArray();
        var coolingSources = objects.Where(o => IsNativeCoolingObject(o.Name)).ToArray();
        outdoorAppeal = appeal; shelteredAppeal = protectedRates.Appeal;
        // Time jumps exceeding 30 minutes indicate lot loads, fast-forward sleep skips, or travel, and are
        // ignored to prevent unwarranted exposure.
        if (passed is < 1 or > 30) return;
        // Calculates the proportion of comfort loss attributable to rain, which is the only portion
        // refunded upon drying indoors.
        var rainShare = rain > 0 && comfortRate > 0 ? (6 + 10 * rain) / comfortRate : 0;
        foreach (var sim in lot.HouseholdSims)
        {
            var (wetness, soaked, chilled, owed) = wet.GetValueOrDefault(sim.ObjectId);
            var simObj = objects.FirstOrDefault(o => o.ObjectId == sim.ObjectId);
            var nearWarmth = (simObj != null && warmthSources.Any(w => Distance2D(w, simObj) <= 4.5f)) || IsWarmingAnimation(sim.Animation);
            var swimming = IsSwimmingAnimation(sim.Animation);
            var nearCooling = swimming || (simObj != null && coolingSources.Any(c => Distance2D(c, simObj) <= 3.5f));
            var curTemp = GetBodyTemp(sim.ObjectId);
            if (!outdoors.Contains(sim.ObjectId))
            {
                var target = nearWarmth ? 16f : 0f;
                var rate = nearWarmth ? 2.2f : 0.75f;
                var nextTemp = curTemp + Math.Clamp(target - curTemp, -rate * passed, rate * passed);
                if (Math.Abs(nextTemp) < 0.05f) bodyTemp.Remove(sim.ObjectId);
                else bodyTemp[sim.ObjectId] = nextTemp;

                exposure.Remove(sim.ObjectId);
                var recoveryMult = nearWarmth ? 2.5f : 1f;
                if (wetness > 0)
                {
                    var dried = Math.Min(wetness, recoveryMult * passed / 60f);
                    owed += soaked * dried / wetness;
                    soaked -= soaked * dried / wetness;
                    wetness -= dried;
                }
                if (chilled > 0)
                {
                    var warmed = Math.Min(chilled, WarmUp * recoveryMult * passed / 60);
                    owed += warmed;
                    chilled -= warmed;
                }
                owed = Regain(sim.ObjectId, owed);
                if (wetness > 0 || chilled > 0 || owed >= 1) wet[sim.ObjectId] = (wetness, soaked, chilled, owed); else wet.Remove(sim.ObjectId);
                continue;
            }
            var covered = sheltered.Contains(sim.ObjectId);
            var actorRain = covered ? 0 : rain;
            var actorComfort = covered ? protectedRates.Comfort : comfortRate;
            var actorHygiene = covered ? protectedRates.Hygiene : hygieneRate;
            var coatFactor = sim.WearingOutdoorSuit && (degrees < 55f || snowNow) ? 0.35f : 1f;
            if (coatFactor < 1f && actorRain <= 0.05f) actorComfort *= coatFactor;
            if (nearWarmth)
            {
                // Outdoor fireplace/campfire/hot tub actively warms chilled Sims and reduces cold discomfort.
                actorComfort *= 0.25f;
                var nextTemp = curTemp + Math.Clamp(14f - curTemp, -2.0f * passed, 2.0f * passed);
                if (Math.Abs(nextTemp) < 0.05f) bodyTemp.Remove(sim.ObjectId);
                else bodyTemp[sim.ObjectId] = nextTemp;
            }
            else if (nearCooling && degrees >= 72f)
            {
                // Swimming pools and sprinklers refresh overheating Sims during warm weather.
                actorComfort *= 0.2f;
                var nextTemp = curTemp + Math.Clamp(-8f - curTemp, -2.2f * passed, 2.2f * passed);
                if (Math.Abs(nextTemp) < 0.05f) bodyTemp.Remove(sim.ObjectId);
                else bodyTemp[sim.ObjectId] = nextTemp;
            }
            else
            {
                var ambientDrift = (degrees - 68f) * 1.35f;
                if (degrees < 55f && sim.WearingOutdoorSuit) ambientDrift *= 0.3f;
                if (swimming && degrees <= 45f) ambientDrift -= 28f;
                if (wetness > 0.25f) ambientDrift -= 18f * wetness;
                var target = Math.Clamp(ambientDrift, -95f, 95f);
                var delta = Math.Clamp(target - curTemp, -1.1f * passed, 1.1f * passed);
                var nextTemp = Math.Clamp(curTemp + delta, -100f, 100f);
                if (Math.Abs(nextTemp) >= 0.05f) bodyTemp[sim.ObjectId] = nextTemp;
            }
            var (comfort, hygiene) = exposure.GetValueOrDefault(sim.ObjectId);
            (comfort, var taken) = Lose(sim.ObjectId, Comfort, ComfortFloor, comfort + actorComfort * passed / 60);
            (hygiene, _) = Lose(sim.ObjectId, Hygiene, HygieneFloor, hygiene + actorHygiene * passed / 60);
            exposure[sim.ObjectId] = (comfort, hygiene);
            var share = covered ? 0 : Math.Min(1, rainShare);
            chilled += taken * (1 - share);
            if (actorRain > 0) (wetness, soaked) = (Math.Min(1, wetness + actorRain * passed / 30f), soaked + taken * share);
            else if (wetness > 0) { var dried = Math.Min(wetness, passed / 120f); soaked -= soaked * dried / wetness; wetness -= dried; }
            if (wetness > 0 || chilled > 0 || owed >= 1) wet[sim.ObjectId] = (wetness, soaked, chilled, owed); else wet.Remove(sim.ObjectId);
        }
        foreach (var gone in exposure.Keys.Where(id => !lot.HouseholdSims.Any(sim => sim.ObjectId == id)).ToArray()) exposure.Remove(gone);
        foreach (var gone in wet.Keys.Where(id => !lot.HouseholdSims.Any(sim => sim.ObjectId == id)).ToArray()) wet.Remove(gone);
        foreach (var gone in bodyTemp.Keys.Where(id => !lot.HouseholdSims.Any(sim => sim.ObjectId == id)).ToArray()) bodyTemp.Remove(gone);
    }

    private void WaterOutdoorPlants(IPluginSimulation lot)
    {
        foreach (var item in lot.Objects)
        {
            if (item.IsPerson || item.ObjectId != item.LeadObjectId) continue;
            if (!item.Outside || item.Sheltered || item.AttributeCount <= 0) continue;
            if (!lot.GetDefinedInteractions(item.ObjectId).Any(static name => name.Contains("Water", StringComparison.OrdinalIgnoreCase)))
                continue;
            if (context.GetObjectAttribute(item.ObjectId, 0) < 100)
                context.SetObjectAttribute(item.ObjectId, 0, 100);
        }
    }

    private void UpdateWinterOuterwear(IPluginSimulation lot)
    {
        var dayIndex = Day;
        var hour = (lot.Hours * 60 + lot.Minutes) / 60f;
        var time = dayIndex * 24 + hour;
        var season = Season(dayIndex);
        var (mode, amount, _) = Ground(dayIndex, hour);
        var rain = QuantizePrecipitation(Precipitation(time));
        var tempF = Temperature(time, true);
        bool winterWeather = season == 3 || (mode == 2 && (amount > 0 || rain > 0)) || tempF <= 42f;

        IReadOnlyList<PluginSimProfile> sims;
        try { sims = lot.AllSims; }
        catch (NotSupportedException) { return; }

        var presentIds = new HashSet<short>();
        foreach (var sim in sims)
        {
            if ((!sim.Household && !sim.Visitor) || sim.Dog || sim.Cat)
                continue;
            presentIds.Add(sim.ObjectId);
            bool manual = manualWinterCoat.Contains(sim.ObjectId);
            bool wantsCoat = manual || (winterWeather && sim.Outside);
            bool currentlyApplied = simWearingWinterCoat.GetValueOrDefault(sim.ObjectId);
            if (wantsCoat == currentlyApplied)
                continue;

            if (wantsCoat)
            {
                var suit = context.ResolveSimSuit(sim.ObjectId, 'w', 33);
                if (string.IsNullOrEmpty(suit))
                    continue;
                context.SetSimAppearanceOverride(sim.ObjectId, suit, animateSpin: true);
                simWearingWinterCoat[sim.ObjectId] = true;
            }
            else
            {
                context.SetSimAppearanceOverride(sim.ObjectId, null, animateSpin: true);
                simWearingWinterCoat.Remove(sim.ObjectId);
            }
        }

        foreach (var gone in simWearingWinterCoat.Keys.Where(id => !presentIds.Contains(id)).ToArray())
            simWearingWinterCoat.Remove(gone);
    }

    private float Regain(short sim, float owed)
    {
        var points = (int)MathF.Floor(owed);
        if (points <= 0) return owed;
        var room = (int)Math.Max(0, 100 - context.Simulation.GetMotive(sim, Comfort));
        if (room > 0) context.Simulation.ChangeMotive(sim, Comfort, Math.Min(points, Math.Min(room, 100)));
        return owed - points;
    }

    private (float Owed, int Taken) Lose(short sim, int motive, float floor, float owed)
    {
        var points = (int)MathF.Floor(owed);
        if (points <= 0) return (owed, 0);
        var room = (int)Math.Max(0, context.Simulation.GetMotive(sim, motive) - floor);
        var taken = Math.Min(points, Math.Min(room, 100));
        if (taken > 0) context.Simulation.ChangeMotive(sim, motive, -taken);
        return (owed - points, taken);
    }

    // Critical motives below the urgency threshold bypass weather appeal modifiers so emergency autonomous
    // actions remain unaffected.
    private static readonly int[] Urgent = [5, 7, 8, 9];
    private const int UrgentBelow = -40;

    public float ScoreAutonomy(PluginAutonomyChoice choice, float score)
    {
        // Snow activity availability is verified before urgent-need exemptions because snow objects cannot
        // satisfy survival motives.
        if (IsSnowActivity(choice.ObjectGuid, choice.InteractionId, choice.Global) && !SnowActivityAvailable(choice.ObjectGuid)) return 0;
        var lot = context.Simulation;
        var hour = (lot.Hours * 60 + lot.Minutes) / 60f;
        var time = Day * 24 + hour;
        if (IsSnowDay(lot.House, Day, hour)
            && lot.HouseholdSims.Any(s => s.ObjectId == choice.SimId && s.Child)
            && objectNames.TryGetValue(choice.ObjectId, out var busName)
            && busName.Contains("School Bus", StringComparison.OrdinalIgnoreCase))
        {
            return 0;
        }
        var urgent = choice.Household && Urgent.Any(motive => lot.GetMotive(choice.SimId, motive) < UrgentBelow);
        var adjusted = score;
        if (outdoors.Contains(choice.ObjectId) && !urgent)
            adjusted *= sheltered.Contains(choice.ObjectId) ? shelteredAppeal : outdoorAppeal;

        // Smart Rain Reactions: Sims caught outside in rain or thunderstorms hurry indoors.
        var rainNow = Seasonal(lot.House) ? Precipitation(time) : 0f;
        var snowingNow = rainNow > 0.05f && FallingAt(time) == "snow";
        if (!urgent && choice.Household && rainNow > 0.25f && !snowingNow)
        {
            var isTargetOutdoor = outdoors.Contains(choice.ObjectId) && !sheltered.Contains(choice.ObjectId);
            var isStorm = Storm(time);
            if (isTargetOutdoor)
            {
                adjusted *= isStorm ? 0.15f : 0.25f;
            }
            else if (wet.TryGetValue(choice.SimId, out var wState) && wState.Wetness >= 0.15f)
            {
                adjusted *= isStorm ? 1.75f : 1.45f;
            }
        }

        if (!urgent && choice.Household && objectNames.TryGetValue(choice.ObjectId, out var objName))
        {
            var simTemp = GetBodyTemp(choice.SimId);
            if (simTemp < -30f && (IsNativeWarmthObject(objName) || NameMatches(objName, "coffee", "espresso", "tub", "bath", "shower")))
                adjusted *= 1.45f;
            else if (simTemp > 45f && (IsNativeCoolingObject(objName) || NameMatches(objName, "shower", "bath")))
                adjusted *= 1.45f;

            if (Holiday(Day) != null)
            {
                var season = Season(Day);
                var festiveMatch = season switch
                {
                    0 => NameMatches(objName, "flower", "garden", "picnic", "swing", "bench"),
                    1 => NameMatches(objName, "pool", "hot tub", "sprinkler", "grill", "barbecue", "volleyball"),
                    2 => NameMatches(objName, "fireplace", "stove", "oven", "dining", "garden", "campfire"),
                    _ => IsSnowObject(choice.ObjectGuid) || NameMatches(objName, "fireplace", "christmas", "tree", "campfire", "hot tub"),
                };
                if (festiveMatch) adjusted *= 1.35f;
            }
        }
        return adjusted;
    }
}
