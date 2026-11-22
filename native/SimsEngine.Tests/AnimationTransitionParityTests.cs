using System.Numerics;
using System.Text.Json;
using SimsEngine.Character;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsSimulation;
using Xunit;

namespace SimsEngine.Tests;

public sealed class AnimationTransitionParityTests
{
    private static Bone MakeBone(string name, string parent, Vector3 translation, bool canBlend = true, float[]? floats = null) =>
        new(name, parent, [], translation, Quaternion.Identity, [0, 0, canBlend ? 1 : 0], floats ?? [0f, 0f]);

    private static Motion MakeMotion(string name, int frames, int translationBase = 0, int rotationBase = -1) =>
        new(name, frames, 0f, [0, 0, translationBase, rotationBase], [], []);

    [Fact]
    public void StopCurrentAnimation_MovesPrimaryToLastWithPriorityPlusOneAndFadesToZeroOver200Ms()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        var background = new AvatarAnimationPlayback(new AvatarAnimationClip("bg", 8, []), false, true);
        var oldPrimary = new AvatarAnimationPlayback(new AvatarAnimationClip("old-primary", 8, []), false, false);
        var carry = new AvatarAnimationPlayback(new AvatarAnimationClip("carry", 8, []), false, true);
        person.BackgroundAnimationPlayback = background;
        person.AnimationPlayback = oldPrimary;
        person.CarryAnimationPlayback = carry;
        person.CarryPracticeMode = 6;
        person.BackgroundPracticePersonState = 0;

        context.World.StopCurrentAnimation(person);

        Assert.Null(person.AnimationPlayback);
        Assert.Same(oldPrimary, person.LastAnimationPlayback);
        Assert.Equal(1, oldPrimary.PracticePriority);
        Assert.False(oldPrimary.AllowUnblendedOverride);
        Assert.True(oldPrimary.IsPracticeWeightFadeActive);
        Assert.Equal(1f, oldPrimary.PracticeWeight);

        var newPrimary = new AvatarAnimationPlayback(new AvatarAnimationClip("new-primary", 8, []), false, false);
        context.World.BeginPrimaryAnimation(person, newPrimary);

        var order = person.GetAnimationPracticeApplicationOrder().Select(p => p.Clip.Name).ToArray();
        Assert.Equal(["bg", "new-primary", "old-primary", "carry"], order);

        for (var i = 1; i <= 4; i++)
        {
            context.World.TickAvatarAnimations(person);
            Assert.Same(oldPrimary, person.LastAnimationPlayback);
            Assert.Equal(1f - (i * 42f / 200f), oldPrimary.PracticeWeight, precision: 5);
        }

