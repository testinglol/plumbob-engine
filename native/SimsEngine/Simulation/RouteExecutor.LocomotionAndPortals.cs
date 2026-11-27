using SimsEngine.Formats;
using System.Buffers;

namespace SimsEngine.Simulation;

internal static partial class RouteExecutor
{

    internal static bool TryBeginRouteTurnRoot(SimulationWorld world, XPerson person)
    {
        if (person.AnimatorControlState != 3 || person.NativeRoute is not
            { MotionTargetX: not int.MinValue, MotionTargetY: not int.MinValue } route ||
            !float.IsFinite(person.AnimatorWalkingScale) || person.AnimatorWalkingScale <= 0f)
            return false;

        var rootX = person.AnimatorRootX ?? route.MotionX;
        var rootY = person.AnimatorRootY ?? route.MotionY;
        if (!float.IsFinite(rootX) || !float.IsFinite(rootY)) return false;
        if (route.TransitionTargetX is { } transitionX && route.TransitionTargetY is { } transitionY)
        {
            person.AnimatorRootX = transitionX;
            person.AnimatorRootY = transitionY;
            person.NativeRoute = route with { MotionX = transitionX, MotionY = transitionY };
            return false;
        }
        var stepTargetX = (float)route.MotionTargetX;
        var stepTargetY = (float)route.MotionTargetY;
        if (route.AnimatorFollowState == 1)
        {
            var lookahead = ResolveRouteLookahead(world, person, route, rootX, rootY);
            if (lookahead.AdvancedCursor)
            {
                route = lookahead.Route;
                person.NativeRoute = route;
            }
            stepTargetX = lookahead.TargetX;
            stepTargetY = lookahead.TargetY;
        }
        var dx = route.MotionTargetX - rootX;
        var dy = route.MotionTargetY - rootY;
        var distance = MathF.Sqrt(dx * dx + dy * dy);
        var aimDx = stepTargetX - rootX;
        var aimDy = stepTargetY - rootY;
        var aimDistance = MathF.Sqrt(aimDx * aimDx + aimDy * aimDy);
        var specialBody = person.AnimatorBodyStringMode > 1;
        var maximumDistance = specialBody ? 3.1f / 12f : 3.1f;
        var snapDistance = specialBody ? 0.5f / 5f : 0.5f;

        var currentDirection = person.AnimatorRootDirection ?? person[ObjectData.Direction];
        var targetDirection = aimDistance <= 0.000001f && route.MotionTargetIsDestination
            ? (HasExplicitArrivalHeading(route) ? ArrivalHeading(route) : QuantizeRootDirection(currentDirection))
            : SimsEngine.Character.AvatarDirection.Toward(aimDx, aimDy);
        var headingError = targetDirection - currentDirection;
        while (headingError >= 4f) headingError -= 8f;
        while (headingError < -4f) headingError += 8f;
        if (distance <= 0.000001f && MathF.Abs(headingError) <= 0.000001f) return false;
        var angleThreshold = (specialBody ? 0.0625f : 0.25f) / person.AnimatorWalkingScale;
        if (MathF.Abs(headingError) >= angleThreshold ||
            (route.LookTowardsHeading is null && route.AnimatorFollowState != 1 && distance >= maximumDistance))
            return TryBeginRouteBodyTurn(world, person, route, rootX, rootY, targetDirection, currentDirection,
                headingError);
        if (distance >= maximumDistance)
            return false;

        if (route.AnimatorFollowState == -1 && route.MotionTargetIsDestination && distance < snapDistance)
        {
            person.AnimatorRootX = route.MotionTargetX;
            person.AnimatorRootY = route.MotionTargetY;
            person.AnimatorRootDirection = targetDirection;
            person[ObjectData.Direction] = SimsEngine.Character.AvatarDirection.ToObjectDirection(targetDirection);
            person.NativeRoute = route with { MotionX = route.MotionTargetX, MotionY = route.MotionTargetY };
            return false;
        }

        var facingAngle = SimsEngine.Character.AvatarDirection.LotFacingAngle(targetDirection);
        var cosFacing = MathF.Cos(facingAngle);
        var sinFacing = MathF.Sin(facingAngle);
        var localDx = -dx * sinFacing + dy * cosFacing;
        var localDz = dx * cosFacing + dy * sinFacing;
        var skill = StandingTurnAnimationForVector(localDx, localDz);
        var clip = ResolveWalkAnimation(world, person, skill);
        if (clip?.StandardRootMotionSamples is not { Count: > 1 }) return false;

        if (distance < snapDistance)
        {
            rootX = route.MotionTargetX;
            rootY = route.MotionTargetY;
            person.AnimatorRootX = rootX;
            person.AnimatorRootY = rootY;
        }

        var practiceDirection = currentDirection + headingError;
        var (stepLocalX, stepLocalZ) = StandingAdjustLocalStepFtiles(clip, person.AnimatorBodyScale);
        var offsetLength = MathF.Sqrt(stepLocalX * stepLocalX + stepLocalZ * stepLocalZ);
        var practiceWeight = distance < 0.1f
            ? 0.5f
            : offsetLength <= 0.0001f || distance >= offsetLength
                ? 1f
                : Math.Clamp(distance / offsetLength, 0.5f, 1f);
        var adjustedTarget = TurnRootTarget(route.MotionTargetX, route.MotionTargetY, facingAngle,
            stepLocalX * practiceWeight, stepLocalZ * practiceWeight);
        var playbackScale = person.AnimatorWalkingScale;
        route = route with
        {
            MotionAnimationIndex = skill,
            MotionDirection = QuantizeRootDirection(targetDirection),
            MotionFrame = 0f,
            MotionPracticeFrame = 0f,
            MotionPlaybackScale = playbackScale,
            MotionX = rootX,
            MotionY = rootY,
            TurnRootOriginX = rootX,
            TurnRootOriginY = rootY,
            TurnRootTargetX = adjustedTarget.X,
            TurnRootTargetY = adjustedTarget.Y,
            TurnRootSavedDirection = targetDirection,
            TurnRootPracticeScale = playbackScale,
            TurnRootStartDirection = currentDirection,
            TurnRootPracticeDirection = practiceDirection,
        };
        person.NativeRoute = route;
        world.StopCurrentAnimation(person);
        person.AnimatorControlState = 5;
        ShowWalkSkill(world, person, clip, 0f, clip.StandardRootMotionSamples.Count);
        if (person.AnimationPlayback is { } adjustPlayback)
            adjustPlayback.PracticeWeight = practiceWeight;
        return true;
    }

