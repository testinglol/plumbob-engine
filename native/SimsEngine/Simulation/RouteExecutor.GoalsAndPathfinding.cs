using SimsEngine.Formats;
using System.Buffers;

namespace SimsEngine.Simulation;

internal static partial class RouteExecutor
{

    internal static SelectedRouteGoal? SelectDestination(SimulationWorld world, XPerson person, XObject anchor,
        RoutingSlotRequest slot, TreeStack? stack = null)
    {
        var orientation = (slot.Flags & 0x0200) != 0 ? (short)0 : anchor[ObjectData.Direction];
        var center = LotGeometry.SlotPosition(RouteAnchorOrigin(world, anchor, slot), orientation, slot.X, slot.Y);
        if ((slot.Flags & 0xff) == 0 || slot.SnapTargetSlot >= 0)
        {
            var exact = slot.SnapTargetSlot >= 0 ? anchor.Position : center;
            var accepted = Walkable(world, person, anchor, exact, slot, stack: stack);
            TraceCandidate(world, person, anchor, exact, accepted, slot.Flags);
            return accepted ? new SelectedRouteGoal(exact, orientation) : null;
        }

        var candidates = AuthoredRouteSlotCandidates(world, person, anchor, center, slot, orientation);
        var capacity = AuthoredRouteCandidateCapacity(world, person);
        var placeable = new List<RouteGoalCandidate>(capacity);
        foreach (var candidate in candidates)
        {
            if (!Walkable(world, person, anchor, candidate.Position, slot, stack: stack,
                    candidateSector: candidate.SearchDirection))
            {
                TraceCandidate(world, person, anchor, candidate.Position, false, slot.Flags);
                continue;
            }

            placeable.Add(candidate);
            TraceCandidate(world, person, anchor, candidate.Position, true, slot.Flags);
        }

        var routeCandidates = SampleRouteCandidates(world, placeable, capacity);
        RouteGoalCandidate? bestGoal = null;
        RouteGoalCandidate? bestCrossFloorGoal = null;
        var bestPathCost = double.PositiveInfinity;
        var bestCrossFloorRouteCost = double.PositiveInfinity;
        Dictionary<(ushort CurrentRoom, ushort DestinationRoom), (XObject? Portal, float Cost)>? portalCache = null;
        FloorPartition? floorPartition = null;
        var floorPartitionAttempted = false;
        foreach (var candidate in routeCandidates)
        {
            if (candidate.Position.Height != person.Position.Height)
            {
                var currentRoom = unchecked((ushort)person.RoomWord84);
                var destinationRoom = PortalRoomKey(anchor);
                if (currentRoom == SimsEngine.World.RoomMap.NoRoom ||
                    destinationRoom == SimsEngine.World.RoomMap.NoRoom) continue;
                portalCache ??= new Dictionary<(ushort, ushort), (XObject? Portal, float Cost)>();
                var roomPair = (currentRoom, destinationRoom);
                if (!portalCache.TryGetValue(roomPair, out var portalPreview))
                {
                    portalPreview = PreviewPortalForDestination(world, person, anchor, currentRoom, destinationRoom);
                    portalCache[roomPair] = portalPreview;
                }
                var (selectedPortal, portalRouteCost) = portalPreview;
                if (selectedPortal is null) continue;
                if (portalRouteCost < bestCrossFloorRouteCost ||
                    (portalRouteCost == bestCrossFloorRouteCost &&
                     (bestCrossFloorGoal is null || candidate.Cost > bestCrossFloorGoal.Value.Cost)))
                {
                    bestCrossFloorGoal = candidate;
                    bestCrossFloorRouteCost = portalRouteCost;
                }
                continue;
            }
            if (!floorPartitionAttempted)
            {
                floorPartitionAttempted = true;
                floorPartition = TryBuildFloorPartition(world, person, anchor, allowCrossRoom: true, stack: stack);
            }
            if (floorPartition is not null &&
                TryPathWithPartition(floorPartition, candidate.Position, out _, out var pathCost))
            {
                if (pathCost < bestPathCost ||
                    (pathCost == bestPathCost && (bestGoal is null || candidate.Cost > bestGoal.Value.Cost)))
                {
                    bestGoal = candidate;
                    bestPathCost = pathCost;
                }
            }
        }

        if (bestGoal is { } selectedGoal)
            return new SelectedRouteGoal(selectedGoal.Position, selectedGoal.SearchDirection,
                selectedGoal.EntryFlags, selectedGoal.ChairObjectId);
        if (bestCrossFloorGoal is { } selectedCrossFloorGoal)
            return new SelectedRouteGoal(selectedCrossFloorGoal.Position, selectedCrossFloorGoal.SearchDirection,
                selectedCrossFloorGoal.EntryFlags, selectedCrossFloorGoal.ChairObjectId);
        if (placeable.Count != 0) world.LastRouteCandidateFailureReason = "authored candidates have no route path";
        return null;
    }

    private static (XObject? Portal, float Cost) PreviewPortalForDestination(SimulationWorld world,
        XPerson person, XObject destination, ushort currentRoom, ushort destinationRoom)
    {
        var savedPersonRouteId = person[ObjectData.RouteId];
        var portals = Portals(world).ToArray();
        var savedPortalState = new (short RouteId, KeyValuePair<short, float>[] Costs)[portals.Length];
        for (var i = 0; i < portals.Length; i++)
        {
            var portal = portals[i];
            savedPortalState[i] = (portal[ObjectData.RouteId], portal.PortalRouteCosts.ToArray());
        }
        try
        {
            var routeId = person[ObjectData.RouteId];
            if (routeId == 0) routeId = world.InitializePortalRouteCosts(person);
            if (routeId <= 0) return (null, float.PositiveInfinity);

            foreach (var portal in portals)
                portal.SetPortalRouteCost(routeId, XObject.UninitializedPortalRouteCost);
            var selected = SelectPortalForDestination(world, person, destination, currentRoom,
                destinationRoom, recordTrace: false);
            return (selected, selected?.PortalRouteCostAt(routeId) ?? float.PositiveInfinity);
        }
        finally
        {
            person[ObjectData.RouteId] = savedPersonRouteId;
            for (var i = 0; i < portals.Length; i++)
            {
                var portal = portals[i];
                var (routeId, costs) = savedPortalState[i];
                portal[ObjectData.RouteId] = routeId;
                portal.PortalRouteCosts.Clear();
                foreach (var (id, cost) in costs) portal.PortalRouteCosts.Add(id, cost);
            }
        }
    }

    private static IReadOnlyList<RouteGoalCandidate> SampleRouteCandidates(
        SimulationWorld world, IReadOnlyList<RouteGoalCandidate> candidates, int capacity)
    {
        if (candidates.Count <= capacity) return candidates;

        var selected = new List<RouteGoalCandidate>(capacity);
        var consumed = new bool[candidates.Count];
        for (var attempt = 0; attempt < capacity; attempt++)
        {
            var index = (int)(world.NextRandom() % (uint)candidates.Count);
            while (index < candidates.Count && consumed[index]) index++;
            if (index == candidates.Count) continue;
            consumed[index] = true;
            selected.Add(candidates[index]);
        }
        return selected;
    }

    internal static int AuthoredRouteCandidateCapacity(SimulationWorld world, XPerson person)
    {
        var position = person.Position;
        if (world.HasRoomRecord(person.RoomWord84) && world.LotRoomMaps.TryGetValue(position.Height, out var map))
        {
            var room = unchecked((ushort)person.RoomWord84);
            if (map.RoomHalfArea(room, world.RoomIsOutside(person.RoomWord84)) > 250) return 8;
        }
        return 48;
    }

