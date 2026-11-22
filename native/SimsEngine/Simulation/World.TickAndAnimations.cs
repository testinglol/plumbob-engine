using SimsEngine.Formats;
using SimsEngine.Content;
using SimsEngine.Character;
using System.Numerics;

namespace SimsEngine.Simulation;

public sealed partial class SimulationWorld
{

    public int AdvanceSimulationTick(SimulationClockControl control, short clockState28, int clockTickCounter)
    {
        var callbacks = AdvanceSimulationTick(control, clockState28, clockTickCounter, TickClockObject);
        ContinueDirectPositionRoutes();
        return callbacks;

        bool TickClockObject(XObject item, int tickCounter)
        {
            try
            {
                var outfitTransition = item is XPerson { NativeOutfitTransitionActive: true };
                var completed = outfitTransition || !SavedExecutionStacks.ContainsKey(item.Id) || TreeRunner.RunRestoredObjectStack(this, item);
                if (item is XPerson scalingPerson) UpdateAnimatorBodyScale(scalingPerson, tickCounter);
                if (completed) FinishObjectSimulation(item);
                if (completed && item is XPerson animatingPerson)
                {
                    TickAvatarAnimations(animatingPerson);
                }
                if (completed && item is XPerson person) ApplyPersonPostUpdate(person, tickCounter);
                return completed;
            }
            catch (Exception error) when (error is SimulationException or TreeRunException)
            {
                var failing = SavedExecutionStacks.GetValueOrDefault(item.Id)?.Top;
                var failingTree = failing?.Tree as Bhav;
                var operand = failingTree is not null && failing!.Instruction >= 0 &&
                              failing.Instruction < failingTree.Instructions.Count
                    ? Convert.ToHexString(failingTree.Instructions[failing.Instruction].Operand)
                    : string.Empty;
                var frames = SavedExecutionStacks.GetValueOrDefault(item.Id)?.Frames.Select(frame =>
                {
                    var tree = frame.Tree as Bhav;
                    var instruction = tree is not null && frame.Instruction >= 0 && frame.Instruction < tree.Instructions.Count
                        ? tree.Instructions[frame.Instruction]
                        : null;
                    var behaviorScope = frame.Table as BehaviorScope;
                    var treeLabel = behaviorScope?.FileFor(frame.TreeId)?.Find(ResourceType.Bhav,
                        unchecked((ushort)frame.TreeId))?.Label;
                    var stackObject = ObjectByStackObject(item, frame.StackObject);
                    return new ThreadFrameError(frame.TreeId, frame.Instruction, instruction?.Opcode, frame.StackObject,
                        frame.Parameters.ToArray(), frame.Locals.ToArray(), frame.CodeOwner,
                        treeLabel, behaviorScope?.ObjectKey,
                        behaviorScope is null ? null : BehaviorScope.ScopeOf(frame.TreeId).ToString(),
                        instruction?.TrueTarget, instruction?.FalseTarget,
                        instruction is null ? null : Convert.ToHexString(instruction.Operand),
                        stackObject?.Id, stackObject?.TypeRecord?.Key, stackObject is XPerson);
                }).ToArray() ?? [];
                ThreadErrors.Add(new ThreadError(item.Id,
                    $"{error.Message} (tree {failing?.TreeId}, instruction {failing?.Instruction}, stack {failing?.StackObject}, operand {operand})",
                    (item as XPerson)?.Temporaries.ToArray(), frames));
                var activeStack = SavedExecutionStacks.GetValueOrDefault(item.Id);
                NotifyPersonObjectReferenceRecipients(item);
                SavedExecutionStacks.Remove(item.Id);
                if (item is XPerson erroredPerson)
                {
                    ResetPersonForChangedCode(erroredPerson);
                }
                else if (FunctionTreeId(item, 3) != 0)
                {
                    ResetObjectForChangedCode(item);
                }
                else if ((item.Flags & DyingObjectFlag) != 0)
                {
                    BeginObjectRemoval(item, 1);
                    item.SavedStack.Clear();
                    item.SavedStackSize = 0;
                }
                else ResetObjectAfterScriptError(item, activeStack);
                if (item.ClockManagerIndex > 0)
                    ClockManager.SetWaitTicksAt(item.ClockManagerIndex, -1);
                return false;
            }
            catch (Exception error)
            {
                error.Data["tickingObject"] = item.Id;
                error.Data["executionLocation"] = CurrentExecutionLocation;
                throw;
            }
        }
    }