    private static bool TryBeginRouteBodyTurn(SimulationWorld world, XPerson person, RouteState route,
        float rootX, float rootY, float targetDirection, float currentDirection, float headingError)
    {
        var (skill, correction) = BodyTurnSkillForHeadingError(headingError);

        var clip = ResolveWalkAnimation(world, person, skill);
        if (clip?.StandardRootMotionSamples is not { Count: > 1 } samples) return false;
        var practiceDirection = currentDirection + headingError - correction;
        var turnInPlace = route.LookTowardsHeading is not null ||
                          (route.AnimatorFollowState == 1 && route.MotionPath is { Count: > 1 });
        var turnTargetX = turnInPlace ? rootX : (float)route.MotionTargetX;
        var turnTargetY = turnInPlace ? rootY : (float)route.MotionTargetY;
        route = route with
        {
            MotionAnimationIndex = skill,
            MotionDirection = QuantizeRootDirection(targetDirection),
            MotionFrame = 0f,
            MotionPracticeFrame = 0f,
            MotionPlaybackScale = person.AnimatorWalkingScale,
            MotionX = rootX,
            MotionY = rootY,
            TurnRootOriginX = rootX,
            TurnRootOriginY = rootY,
            TurnRootTargetX = turnTargetX,
            TurnRootTargetY = turnTargetY,
            TurnRootSavedDirection = targetDirection,
            TurnRootPracticeScale = person.AnimatorWalkingScale,
            TurnRootStartDirection = currentDirection,
            TurnRootPracticeDirection = practiceDirection,
        };
        person.NativeRoute = route;
        world.StopCurrentAnimation(person);
        person.AnimatorControlState = 4;
        ShowWalkSkill(world, person, clip, 0f, samples.Count);
        return true;
    }

    internal static (short Skill, float Correction) BodyTurnSkillForHeadingError(float headingError)
    {
        if (headingError < -3f) return (5, -4f);
        if (headingError > 3f) return (4, 4f);
        if (headingError >= -0.5f && headingError <= 0.5f) return (10, 0f);
        if (headingError > 0.5f && headingError <= 1.5f) return (8, 1f);
        if (headingError > 1.5f && headingError <= 3f) return (6, 2f);
        if (headingError < -0.5f && headingError >= -1.5f) return (9, -1f);
        if (headingError < -1.5f && headingError >= -3f) return (7, -2f);
        return (10, 0f);
    }

    internal static short StandingTurnAnimationForVector(float deltaX, float deltaY)
    {
        var sector = (int)MathF.Floor(MathF.Atan2(deltaY, deltaX) * (4f / MathF.PI) + 0.5f);
        sector = (sector % 8 + 8) % 8;
        return sector switch
        {
            0 => 15,
            1 => 13,
            2 => 11,
            3 => 12,
            4 => 14,
            5 => 16,
            6 => 18,
            _ => 17,
        };
    }

    internal static void TickRouteTurnRootInterpolation(SimulationWorld world, XPerson person)
    {
        var controlState = person.AnimatorControlState;
        if (controlState is not (4 or 5) || person.NativeRoute is not { } route ||
            (controlState == 5 && (route.MotionAnimationIndex is < 11 or > 18)) ||
            route.TurnRootOriginX is not { } originX || route.TurnRootOriginY is not { } originY ||
            route.TurnRootTargetX is not { } targetX || route.TurnRootTargetY is not { } targetY)
            return;
        person.AnimatorGaitEntryState = 0;
        if (!person.AnimatorPoolTile)
            person.AnimatorPoolTransitionState = 0;
        var turnClip = ResolveWalkAnimation(world, person, route.MotionAnimationIndex);
        var sampleCount = turnClip?.StandardRootMotionSamples?.Count ?? 0;
        if (sampleCount <= 0) return;
        var arrivalTurn = route.AnimatorFollowState == -1;
        if (arrivalTurn && !world.AvatarAnimationRootOnly && turnClip!.DurationMilliseconds > 0f)
        {
            var elapsedMils = person.AnimationPlayback?.LastPracticeApplyMils is { } lastApplyMils
                ? unchecked(person.AnimatorMilliseconds - lastApplyMils)
                : AnimatorTickMilliseconds;
            var turnScale = route.TurnRootPracticeScale ?? person.AnimatorWalkingScale;
            var advanced = Math.Min(sampleCount,
                route.MotionPracticeFrame + sampleCount * elapsedMils * turnScale / turnClip.DurationMilliseconds);
            route = route with { MotionFrame = advanced, MotionPracticeFrame = advanced };
            person.NativeRoute = route;
            ShowWalkSkill(world, person, turnClip, advanced, sampleCount);
        }
        var phase = route.MotionPracticeFrame / sampleCount;
        if (phase >= 1f)
        {
            var settledX = controlState == 5 && route.MotionTargetX != int.MinValue
                ? (float)route.MotionTargetX
                : targetX;
            var settledY = controlState == 5 && route.MotionTargetY != int.MinValue
                ? (float)route.MotionTargetY
                : targetY;
            person.AnimatorRootX = settledX;
            person.AnimatorRootY = settledY;
            if (controlState == 5 && person.AnimationPlayback is { } completedAdjust)
                completedAdjust.PracticeWeight = 0f;
            world.StopCurrentAnimation(person);
            if (controlState == 4)
            {
                person.LastAnimationPlayback = null;
                person.AnimatorDiscontinuityPending = route.AnimatorFollowState == 1;
            }
            person.AnimatorControlState = 3;
            if (route.TurnRootSavedDirection is { } savedDirection)
            {
                person.AnimatorRootDirection = savedDirection;
                person[ObjectData.Direction] = QuantizeRootDirection(savedDirection);
            }
            var arrivedAtDestination = route.AnimatorFollowState == 1 && !route.EndFollowPending &&
                                       route.MotionTargetIsDestination && route.TransitionTargetX is null &&
                                       !person.AnimatorPoolTile &&
                                       MathF.Abs(settledX - route.MotionTargetX) <= 0.0001f &&
                                       MathF.Abs(settledY - route.MotionTargetY) <= 0.0001f;
            if (arrivedAtDestination && route.LookTowardsFollow)
            {
                person.AnimatorRootDirection = route.ArrivalFacing;
                person[ObjectData.Direction] = QuantizeRootDirection(route.ArrivalFacing);
            }
            person.NativeRoute = route with
            {
                AnimatorFollowState = arrivedAtDestination ? -1 : route.AnimatorFollowState,
                LocomotionFadeEndMils = arrivedAtDestination ? 0 : route.LocomotionFadeEndMils,
                MotionX = settledX,
                MotionY = settledY,
                MotionAnimationIndex = -1,
                MotionFrame = 0f,
                MotionPracticeFrame = 0f,
                TurnRootOriginX = null,
                TurnRootOriginY = null,
                TurnRootTargetX = null,
                TurnRootTargetY = null,
                TurnRootSavedDirection = null,
                TurnRootPracticeScale = null,
                TurnRootStartDirection = null,
                TurnRootPracticeDirection = null,
            };
            if (arrivedAtDestination)
            {
                person.AnimatorLocomotionFadeGate = 0;
                person.AnimatorPoolTransitionState = 0;
            }
            else if (route.AnimatorFollowState == 1)
            {
                world.ApplyAnimatorRouteEntryGate(person, routeHeadingClamped: false);
            }
            return;
        }
        var rootX = originX + (targetX - originX) * phase;
        var rootY = originY + (targetY - originY) * phase;
        person.AnimatorRootX = rootX;
        person.AnimatorRootY = rootY;
        if (controlState is 4 or 5 && route.TurnRootStartDirection is { } startDirection &&
            route.TurnRootPracticeDirection is { } practiceDirection)
        {
            var heading = startDirection + (practiceDirection - startDirection) * phase;
            person.AnimatorRootDirection = heading;
            person[ObjectData.Direction] = QuantizeRootDirection(heading);
        }
        person.NativeRoute = route with { MotionX = rootX, MotionY = rootY };
    }