    private static List<RouteGoalCandidate> AuthoredRouteSlotCandidates(
        SimulationWorld world, XPerson person, XObject anchor, ObjectPosition center, RoutingSlotRequest slot,
        short orientation)
    {
        var results = new List<RouteGoalCandidate>();
        if (slot.MinProximity is < 1 or > 512 || slot.MaxProximity is < 1 or > 512 ||
            slot.MinProximity > slot.OptimalProximity || slot.OptimalProximity > slot.MaxProximity ||
            slot.Resolution <= 0)
        {
            world.LastRouteCandidateFailureReason = "invalid authored route-slot range or resolution";
            return results;
        }

        var petActor = person[PersonData.Gender] > 1;
        var sittingScore = !petActor && slot.Sitting > 0 ? slot.Sitting * 10d : 0d;
        var effectiveStanding = petActor && slot.Sitting > 0 && slot.Standing == 0 ? 1 : slot.Standing;
        var floorPreference = Math.Max(effectiveStanding, slot.Ground) * 10d;
        var allowStanding = floorPreference > 0d || sittingScore <= 0d;
        var resolution = sittingScore > 0d ? 16 : slot.Resolution;

        var directionMask = slot.Flags & 0xff;
        // Widen bounds by 1 tile for sitting so approach tiles around boundary chairs are scanned.
        var minY = (int)Math.Round(-(double)slot.MinProximity / resolution, MidpointRounding.ToEven);
        var maxY = (int)Math.Round(-(double)slot.MaxProximity / resolution, MidpointRounding.ToEven);
        if (sittingScore > 0d)
        {
            maxY -= 1;
            minY = Math.Min(-1, minY + 1);
        }
        var radiusMinimumSquared = (long)slot.MinProximity * slot.MinProximity;
        var radiusMaximumSquared = (long)slot.MaxProximity * slot.MaxProximity;
        var wallMask = 0u;
        if ((slot.Flags & BypassWallsAndRoomsFlag) == 0 && (slot.Flags & 0x0400) == 0 && world.LotRoomMaps.TryGetValue(center.Height, out var roomMap))
        {
            var worldWallMask = RouteMaskAt(world, roomMap, anchor.Position.X, anchor.Position.Y);
            var rotation = orientation & 7;
            wallMask = rotation == 0
                ? worldWallMask
                : ((worldWallMask >> rotation) | (worldWallMask << (8 - rotation))) & 0xff;
        }

        double ScoreCandidate(long distanceSquared, double posturePreference, int wallSector, ObjectPosition bonusTarget)
        {
            var radius = Math.Sqrt(distanceSquared);
            var roundedRadius = Math.Round(radius, MidpointRounding.ToEven);
            var gradientPenalty = Math.Round(
                Math.Abs(roundedRadius - slot.OptimalProximity) * slot.Gradient,
                MidpointRounding.ToEven);
            var score = 100d + posturePreference - gradientPenalty;
            if ((slot.Flags & 0x2000) != 0) score += -10 + (int)(world.NextRandom() % 20);
            var wallSectorAndNeighbors = (1u << wallSector) |
                (1u << ((wallSector + 1) & 7)) | (1u << ((wallSector + 7) & 7));
            if ((wallMask & wallSectorAndNeighbors) == 0) score += 25;
            if (bonusTarget.X == person.Position.X && bonusTarget.Y == person.Position.Y &&
                bonusTarget.Height == person.Position.Height) score += 20;
            return score;
        }

        for (var localSector = 0; localSector < 8; localSector++)
        {
            if ((directionMask & (1u << localSector)) == 0) continue;
            if ((wallMask & (1u << localSector)) != 0) continue;
            var worldSector = (orientation + localSector) & 7;
            var expectedChairDirection = (worldSector + 4) & 7;
            var candidateDirectionBit = 1u << ((localSector + 2) & 7);
            for (var localY = minY; localY >= maxY; localY--)
            {
                // Trim row upper bound when sector (localSector + 2) is enabled so shared boundaries are evaluated once.
                var startX = localY;
                var endX = -localY - ((directionMask & candidateDirectionBit) != 0 ? 1 : 0);
                for (var localX = startX; localX <= endX; localX++)
                {
                    var offsetX = localX * resolution;
                    var offsetY = localY * resolution;
                    var standPos = LotGeometry.SlotPosition(center, (short)worldSector, offsetX, offsetY);

                    bool TryEmitStanding()
                    {
                        if (!allowStanding) return false;
                        var radiusSquared = (long)offsetX * offsetX + (long)offsetY * offsetY;
                        if (radiusSquared < radiusMinimumSquared || radiusSquared > radiusMaximumSquared) return false;
                        var score = ScoreCandidate(radiusSquared, floorPreference, localSector, standPos);
                        results.Add(new RouteGoalCandidate(standPos, score, (short)worldSector,
                            LocalSectorEntryFlags((short)worldSector, orientation)));
                        return true;
                    }

                    bool TryEmitChair()
                    {
                        if (sittingScore <= 0d) return false;
                        for (var chairSide = 0; chairSide < 8; chairSide++)
                        {
                            var step = LotGeometry.FootprintOffset((short)chairSide);
                            var chairLocalX = offsetX + step.X;
                            var chairLocalY = offsetY + step.Y;
                            var chairTileLocalX = chairLocalX >> 4;
                            var chairTileLocalY = chairLocalY >> 4;
                            var inCone = chairTileLocalY == localY
                                ? localY <= chairTileLocalX && chairTileLocalX <= endX
                                : chairTileLocalY <= localY || (localY < chairTileLocalX && chairTileLocalX < endX);
                            if (!inCone) continue;

                            var chairPos = LotGeometry.SlotPosition(center, (short)worldSector, chairLocalX, chairLocalY);
                            var chairTileX = chairPos.X >> 4;
                            var chairTileY = chairPos.Y >> 4;
                            if (chairTileX <= 0 || chairTileY <= 0 ||
                                chairTileX >= LotGeometry.LotDimension - 1 || chairTileY >= LotGeometry.LotDimension - 1)
                                continue;

                            var chair = FindChairAtTile(world, chairTileX, chairTileY, anchor.Position.Height);
                            if (chair is null || (chair[ObjectData.Direction] & 7) != expectedChairDirection) continue;
                            var chairEntryMask = unchecked((ushort)chair.Definition[(int)Formats.ObjdField.ChairEntryFlags]);
                            var entryBit = (short)(1 << chairSide);
                            if ((chairEntryMask & (ushort)entryBit) == 0) continue;

                            if (chair.FootprintSlots.Count > 0)
                            {
                                var occupantKey = chair.FootprintSlots[0].OccupantObjectId;
                                if (occupantKey > 0 && occupantKey != person.ClockManagerIndex &&
                                    world.ObjectTableEntry(occupantKey) is { } occupant && !ReferenceEquals(occupant, person))
                                {
                                    person[ObjectData.PrimitiveResultId] = occupant.ClockManagerIndex;
                                    continue;
                                }
                            }

                            var chairRadiusSquared = (long)chairLocalX * chairLocalX + (long)chairLocalY * chairLocalY;
                            if (chairRadiusSquared < radiusMinimumSquared || chairRadiusSquared > radiusMaximumSquared)
                                continue;

                            var score = ScoreCandidate(chairRadiusSquared, sittingScore, localSector, chairPos);
                            results.Add(new RouteGoalCandidate(standPos, score, (short)worldSector,
                                EntryFlags: entryBit, ChairObjectId: chair.Id));
                            return true;
                        }
                        return false;
                    }

                    if (floorPreference >= sittingScore)
                    {
                        if (!TryEmitStanding()) TryEmitChair();
                    }
                    else
                    {
                        if (!TryEmitChair()) TryEmitStanding();
                    }
                }
            }
        }

        return results;
    }

    private static XObject? FindChairAtTile(SimulationWorld world, int tileX, int tileY, int level)
    {
        var effectiveLevel = level == 0 ? 1 : level;
        try
        {
            foreach (var candidate in world.ObjectsAtTile(tileX, tileY, effectiveLevel))
            {
                if (candidate is XPerson) continue;
                if (candidate[ObjectData.ParentId] != 0 && candidate[ObjectData.SlotHierNumber] != 0) continue;
                var flags = unchecked((ushort)candidate[ObjectData.Flags]);
                var skip = (flags & 4) == 0 ? (flags & 0x10) != 0 : (flags & 2) == 0;
                if (skip) continue;
                return SimulationWorld.HasFunction(candidate, 0x1a) ? candidate : null;
            }
        }
        catch (InvalidDataException)
        {
        }
        return null;
    }