    public void TickAvatarAnimations(XPerson person)
    {
        person.AnimatorMilliseconds = unchecked(person.AnimatorMilliseconds + 42);
        if (person.LastAnimationPlayback is { } expiredLast &&
            MathF.Abs(expiredLast.PracticeWeight) <= LastPracticePruneWeightThreshold)
            person.LastAnimationPlayback = null;
        if (person.AnimationPlayback is { RouteDriven: true } && person.NativeRoute is null)
            StopCurrentAnimation(person);
        UpdateCarryPractice(person);
        UpdateBackgroundPractice(person);
        UpdateAnimatorWalkingScale(person);
        if (!AnimatorOutOfBounds(person) && !person.NativeOutfitTransitionActive)
        {
            var firstFollowTick = person.NativeRoute is { BeginFollowPendingTick: true };
            if (firstFollowTick)
                person.NativeRoute = person.NativeRoute! with { BeginFollowPendingTick = false };
            var routeHeadingClamped = !firstFollowTick && UpdateAnimatorRootDirection(this, person);
            if (!firstFollowTick)
                RouteExecutor.TryBeginRouteTurnRoot(this, person);
            ApplyAnimatorRouteEntryGate(person, routeHeadingClamped);
            RouteExecutor.TickRouteTurnRootInterpolation(this, person);
            if (person.AnimatorPoolTile && person.AnimatorRouteTransitionState == 0)
                person.AnimatorRouteTransitionState = 1;
            switch (person.AnimatorControlState)
            {
                case 0 when person.AnimatorPracticeScaleEnabled && person.AnimationPlayback is { } primaryPractice:
                    var practiceScale = person.AnimatorWalkingScale;
                    primaryPractice.SetPracticeScale(primaryPractice.PracticeScale < 0f ? -practiceScale : practiceScale);
                    break;
                case 1:
                    if (person.AnimationPlayback is not null && person[PersonData.FreezeForIdleHotDate] == 0)
                    {
                        StopCurrentAnimation(person);
                        person.BackgroundPracticePersonState = -1;
                        UpdateBackgroundPractice(person);
                    }
                    person.AnimatorGaitEntryState = 0;
                    person.AnimatorPoolTransitionState = 0;
                    break;
                case 2:
                    if (person.AnimationPlayback is not null)
                    {
                        StopCurrentAnimation(person);
                        person.BackgroundPracticePersonState = -1;
                        UpdateBackgroundPractice(person);
                    }
                    person.AnimatorGaitEntryState = 0;
                    person.AnimatorPoolTransitionState = 0;
                    break;
                case 4 or 12:
                    person.AnimatorGaitEntryState = 0;
                    person.AnimatorPoolTransitionState = 0;
                    break;
                case 8:
                    person.AnimatorGaitEntryState = 1;
                    person.AnimatorPoolTransitionState = 1;
                    break;
            }
            if (person.AnimatorControlState is 6 or 7 or 11)
            {
                person.AnimatorGaitEntryState = 0;
                person.AnimatorPoolTransitionState = 0;
            }
            if (person.AnimatorControlState != 5 && person.NativeRoute?.MotionAnimationIndex is >= 11 and <= 18)
            {
                person.AnimatorPoolTransitionState = 1;
            }
            TickRouteLocomotionFade(person);
            TickRouteFollowTransition(person);
            TickPoolSwimExit(person);
            TickDeferredEndFollow(person);
            RouteExecutor.TickStandingStartRootInterpolation(this, person);
            RouteExecutor.TickRouteRootMovement(this, person,
                SavedExecutionStacks.GetValueOrDefault(person.Id));
            TickAnchorRootPinning(person);
        }
        if (AvatarAnimationRootOnly) return;
        foreach (var playback in person.GetAnimationPracticeApplicationOrder())
            Tick(playback);
        if (person.LastAnimationPlayback is { } fadedLast &&
            !fadedLast.IsPracticeWeightFadeActive &&
            MathF.Abs(fadedLast.PracticeWeight) <= LastPracticePruneWeightThreshold)
        {
            person.LastAnimationPlayback = null;
        }

        void Tick(AvatarAnimationPlayback playback)
        {
            var isLast = ReferenceEquals(playback, person.LastAnimationPlayback);
            playback.Tick(deliverAnimationEvents: !isLast, person.AnimatorMilliseconds);
            if (isLast)
            {
                playback.EventQueue.Clear();
                playback.SoundEventQueue.Clear();
                return;
            }
            person.PendingAnimationEvents.AddRange(playback.EventQueue);
            playback.EventQueue.Clear();
            foreach (var sound in playback.SoundEventQueue)
            {
                if (ApplyAnimationTimeProperty(person, playback, sound)) continue;
                if (string.IsNullOrEmpty(sound.PackId) &&
                    sound.Resource is "anchor" or "discontinuity")
                    continue;
                AnimationSound?.Invoke(person.Id, sound);
            }
            playback.SoundEventQueue.Clear();
        }
        TickHeadPosture(person);
    }

    private void TickAnchorRootPinning(XPerson person)
    {
        if (AnchorBoneWorldResolver is null || person.AnimationPlayback is null ||
            person.NativeRoute is not { AnimatorFollowState: 1 } ||
            person.AnimatorControlState is not (6 or 8 or 9 or 10))
        {
            person.AnimatorAnchorInitialized = false;
            return;
        }
        if (string.IsNullOrEmpty(person.AnimatorAnchorBone) ||
            person.AnimatorRootX is not { } rx || person.AnimatorRootY is not { } ry ||
            !float.IsFinite(rx) || !float.IsFinite(ry))
        {
            person.AnimatorAnchorInitialized = false;
            return;
        }
        if (AnchorBoneWorldResolver.Invoke(person, person.AnimatorAnchorBone) is not { } boneAvatarPos)
            return;
        // 0058dc76.c:101-103 zeroes avatar-local X/Y and transforms (0, 0, bz) by the avatar world transform
        // (LotFacingAngle rotation + body scale + root translation in VitaBoy units).
        const float scale = 16f / 3f;
        var rootDirection = AvatarDirection.RootDirection(person.AnimatorRootDirection,
            person[ObjectData.Direction], person.AnimatorDisplacementDirection);
        var facingMatrix = Matrix4x4.CreateRotationY(AvatarDirection.LotFacingAngle(rootDirection));
        var bodyScale = float.IsFinite(person.AnimatorBodyScale) && person.AnimatorBodyScale > 0f
            ? person.AnimatorBodyScale
            : 1f;
        var curPos = Vector3.Transform(new Vector3(0f, 0f, boneAvatarPos.Z), facingMatrix) * bodyScale +
                     new Vector3(ry / scale, 0f, rx / scale);
        if (!person.AnimatorAnchorInitialized)
        {
            person.AnimatorAnchorWorldPosition = curPos;
            person.AnimatorAnchorInitialized = true;
            return;
        }
        var delta = person.AnimatorAnchorWorldPosition - curPos;
        var dx = scale * delta.Z;
        var dy = scale * delta.X;
        var distSq = dx * dx + dy * dy;
        if (distSq > 0.01f && distSq <= 10000.0f)
        {
            person.AnimatorRootX = rx + dx;
            person.AnimatorRootY = ry + dy;
        }
    }

    public static bool ApplyAnimationTimeProperty(XPerson person, AvatarAnimationPlayback playback, AvatarAnimationSoundEvent prop)
    {
        if (!string.IsNullOrEmpty(prop.PackId)) return false;
        _ = int.TryParse(prop.Cue, System.Globalization.NumberStyles.Integer, System.Globalization.CultureInfo.InvariantCulture, out var intValue);
        switch (prop.Resource)
        {
            case "interruptable":
            case "interruptible":
                playback.Interruptible = intValue != 0;
                return true;
            case "lefthand":
                person[PersonData.HandGestureLeft] = unchecked((short)intValue);
                return true;
            case "righthand":
                person[PersonData.HandGestureRight] = unchecked((short)intValue);
                return true;
            case "censor":
                person[PersonData.CensorshipFlags] = unchecked((short)intValue);
                return true;
            case "dress":
                person.DressAccessory(prop.Cue);
                return true;
            case "undress":
                person.UndressAccessory(prop.Cue);
                return true;
            case "discontinuity":
                if (person.LastAnimationPlayback is not null)
                {
                    person.LastAnimationPlayback = null;
                    person.AnimatorDiscontinuityPending = true;
                }
                return true;
            case "anchor":
            {
                if (!ReferenceEquals(playback, person.AnimationPlayback))
                    return false;
                var boneName = prop.BoneName ?? "";
                if (intValue == 0)
                {
                    playback.AnchorBone = null;
                    if (string.Equals(person.AnimatorAnchorBone, boneName, StringComparison.Ordinal))
                    {
                        person.AnimatorAnchorBone = null;
                        person.AnimatorAnchorInitialized = false;
                    }
                }
                else
                {
                    playback.AnchorBone = boneName;
                    if (!string.Equals(person.AnimatorAnchorBone, boneName, StringComparison.Ordinal))
                    {
                        person.AnimatorAnchorBone = boneName;
                        person.AnimatorAnchorInitialized = false;
                    }
                }
                return true;
            }
            default:
                return false;
        }
    }