    internal readonly record struct RouteLookahead(RouteState Route, int ActiveSegmentIndex, float TargetX,
        float TargetY, bool ReachedSegmentEnd, bool AdvancedCursor);

    internal static RouteLookahead ResolveRouteLookahead(SimulationWorld world, XPerson person, RouteState route,
        float rootX, float rootY)
    {
        if (route.LookTowardsHeading is not null || route.AnimatorFollowState == -1)
            return new RouteLookahead(route, -1, route.MotionTargetX, route.MotionTargetY, false, false);

        var motionPath = route.MotionPath;
        var activeTargetIndex = route.MotionTargetPathIndex;
        if (motionPath is { Count: > 1 } && (activeTargetIndex < 1 || activeTargetIndex >= motionPath.Count))
        {
            for (var index = 1; index < motionPath.Count; index++)
            {
                if (motionPath[index].X != route.MotionTargetX || motionPath[index].Y != route.MotionTargetY) continue;
                activeTargetIndex = index;
                break;
            }
        }
        var activeSegmentIndex = motionPath is { Count: > 1 } && activeTargetIndex >= 1 &&
                                 activeTargetIndex < motionPath.Count
            ? activeTargetIndex - 1
            : -1;

        var targetX = (float)route.MotionTargetX;
        var targetY = (float)route.MotionTargetY;
        var progressReachedSegmentEnd = false;
        var advancedProgressCursor = false;
        if (motionPath is { } progressPath && activeSegmentIndex >= 0)
        {
            var strideSkill = ResolveWalkAnimation(world, person, person[ObjectData.WalkStyle] == 1 ? 21 : 20);
            var halfStride = (strideSkill?.StandardDistance ?? 0f) * (8f / 3f);
            var progressTarget = FindRouteProgressTarget(progressPath[activeSegmentIndex], progressPath[activeTargetIndex],
                rootX, rootY, halfStride);
            while (progressTarget.ReachedSegmentEnd && activeTargetIndex + 1 < progressPath.Count)
            {
                activeTargetIndex++;
                activeSegmentIndex++;
                advancedProgressCursor = true;
                var nextTarget = progressPath[activeTargetIndex];
                route = route with
                {
                    MotionTargetPathIndex = activeTargetIndex,
                    MotionTargetTileX = nextTarget.TileX,
                    MotionTargetTileY = nextTarget.TileY,
                    MotionTargetX = nextTarget.X,
                    MotionTargetY = nextTarget.Y,
                    MotionTargetIsDestination = nextTarget.IsDestination,
                };
                progressTarget = FindRouteProgressTarget(progressPath[activeSegmentIndex],
                    progressPath[activeTargetIndex], rootX, rootY, halfStride);
            }
            targetX = progressTarget.X;
            targetY = progressTarget.Y;
            progressReachedSegmentEnd = progressTarget.ReachedSegmentEnd;
        }

        return new RouteLookahead(route, activeSegmentIndex, targetX, targetY, progressReachedSegmentEnd,
            advancedProgressCursor);
    }