    private static bool IsSeatedChairMatchingSlot(SimulationWorld world, XPerson person, XObject anchor,
        RoutingSlotRequest slot, XObject seat, out short matchedWorldSector)
    {
        matchedWorldSector = seat[ObjectData.Direction];
        if (slot.Sitting <= 0 || person[PersonData.Gender] >= 2 || (slot.Flags & 0xff) == 0 || slot.SnapTargetSlot >= 0)
            return false;
        if (slot.MinProximity is < 1 or > 512 || slot.MaxProximity is < 1 or > 512) return false;
        var orientation = (slot.Flags & 0x0200) != 0 ? (short)0 : anchor[ObjectData.Direction];
        var center = LotGeometry.SlotPosition(RouteAnchorOrigin(world, anchor, slot), orientation, slot.X, slot.Y);
        var minR2 = (long)slot.MinProximity * slot.MinProximity;
        var maxR2 = (long)slot.MaxProximity * slot.MaxProximity;
        var minY = Math.Min(-1, (int)Math.Round(-(double)slot.MinProximity / 16d, MidpointRounding.ToEven));
        var maxY = (int)Math.Round(-(double)slot.MaxProximity / 16d, MidpointRounding.ToEven);
        var directionMask = slot.Flags & 0xff;
        for (var localSector = 0; localSector < 8; localSector++)
        {
            if ((directionMask & (1u << localSector)) == 0) continue;
            var worldSector = (short)((orientation + localSector) & 7);
            if ((seat[ObjectData.Direction] & 7) != ((worldSector + 4) & 7)) continue;
            var candidateDirectionBit = 1u << ((localSector + 2) & 7);
            for (var localY = minY; localY >= maxY; localY--)
            {
                var endX = -localY - ((directionMask & candidateDirectionBit) != 0 ? 1 : 0);
                for (var localX = localY; localX <= endX; localX++)
                {
                    var ox = localX * 16;
                    var oy = localY * 16;
                    var r2 = (long)ox * ox + (long)oy * oy;
                    if (r2 < minR2 || r2 > maxR2) continue;
                    var projected = LotGeometry.SlotPosition(center, worldSector, ox, oy);
                    if ((projected.X >> 4) == (seat.Position.X >> 4) &&
                        (projected.Y >> 4) == (seat.Position.Y >> 4) &&
                        projected.Height == seat.Position.Height)
                    {
                        matchedWorldSector = worldSector;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private static uint RouteMaskAt(SimulationWorld world, SimsEngine.World.RoomMap map, int worldX, int worldY)
    {
        var x = worldX >> 4;
        var y = worldY >> 4;
        if ((uint)x >= map.Width || (uint)y >= map.Height) return 0;
        var mask = 0u;
        for (var direction = 0; direction < 8; direction++)
        {
            if (world.BlocksRouteDirectionAt(map, x, y, direction)) mask |= 1u << direction;
        }
        return mask;
    }

    private static void TraceCandidate(SimulationWorld world, XPerson person, XObject anchor,
        ObjectPosition candidate, bool accepted, uint slotFlags)
    {
        if (!world.CaptureExecutionTrace) return;
        world.RouteCandidateTrace.Add(new SimulationRouteCandidateTrace(person.Id, anchor.Id,
            candidate, RoomKeyAt(world, candidate), anchor[ObjectData.Direction], accepted,
            world.LastPlacementFailureCode, person[ObjectData.PrimitiveResultId], accepted,
            $"{world.LastRouteCandidateFailureReason}; slotFlags=0x{slotFlags:X}"));
    }

    private static bool Walkable(SimulationWorld world, XPerson person, XObject anchor, ObjectPosition position,
        RoutingSlotRequest? destinationSlot = null, bool writeCandidateResults = true, TreeStack? stack = null,
        short? candidateSector = null)
    {
        var accepted = IsWalkableCandidate(world, person, anchor, position, destinationSlot, stack, out var blockerId,
            candidateSector: candidateSector);
        if (writeCandidateResults)
        {
            person[ObjectData.PrimitiveResultId] = blockerId;
            person[ObjectData.PrimitiveResult] = 0;
        }
        return accepted;
    }

    private static bool IsWalkableCandidate(SimulationWorld world, XPerson person, XObject anchor, ObjectPosition position,
        RoutingSlotRequest? destinationSlot, TreeStack? stack, out short blockerId, short? candidateSector = null)
    {
        world.LastRouteCandidateFailureReason = string.Empty;
        world.LastPlacementBlockingObjectId = 0;
        blockerId = 0;
        if (!world.LotRoomMaps.TryGetValue(position.Height, out var map))
        {
            world.LastRouteCandidateFailureReason = "missing route map";
            return false;
        }
        var x = position.X >> 4;
        var y = position.Y >> 4;
        // Portal anchors can sit on perimeter sidewalk tiles outside normal inner lot bounds.
        var isPortalAnchor = unchecked((uint)(anchor.TypeRecord?.Key ?? 0)) == 0x81E6BEF9 || anchor.RuntimeClass == Formats.ObjectClass.Portal;
        var bypassRouteEdgeChecks = (destinationSlot is not null && (destinationSlot.Flags & BypassWallsAndRoomsFlag) != 0) || isPortalAnchor;
        if (!bypassRouteEdgeChecks && (x < 1 || y < 1 || x >= map.Width - 1 || y >= map.Height - 1))
        {
            world.LastRouteCandidateFailureReason = "outside routable tile bounds";
            return false;
        }
        if (x < 0 || y < 0 || x >= map.Width || y >= map.Height)
        {
            world.LastRouteCandidateFailureReason = "outside map tile bounds";
            return false;
        }
        var room = map.RoomAtPosition(position.X, position.Y);
        if (!bypassRouteEdgeChecks && room == SimsEngine.World.RoomMap.NoRoom)
        {
            world.LastRouteCandidateFailureReason = "no room at candidate";
            return false;
        }
        var anchorOrigin = destinationSlot is not null ? RouteAnchorOrigin(world, anchor, destinationSlot) : anchor.Position;
        var anchorTileX = anchorOrigin.X >> 4;
        var anchorTileY = anchorOrigin.Y >> 4;
        var personPosition = person.Position;
        var currentTileX = personPosition.X >> 4;
        var currentTileY = personPosition.Y >> 4;
        var currentRoom = unchecked((ushort)person.RoomWord84);
        if (destinationSlot is not null && (destinationSlot.Flags & BypassWallsAndRoomsFlag) == 0 && (destinationSlot.Flags & 0x0400) == 0)
        {
            if (ReferenceEquals(anchor, person))
            {
                if (room == currentRoom && (position.X != personPosition.X || position.Y != personPosition.Y))
                {
                    var direction = DirectionToWaypoint((personPosition.X, personPosition.Y), (position.X, position.Y));
                    var reverseDirection = (direction + 4) & 7;
                    var fromBlocked = world.BlocksRouteDirectionAt(map, currentTileX, currentTileY, direction);
                    var toBlocked = world.BlocksRouteDirectionAt(map, x, y, reverseDirection);
                    if (fromBlocked || toBlocked)
                    {
                        world.LastRouteCandidateFailureReason = world.CaptureExecutionTrace
                            ? $"same-room route edge blocked; from={RouteBlockDetails(world, map, currentTileX, currentTileY, direction, fromBlocked)}; to={RouteBlockDetails(world, map, x, y, reverseDirection, toBlocked)}"
                            : "same-room route edge blocked";
                        return false;
                    }
                }
            }
            else
            {
                var anchorRoom = PortalRoomKey(anchor);
                var radialSlot = (destinationSlot.Flags & 0xff) != 0;
                if (radialSlot && !isPortalAnchor && anchor.TypeRecord?.ObjectType != 8 &&
                    anchorRoom != SimsEngine.World.RoomMap.NoRoom && anchorRoom != unchecked((ushort)-5) &&
                    room != anchorRoom)
                {
                    world.LastRouteCandidateFailureReason = $"candidate room {room} does not match target room {anchorRoom}";
                    return false;
                }
                if (room == anchorRoom && (x != anchorTileX || y != anchorTileY))
                {
                    var direction = candidateSector ?? DirectionToWaypoint((anchorOrigin.X, anchorOrigin.Y), (position.X, position.Y));
                    var reverseDirection = (direction + 4) & 7;
                    var fromBlocked = !radialSlot && world.BlocksRouteDirectionAt(map, anchorTileX, anchorTileY, direction);
                    var toBlocked = world.BlocksRouteDirectionAt(map, x, y, reverseDirection);
                    var diagonalCornerBlocked = (direction & 1) != 0 &&
                        (world.BlocksRouteDirectionAt(map, x, y, (reverseDirection + 1) & 7) ||
                         world.BlocksRouteDirectionAt(map, x, y, (reverseDirection + 7) & 7));
                    if (fromBlocked || toBlocked || diagonalCornerBlocked)
                    {
                        world.LastRouteCandidateFailureReason = world.CaptureExecutionTrace
                            ? $"same-room route edge blocked; from={RouteBlockDetails(world, map, anchorTileX, anchorTileY, direction, fromBlocked)}; to={RouteBlockDetails(world, map, x, y, reverseDirection, toBlocked)}; diagonalCornerBlocked={diagonalCornerBlocked}"
                            : "same-room route edge blocked";
                        return false;
                    }
                }
            }
        }
        var placementAccepted = destinationSlot is { SnapTargetSlot: >= 0 } snappedSlot
            ? world.CanPlaceRouteCandidate(person, position, anchor, snappedSlot.SnapTargetSlot)
            // Non-snap validation omits anchor so non-solid markers (Flags & 0x04) do not fail with 0x0C.
            : world.CanPlaceObject(person, position, stack);
        if (!placementAccepted)
        {
            if (world.CaptureExecutionTrace)
            {
                var referenceSlot = destinationSlot?.SnapTargetSlot ?? -1;
                var referencedHeightCode = referenceSlot >= 0 && referenceSlot < anchor.FootprintSlots.Count
                    ? anchor.FootprintSlots[referenceSlot].HeightCode
                    : (byte)0;
                world.LastRouteCandidateFailureReason =
                    $"person placement callback rejected candidate (error=0x{world.LastPlacementFailureCode:X2}; referenceSlot={referenceSlot}; heightCode={referencedHeightCode}; allowedHeight=0x{unchecked((ushort)person[ObjectData.AllowedHeightFlags]):X4}; overlapObject={world.LastPlacementBlockingObjectId})";
            }
            else
            {
                world.LastRouteCandidateFailureReason = "person placement callback rejected candidate";
            }
            blockerId = world.LastPlacementBlockingObjectId != 0
                ? world.LastPlacementBlockingObjectId
                : BlockingRootObjectId(world, person, anchor, x, y, position.Height);
            return false;
        }

        if (destinationSlot is { CheckCandidateFootprintAgainstWall: true })
        {
            var originalDirection = person[ObjectData.Direction];
            person[ObjectData.Direction] = CandidateValidationDirection(person, anchor, destinationSlot);
            bool intersectsWall;
            try
            {
                intersectsWall = world.FootprintIntersectsWall(
                    person.FootprintBoundsAt(position), position.Height);
            }
            finally
            {
                person[ObjectData.Direction] = originalDirection;
            }
            if (intersectsWall)
            {
                world.LastRouteCandidateFailureReason = "arrival footprint intersects a wall";
                return false;
            }
        }

        return true;
    }

    private static string RouteBlockDetails(SimulationWorld world, SimsEngine.World.RoomMap map, int x, int y,
        int direction, bool blocked)
    {
        if (!blocked) return "open";
        uint objectMask;
        try
        {
            objectMask = world.ObjectsAtTile(x, y, map.Level).Aggregate(0u, (mask, item) =>
            {
                var flags = unchecked((uint)(ushort)item[ObjectData.WallBlockFlags]);
                var rotated = flags << (unchecked((byte)item[ObjectData.Direction]) & 0x1f);
                return mask | ((rotated & 0xff) | ((rotated >> 8) & 0xff));
            });
        }
        catch (InvalidDataException)
        {
            return $"direction={direction},static=0x{map.RouteBlockingMaskAt(x, y):X2},objects=cycle";
        }
        return $"direction={direction},static=0x{map.RouteBlockingMaskAt(x, y):X2},objects=0x{objectMask:X2}";
    }

    private static short BlockingRootObjectId(SimulationWorld world, XPerson person, XObject anchor, int x, int y,
        int height)
    {
        var occupant = world.TileValueAt(x, y, height);
        var personKey = person.HasRequestKey ? person.RequestKey : person.ClockManagerIndex;
        var anchorKey = anchor.HasRequestKey ? anchor.RequestKey : anchor.ClockManagerIndex;
        if (occupant == 0 || occupant == personKey || occupant == anchorKey) return 0;
        var tableCandidate = occupant is > 0 and <= short.MaxValue ? world.ObjectTableEntry((short)occupant) : null;
        var blocker = tableCandidate is not null &&
            tableCandidate.Position.Height == height &&
            (tableCandidate.Position.X >> 4) == x &&
            (tableCandidate.Position.Y >> 4) == y &&
            (tableCandidate.HasRequestKey ? tableCandidate.RequestKey : tableCandidate.ClockManagerIndex) == occupant
            ? tableCandidate
            : world.WalkOrder.FirstOrDefault(candidate => candidate.Position.Height == height &&
                (candidate.Position.X >> 4) == x && (candidate.Position.Y >> 4) == y &&
                (candidate.HasRequestKey ? candidate.RequestKey : candidate.ClockManagerIndex) == occupant);
        if (blocker is null || blocker.RuntimeClass == SimsEngine.Formats.ObjectClass.Portal) return 0;
        return blocker.ClockManagerIndex;
    }

    internal static void AskPeopleOnRouteToMove(SimulationWorld world, XPerson requester, XObject anchor,
        IReadOnlyList<RouteWaypoint> path)
    {
        if (requester[PersonData.Sitting] != 0) return;
        var map = world.LotRoomMaps.GetValueOrDefault(requester.Position.Height);
        if (map is null) return;

        var reqLevel = requester.Position.Height;
        var reqRoom = unchecked((ushort)requester.RoomWord84);
        List<(XPerson Other, short CrossingDirection)>? blockers = null;
        for (var i = 0; i < world.WalkOrder.Count; i++)
        {
            if (world.WalkOrder[i] is not XPerson other) continue;
            if (ReferenceEquals(other, requester) || ReferenceEquals(other, anchor) ||
                other[PersonData.Sitting] != 0 ||
                other.Position.Height != reqLevel ||
                unchecked((ushort)other.RoomWord84) != reqRoom ||
                other.NativeRoute is not null ||
                GetDistanceToPrimitive.DistanceBetween(requester, other) > 3.0 ||
                world.ResolveParentContainer(other) is not null ||
                HasMoveAsideAction(other))
                continue;

            if (RouteCrossingDirection(other, path) is not { } crossingDirection)
                continue;

            blockers ??= [];
            blockers.Add((other, crossingDirection));
        }

        if (blockers is null) return;

        foreach (var (other, crossingDirection) in blockers)
        {
            var guid = 0x7c4;
            var aside = world.ObjectFactory?.Invoke(guid);
            if (aside is null) continue;

            var added = false;
            try
            {
                world.Add(aside);
                added = true;
                world.InitializeCreatedObject(aside);
                world.SetObjectPosition(aside, other.Position);

                var direction = crossingDirection;
                var firstDirection = (direction + 2) & 7;
                var secondDirection = (direction + 6) & 7;
                var moveSlot = new RoutingSlotRequest
                {
                    Flags = 0x2100u | (1u << firstDirection) | (1u << secondDirection),
                    MinProximity = 16,
                    MaxProximity = 80,
                    OptimalProximity = 16,
                    Standing = 1,
                    Facing = -3,
                };
                aside.RoutingSlots.Insert(0, moveSlot);
                if (SelectDestination(world, other, aside, moveSlot) is null)
                {
                    moveSlot.Flags |= 1u << (direction & 7);
                    moveSlot.OptimalProximity = 80;
                }

                var interaction = aside.TypeRecord?.Interactions?.Interactions
                    .FirstOrDefault(candidate => candidate.TtaIndex == 3);
                var priority = requester.ActivePriority != 0
                    ? requester.ActivePriority
                    : requester.CurrentActionRecord?.Threshold ?? 0;
                if (interaction is null || !world.EnqueueInteractionAction(other, aside, interaction, 3,
                        priority, null, secondarySpecified: false, recordFlags: 0))
                {
                    world.Remove(aside.Id);
                    continue;
                }
                added = false;
            }
            catch (Exception error) when (error is InvalidOperationException or ArgumentException)
            {
                if (added) world.Remove(aside.Id);
            }
        }
    }

    internal static bool MoveOutOfWay(SimulationWorld world, XPerson blocker, int priority)
    {
        if (HasMoveAsideAction(blocker)) return false;
        var aside = world.ObjectFactory?.Invoke(0x7c4);
        if (aside is null) return false;

        var added = false;
        try
        {
            world.Add(aside);
            added = true;
            world.InitializeCreatedObject(aside);
            world.SetObjectPosition(aside, blocker.Position);
            aside.RoutingSlots.Insert(0, new RoutingSlotRequest
            {
                Flags = 0x2100u | (1u << 0) | (1u << 2) | (1u << 4) | (1u << 6),
                MinProximity = 16,
                MaxProximity = 80,
                OptimalProximity = 16,
                Standing = 1,
                Facing = -3,
            });
            var interaction = aside.TypeRecord?.Interactions?.Interactions
                .FirstOrDefault(candidate => candidate.TtaIndex == 3);
            if (interaction is not null && world.EnqueueInteractionAction(blocker, aside, interaction, 3,
                    priority, null, secondarySpecified: false, recordFlags: 0))
                return true;
        }
        catch (Exception error) when (error is InvalidOperationException or ArgumentException)
        {
        }
        if (added) world.Remove(aside.Id);
        return false;
    }

    private static bool HasMoveAsideAction(XPerson person)
    {
        static bool IsMoveAside(ActionQueueSlot? action) =>
            action?.Owner is { } owner &&
            (owner.TypeRecord?.Key == 0x7c4 ||
             ((ushort)owner.Definition[(int)SimsEngine.Formats.ObjdField.Guid1] |
              ((uint)(ushort)owner.Definition[(int)SimsEngine.Formats.ObjdField.Guid2] << 16)) == 0x7c4u) &&
            (action.RawDword10 == 3 || action.Threshold == 3);

        if (IsMoveAside(person.CurrentActionRecord)) return true;
        for (var cursor = person.ActionQueueCurrent; cursor != person.ActionQueueEnd; cursor++)
            if (IsMoveAside(person.ActionQueue[cursor & 7])) return true;
        return false;
    }

    internal static short? RouteCrossingDirection(XPerson person, IReadOnlyList<RouteWaypoint> path)
    {
        var bounds = person.FootprintBounds;
        (int X, int Y)? entry = null;
        for (var segmentIndex = 0; segmentIndex + 1 < path.Count; segmentIndex++)
        {
            var start = path[segmentIndex];
            var end = path[segmentIndex + 1];
            var dx = end.X - start.X;
            var dy = end.Y - start.Y;
            var steps = Math.Max(1, Math.Max(Math.Abs(dx), Math.Abs(dy)));
            for (var sample = 0; sample <= steps; sample++)
            {
                var x = start.X + dx * (sample / (float)steps);
                var y = start.Y + dy * (sample / (float)steps);
                var sampleX = (int)x;
                var sampleY = (int)y;
                var inside = sampleX >= bounds.MinX && sampleX < bounds.MaxX &&
                             sampleY >= bounds.MinY && sampleY < bounds.MaxY;
                if (inside && entry is null)
                    entry = (sampleX, sampleY);
                else if (!inside && entry is { } first)
                    return DirectionToWaypoint(first, (sampleX, sampleY));
            }
        }
        if (entry is not { } only || path.Count <= 1)
            return null;
        var terminal = (path[^1].X, path[^1].Y);
        return only != terminal
            ? DirectionToWaypoint(only, terminal)
            : DirectionToWaypoint((path[^2].X, path[^2].Y), terminal);
    }

    private static bool SharesActiveRoute(SimulationWorld world, XPerson person, IReadOnlyList<RouteWaypoint> path)
    {
        if (person.NativeRoute is not { } otherRoute ||
            world.ObjectById(otherRoute.AnchorObjectId) is not { } otherAnchor ||
            !TryPath(world, person, otherRoute.Destination, otherAnchor, out var otherPath, out _,
                directPositionRequest: otherRoute.DirectPositionRequest, directSlot: otherRoute.Slot,
                allowCrossRoom: otherRoute.DirectPositionRequest)) return false;
        var requestCells = path.Skip(1).Select(point => (point.TileX, point.TileY)).ToHashSet();
        return otherPath.Skip(1).Any(point => requestCells.Contains((point.TileX, point.TileY)));
    }

    private static (int Index, (int X, int Y) Before, (int X, int Y) Point, (int X, int Y) After)
        ClosestRoutePoint(XPerson person, IReadOnlyList<RouteWaypoint> path)
    {
        var index = 1;
        var minimum = double.PositiveInfinity;
        for (var candidate = 1; candidate < path.Count; candidate++)
        {
            var dx = (long)path[candidate].X - person.Position.X;
            var dy = (long)path[candidate].Y - person.Position.Y;
            var distance = dx * dx + dy * dy;
            if (distance >= minimum) continue;
            minimum = distance;
            index = candidate;
        }
        var previous = path[Math.Max(0, index - 1)];
        var current = path[index];
        var next = path[Math.Min(path.Count - 1, index + 1)];
        return (index, (previous.X, previous.Y), (current.X, current.Y), (next.X, next.Y));
    }

    private static bool CanPlaceArrival(SimulationWorld world, XPerson person, XObject? anchor,
        RoutingSlotRequest slot, ObjectPosition position, TreeStack? stack)
    {
        var targetPosition = position with { Height = position.Height == 0 ? 1 : position.Height };
        if (world.CanPlaceObject(person, targetPosition, stack))
            return true;

        if (slot.SnapTargetSlot >= 0 && anchor is not null)
        {
            if (!world.CanPlaceRouteCandidate(person, targetPosition, anchor, slot.SnapTargetSlot))
                return false;

            var originalFlags = anchor[ObjectData.Flags];
            anchor[ObjectData.Flags] = (short)(originalFlags | 0x10);
            try
            {
                return world.CanPlaceObject(person, targetPosition, stack);
            }
            finally
            {
                anchor[ObjectData.Flags] = originalFlags;
            }
        }

        return false;
    }

    private static void ApplyRoutePlacement(SimulationWorld world, XPerson person, XObject anchor,
        ObjectPosition destination, RoutingSlotRequest slot, TreeStack? stack)
    {
        if (slot.SnapTargetSlot >= 0)
            // Converts the zero-based slot definition index to a one-based container relationship index.
            world.PlaceObject(person, destination, stack, anchor, checked((short)(slot.SnapTargetSlot + 1)));
        else
            world.PlaceObject(person, destination, stack);
        world.RefreshPersonRoomStateAfterMovement(person);
    }

    private static XObject? ResolveSeatedContainer(SimulationWorld world, XPerson person)
    {
        var containerKey = person[ObjectData.ContainerId];
        if (containerKey > 0)
        {
            if (person.ObjectTableEntry(containerKey) is { } fromPersonTable && !ReferenceEquals(fromPersonTable, person))
                return fromPersonTable;
            if (world.ObjectTableEntry(containerKey) is { } fromWorldTable && !ReferenceEquals(fromWorldTable, person))
                return fromWorldTable;
            if (world.ObjectById(containerKey) is { } fromId && !ReferenceEquals(fromId, person))
                return fromId;
        }
        return world.ResolveParentContainer(person);
    }

    private static bool TryPushSeatedStandTree(SimulationWorld world, XPerson person, XObject? seat, XObject anchor,
        RouteState route, TreeStack? stack, out int callerDepth)
    {
        callerDepth = -1;
        if (stack is null || seat is null ||
            !SimulationWorld.HasFunction(seat, 0x1a) ||
            SimulationWorld.FunctionTreeId(seat, 0x1b) is not (var standTree and not 0) ||
            seat.TypeRecord?.BehaviorScope is not { } seatScope)
            return false;

        if (route.DirectPositionRequest)
            person[PersonData.RouteEntryFlags] = 0;
        else
            person[PersonData.RouteEntryFlags] = SeatExitEntryFlags(world, person, seat, anchor);

        var nextCallerDepth = stack.Frames.Count;
        if (!PersonInteractionStack.Push(person, seat, stack, seatScope, standTree, seat.StackObjectKey,
                [person[PersonData.RouteEntryFlags], 0, 0, 0], codeOwner: world.ResolveCodeOwner(seat, seatScope)))
            return false;

        callerDepth = nextCallerDepth;
        return true;
    }

    private static void SetRouteEntryFlags(SimulationWorld world, XPerson person, XObject anchor, RouteState route)
    {
        if (route.DirectPositionRequest) return;
        person[PersonData.RouteEntryFlags] = route.EntryFlags;
    }

    private static short LocalSectorEntryFlags(short worldSector, short orientation) =>
        unchecked((short)(1 << ((worldSector - orientation) & 7)));

    private static short SeatExitEntryFlags(SimulationWorld world, XPerson person, XObject seat, XObject target)
    {
        if (!SimulationWorld.HasFunction(seat, 0x1a)) return 0;
        var entryMask = unchecked((ushort)seat.Definition[(int)Formats.ObjdField.ChairEntryFlags]);
        short best = 0;
        var bestDistance = long.MaxValue;
        for (var side = 0; side < 8; side++)
        {
            if ((entryMask & (1 << side)) == 0) continue;
            var worldDirection = (short)((seat[ObjectData.Direction] + side) & 7);
            var offset = LotGeometry.FootprintOffset(worldDirection);
            var candidate = person.Position with { X = person.Position.X + offset.X, Y = person.Position.Y + offset.Y };
            var accepted = Walkable(world, person, seat, candidate, writeCandidateResults: false);
            if (!accepted && world.LastPlacementBlockingObjectId != 0 &&
                (world.ObjectTableEntry(world.LastPlacementBlockingObjectId)
                    ?? world.WalkOrder.FirstOrDefault(item => item.ClockManagerIndex == world.LastPlacementBlockingObjectId))
                    is XPerson)
                accepted = true;
            if (!accepted) continue;
            long dx = target.Position.X - candidate.X;
            long dy = target.Position.Y - candidate.Y;
            var distance = dx * dx + dy * dy;
            if (best != 0 && distance >= bestDistance) continue;
            best = unchecked((short)(1 << side));
            bestDistance = distance;
        }
        return best;
    }

    private readonly record struct PartitionCell(int MinX, int MinY, int MaxX, int MaxY,
        int CenterX, int CenterY, ushort Room, int Cost);

    private sealed class FloorPartition(
        SimulationWorld world,
        XPerson person,
        XObject anchor,
        TreeStack? stack,
        SimsEngine.World.RoomMap map,
        (int X, int Y) startTile,
        int startPointX,
        int startPointY,
        ushort startRoom,
        int startId,
        bool allowCrossRoom,
        List<PartitionCell> cells,
        List<(int Id, int X, int Y)>[] neighbors,
        IReadOnlySet<short>? startOverlappingObjectKeys = null,
        IReadOnlyList<FootprintBounds>? startOverlappingBounds = null)
    {
        public SimulationWorld World { get; } = world;
        public XPerson Person { get; } = person;
        public XObject Anchor { get; } = anchor;
        public TreeStack? Stack { get; } = stack;
        public SimsEngine.World.RoomMap Map { get; } = map;
        public (int X, int Y) StartTile { get; } = startTile;
        public int StartPointX { get; } = startPointX;
        public int StartPointY { get; } = startPointY;
        public ushort StartRoom { get; } = startRoom;
        public int StartId { get; } = startId;
        public bool AllowCrossRoom { get; } = allowCrossRoom;
        public List<PartitionCell> Cells { get; } = cells;
        public List<(int Id, int X, int Y)>[] Neighbors { get; } = neighbors;
        public IReadOnlySet<short>? StartOverlappingObjectKeys { get; } = startOverlappingObjectKeys;
        public IReadOnlyList<FootprintBounds>? StartOverlappingBounds { get; } = startOverlappingBounds;
        public Dictionary<int, bool> PlacementCache { get; } = [];
    }

    private static FloorPartition? TryBuildFloorPartition(SimulationWorld world, XPerson person, XObject anchor,
        bool allowCrossRoom = true, TreeStack? stack = null,
        (int X, int Y)? startTileOverride = null, (int X, int Y)? startCellCenterOverride = null)
    {
        if (!world.LotRoomMaps.TryGetValue(person.Position.Height, out var map))
            return null;
        var startPointX = person.Position.X;
        var startPointY = person.Position.Y;
        var startTile = startTileOverride ?? (X: startPointX >> 4, Y: startPointY >> 4);
        if (startTile.X < 0 || startTile.Y < 0 || startTile.X >= map.Width || startTile.Y >= map.Height)
            return null;

        var startRoom = map.RoomAt(startTile.X, startTile.Y);
        if (startRoom == SimsEngine.World.RoomMap.NoRoom) return null;

        var penaltyRects = new List<(int MinX, int MinY, int MaxX, int MaxY, int Cost, ushort Room)>();
        const int wallPenaltyInflate = 8;
        const int roomWallClearanceInflate = 7;

        var ghostIgnoresWalls = (person[PersonData.IsGhost] & 1) != 0;
        if (!ghostIgnoresWalls)
        for (var tileY = 0; tileY < map.Height; tileY++)
        for (var tileX = 0; tileX < map.Width; tileX++)
        {
            var walls = map.ExpandedWallAt(tileX, tileY);
            if (walls is null) continue;
            var mask = walls.Value.UInt32At(0);
            if ((mask & 0x33) == 0) continue;
            if ((mask & 1) != 0 && walls.Value.WallCategory(1) is not (3 or 5 or 6 or 15 or 23))
                AddRouteCostRect(tileX * 16, tileY * 16, tileX * 16, (tileY + 1) * 16,
                    10_000, SimsEngine.World.RoomMap.NoRoom, roomWallClearanceInflate, roomWallClearanceInflate);
            if ((mask & 2) != 0 && walls.Value.WallCategory(2) is not (3 or 5 or 6 or 15 or 23))
                AddRouteCostRect(tileX * 16, tileY * 16, (tileX + 1) * 16, tileY * 16,
                    10_000, SimsEngine.World.RoomMap.NoRoom, roomWallClearanceInflate, roomWallClearanceInflate);
            if ((mask & 0x10) != 0 && walls.Value.WallCategory(0x10) is not (3 or 5 or 6 or 15 or 23))
            {
                AddRouteCostRect(tileX * 16 + 4, tileY * 16 + 12, tileX * 16 + 4, tileY * 16 + 12,
                    10_000, SimsEngine.World.RoomMap.NoRoom, roomWallClearanceInflate, roomWallClearanceInflate);
                AddRouteCostRect(tileX * 16 + 12, tileY * 16 + 4, tileX * 16 + 12, tileY * 16 + 4,
                    10_000, SimsEngine.World.RoomMap.NoRoom, roomWallClearanceInflate, roomWallClearanceInflate);
            }
            if ((mask & 0x20) != 0 && walls.Value.WallCategory(0x20) is not (3 or 5 or 6 or 15 or 23))
            {
                AddRouteCostRect(tileX * 16 + 4, tileY * 16 + 4, tileX * 16 + 4, tileY * 16 + 4,
                    10_000, SimsEngine.World.RoomMap.NoRoom, roomWallClearanceInflate, roomWallClearanceInflate);
                AddRouteCostRect(tileX * 16 + 12, tileY * 16 + 12, tileX * 16 + 12, tileY * 16 + 12,
                    10_000, SimsEngine.World.RoomMap.NoRoom, roomWallClearanceInflate, roomWallClearanceInflate);
            }
        }

        if (startTileOverride is { } retained && startCellCenterOverride is null)
        {
            if (startPointX == (retained.X + 1) * 16) startPointX--;
            if (startPointY == (retained.Y + 1) * 16) startPointY--;
        }
        var startLookupX = startCellCenterOverride?.X ?? startPointX;
        var startLookupY = startCellCenterOverride?.Y ?? startPointY;
        var personIsGhost = (person.FootprintFlags614 & 1) != 0 || (person.FootprintFlags634 & 1) != 0;
        var personHalfSpan = personIsGhost ? 0 : 3;
        var actorBounds = person.FootprintBoundsAt(new ObjectPosition(startLookupX, startLookupY, person.Position.Height));
        HashSet<short>? startOverlappingObjectKeys = null;
        List<FootprintBounds>? startOverlappingBounds = null;

        // Snapshots the object list because routing check scripts can mutate the lot object collection
        // during evaluation.
        if (!personIsGhost)
        {
        foreach (var item in world.WalkOrder.ToArray())
        {
            if (item.Id == person.Id || item.Position.Height != person.Position.Height) continue;
            if (world.ResolveParentContainer(item) is not null)
                continue;

            var routePenalty = item[ObjectData.RoutePenalty];
            var objectFlags = unchecked((ushort)item[ObjectData.Flags]);
            var ignoreZeroPenalty = (objectFlags & 0x0004) != 0
                ? (objectFlags & 0x0002) == 0
                : (objectFlags & 0x0010) != 0;
            if (routePenalty == 0 && ignoreZeroPenalty) continue;

            if (item.TypeRecord?.ObjectType == 2)
            {
                if (item.Id == anchor.Id || GetDistanceToPrimitive.DistanceBetween(person, item) > 3.0)
                    continue;
            }
            else
            {
                var checkTree = SimulationWorld.FunctionTreeId(item, 5);
                if (checkTree != 0 && item.TypeRecord?.BehaviorScope is { } scope &&
                    TreeRunner.RunWithParameters(world, item, scope, checkTree,
                        person.StackObjectKey, []))
                    continue;
            }

            var routeCost = routePenalty == 0 ? int.MaxValue : 10;
            FootprintBounds bounds;
            if (item is XPerson itemPerson)
            {
                itemPerson.RefreshFootprintBounds();
                bounds = itemPerson.FootprintBounds;
            }
            else
            {
                bounds = SimulationWorld.PlacementFootprintBounds(item, item.Position);
            }
            var itemRoom = unchecked((ushort)item.RoomWord84);
            var intersectsActor = bounds.MinX < actorBounds.MaxX && actorBounds.MinX < bounds.MaxX &&
                                  bounds.MinY < actorBounds.MaxY && actorBounds.MinY < bounds.MaxY;
            if (!intersectsActor)
            {
                var obstacleInflate = item.TypeRecord?.ObjectType == 2 || routeCost == int.MaxValue || routeCost > 7
                    ? personHalfSpan
                    : 0;
                AddRouteCostRect(bounds.MinX, bounds.MinY, bounds.MaxX, bounds.MaxY, routeCost, itemRoom,
                    obstacleInflate, obstacleInflate);
            }
            else if (item.ClockManagerIndex > 0)
            {
                startOverlappingObjectKeys ??= [];
                startOverlappingObjectKeys.Add(item.ClockManagerIndex);
                startOverlappingBounds ??= [];
                startOverlappingBounds.Add(new FootprintBounds(
                    MaxX: bounds.MaxX + personHalfSpan,
                    MaxY: bounds.MaxY + personHalfSpan,
                    MinX: bounds.MinX - personHalfSpan,
                    MinY: bounds.MinY - personHalfSpan));
            }
            if (item.TypeRecord?.ObjectType != 8) continue;
            var storedWallFlags = unchecked((uint)(ushort)item[ObjectData.WallBlockFlags]);
            var rotatedWallFlags = storedWallFlags << (unchecked((byte)item[ObjectData.Direction]) & 0x1f);
            var wallFlags = (rotatedWallFlags & 0xff) | ((rotatedWallFlags >> 8) & 0xff);
            if ((wallFlags & 0x0001) != 0)
                AddRouteCostRect(bounds.MinX, bounds.MinY, bounds.MaxX + 1,
                    bounds.MaxY, 10_000, itemRoom, wallPenaltyInflate, wallPenaltyInflate);
            if ((wallFlags & 0x0004) != 0)
                AddRouteCostRect(bounds.MinX, bounds.MaxY - 1, bounds.MaxX,
                    bounds.MaxY, 10_000, itemRoom, wallPenaltyInflate, wallPenaltyInflate);
            if ((wallFlags & 0x0010) != 0)
                AddRouteCostRect(bounds.MaxX - 1, bounds.MinY, bounds.MaxX,
                    bounds.MaxY, 10_000, itemRoom, wallPenaltyInflate, wallPenaltyInflate);
            if ((wallFlags & 0x0040) != 0)
                AddRouteCostRect(bounds.MinX, bounds.MinY, bounds.MaxX,
                    bounds.MinY + 1, 10_000, itemRoom, wallPenaltyInflate, wallPenaltyInflate);
        }

        if (person[PersonData.Sitting] == 1 &&
            ResolveSeatedContainer(world, person) is { ClockManagerIndex: > 0 } seatedContainer)
        {
            startOverlappingObjectKeys ??= [];
            if (startOverlappingObjectKeys.Add(seatedContainer.ClockManagerIndex))
            {
                var seatBounds = SimulationWorld.PlacementFootprintBounds(seatedContainer, seatedContainer.Position);
                startOverlappingBounds ??= [];
                startOverlappingBounds.Add(new FootprintBounds(
                    MaxX: seatBounds.MaxX + personHalfSpan,
                    MaxY: seatBounds.MaxY + personHalfSpan,
                    MinX: seatBounds.MinX - personHalfSpan,
                    MinY: seatBounds.MinY - personHalfSpan));
            }
        }
        }

        void AddRouteCostRect(int minX, int minY, int maxX, int maxY, int cost,
            ushort room, int inflateX = 0, int inflateY = 0)
        {
            minX = Math.Max(0, minX - inflateX);
            minY = Math.Max(0, minY - inflateY);
            maxX = Math.Min(map.Width * 16, maxX + inflateX);
            maxY = Math.Min(map.Height * 16, maxY + inflateY);
            if (minX < maxX && minY < maxY)
                penaltyRects.Add((minX, minY, maxX, maxY, cost, room));
        }

        var mapWidth = map.Width;
        var mapHeight = map.Height;
        var tileCount = mapWidth * mapHeight;
        var singleTileCells = new PartitionCell[tileCount];
        var tilePresent = new bool[tileCount];
        List<PartitionCell>[]? splitTileCells = null;

        for (var tileY = 0; tileY < mapHeight; tileY++)
        for (var tileX = 0; tileX < mapWidth; tileX++)
        {
            var room = map.RoomAt(tileX, tileY);
            if (room == SimsEngine.World.RoomMap.NoRoom || (!allowCrossRoom && room != startRoom)) continue;
            var minX = tileX * 16; var minY = tileY * 16;
            var maxX = minX + 16; var maxY = minY + 16;
            var tileIdx = tileY * mapWidth + tileX;
            singleTileCells[tileIdx] = new PartitionCell(minX, minY, maxX, maxY, minX + 8, minY + 8, room, 0);
            tilePresent[tileIdx] = true;
        }

        if (penaltyRects.Count > 0)
        {
            var nextTileCells = new List<PartitionCell>(16);
            Span<int> xValues = stackalloc int[4];
            Span<int> yValues = stackalloc int[4];
            foreach (var rect in penaltyRects)
            {
                var txMin = Math.Max(0, rect.MinX >> 4);
                var txMax = Math.Min(mapWidth - 1, (rect.MaxX - 1) >> 4);
                var tyMin = Math.Max(0, rect.MinY >> 4);
                var tyMax = Math.Min(mapHeight - 1, (rect.MaxY - 1) >> 4);
                for (var ty = tyMin; ty <= tyMax; ty++)
                for (var tx = txMin; tx <= txMax; tx++)
                {
                    var tileIdx = ty * mapWidth + tx;
                    if (!tilePresent[tileIdx]) continue;
                    var existingList = splitTileCells?[tileIdx];
                    if (existingList is null)
                    {
                        var cell = singleTileCells[tileIdx];
                        if ((rect.Room != SimsEngine.World.RoomMap.NoRoom && cell.Room != rect.Room) ||
                            rect.MinX >= cell.MaxX || rect.MaxX <= cell.MinX ||
                            rect.MinY >= cell.MaxY || rect.MaxY <= cell.MinY)
                            continue;

                        var xCount = SortedUnique4(cell.MinX, cell.MaxX,
                            Math.Clamp(rect.MinX, cell.MinX, cell.MaxX),
                            Math.Clamp(rect.MaxX, cell.MinX, cell.MaxX), xValues);
                        var yCount = SortedUnique4(cell.MinY, cell.MaxY,
                            Math.Clamp(rect.MinY, cell.MinY, cell.MaxY),
                            Math.Clamp(rect.MaxY, cell.MinY, cell.MaxY), yValues);
                        if (xCount == 2 && yCount == 2)
                        {
                            var inside = cell.CenterX >= rect.MinX && cell.CenterX < rect.MaxX &&
                                         cell.CenterY >= rect.MinY && cell.CenterY < rect.MaxY;
                            if (inside && rect.Cost > cell.Cost)
                                singleTileCells[tileIdx] = cell with { Cost = rect.Cost };
                            continue;
                        }

                        splitTileCells ??= new List<PartitionCell>[tileCount];
                        var splitList = new List<PartitionCell>((xCount - 1) * (yCount - 1));
                        for (var y = 0; y < yCount - 1; y++)
                        for (var x = 0; x < xCount - 1; x++)
                        {
                            var minX = xValues[x]; var maxX = xValues[x + 1];
                            var minY = yValues[y]; var maxY = yValues[y + 1];
                            var centerX = minX + (maxX - minX) / 2;
                            var centerY = minY + (maxY - minY) / 2;
                            var inside = centerX >= rect.MinX && centerX < rect.MaxX &&
                                         centerY >= rect.MinY && centerY < rect.MaxY;
                            splitList.Add(new PartitionCell(minX, minY, maxX, maxY, centerX, centerY,
                                cell.Room, inside ? Math.Max(cell.Cost, rect.Cost) : cell.Cost));
                        }
                        splitTileCells[tileIdx] = splitList;
                    }
                    else
                    {
                        nextTileCells.Clear();
                        var changed = false;
                        for (var i = 0; i < existingList.Count; i++)
                        {
                            var cell = existingList[i];
                            if ((rect.Room != SimsEngine.World.RoomMap.NoRoom && cell.Room != rect.Room) ||
                                rect.MinX >= cell.MaxX || rect.MaxX <= cell.MinX ||
                                rect.MinY >= cell.MaxY || rect.MaxY <= cell.MinY)
                            {
                                nextTileCells.Add(cell);
                                continue;
                            }

                            changed = true;
                            var xCount = SortedUnique4(cell.MinX, cell.MaxX,
                                Math.Clamp(rect.MinX, cell.MinX, cell.MaxX),
                                Math.Clamp(rect.MaxX, cell.MinX, cell.MaxX), xValues);
                            var yCount = SortedUnique4(cell.MinY, cell.MaxY,
                                Math.Clamp(rect.MinY, cell.MinY, cell.MaxY),
                                Math.Clamp(rect.MaxY, cell.MinY, cell.MaxY), yValues);
                            for (var y = 0; y < yCount - 1; y++)
                            for (var x = 0; x < xCount - 1; x++)
                            {
                                var minX = xValues[x]; var maxX = xValues[x + 1];
                                var minY = yValues[y]; var maxY = yValues[y + 1];
                                var centerX = minX + (maxX - minX) / 2;
                                var centerY = minY + (maxY - minY) / 2;
                                var inside = centerX >= rect.MinX && centerX < rect.MaxX &&
                                             centerY >= rect.MinY && centerY < rect.MaxY;
                                nextTileCells.Add(new PartitionCell(minX, minY, maxX, maxY, centerX, centerY,
                                    cell.Room, inside ? Math.Max(cell.Cost, rect.Cost) : cell.Cost));
                            }
                        }
                        if (changed)
                        {
                            existingList.Clear();
                            existingList.AddRange(nextTileCells);
                        }
                    }
                }
            }
        }

        var cells = new List<PartitionCell>(tileCount + 64);
        for (var tileIdx = 0; tileIdx < tileCount; tileIdx++)
        {
            if (!tilePresent[tileIdx]) continue;
            if (splitTileCells?[tileIdx] is { } list) cells.AddRange(list);
            else cells.Add(singleTileCells[tileIdx]);
        }

        var startId = cells.FindIndex(cell => startLookupX >= cell.MinX && startLookupX < cell.MaxX &&
            startLookupY >= cell.MinY && startLookupY < cell.MaxY);
        if (startId < 0) return null;

        var neighbors = new List<(int Id, int X, int Y)>[cells.Count];
        for (var i = 0; i < cells.Count; i++) neighbors[i] = new List<(int Id, int X, int Y)>(4);
        var minXEdges = new Dictionary<int, List<int>>(mapWidth * 2);
        var maxXEdges = new Dictionary<int, List<int>>(mapWidth * 2);
        var minYEdges = new Dictionary<int, List<int>>(mapHeight * 2);
        var maxYEdges = new Dictionary<int, List<int>>(mapHeight * 2);
        for (var id = 0; id < cells.Count; id++)
        {
            var cell = cells[id];
            AddEdge(minXEdges, cell.MinX, id); AddEdge(maxXEdges, cell.MaxX, id);
            AddEdge(minYEdges, cell.MinY, id); AddEdge(maxYEdges, cell.MaxY, id);
        }
        void Connect(int firstId, int secondId)
        {
            var point = FindPartitionInterface(cells[firstId], cells[secondId]);
            neighbors[firstId].Add((secondId, point.X, point.Y));
            neighbors[secondId].Add((firstId, point.X, point.Y));
        }
        var compareByMinY = Comparer<int>.Create((a, b) => cells[a].MinY.CompareTo(cells[b].MinY));
        var compareByMinX = Comparer<int>.Create((a, b) => cells[a].MinX.CompareTo(cells[b].MinX));
        foreach (var edge in maxXEdges)
        {
            if (!minXEdges.TryGetValue(edge.Key, out var rightCells)) continue;
            var leftCells = edge.Value;
            leftCells.Sort(compareByMinY);
            rightCells.Sort(compareByMinY);
            int li = 0, ri = 0;
            while (li < leftCells.Count && ri < rightCells.Count)
            {
                var leftId = leftCells[li];
                var rightId = rightCells[ri];
                var left = cells[leftId];
                var right = cells[rightId];
                if (Math.Max(left.MinY, right.MinY) < Math.Min(left.MaxY, right.MaxY))
                    Connect(leftId, rightId);
                if (left.MaxY <= right.MaxY) li++;
                else ri++;
            }
        }
        foreach (var edge in maxYEdges)
        {
            if (!minYEdges.TryGetValue(edge.Key, out var lowerCells)) continue;
            var upperCells = edge.Value;
            upperCells.Sort(compareByMinX);
            lowerCells.Sort(compareByMinX);
            int ui = 0, li = 0;
            while (ui < upperCells.Count && li < lowerCells.Count)
            {
                var upperId = upperCells[ui];
                var lowerId = lowerCells[li];
                var upper = cells[upperId];
                var lower = cells[lowerId];
                if (Math.Max(upper.MinX, lower.MinX) < Math.Min(upper.MaxX, lower.MaxX))
                    Connect(upperId, lowerId);
                if (upper.MaxX <= lower.MaxX) ui++;
                else li++;
            }
        }

        static void AddEdge(Dictionary<int, List<int>> edges, int coordinate, int id)
        {
            if (!edges.TryGetValue(coordinate, out var line)) edges[coordinate] = line = [];
            line.Add(id);
        }

        static int SortedUnique4(int a, int b, int c, int d, Span<int> dst)
        {
            Span<int> raw = stackalloc int[4] { a, b, c, d };
            for (var i = 1; i < 4; i++)
            {
                var key = raw[i];
                var j = i - 1;
                while (j >= 0 && raw[j] > key)
                {
                    raw[j + 1] = raw[j];
                    j--;
                }
                raw[j + 1] = key;
            }
            var count = 0;
            for (var i = 0; i < 4; i++)
                if (count == 0 || raw[i] != dst[count - 1])
                    dst[count++] = raw[i];
            return count;
        }

        return new FloorPartition(world, person, anchor, stack, map, startTile, startPointX, startPointY,
            startRoom, startId, allowCrossRoom, cells, neighbors,
            startOverlappingObjectKeys, startOverlappingBounds);
    }

    internal static bool TryPath(SimulationWorld world, XPerson person, ObjectPosition destination, XObject anchor,
        out List<RouteWaypoint> path, out double pathCost, bool directPositionRequest = false,
        RoutingSlotRequest? directSlot = null, TreeStack? stack = null,
        (int X, int Y)? startTileOverride = null, (int X, int Y)? startCellCenterOverride = null,
        bool allowCrossRoom = true)
    {
        path = [];
        pathCost = double.PositiveInfinity;
        if (destination.Height != person.Position.Height ||
            !world.LotRoomMaps.TryGetValue(person.Position.Height, out var map))
            return false;
        var endTile = (X: destination.X >> 4, Y: destination.Y >> 4);
        if (endTile.X < 0 || endTile.Y < 0 || endTile.X >= map.Width || endTile.Y >= map.Height)
            return false;
        var endRoom = map.RoomAt(endTile.X, endTile.Y);
        if (endRoom == SimsEngine.World.RoomMap.NoRoom) return false;
        var startTile = startTileOverride ?? (X: person.Position.X >> 4, Y: person.Position.Y >> 4);
        if (startTile.X < 0 || startTile.Y < 0 || startTile.X >= map.Width || startTile.Y >= map.Height)
            return false;
        if (!allowCrossRoom && map.RoomAt(startTile.X, startTile.Y) != endRoom)
            return false;
        if (TryBuildFloorPartition(world, person, anchor, allowCrossRoom, stack, startTileOverride, startCellCenterOverride) is not { } partition)
            return false;
        return TryPathWithPartition(partition, destination, out path, out pathCost);
    }

    private static bool TryPathWithPartition(FloorPartition partition, ObjectPosition destination,
        out List<RouteWaypoint> path, out double pathCost)
    {
        path = [];
        pathCost = double.PositiveInfinity;
        var world = partition.World;
        var person = partition.Person;
        if (destination.Height != person.Position.Height) return false;
        var map = partition.Map;
        var endTile = (X: destination.X >> 4, Y: destination.Y >> 4);
        if (endTile.X < 0 || endTile.Y < 0 || endTile.X >= map.Width || endTile.Y >= map.Height)
            return false;
        var endRoom = map.RoomAt(endTile.X, endTile.Y);
        if (endRoom == SimsEngine.World.RoomMap.NoRoom) return false;
        if (!partition.AllowCrossRoom && partition.StartRoom != endRoom) return false;

        var cells = partition.Cells;
        var startId = partition.StartId;
        var endId = cells.FindIndex(cell => destination.X >= cell.MinX && destination.X < cell.MaxX &&
            destination.Y >= cell.MinY && destination.Y < cell.MaxY);
        if (endId < 0) return false;

        var neighbors = partition.Neighbors;
        var anchor = partition.Anchor;
        var stack = partition.Stack;
        var startTile = partition.StartTile;
        var startPointX = partition.StartPointX;
        var startPointY = partition.StartPointY;
        var startRoom = partition.StartRoom;

        var nodeCount = cells.Count;
        var queue = new PriorityQueue<int, (double Estimate, double Cost, long Sequence)>();
        var costs = ArrayPool<double>.Shared.Rent(nodeCount);
        var previous = ArrayPool<int>.Shared.Rent(nodeCount);
        var visited = ArrayPool<byte>.Shared.Rent(nodeCount);
        try
        {
            costs.AsSpan(0, nodeCount).Fill(double.PositiveInfinity);
            visited.AsSpan(0, nodeCount).Clear();
            costs[startId] = 0d;
            var visitedCount = 0;
            long sequence = 0;
            var rejectedPlacements = 0;
            var rejectedEdges = 0;
            var placementCache = partition.PlacementCache;
            var anchorRawBounds = anchor is XPerson anchorPerson
                ? anchorPerson.FootprintBoundsAt(anchor.Position)
                : SimulationWorld.PlacementFootprintBounds(anchor, anchor.Position);
            var anchorInflate = (person.FootprintFlags614 & 1) != 0 || (person.FootprintFlags634 & 1) != 0 ? 0 : 3;
            var ghostIgnoresWalls = (person[PersonData.IsGhost] & 1) != 0;
            var anchorInfMinX = anchorRawBounds.MinX - anchorInflate;
            var anchorInfMinY = anchorRawBounds.MinY - anchorInflate;
            var anchorInfMaxX = anchorRawBounds.MaxX + anchorInflate;
            var anchorInfMaxY = anchorRawBounds.MaxY + anchorInflate;
            var destinationInAnchorCollar = destination.X >= anchorInfMinX && destination.X < anchorInfMaxX &&
                                            destination.Y >= anchorInfMinY && destination.Y < anchorInfMaxY;
            bool IsAnchorCollarForGoal(int id)
            {
                if (!destinationInAnchorCollar) return false;
                var c = cells[id];
                return c.CenterX >= anchorInfMinX && c.CenterX < anchorInfMaxX &&
                       c.CenterY >= anchorInfMinY && c.CenterY < anchorInfMaxY;
            }
            bool IsStartOverlapCollar(int id)
            {
                if (partition.StartOverlappingBounds is not { Count: > 0 } overlapBounds) return false;
                var c = cells[id];
                foreach (var b in overlapBounds)
                {
                    if (c.CenterX >= b.MinX && c.CenterX < b.MaxX &&
                        c.CenterY >= b.MinY && c.CenterY < b.MaxY)
                        return true;
                }
                return false;
            }
            bool CanVisit(int id)
            {
                if (id == startId || id == endId) return true;
                if (IsAnchorCollarForGoal(id))
                {
                    var collarCell = cells[id];
                    var collarCandidate = new ObjectPosition(collarCell.CenterX, collarCell.CenterY, person.Position.Height);
                    if (Walkable(world, person, anchor, collarCandidate, writeCandidateResults: false, stack: stack))
                        return true;
                    return world.LastPlacementFailureCode == 0x0b &&
                           world.LastPlacementBlockingObjectId == anchor.ClockManagerIndex;
                }
                if (placementCache.TryGetValue(id, out var allowed)) return allowed;
                var cell = cells[id];
                var candidate = new ObjectPosition(cell.CenterX, cell.CenterY, person.Position.Height);
                allowed = Walkable(world, person, anchor, candidate, writeCandidateResults: false, stack: stack);
                if (!allowed &&
                    partition.StartOverlappingObjectKeys is { Count: > 0 } startOverlapKeys &&
                    IsStartOverlapCollar(id) &&
                    world.LastPlacementFailureCode == 0x0b &&
                    startOverlapKeys.Contains(world.LastPlacementBlockingObjectId))
                {
                    allowed = ghostIgnoresWalls ||
                              (unchecked((ushort)person[ObjectData.PlacementFlags]) & 0x0400) != 0 ||
                              !world.FootprintIntersectsWall(person.FootprintBoundsAt(candidate), candidate.Height);
                }
                placementCache[id] = allowed;
                if (!allowed) rejectedPlacements++;
                return allowed;
            }
            queue.Enqueue(startId, (DistanceBetweenNodeCenters(cells[startId], cells[endId]), 0d, sequence++));

            while (queue.TryDequeue(out var currentId, out var queuedPriority))
            {
                if (queuedPriority.Cost != costs[currentId] || visited[currentId] != 0) continue;
                visited[currentId] = 1;
                visitedCount++;
                var currentCost = costs[currentId];
                if (currentId == endId)
                {
                    pathCost = currentCost;
                    break;
                }
                var current = cells[currentId];
                foreach (var (nextId, interfaceX, interfaceY) in neighbors[currentId])
                {
                    if (nextId < 0 || visited[nextId] != 0) continue;
                    var next = cells[nextId];
                    if (nextId != endId && !IsAnchorCollarForGoal(nextId) && next.Cost == int.MaxValue) { rejectedEdges++; continue; }
                    if (!CanVisit(nextId)) continue;
                    var fromTile = (X: current.CenterX >> 4, Y: current.CenterY >> 4);
                    var toTile = (X: next.CenterX >> 4, Y: next.CenterY >> 4);
                    if (!ghostIgnoresWalls)
                    {
                        if (fromTile == toTile)
                        {
                            if (current.Room != next.Room) { rejectedEdges++; continue; }
                        }
                        else if (!CanStep(world, map, fromTile, toTile))
                        {
                            rejectedEdges++;
                            continue;
                        }
                    }

                    var dx1 = interfaceX - current.CenterX;
                    var dy1 = interfaceY - current.CenterY;
                    var dx2 = next.CenterX - interfaceX;
                    var dy2 = next.CenterY - interfaceY;
                    var edgeDistance = Math.Sqrt(dx1 * dx1 + dy1 * dy1) + Math.Sqrt(dx2 * dx2 + dy2 * dy2);
                    var edgeCost = ((current.Cost + 2L + next.Cost) >> 1) * edgeDistance;
                    var nextCost = currentCost + edgeCost;
                    if (costs[nextId] <= nextCost) continue;
                    costs[nextId] = nextCost;
                    previous[nextId] = currentId;
                    queue.Enqueue(nextId, (nextCost + DistanceBetweenNodeCenters(next, cells[endId]), nextCost, sequence++));
                }
            }

            if (world.CaptureExecutionTrace)
            {
                var roomCounts = new Dictionary<ushort, int>();
                for (var id = 0; id < nodeCount; id++)
                {
                    if (visited[id] == 0) continue;
                    var room = cells[id].Room;
                    roomCounts[room] = roomCounts.TryGetValue(room, out var count) ? count + 1 : 1;
                }
                var visitedRooms = string.Join(",", roomCounts.OrderBy(group => group.Key).Select(group => $"{group.Key}:{group.Value}"));
                world.RouteSearchTrace.Add(new SimulationRouteSearchTrace(person.Id, destination, startTile, endTile,
                    startRoom, endRoom, visitedCount, rejectedPlacements, rejectedEdges, visitedRooms));
            }
            if (!double.IsFinite(pathCost)) return false;

            var reverse = new List<int> { endId };
            while (reverse[^1] != startId) reverse.Add(previous[reverse[^1]]);
            reverse.Reverse();
            if (reverse.Count == 1)
            {
                var singlePoint = startPointX == destination.X && startPointY == destination.Y;
                path.Add(new RouteWaypoint(startTile.X, startTile.Y, startPointX, startPointY,
                    cells[startId].CenterX, cells[startId].CenterY, singlePoint));
                if (!singlePoint)
                {
                    path.Add(new RouteWaypoint(endTile.X, endTile.Y, destination.X, destination.Y,
                        cells[endId].CenterX, cells[endId].CenterY, true));
                }
            }
            else
            {
                var smoothedPoints = new List<(int CenterX, int CenterY)>(reverse.Count)
                {
                    (startPointX, startPointY),
                };
                for (var i = 1; i < reverse.Count - 1; i++)
                {
                    var cell = cells[reverse[i]];
                    smoothedPoints.Add((cell.CenterX, cell.CenterY));
                }
                smoothedPoints.Add((destination.X, destination.Y));
                SmoothPartitionPath(cells, reverse, smoothedPoints);
                path.Add(new RouteWaypoint(startTile.X, startTile.Y, startPointX, startPointY,
                    cells[startId].CenterX, cells[startId].CenterY, false));
                for (var i = 1; i < reverse.Count - 1; i++)
                {
                    var cell = cells[reverse[i]];
                    path.Add(ToWaypoint(smoothedPoints[i], cell));
                }
                var prevCell = cells[reverse[^2]];
                var endCell = cells[endId];
                var prevPt = smoothedPoints[^2];
                if (TryClampFinalCellEntry(prevCell, endCell, prevPt, (destination.X, destination.Y), out var entryPoint) &&
                    (entryPoint.X != prevPt.CenterX || entryPoint.Y != prevPt.CenterY) &&
                    (entryPoint.X != destination.X || entryPoint.Y != destination.Y))
                {
                    path.Add(ToWaypoint(entryPoint, endCell));
                }
                if (path[^1].X == destination.X && path[^1].Y == destination.Y &&
                    path[^1].TileX == endTile.X && path[^1].TileY == endTile.Y)
                {
                    path[^1] = path[^1] with { IsDestination = true };
                }
                else
                {
                    path.Add(new RouteWaypoint(endTile.X, endTile.Y, destination.X, destination.Y,
                        cells[endId].CenterX, cells[endId].CenterY, true));
                }
            }
            if (world.CaptureExecutionTrace)
            {
                var crossings = new List<string>();
                ushort previousRoom = SimsEngine.World.RoomMap.NoRoom;
                foreach (var point in path)
                {
                    var room = map.RoomAt(point.TileX, point.TileY);
                    if (crossings.Count == 0 || room != previousRoom)
                        crossings.Add($"{room}@{point.TileX},{point.TileY}");
                    previousRoom = room;
                }
                world.NativeRouteTrace.Add(new SimulationNativeRouteTrace(person.Id, anchor.Id, destination,
                    "path-rooms", string.Join("->", crossings)));
            }
            return true;
        }
        finally
        {
            ArrayPool<double>.Shared.Return(costs);
            ArrayPool<int>.Shared.Return(previous);
            ArrayPool<byte>.Shared.Return(visited);
        }

        RouteWaypoint ToWaypoint((int CenterX, int CenterY) point, PartitionCell cell) =>
            new(
                Math.Clamp(point.CenterX >> 4, cell.MinX >> 4, Math.Max(cell.MinX >> 4, (cell.MaxX - 1) >> 4)),
                Math.Clamp(point.CenterY >> 4, cell.MinY >> 4, Math.Max(cell.MinY >> 4, (cell.MaxY - 1) >> 4)),
                point.CenterX, point.CenterY, cell.CenterX, cell.CenterY, false);
    }

    private static bool TryClampFinalCellEntry(PartitionCell previousCell, PartitionCell endCell,
        (int CenterX, int CenterY) previousPoint, (int X, int Y) destination, out (int X, int Y) entryPoint)
    {
        entryPoint = default;
        if (previousCell.MaxX == endCell.MinX || endCell.MaxX == previousCell.MinX)
        {
            var sharedX = previousCell.MaxX == endCell.MinX ? previousCell.MaxX : previousCell.MinX;
            var minY = Math.Max(previousCell.MinY, endCell.MinY);
            var maxY = Math.Min(previousCell.MaxY, endCell.MaxY);
            if (maxY <= minY || destination.X == previousPoint.CenterX) return false;
            var crossY = previousPoint.CenterY +
                         (double)(sharedX - previousPoint.CenterX) * (destination.Y - previousPoint.CenterY) /
                         (destination.X - previousPoint.CenterX);
            if (crossY >= minY && crossY < maxY) return false;
            var clampedX = Math.Clamp(sharedX, endCell.MinX, Math.Max(endCell.MinX, endCell.MaxX - 1));
            var clampedY = Math.Clamp((int)Math.Round(crossY), minY, maxY - 1);
            entryPoint = (clampedX, clampedY);
            return true;
        }
        if (previousCell.MaxY == endCell.MinY || endCell.MaxY == previousCell.MinY)
        {
            var sharedY = previousCell.MaxY == endCell.MinY ? previousCell.MaxY : previousCell.MinY;
            var minX = Math.Max(previousCell.MinX, endCell.MinX);
            var maxX = Math.Min(previousCell.MaxX, endCell.MaxX);
            if (maxX <= minX || destination.Y == previousPoint.CenterY) return false;
            var crossX = previousPoint.CenterX +
                         (double)(sharedY - previousPoint.CenterY) * (destination.X - previousPoint.CenterX) /
                         (destination.Y - previousPoint.CenterY);
            if (crossX >= minX && crossX < maxX) return false;
            var clampedX = Math.Clamp((int)Math.Round(crossX), minX, maxX - 1);
            var clampedY = Math.Clamp(sharedY, endCell.MinY, Math.Max(endCell.MinY, endCell.MaxY - 1));
            entryPoint = (clampedX, clampedY);
            return true;
        }
        return false;
    }

    private static void SmoothPartitionPath(IReadOnlyList<PartitionCell> cells, IReadOnlyList<int> nodeIds,
        IList<(int CenterX, int CenterY)> points)
    {
        if (nodeIds.Count < 3) return;

        for (var pass = 0; ; pass++)
        {
            var divisor = (long)(pass + 1) * (pass + 1);
            var radius = (int)Math.Max(1, 100 / divisor);
            var moved = false;
            for (var index = 1; index < nodeIds.Count - 1; index++)
            {
                var previousCell = cells[nodeIds[index - 1]];
                var currentCell = cells[nodeIds[index]];
                var left = Math.Max(previousCell.MinX, currentCell.MinX - 1);
                var top = Math.Max(previousCell.MinY, currentCell.MinY - 1);
                var right = Math.Min(previousCell.MaxX, currentCell.MaxX + 1);
                var bottom = Math.Min(previousCell.MaxY, currentCell.MaxY + 1);
                var point = points[index];
                var previous = points[index - 1];
                var next = index + 1 < points.Count ? points[index + 1] : point;
                var best = point;
                var bestCost = Distance(previous, point) + Distance(point, next);

                void Consider(int x, int y)
                {
                    var candidate = (CenterX: x, CenterY: y);
                    var cost = Distance(previous, candidate) + Distance(candidate, next);
                    if (cost >= bestCost) return;
                    bestCost = cost;
                    best = candidate;
                }

                if (right - left > 2 && point.CenterX < right - radius)
                    Consider(point.CenterX + radius, point.CenterY);
                if (right - left > 2 && point.CenterX > left + radius)
                    Consider(point.CenterX - radius, point.CenterY);
                if (bottom - top > 2 && point.CenterY < bottom - radius)
                    Consider(point.CenterX, point.CenterY + radius);
                if (bottom - top > 2 && point.CenterY > top + radius)
                    Consider(point.CenterX, point.CenterY - radius);

                if (best == point) continue;
                points[index] = best;
                moved = true;
            }

            if (moved) continue;
            if (radius > 1) continue;
            return;
        }

        static float Distance((int CenterX, int CenterY) first, (int CenterX, int CenterY) second)
        {
            var dx = (float)(first.CenterX - second.CenterX);
            var dy = (float)(first.CenterY - second.CenterY);
            return MathF.Sqrt(dx * dx + dy * dy);
        }
    }

    private static (int X, int Y) FindPartitionInterface(PartitionCell first, PartitionCell second)
    {
        if (first.MaxX == second.MinX || second.MaxX == first.MinX)
        {
            var sharedX = first.MaxX == second.MinX ? first.MaxX : first.MinX;
            var minY = Math.Max(first.MinY - 1, second.MinY - 1);
            var maxY = Math.Min(first.MaxY + 1, second.MaxY + 1);
            return (sharedX, (minY + maxY) / 2);
        }
        var sharedY = first.MaxY == second.MinY ? first.MaxY : first.MinY;
        var minX = Math.Max(first.MinX - 1, second.MinX - 1);
        var maxX = Math.Min(first.MaxX + 1, second.MaxX + 1);
        return ((minX + maxX) / 2, sharedY);
    }

    private static double DistanceBetweenNodeCenters(PartitionCell first, PartitionCell second)
    {
        var deltaX = second.CenterX - first.CenterX;
        var deltaY = second.CenterY - first.CenterY;
        return Math.Sqrt(deltaX * deltaX + deltaY * deltaY);
    }

    private static bool CanCaptureRouteSnapshot(SimulationWorld world, RouteState route) =>
        world.CaptureExecutionTrace && route.DiagnosticSnapshotCount < 3;

    private static RouteState TracePortalCallbackSnapshot(SimulationWorld world, XPerson person,
        RouteState route)
    {
        if (!CanCaptureRouteSnapshot(world, route)) return route;
        route = route with { DiagnosticSnapshotCount = route.DiagnosticSnapshotCount + 1 };
        person.NativeRoute = route;
        var currentRoom = RoomKeyAt(world, person.Position);
        var destinationRoom = RoomKeyAt(world, route.Destination);
        Trace(world, person, route.AnchorObjectId, route.Destination, "portal-callback-world",
            $"portal={route.OpenedPortalId}; function={route.OpenedPortalFunctionObjectId}; " +
            $"position=({person.Position.X},{person.Position.Y},{person.Position.Height}); roomWord={person.RoomWord84}; " +
            $"tileRoom={currentRoom}; destinationRoom={destinationRoom}; " +
            RouteWorldSnapshot(world, person, person.Position, route.Destination));
        return route;
    }

    private static string RouteWorldSnapshot(SimulationWorld world, XPerson person,
        ObjectPosition source, ObjectPosition destination)
    {
        var parent = person.ObjectTableEntry(person[ObjectData.ParentId]);
        return $"person={DescribeObject(person)} parent={DescribeObject(parent)}; " +
            $"sourceTile={TileRootDescription(world, source.X >> 4, source.Y >> 4, source.Height)}; " +
            $"destinationTile={TileRootDescription(world, destination.X >> 4, destination.Y >> 4, destination.Height)}";
    }

    private static string TileRootDescription(SimulationWorld world, int x, int y, int level)
    {
        var rootKey = world.TileValueAt(x, y, level);
        var root = rootKey is > 0 and <= short.MaxValue ? world.ObjectTableEntry((short)rootKey) : null;
        return $"({x},{y},{level})={rootKey}:{DescribeObject(root)}";
    }

    private static string DescribeObject(XObject? item)
    {
        if (item is null) return "null";
        var slots = string.Join(",", item.Slots.Take(4));
        return $"id={item.Id}/key={item.ClockManagerIndex}/parent={item[ObjectData.ParentId]}/" +
            $"container={item[ObjectData.ContainerId]}/slot={item[ObjectData.SlotHierNumber]}/slots=[{slots}]";
    }

    private static string RejectedEdgeDescription(SimulationWorld world, SimsEngine.World.RoomMap map,
        (int X, int Y) from, (int X, int Y) to)
    {
        var direction = DirectionToWaypoint(from, to);
        var fromRoom = map.RoomAt(from.X, from.Y);
        var toRoom = map.RoomAt(to.X, to.Y);
        var fromBlocked = world.BlocksRouteDirectionAt(map, from.X, from.Y, direction);
        var toDirection = (direction + 4) & 7;
        var toBlocked = world.BlocksRouteDirectionAt(map, to.X, to.Y, toDirection);
        var fromDetails = RouteBlockDetails(world, map, from.X, from.Y, direction, fromBlocked);
        var toDetails = RouteBlockDetails(world, map, to.X, to.Y, toDirection, toBlocked);
        var reason = fromRoom != toRoom
            ? "cross-room portal authorization rejected"
            : fromBlocked || toBlocked
                ? "endpoint route-block mask"
                : $"diagonal corner blocked; horizontal={CardinalEdgeDescription(world, map, from, (to.X, from.Y))}; " +
                  $"vertical={CardinalEdgeDescription(world, map, from, (from.X, to.Y))}";
        return $"edge reason={reason}; direction={direction}; from=({from.X},{from.Y}) room={fromRoom} {fromDetails} " +
            $"to=({to.X},{to.Y}) room={toRoom} {toDetails}; " +
            $"root={TileRootDescription(world, to.X, to.Y, map.Level)}";
    }

    private static string CardinalEdgeDescription(SimulationWorld world, SimsEngine.World.RoomMap map,
        (int X, int Y) from, (int X, int Y) to)
    {
        var direction = DirectionToWaypoint(from, to);
        var reverse = (direction + 4) & 7;
        var fromBlocked = world.BlocksRouteDirectionAt(map, from.X, from.Y, direction);
        var toBlocked = world.BlocksRouteDirectionAt(map, to.X, to.Y, reverse);
        return $"from=({from.X},{from.Y}) {RouteBlockDetails(world, map, from.X, from.Y, direction, fromBlocked)}; " +
            $"to=({to.X},{to.Y}) {RouteBlockDetails(world, map, to.X, to.Y, reverse, toBlocked)}";
    }

    private static ushort RoomKeyAt(SimulationWorld world, ObjectPosition position) =>
        world.LotRoomMaps.TryGetValue(position.Height, out var map) &&
        (uint)(position.X >> 4) < map.Width && (uint)(position.Y >> 4) < map.Height
            ? map.RoomAtPosition(position.X, position.Y)
            : SimsEngine.World.RoomMap.NoRoom;

    internal static bool CanStep(SimulationWorld world, SimsEngine.World.RoomMap map,
        (int X, int Y) from, (int X, int Y) to)
    {
        var direction = DirectionToWaypoint(from, to);
        var fromRoom = map.RoomAt(from.X, from.Y);
        var toRoom = map.RoomAt(to.X, to.Y);
        if (fromRoom != toRoom)
        {
            // Room transitions require routing through a portal because static wall blocker masks remain
            // active at door locations.
            return fromRoom != SimsEngine.World.RoomMap.NoRoom &&
                   toRoom != SimsEngine.World.RoomMap.NoRoom &&
                   HasPortalForStep(world, map.Level, fromRoom, toRoom, from, to);
        }
        if (world.BlocksRouteDirectionAt(map, from.X, from.Y, direction) ||
            world.BlocksRouteDirectionAt(map, to.X, to.Y, (direction + 4) & 7)) return false;

        // Avoids one-sided cardinal corner gating to prevent valid diagonal entries from becoming one-way
        // when the reverse side has a blocked orthogonal edge.
        return fromRoom != SimsEngine.World.RoomMap.NoRoom;
    }

    private static IEnumerable<XObject> Portals(SimulationWorld world) =>
        world.WalkOrder.Where(item => item.RuntimeClass == SimsEngine.Formats.ObjectClass.Portal &&
            SimulationWorld.FunctionTreeId(item, 0x0f) != 0);
}
