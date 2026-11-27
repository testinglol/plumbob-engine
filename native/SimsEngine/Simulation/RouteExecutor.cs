using SimsEngine.Formats;
using System.Buffers;

namespace SimsEngine.Simulation;

public sealed record RouteState(short AnchorObjectId, ObjectPosition Destination, RoutingSlotRequest Slot,
    short PendingPortalId = 0, int PortalCallerDepth = -1, StackFrame? OwnerFrame = null, short OpenedPortalId = 0,
    short ArrivalFacing = 0, short PendingPortalFunctionObjectId = 0, short OpenedPortalFunctionObjectId = 0,
    short LastUsedPortalId = 0, short LastUsedPortalFunctionObjectId = 0, bool DirectPositionRequest = false,
    short[]? UsedPortalIds = null, int DiagnosticSnapshotCount = 0, int WaypointCooldownTicks = 0,
    int WaypointTileX = -1, int WaypointTileY = -1, int WaypointX = int.MinValue, int WaypointY = int.MinValue,
    int WaypointCellCenterX = int.MinValue, int WaypointCellCenterY = int.MinValue,
    int MotionTargetTileX = -1, int MotionTargetTileY = -1, int MotionTargetX = int.MinValue,
    int MotionTargetY = int.MinValue, bool MotionTargetIsDestination = false,
    float MotionFrame = 0f, float MotionPracticeFrame = 0f, float MotionX = float.NaN, float MotionY = float.NaN,
    float MotionPlaybackScale = 1f,
    short MotionAnimationIndex = -1, short MotionDirection = -1, bool StandChecked = false, int PendingStandDepth = -1,
    int AnimatorFollowState = 1, bool EndFollowPending = false, bool FollowPlacementRejected = false,
    int LocomotionFadeEndMils = 0, int PendingFailureFeedbackDepth = -1, short FailureReason = 0)
{
    internal IReadOnlyList<RouteExecutor.RouteWaypoint>? MotionPath { get; init; }
    internal int MotionTargetPathIndex { get; init; } = -1;
    internal IReadOnlyList<RouteExecutor.RouteWaypoint>? FollowPath { get; init; }
    internal int FollowWaypointIndex { get; init; }
    internal bool LookTowardsFollow { get; init; }
    internal float? LookTowardsHeading { get; init; }
    internal bool BeginFollowPendingTick { get; init; }
    internal bool AwaitingBeginFollow { get; init; }
    internal bool EndFollowOnArrival { get; init; }
    internal bool PoolSwimExitPending { get; init; }
    internal float? PoolSwimExitRootX { get; init; }
    internal float? PoolSwimExitRootY { get; init; }
    internal float? PoolSwimExitDirection { get; init; }
    public float? StartRootOriginX { get; init; }
    public float? StartRootOriginY { get; init; }
    public float? StartRootTargetX { get; init; }
    public float? StartRootTargetY { get; init; }
    public float? TurnRootOriginX { get; init; }
    public float? TurnRootOriginY { get; init; }
    public float? TurnRootTargetX { get; init; }
    public float? TurnRootTargetY { get; init; }
    public float? TurnRootSavedDirection { get; init; }
    public float? TurnRootPracticeScale { get; init; }
    public float? TurnRootStartDirection { get; init; }
    public float? TurnRootPracticeDirection { get; init; }
    public float? TransitionTargetX { get; init; }
    public float? TransitionTargetY { get; init; }
    internal short EntryFlags { get; init; }
    internal short ChairObjectId { get; init; }
    internal int PendingSitDepth { get; init; } = -1;
}

internal static partial class RouteExecutor
{
    internal readonly record struct SelectedRouteGoal(ObjectPosition Position, short SearchDirection,
        short EntryFlags = 0, short ChairObjectId = 0);
    private readonly record struct RouteGoalCandidate(ObjectPosition Position, double Cost, short SearchDirection,
        short EntryFlags = 0, short ChairObjectId = 0);
    internal readonly record struct RouteWaypoint(int TileX, int TileY, int X, int Y,
        int CellCenterX, int CellCenterY, bool IsDestination);

    internal static PrimitiveResult BeginLookTowardsFollow(SimulationWorld world, XPerson person, StackFrame frame,
        IReadOnlyList<ObjectPosition> points)
    {
        if (points.Count < 2) throw new ArgumentException("A follow path needs at least two points.", nameof(points));
        person.AnimatorControlState = 3;
        person.AnimatorRouteTransitionState = 0;
        world.StopCurrentAnimation(person);
        person.AnimatorRootX = person.Position.X;
        person.AnimatorRootY = person.Position.Y;
        person.AnimatorRootDirection = person[ObjectData.Direction];
        person.SetAnimatorDisplacements(0f, 0f, 0f);
        var path = points.Select((point, index) => new RouteWaypoint(
            point.X >> 4, point.Y >> 4, point.X, point.Y, point.X, point.Y, index == points.Count - 1)).ToArray();
        var here = points[0];
        var lookPoint = points[^1];
        var lookDx = lookPoint.X - here.X;
        var lookDy = lookPoint.Y - here.Y;
        var lookHeading = lookDx == 0 && lookDy == 0
            ? (float)(person[ObjectData.Direction] & 7)
            : SimsEngine.Character.AvatarDirection.Toward(lookDx, lookDy);
        person.NativeRoute = new RouteState(person.Id, here, new RoutingSlotRequest(), OwnerFrame: frame,
            DirectPositionRequest: true, ArrivalFacing: SimsEngine.Character.AvatarDirection.ToObjectDirection(lookHeading),
            MotionTargetTileX: here.X >> 4, MotionTargetTileY: here.Y >> 4, MotionTargetX: here.X,
            MotionTargetY: here.Y, MotionTargetIsDestination: true,
            MotionX: here.X, MotionY: here.Y,
            MotionPlaybackScale: person.AnimatorWalkingScale,
            MotionAnimationIndex: -1,
            MotionDirection: (short)(person[ObjectData.Direction] & 7), StandChecked: true, AnimatorFollowState: -1)
        {
            MotionPath = [path[0]],
            MotionTargetPathIndex = 1,
            FollowPath = path,
            FollowWaypointIndex = 1,
            LookTowardsFollow = true,
            LookTowardsHeading = lookHeading,
            BeginFollowPendingTick = false,
        };
        frame.Waiting = true;
        return PrimitiveResult.Stop;
    }

    internal static PrimitiveResult BeginDirectWalkFollow(SimulationWorld world, XPerson person, StackFrame frame,
        IReadOnlyList<ObjectPosition> points)
    {
        if (points.Count < 2) throw new ArgumentException("A follow path needs at least two points.", nameof(points));
        person.AnimatorControlState = 3;
        person.AnimatorRouteTransitionState = 0;
        person.AnimatorRootX = person.Position.X;
        person.AnimatorRootY = person.Position.Y;
        person.AnimatorRootDirection = person[ObjectData.Direction];
        person.SetAnimatorDisplacements(0f, 0f, 0f);
        var path = points.Select((point, index) => new RouteWaypoint(
            point.X >> 4, point.Y >> 4, point.X, point.Y, point.X, point.Y, index == points.Count - 1)).ToArray();
        var target = path[1];
        person.NativeRoute = new RouteState(person.Id, points[^1], new RoutingSlotRequest(), OwnerFrame: frame,
            DirectPositionRequest: true, ArrivalFacing: person[ObjectData.Direction],
            MotionTargetTileX: target.TileX, MotionTargetTileY: target.TileY, MotionTargetX: target.X,
            MotionTargetY: target.Y, MotionTargetIsDestination: target.IsDestination,
            MotionX: person.Position.X, MotionY: person.Position.Y,
            MotionPlaybackScale: person.AnimatorWalkingScale,
            MotionAnimationIndex: DirectionalWalkAnimation((short)(person[ObjectData.Direction] & 7)),
            MotionDirection: (short)(person[ObjectData.Direction] & 7), StandChecked: true, AnimatorFollowState: 1)
        {
            MotionPath = path,
            MotionTargetPathIndex = 1,
            FollowPath = path,
            FollowWaypointIndex = 1,
            LookTowardsFollow = true,
            BeginFollowPendingTick = true,
        };
        var clip = ResolveWalkAnimation(world, person, person.NativeRoute.MotionAnimationIndex);
        if (clip?.StandardRootMotionSamples is { Count: > 1 } samples)
            ShowWalkSkill(world, person, clip, 0f, samples.Count);
        frame.Waiting = true;
        return PrimitiveResult.Stop;
    }