    internal static void TickRouteRootMovement(SimulationWorld world, XPerson person, TreeStack? stack)
    {
        if (person.AnimatorControlState is not (3 or 9 or 10)) return;
        if (person.NativeRoute is not { MotionTargetX: not int.MinValue, MotionTargetY: not int.MinValue } route)
            return;
        if (route.TransitionTargetX is not null || route.AnimatorFollowState is -1 or 2) return;
        var rootX = person.AnimatorRootX ?? route.MotionX;
        var rootY = person.AnimatorRootY ?? route.MotionY;
        if (!float.IsFinite(rootX) || !float.IsFinite(rootY)) return;
        var clip = ResolveWalkAnimation(world, person, route.MotionAnimationIndex);
        if (clip is null || clip.DurationMilliseconds <= 0f || person.AnimatorWalkingScale <= 0f) return;

        var motionPath = route.MotionPath;
        var lookahead = ResolveRouteLookahead(world, person, route, rootX, rootY);
        route = lookahead.Route;
        var activeSegmentIndex = lookahead.ActiveSegmentIndex;
        var activeTargetIndex = activeSegmentIndex + 1;
        var targetX = lookahead.TargetX;
        var targetY = lookahead.TargetY;
        var progressReachedSegmentEnd = lookahead.ReachedSegmentEnd;
        var advancedProgressCursor = lookahead.AdvancedCursor;

        var step = RouteStepDistance(clip.StandardDistance, clip.DurationMilliseconds,
            person.AnimatorWalkingScale, AnimatorTickMilliseconds);
        float stepX, stepY;
        var arrival = false;
        if (person.AnimatorPoolTile && IsRoutePreferenceArrival(person, route, rootX, rootY))
        {
            person.AnimatorRouteTransitionState = 1;
            if (person.AnimatorPoolTransitionState == 0)
            {
                person.AnimatorControlState = 3;
                person.NativeRoute = route with
                {
                    AnimatorFollowState = -1,
                    TransitionTargetX = rootX,
                    TransitionTargetY = rootY,
                    MotionX = rootX,
                    MotionY = rootY,
                };
                return;
            }
            world.StartPoolSwimExitPractice(person);
            person.NativeRoute = route with
            {
                PoolSwimExitPending = true,
                PoolSwimExitRootX = route.MotionTargetX,
                PoolSwimExitRootY = route.MotionTargetY,
                PoolSwimExitDirection = ArrivalHeading(route),
                TransitionTargetX = route.MotionTargetX,
                TransitionTargetY = route.MotionTargetY,
            };
            return;
        }
        if (IsRoutePreferenceArrival(person, route, rootX, rootY))
        {
            person.AnimatorRouteTransitionState = 1;
            person.AnimatorLocomotionFadeGate = 1;
            person.AnimatorControlState = 3;
            route = route with
            {
                AnimatorFollowState = -1,
                TransitionTargetX = rootX,
                TransitionTargetY = rootY,
                MotionX = rootX,
                MotionY = rootY,
            };
            if (person.AnimationPlayback is null)
            {
                person.NativeRoute = route;
                return;
            }
            person.AnimatorPoolTransitionState = 1;
            var storedX = person.AnimatorProjectedRootStepX;
            var storedY = person.AnimatorProjectedRootStepY;
            var storedLength = MathF.Sqrt(storedX * storedX + storedY * storedY);
            stepX = storedLength > 1e-6f ? storedX * step / storedLength : 0f;
            stepY = storedLength > 1e-6f ? storedY * step / storedLength : 0f;
            arrival = true;
        }
        else
        {
            var deltaX = targetX - rootX;
            var deltaY = targetY - rootY;
            if (MathF.Abs(deltaX * deltaX + deltaY * deltaY) <= 1e-6f)
            {
                person.NativeRoute = route;
                return;
            }
            var distance = MathF.Sqrt(deltaX * deltaX + deltaY * deltaY);
            var finalDestinationSegment = route.MotionTargetIsDestination &&
                                          (motionPath is null || activeTargetIndex >= motionPath.Count - 1);
            var effectiveStep = finalDestinationSegment ? MathF.Min(step, distance) : step;
            stepX = distance > 0f ? deltaX * effectiveStep / distance : 0f;
            stepY = distance > 0f ? deltaY * effectiveStep / distance : 0f;
        }
        person.AnimatorProjectedRootStepX = stepX;
        person.AnimatorProjectedRootStepY = stepY;
        var nextRootX = rootX + stepX;
        var nextRootY = rootY + stepY;
        var tileX = TickRootIntegerCoordinate(nextRootX);
        var tileY = TickRootIntegerCoordinate(nextRootY);
        var nearest = motionPath is { } path && activeSegmentIndex >= 0
            ? FindNearestRouteSegment(path, tileX, tileY, activeSegmentIndex, activeSegmentIndex)
            : null;
        var nextPosition = nearest is { } point
            ? new ObjectPosition(point.X, point.Y, person.Position.Height)
            : new ObjectPosition(tileX, tileY, person.Position.Height);
        var canPlacePosition = nextPosition with { Height = nextPosition.Height == 0 ? 1 : nextPosition.Height };
        var anchor = route.AnchorObjectId != 0 ? world.ObjectById(route.AnchorObjectId) : null;
        var isSnapTile = route.Slot.SnapTargetSlot >= 0 && anchor is not null &&
            (canPlacePosition.X >> 4 == route.Destination.X >> 4 && canPlacePosition.Y >> 4 == route.Destination.Y >> 4);
        var stepAccepted = isSnapTile
            ? CanPlaceArrival(world, person, anchor, route.Slot, canPlacePosition, stack)
            : world.CanPlaceObject(person, canPlacePosition, stack);
        if (!stepAccepted)
        {
            person.NativeRoute = route with
            {
                AnimatorFollowState = 3,
                FollowPlacementRejected = true,
                MotionX = rootX,
                MotionY = rootY,
            };
            return;
        }

        world.PlaceObject(person, nextPosition, stack);
        world.RefreshPersonRoomStateAfterMovement(person);
        person.AnimatorRootX = nextRootX;
        person.AnimatorRootY = nextRootY;
        var nextRoute = route with { MotionX = nextRootX, MotionY = nextRootY };
        if (arrival)
        {
            person.NativeRoute = nextRoute;
            return;
        }
        if (!advancedProgressCursor && motionPath is { } routePath && nearest is { SegmentIndex: >= 0 } &&
            activeTargetIndex >= 1 && activeTargetIndex < routePath.Count)
        {
            var start = routePath[activeTargetIndex - 1];
            var end = routePath[activeTargetIndex];
            var segmentX = end.X - start.X;
            var segmentY = end.Y - start.Y;
            var pastEndpoint = (nextRootX - end.X) * (double)segmentX +
                               (nextRootY - end.Y) * (double)segmentY >= 0d;
            var nextTargetIndex = activeTargetIndex + 1;
            if (pastEndpoint && nextTargetIndex < routePath.Count)
            {
                var target = routePath[nextTargetIndex];
                nextRoute = nextRoute with
                {
                    MotionTargetPathIndex = nextTargetIndex,
                    MotionTargetTileX = target.TileX,
                    MotionTargetTileY = target.TileY,
                    MotionTargetX = target.X,
                    MotionTargetY = target.Y,
                    MotionTargetIsDestination = target.IsDestination,
                };
            }
        }
        person.NativeRoute = nextRoute;
    }

    internal static bool IsRoutePreferenceArrival(XPerson person, RouteState route, float rootX, float rootY)
    {
        if (person[ObjectData.RoutePreference] == 0) return false;
        if (route.MotionPath is { Count: > 1 } && !route.MotionTargetIsDestination) return false;
        if (person.AnimatorRouteTransitionState != 0) return true;
        var remaining = MathF.Sqrt(MathF.Pow(route.MotionTargetX - rootX, 2) + MathF.Pow(route.MotionTargetY - rootY, 2));
        return remaining < (person[ObjectData.WalkStyle] == 1 ? 4.5f : 3f);
    }

    private static (float X, float Y, bool ReachedSegmentEnd) FindRouteProgressTarget(RouteWaypoint start, RouteWaypoint end,
        float rootX, float rootY, float halfStride)
    {
        var segmentX = (double)end.X - start.X;
        var segmentY = (double)end.Y - start.Y;
        var lengthSquared = segmentX * segmentX + segmentY * segmentY;
        if (lengthSquared <= 0d) return (end.X, end.Y, true);

        var length = Math.Sqrt(lengthSquared);
        var progress = ((rootX - start.X) * segmentX + (rootY - start.Y) * segmentY) / lengthSquared;
        progress = Math.Clamp(progress, 0d, 1d);
        var sampleStep = 1d / length;
        var thresholdSquared = Math.Max(0f, halfStride) * Math.Max(0f, halfStride);
        var candidateX = (float)end.X;
        var candidateY = (float)end.Y;
        for (var sampleProgress = progress; ; sampleProgress = Math.Min(1d, sampleProgress + sampleStep))
        {
            candidateX = FTileIntegerCoordinate((float)(start.X + segmentX * sampleProgress));
            candidateY = FTileIntegerCoordinate((float)(start.Y + segmentY * sampleProgress));
            var offsetX = candidateX - rootX;
            var offsetY = candidateY - rootY;
            if (offsetX * offsetX + offsetY * offsetY >= thresholdSquared || sampleProgress >= 1d)
                return (candidateX, candidateY, sampleProgress >= 1d);
        }
    }