    private void TickHeadPosture(XPerson person)
    {
        if (person[PersonData.HeadSeekTimeout] > 0)
        {
            person[PersonData.HeadSeekTimeout]--;
            if (person[PersonData.HeadSeekTimeout] == 0)
                person[PersonData.HeadSeekState] = 8;
        }

        var seeking = (person[PersonData.HeadSeekState] & 1) != 0;
        person.AnimatorHeadAdjustment = Pose.AdvanceHeadAdjustment(person.AnimatorHeadAdjustment,
            person.AnimatorHeadBaselineDirection, person.AnimatorHeadTargetDirection, seeking, out var hitLimit);
        if (hitLimit)
        {
            switch (person[PersonData.HeadSeekLimitAction])
            {
                case 0: person[PersonData.HeadSeekState] = 5; break;
                case 1: person[PersonData.HeadSeekState] = 4; break;
            }
        }

        if (person.AnimatorHeadSeekRegistrationsAvailable == false ||
            (person.AnimatorHeadSeekRegistrationsAvailable is null && HeadSeekGeometryResolver is null) ||
            (person[PersonData.HeadSeekState] & 1) == 0) return;

        XObject? target = null;
        if (person[PersonData.HeadSeekObject] != 0)
        {
            target = ObjectByStackObject(person, person[PersonData.HeadSeekObject]);
            if (target is null)
            {
                person[PersonData.HeadSeekObject] = 0;
                person[PersonData.HeadSeekState] = 0x10;
            }
            else if (target.Position.Height != person.Position.Height)
            {
                person[PersonData.HeadSeekObject] = 0;
                person[PersonData.HeadSeekState] = 0x10;
            }
        }

        if (HeadSeekGeometryResolver?.Invoke(person, target ?? person) is { } geometry)
        {
            if (target is not null)
                person.AnimatorHeadTargetPoint = geometry.Target;
            person.AnimatorHeadBaselineDirection = Pose.HeadDirection(geometry.Actor, geometry.HeadFake,
                person.AnimatorHeadBaselineDirection);
            person.AnimatorHeadTargetDirection = Pose.HeadDirection(geometry.Actor, person.AnimatorHeadTargetPoint,
                person.AnimatorHeadTargetDirection);
        }
    }

    internal const int StopPracticeFadeDurationMilliseconds = 200;
    private const float LastPracticePruneWeightThreshold = 1e-6f;

    // Matches Sims.exe FUN_00586ed8.
    internal void StopCurrentAnimation(XPerson person)
    {
        if (person.AnimationPlayback is { } current)
        {
            current.EventQueue.Clear();
            current.SoundEventQueue.Clear();
            if (current.PracticeWeight > LastPracticePruneWeightThreshold)
            {
                current.RouteDriven = false;
                current.AllowUnblendedOverride = false;
                current.PracticePriority = current.PracticePriority + 1;
                current.FadePracticeWeight(person.AnimatorMilliseconds,
                    unchecked(person.AnimatorMilliseconds + StopPracticeFadeDurationMilliseconds),
                    current.PracticeWeight, 0f);
                person.LastAnimationPlayback = current;
            }
            else
            {
                person.LastAnimationPlayback = null;
            }
        }
        person.AnimationPlayback = null;
        person.AnimatorAnchorBone = null;
        person.AnimatorAnchorInitialized = false;
        person.AnimatorAnchorWorldPosition = Vector3.Zero;
        person.AnimatorCurrentSkill = -1;
    }

    // Matches Sims.exe FUN_005926e6.
    internal void BeginPrimaryAnimation(XPerson person, AvatarAnimationPlayback next)
    {
        StopCurrentAnimation(person);
        if (person.AnimatorDiscontinuityPending)
        {
            person.AnimatorDiscontinuityPending = false;
            person.LastAnimationPlayback = null;
            next.PracticePriority += 5;
        }
        else if (person.LastAnimationPlayback is null &&
                 person.BackgroundAnimationPlayback is { } background &&
                 background.PracticeWeight > LastPracticePruneWeightThreshold)
        {
            var fadingBackground = new AvatarAnimationPlayback(background.Clip, background.Backwards, background.Loop,
                startedAtMils: person.AnimatorMilliseconds)
            {
                PracticeWeight = background.PracticeWeight,
                PracticePriority = next.PracticePriority + 1,
                AllowUnblendedOverride = false,
            };
            fadingBackground.SetFrame(background.Frame);
            fadingBackground.SetPracticeScale(background.PracticeScale);
            fadingBackground.FadePracticeWeight(person.AnimatorMilliseconds,
                unchecked(person.AnimatorMilliseconds + StopPracticeFadeDurationMilliseconds),
                background.PracticeWeight, 0f);
            person.LastAnimationPlayback = fadingBackground;
        }
        person.PendingAnimationEvents.Clear();
        person.AnimatorCurrentSkill = -1;
        person.AnimationPlayback = next;
    }

    internal void StopReachAnimation(XPerson person)
    {
        StopCurrentAnimation(person);
        person.ReachAnimationActive = false;
        person.PrimaryAnimationWaiting = false;
        person.PrimaryAnimationEventsRun = 0;
        person.PrimaryAnimationBackwards = false;
        person.PendingAnimationEvents.Clear();
        person.AnimatorControlState = person[PersonData.Sitting] switch
        {
            0 => 3,
            1 => 1,
            2 => 2,
            _ => person.AnimatorControlState,
        };
    }