    private const float AnimationFramesPerTick = 1.2f;
    private const float AnimatorTickMilliseconds = 42f;
    private const float StartTransitionProgress = 0.95f;
    private const uint BypassWallsAndRoomsFlag = 0x0800u;
    private const float MinRoomRankPortalCost = 1001f;
    private const float MaxRoomRankPortalCost = 1100f;
    private const float UsedPortalRouteCost = 1101f;
    private const float UnreachablePortalRouteCost = 10000f;

    public static PrimitiveResult Start(SimulationWorld world, XObject me, StackFrame frame, XObject anchor, RoutingSlotRequest slot, TreeStack? stack)
    {
        if (me is not XPerson person)
            throw new NotSupportedException("Sims.exe dispatches Go To Routing Slot only for a person.");
        if (person.ActiveActionCancelRequested && person[PersonData.NonInterruptible] == 0)
            return FailRouteBeforeStart(world, person, anchor, slot, frame, stack, failureReason: 4);
        if ((person[PersonData.IsGhost] & 1) != 0 && (slot.Flags & BypassWallsAndRoomsFlag) == 0)
        {
            slot = new RoutingSlotRequest
            {
                X = slot.X,
                Y = slot.Y,
                Z = slot.Z,
                Standing = slot.Standing,
                Sitting = slot.Sitting,
                Ground = slot.Ground,
                Flags = slot.Flags | BypassWallsAndRoomsFlag,
                CheckCandidateFootprintAgainstWall = slot.CheckCandidateFootprintAgainstWall,
                SnapTargetSlot = slot.SnapTargetSlot,
                MinProximity = slot.MinProximity,
                MaxProximity = slot.MaxProximity,
                OptimalProximity = slot.OptimalProximity,
                Gradient = slot.Gradient,
                Facing = slot.Facing,
                Resolution = slot.Resolution,
            };
        }
        var goal = SelectDestination(world, person, anchor, slot, stack);
        if (goal is null && person[PersonData.Sitting] == 1 &&
            ResolveSeatedContainer(world, person) is { } currentSeat &&
            SimulationWorld.HasFunction(currentSeat, 0x1a))
        {
            if (ReferenceEquals(currentSeat, anchor))
                goal = new SelectedRouteGoal(person.Position, anchor[ObjectData.Direction]);
            else if (IsSeatedChairMatchingSlot(world, person, anchor, slot, currentSeat, out var chairSector))
                goal = new SelectedRouteGoal(person.Position, chairSector, ChairObjectId: currentSeat.Id);
        }
        if (goal is null)
        {
            Trace(world, person, anchor.Id, anchor.Position, "destination-rejected", "no candidate passed placement validation");
            return FailRouteBeforeStart(world, person, anchor, slot, frame, stack, failureReason: 1);
        }
        Trace(world, person, anchor.Id, goal.Value.Position, "destination-selected", null);
        return StartResolved(world, person, frame, anchor, slot, goal.Value.Position, stack,
            routeSearchDirection: goal.Value.SearchDirection, routeEntryFlags: goal.Value.EntryFlags,
            chairObjectId: goal.Value.ChairObjectId);
    }

    internal static PrimitiveResult StartDirectPosition(SimulationWorld world, XPerson person, StackFrame frame,
        ObjectPosition destination, TreeStack? stack)
    {
        if (person.ActiveActionCancelRequested && person[PersonData.NonInterruptible] == 0)
        {
            person[PersonData.RouteResult] = 4;
            return PrimitiveResult.False;
        }
        var slot = (person[PersonData.IsGhost] & 1) != 0 ? new RoutingSlotRequest { Flags = BypassWallsAndRoomsFlag } : new RoutingSlotRequest();
        if (!Walkable(world, person, person, destination, slot, stack: stack))
        {
            Trace(world, person, person.Id, destination, "destination-rejected",
                $"direct target failed placement validation: {world.LastRouteCandidateFailureReason}");
            person[PersonData.RouteResult] = 1;
            return PrimitiveResult.False;
        }
        Trace(world, person, person.Id, destination, "destination-selected", null);
        return StartResolved(world, person, frame, person, slot, destination, stack, directPositionRequest: true);
    }

    internal static bool CancelDirectPosition(SimulationWorld world, XPerson person, StackFrame ownerFrame)
    {
        var route = person.NativeRoute;
        if (route is null || !route.DirectPositionRequest || !ReferenceEquals(route.OwnerFrame, ownerFrame) ||
            person.NativeRouteParents.Count != 0 || route.PendingPortalId != 0 || route.PortalCallerDepth >= 0)
            return false;

        Trace(world, person, route.AnchorObjectId, route.Destination, "direct-position-replaced", null);
        CompleteEndFollow(world, person, route);
        person.NativeRoute = null;
        ownerFrame.Waiting = false;
        return true;
    }

    private static PrimitiveResult StartResolved(SimulationWorld world, XPerson person, StackFrame frame,
        XObject anchor, RoutingSlotRequest slot, ObjectPosition destination, TreeStack? stack,
        bool directPositionRequest = false, short? routeSearchDirection = null, short routeEntryFlags = 0,
        short chairObjectId = 0)
    {
        person.AnimatorPoolTile = world.IsPoolTile(person.Position);
        var openedPortalId = (short)0;
        if (person.NativeRoute is { } parent && !ReferenceEquals(parent.OwnerFrame, frame))
        {
            person.NativeRouteParents.Add(parent);
            // Nested routing requests within a portal function cross the active portal directly to avoid
            // recursively triggering its transition tree.
            if (parent.PendingPortalId == anchor.Id) openedPortalId = anchor.Id;
        }
        person.NativeRoute = new RouteState(anchor.Id, destination, slot,
            OwnerFrame: frame, OpenedPortalId: openedPortalId,
            ArrivalFacing: directPositionRequest
                ? person[ObjectData.Direction]
                : RelativeArrivalFacing(world, person, anchor, slot, destination, routeSearchDirection),
            MotionPlaybackScale: person.AnimatorWalkingScale,
            DirectPositionRequest: directPositionRequest, AnimatorFollowState: 1)
        {
            AwaitingBeginFollow = true,
            EntryFlags = directPositionRequest ? (short)0 : routeEntryFlags,
            ChairObjectId = directPositionRequest ? (short)0 : chairObjectId,
        };
        frame.Waiting = true;
        return Continue(world, person, frame, stack);
    }