    internal static short DirectionToWaypoint((int X, int Y) from, (int X, int Y) to)
    {
        var deltaY = to.Y - from.Y;
        var deltaX = to.X - from.X;
        var absY = Math.Abs(deltaY);
        var absX = Math.Abs(deltaX);
        int direction;
        if (absX * 2 < absY)
        {
            direction = 4;
        }
        else
        {
            direction = absX <= absY * 2 ? 3 : 2;
        }
        if (deltaX < 0)
        {
            if (direction == 2) direction = 6;
            else if (direction == 3) direction = 5;
        }
        if (deltaY < 0)
        {
            if (direction == 3) direction = 1;
            else if (direction == 4) direction = 0;
            else if (direction == 5) direction = 7;
        }
        return (short)(direction & 7);
    }

    private static short QuantizeRootDirection(float direction) =>
        SimsEngine.Character.AvatarDirection.ToObjectDirection(direction);

    private static void InitializeRoutePortalCosts(SimulationWorld world, XPerson person, RouteState route)
    {
        if (route.OpenedPortalId != 0 || route.UsedPortalIds is { Length: > 0 }) return;
        world.InitializePortalRouteCosts(person);
    }

    private static void ClearRoute(XPerson person)
    {
        var completedRoute = person.NativeRoute;
        if (person.NativeRouteParents.Count == 0)
        {
            if (completedRoute is { LookTowardsFollow: false } && person[PersonData.MultipleRoutes] == 0)
                person[PersonData.RoutingComplete] = 1;
            person[ObjectData.RoutePreference] = 0;
            person.NativeRoute = null;
            return;
        }
        var last = person.NativeRouteParents.Count - 1;
        person.NativeRoute = person.NativeRouteParents[last];
        person.NativeRouteParents.RemoveAt(last);
    }

    private static PrimitiveResult EndFollowAndClearRoute(SimulationWorld world, XPerson person, RouteState route,
        StackFrame frame, TreeStack? stack = null, short failureReason = 1)
    {
        if (!route.LookTowardsFollow)
            person[PersonData.RouteResult] = failureReason;
        route = route with { EndFollowPending = true, EndFollowOnArrival = false, FailureReason = failureReason };
        person.NativeRoute = route;
        if (route.AnimatorFollowState is 1 or -1)
        {
            frame.Waiting = true;
            return PrimitiveResult.Stop;
        }

        CompleteEndFollow(world, person, route);
        if (route.LookTowardsFollow)
        {
            ClearRoute(person);
            frame.Waiting = false;
            return PrimitiveResult.True;
        }
        return FinishRouteFailure(world, person, route, frame, stack, failureReason);
    }

    private static PrimitiveResult FailRouteBeforeStart(SimulationWorld world, XPerson person, XObject anchor, RoutingSlotRequest slot,
        StackFrame frame, TreeStack? stack, short failureReason)
    {
        person[PersonData.RouteResult] = failureReason;
        if ((slot.Flags & 0x4000) != 0 && stack is not null &&
            TryPushRouteFailureFeedback(world, person, anchor, frame, stack, failureReason, out var callerDepth))
        {
            if (person.NativeRoute is { } parent && !ReferenceEquals(parent.OwnerFrame, frame))
                person.NativeRouteParents.Add(parent);
            person.NativeRoute = new RouteState(anchor.Id, anchor.Position, slot,
                OwnerFrame: frame, AnimatorFollowState: 0,
                PendingFailureFeedbackDepth: callerDepth, FailureReason: failureReason)
            { AwaitingBeginFollow = true };
            frame.Waiting = true;
            return PrimitiveResult.Again;
        }
        return PrimitiveResult.False;
    }

    private static PrimitiveResult FinishRouteFailure(SimulationWorld world, XPerson person, RouteState route,
        StackFrame frame, TreeStack? stack, short failureReason)
    {
        person[PersonData.RouteResult] = failureReason;
        if (!route.LookTowardsFollow && !route.DirectPositionRequest && (route.Slot.Flags & 0x4000) != 0 &&
            stack is not null && world.ObjectById(route.AnchorObjectId) is { } anchor &&
            TryPushRouteFailureFeedback(world, person, anchor, frame, stack, failureReason, out var callerDepth))
        {
            person.NativeRoute = route with
            {
                PendingFailureFeedbackDepth = callerDepth,
                FailureReason = failureReason,
                EndFollowPending = false,
                AwaitingBeginFollow = true,
            };
            frame.Waiting = true;
            return PrimitiveResult.Again;
        }
        ClearRoute(person);
        frame.Waiting = false;
        return route.LookTowardsFollow ? PrimitiveResult.True : PrimitiveResult.False;
    }

    private static bool TryPushRouteFailureFeedback(SimulationWorld world, XPerson person, XObject anchor, StackFrame frame, TreeStack stack,
        short failureReason, out int callerDepth)
    {
        callerDepth = -1;
        ITreeTable? resolvedScope = null;
        short resolvedTreeId = 0;
        short resolvedCodeOwner = 0;
        if (anchor.TypeRecord?.BehaviorScope is SimsEngine.Content.BehaviorScope anchorScope &&
            anchorScope.FindNamedTree("Route failure feedback") is var anchorTree && anchorTree != 0)
        {
            resolvedScope = anchorScope;
            resolvedTreeId = anchorTree;
            resolvedCodeOwner = world.ResolveCodeOwner(anchor, anchorScope);
        }
        else if (person.TypeRecord?.BehaviorScope is SimsEngine.Content.BehaviorScope personScope &&
                 personScope.FindNamedTree("Route failure feedback") is var personTree && personTree != 0)
        {
            resolvedScope = personScope;
            resolvedTreeId = personTree;
            resolvedCodeOwner = world.ResolveCodeOwner(person, personScope);
        }
        else if (frame.Table is SimsEngine.Content.BehaviorScope frameScope &&
                 frameScope.FindNamedTree("Route failure feedback") is var frameTree && frameTree != 0)
        {
            resolvedScope = frameScope;
            resolvedTreeId = frameTree;
            resolvedCodeOwner = frame.CodeOwner;
        }

        if (resolvedScope is null || resolvedTreeId == 0)
            return false;

        callerDepth = stack.Frames.Count;
        var blockerId = person[ObjectData.PrimitiveResultId];
        return PersonInteractionStack.Push(person, anchor, stack, resolvedScope, resolvedTreeId, anchor.StackObjectKey,
            [failureReason, blockerId, 0, 0], codeOwner: resolvedCodeOwner);
    }