    private static bool UpdateAnimatorRootDirection(SimulationWorld world, XPerson person)
    {
        if (person.AnimatorControlState is not (3 or 9 or 10)) return false;
        if (person.NativeRoute is not { MotionTargetX: not int.MinValue, MotionTargetY: not int.MinValue } route)
            return false;
        if (route.LocomotionFadeEndMils != 0) return false;

        var rootX = person.AnimatorRootX ?? route.MotionX;
        var rootY = person.AnimatorRootY ?? route.MotionY;
        if (!float.IsFinite(rootX) || !float.IsFinite(rootY)) return false;
        var lookahead = RouteExecutor.ResolveRouteLookahead(world, person, route, rootX, rootY);
        if (lookahead.AdvancedCursor)
        {
            route = lookahead.Route;
            person.NativeRoute = route;
        }
        var deltaX = lookahead.TargetX - rootX;
        var deltaY = lookahead.TargetY - rootY;
        var distanceSquared = deltaX * deltaX + deltaY * deltaY;
        if (distanceSquared <= 1e-6f && !route.MotionTargetIsDestination) return false;

        var current = person.AnimatorRootDirection ?? person[ObjectData.Direction];
        var targetDirection = distanceSquared <= 1e-6f && route.MotionTargetIsDestination
            ? RouteExecutor.ArrivalHeading(route) : AvatarDirection.Toward(deltaX, deltaY);
        if (person.AnimatorControlState is 9 or 10 && route.AnimatorFollowState == 1 &&
            person.AnimatorRouteTransitionState == 0 && distanceSquared > 0.25f)
        {
            var headingError = targetDirection - current;
            while (headingError >= 4f) headingError -= 8f;
            while (headingError < -4f) headingError += 8f;
            var largeTurnThreshold = person.AnimatorBodyStringMode > 1 ? 0.57f : 2.0f;
            if (person.AnimatorWalkingScale is < 1f and > 0f)
                largeTurnThreshold /= person.AnimatorWalkingScale;
            if (MathF.Abs(headingError) >= largeTurnThreshold)
            {
                var (turnSkill, _) = RouteExecutor.BodyTurnSkillForHeadingError(headingError);
                if (RouteExecutor.ResolveWalkAnimation(world, person, turnSkill)?.StandardRootMotionSamples is { Count: > 1 })
                {
                    person.AnimatorControlState = 3;
                    person.AnimatorGaitEntryState = 0;
                    return false;
                }
            }
        }

        var step = person.AnimatorBodyStringMode > 1 ? 0.056f : 0.2f;
        if (person.AnimatorWalkingScale < 1f && person.AnimatorWalkingScale > 0f)
            step /= person.AnimatorWalkingScale;
        person.AnimatorRootDirection = AvatarDirection.Approach(current, targetDirection, step,
            out var clamped);
        person[ObjectData.Direction] = AvatarDirection.ToObjectDirection(person.AnimatorRootDirection.Value);
        return clamped;
    }

    internal void ApplyAnimatorRouteEntryGate(XPerson person, bool routeHeadingClamped)
    {
        if (person.AnimatorControlState is not (3 or 9) || person.NativeRoute is not
            { MotionTargetX: not int.MinValue, MotionTargetY: not int.MinValue } route) return;

        var walkStyle = person[ObjectData.WalkStyle];
        var running = walkStyle == 1;
        var currentSkill = person.AnimatorCurrentSkill;
        var rootX = person.AnimatorRootX ?? route.MotionX;
        var rootY = person.AnimatorRootY ?? route.MotionY;
        if (route.TransitionTargetX is not null || route.AnimatorFollowState is -1 or 2 ||
            RouteExecutor.IsRoutePreferenceArrival(person, route, rootX, rootY)) return;
        var remainingDistance = float.IsFinite(rootX) && float.IsFinite(rootY)
            ? MathF.Sqrt(MathF.Pow(route.MotionTargetX - rootX, 2) + MathF.Pow(route.MotionTargetY - rootY, 2))
            : 0f;
        var finalSegment = route.MotionPath is not { Count: > 1 } || route.MotionTargetIsDestination;
        if (finalSegment)
        {
            if (person.AnimatorRouteTransitionState == 0 && remainingDistance >= (running ? 4.5f : 3f))
                person.AnimatorControlState = running ? 10 : 9;
        }
        else if (person.AnimationPlayback is not { Interruptible: false, EndReached: false })
        {
            person.AnimatorControlState = running ? 10 : 9;
        }

        var entersGait = person.AnimatorLocomotionFadeGate != 0 || person.AnimatorGaitEntryState != 0 ||
                         currentSkill is 20 or 21;
        if (!entersGait && !person.AnimatorPoolTile)
        {
            var thresholdSkill = RouteExecutor.ResolveWalkAnimation(this, person, running ? 22 : 19);
            var threshold = (thresholdSkill?.StandardDistance ?? 0f) * (16f / 3f);
            var lookahead = RouteExecutor.ResolveRouteLookahead(this, person, route, rootX, rootY);
            var offsetSquared = MathF.Pow(lookahead.TargetX - rootX, 2) + MathF.Pow(lookahead.TargetY - rootY, 2);
            entersGait = routeHeadingClamped || offsetSquared <= threshold * threshold;
        }

        person.AnimatorProjectedRootStepX = 0f;
        person.AnimatorProjectedRootStepY = 0f;
        if (!entersGait)
        {
            var startSkill = running ? (short)22 : (short)19;
            person.AnimatorControlState = running ? 11 : 6;
            if (route.MotionAnimationIndex < 0 &&
                RouteExecutor.ResolveWalkAnimation(this, person, startSkill) is { StandardRootMotionSamples.Count: > 1 } startClip)
            {
                person.AnimatorGaitEntryState = 0;
                person.AnimatorPoolTransitionState = 0;
                var originX = float.IsFinite(rootX) ? rootX : person.Position.X;
                var originY = float.IsFinite(rootY) ? rootY : person.Position.Y;
                if (startClip.StandardDistance > 0f)
                {
                    var angle = ((person.AnimatorRootDirection ?? person[ObjectData.Direction]) + 6f) * (MathF.PI / 4f);
                    var startDistance = startClip.StandardDistance * (16f / 3f);
                    route = route with
                    {
                        MotionAnimationIndex = startSkill,
                        MotionFrame = 0f,
                        MotionPracticeFrame = 0f,
                        StartRootOriginX = originX,
                        StartRootOriginY = originY,
                        StartRootTargetX = originX + MathF.Cos(angle) * startDistance,
                        StartRootTargetY = originY + MathF.Sin(angle) * startDistance,
                    };
                }
                else
                {
                    route = route with { MotionAnimationIndex = startSkill, MotionFrame = 0f, MotionPracticeFrame = 0f };
                }
                person.NativeRoute = route;
                RouteExecutor.ShowWalkSkill(this, person, startClip, 0f, startClip.StandardRootMotionSamples.Count);
            }
            return;
        }

        person.AnimatorGaitEntryState = 1;
        if (person.AnimatorControlState == 10 && !running)
            person.AnimatorControlState = 9;
        var gaitSkill = person.AnimatorControlState switch
        {
            9 => 20,
            10 => 21,
            _ => 0,
        };
        if (gaitSkill == 0 || currentSkill == gaitSkill) return;

        var clip = RouteExecutor.ResolveWalkAnimation(this, person, gaitSkill);
        if (clip?.StandardRootMotionSamples is not { Count: > 1 } samples) return;
        route = route with { MotionAnimationIndex = (short)gaitSkill, MotionFrame = 0f, MotionPracticeFrame = 0f };
        person.NativeRoute = route;
        RouteExecutor.ShowWalkSkill(this, person, clip, 0f, samples.Count);
    }