    public static PrimitiveResult Continue(SimulationWorld world, XObject me, StackFrame frame, TreeStack? stack)
    {
        if (me is not XPerson person)
            throw new NotSupportedException("Sims.exe dispatches Go To Routing Slot only for a person.");
        var route = person.NativeRoute;
        if (route is null)
        {
            frame.Waiting = false;
            return PrimitiveResult.False;
        }
        if (route.PendingFailureFeedbackDepth >= 0)
        {
            if (stack is not null && stack.Frames.Count > route.PendingFailureFeedbackDepth)
            {
                frame.Waiting = true;
                return PrimitiveResult.Stop;
            }
            person[PersonData.RouteResult] = route.FailureReason != 0 ? route.FailureReason : (short)1;
            ClearRoute(person);
            frame.Waiting = false;
            return PrimitiveResult.False;
        }
        if (route.PendingSitDepth >= 0)
        {
            if (stack is not null && stack.Frames.Count > route.PendingSitDepth)
            {
                frame.Waiting = true;
                return PrimitiveResult.Stop;
            }
            var targetChair = route.ChairObjectId != 0 ? world.ObjectById(route.ChairObjectId) : null;
            if (targetChair is not null && person[PersonData.Sitting] != 0 &&
                ReferenceEquals(ResolveSeatedContainer(world, person), targetChair))
            {
                person[PersonData.RouteResult] = 0;
                ClearRoute(person);
                frame.Waiting = false;
                return PrimitiveResult.True;
            }
            var sitFailure = person[PersonData.RouteResult] != 0 ? person[PersonData.RouteResult] : (short)5;
            return FinishRouteFailure(world, person, route with { PendingSitDepth = -1 }, frame, stack,
                failureReason: sitFailure);
        }
        var actionCancelled = person.ActiveActionCancelRequested && person[PersonData.NonInterruptible] == 0;
        if (actionCancelled && !route.LookTowardsFollow)
        {
            var cancelReason = route.FailureReason != 0 ? route.FailureReason : (short)4;
            person[PersonData.RouteResult] = cancelReason;
            route = route with { EndFollowPending = true, EndFollowOnArrival = false, FailureReason = cancelReason };
            person.NativeRoute = route;
            if (route.AnimatorFollowState is not (1 or -1))
            {
                CompleteEndFollow(world, person, route);
                return FinishRouteFailure(world, person, route, frame, stack, cancelReason);
            }
            frame.Waiting = true;
            return PrimitiveResult.Stop;
        }
        if (route.EndFollowPending && !route.EndFollowOnArrival)
        {
            if (route.AnimatorFollowState is not (1 or -1))
            {
                CompleteEndFollow(world, person, route);
                if (route.FollowPlacementRejected)
                {
                    person.AnimatorRootX = null;
                    person.AnimatorRootY = null;
                }
                if (route.LookTowardsFollow)
                {
                    ClearRoute(person);
                    frame.Waiting = false;
                    return PrimitiveResult.True;
                }
                return FinishRouteFailure(world, person, route, frame, stack,
                    route.FailureReason != 0 ? route.FailureReason : (short)1);
            }
            frame.Waiting = true;
            return PrimitiveResult.Stop;
        }
        if (route.AnimatorFollowState == -1 || route.PoolSwimExitPending)
        {
            frame.Waiting = true;
            return PrimitiveResult.Stop;
        }
        if (route.FollowPlacementRejected && route.AnimatorFollowState == 3)
        {
            CompleteEndFollow(world, person, route);
            person.AnimatorRootX = null;
            person.AnimatorRootY = null;
            if (route.LookTowardsFollow)
            {
                ClearRoute(person);
                frame.Waiting = false;
                return PrimitiveResult.True;
            }
            return FinishRouteFailure(world, person, route, frame, stack,
                route.FailureReason != 0 ? route.FailureReason : (short)1);
        }

        var portalCallbackCompleted = false;
        if (route.PendingPortalId != 0)
        {
            if (stack is null)
                throw new NotSupportedException("A route crossing a portal requires the active BHAV stack.");
            if (stack.Frames.Count > route.PortalCallerDepth) return PrimitiveResult.Stop;
            route = route with
            {
                PendingPortalId = 0,
                PortalCallerDepth = -1,
                OpenedPortalId = route.PendingPortalId,
                OpenedPortalFunctionObjectId = route.PendingPortalFunctionObjectId,
                PendingPortalFunctionObjectId = 0,
                AwaitingBeginFollow = true,
                MotionPath = null,
                MotionTargetX = int.MinValue,
                MotionTargetY = int.MinValue,
                MotionTargetPathIndex = -1,
            };
            portalCallbackCompleted = true;
            person.NativeRoute = route;
            route = TracePortalCallbackSnapshot(world, person, route);
        }

        var anchor = world.ObjectById(route.AnchorObjectId);
        if (anchor is null)
        {
            return EndFollowAndClearRoute(world, person, route, frame, stack, failureReason: 1);
        }

        if (route.PendingStandDepth >= 0)
        {
            if (stack is null || stack.Frames.Count > route.PendingStandDepth) return PrimitiveResult.Stop;
            route = route with { PendingStandDepth = -1 };
            person.NativeRoute = route;
            if (person[PersonData.Sitting] != 0)
                return FinishRouteFailure(world, person, route, frame, stack, failureReason: 6);
        }
        else if (!route.StandChecked)
        {
            route = route with { StandChecked = true };
            person.NativeRoute = route;
            if (person[PersonData.Sitting] == 1)
            {
                var seat = ResolveSeatedContainer(world, person);
                if (!route.DirectPositionRequest && seat is not null && SimulationWorld.HasFunction(seat, 0x1a) &&
                    (ReferenceEquals(seat, anchor) ||
                     (route.ChairObjectId != 0 && seat.Id == route.ChairObjectId) ||
                     IsSeatedChairMatchingSlot(world, person, anchor, route.Slot, seat, out _)))
                {
                    person[PersonData.RouteResult] = 0;
                    ClearRoute(person);
                    frame.Waiting = false;
                    return PrimitiveResult.True;
                }
                if (TryPushSeatedStandTree(world, person, seat, anchor, route, stack, out var callerDepth))
                {
                    person.NativeRoute = route with { PendingStandDepth = callerDepth };
                    frame.Waiting = true;
                    return PrimitiveResult.Again;
                }
                return FinishRouteFailure(world, person, route, frame, stack, failureReason: 1);
            }
        }

        // Invoke portal functions before pathing so movement never advances onto a closed door tile first.
        var currentRoom = unchecked((ushort)person.RoomWord84);
        var destinationRoom = route.LookTowardsFollow ? currentRoom : route.DirectPositionRequest
            ? RoomKeyAt(world, route.Destination)
            : PortalRoomKey(anchor);

        if (portalCallbackCompleted && currentRoom != destinationRoom)
        {
            var usedPortalIds = route.UsedPortalIds?.ToHashSet() ?? [];
            usedPortalIds.Add(route.OpenedPortalId);
            if (route.OpenedPortalFunctionObjectId != 0)
                usedPortalIds.Add(route.OpenedPortalFunctionObjectId);
            MarkPortalRouteCostUsed(world, route.OpenedPortalId, route.OpenedPortalFunctionObjectId,
                person[ObjectData.RouteId]);
            route = route with
            {
                UsedPortalIds = usedPortalIds.ToArray(),
                OpenedPortalId = 0,
                OpenedPortalFunctionObjectId = 0,
            };
            person.NativeRoute = route;
        }

        var isGhost = (person[PersonData.IsGhost] & 1) != 0;
        if (!isGhost && !route.LookTowardsFollow && currentRoom != destinationRoom && route.OpenedPortalId == 0)
        {
            InitializeRoutePortalCosts(world, person, route);
            var routeSourceRoom = unchecked((ushort)person.RoomWord84);
            var portal = PortalForStep(world, person, anchor, routeSourceRoom, destinationRoom,
                route.UsedPortalIds?.ToHashSet(), route.DirectPositionRequest ? route.Destination : null);
            if (portal is null)
            {
                Trace(world, person, anchor.Id, route.Destination, "portal-rejected", "no portal connects the route rooms");
                return EndFollowAndClearRoute(world, person, route, frame, stack, failureReason: 2);
            }
            var failure = stack is null ? "active BHAV stack is missing" : null;
            if (stack is null || !StartPortalFunction(world, person, portal, stack, frame, route, out failure))
            {
                Trace(world, person, anchor.Id, route.Destination, "portal-function-rejected",
                    $"portal={portal.Id}; {failure}");
                return EndFollowAndClearRoute(world, person, route, frame, stack, failureReason: 2);
            }
            Trace(world, person, anchor.Id, route.Destination, "portal-function-started", null);
            return PrimitiveResult.Again;
        }

        // Re-evaluate multi-candidate slots from post-portal coordinates once inside the destination room.
        if (portalCallbackCompleted && currentRoom == destinationRoom &&
            !route.LookTowardsFollow && !route.DirectPositionRequest &&
            (route.Slot.Flags & 0xff) != 0 && route.Slot.SnapTargetSlot < 0)
        {
            var reselected = SelectDestination(world, person, anchor, route.Slot, stack);
            if (reselected is { } selectedDestination)
            {
                var arrivalFacing = RelativeArrivalFacing(world, person, anchor, route.Slot,
                    selectedDestination.Position, selectedDestination.SearchDirection);
                route = route with
                {
                    Destination = selectedDestination.Position,
                    ArrivalFacing = arrivalFacing,
                    EntryFlags = selectedDestination.EntryFlags,
                    ChairObjectId = selectedDestination.ChairObjectId,
                };
                person.NativeRoute = route;
            }
        }

        if (!route.LookTowardsFollow && !route.DirectPositionRequest && route.ChairObjectId != 0)
        {
            person[PersonData.RouteEntryFlags] = route.EntryFlags;
            var chair = world.ObjectById(route.ChairObjectId);
            if (chair is not null && SimulationWorld.HasFunction(chair, 0x1a))
            {
                if (person[PersonData.Sitting] != 0 && ReferenceEquals(ResolveSeatedContainer(world, person), chair))
                {
                    person[PersonData.RouteResult] = 0;
                    ClearRoute(person);
                    frame.Waiting = false;
                    return PrimitiveResult.True;
                }
                if (person[PersonData.Gender] < 2 && stack is not null &&
                    SimulationWorld.FunctionTreeId(chair, 0x1a) is var sitTree && sitTree != 0 &&
                    chair.TypeRecord?.BehaviorScope is { } chairScope)
                {
                    var callerDepth = stack.Frames.Count;
                    if (PersonInteractionStack.Push(person, chair, stack, chairScope, sitTree, chair.StackObjectKey,
                            [0, 0, 0, 0], codeOwner: world.ResolveCodeOwner(chair, chairScope)))
                    {
                        person.NativeRoute = route with { PendingSitDepth = callerDepth };
                        frame.Waiting = true;
                        return PrimitiveResult.Again;
                    }
                }
            }
            return FinishRouteFailure(world, person, route, frame, stack, failureReason: 5);
        }

        var pendingTarget = route.MotionTargetX != int.MinValue;
        IReadOnlyList<RouteWaypoint>? followedPath = route.LookTowardsFollow ? route.FollowPath : pendingTarget ? route.MotionPath : null;
        List<RouteWaypoint>? plannedPath = null;
        if (!route.LookTowardsFollow && followedPath is null && !TryPath(world, person, route.Destination, anchor, out plannedPath, out _,
                directPositionRequest: route.DirectPositionRequest, directSlot: route.Slot, stack: stack,
                startTileOverride: person.Position.X == route.WaypointX && person.Position.Y == route.WaypointY
                    ? (route.WaypointTileX, route.WaypointTileY)
                    : null,
                startCellCenterOverride: person.Position.X == route.WaypointX && person.Position.Y == route.WaypointY &&
                                         route.WaypointCellCenterX != int.MinValue
                    ? (route.WaypointCellCenterX, route.WaypointCellCenterY)
                    : null,
                allowCrossRoom: isGhost || route.DirectPositionRequest || person.NativeRouteParents.Count != 0))
        {
            Trace(world, person, anchor.Id, route.Destination, "path-rejected", "no route path to selected destination");
            return EndFollowAndClearRoute(world, person, route, frame, stack, failureReason: 1);
        }
        IReadOnlyList<RouteWaypoint> path = followedPath ?? plannedPath!;

        if (route.AnimatorFollowState == 2)
        {
            ObjectPosition position;
            if (route.LookTowardsHeading is not null)
            {
                position = route.Destination with { Height = person.Position.Height };
            }
            else
            {
                var rootX = person.AnimatorRootX ?? route.MotionX;
                var rootY = person.AnimatorRootY ?? route.MotionY;
                var completedProjection = FindNearestRoutePoint(path, FTileIntegerCoordinate(rootX), FTileIntegerCoordinate(rootY));
                position = completedProjection is { } point
                    ? new ObjectPosition(point.X, point.Y, person.Position.Height)
                    : new ObjectPosition(FTileIntegerCoordinate(rootX), FTileIntegerCoordinate(rootY), person.Position.Height);
            }
            person[ObjectData.Direction] = QuantizeRootDirection(
                person.AnimatorRootDirection ?? person[ObjectData.Direction]);
            var placementAccepted = CanPlaceArrival(world, person, anchor, route.Slot, position, stack);
            if (!placementAccepted)
            {
                world.PlaceObject(person, person.Position, stack);
                world.RefreshPersonRoomStateAfterMovement(person);
            }
            else if (route.LookTowardsFollow)
            {
                world.PlaceObject(person, position, stack);
                world.RefreshPersonRoomStateAfterMovement(person);
            }
            CompleteEndFollow(world, person, route);
            if (placementAccepted && !route.LookTowardsFollow)
            {
                person[PersonData.RouteResult] = 0;
                ApplyRoutePlacement(world, person, anchor, route.Destination, route.Slot, stack);
                SetRouteEntryFlags(world, person, anchor, route);
                CommitArrivalHeading(person, route);
            }
            else if (placementAccepted && route.LookTowardsFollow)
            {
                CommitArrivalHeading(person, route);
            }
            Trace(world, person, anchor.Id, route.Destination,
                placementAccepted ? "follow-completed" : "follow-placement-rejected", null);
            if (!placementAccepted && !route.LookTowardsFollow)
                return FinishRouteFailure(world, person, route, frame, stack, failureReason: 1);
            ClearRoute(person);
            frame.Waiting = false;
            return PrimitiveResult.True;
        }

        if (route.AwaitingBeginFollow)
        {
            if (!route.LookTowardsFollow)
                world.PlaySoundEvent?.Invoke("begin_route", person.Id, false, false);
            if (person.AnimationPlayback is { RouteDriven: true })
                world.StopCurrentAnimation(person);
            person.AnimatorCurrentSkill = -1;
            person.AnimatorControlState = 3;
            person.AnimatorRouteTransitionState = 0;
            person.AnimatorGaitEntryState = 0;
            person.AnimatorPoolTransitionState = 0;
            person.AnimatorRootX = person.Position.X;
            person.AnimatorRootY = person.Position.Y;
            person.AnimatorRootDirection = person[ObjectData.Direction];
            person.SetAnimatorDisplacements(0f, 0f, 0f);
            route = route with
            {
                AwaitingBeginFollow = false,
                BeginFollowPendingTick = true,
                AnimatorFollowState = 1,
                MotionX = person.Position.X,
                MotionY = person.Position.Y,
                MotionAnimationIndex = -1,
                MotionFrame = 0,
                MotionPracticeFrame = 0,
                LocomotionFadeEndMils = 0,
            };
            person.NativeRoute = route;
        }

        if (!route.LookTowardsFollow && path.Count > 1)
            AskPeopleOnRouteToMove(world, person, anchor, path);

        if (world.CaptureExecutionTrace)
        {
            var nextTileDescription = path.Count > 1
                ? $"tile=({path[1].TileX},{path[1].TileY}) point=({path[1].X},{path[1].Y})"
                : "none";
            var owner = route.OwnerFrame is { } ownerFrame ? $"{ownerFrame.TreeId}:{ownerFrame.Instruction}" : "none";
            Trace(world, person, anchor.Id, route.Destination, "path-plan",
                $"owner={owner}; slotSnap={route.Slot.SnapTargetSlot}; slotFlags=0x{route.Slot.Flags:X}; direct={route.DirectPositionRequest}; " +
                $"before=({person.Position.X},{person.Position.Y},{person.Position.Height}); " +
                $"start=({path[0].X},{path[0].Y}); count={path.Count}; next={nextTileDescription}; " +
                $"end=({path[^1].X},{path[^1].Y})");
        }

        var hasPendingMotionTarget = route.MotionTargetX != int.MinValue;
        if (path.Count <= 1 && !hasPendingMotionTarget)
        {
            var atDestinationHeading = ArrivalHeading(route);
            var atDestinationError = atDestinationHeading - (person.AnimatorRootDirection ?? person[ObjectData.Direction]);
            while (atDestinationError >= 4f) atDestinationError -= 8f;
            while (atDestinationError < -4f) atDestinationError += 8f;
            if (route.AnimatorFollowState == 1 && !route.EndFollowPending && !route.LookTowardsFollow &&
                MathF.Abs(atDestinationError) > 0.000001f)
            {
                var here = person.Position;
                person.AnimatorControlState = 3;
                person.AnimatorRootX = here.X;
                person.AnimatorRootY = here.Y;
                person.NativeRoute = route with
                {
                    AnimatorFollowState = -1,
                    BeginFollowPendingTick = false,
                    MotionPath = path,
                    MotionTargetPathIndex = path.Count - 1,
                    MotionTargetTileX = here.X >> 4,
                    MotionTargetTileY = here.Y >> 4,
                    MotionTargetX = here.X,
                    MotionTargetY = here.Y,
                    MotionTargetIsDestination = true,
                    MotionX = here.X,
                    MotionY = here.Y,
                    MotionAnimationIndex = -1,
                    MotionFrame = 0f,
                    MotionPracticeFrame = 0f,
                };
                frame.Waiting = true;
                return PrimitiveResult.Stop;
            }
            if (route.AnimatorFollowState is 1 or -1)
            {
                person.NativeRoute = route with { EndFollowPending = true, EndFollowOnArrival = true };
                frame.Waiting = true;
                return PrimitiveResult.Stop;
            }
            var destinationPosition = route.Destination with { Height = route.Destination.Height == 0 ? 1 : route.Destination.Height };
            var placementAccepted = CanPlaceArrival(world, person, anchor, route.Slot, destinationPosition, stack);
            if (!placementAccepted && !route.LookTowardsFollow)
            {
                CompleteEndFollow(world, person, route);
                return FinishRouteFailure(world, person, route, frame, stack, failureReason: 1);
            }
            if (!route.LookTowardsFollow)
                person[PersonData.RouteResult] = 0;
            CommitArrivalHeading(person, route);
            ApplyRoutePlacement(world, person, anchor, route.Destination, route.Slot, stack);
            SetRouteEntryFlags(world, person, anchor, route);
            CompleteEndFollow(world, person, route);
            ClearRoute(person);
            frame.Waiting = false;
            return PrimitiveResult.True;
        }

        var next = hasPendingMotionTarget
            ? new RouteWaypoint(route.MotionTargetTileX, route.MotionTargetTileY, route.MotionTargetX,
                route.MotionTargetY, route.MotionTargetX, route.MotionTargetY, route.MotionTargetIsDestination)
            : path[1];
        var nextPosition = new ObjectPosition(next.X, next.Y, person.Position.Height);
        var nextRoom = world.LotRoomMaps.TryGetValue(nextPosition.Height, out var routeMap) &&
                       (uint)next.TileX < routeMap.Width && (uint)next.TileY < routeMap.Height
            ? routeMap.RoomAt(next.TileX, next.TileY)
            : SimsEngine.World.RoomMap.NoRoom;
        if (!isGhost && !route.LookTowardsFollow && person.NativeRouteParents.Count == 0 && currentRoom != nextRoom && currentRoom != SimsEngine.World.RoomMap.NoRoom && nextRoom != SimsEngine.World.RoomMap.NoRoom)
        {
            InitializeRoutePortalCosts(world, person, route);
            var routeSourceRoom = unchecked((ushort)person.RoomWord84);
            var routeDestinationRoom = route.DirectPositionRequest
                ? RoomKeyAt(world, route.Destination)
                : PortalRoomKey(anchor);
            // Reuse OpenedPortalId before PortalForStep so multi-tile doors cannot pick a sibling tile before being marked used.
            var portal = route.OpenedPortalId != 0
                ? world.ObjectById(route.OpenedPortalId)
                : PortalForStep(world, person, anchor, routeSourceRoom, routeDestinationRoom,
                    route.UsedPortalIds?.ToHashSet(), route.DirectPositionRequest ? route.Destination : null);
            if (portal is null)
            {
                Trace(world, person, anchor.Id, route.Destination, "portal-rejected", "no portal connects the route rooms");
                return EndFollowAndClearRoute(world, person, route, frame, stack, failureReason: 2);
            }
            if (route.LastUsedPortalId != 0)
            {
                MarkPortalRouteCostUsed(world, route.LastUsedPortalId, route.LastUsedPortalFunctionObjectId,
                    person[ObjectData.RouteId]);
                route = route with { LastUsedPortalId = 0, LastUsedPortalFunctionObjectId = 0 };
                person.NativeRoute = route;
            }
            if (route.OpenedPortalId != portal.Id)
            {
                var failure = stack is null ? "active BHAV stack is missing" : null;
                if (stack is null || !StartPortalFunction(world, person, portal, stack, frame, route, out failure))
                {
                    Trace(world, person, anchor.Id, route.Destination, "portal-function-rejected",
                        $"portal={portal.Id}; {failure}");
                    return EndFollowAndClearRoute(world, person, route, frame, stack, failureReason: 2);
                }
                if (!route.AwaitingBeginFollow)
                    world.PlaySoundEvent?.Invoke("end_route", person.Id, false, false);
                Trace(world, person, anchor.Id, route.Destination, "portal-function-started", null);
                return PrimitiveResult.Again;
            }
            route = route with
            {
                OpenedPortalId = 0,
                LastUsedPortalId = portal.Id,
                LastUsedPortalFunctionObjectId = route.OpenedPortalFunctionObjectId,
                OpenedPortalFunctionObjectId = 0,
            };
            person.NativeRoute = route;
        }
        var targetX = hasPendingMotionTarget ? route.MotionTargetX : next.X;
        var targetY = hasPendingMotionTarget ? route.MotionTargetY : next.Y;
        var motionX = float.IsNaN(route.MotionX) ? person.Position.X : route.MotionX;
        var motionY = float.IsNaN(route.MotionY) ? person.Position.Y : route.MotionY;
        var desiredDirection = DirectionToWaypoint((person.Position.X, person.Position.Y), (targetX, targetY));
        var previousMotionDirection = route.MotionDirection;
        if (!hasPendingMotionTarget)
        {
            route = route with
            {
                MotionTargetPathIndex = 1,
                MotionTargetTileX = next.TileX,
                MotionTargetTileY = next.TileY,
                MotionTargetX = targetX,
                MotionTargetY = targetY,
                MotionTargetIsDestination = next.IsDestination,
                MotionX = motionX,
                MotionY = motionY,
                MotionPath = path,
            };
        }
        if (route.MotionAnimationIndex < 0)
        {
            var probeSkill = person[ObjectData.WalkStyle] == 1 ? (short)21 : (short)20;
            var fallbackAdjustSkill = DirectionalWalkAnimation(desiredDirection);
            var probeClip = ResolveWalkAnimation(world, person, probeSkill) ??
                            ResolveWalkAnimation(world, person, fallbackAdjustSkill);
            if (probeClip?.StandardRootMotionSamples is not { Count: > 1 } probeSamples)
            {
                Trace(world, person, anchor.Id, route.Destination, "walk-skill-missing",
                    $"standard animation {probeSkill} has no root-motion samples");
                return EndFollowAndClearRoute(world, person, route, frame);
            }
            if (route.BeginFollowPendingTick)
            {
                route = route with { MotionDirection = desiredDirection };
                person.NativeRoute = route;
                if (person.AnimationPlayback is not { RouteDriven: true })
                {
                    ShowWalkSkill(world, person, probeClip, 0f, probeSamples.Count);
                    person.AnimatorCurrentSkill = -1;
                }
                return PrimitiveResult.Stop;
            }
            var selectedFallback = person.AnimatorControlState is 9 or 10
                ? (ResolveWalkAnimation(world, person, probeSkill)?.StandardRootMotionSamples is { Count: > 1 }
                    ? probeSkill
                    : fallbackAdjustSkill)
                : (ResolveWalkAnimation(world, person, fallbackAdjustSkill)?.StandardRootMotionSamples is { Count: > 1 }
                    ? fallbackAdjustSkill
                    : probeSkill);
            route = route with
            {
                MotionDirection = desiredDirection,
                MotionAnimationIndex = selectedFallback,
                MotionFrame = 0f,
                MotionPracticeFrame = 0f,
            };
        }
        else if (!hasPendingMotionTarget && previousMotionDirection != desiredDirection)
        {
            var walking = route.MotionAnimationIndex >= 19;
            route = route with
            {
                MotionDirection = desiredDirection,
                MotionAnimationIndex = walking ? route.MotionAnimationIndex : DirectionalWalkAnimation(desiredDirection),
                MotionFrame = walking ? route.MotionFrame : 0f,
                MotionPracticeFrame = walking ? route.MotionPracticeFrame : 0f,
            };
        }
        if (route.MotionAnimationIndex is 19 or 22 &&
            ResolveWalkAnimation(world, person, route.MotionAnimationIndex)?.StandardRootMotionSamples is { Count: > 1 } startSamples &&
            route.MotionPracticeFrame >= startSamples.Count * StartTransitionProgress)
        {
            route = route with
            {
                MotionAnimationIndex = person[ObjectData.WalkStyle] == 1 ? (short)21 : (short)20,
                MotionFrame = 0f,
                MotionPracticeFrame = 0f,
            };
            person.AnimatorControlState = person[ObjectData.WalkStyle] == 1 ? 10 : 9;
            person.AnimatorGaitEntryState = 1;
            person.AnimatorPoolTransitionState = 1;
            person.NativeRoute = route;
        }

        var clip = ResolveWalkAnimation(world, person, route.MotionAnimationIndex);
        if (clip?.StandardRootMotionSamples is not { Count: > 1 } samples)
        {
            Trace(world, person, anchor.Id, route.Destination, "walk-skill-missing",
                $"standard animation {route.MotionAnimationIndex} has no root-motion samples");
            return EndFollowAndClearRoute(world, person, route, frame);
        }
        var turnPractice = person.AnimatorControlState is 4 or 5;
        var playbackScale = turnPractice && route.TurnRootPracticeScale is { } turnScale
            ? turnScale
            : person.AnimatorWalkingScale;
        route = route with { MotionPlaybackScale = playbackScale };
        var effectivePlaybackScale = playbackScale;
        var oneShot = turnPractice || route.MotionAnimationIndex is >= 4 and <= 18;
        // Root motion advances every tick even when bone poses are skipped, so animation phase calculation
        // must measure elapsed time since the last full evaluation when full updates resume.
        var practiceApplyMils = unchecked(person.AnimatorMilliseconds + AnimatorTickMilliseconds);
        var elapsedPracticeMils = person.AnimationPlayback?.LastPracticeApplyMils is { } lastApplyMils
            ? unchecked(practiceApplyMils - lastApplyMils)
            : AnimatorTickMilliseconds;
        var practiceFrameDelta = clip.DurationMilliseconds > 0f
            ? samples.Count * elapsedPracticeMils * effectivePlaybackScale / clip.DurationMilliseconds
            : AnimationFramesPerTick * (elapsedPracticeMils / (float)AnimatorTickMilliseconds) * effectivePlaybackScale;
        var frameDelta = oneShot
            ? MathF.Min(practiceFrameDelta, Math.Max(0f, samples.Count - route.MotionFrame))
            : practiceFrameDelta;
        var targetDxNow = targetX - motionX;
        var targetDyNow = targetY - motionY;
        var targetDistanceNow = MathF.Sqrt(targetDxNow * targetDxNow + targetDyNow * targetDyNow);
        var movedX = motionX;
        var movedY = motionY;
        var activeFollowPlacement = route.AnimatorFollowState == 2;
        var arrived = activeFollowPlacement && (targetDistanceNow <= 0.0001f ||
                      (person.Position.X == targetX && person.Position.Y == targetY));

        var movedXInteger = FTileIntegerCoordinate(movedX);
        var movedYInteger = FTileIntegerCoordinate(movedY);
        var nearestRoutePoint = FindNearestRoutePoint(path, movedXInteger, movedYInteger);
        var movedPosition = nearestRoutePoint is { } nearest
            ? new ObjectPosition(nearest.X, nearest.Y, person.Position.Height)
            : new ObjectPosition(movedXInteger, movedYInteger, person.Position.Height);
        if (movedX != motionX || movedY != motionY)
        {
            person.AnimatorProjectedRootStepX = movedX - motionX;
            person.AnimatorProjectedRootStepY = movedY - motionY;
        }
        var positionBefore = person.Position;
        var captureWaypointSnapshot = CanCaptureRouteSnapshot(world, route);
        if (captureWaypointSnapshot)
        {
            route = route with { DiagnosticSnapshotCount = route.DiagnosticSnapshotCount + 1 };
            person.NativeRoute = route;
            Trace(world, person, anchor.Id, route.Destination, "waypoint-world-before",
                $"owner={route.OwnerFrame?.TreeId}:{route.OwnerFrame?.Instruction}; next=({next.TileX},{next.TileY})@({targetX},{targetY}); " +
                RouteWorldSnapshot(world, person, positionBefore, movedPosition));
        }
        var canPlacePosition = movedPosition with
        {
            Height = movedPosition.Height == 0 ? 1 : movedPosition.Height,
        };
        if (route.AnimatorFollowState == 2)
            person[ObjectData.Direction] = QuantizeRootDirection(
                person.AnimatorRootDirection ?? person[ObjectData.Direction]);
        var accepted = !activeFollowPlacement || CanPlaceArrival(world, person, anchor, route.Slot, canPlacePosition, stack);
        if (!accepted && world.CaptureExecutionTrace)
            Trace(world, person, anchor.Id, route.Destination, "follow-placement-rejected",
                $"follow={route.AnimatorFollowState}; control={person.AnimatorControlState}; " +
                $"position=({canPlacePosition.X},{canPlacePosition.Y},{canPlacePosition.Height}); " +
                $"failure={world.LastPlacementFailureCode}; portalFailure={world.LastPortalPlacementFailureCode}");
        if (!accepted)
        {
            movedPosition = positionBefore;
            movedX = positionBefore.X;
            movedY = positionBefore.Y;
        }
        if (activeFollowPlacement)
        {
            world.PlaceObject(person, movedPosition, stack);
            world.RefreshPersonRoomStateAfterMovement(person);
        }
        if (world.CaptureExecutionTrace)
            Trace(world, person, anchor.Id, route.Destination,
                activeFollowPlacement ? "waypoint-placement" : "follow-pending",
                $"owner={route.OwnerFrame?.TreeId}:{route.OwnerFrame?.Instruction}; next=({next.TileX},{next.TileY})@({targetX},{targetY}); " +
                $"follow={route.AnimatorFollowState}; control={person.AnimatorControlState}; skill={route.MotionAnimationIndex}; fade={route.LocomotionFadeEndMils}; " +
                $"clip={clip.Name}; markers={clip.LocomotionMarkerOne}/{clip.LocomotionMarkerTwo}; " +
                $"before=({positionBefore.X},{positionBefore.Y},{positionBefore.Height}); " +
                $"after=({person.Position.X},{person.Position.Y},{person.Position.Height})");
        if (captureWaypointSnapshot)
            Trace(world, person, anchor.Id, route.Destination, "waypoint-world-after",
                $"owner={route.OwnerFrame?.TreeId}:{route.OwnerFrame?.Instruction}; next=({next.TileX},{next.TileY})@({targetX},{targetY}); " +
                RouteWorldSnapshot(world, person, positionBefore, person.Position));

        if (!accepted)
        {
            if (!route.LookTowardsFollow)
                person[PersonData.RouteResult] = 1;
            route = route with { MotionX = movedX, MotionY = movedY, FailureReason = 1 };
            if (route.AnimatorFollowState is 1 or -1)
            {
                person.NativeRoute = route with { EndFollowPending = true, FollowPlacementRejected = true };
                return PrimitiveResult.Stop;
            }
            if (route.LookTowardsFollow)
            {
                route = route with { AnimatorFollowState = 3 };
                person.NativeRoute = route;
                CompleteEndFollow(world, person, route);
                ClearRoute(person);
                person.AnimatorRootX = null;
                person.AnimatorRootY = null;
                frame.Waiting = false;
                return PrimitiveResult.True;
            }
            route = route with { AnimatorFollowState = 3 };
            person.NativeRoute = route;
            CompleteEndFollow(world, person, route);
            person.AnimatorRootX = null;
            person.AnimatorRootY = null;
            return FinishRouteFailure(world, person, route, frame, stack, failureReason: 1);
        }

        var oneShotEnded = oneShot && route.MotionFrame + frameDelta >= samples.Count;
        var standingAdjustEnded = oneShotEnded && !turnPractice &&
                                  route.MotionAnimationIndex is >= 11 and <= 18;
        if (standingAdjustEnded)
        {
            person[ObjectData.Direction] = route.MotionDirection;
            person.AnimatorRootDirection = route.MotionDirection;
            person.RefreshFootprintBounds();
        }
        var nextAnimationIndex = turnPractice ? route.MotionAnimationIndex : route.MotionAnimationIndex switch
        {
            >= 4 and <= 18 => person[ObjectData.WalkStyle] == 1 ? (short)22 : (short)19,
            19 => (short)20,
            22 => (short)21,
            _ => route.MotionAnimationIndex,
        };
        var nextFrame = oneShotEnded ? 0f : oneShot
            ? route.MotionFrame + frameDelta
            : (route.MotionFrame + frameDelta) % samples.Count;
        var nextPracticeFrame = oneShotEnded && !turnPractice ? 0f : world.AvatarAnimationRootOnly
            ? route.MotionPracticeFrame
            : turnPractice || route.MotionAnimationIndex is 19 or 22
                ? Math.Min(samples.Count, route.MotionPracticeFrame + frameDelta)
                : (route.MotionPracticeFrame + frameDelta) % samples.Count;
        route = route with
        {
            MotionAnimationIndex = oneShotEnded && !turnPractice ? nextAnimationIndex : route.MotionAnimationIndex,
            MotionFrame = oneShotEnded && turnPractice ? route.MotionFrame + frameDelta : nextFrame,
            MotionPracticeFrame = nextPracticeFrame,
            MotionX = movedX,
            MotionY = movedY,
        };
        person.AnimatorRootX = movedX;
        person.AnimatorRootY = movedY;
        if (standingAdjustEnded)
        {
            person.AnimatorControlState = person[ObjectData.WalkStyle] == 1 ? 11 : 6;
            person.AnimatorGaitEntryState = 0;
            person.AnimatorPoolTransitionState = 0;
            var startClip = ResolveWalkAnimation(world, person, nextAnimationIndex);
            if (startClip is { StandardDistance: > 0f })
            {
                var angle = ((person.AnimatorRootDirection ?? person[ObjectData.Direction]) + 6f) * (MathF.PI / 4f);
                var startDistance = startClip.StandardDistance * (16f / 3f);
                route = route with
                {
                    StartRootOriginX = movedX,
                    StartRootOriginY = movedY,
                    StartRootTargetX = movedX + MathF.Cos(angle) * startDistance,
                    StartRootTargetY = movedY + MathF.Sin(angle) * startDistance,
                };
            }
        }
        if (route.LookTowardsFollow && arrived && next.IsDestination)
        {
            route = route with { AnimatorFollowState = 3 };
            person.NativeRoute = route;
            CompleteEndFollow(world, person, route);
            ClearRoute(person);
            frame.Waiting = false;
            return PrimitiveResult.True;
        }
        if (arrived && next.IsDestination)
        {
            var wasEndFollowPending = route.EndFollowPending;
            route = route with { AnimatorFollowState = 3 };
            person.NativeRoute = route;
            CompleteEndFollow(world, person, route);
            if (!wasEndFollowPending)
            {
                person[PersonData.RouteResult] = 0;
                ApplyRoutePlacement(world, person, anchor, route.Destination, route.Slot, stack);
                SetRouteEntryFlags(world, person, anchor, route);
                CommitArrivalHeading(person, route);
            }
            Trace(world, person, anchor.Id, route.Destination, "waypoint", null);
            if (wasEndFollowPending)
                return FinishRouteFailure(world, person, route, frame, stack,
                    route.FailureReason != 0 ? route.FailureReason : (short)1);
            ClearRoute(person);
            frame.Waiting = false;
            return PrimitiveResult.True;
        }
        if (arrived)
        {
            if (route.LookTowardsFollow)
            {
                var nextIndex = route.FollowWaypointIndex + 1;
                if (route.FollowPath is not { } followPath || nextIndex >= followPath.Count)
                {
                    return EndFollowAndClearRoute(world, person, route, frame, stack);
                }
                var followTarget = followPath[nextIndex];
                route = route with
                {
                    FollowWaypointIndex = nextIndex,
                    MotionTargetPathIndex = nextIndex,
                    MotionTargetTileX = followTarget.TileX,
                    MotionTargetTileY = followTarget.TileY,
                    MotionTargetX = followTarget.X,
                    MotionTargetY = followTarget.Y,
                    MotionTargetIsDestination = followTarget.IsDestination,
                    MotionPath = followPath,
                    MotionX = targetX,
                    MotionY = targetY,
                };
            }
            else
            {
                var nextIndex = Math.Max(1, route.MotionTargetPathIndex) + 1;
                if (nextIndex < path.Count)
                {
                    var following = path[nextIndex];
                    route = route with
                    {
                        MotionTargetPathIndex = nextIndex,
                        MotionTargetTileX = following.TileX,
                        MotionTargetTileY = following.TileY,
                        MotionTargetX = following.X,
                        MotionTargetY = following.Y,
                        MotionTargetIsDestination = following.IsDestination,
                        MotionPath = path,
                        MotionX = targetX,
                        MotionY = targetY,
                    };
                }
            }
            Trace(world, person, anchor.Id, route.Destination, "waypoint", null);
        }
        person.NativeRoute = route;
        var practiceClip = ResolveWalkAnimation(world, person, route.MotionAnimationIndex) ?? clip;
        var practiceSamples = practiceClip.StandardRootMotionSamples?.Count ?? samples.Count;
        ShowWalkSkill(world, person, practiceClip, nextPracticeFrame, practiceSamples);
        return PrimitiveResult.Stop;
    }