    private static void CompleteEndFollow(SimulationWorld world, XPerson person, RouteState route)
    {
        if (!route.LookTowardsFollow && !route.AwaitingBeginFollow)
            world.PlaySoundEvent?.Invoke("end_route", person.Id, false, false);
        person.AnimatorControlState = 3;
        var rootX = float.IsFinite(route.MotionX) ? route.MotionX : person.Position.X;
        var rootY = float.IsFinite(route.MotionY) ? route.MotionY : person.Position.Y;
        var rootDir = person.AnimatorRootDirection ?? person[ObjectData.Direction];
        var discreteDirection = QuantizeRootDirection(rootDir);
        person[ObjectData.Direction] = discreteDirection;
        person.AnimatorRootDirection = discreteDirection;
        person.AnimatorRootX = rootX;
        person.AnimatorRootY = rootY;
        person.NativeRoute = route with
        {
            AnimatorFollowState = 0,
            EndFollowPending = false,
            MotionX = rootX,
            MotionY = rootY,
            TransitionTargetX = rootX,
            TransitionTargetY = rootY,
            MotionTargetPathIndex = -1,
        };
    }

    private static void Trace(SimulationWorld world, XPerson person, short anchorId, ObjectPosition destination,
        string phase, string? failure)
    {
        if (world.CaptureExecutionTrace)
            world.NativeRouteTrace.Add(new SimulationNativeRouteTrace(person.Id, anchorId, destination, phase, failure));
    }

    private static bool StartPortalFunction(SimulationWorld world, XPerson person, XObject portal, TreeStack stack,
        StackFrame caller, RouteState route, out string? failure)
    {
        // Resolves portal crossing tree 0x0f from the selected portal's definition rather than its linked
        // multi-tile parts.
        var treeId = SimulationWorld.FunctionTreeId(portal, 0x0f);
        if (treeId == 0)
        {
            failure = "selected portal has no function 0x0f";
            return false;
        }
        var scope = portal.TypeRecord?.BehaviorScope;
        if (scope is null)
        {
            failure = $"selected portal {portal.Id} has no behavior scope";
            return false;
        }
        var callerDepth = stack.Frames.Count;
        if (!PersonInteractionStack.Push(person, portal, stack, scope, treeId, portal.StackObjectKey,
                codeOwner: world.ResolveCodeOwner(portal, scope)))
        {
            failure = $"function tree {treeId} on selected portal {portal.Id} could not be pushed";
            return false;
        }
        failure = null;
        if (!route.AwaitingBeginFollow)
        {
            // Halt route locomotion so portal animations do not stall on active gait or turn states.
            if (person.AnimationPlayback is { RouteDriven: true })
                world.StopCurrentAnimation(person);
            person.AnimatorControlState = 3;
            var rootX = float.IsFinite(route.MotionX) ? route.MotionX : person.Position.X;
            var rootY = float.IsFinite(route.MotionY) ? route.MotionY : person.Position.Y;
            var discreteDirection = QuantizeRootDirection(person.AnimatorRootDirection ?? person[ObjectData.Direction]);
            person[ObjectData.Direction] = discreteDirection;
            person.AnimatorRootDirection = discreteDirection;
            person.AnimatorRootX = rootX;
            person.AnimatorRootY = rootY;
            route = route with
            {
                AnimatorFollowState = 0,
                EndFollowPending = false,
                MotionAnimationIndex = -1,
                MotionFrame = 0f,
                MotionPracticeFrame = 0f,
                MotionX = rootX,
                MotionY = rootY,
            };
        }
        var routeCostFunctionObject = PortalFunction(world, portal)?.FunctionObject ?? portal;
        RecordPortalRouteCostAfterSelection(world, person, portal, routeCostFunctionObject);
        person.NativeRoute = route with
        {
            PendingPortalId = portal.Id,
            PendingPortalFunctionObjectId = routeCostFunctionObject.Id,
            PortalCallerDepth = callerDepth,
        };
        caller.Waiting = true;
        return true;
    }

    internal static void MarkPortalRouteCostUsed(SimulationWorld world, short portalId, short functionObjectId,
        short routeId)
    {
        if (routeId <= 0) return;
        world.ObjectById(portalId)?.SetPortalRouteCost(routeId, UsedPortalRouteCost);
        world.ObjectById(functionObjectId)?.SetPortalRouteCost(routeId, UsedPortalRouteCost);
    }

    internal static (XObject FunctionObject, ITreeTable? Scope, short TreeId)? PortalFunction(SimulationWorld world, XObject portal)
    {
        var matchInteractionGroup = portal.Definition[(int)SimsEngine.Formats.ObjdField.BuildModeType] == 1;
        var visited = new HashSet<short>();
        var nextId = matchInteractionGroup
            ? portal.MultiTileMasterId == 0 ? portal.Id : portal.MultiTileMasterId
            : portal.MultiTileNextId != 0 ? portal.MultiTileNextId : portal.MultiTileMasterId;
        var firstId = nextId;
        while (nextId != 0 && visited.Add(nextId))
        {
            var current = world.ObjectById(nextId);
            if (current is null) return null;
            if (current.RuntimeClass is not (SimsEngine.Formats.ObjectClass.Portal or SimsEngine.Formats.ObjectClass.MultiTileObject))
                return null;
            if (matchInteractionGroup && (current.Id == portal.Id ||
                current.Definition[(int)SimsEngine.Formats.ObjdField.InteractionGroup] !=
                portal.Definition[(int)SimsEngine.Formats.ObjdField.InteractionGroup]))
            {
                nextId = current.MultiTileNextId;
                if (nextId == firstId) return null;
                continue;
            }
            if (!matchInteractionGroup && current.Id == portal.Id) return null;
            var treeId = SimulationWorld.FunctionTreeId(current, 0x0f);
            if (treeId != 0)
                return (current, current.TypeRecord?.BehaviorScope, treeId);
            nextId = current.MultiTileNextId != 0 || matchInteractionGroup
                ? current.MultiTileNextId
                : current.MultiTileMasterId;
            if (nextId == firstId) return null;
        }
        return null;
    }