    private bool AnimatorOutOfBounds(XPerson person)
    {
        if (!LotRoomMaps.TryGetValue(person.Position.Height, out var map)) return false;
        var tileX = person.Position.X >> 4;
        var tileY = person.Position.Y >> 4;
        return tileX < 1 || tileY < 1 || tileX >= map.Width - 1 || tileY >= map.Height - 1;
    }

    private void TickRouteLocomotionFade(XPerson person)
    {
        if (person.NativeRoute is not { } route || route.MotionTargetX == int.MinValue ||
            route.MotionTargetY == int.MinValue || person.AnimationPlayback is not { RouteDriven: true } playback)
        {
            person.AnimatorLocomotionFadeGate = 0;
            return;
        }

        if (route.MotionPath is { Count: > 1 } && !route.MotionTargetIsDestination) return;
        if (person.AnimatorControlState is not (3 or 9 or 10)) return;
        if (person[ObjectData.RoutePreference] != 0) return;

        if (route.LocomotionFadeEndMils > 0)
        {
            var expiryRootX = person.AnimatorRootX ?? route.MotionX;
            var expiryRootY = person.AnimatorRootY ?? route.MotionY;
            var distanceToTarget = float.IsFinite(expiryRootX) && float.IsFinite(expiryRootY)
                ? MathF.Sqrt(MathF.Pow(route.MotionTargetX - expiryRootX, 2) + MathF.Pow(route.MotionTargetY - expiryRootY, 2))
                : float.PositiveInfinity;
            if (person[ObjectData.WalkStyle] != 1 && distanceToTarget < 2f &&
                person.AnimatorMilliseconds < route.LocomotionFadeEndMils) return;

            route = route with { LocomotionFadeEndMils = -1 };
            person.NativeRoute = route;
            person.AnimatorLocomotionFadeGate = 0;
            person.AnimatorPoolTransitionState = 0;
        }

        if (route.LocomotionFadeEndMils < 0)
        {
            person.AnimatorRootX = route.MotionTargetX;
            person.AnimatorRootY = route.MotionTargetY;
            if (route.LookTowardsFollow)
                person.AnimatorRootDirection = route.ArrivalFacing;
            person.AnimatorControlState = 3;
            StopCurrentAnimation(person);
            person.NativeRoute = route with
            {
                AnimatorFollowState = -1,
                MotionAnimationIndex = -1,
                LocomotionFadeEndMils = 0,
                MotionX = route.MotionTargetX,
                MotionY = route.MotionTargetY,
            };
            person.AnimatorLocomotionFadeGate = 0;
            person.AnimatorPoolTransitionState = 0;
            return;
        }

        var clip = playback.Clip;
        if (LocomotionStrideResolver is null || clip.FrameCount <= 0 || clip.DurationMilliseconds <= 0f ||
            person.AnimatorWalkingScale <= 0f)
            return;

        var rootX = person.AnimatorRootX ?? route.MotionX;
        var rootY = person.AnimatorRootY ?? route.MotionY;
        if (!float.IsFinite(rootX) || !float.IsFinite(rootY)) return;
        var distance = MathF.Sqrt(MathF.Pow(route.MotionTargetX - rootX, 2) + MathF.Pow(route.MotionTargetY - rootY, 2));

        (float TargetWeight, int DurationMilliseconds)? fade = null;
        var markerClip = RouteExecutor.ResolveWalkAnimation(this, person, 0x14);
        if (markerClip is not null &&
            markerClip.LocomotionMarkerOne is { } markerOne && markerOne.Bone.Length > 0 &&
            markerClip.LocomotionMarkerTwo is { } markerTwo && markerTwo.Bone.Length > 0 &&
            LocomotionStrideResolver.Invoke(person, markerClip.Name) is { } strides)
        {
            var phase = playback.Frame / clip.FrameCount;
            var stride = Pose.LocomotionStrideAtPhase(phase, markerOne.NormalizedTime, markerTwo.NormalizedTime,
                strides.MarkerOneStride, strides.MarkerTwoStride);
            if (!person.AnimatorPoolTile && person[ObjectData.WalkStyle] == 1)
                stride *= person.AnimatorWalkingScale;

            fade = Pose.LocomotionFade(distance, stride, phase, markerOne.NormalizedTime, markerTwo.NormalizedTime,
                clip.DurationMilliseconds, person.AnimatorWalkingScale);
            if (fade is null && stride <= 0f && route.MotionTargetIsDestination && distance <= 1e-3f)
                fade = (0.2f, 100);
        }
        else if (route.MotionTargetIsDestination && distance <= 1e-3f)
        {
            fade = (0.2f, 100);
        }

        if (fade is not { } schedule) return;

        person.AnimatorRouteTransitionState = 1;
        person.AnimatorPoolTransitionState = 1;
        var endMils = unchecked(person.AnimatorMilliseconds + schedule.DurationMilliseconds);
        playback.FadePracticeWeight(person.AnimatorMilliseconds, endMils, playback.PracticeWeight, schedule.TargetWeight);
        person.NativeRoute = route with { LocomotionFadeEndMils = endMils };
        person.AnimatorLocomotionFadeGate = 1;
    }