    internal static void ShowWalkSkill(SimulationWorld world, XPerson person, AvatarAnimationClip clip, float routeFrame, int sampleCount)
    {
        var loop = true;
        short? currentSkill = null;
        if (person.NativeRoute is { } route)
        {
            currentSkill = route.MotionAnimationIndex;
            loop = route.MotionAnimationIndex is not (>= 4 and <= 18);
        }
        if (person.AnimationPlayback is not { RouteDriven: true } playback || playback.Clip.Name != clip.Name)
        {
            playback = new AvatarAnimationPlayback(clip, backwards: false, loop: loop,
                startedAtMils: person.AnimatorMilliseconds)
                { RouteDriven = true, Interruptible = true };
            world.BeginPrimaryAnimation(person, playback);
        }
        if (currentSkill is { } skill)
            person.AnimatorCurrentSkill = skill;
        var scale = person.AnimatorControlState is 4 or 5 &&
                    person.NativeRoute?.TurnRootPracticeScale is { } ts &&
                    float.IsFinite(ts) && ts > 0f
            ? ts
            : (float.IsFinite(person.AnimatorWalkingScale) && person.AnimatorWalkingScale > 0f
                ? person.AnimatorWalkingScale
                : 1f);
        playback.SetPracticeScale(playback.Backwards ? -scale : scale);
        var nextPlaybackFrame = Math.Min(routeFrame * clip.FrameCount / Math.Max(sampleCount, 1), clip.FrameCount - 0.001f);
        playback.AdvanceRouteFrame(nextPlaybackFrame, queueSoundEvents: !world.AvatarAnimationRootOnly);
    }

