using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;

namespace SimsSimulation;

internal sealed class SimAppearanceTransitionService(string gameRoot, ObjectRegistry registry)
{
    private sealed class Transition(
        string? targetSuitSpec,
        PersonCharacter? previousPresentation,
        PersonCharacter? targetPresentation,
        AvatarAnimationPlayback? previousPlayback,
        AvatarAnimationPlayback changePlayback)
    {
        internal string? TargetSuitSpec { get; } = targetSuitSpec;
        internal PersonCharacter? PreviousPresentation { get; } = previousPresentation;
        internal PersonCharacter? TargetPresentation { get; } = targetPresentation;
        internal AvatarAnimationPlayback? PreviousPlayback { get; } = previousPlayback;
        internal AvatarAnimationPlayback ChangePlayback { get; } = changePlayback;
        internal bool OutfitApplied { get; set; }
    }

    private readonly Dictionary<short, (string? SuitSpec, bool Animate)> desiredSuits = [];
    private readonly Dictionary<short, string?> appliedSuits = [];
    private readonly Dictionary<short, Transition> transitions = [];
    private readonly AvatarSceneGeometry geometry = AvatarSceneGeometry.For(gameRoot, registry);
    private SimulationWorld? worldForTick;

    internal bool HasOverride(XPerson person) => person.PresentationCharacter is not null;

    internal string? ResolveCategorySuit(XPerson person, char categoryPrefix, int bodyStringIndex) =>
        geometry.ResolveSimCategorySuit(person, categoryPrefix, bodyStringIndex);

    internal void SetAppearanceOverride(short simId, string? bodySuitSpec, bool animateSpin = true)
    {
        string? normalized = string.IsNullOrWhiteSpace(bodySuitSpec) ? null : bodySuitSpec.Trim();
        if (normalized is null)
        {
            if (appliedSuits.TryGetValue(simId, out var cur) && cur is not null)
                desiredSuits[simId] = (null, animateSpin);
            else
                desiredSuits.Remove(simId);
        }
        else
        {
            desiredSuits[simId] = (normalized, animateSpin);
        }
    }

    internal void Tick(SimulationWorld world)
    {
        worldForTick = world;
        var people = world.WalkOrder.OfType<XPerson>().ToDictionary(person => person.Id);
        foreach (var id in appliedSuits.Keys.Concat(desiredSuits.Keys).Distinct().Where(id => !people.ContainsKey(id)).ToArray())
        {
            if (transitions.Remove(id, out var removed))
                removed.ChangePlayback.EventQueue.Clear();
            appliedSuits.Remove(id);
            desiredSuits.Remove(id);
        }

        foreach (var person in people.Values)
        {
            bool eligible = person[PersonData.PersonType] < 2
                && person[PersonData.IsGhost] == 0
                && person[PersonData.CurrentOutfit] == 0
                && person.SavedCharacter is { Parts.Count: 5 };

            string? targetSpec = eligible && desiredSuits.TryGetValue(person.Id, out var req) ? req.SuitSpec : null;
            bool animate = !desiredSuits.TryGetValue(person.Id, out var animReq) || animReq.Animate;

            if (transitions.TryGetValue(person.Id, out var active))
            {
                if (!eligible || !string.Equals(targetSpec, active.TargetSuitSpec, StringComparison.Ordinal))
                {
                    Cancel(person, active);
                    transitions.Remove(person.Id);
                }
                else
                {
                    if (!active.OutfitApplied &&
                        (active.ChangePlayback.EventQueue.Contains((short)101) || person.PendingAnimationEvents.Remove((short)101)))
                    {
                        ApplyPresentation(person, active.TargetPresentation, active.TargetSuitSpec);
                        active.OutfitApplied = true;
                    }
                    if (active.ChangePlayback.EndReached)
                    {
                        if (!active.OutfitApplied)
                            ApplyPresentation(person, active.TargetPresentation, active.TargetSuitSpec);
                        RestorePreviousPlayback(person, active);
                        person.NativeOutfitTransitionActive = false;
                        transitions.Remove(person.Id);
                    }
                    continue;
                }
            }

            if (!eligible)
            {
                person.PresentationCharacter = null;
                appliedSuits.Remove(person.Id);
                continue;
            }

            string? currentSpec = person.PresentationCharacter is not null && appliedSuits.TryGetValue(person.Id, out var cur) ? cur : null;
            if (string.Equals(targetSpec, currentSpec, StringComparison.Ordinal))
            {
                if (targetSpec is null)
                    desiredSuits.Remove(person.Id);
                continue;
            }

            if (!animate)
            {
                ApplyPresentation(person, BuildPresentation(person.SavedCharacter!, targetSpec), targetSpec);
                if (targetSpec is null)
                    desiredSuits.Remove(person.Id);
                continue;
            }

            if (person.NativeRouteParents.Count > 0 ||
                person.NativeRoute is { PendingPortalId: not 0 } or { AnimatorFollowState: -1 })
            {
                continue;
            }

            Start(person, targetSpec);
        }
    }