    private static void TickRouteFollowTransition(XPerson person)
    {
        if (person.NativeRoute is { AnimatorFollowState: -1, TransitionTargetX: { } transitionX,
                TransitionTargetY: { } transitionY } arrivalRoute)
        {
            var arrivalRootX = person.AnimatorRootX ?? arrivalRoute.MotionX;
            var arrivalRootY = person.AnimatorRootY ?? arrivalRoute.MotionY;
            if (MathF.Abs(arrivalRootX - transitionX) > 0.000001f || MathF.Abs(arrivalRootY - transitionY) > 0.000001f)
                return;
            person.NativeRoute = arrivalRoute with
            {
                AnimatorFollowState = 2,
                TransitionTargetX = null,
                TransitionTargetY = null,
            };
            return;
        }
        if (person.NativeRoute is not { AnimatorFollowState: -1, MotionAnimationIndex: -1 } route) return;
        var rootX = person.AnimatorRootX ?? route.MotionX;
        var rootY = person.AnimatorRootY ?? route.MotionY;
        if (!float.IsFinite(rootX) || !float.IsFinite(rootY) ||
            MathF.Abs(rootX - route.MotionX) > 0.000001f || MathF.Abs(rootY - route.MotionY) > 0.000001f)
            return;

        if ((route.LookTowardsHeading is not null || !route.LookTowardsFollow) && route.MotionTargetIsDestination)
        {
            var headingError = RouteExecutor.ArrivalHeading(route) -
                               (person.AnimatorRootDirection ?? person[ObjectData.Direction]);
            while (headingError >= 4f) headingError -= 8f;
            while (headingError < -4f) headingError += 8f;
            if (MathF.Abs(headingError) > 0.000001f) return;
        }
        person.NativeRoute = route with { AnimatorFollowState = 2 };
    }

    private void TickDeferredEndFollow(XPerson person)
    {
        if (person.NativeRoute is not { EndFollowPending: true, AnimatorFollowState: 1 } route ||
            person.AnimationPlayback is { Interruptible: false, EndReached: false }) return;

        var poolSwimExitStarted = false;
        float? poolSwimExitRootX = null;
        float? poolSwimExitRootY = null;
        float? poolSwimExitDirection = null;
        if (person.AnimatorPoolTile)
        {
            person.AnimatorRouteTransitionState = 3;
            if (person.AnimatorPoolTransitionState == 0)
            {
                person.AnimatorControlState = 3;
            }
            else
            {
                poolSwimExitStarted = true;
                poolSwimExitRootX = person.AnimatorRootX ?? route.MotionX;
                poolSwimExitRootY = person.AnimatorRootY ?? route.MotionY;
                poolSwimExitDirection = person.AnimatorRootDirection ?? person[ObjectData.Direction];
                StartPoolSwimExitPractice(person);
            }
        }

        person.NativeRoute = route with
        {
            AnimatorFollowState = poolSwimExitStarted ? 1 : 3,
            EndFollowPending = !poolSwimExitStarted,
            PoolSwimExitPending = poolSwimExitStarted,
            PoolSwimExitRootX = poolSwimExitRootX,
            PoolSwimExitRootY = poolSwimExitRootY,
            PoolSwimExitDirection = poolSwimExitDirection,
        };
    }

    internal void StartPoolSwimExitPractice(XPerson person)
    {
        person.AnimatorControlState = 7;
        var swimExit = RouteExecutor.ResolveWalkAnimation(this, person, 0x13);
        if (swimExit is not null)
        {
            BeginPrimaryAnimation(person, new AvatarAnimationPlayback(swimExit, backwards: true, loop: false,
                startedAtMils: person.AnimatorMilliseconds)
            {
                Interruptible = true,
                PoolSwimExit = true,
            });
        }
        person.AnimatorCurrentSkill = 0x13;
    }

    private void TickPoolSwimExit(XPerson person)
    {
        if (person.NativeRoute is not { PoolSwimExitPending: true } route) return;
        if (person.AnimatorControlState == 7 &&
            person.AnimationPlayback is null or { EndReached: true })
        {
            var rootX = route.PoolSwimExitRootX ?? person.AnimatorRootX ?? route.MotionX;
            var rootY = route.PoolSwimExitRootY ?? person.AnimatorRootY ?? route.MotionY;
            var direction = route.PoolSwimExitDirection ?? person.AnimatorRootDirection ?? person[ObjectData.Direction];
            person.AnimatorRootX = rootX;
            person.AnimatorRootY = rootY;
            person.AnimatorRootDirection = direction;
            person[ObjectData.Direction] = SimsEngine.Character.AvatarDirection.ToObjectDirection(direction);
            person.AnimatorStateTailField198 = 1;
            StopCurrentAnimation(person);
            person.AnimatorControlState = 3;
            person.NativeRoute = route with
            {
                MotionX = rootX,
                MotionY = rootY,
                AnimatorFollowState = person.AnimatorRouteTransitionState switch
                {
                    1 => -1,
                    2 => 2,
                    _ => 3,
                },
                PoolSwimExitPending = false,
            };
            return;
        }
        if (person.AnimatorRouteTransitionState != 3) return;
        if (person.AnimationPlayback is { PoolSwimExit: true, EndReached: true })
        {
            StopCurrentAnimation(person);
            person.AnimatorControlState = 3;
            person.NativeRoute = route with
            {
                AnimatorFollowState = 3,
                PoolSwimExitPending = false,
            };
            return;
        }
        if (person.AnimatorControlState != 7) return;

        person.AnimatorControlState = 3;
        person.NativeRoute = route with
        {
            AnimatorFollowState = 3,
            PoolSwimExitPending = person.AnimationPlayback is { PoolSwimExit: true },
        };
    }

    private static void UpdateAnimatorWalkingScale(XPerson person)
    {
        var scaleSelector = 1f;
        if (person[ObjectData.WalkStyle] == 1)
        {
            if (person.AnimatorControlState == 0)
                scaleSelector = 8f;
            else if (person.AnimatorControlState is >= 4 and <= 9)
                scaleSelector = person.AnimatorBodyStringMode <= 1 ? 8f : 0f;
        }
        var target = 1.2f + scaleSelector * (scaleSelector < 0.5f ? 0.2f : 0.4f);
        const float step = 0.2f;
        var current = person.AnimatorWalkingScale;
        if (current >= target - step && current <= target + step)
            current = target;
        else if (target > current)
            current += step;
        else
            current = target;
        person.AnimatorWalkingScale = current;
        if (person.NativeRoute is { } route)
            person.NativeRoute = route with { MotionPlaybackScale = current };
    }