    internal static AvatarAnimationClip? ResolveWalkAnimation(SimulationWorld world, XPerson person, int standardIndex)
    {
        var isPet = person.AnimatorBodyStringMode >= 2 || (person[PersonData.Gender] & 6) != 0;
        var child = !isPet && person[PersonData.PersonAge] <= 17;
        AvatarAnimationClip? clip = null;
        uint personGuid = 0;
        if (person.TypeRecord is { } typeRecord)
        {
            personGuid = unchecked((uint)typeRecord.Key);
            if (world.CustomWalkAvatarAnimationTable.TryGetValue((personGuid, standardIndex), out var customClip))
                clip = customClip;
        }

        if (!isPet && person.AnimatorPoolTile)
        {
            var poolTable = child ? (ushort)160 : (ushort)(158 + (person[PersonData.Gender] & 1));
            if (world.StandardWalkFallbackAnimationTable.TryGetValue((poolTable, standardIndex), out var poolClip))
                return poolClip;
        }
        if (clip is not null) return clip;
        if (isPet)
        {
            var templateGuid = person.AnimatorBodyStringMode is 2 or 3 || (person[PersonData.Gender] & 2) != 0
                ? 0x4A70DF92u
                : 0x7BEA0977u;
            if (world.CustomWalkAvatarAnimationTable.TryGetValue((templateGuid, standardIndex), out clip))
                return clip;
            if (world.CustomWalkAvatarAnimationTable.Count > 0)
                return null;
        }
        else if (personGuid != 0 &&
                 world.CustomWalkAvatarAnimationTable.TryGetValue((personGuid, 3), out var customStand) &&
                 !customStand.Name.StartsWith("a2o-", StringComparison.OrdinalIgnoreCase) &&
                 !customStand.Name.StartsWith("c2o-", StringComparison.OrdinalIgnoreCase))
        {
            return null;
        }

        var fallbackTable = child ? (ushort)151 : (ushort)(152 + (person[PersonData.Gender] & 1));
        if (world.StandardWalkFallbackAnimationTable.TryGetValue((fallbackTable, standardIndex), out clip)) return clip;
        return world.StandardWalkFallbackAnimationTable.GetValueOrDefault(((ushort)150, standardIndex));
    }