        context.World.TickAvatarAnimations(person);
        Assert.Equal(0f, oldPrimary.PracticeWeight);
        Assert.False(oldPrimary.IsPracticeWeightFadeActive);
        Assert.Null(person.LastAnimationPlayback);
    }

    [Fact]
    public void EvaluatePracticeWeight_InterpolatesSubTickWhenActiveAndHandlesZeroDuration()
    {
        var playback = new AvatarAnimationPlayback(new AvatarAnimationClip("fade", 8, []), false, false);
        playback.FadePracticeWeight(startMils: 0, endMils: 200, startWeight: 1f, targetWeight: 0f);

        Assert.Equal(1f, playback.EvaluatePracticeWeight(0, subTickAlpha: 0f));
        Assert.Equal(1f - 21f / 200f, playback.EvaluatePracticeWeight(0, subTickAlpha: 0.5f), precision: 5);

        playback.FadePracticeWeight(startMils: 100, endMils: 100, startWeight: 1f, targetWeight: 0f);
        Assert.Equal(0f, playback.EvaluatePracticeWeight(100, subTickAlpha: 0.5f));
        playback.Tick(animatorMils: 100);
        Assert.False(playback.IsPracticeWeightFadeActive);
        Assert.Equal(0f, playback.PracticeWeight);
    }

    [Fact]
    public void LastAnimationPlayback_DoesNotDeliverStaleXevtsOrSounds()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        var firedSounds = new List<AvatarAnimationSoundEvent>();
        context.World.AnimationSound = (_, sound) => firedSounds.Add(sound);

        var clip = new AvatarAnimationClip(
            "old-with-events",
            4,
            [new AvatarAnimationEvent(42, 0), new AvatarAnimationEvent(84, 1)],
            [new AvatarAnimationSoundEvent(42, "", "sound", "old_cue", false, false)],
            DurationMilliseconds: 168f);
        person.AnimationPlayback = new AvatarAnimationPlayback(clip, false, false, startedAtMils: 0);

        context.World.StopCurrentAnimation(person);
        context.World.TickAvatarAnimations(person);
        context.World.TickAvatarAnimations(person);

        Assert.Empty(person.PendingAnimationEvents);
        Assert.Empty(firedSounds);
        Assert.Empty(person.LastAnimationPlayback!.EventQueue);
        Assert.Empty(person.LastAnimationPlayback.SoundEventQueue);
    }

    [Fact]
    public void StopCurrentAnimation_PreservesExistingLastWhenPrimaryAlreadyNullAndSkipsZeroWeightPrimary()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        var first = new AvatarAnimationPlayback(new AvatarAnimationClip("first", 4, []), false, false);
        person.AnimationPlayback = first;
        context.World.StopCurrentAnimation(person);
        Assert.Same(first, person.LastAnimationPlayback);

        context.World.StopCurrentAnimation(person);
        Assert.Same(first, person.LastAnimationPlayback);

        var zeroWeight = new AvatarAnimationPlayback(new AvatarAnimationClip("zero", 4, []), false, false)
        {
            PracticeWeight = 0f,
        };
        person.AnimationPlayback = zeroWeight;
        context.World.StopCurrentAnimation(person);
        Assert.Null(person.LastAnimationPlayback);
    }

    [Fact]
    public void PoseSample_WithAllowUnblendedOverrideFalse_SkipsCanBlendZeroBonesSoPrimaryRootAndPelvisWin()
    {
        var skeleton = new Skeleton("test", [
            MakeBone("ROOT", "NULL", Vector3.Zero, canBlend: false),
            MakeBone("PELVIS", "ROOT", Vector3.Zero, canBlend: false),
            MakeBone("SPINE", "PELVIS", Vector3.Zero, canBlend: true),
        ]);
        var anim = new Animation("pose", "pose", [0f, 0f], 0, 3, 0, [
            MakeMotion("ROOT", 1, translationBase: 0),
            MakeMotion("PELVIS", 1, translationBase: 1),
            MakeMotion("SPINE", 1, translationBase: 2),
        ]);
        var primaryCurves = new AnimationCurves([1f, 0f, 0f, 2f, 0f, 0f, 10f, 0f, 0f], []);
        var lastCurves = new AnimationCurves([9f, 0f, 0f, 8f, 0f, 0f, 20f, 0f, 0f], []);

        var primaryPose = Pose.Sample(skeleton, anim, primaryCurves, 0, practiceWeight: 1f, allowUnblendedOverride: true);
        var blendedPose = Pose.Sample(skeleton, anim, lastCurves, 0, basePose: primaryPose, practiceWeight: 0.5f, allowUnblendedOverride: false);

        Assert.Equal(new Vector3(1f, 0f, 0f), blendedPose[0].LocalTranslation);
        Assert.Equal(new Vector3(2f, 0f, 0f), blendedPose[1].LocalTranslation);
        Assert.Equal(new Vector3(15f, 0f, 0f), blendedPose[2].LocalTranslation);
    }

    [Fact]
    public void RouteDrivenStopWhenNativeRouteCleared_MovesWalkClipToLastFadeOut()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        var walkPlayback = new AvatarAnimationPlayback(new AvatarAnimationClip("walk", 8, []), false, true)
        {
            RouteDriven = true,
        };
        person.AnimationPlayback = walkPlayback;
        person.NativeRoute = null;

        context.World.TickAvatarAnimations(person);

        Assert.Null(person.AnimationPlayback);
        Assert.Same(walkPlayback, person.LastAnimationPlayback);
        Assert.False(walkPlayback.AllowUnblendedOverride);
        Assert.Equal(1f, walkPlayback.PracticeWeight);

        context.World.TickAvatarAnimations(person);
        Assert.True(walkPlayback.PracticeWeight > 0f && walkPlayback.PracticeWeight < 1f);
    }

    [Fact]
    public void PlaybackStateSaveRestore_PreservesNewFieldsAndAcceptsLegacyJsonDefaults()
    {
        var playback = new AvatarAnimationPlayback(new AvatarAnimationClip("saved", 4, []), false, false)
        {
            PracticePriority = 5,
            AllowUnblendedOverride = false,
            AnchorBone = "R_TOE01",
        };
        var options = new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase };
        var json = JsonSerializer.Serialize(playback.SaveState(), options);
        var restored = AvatarAnimationPlayback.RestoreState(
            JsonSerializer.Deserialize<AvatarAnimationPlaybackState>(json, options)!);

        Assert.Equal(5, restored.PracticePriority);
        Assert.False(restored.AllowUnblendedOverride);
        Assert.Equal("R_TOE01", restored.AnchorBone);

        var legacyJson = """
        {
          "name": "legacy",
          "frameCount": 4,
          "events": [],
          "soundEvents": null,
          "standardDistance": 0,
          "standardOffset": [0, 0, 0],
          "standardRootMotionSamples": null,
          "durationMilliseconds": 168,
          "backwards": false,
          "loop": false,
          "frame": 0,
          "endReached": false,
          "routeDriven": false,
          "eventsRun": 0,
          "nextEventIndex": 0,
          "nextSoundEventIndex": 0,
          "eventQueue": [],
          "soundEventQueue": []
        }
        """;
        var legacyRestored = AvatarAnimationPlayback.RestoreState(
            JsonSerializer.Deserialize<AvatarAnimationPlaybackState>(legacyJson, options)!);
        Assert.Equal(0, legacyRestored.PracticePriority);
        Assert.True(legacyRestored.AllowUnblendedOverride);
        Assert.Null(legacyRestored.AnchorBone);
    }

    [Fact]
    public void DiscontinuityTimeProperty_ClearsLastAndBumpsNextPrimaryPriority()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        var oldPrimary = new AvatarAnimationPlayback(new AvatarAnimationClip("old", 4, []), false, false);
        person.AnimationPlayback = oldPrimary;
        context.World.StopCurrentAnimation(person);
        Assert.Same(oldPrimary, person.LastAnimationPlayback);

        var handled = SimulationWorld.ApplyAnimationTimeProperty(person, oldPrimary,
            new AvatarAnimationSoundEvent(0, "", "discontinuity", "", false, false, "ROOT"));
        Assert.True(handled);
        Assert.Null(person.LastAnimationPlayback);
        Assert.True(person.AnimatorDiscontinuityPending);

        var nextPrimary = new AvatarAnimationPlayback(new AvatarAnimationClip("next", 4, []), false, false);
        context.World.BeginPrimaryAnimation(person, nextPrimary);

        Assert.False(person.AnimatorDiscontinuityPending);
        Assert.Null(person.LastAnimationPlayback);
        Assert.Equal(5, nextPrimary.PracticePriority);
    }

    [Fact]
    public void AnchorTimeProperty_AppliesOnlyToPrimaryAndTracksBoneChanges()
    {
        var (_, person, _) = PrimitiveTestWorld.Create();
        var primary = new AvatarAnimationPlayback(new AvatarAnimationClip("primary", 4, []), false, false);
        var background = new AvatarAnimationPlayback(new AvatarAnimationClip("bg", 4, []), false, true);
        person.AnimationPlayback = primary;
        person.BackgroundAnimationPlayback = background;

        Assert.True(SimulationWorld.ApplyAnimationTimeProperty(person, primary,
            new AvatarAnimationSoundEvent(0, "", "anchor", "1", false, false, "R_TOE01")));
        Assert.Equal("R_TOE01", primary.AnchorBone);
        Assert.Equal("R_TOE01", person.AnimatorAnchorBone);
        Assert.False(person.AnimatorAnchorInitialized);

        person.AnimatorAnchorInitialized = true;
        Assert.False(SimulationWorld.ApplyAnimationTimeProperty(person, background,
            new AvatarAnimationSoundEvent(0, "", "anchor", "0", false, false, "R_TOE01")));
        Assert.Equal("R_TOE01", primary.AnchorBone);
        Assert.Equal("R_TOE01", person.AnimatorAnchorBone);
        Assert.True(person.AnimatorAnchorInitialized);

        Assert.True(SimulationWorld.ApplyAnimationTimeProperty(person, primary,
            new AvatarAnimationSoundEvent(0, "", "anchor", "2", false, false, "L_TOE01")));
        Assert.Equal("L_TOE01", primary.AnchorBone);
        Assert.Equal("L_TOE01", person.AnimatorAnchorBone);
        Assert.False(person.AnimatorAnchorInitialized);

        Assert.True(SimulationWorld.ApplyAnimationTimeProperty(person, primary,
            new AvatarAnimationSoundEvent(0, "", "anchor", "0", false, false, "L_TOE01")));
        Assert.Null(primary.AnchorBone);
        Assert.Null(person.AnimatorAnchorBone);
        Assert.False(person.AnimatorAnchorInitialized);
    }

    [Fact]
    public void AvatarAnimations_ExtractAnimationEvents_ParsesEmptyDiscontinuityAndAnchorWithBoneName()
    {
        var animation = new Animation("walk-start", "walk-start", [1000f, 0f], 0, 0, 0, [
            new Motion("R_TOE01", 10, 0f, [0, 0, -1, -1], [], [
                new MotionEvent(100, [new PropertyPair("anchor", "1")]),
                new MotionEvent(400, [new PropertyPair("anchor", "0")]),
            ]),
            new Motion("ROOT", 10, 0f, [0, 0, -1, -1], [], [
                new MotionEvent(200, [new PropertyPair("discontinuity", "")]),
            ]),
        ]);

        var (_, sounds) = AvatarAnimations.ExtractAnimationEvents(animation);

        Assert.Equal(3, sounds.Count);
        Assert.Equal("anchor", sounds[0].Resource);
        Assert.Equal("1", sounds[0].Cue);
        Assert.Equal("R_TOE01", sounds[0].BoneName);
        Assert.Equal("discontinuity", sounds[1].Resource);
        Assert.Equal("", sounds[1].Cue);
        Assert.Equal("ROOT", sounds[1].BoneName);
        Assert.Equal("anchor", sounds[2].Resource);
        Assert.Equal("0", sounds[2].Cue);
        Assert.Equal("R_TOE01", sounds[2].BoneName);
    }

    [Fact]
    public void TickAnchorRootPinning_AdjustsRootWithinBoundsWhenAnchorBoneDrifts()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        var zOffset = 0f;
        context.World.AnchorBoneWorldResolver = (_, bone) =>
            bone == "R_TOE01" ? new Vector3(0f, 0f, zOffset) : null;

        person.AnimationPlayback = new AvatarAnimationPlayback(new AvatarAnimationClip("walk", 8, []), false, true);
        person.AnimatorControlState = 9;
        person.NativeRoute = new RouteState(0, default, new RoutingSlotRequest(), AnimatorFollowState: 1);
        person.AnimatorRootX = 10f;
        person.AnimatorRootY = 10f;
        person.AnimatorRootDirection = 2f;
        person.AnimatorAnchorBone = "R_TOE01";

        context.World.TickAvatarAnimations(person);
        Assert.True(person.AnimatorAnchorInitialized);
        Assert.Equal(10f, person.AnimatorRootX);

        zOffset = -0.5f;
        context.World.TickAvatarAnimations(person);
        Assert.Equal(10f + (16f / 3f) * 0.5f, person.AnimatorRootX!.Value, precision: 4);
    }

    [Fact]
    public void AnimateSim_ExternalStopMidWait_DoesNotRestartAndFiresRemainingSubstituteEvents()
    {
        var (context, person, _) = PrimitiveTestWorld.Create(parameters: [0]);
        person[PersonData.PersonAge] = 18;
        context.World.AvatarAnimationTable[(3, false, 58)] = new AvatarAnimationClip(
            "cook", 10, [new AvatarAnimationEvent(0, 0)], DurationMilliseconds: 333f);
        byte[] operand = [58, 0, 0, 0, 3, 0, 3, 0];

        Assert.Equal(PrimitiveResult.Stop, AnimateSimPrimitive.Execute(context, operand));
        Assert.True(person.PrimaryAnimationWaiting);

        context.World.TickAvatarAnimations(person);
        Assert.Equal(PrimitiveResult.False, AnimateSimPrimitive.Execute(context, operand));
        Assert.Equal((short)0, context.Frame.Parameters[0]);

        person.AnimatorControlState = 2;
        context.World.TickAvatarAnimations(person);
        Assert.Null(person.AnimationPlayback);
        Assert.NotNull(person.LastAnimationPlayback);

        Assert.Equal(PrimitiveResult.False, AnimateSimPrimitive.Execute(context, operand));
        Assert.Equal((short)1, context.Frame.Parameters[0]);
        Assert.Null(person.AnimationPlayback);

        Assert.Equal(PrimitiveResult.False, AnimateSimPrimitive.Execute(context, operand));
        Assert.Equal((short)2, context.Frame.Parameters[0]);

        Assert.Equal(PrimitiveResult.True, AnimateSimPrimitive.Execute(context, operand));
        Assert.False(person.PrimaryAnimationWaiting);
    }

    [Theory]
    [InlineData(false, new short[] { 0, 1, 2 })]
    [InlineData(true, new short[] { 2, 1, 0 })]
    public void AnimateSim_MissingClipAndMissing0x25Fallback_WithExpectedEvents_FiresSubstituteEvents(
        bool backwards, short[] expectedOrder)
    {
        var (context, person, _) = PrimitiveTestWorld.Create(parameters: [0]);
        person[PersonData.PersonAge] = 18;
        byte flags = backwards ? (byte)0x02 : (byte)0x00;
        byte[] operand = [99, 0, 0, 0, 3, flags, 3, 0];

        var fired = new List<short>();
        var result = AnimateSimPrimitive.Execute(context, operand);
        while (result == PrimitiveResult.False)
        {
            fired.Add(context.Frame.Parameters[0]);
            result = AnimateSimPrimitive.Execute(context, operand);
        }

        Assert.Equal(PrimitiveResult.True, result);
        Assert.Equal(expectedOrder, fired);
        Assert.False(person.PrimaryAnimationWaiting);
    }

    [Fact]
    public void PoseSample_IgnoresBoneFloatsWiggleMetadataAndRemainsDeterministic()
    {
        var skeletonZero = new Skeleton("adult", [
            MakeBone("ROOT", "NULL", Vector3.Zero, canBlend: false, floats: [0f, 0f]),
            MakeBone("HEAD", "ROOT", new Vector3(0f, 1f, 0f), canBlend: true, floats: [0f, 0f]),
        ]);
        var wiggleFloat = BitConverter.Int32BitsToSingle(700000);
        var skeletonWiggle = new Skeleton("adult", [
            MakeBone("ROOT", "NULL", Vector3.Zero, canBlend: false, floats: [0f, 0f]),
            MakeBone("HEAD", "ROOT", new Vector3(0f, 1f, 0f), canBlend: true, floats: [wiggleFloat, 0.05f]),
        ]);
        Assert.Equal(700000, skeletonWiggle.Bones[1].WiggleLengthBits);
        Assert.Equal(0.05f, skeletonWiggle.Bones[1].WigglePower);

        var anim = new Animation("idle", "idle", [0f, 0f], 0, 1, 0, [MakeMotion("HEAD", 1, translationBase: 0)]);
        var curves = new AnimationCurves([0.5f, 1.5f, 0.25f], []);

        var poseZero = Pose.Sample(skeletonZero, anim, curves, 0);
        var poseWiggle = Pose.Sample(skeletonWiggle, anim, curves, 0);

        Assert.Equal(poseZero[1].WorldTranslation, poseWiggle[1].WorldTranslation);
        Assert.Equal(poseZero[1].WorldRotation, poseWiggle[1].WorldRotation);
    }

    [Fact]
    public void PoseApplyHeadAdjustment_RotatesHeadBoneOn29BoneAdultAndChildSkeletons()
    {
        var bones = new Bone[29];
        bones[0] = MakeBone("ROOT", "NULL", Vector3.Zero, canBlend: false);
        for (var i = 1; i < 29; i++)
        {
            var name = i == 10 ? "HEAD" : $"BONE_{i}";
            bones[i] = new Bone(name, "ROOT", [], Vector3.Zero, new Quaternion(0f, 0f, 0f, -1f), [0, 0, 1], [0f, 0f]);
        }
        var skeleton = new Skeleton("adult", bones);
        var pose = Pose.Sample(skeleton, new Animation("bind", "", [], 0, 0, 0, []), new AnimationCurves([], []), 0);

        var adjusted = Pose.ApplyHeadAdjustment(skeleton, pose, 1f);
        var expectedAngle = MathF.PI / 8f;
        Assert.Equal(new Quaternion(-MathF.Sin(expectedAngle), 0f, 0f, -MathF.Cos(expectedAngle)), adjusted[10].LocalRotation);
        Assert.Equal(pose[11].LocalRotation, adjusted[11].LocalRotation);
    }

    [Fact]
    public void TickAnchorRootPinning_NonEastHeadingsPinBothAxesAndConvergeAcrossTicks()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        var zOffset = 0f;
        context.World.AnchorBoneWorldResolver = (_, bone) =>
            bone == "R_TOE01" ? new Vector3(1.25f, -0.4f, zOffset) : null;

        person.AnimationPlayback = new AvatarAnimationPlayback(new AvatarAnimationClip("walk", 8, []), false, true);
        person.AnimatorControlState = 9;
        person.NativeRoute = new RouteState(0, default, new RoutingSlotRequest(), AnimatorFollowState: 1);
        const float facingSouth = 4f;
        person.AnimatorRootX = 10f;
        person.AnimatorRootY = 10f;
        person.AnimatorRootDirection = facingSouth;
        person.AnimatorAnchorBone = "R_TOE01";

        context.World.TickAvatarAnimations(person);
        Assert.True(person.AnimatorAnchorInitialized);

        zOffset = -0.5f;
        context.World.TickAvatarAnimations(person);
        var expectedY = 10f + (16f / 3f) * 0.5f;
        Assert.Equal(10f, person.AnimatorRootX!.Value, precision: 4);
        Assert.Equal(expectedY, person.AnimatorRootY!.Value, precision: 4);

        context.World.TickAvatarAnimations(person);
        Assert.Equal(10f, person.AnimatorRootX!.Value, precision: 4);
        Assert.Equal(expectedY, person.AnimatorRootY!.Value, precision: 4);

        var (diagContext, diagPerson, _) = PrimitiveTestWorld.Create();
        var diagZ = 0f;
        diagContext.World.AnchorBoneWorldResolver = (_, bone) =>
            bone == "L_TOE01" ? new Vector3(0f, 0f, diagZ) : null;
        diagPerson.AnimationPlayback = new AvatarAnimationPlayback(new AvatarAnimationClip("walk", 8, []), false, true);
        diagPerson.AnimatorControlState = 9;
        diagPerson.NativeRoute = new RouteState(0, default, new RoutingSlotRequest(), AnimatorFollowState: 1);
        const float facingNorthEast = 1f;
        diagPerson.AnimatorRootX = 20f;
        diagPerson.AnimatorRootY = 20f;
        diagPerson.AnimatorRootDirection = facingNorthEast;
        diagPerson.AnimatorAnchorBone = "L_TOE01";

        diagContext.World.TickAvatarAnimations(diagPerson);
        diagZ = -0.5f;
        diagContext.World.TickAvatarAnimations(diagPerson);
        var step = (16f / 3f) * 0.5f * MathF.Sqrt(0.5f);
        Assert.Equal(20f + step, diagPerson.AnimatorRootX!.Value, precision: 4);
        Assert.Equal(20f - step, diagPerson.AnimatorRootY!.Value, precision: 4);
    }

    [Fact]
    public void WorldBootstrap_WiresAnchorBoneWorldResolverAndResolvesRealBonesGracefully()
    {
        var gameDir = TestGameLocator.Locate();
        if (gameDir is null || !File.Exists(Path.Combine(gameDir, "UserData", "Houses", "House05.iff")))
            return;

        var boot = WorldBootstrap.Load(gameDir, Path.Combine(gameDir, "UserData", "Houses", "House05.iff"));
        Assert.NotNull(boot.World.AnchorBoneWorldResolver);

        var bella = Assert.IsType<XPerson>(boot.World.ObjectById(18));
        var walkClip = RouteExecutor.ResolveWalkAnimation(boot.World, bella, 20);
        Assert.NotNull(walkClip);
        bella.AnimationPlayback = new AvatarAnimationPlayback(walkClip!, false, true);

        var toePos = boot.World.AnchorBoneWorldResolver!(bella, "R_TOE01");
        Assert.NotNull(toePos);
        Assert.True(float.IsFinite(toePos.Value.X) && float.IsFinite(toePos.Value.Y) && float.IsFinite(toePos.Value.Z));

        Assert.Null(boot.World.AnchorBoneWorldResolver!(bella, "NON_EXISTENT_BONE"));
        bella.AnimationPlayback = new AvatarAnimationPlayback(new AvatarAnimationClip("missing-synthetic-clip", 4, []), false, false);
        Assert.Null(boot.World.AnchorBoneWorldResolver!(bella, "R_TOE01"));
    }

    [Fact]
    public void BeginPrimaryAnimation_And_StopCurrentAnimation_ClearStaleAnchorState()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        var clipA = new AvatarAnimationClip("clip-a", 8, []);
        var clipB = new AvatarAnimationClip("clip-b", 8, []);
        person.AnimationPlayback = new AvatarAnimationPlayback(clipA, false, false);
        person.AnimatorAnchorBone = "R_TOE01";
        person.AnimatorAnchorInitialized = true;
        person.AnimatorAnchorWorldPosition = new Vector3(1f, 2f, 3f);

        context.World.BeginPrimaryAnimation(person, new AvatarAnimationPlayback(clipB, false, false));

        Assert.Null(person.AnimatorAnchorBone);
        Assert.False(person.AnimatorAnchorInitialized);
        Assert.Equal(Vector3.Zero, person.AnimatorAnchorWorldPosition);

        person.AnimatorAnchorBone = "L_TOE01";
        person.AnimatorAnchorInitialized = true;
        person.AnimatorAnchorWorldPosition = new Vector3(4f, 5f, 6f);
        context.World.StopCurrentAnimation(person);

        Assert.Null(person.AnimatorAnchorBone);
        Assert.False(person.AnimatorAnchorInitialized);
        Assert.Equal(Vector3.Zero, person.AnimatorAnchorWorldPosition);
    }

    [Fact]
    public void Discontinuity_WithNullLast_DoesNotSetPendingFlagOrSuppressNextLastFade()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        var firedSounds = new List<AvatarAnimationSoundEvent>();
        context.World.AnimationSound = (_, sound) => firedSounds.Add(sound);

        var clipA = new AvatarAnimationClip("clip-a", 8, [],
            [new AvatarAnimationSoundEvent(20, "", "discontinuity", "", false, false, "ROOT")],
            DurationMilliseconds: 336f);
        person.AnimationPlayback = new AvatarAnimationPlayback(clipA, false, false, startedAtMils: 0);
        Assert.Null(person.LastAnimationPlayback);

        context.World.TickAvatarAnimations(person);

        Assert.False(person.AnimatorDiscontinuityPending);
        Assert.Empty(firedSounds);

        var clipB = new AvatarAnimationClip("clip-b", 8, []);
        context.World.BeginPrimaryAnimation(person, new AvatarAnimationPlayback(clipB, false, false));
        Assert.Same(clipA, person.LastAnimationPlayback?.Clip);
        Assert.Equal(0, person.AnimationPlayback?.PracticePriority);
    }

    [Fact]
    public void AnchorAndDiscontinuity_OnBackgroundOrCarry_NeverLeakToAnimationSound()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        var firedSounds = new List<AvatarAnimationSoundEvent>();
        context.World.AnimationSound = (_, sound) => firedSounds.Add(sound);
        person.BackgroundPracticePersonState = 0;
        person.CarryPracticeMode = 6;

        person.BackgroundAnimationPlayback = new AvatarAnimationPlayback(
            new AvatarAnimationClip("bg-anchor", 4, [],
                [
                    new AvatarAnimationSoundEvent(20, "", "anchor", "1", false, false, "L_TOE01"),
                    new AvatarAnimationSoundEvent(30, "", "sound", "real_bg_cue", false, false, "ROOT"),
                ],
                DurationMilliseconds: 168f),
            false, true, startedAtMils: 0);
        person.CarryAnimationPlayback = new AvatarAnimationPlayback(
            new AvatarAnimationClip("carry-anchor", 4, [],
                [
                    new AvatarAnimationSoundEvent(20, "", "anchor", "1", false, false, "R_TOE01"),
                    new AvatarAnimationSoundEvent(30, "", "discontinuity", "", false, false, "ROOT"),
                ],
                DurationMilliseconds: 168f),
            false, true, startedAtMils: 0);

        context.World.TickAvatarAnimations(person);

        Assert.Null(person.AnimatorAnchorBone);
        Assert.False(person.AnimatorDiscontinuityPending);
        var sound = Assert.Single(firedSounds);
        Assert.Equal("real_bg_cue", sound.Cue);
    }

    [Fact]
    public void AnimateSim_Mode3MissingClipWithZeroExpectedEvents_ClearsReachAndRestoresCarry()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        person[PersonData.PersonAge] = 18;
        person[PersonData.Gender] = 0;
        context.World.StandardWalkFallbackAnimationTable[(152, 0x26)] = new AvatarAnimationClip("carry-practice", 8, []);
        person.FootprintSlots.Add(new ObjectFootprintSlot { OccupantObjectId = 42 });

        context.World.TickAvatarAnimations(person);
        Assert.Equal("carry-practice", person.CarryAnimationPlayback?.Clip.Name);

        byte[] operand = [99, 0, 0, 0, 3, 0x11, 0, 0];
        Assert.Equal(PrimitiveResult.True, AnimateSimPrimitive.Execute(context, operand));
        Assert.False(person.ReachAnimationActive);
        Assert.False(person.PrimaryAnimationWaiting);

        context.World.TickAvatarAnimations(person);
        Assert.Equal("carry-practice", person.CarryAnimationPlayback?.Clip.Name);
    }

    [Fact]
    public void AnimateSim_ActiveRouteDrivenAndMissingClipZeroEvents_StopsCurrentAnimation()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        person[PersonData.PersonAge] = 18;
        var walkPlayback = new AvatarAnimationPlayback(new AvatarAnimationClip("walk", 8, []), false, true)
        {
            RouteDriven = true,
        };
        person.AnimationPlayback = walkPlayback;

        byte[] operand = [99, 0, 0, 0, 3, 0, 0, 0];
        Assert.Equal(PrimitiveResult.True, AnimateSimPrimitive.Execute(context, operand));
        Assert.Null(person.AnimationPlayback);
        Assert.Same(walkPlayback, person.LastAnimationPlayback);
    }

    [Fact]
    public void AnimateSim_0x25FallbackWithPlayBackwardsFlag_FiresSubstituteEventsInReverseOrder()
    {
        var (context, person, _) = PrimitiveTestWorld.Create(parameters: [0]);
        person[PersonData.PersonAge] = 18;
        person[PersonData.Gender] = 0;
        context.World.StandardWalkFallbackAnimationTable[(152, 0x25)] = new AvatarAnimationClip("fallback-0x25", 1, []);
        const byte playBackwardsFlag = 0x02;
        const byte expectedEvents = 3;
        byte[] operand = [99, 0, 0, 0, 3, playBackwardsFlag, expectedEvents, 0];

        Assert.Equal(PrimitiveResult.Stop, AnimateSimPrimitive.Execute(context, operand));
        Assert.False(person.AnimationPlayback!.Backwards);
        Assert.True(person.PrimaryAnimationBackwards);

        context.World.TickAvatarAnimations(person);
        Assert.True(person.AnimationPlayback.EndReached);

        var fired = new List<short>();
        var result = AnimateSimPrimitive.Execute(context, operand);
        while (result == PrimitiveResult.False)
        {
            fired.Add(context.Frame.Parameters[0]);
            result = AnimateSimPrimitive.Execute(context, operand);
        }

        Assert.Equal(PrimitiveResult.True, result);
        Assert.Equal(new short[] { 2, 1, 0 }, fired);
    }

    [Fact]
    public void AnimateSim_ReplacesLeftoverNonRouteDrivenPlaybackWhenNotWaiting()
    {
        var (context, person, _) = PrimitiveTestWorld.Create(parameters: [0]);
        person[PersonData.PersonAge] = 18;
        var reachClip = new AvatarAnimationClip("reach-low", 8, []);
        var sitClip = new AvatarAnimationClip("sit-down", 8, []);
        context.World.ReachAvatarAnimationTable[(false, 1)] = reachClip;
        context.World.AvatarAnimationTable[(3, false, 58)] = sitClip;

        var reachOps = new ReachOps(context.World, null);
        Assert.True(reachOps.StartReachAnimation(person, 0.5f));
        Assert.Same(reachClip, person.AnimationPlayback?.Clip);
        Assert.False(person.PrimaryAnimationWaiting);

        byte[] operand = [58, 0, 0, 0, 3, 0, 0, 0];
        Assert.Equal(PrimitiveResult.Stop, AnimateSimPrimitive.Execute(context, operand));
        Assert.Same(sitClip, person.AnimationPlayback?.Clip);
        Assert.Same(reachClip, person.LastAnimationPlayback?.Clip);
        Assert.True(person.PrimaryAnimationWaiting);
    }

    [Fact]
    public void ReachOps_And_RouteExecutorShowWalkSkill_TransitionViaBeginPrimaryAnimation()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        person[PersonData.PersonAge] = 18;
        var initial = new AvatarAnimationPlayback(new AvatarAnimationClip("initial", 8, []), false, false);
        var reachClip = new AvatarAnimationClip("reach-low", 8, []);
        var walkClip = new AvatarAnimationClip("walk-loop", 8, []);
        context.World.ReachAvatarAnimationTable[(false, 1)] = reachClip;

        person.AnimationPlayback = initial;
        var reachOps = new ReachOps(context.World, null);
        Assert.True(reachOps.StartReachAnimation(person, 0.5f));
        Assert.Same(reachClip, person.AnimationPlayback?.Clip);
        Assert.Same(initial, person.LastAnimationPlayback);

        person.NativeRoute = new RouteState(person.Id, person.Position, new RoutingSlotRequest(), MotionAnimationIndex: 20);
        RouteExecutor.ShowWalkSkill(context.World, person, walkClip, 2f, 8);
        Assert.Same(walkClip, person.AnimationPlayback?.Clip);
        Assert.Same(reachClip, person.LastAnimationPlayback?.Clip);
        Assert.Equal(20, person.AnimatorCurrentSkill);
    }

    [Fact]
    public void AnimateSim_NormalCompletionHoldsPoseUntilResetOrNextAnimationAndCrossFades()
    {
        var (context, person, _) = PrimitiveTestWorld.Create(parameters: [0]);
        person[PersonData.PersonAge] = 18;
        person[PersonData.Gender] = 0;
        person[PersonData.Sitting] = 0;
        var idleClip = new AvatarAnimationClip("stand-idle", 8, [], DurationMilliseconds: 336f);
        var clipA = new AvatarAnimationClip("clip-a", 4, [], DurationMilliseconds: 168f);
        var clipB = new AvatarAnimationClip("clip-b", 4, [], DurationMilliseconds: 168f);
        context.World.StandardWalkFallbackAnimationTable[(152, 3)] = idleClip;
        context.World.AvatarAnimationTable[(3, false, 58)] = clipA;
        context.World.AvatarAnimationTable[(3, false, 59)] = clipB;

        context.World.TickAvatarAnimations(person);
        Assert.Same(idleClip, person.BackgroundAnimationPlayback?.Clip);

        byte[] opA = [58, 0, 0, 0, 3, 0, 0, 0];
        Assert.Equal(PrimitiveResult.Stop, AnimateSimPrimitive.Execute(context, opA));
        var playbackA = Assert.IsType<AvatarAnimationPlayback>(person.AnimationPlayback);
        for (var i = 0; i < 4; i++)
            context.World.TickAvatarAnimations(person);
        Assert.True(playbackA.EndReached);

        Assert.Equal(PrimitiveResult.True, AnimateSimPrimitive.Execute(context, opA));
        Assert.False(person.PrimaryAnimationWaiting);
        Assert.Equal(3, person.AnimatorControlState);
        Assert.Same(playbackA, person.AnimationPlayback);
        Assert.Equal(1f, playbackA.PracticeWeight);

        byte[] opB = [59, 0, 0, 0, 3, 0, 0, 0];
        Assert.Equal(PrimitiveResult.Stop, AnimateSimPrimitive.Execute(context, opB));
        var playbackB = Assert.IsType<AvatarAnimationPlayback>(person.AnimationPlayback);
        Assert.Same(clipB, playbackB.Clip);
        Assert.Same(playbackA, person.LastAnimationPlayback);
        Assert.True(playbackA.IsPracticeWeightFadeActive);
        Assert.False(playbackA.AllowUnblendedOverride);
        Assert.Equal(1, playbackA.PracticePriority);

        for (var i = 0; i < 5; i++)
            context.World.TickAvatarAnimations(person);
        Assert.Null(person.LastAnimationPlayback);
        Assert.True(playbackB.EndReached);
        Assert.Equal(PrimitiveResult.True, AnimateSimPrimitive.Execute(context, opB));
        Assert.Same(playbackB, person.AnimationPlayback);

        Assert.Equal(PrimitiveResult.True, AnimateSimPrimitive.Execute(context, new byte[8]));
        Assert.Null(person.AnimationPlayback);
        Assert.Same(playbackB, person.LastAnimationPlayback);
        Assert.True(playbackB.IsPracticeWeightFadeActive);
        Assert.False(playbackB.AllowUnblendedOverride);
        Assert.Equal(1, playbackB.PracticePriority);

        context.World.TickAvatarAnimations(person);
        Assert.InRange(playbackB.PracticeWeight, 0.001f, 0.999f);
        for (var i = 0; i < 4; i++)
            context.World.TickAvatarAnimations(person);
        Assert.Null(person.LastAnimationPlayback);
    }

    [Fact]
    public void BeginPrimaryAnimation_FromBackgroundIdle_CrossFadesBackgroundToLastUnlessDiscontinuityPending()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        var idleClip = new AvatarAnimationClip("idle", 8, [], DurationMilliseconds: 336f);
        var background = new AvatarAnimationPlayback(idleClip, backwards: false, loop: true, startedAtMils: 0)
        {
            PracticeWeight = 1f,
        };
        background.SetFrame(3f);
        background.SetPracticeScale(1f);
        person.BackgroundAnimationPlayback = background;
        Assert.Null(person.AnimationPlayback);

        var primary = new AvatarAnimationPlayback(new AvatarAnimationClip("primary", 8, []), backwards: false, loop: false);
        context.World.BeginPrimaryAnimation(person, primary);

        var fading = Assert.IsType<AvatarAnimationPlayback>(person.LastAnimationPlayback);
        Assert.NotSame(background, fading);
        Assert.Equal("idle", fading.Clip.Name);
        Assert.Equal(3f, fading.Frame);
        Assert.False(fading.AllowUnblendedOverride);
        Assert.Equal(primary.PracticePriority + 1, fading.PracticePriority);
        Assert.True(fading.IsPracticeWeightFadeActive);
        Assert.Equal(1f, fading.PracticeWeight);

        context.World.TickAvatarAnimations(person);
        Assert.InRange(fading.PracticeWeight, 0.001f, 0.999f);
        for (var i = 0; i < 4; i++)
            context.World.TickAvatarAnimations(person);
        Assert.Null(person.LastAnimationPlayback);

        person.AnimationPlayback = null;
        person.BackgroundAnimationPlayback = background;
        person.AnimatorDiscontinuityPending = true;
        var discontinuityPrimary = new AvatarAnimationPlayback(new AvatarAnimationClip("cut", 8, []), backwards: false, loop: false);
        context.World.BeginPrimaryAnimation(person, discontinuityPrimary);

        Assert.False(person.AnimatorDiscontinuityPending);
        Assert.Null(person.LastAnimationPlayback);
        Assert.Equal(5, discontinuityPrimary.PracticePriority);
    }

    [Fact]
    public void TickRouteLocomotionFade_ArrivalFadesWalkToLastWithoutDiscontinuityAndAdvancesDuringFade()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        var walkClip = new AvatarAnimationClip("walk-loop", 10, [], DurationMilliseconds: 420f);
        var walkPlayback = new AvatarAnimationPlayback(walkClip, backwards: false, loop: true, startedAtMils: 0)
        {
            RouteDriven = true,
        };
        walkPlayback.SetFrame(2f);
        person.AnimationPlayback = walkPlayback;
        person.AnimatorControlState = 9;
        person.AnimatorRootX = 100f;
        person.AnimatorRootY = 100f;
        person.AnimatorMilliseconds = 168;
        person.NativeRoute = new RouteState(
            0,
            new ObjectPosition(100, 100, 1),
            new RoutingSlotRequest(),
            AnimatorFollowState: 1,
            MotionTargetX: 100,
            MotionTargetY: 100,
            MotionTargetIsDestination: true,
            MotionX: 100f,
            MotionY: 100f,
            MotionAnimationIndex: 20,
            LocomotionFadeEndMils: 168);

        context.World.TickAvatarAnimations(person);

        Assert.Null(person.AnimationPlayback);
        Assert.False(person.AnimatorDiscontinuityPending);
        Assert.Same(walkPlayback, person.LastAnimationPlayback);
        Assert.False(walkPlayback.RouteDriven);
        Assert.False(walkPlayback.AllowUnblendedOverride);
        Assert.True(walkPlayback.IsPracticeWeightFadeActive);
        Assert.True(walkPlayback.Frame > 2f);
        Assert.Equal(1f, walkPlayback.PracticeWeight);

        var frameAfterArrivalTick = walkPlayback.Frame;
        context.World.TickAvatarAnimations(person);
        Assert.True(walkPlayback.Frame > frameAfterArrivalTick);
        Assert.InRange(walkPlayback.PracticeWeight, 0.001f, 0.999f);

        for (var i = 0; i < 4; i++)
            context.World.TickAvatarAnimations(person);
        Assert.Null(person.LastAnimationPlayback);
    }

    [Fact]
    public void FinishedNonInterruptiblePrimary_DoesNotBlockRouteEntryGateOrDeferredEndFollow()
    {
        var (context, person, _) = PrimitiveTestWorld.Create();
        person[PersonData.PersonAge] = 18;
        var walkClip = new AvatarAnimationClip("walk-20", 8, [],
            StandardRootMotionSamples: Enumerable.Repeat(Vector3.UnitZ, 8).ToArray(),
            DurationMilliseconds: 336f);
        context.World.StandardWalkFallbackAnimationTable[(150, 20)] = walkClip;

        var finishedPrimary = new AvatarAnimationPlayback(new AvatarAnimationClip("finished", 1, [], DurationMilliseconds: 1f),
            backwards: false, loop: false)
        {
            Interruptible = false,
        };
        finishedPrimary.Tick();
        Assert.True(finishedPrimary.EndReached);

        person.AnimationPlayback = finishedPrimary;
        person.AnimatorControlState = 3;
        person.AnimatorGaitEntryState = 1;
        person.AnimatorRootX = 16f;
        person.AnimatorRootY = 16f;
        person.NativeRoute = new RouteState(
            0,
            new ObjectPosition(80, 16, 1),
            new RoutingSlotRequest(),
            AnimatorFollowState: 1,
            MotionTargetX: 32,
            MotionTargetY: 16,
            MotionTargetIsDestination: false,
            MotionX: 16f,
            MotionY: 16f)
        {
            MotionPath =
            [
                new RouteExecutor.RouteWaypoint(1, 1, 16, 16, 16, 16, false),
                new RouteExecutor.RouteWaypoint(2, 1, 32, 16, 32, 16, false),
                new RouteExecutor.RouteWaypoint(5, 1, 80, 16, 80, 16, true),
            ],
            MotionTargetPathIndex = 1,
        };

        context.World.ApplyAnimatorRouteEntryGate(person, routeHeadingClamped: false);

        Assert.Equal(9, person.AnimatorControlState);
        Assert.Same(walkClip, person.AnimationPlayback?.Clip);

        var finishedForEndFollow = new AvatarAnimationPlayback(new AvatarAnimationClip("finished2", 1, [], DurationMilliseconds: 1f),
            backwards: false, loop: false)
        {
            Interruptible = false,
        };
        finishedForEndFollow.Tick();
        Assert.True(finishedForEndFollow.EndReached);

        person.AnimationPlayback = finishedForEndFollow;
        person.NativeRoute = new RouteState(
            0,
            new ObjectPosition(80, 16, 1),
            new RoutingSlotRequest(),
            AnimatorFollowState: 1,
            EndFollowPending: true);

        context.World.TickAvatarAnimations(person);
        Assert.Equal(3, person.NativeRoute!.AnimatorFollowState);

        var activeUninterruptible = new AvatarAnimationPlayback(new AvatarAnimationClip("active", 8, [], DurationMilliseconds: 336f),
            backwards: false, loop: false)
        {
            Interruptible = false,
        };
        Assert.False(activeUninterruptible.EndReached);
        person.AnimationPlayback = activeUninterruptible;
        person.NativeRoute = new RouteState(
            0,
            new ObjectPosition(80, 16, 1),
            new RoutingSlotRequest(),
            AnimatorFollowState: 1,
            EndFollowPending: true);

        context.World.TickAvatarAnimations(person);
        Assert.Equal(1, person.NativeRoute!.AnimatorFollowState);
    }

    [Fact]
    public void ToiletPortableGypsy_StaysInsideRearStallAcrossLoopAndIdleWaitTicks()
    {
        var gameDir = TestGameLocator.Locate();
        if (gameDir is null) return;
        var house05Path = Path.Combine(gameDir, "UserData", "Houses", "House05.iff");
        var house93Path = Path.Combine(gameDir, "UserData", "Houses", "House93.iff");
        if (!File.Exists(house05Path) || !File.Exists(house93Path)) return;

        var house05 = WorldBootstrap.Load(gameDir, house05Path);
        var house93 = WorldBootstrap.Load(gameDir, house93Path, existingRegistry: house05.Registry);
        var world = house93.World;

        const uint rearGuid = 0x7fefc921u;
        const uint frontGuid = 0x7eb399bcu;
        Assert.Equal("a2o-toilet-porta-getin", world.ObjectAvatarAnimationTable[(unchecked((int)rearGuid), 129, 1)].Name, ignoreCase: true);
        Assert.Equal("a2o-toilet-porta-loop", world.ObjectAvatarAnimationTable[(unchecked((int)rearGuid), 129, 2)].Name, ignoreCase: true);
        Assert.Equal("a2o-toilet-porta-getout", world.ObjectAvatarAnimationTable[(unchecked((int)rearGuid), 129, 3)].Name, ignoreCase: true);

        var rear = world.WalkOrder.FirstOrDefault(o => unchecked((uint?)o.TypeRecord?.Key) == rearGuid);
        var front = world.WalkOrder.FirstOrDefault(o => unchecked((uint?)o.TypeRecord?.Key) == frontGuid);
        Assert.NotNull(rear);
        Assert.NotNull(front);

        var bella = Assert.IsType<XPerson>(house05.World.ObjectById(18));
        var sim = world.Add(new XPerson(world.NextObjectId(), (short[])bella.Definition.Clone())
        {
            TypeRecord = bella.TypeRecord,
            SavedCharacter = bella.SavedCharacter,
            Position = new ObjectPosition(front!.Position.X, front.Position.Y, front.Position.Height),
        });
        Array.Copy(bella.PersonData, sim.PersonData, bella.PersonData.Length);

        var facing = AvatarDirection.ToObjectDirection(AvatarDirection.Toward(
            rear!.Position.X - front.Position.X, rear.Position.Y - front.Position.Y));
        sim[ObjectData.Direction] = facing;
        sim.AnimatorRootDirection = facing;
        sim.AnimatorRootX = front.Position.X;
        sim.AnimatorRootY = front.Position.Y;

        world.TickAvatarAnimations(sim);
        Assert.NotNull(sim.BackgroundAnimationPlayback);

        sim.InteractingObjects.Add(rear);
        var frame = new StackFrame(rear.Id, [0], [0, 0]);
        var context = new TreeContext(world, sim, frame) { Stack = TreeRunner.CreateTransientStack(world, sim) };
        var geometry = AvatarSceneGeometry.For(gameDir, house93.Registry);
        var camera = new LotCamera(0, 64, 64);
        var frontOrigin = new Vector2(front.Position.X / 16f, front.Position.Y / 16f);

        void RunAnimateSimToCompletion(short animId, byte flags, Action? perTickAssert = null)
        {
            byte[] operand = [(byte)animId, 0, 1, 0, 0, flags, 0, 0];
            var result = AnimateSimPrimitive.Execute(context, operand);
            for (var tick = 0; tick < 200 && result != PrimitiveResult.True; tick++)
            {
                world.TickAvatarAnimations(sim);
                perTickAssert?.Invoke();
                result = AnimateSimPrimitive.Execute(context, operand);
                while (result == PrimitiveResult.False)
                    result = AnimateSimPrimitive.Execute(context, operand);
            }
            Assert.Equal(PrimitiveResult.True, result);
        }

        RunAnimateSimToCompletion(1, 0x60);

        void AssertInsideRearStall()
        {
            _ = geometry.Build(sim, sim.Position.Height, 0, (_, _) => 0f, camera);
            var pelvis = geometry.PelvisPosition(sim);
            Assert.NotNull(pelvis);
            var distanceFromFront = Vector2.Distance(new Vector2(pelvis!.Value.X, pelvis.Value.Y), frontOrigin);
            Assert.True(distanceFromFront > 0.7f,
                $"Expected Sim pelvis to stay inside Rear stall (>0.7 tiles from Front), observed {distanceFromFront:F3} tiles.");
        }

        RunAnimateSimToCompletion(2, 0x20, AssertInsideRearStall);
        AssertInsideRearStall();

        for (var waitTick = 0; waitTick < 60; waitTick++)
        {
            world.TickAvatarAnimations(sim);
            AssertInsideRearStall();
        }

        RunAnimateSimToCompletion(3, 0x20);
        Assert.Equal(PrimitiveResult.True, AnimateSimPrimitive.Execute(context, new byte[8]));
        for (var i = 0; i < 10; i++)
            world.TickAvatarAnimations(sim);

        _ = geometry.Build(sim, sim.Position.Height, 0, (_, _) => 0f, camera);
        var exitedPelvis = geometry.PelvisPosition(sim);
        Assert.NotNull(exitedPelvis);
        var exitDistance = Vector2.Distance(new Vector2(exitedPelvis!.Value.X, exitedPelvis.Value.Y), frontOrigin);
        Assert.True(exitDistance < 0.25f,
            $"Expected Sim pelvis to return outside near Front tile (<0.25 tiles), observed {exitDistance:F3} tiles.");
    }
}