    internal void UpdateCarryPractice(XPerson person)
    {
        if (person.CarryPracticeMode == 6) return;

        var desiredState = -1;
        if (!person.ReachAnimationActive)
        {
            person.CarryPracticeMode = person.FootprintSlots.Count > 0 &&
                person.FootprintSlots[0].OccupantObjectId != 0 ? 1 : 0;
            if (person.CarryPracticeMode is > 0 and < 6)
                desiredState = 0;
        }

        if (desiredState == person.CarryPracticeCachedState) return;

        person.CarryAnimationPlayback = null;
        if (desiredState == 0)
        {
            var clip = RouteExecutor.ResolveWalkAnimation(this, person, 0x26);
            if (clip is not null) person.CarryAnimationPlayback = new AvatarAnimationPlayback(clip, backwards: false,
                loop: true, startedAtMils: person.AnimatorMilliseconds);
        }
        person.CarryPracticeCachedState = desiredState;
    }

    internal void UpdateBackgroundPractice(XPerson person)
    {
        var state = person[PersonData.Sitting];
        var changed = state != person.BackgroundPracticePersonState;
        if (changed)
        {
            person.BackgroundAnimationPlayback = null;
        }
        else if (person.BackgroundAnimationPlayback is not null && !UpdateBackgroundPracticeForPersonState(person))
        {
            return;
        }

        if ((unchecked((ushort)person.Definition[(int)ObjdField.VitaBoyFlags]) & 0x0004) != 0) return;

        person.BackgroundPracticePersonState = state;

        var standardIndex = state switch { 0 => 3, 1 => 1, 2 => 2, _ => -1 };
        if (standardIndex < 0) return;
        var clip = RouteExecutor.ResolveWalkAnimation(this, person, standardIndex);
        if (clip is null) return;
        person.BackgroundAnimationPlayback = new AvatarAnimationPlayback(clip, backwards: false, loop: true,
            startedAtMils: person.AnimatorMilliseconds);

        static bool UpdateBackgroundPracticeForPersonState(XPerson sim)
        {
            // Human animator body string modes (0 and 1) preserve active practice, while pet modes (2
            // through 5) trigger a refresh.
            var bodyStringMode = sim.AnimatorBodyStringMode;
            var value = bodyStringMode ^ 1;
            var difference = unchecked((value >> 1) - (value & bodyStringMode));
            return (unchecked((uint)difference) & 0x4000_0000u) != 0;
        }
    }

    public bool StartDirectPositionRoute(XPerson person, ObjectPosition destination)
    {
        ArgumentNullException.ThrowIfNull(person);
        if (!ReferenceEquals(person, ObjectById(person.Id)))
            throw new ArgumentException("The Sim is not in this world.", nameof(person));
        if (_directPositionRoutes.TryGetValue(person.Id, out var previous) &&
            RouteExecutor.CancelDirectPosition(this, person, previous.Frame))
            _directPositionRoutes.Remove(person.Id);
        if (_directPositionRoutes.ContainsKey(person.Id) || person.NativeRoute is not null)
            throw new InvalidOperationException("The Sim is already routing.");

        var frame = new StackFrame(person.Id, [], []);
        var stack = SavedExecutionStacks.GetValueOrDefault(person.Id);
        var result = RouteExecutor.StartDirectPosition(this, person, frame, destination, stack);
        if (result == PrimitiveResult.False) return false;
        if (frame.Waiting) _directPositionRoutes.Add(person.Id, (frame, stack));
        return true;
    }

    private void ContinueDirectPositionRoutes()
    {
        foreach (var (personId, route) in _directPositionRoutes.ToArray())
        {
            if (Objects.GetValueOrDefault(personId) is XPerson { NativeOutfitTransitionActive: true }) continue;
            if (ObjectById(personId) is not XPerson person || !ReferenceEquals(person.NativeRoute?.OwnerFrame, route.Frame))
            {
                _directPositionRoutes.Remove(personId);
                continue;
            }

            RouteExecutor.Continue(this, person, route.Frame, SavedExecutionStacks.GetValueOrDefault(personId));
            if (!route.Frame.Waiting) _directPositionRoutes.Remove(personId);
        }
    }

    public bool EnqueueInteractionAction(XPerson person, XObject owner, Interaction interaction, byte interactionId,
        int priority, XObject? secondary, bool secondarySpecified, int recordFlags)
    {
        var action = new ActionQueueSlot
        {
            Threshold = priority,
            Person = person,
            Owner = owner,
            Secondary = secondarySpecified ? secondary : owner,
            InteractionId = interactionId,
            ActionTree = interaction.ActionTree,
            Attenuation = InteractionAttenuation(person, interaction),
            Flags = (interaction.Flags & 0x100) != 0 ? 1 : 0,
        };
        action.Flags |= recordFlags;
        return EnqueueInteractionAction(person, action, (recordFlags & 2) != 0);
    }

    public InteractionTable? EffectiveInteractions(XObject? obj)
    {
        if (obj is null) return null;
        if (obj.TypeRecord?.Interactions is { } direct) return direct;
        if (obj.Definition is { Length: > (int)SimsEngine.Formats.ObjdField.MasterId } def &&
            def[(int)SimsEngine.Formats.ObjdField.MasterId] != 0)
        {
            var resolved = InteractionMenus.Target(this, obj);
            if (resolved.TypeRecord?.Interactions is { } targetTable) return targetTable;
            foreach (var member in MultiTileMembers(obj))
            {
                if (member.TypeRecord?.Interactions is { } memberTable) return memberTable;
            }
        }
        return null;
    }

    public bool IsImmediateMenuInteraction(ActionQueueSlot choice) =>
        EffectiveInteractions(choice.Owner)?.Interactions
            .FirstOrDefault(entry => entry.TtaIndex == choice.RawDword10) is { } interaction &&
        (interaction.Flags & 4) != 0;