    internal static short DirectionalWalkAnimation(short direction) => direction switch
    {
        0 => 18,
        1 => 17,
        2 => 15,
        3 => 13,
        4 => 11,
        5 => 12,
        6 => 14,
        7 => 16,
        _ => 15,
    };

    internal static float RouteStepDistance(float standardDistance, float skillDurationMilliseconds, float practiceScale,
        float elapsedMilliseconds)
    {
        var practiceDuration = skillDurationMilliseconds / practiceScale;
        var ticksPerPractice = practiceDuration / elapsedMilliseconds;
        var skillDistancePerTile = standardDistance / 3f;
        return (16f * skillDistancePerTile) / ticksPerPractice;
    }

    internal static (int X, int Y)? FindNearestRoutePoint(IReadOnlyList<RouteWaypoint> path, int x, int y)
    {
        var nearest = FindNearestRouteSegment(path, x, y);
        return nearest is { } point ? (point.X, point.Y) : null;
    }

    private static (int X, int Y, int SegmentIndex)? FindNearestRouteSegment(IReadOnlyList<RouteWaypoint> path,
        int x, int y, int firstSegment = 0, int? lastSegmentOverride = null)
    {
        var lastSegment = Math.Min(path.Count - 2, lastSegmentOverride ?? path.Count - 2);
        firstSegment = Math.Max(0, firstSegment);
        if (lastSegment < 0) return null;
        if (firstSegment > lastSegment) return null;

        var first = path[firstSegment];
        var bestX = first.X;
        var bestY = first.Y;
        var bestDx = bestX - x;
        var bestDy = bestY - y;
        var bestDistanceSquared = (long)bestDx * bestDx + (long)bestDy * bestDy;
        var bestSegmentIndex = -1;
        for (var index = firstSegment; index <= lastSegment; index++)
        {
            var start = path[index];
            var end = path[index + 1];
            var dx = start.X - end.X;
            var dy = start.Y - end.Y;
            var lengthSquared = MathF.FusedMultiplyAdd(dy, dy, (float)dx * dx);
            if (lengthSquared == 0f) continue;

            var numerator = MathF.FusedMultiplyAdd(y - end.Y, dy, (float)(x - end.X) * dx);
            var amount = Math.Clamp(numerator / lengthSquared, 0f, 1f);
            var projectedX = (int)MathF.FusedMultiplyAdd(amount, dx, end.X);
            var projectedY = (int)MathF.FusedMultiplyAdd(amount, dy, end.Y);
            var projectedDx = projectedX - x;
            var projectedDy = projectedY - y;
            var distanceSquared = (long)projectedDx * projectedDx + (long)projectedDy * projectedDy;
            if (distanceSquared >= bestDistanceSquared) continue;
            bestDistanceSquared = distanceSquared;
            bestX = projectedX;
            bestY = projectedY;
            bestSegmentIndex = index;
        }

        return (bestX, bestY, bestSegmentIndex);
    }