    internal static void RecordPortalRouteCostAfterSelection(SimulationWorld world, XPerson person, XObject portal,
        XObject functionObject)
    {
        var routeId = person[ObjectData.RouteId];
        if (routeId <= 0) return;
        var cost = portal.PortalRouteCostAt(routeId);
        if (cost is >= MinRoomRankPortalCost and <= MaxRoomRankPortalCost)
        {
            portal.SetPortalRouteCost(routeId, UsedPortalRouteCost);
            functionObject.SetPortalRouteCost(routeId, UsedPortalRouteCost);
            return;
        }

        // Sims.exe parity: compares cached RoomWord84 rather than dynamic room map queries.
        var room = portal.RoomWord84;
        var greatestRoomCost = MinRoomRankPortalCost;
        foreach (var candidate in Portals(world))
        {
            if (candidate.RoomWord84 != room) continue;
            var candidateCost = candidate.PortalRouteCostAt(routeId);
            if (candidateCost is >= MinRoomRankPortalCost and <= MaxRoomRankPortalCost && greatestRoomCost <= candidateCost)
                greatestRoomCost = candidateCost;
        }
        if (cost != UsedPortalRouteCost)
        {
            portal.SetPortalRouteCost(routeId, greatestRoomCost);
            functionObject.SetPortalRouteCost(routeId, greatestRoomCost);
        }
    }

    internal static bool PortalIsEligibleFromCurrentRoom(ushort portalRoom, ushort currentRoom) =>
        portalRoom == currentRoom;

    private static XObject? PortalForStep(SimulationWorld world, XPerson person, XObject destination,
        ushort currentRoom, ushort destinationRoom, IReadOnlySet<short>? excludedPortalIds = null,
        ObjectPosition? destinationPosition = null) =>
        SelectPortalForDestination(world, person, destination, currentRoom, destinationRoom, excludedPortalIds,
            destinationPosition: destinationPosition);

    private static bool HasPortalForStep(SimulationWorld world, int level, ushort fromRoom, ushort toRoom,
        (int X, int Y) from, (int X, int Y) to) =>
        PortalCandidatesForStep(world, fromRoom, toRoom, from, to, level: level).Any();

    internal static IEnumerable<XObject> PortalCandidatesForStep(SimulationWorld world, ushort fromRoom,
        ushort toRoom, (int X, int Y) from, (int X, int Y) to, short? currentRoomWord = null, int? level = null)
    {
        if (Math.Abs(from.X - to.X) + Math.Abs(from.Y - to.Y) != 1) return [];
        var verticalCrossing = from.X == to.X;
        var sourceCurrentRoom = currentRoomWord is { } roomWord && roomWord != -5
            ? unchecked((ushort)roomWord)
            : fromRoom;
        return Portals(world).Where(portal =>
        {
            if (level is { } requestedLevel && portal.Position.Height != requestedLevel) return false;
            var tile = (X: portal.Position.X >> 4, Y: portal.Position.Y >> 4);
            if (tile != from && tile != to) return false;
            var portalRoom = portal.RoomWord84 != -5
                ? unchecked((ushort)portal.RoomWord84)
                : RoomKeyAt(world, portal.Position);
            if (!PortalIsEligibleFromCurrentRoom(portalRoom, sourceCurrentRoom)) return false;
            return verticalCrossing ? portal[ObjectData.Direction] % 4 == 0 : portal[ObjectData.Direction] % 4 == 2;
        });
    }

    internal static float PortalTransitionDistanceCost(XObject from, XObject to)
    {
        if (to.TypeRecord?.ObjectType == 7) return XObject.UnallocatedPortalRouteCost;
        return PortalTransitionDistanceCost(from, to.Position);
    }

    private static float PortalTransitionDistanceCost(XObject from, ObjectPosition to)
    {
        var dx = (float)from.Position.X - to.X;
        var dy = (float)from.Position.Y - to.Y;
        var dz = (to.Height - from.Position.Height) * 20f;
        return MathF.Sqrt((dx * dx + dy * dy) * (1f / 256f) + dz * dz);
    }

    internal static float ProjectPortalRouteDistance(SimulationWorld world, XObject origin, XObject target)
    {
        ProjectPortalRoutes(world, origin);
        var routeId = origin[ObjectData.RouteId];
        if (routeId > 0 && target.RuntimeClass == SimsEngine.Formats.ObjectClass.Portal &&
            SimulationWorld.FunctionTreeId(target, 0x0f) != 0 &&
            !target.PortalRouteCosts.ContainsKey(routeId))
        {
            world.InitializePortalRouteCosts(origin);
            origin.SetPortalRouteCost(routeId, XObject.UninitializedPortalRouteCost);
            ProjectPortalRoutes(world, origin);
        }
        return routeId > 0 ? target.PortalRouteCostAt(routeId) : XObject.UnallocatedPortalRouteCost;
    }

    private static void ProjectPortalRoutes(SimulationWorld world, XObject origin)
    {
        var routeId = origin[ObjectData.RouteId];
        if (routeId == 0 || !origin.PortalRouteCosts.ContainsKey(routeId))
        {
            routeId = world.InitializePortalRouteCosts(origin);
            if (routeId > 0 && !origin.PortalRouteCosts.ContainsKey(routeId))
                origin.SetPortalRouteCost(routeId, XObject.UninitializedPortalRouteCost);
        }
        if (routeId <= 0) return;
        if (origin.PortalRouteCostAt(routeId) != XObject.UninitializedPortalRouteCost) return;

        var portals = Portals(world).ToArray();
        foreach (var portal in portals) portal.SetPortalRouteCost(routeId, UnreachablePortalRouteCost);
        origin.SetPortalRouteCost(routeId, 0f);
        var settled = new HashSet<short>();
        while (true)
        {
            XObject? current = null;
            var currentCost = UnreachablePortalRouteCost;
            foreach (var portal in portals)
            {
                if (settled.Contains(portal.Id)) continue;
                var cost = portal.PortalRouteCostAt(routeId);
                if (cost >= currentCost) continue;
                current = portal;
                currentCost = cost;
            }
            if (current is null) break;
            settled.Add(current.Id);
            var linkedFunction = PortalFunction(world, current)?.FunctionObject;
            foreach (var candidate in portals)
            {
                if (settled.Contains(candidate.Id) ||
                    (candidate.RoomWord84 != current.RoomWord84 && !ReferenceEquals(candidate, linkedFunction))) continue;
                var priorCost = candidate.PortalRouteCostAt(routeId);
                var projected = currentCost + PortalTransitionDistanceCost(current, candidate) + 1f;
                if (projected < priorCost)
                    candidate.SetPortalRouteCost(routeId, projected);
            }
        }
    }