    public bool RunImmediateMenuInteraction(XPerson person, ActionQueueSlot choice)
    {
        if (ImmediateInteractionRunning || choice.Owner?.TypeRecord?.BehaviorScope is not { } scope) return false;
        var previousPriority = person.ActivePriority;
        var previousImmediate = ActiveImmediateAction;
        var previousImmediatePerson = ActiveImmediatePerson;
        ImmediateInteractionRunning = true;
        ActiveImmediateAction = choice;
        ActiveImmediatePerson = person;
        person.ActivePriority = unchecked((short)choice.Threshold);
        try
        {
            TreeRunner.RunWithParameters(this, person, scope, unchecked((short)choice.ActionTree),
                choice.Owner.StackObjectKey, choice.Parameters);
            return true;
        }
        finally
        {
            person.ActivePriority = previousPriority;
            ImmediateInteractionRunning = false;
            ActiveImmediateAction = previousImmediate;
            ActiveImmediatePerson = previousImmediatePerson;
        }
    }

    public bool EnqueueInteractionAction(XPerson person, ActionQueueSlot candidate, bool headContinuation = false)
    {
        var action = candidate.Copy();
        action.Sequence = unchecked(++_actionQueueSequence);
        if (headContinuation)
        {
            if ((action.Flags & 0x40) != 0)
            {
                var sourceRecord = ActiveImmediateAction is not null && ReferenceEquals(ActiveImmediatePerson, person)
                    ? ActiveImmediateAction
                    : person.CurrentActionRecord;
                InheritActionRecordText(action, sourceRecord);
            }
            return EnqueueHeadContinuation(person, action);
        }

        var priority = action.Threshold;
        var count = person.ActionQueueEnd - person.ActionQueueCurrent;
        if (count is < 0 or > 8) return false;

        var insertion = count;
        while (insertion > 0)
        {
            var previous = person.ActionQueue[(person.ActionQueueCurrent + insertion - 1) & 7];
            if (previous.Threshold >= priority) break;
            insertion--;
        }

        if (insertion != count)
        {
            var retained = new ActionQueueSlot[insertion];
            for (var index = 0; index < insertion; index++)
                retained[index] = person.ActionQueue[(person.ActionQueueCurrent + index) & 7];
            for (var index = insertion; index < count; index++)
                if (person.ActionQueue[(person.ActionQueueCurrent + index) & 7].Owner is not null)
                    ActionQueueRemovalNotices.Add(new ActionQueueRemovalNotice(person.RequestKey, index));

            person.ActionQueueCurrent = 0;
            person.ActionQueueEnd = 0;
            foreach (var queued in retained)
                person.ActionQueue[person.ActionQueueEnd++] = queued;
        }
        else if (count == 8)
        {
            return false;
        }

        if ((action.Flags & 0x40) != 0 && ActiveImmediateAction is not null && ReferenceEquals(ActiveImmediatePerson, person))
        {
            InheritActionRecordText(action, ActiveImmediateAction);
        }

        person.ActionQueue[person.ActionQueueEnd & 7] = action;
        person.ActionQueueEnd = unchecked(person.ActionQueueEnd + 1);
        return true;
    }

    private void InheritActionRecordText(ActionQueueSlot destination, ActionQueueSlot? source)
    {
        if (source is null) return;
        var text = source.ActionText;
        if (string.IsNullOrEmpty(text))
            text = EffectiveInteractions(source.Owner)?.Interactions
                .FirstOrDefault(entry => entry.TtaIndex == source.RawDword10)?.Name;
        source.Flags &= ~0x80;
        if (!string.IsNullOrEmpty(text))
        {
            destination.ActionText = text;
            destination.Flags |= 0x80;
        }
    }

    public void StartFoundAction(XPerson person, XObject target, int key, int priority)
    {
        ArgumentNullException.ThrowIfNull(person);
        ArgumentNullException.ThrowIfNull(target);
        var interaction = EffectiveInteractions(target)?.Interactions.FirstOrDefault(entry => entry.TtaIndex == key);
        var action = new ActionQueueSlot
        {
            RecordKind = 0,
            Person = person,
            Owner = target,
            Secondary = target,
            RawDword10 = key,
            Threshold = priority,
            ActionTree = interaction?.ActionTree ?? 0,
            Attenuation = interaction is null ? 0 : InteractionAttenuation(person, interaction),
            Flags = interaction is not null && (interaction.Flags & 0x100) != 0 ? 1 : 0,
        };
        action.Sequence = unchecked(++_actionQueueSequence);
        ApplyStartedInteractionAction(person, action);
    }

    private static bool EnqueueHeadContinuation(XPerson person, ActionQueueSlot action)
    {
        var count = unchecked(person.ActionQueueEnd - person.ActionQueueCurrent);
        if (count is < 0 or > 8) return false;
        var retainedCount = Math.Min(count, 7);
        var retained = new ActionQueueSlot[retainedCount];
        for (var index = 0; index < retainedCount; index++)
            retained[index] = person.ActionQueue[(person.ActionQueueCurrent + index) & 7].Copy();

        for (var index = 0; index < person.ActionQueue.Length; index++)
            person.ActionQueue[index] = ActionQueueSlot.EmptyRecord();
        person.ActionQueueCurrent = 0;
        person.ActionQueueEnd = 0;
        person.ActionQueue[person.ActionQueueEnd++] = action;
        foreach (var queued in retained)
            person.ActionQueue[person.ActionQueueEnd++] = queued;
        return true;
    }

    public bool RemoveQueuedActionsReferencing(XPerson person, XObject subject)
    {
        var count = unchecked(person.ActionQueueEnd - person.ActionQueueCurrent);
        if (count is < 0 or > 8) return false;

        var survivors = new List<ActionQueueSlot>(count);
        var removedAny = false;
        for (var index = 0; index < count; index++)
        {
            var action = person.ActionQueue[(person.ActionQueueCurrent + index) & 7];
            if (ReferenceEquals(action.Owner, subject) || ReferenceEquals(action.Secondary, subject))
            {
                removedAny = true;
                if (action.Owner is not null)
                    ActionQueueRemovalNotices.Add(new ActionQueueRemovalNotice(person.RequestKey, index));
            }
            else
            {
                survivors.Add(action.Copy());
            }
        }

        if (!removedAny) return false;
        for (var index = 0; index < person.ActionQueue.Length; index++)
            person.ActionQueue[index] = new ActionQueueSlot();
        for (var index = 0; index < survivors.Count; index++)
            person.ActionQueue[index] = survivors[index];
        person.ActionQueueCurrent = 0;
        person.ActionQueueEnd = survivors.Count;
        return true;
    }
}