    internal static int FTileIntegerCoordinate(float coordinate) => (int)(coordinate + 0.5f);

    internal static int TickRootIntegerCoordinate(float coordinate) => (int)coordinate;

    internal static void TickStandingStartRootInterpolation(SimulationWorld world, XPerson person)
    {
        var startSkill = person.AnimatorControlState switch
        {
            6 => 19,
            11 => 22,
            _ => -1,
        };
        if (startSkill < 0 || person.NativeRoute is not { } route || route.MotionAnimationIndex != startSkill ||
            route.StartRootOriginX is not { } originX || route.StartRootOriginY is not { } originY ||
            route.StartRootTargetX is not { } targetX || route.StartRootTargetY is not { } targetY)
            return;
        var sampleCount = ResolveWalkAnimation(world, person, startSkill)?.StandardRootMotionSamples?.Count ?? 0;
        if (sampleCount <= 0) return;
        var phase = route.MotionPracticeFrame / sampleCount;
        if (phase >= 1f) return;
        var rootX = originX + (targetX - originX) * phase;
        var rootY = originY + (targetY - originY) * phase;
        person.AnimatorRootX = rootX;
        person.AnimatorRootY = rootY;
        person.NativeRoute = route with { MotionX = rootX, MotionY = rootY };
    }

    internal static (float LocalX, float LocalZ) StandingAdjustLocalStepFtiles(AvatarAnimationClip clip,
        float bodyScale = 1f)
    {
        var scale = float.IsFinite(bodyScale) && bodyScale > 0f ? bodyScale : 1f;
        if (clip.StandardRootMotionSamples is { Count: > 1 } samples)
        {
            var delta = samples[^1] - samples[0];
            if (MathF.Abs(delta.X) > 0.0001f || MathF.Abs(delta.Z) > 0.0001f)
                return (delta.X * scale, delta.Z * scale);
        }
        const float lotUnitsPerSkillUnit = 16f / 3f;
        return (clip.StandardOffset.X * lotUnitsPerSkillUnit * scale,
                clip.StandardOffset.Z * lotUnitsPerSkillUnit * scale);
    }