    internal static XObject? SelectPortalForDestination(SimulationWorld world, XPerson person, XObject destination,
        ushort currentRoom, ushort destinationRoom, IReadOnlySet<short>? excludedPortalIds = null,
        bool recordTrace = true, ObjectPosition? destinationPosition = null)
    {
        var routeId = person[ObjectData.RouteId];
        if (routeId == 0) return null;
        var portals = Portals(world).ToArray();
        foreach (var sourcePortal in portals)
        {
            if (PortalRoomKey(sourcePortal) != currentRoom) continue;
            var bestCost = sourcePortal.PortalRouteCostAt(routeId);
            if (sourcePortal.PortalRouteCosts.ContainsKey(routeId) &&
                bestCost != XObject.UninitializedPortalRouteCost) continue;
            sourcePortal.SetPortalRouteCost(routeId, UnreachablePortalRouteCost);
            var sourceDistance = PortalTransitionDistanceCost(person, sourcePortal);
            foreach (var destinationPortal in portals)
            {
                if (PortalRoomKey(destinationPortal) != destinationRoom) continue;
                var projectedCost = ProjectPortalRouteDistance(world, sourcePortal, destinationPortal);
                if (projectedCost == UnreachablePortalRouteCost) continue;
                var functionObject = PortalFunction(world, sourcePortal)?.FunctionObject ?? sourcePortal;
                if (ProjectPortalRouteDistance(world, functionObject, destinationPortal) > projectedCost) continue;
                var destinationDistance = destinationPosition is { } position
                    ? PortalTransitionDistanceCost(destinationPortal, position)
                    : PortalTransitionDistanceCost(destinationPortal, destination);
                var projected = MathF.Min(1000f, destinationDistance + projectedCost + sourceDistance);
                if (projected < sourcePortal.PortalRouteCostAt(routeId))
                    sourcePortal.SetPortalRouteCost(routeId, projected);
            }
        }

        var candidates = portals.Where(portal => PortalRoomKey(portal) == currentRoom &&
            (excludedPortalIds is null || !excludedPortalIds.Contains(portal.Id))).ToArray();
        var selected = SelectPreRankedPortal(candidates, routeId);
        if (recordTrace && world.CaptureExecutionTrace)
        {
            var details = string.Join(";", candidates.Select(portal =>
                $"{portal.Id}:{portal.TypeRecord?.Name ?? "?"}:room={PortalRoomKey(portal)}:cost={portal.PortalRouteCostAt(routeId)}:fn={PortalFunction(world, portal)?.FunctionObject.Id ?? 0}"));
            world.NativeRouteTrace.Add(new SimulationNativeRouteTrace(person.Id, destination.Id, destination.Position,
                "portal-ranking", $"route={routeId};source={currentRoom};destination={destinationRoom};selected={selected?.Id ?? 0};candidates={details}"));
        }
        return selected;
    }

    // Compares stored room attributes directly to prevent dynamic map queries from resolving sentinel room
    // values into valid rooms.
    private static ushort PortalRoomKey(XObject item) => unchecked((ushort)item.RoomWord84);

    internal static XObject? SelectPreRankedPortal(IReadOnlyList<XObject> candidates, short routeId)
    {
        if (candidates.Count == 0) return null;
        if (routeId == 0) return null;
        var eligible = candidates.Where(candidate => candidate.PortalRouteCostAt(routeId) is not (UnreachablePortalRouteCost or UsedPortalRouteCost)).ToArray();
        if (eligible.Length == 0) return null;
        var selected = eligible[0];
        var selectedCost = selected.PortalRouteCostAt(routeId);
        for (var index = 1; index < eligible.Length; index++)
        {
            var candidate = eligible[index];
            var cost = candidate.PortalRouteCostAt(routeId);
            if (cost >= selectedCost) continue;
            selected = candidate;
            selectedCost = cost;
        }
        return selected;
    }

    internal static short RelativeArrivalFacing(SimulationWorld world, XPerson person, XObject anchor,
        RoutingSlotRequest slot, ObjectPosition destination, short? routeSearchDirection)
    {
        var anchorDirection = (slot.Flags & 0x200) != 0 ? (short)0 : anchor[ObjectData.Direction];
        if ((slot.Flags & 0xff) == 0)
        {
            if (slot.Facing is -1 or -2)
            {
                var exactAnchorOrigin = RouteAnchorOrigin(world, anchor, slot);
                var faceTowardAnchor = (destination.X == exactAnchorOrigin.X && destination.Y == exactAnchorOrigin.Y)
                    ? anchorDirection
                    : DirectionToWaypoint((destination.X, destination.Y), (exactAnchorOrigin.X, exactAnchorOrigin.Y));
                return slot.Facing == -1 ? (short)((faceTowardAnchor + 4) & 7) : faceTowardAnchor;
            }
            return slot.Facing switch
            {
                >= 0 and <= 7 => (short)((anchorDirection + slot.Facing) & 7),
                -3 => person[ObjectData.Direction],
                _ => (short)((anchorDirection + 4) & 7),
            };
        }

        var anchorOrigin = RouteAnchorOrigin(world, anchor, slot);
        var center = LotGeometry.SlotPosition(anchorOrigin, anchorDirection, slot.X, slot.Y);
        var side = DirectionToWaypoint((center.X, center.Y), (destination.X, destination.Y));
        var searchDirection = routeSearchDirection ?? side;

        return slot.Facing switch
        {
            -1 => searchDirection,
            -2 => (destination.X == anchorOrigin.X && destination.Y == anchorOrigin.Y)
                ? (short)((anchorDirection + 4) & 7)
                : DirectionToWaypoint((destination.X, destination.Y), (anchorOrigin.X, anchorOrigin.Y)),
            -3 => person[ObjectData.Direction],
            _ => (short)((anchorDirection + slot.Facing) & 7),
        };
    }

    private static ObjectPosition RouteAnchorOrigin(SimulationWorld world, XObject anchor, RoutingSlotRequest slot)
    {
        if ((slot.Flags & 0x00010000) == 0) return anchor.Position;

        var lead = anchor.MultiTileMasterId == 0
            ? anchor
            : world.ObjectById(anchor.MultiTileMasterId) ?? anchor;
        long sumX = 0;
        long sumY = 0;
        var count = 0;
        var visited = new HashSet<short>();
        for (var member = lead; member is not null && visited.Add(member.Id);
             member = member.MultiTileNextId == 0 ? null : world.ObjectById(member.MultiTileNextId))
        {
            sumX += member.Position.X;
            sumY += member.Position.Y;
            count++;
        }
        return count == 0
            ? anchor.Position
            : new ObjectPosition(unchecked((int)(sumX / count)), unchecked((int)(sumY / count)), anchor.Position.Height);
    }

    private static short CandidateValidationDirection(XPerson person, XObject anchor, RoutingSlotRequest slot)
    {
        if ((slot.Flags & 0x1000) == 0) return person[ObjectData.Direction];
        var direction = 0;
        while (direction < 7 && (slot.Flags & (1u << direction)) == 0) direction++;
        return (short)((anchor[ObjectData.Direction] + direction) & 7);
    }
}