    private static PersonCharacter? BuildPresentation(PersonCharacter baseline, string? suitSpec)
    {
        if (string.IsNullOrEmpty(suitSpec))
            return null;
        var parts = baseline.Parts.ToArray();
        int comma = suitSpec.IndexOf(',');
        parts[0] = comma >= 0 ? (suitSpec[..comma], suitSpec[(comma + 1)..]) : (suitSpec, "");
        return baseline with { Parts = parts };
    }

    private void Start(XPerson person, string? targetSuitSpec)
    {
        var baseline = person.SavedCharacter!;
        var target = BuildPresentation(baseline, targetSuitSpec);
        string animationName = PersonAgeCategory.IsChild(person[PersonData.PersonAge]) ? "c2o-clotheschange" : "a2o-clotheschange";
        var clip = worldForTick?.AvatarAnimationTable.Values.FirstOrDefault(item =>
            item.Name.Equals(animationName, StringComparison.OrdinalIgnoreCase));
        if (clip is null || !clip.Events.Any(item => item.Value == 101))
        {
            ApplyPresentation(person, target, targetSuitSpec);
            if (targetSuitSpec is null)
                desiredSuits.Remove(person.Id);
            return;
        }

        var playback = new AvatarAnimationPlayback(clip, backwards: false, loop: false, startedAtMils: person.AnimatorMilliseconds)
        {
            Interruptible = false,
        };
        var transition = new Transition(targetSuitSpec, person.PresentationCharacter, target, person.AnimationPlayback, playback);
        transitions[person.Id] = transition;
        person.AnimationPlayback = playback;
        person.NativeOutfitTransitionActive = true;
    }

    internal void Reset(SimulationWorld? world)
    {
        if (world is not null)
        {
            foreach (var person in world.WalkOrder.OfType<XPerson>())
                if (transitions.Remove(person.Id, out var active)) Cancel(person, active);
        }
        desiredSuits.Clear();
        appliedSuits.Clear();
        transitions.Clear();
        worldForTick = null;
    }

    private void ApplyPresentation(XPerson person, PersonCharacter? presentation, string? suitSpec)
    {
        person.PresentationCharacter = presentation;
        if (suitSpec is null)
            appliedSuits.Remove(person.Id);
        else
            appliedSuits[person.Id] = suitSpec;
    }

    private static void RestorePreviousPlayback(XPerson person, Transition transition)
    {
        transition.PreviousPlayback?.Tick(deliverAnimationEvents: false, person.AnimatorMilliseconds);
        person.AnimationPlayback = transition.PreviousPlayback;
    }

    private void Cancel(XPerson person, Transition transition)
    {
        person.PresentationCharacter = transition.PreviousPresentation;
        if (transition.PreviousPresentation is null)
            appliedSuits.Remove(person.Id);
        if (ReferenceEquals(person.AnimationPlayback, transition.ChangePlayback))
            RestorePreviousPlayback(person, transition);
        person.NativeOutfitTransitionActive = false;
        transition.ChangePlayback.EventQueue.Clear();
    }
}