    internal static (float X, float Y) TurnRootTarget(float targetX, float targetY, float facingAngle,
        float localStepFtilesX, float localStepFtilesZ)
    {
        var cosine = MathF.Cos(facingAngle);
        var sine = MathF.Sin(facingAngle);
        var lotStepX = -localStepFtilesX * sine + localStepFtilesZ * cosine;
        var lotStepY = localStepFtilesX * cosine + localStepFtilesZ * sine;
        return (targetX - lotStepX, targetY - lotStepY);
    }

    internal static bool HasExplicitArrivalHeading(RouteState route) =>
        route.LookTowardsHeading is not null ||
        (!route.LookTowardsFollow && !route.DirectPositionRequest && route.Slot.Facing != -3);

    private static void CommitArrivalHeading(XPerson person, RouteState route)
    {
        var heading = HasExplicitArrivalHeading(route)
            ? ArrivalHeading(route)
            : QuantizeRootDirection(person.AnimatorRootDirection ?? person[ObjectData.Direction]);
        person[ObjectData.Direction] = SimsEngine.Character.AvatarDirection.ToObjectDirection(heading);
        person.AnimatorRootDirection = heading;
    }

    internal static float ArrivalHeading(RouteState route)
    {
        if (route.LookTowardsFollow)
            return route.LookTowardsHeading ?? route.ArrivalFacing;
        if (!route.DirectPositionRequest && route.Slot.Facing != -3)
            return route.ArrivalFacing;
        if (route.MotionPath is { Count: >= 2 } path)
        {
            var last = path[^1];
            var previous = path[^2];
            var dx = last.X - previous.X;
            var dy = last.Y - previous.Y;
            if (dx != 0 || dy != 0) return SimsEngine.Character.AvatarDirection.Toward(dx, dy);
        }
        return route.ArrivalFacing;
    }
}
