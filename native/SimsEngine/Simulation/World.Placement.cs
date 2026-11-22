using SimsEngine.Formats;
using SimsEngine.Content;
using SimsEngine.Character;
using System.Numerics;

namespace SimsEngine.Simulation;

public sealed partial class SimulationWorld
{

    public bool FindLocation(XObject stackObject, FindLocationParams parameters, out ObjectPosition found, TreeStack? checkStack = null)
    {
        ArgumentNullException.ThrowIfNull(stackObject);
        var size = LotGeometry.LotDimension;
        var height = parameters.Height is >= 1 and <= 2 ? parameters.Height : 1;
        var centerPosition = new ObjectPosition(parameters.CenterX, parameters.CenterY, height);
        if (parameters.RandomizeCenter)
        {
            if (!parameters.HasTarget || ((centerPosition.X >> 4) == 1 && (centerPosition.Y >> 4) == 1))
            {
                var randY = (int)(NextRandom() % (uint)size);
                var randX = (int)(NextRandom() % (uint)size);
                centerPosition = new ObjectPosition(randX * 16 + 8, randY * 16 + 8, height);
            }
            else
            {
                var baseTileX = centerPosition.X >> 4;
                var baseTileY = centerPosition.Y >> 4;
                var scatteredX = baseTileX;
                var scatteredY = baseTileY;
                for (var scatterTry = 0; scatterTry < 32; scatterTry++)
                {
                    var dy = (int)(NextRandom() % 10) - 5;
                    var dx = (int)(NextRandom() % 10) - 5;
                    var candX = baseTileX + dx;
                    var candY = baseTileY + dy;
                    if (candX >= 1 && candX < size - 1 && candY >= 1 && candY < size - 1)
                    {
                        scatteredX = candX;
                        scatteredY = candY;
                        break;
                    }
                }
                centerPosition = new ObjectPosition(scatteredX * 16 + 8, scatteredY * 16 + 8, height);
            }
        }
        var transformedCenter = LotGeometry.TransformSearchCenter(centerPosition, LotTransformParameter);
        var centerX = Math.Clamp(transformedCenter.X >> 4, 1, size - 2);
        var centerY = Math.Clamp(transformedCenter.Y >> 4, 1, size - 2);
        var hasCenterRoom = TryGetRoomAtTile(centerX, centerY, height, out var centerRoom);
        var offsetX = 0;
        var offsetY = 0;
        var consecutiveOffLot = 0;
        for (var attempt = 0; attempt < 0x1000; attempt++)
        {
            var x = centerX + offsetX;
            var y = centerY + offsetY;
            var insideLot = x >= 1 && y >= 1 && x < size - 1 && y < size - 1;
            consecutiveOffLot = insideLot ? 0 : consecutiveOffLot + 1;
            var hasCandidateRoom = insideLot && TryGetRoomAtTile(x, y, height, out var candidateRoom);
            var candidateRoomKey = hasCandidateRoom ? RoomAtTile(x, y, height) : (short)0;
            if (insideLot &&
                !TileHasDiagonalWall(x, y, height) &&
                (parameters.ContinueFlag == 0 || !hasCenterRoom || !hasCandidateRoom || candidateRoomKey == centerRoom) &&
                (parameters.FlagB == 0 || TileValueAt(x, y, height) == 0) &&
                PassesFindLocationWaterChecks(x, y, height, parameters.FlagC))
            {
                var candidate = new ObjectPosition(x * 16 + 8, y * 16 + 8, height);
                if (CanPlaceObject(stackObject, candidate, checkStack))
                {
                    found = candidate;
                    return true;
                }
            }

            if (consecutiveOffLot >= size * 8) break;

            AdvanceFindLocationOffset(parameters.Direction, ref offsetX, ref offsetY);
        }
        found = default;
        return false;
    }

    public bool FindGoodLocation(XObject item, int centerX, int centerY, out ObjectPosition found)
    {
        ArgumentNullException.ThrowIfNull(item);
        var size = LotGeometry.LotDimension;
        var transformedCenter = LotGeometry.TransformSearchCenter(
            new ObjectPosition(centerX * 16 + 8, centerY * 16 + 8, 1), LotTransformParameter);
        centerX = transformedCenter.X >> 4;
        centerY = transformedCenter.Y >> 4;
        var dx = 0;
        var dy = 0;
        var consecutiveOffLot = 0;
        for (var attempt = 0; attempt < 0x1000; attempt++)
        {
            var x = centerX + dx;
            var y = centerY + dy;
            var insideLot = x >= 1 && y >= 1 && x < size - 1 && y < size - 1;
            consecutiveOffLot = insideLot ? 0 : consecutiveOffLot + 1;
            if (insideLot)
            {
                var candidate = new ObjectPosition(x * 16 + 8, y * 16 + 8, 1);
                if (CanPlaceObject(item, candidate))
                {
                    found = candidate;
                    return true;
                }
            }

            if (consecutiveOffLot >= size * 8) break;

            var negativeDx = -dx;
            if (dy > negativeDx || dy > dx)
            {
                if (dy > dx)
                {
                    if (dy < negativeDx) dy++;
                    else dx++;
                }
                else if (dy <= negativeDx)
                {
                    if (dy < negativeDx) dy++;
                }
                else dy--;
            }
            else dx--;
        }

        found = default;
        return false;
    }

    private bool PassesFindLocationWaterChecks(int x, int y, int height, byte flagC)
    {
        var waterOk = true;
        if (LotRoomMaps.TryGetValue(height, out var map) && map.TryGetWaterGridByte(x, y, out var value) && value < 0x10)
            waterOk = false;
        if (!waterOk) return false;
        return flagC == 0 || FindLocationWaterOverride || LotTileFlags?.InsideLot(x, y) != false;
    }

    internal bool IsPoolTile(ObjectPosition position)
    {
        if (position.Height != 1 || !LotRoomMaps.TryGetValue(1, out var map)) return false;
        var x = position.X >> 4;
        var y = position.Y >> 4;
        return x > 0 && y > 0 && x < map.Width - 1 && y < map.Height - 1 &&
            map.TryGetWaterGridByte(x, y, out var value) && value < 0x10;
    }

    private static void AdvanceFindLocationOffset(short direction, ref int offsetX, ref int offsetY)
    {
        if (direction == -1)
        {
            if (-offsetX < offsetY)
            {
                if (offsetX >= offsetY)
                {
                    offsetY--;
                    return;
                }
            }
            else if (offsetX >= offsetY)
            {
                offsetX--;
                return;
            }

            if (offsetY < -offsetX)
            {
                if (offsetX < offsetY) offsetY++;
            }
            else
            {
                offsetX++;
            }
            return;
        }

        if (direction is 0 or 4) offsetY = offsetY < 1 ? 1 - offsetY : -offsetY;
        else if (direction is 2 or 6) offsetX = offsetX < 1 ? 1 - offsetX : -offsetX;
    }

    public bool CanPlaceObject(XObject item, ObjectPosition at, TreeStack? checkStack = null)
    {
        ArgumentNullException.ThrowIfNull(item);
        LastPortalPlacementFailureCode = 0;
        LastPlacementFailureCode = 0;
        if (item.RuntimeClass is SimsEngine.Formats.ObjectClass.MultiTileObject or SimsEngine.Formats.ObjectClass.Portal)
        {
            if (!PassesMultiTileMemberPlacementChecks(item, at, checkStack)) return false;
        }
        else if (!PassesCommonPlacementChecks(item, at, checkStack: checkStack) ||
                 !PassesUpperFloorPlacementCheck(item, at)) return false;
        if (!PassesPortalWallStyleCheck(item, at))
        {
            LastPortalPlacementFailureCode = 0x16;
            return false;
        }
        if (!PassesPortalPlacementAlignmentCheck(item, at))
        {
            LastPortalPlacementFailureCode = 3;
            return false;
        }
        return true;
    }

    private bool PassesMultiTileMemberPlacementChecks(XObject item, ObjectPosition requested, TreeStack? checkStack,
        bool hasRelativeObject = false, short relativeObjectClockManagerIndex = 0)
    {
        var itemOffset = MultiTileOffset(item);
        var rootTarget = new ObjectPosition(requested.X - itemOffset.X, requested.Y - itemOffset.Y,
            requested.Height - itemOffset.Height);
        var lead = item.MultiTileMasterId == 0 ? item : ObjectById(item.MultiTileMasterId) ?? item;
        var visited = new HashSet<short>();
        for (var member = lead; member is not null && visited.Add(member.Id);
             member = member.MultiTileNextId == 0 ? null : ObjectById(member.MultiTileNextId))
        {
            var offset = MultiTileOffset(member);
            var memberTarget = new ObjectPosition(rootTarget.X + offset.X, rootTarget.Y + offset.Y,
                rootTarget.Height + offset.Height);
            if (!PassesCommonPlacementChecks(member, memberTarget, hasRelativeObject, checkStack, relativeObjectClockManagerIndex) ||
                !PassesUpperFloorPlacementCheck(member, memberTarget)) return false;
        }
        return true;
    }

    public int LastPortalPlacementFailureCode { get; private set; }

    public int LastPlacementFailureCode { get; internal set; }

    internal void ResetPlacementFailure()
    {
        LastPlacementFailureCode = 0;
        LastPlacementBlockingObjectId = 0;
    }

    internal short LastPlacementBlockingObjectId { get; set; }

    private static bool PassesPortalPlacementAlignmentCheck(XObject item, ObjectPosition requested) =>
        item.RuntimeClass != SimsEngine.Formats.ObjectClass.Portal ||
        ((requested.X & 0x0f) == 8 && (requested.Y & 0x0f) == 8);

    private bool PassesPortalWallStyleCheck(XObject item, ObjectPosition requested)
    {
        if (item.RuntimeClass != SimsEngine.Formats.ObjectClass.Portal) return true;
        var lead = item.MultiTileMasterId == 0 ? item : ObjectById(item.MultiTileMasterId);
        if (lead is null) return true;
        var requestedOffset = MultiTileOffset(item);
        var leadOffset = MultiTileOffset(lead);
        var leadTargetX = requested.X - requestedOffset.X + leadOffset.X;
        var leadTargetY = requested.Y - requestedOffset.Y + leadOffset.Y;
        var leadTargetLevel = requested.Height - requestedOffset.Height + leadOffset.Height;
        foreach (var member in MultiTileMembers(lead))
        {
            if (member.Definition[(int)ObjdField.WallStyle] == 0) continue;
            var localMask = member[ObjectData.WallPlacementFlags] & 5;
            var wallBit = localMask switch { 1 => 2u, 4 => 8u, _ => 0u };
            if (wallBit == 0) continue;
            wallBit = RotatePlacementWallBit(wallBit, (member[ObjectData.Direction] & 7) / 2);

            var memberOffset = MultiTileOffset(member);
            var tileX = (leadTargetX - leadOffset.X + memberOffset.X) >> 4;
            var tileY = (leadTargetY - leadOffset.Y + memberOffset.Y) >> 4;
            var level = leadTargetLevel - leadOffset.Height + memberOffset.Height;
            var size = LotGeometry.LotDimension;
            if (tileX <= 0 || tileY <= 0 || tileX >= size - 1 || tileY >= size - 1) continue;
            if (!LotRoomMaps.TryGetValue(level, out var map) || map.ExpandedWallAt(tileX, tileY) is not { } walls)
                return false;
            if (walls.WallCategory(wallBit) != 1) return false;
        }
        return true;
    }

    internal bool CanPlaceRouteCandidate(XObject item, ObjectPosition at, XObject? referenceObject,
        int referenceSlotIndex = -1, TreeStack? checkStack = null)
    {
        LastPlacementFailureCode = 0;
        if (referenceObject is null) return CanPlaceObject(item, at, checkStack);
        return CanPlaceReferencedSlot(item, at, referenceObject, referenceSlotIndex);
    }

    internal bool CanUserPlaceReferencedSlot(XObject item, ObjectPosition at, XObject referenceObject,
        int referenceSlotIndex = -1)
    {
        if (!CanPlaceReferencedSlot(item, at, referenceObject, referenceSlotIndex)) return false;
        if (referenceSlotIndex >= 0 && (at.X & 0x0f) == 8 && (at.Y & 0x0f) == 8 &&
            referenceObject.FootprintSlots[referenceSlotIndex].HeightCode is > 4 and < 8)
        {
            LastPlacementFailureCode = 0x0b;
            return false;
        }
        return true;
    }

    internal bool CanPlaceRelativeObject(XObject item, ObjectPosition at, XObject referenceObject,
        int referenceSlotIndex)
    {
        ArgumentNullException.ThrowIfNull(item);
        ArgumentNullException.ThrowIfNull(referenceObject);
        return CanPlaceReferencedSlot(item, at, referenceObject, referenceSlotIndex);
    }

    private bool CanPlaceReferencedSlot(XObject item, ObjectPosition at, XObject referenceObject,
        int referenceSlotIndex)
    {
        LastPlacementFailureCode = 0;
        if (((unchecked((ushort)item[ObjectData.Flags]) |
              unchecked((ushort)referenceObject[ObjectData.Flags])) & 0x0004) != 0)
        {
            LastPlacementFailureCode = 0x0c;
            return false;
        }
        if (referenceSlotIndex >= 0)
        {
            if (referenceSlotIndex >= referenceObject.FootprintSlots.Count)
            {
                LastPlacementFailureCode = 0x0d;
                return false;
            }
            var slot = referenceObject.FootprintSlots[referenceSlotIndex];
            var occupant = slot.OccupantObjectId;
            if (occupant != 0 && occupant != item.ClockManagerIndex)
            {
                LastPlacementFailureCode = 0x0b;
                return false;
            }
            if (item is not XPerson && item.Definition[(int)ObjdField.Type] != XPerson.PersonType)
            {
                var itemCenteredAndBlocking = slot.X == 0f && slot.Y == 0f &&
                    (unchecked((ushort)item[ObjectData.Flags]) & 0x2000) == 0;
                foreach (var otherSlot in referenceObject.FootprintSlots)
                {
                    if (otherSlot.HeightCode != slot.HeightCode || otherSlot.OccupantObjectId == 0 ||
                        otherSlot.OccupantObjectId == item.ClockManagerIndex)
                        continue;
                    if (otherSlot.X == 0f && otherSlot.Y == 0f)
                    {
                        var otherObj = item.ObjectTableEntry(otherSlot.OccupantObjectId) ??
                            ObjectTableEntry(otherSlot.OccupantObjectId);
                        if (otherObj is null || (unchecked((ushort)otherObj[ObjectData.Flags]) & 0x2000) == 0)
                        {
                            LastPlacementFailureCode = 0x0b;
                            return false;
                        }
                    }
                    if (itemCenteredAndBlocking)
                    {
                        LastPlacementFailureCode = 0x0b;
                        return false;
                    }
                }
            }
            var heightCode = slot.HeightCode;
            var allowedHeightFlags = unchecked((ushort)item[ObjectData.AllowedHeightFlags]);
            if (heightCode == 0 ||
                (allowedHeightFlags & (1 << ((heightCode - 1) & 0x1f))) == 0)
            {
                LastPlacementFailureCode = 0x18;
                return false;
            }
            if (item[ObjectData.Weight] > referenceObject[ObjectData.SupportStrength])
            {
                LastPlacementFailureCode = 0x0e;
                return false;
            }
            if (HasRelativePlacementCycle(item, referenceObject))
            {
                LastPlacementFailureCode = 0x0b;
                return false;
            }
        }
        var relativePosition = referenceObject.Position;
        if (!PassesCommonPlacementChecks(item, relativePosition, hasRelativeObject: true,
                relativeObjectClockManagerIndex: referenceObject.ClockManagerIndex) ||
            !PassesUpperFloorPlacementCheck(item, relativePosition)) return false;
        return true;
    }

    private bool HasRelativePlacementCycle(XObject item, XObject referenceObject)
    {
        var current = referenceObject;
        var visited = new HashSet<short>();
        while (visited.Add(current.ClockManagerIndex))
        {
            if (ReferenceEquals(current, item)) return true;
            var overlap = current;
            var overlapVisited = new HashSet<short> { overlap.ClockManagerIndex };
            while (overlap[ObjectData.SlotHierNumber] == 0 && overlap[ObjectData.ParentId] > 0)
            {
                var next = overlap.ObjectTableEntry(overlap[ObjectData.ParentId]) ?? ObjectTableEntry(overlap[ObjectData.ParentId]);
                if (next is null) break;
                if (next.Slots.Count == 0 || next.Slots[0] != overlap.ClockManagerIndex) break;
                if (!overlapVisited.Add(next.ClockManagerIndex)) return true;
                overlap = next;
            }
            var parentKey = overlap[ObjectData.ParentId];
            if (parentKey <= 0 || (overlap.ObjectTableEntry(parentKey) ?? ObjectTableEntry(parentKey)) is not { } parent)
                return false;
            current = parent;
        }
        return true;
    }

    private bool PassesUpperFloorPlacementCheck(XObject item, ObjectPosition at)
    {
        if (at.Height <= 1) return true;
        var flags = unchecked((ushort)item[ObjectData.PlacementFlags]);
        var floorWord = LotRoomMaps.TryGetValue(at.Height, out var roomMap)
            ? roomMap.FloorGridWordOrZeroAt(at.X >> 4, at.Y >> 4)
            : (ushort)0;
        if ((flags & 0x0200) != 0 || floorWord != 0) return true;
        LastPlacementFailureCode = 0x12;
        return false;
    }

    internal short InitializePortalRouteCosts(XObject routeOwner)
    {
        var current = routeOwner[ObjectData.RouteId];
        if (current == 0)
        {
            var used = new HashSet<short>();
            foreach (var entry in ClockManager.Entries)
                if (entry.Object is { } item && item[ObjectData.RouteId] > 0)
                    used.Add(item[ObjectData.RouteId]);
            foreach (var portal in WalkOrder.Where(item => item.RuntimeClass == SimsEngine.Formats.ObjectClass.Portal))
                if (portal[ObjectData.RouteId] > 0)
                    used.Add(portal[ObjectData.RouteId]);

            for (short candidate = 1; candidate <= 9999; candidate++)
            {
                if (used.Contains(candidate)) continue;
                routeOwner[ObjectData.RouteId] = candidate;
                current = candidate;
                break;
            }
        }

        if (current > 0)
            foreach (var portal in WalkOrder.Where(item => item.RuntimeClass == SimsEngine.Formats.ObjectClass.Portal))
                portal.SetPortalRouteCost(current, XObject.UninitializedPortalRouteCost);
        return current;
    }

    public int ActiveLotDimension
    {
        get
        {
            var configured = this[SimulationGlobal.LotSize];
            return configured is > 3 and <= LotGeometry.LotDimension
                ? configured
                : LotGeometry.LotDimension;
        }
    }

    private bool PassesCommonPlacementChecks(XObject item, ObjectPosition at, bool hasRelativeObject = false,
        TreeStack? checkStack = null, short relativeObjectClockManagerIndex = 0)
    {
        var tileX = at.X >> 4;
        var tileY = at.Y >> 4;
        var size = ActiveLotDimension;
        if (tileX <= 0 || tileY <= 0 || tileX >= size - 1 || tileY >= size - 1)
        {
            LastPlacementFailureCode = 1;
            return false;
        }
        if (at.Height is < 1 or > 3)
        {
            LastPlacementFailureCode = 2;
            return false;
        }

        var placementFlags = unchecked((ushort)item[ObjectData.PlacementFlags]);
        if (at.Height >= 2 && (placementFlags & 0x1000) != 0)
        {
            LastPlacementFailureCode = 0x1f;
            return false;
        }

        // RequireWater rejects dry tiles; AllowOnWater is needed on water.
        if (!hasRelativeObject)
        {
            var hasWaterAtTile = HasPlacementEligibilityAt(tileX, tileY, at.Height);
            if (!hasWaterAtTile)
            {
                if ((placementFlags & 0x2020) != 0)
                {
                    LastPlacementFailureCode = 0x2f;
                    return false;
                }
            }
            else if ((placementFlags & 0x2007) != 0 && (placementFlags & 0x0004) == 0 &&
                     !ObjectsAtTile(tileX, tileY, at.Height).Any(obj => !ReferenceEquals(obj, item) &&
                         (unchecked((ushort)obj[ObjectData.Flags]) & 0x1000) != 0))
            {
                LastPlacementFailureCode = 0x1d;
                return false;
            }
        }

        if (!hasRelativeObject && item.Definition[(int)ObjdField.Type] != XPerson.PersonType &&
            (at.Height == 1 || (placementFlags & 0x1000) == 0) &&
            !PassesWallPlacementCheck(item, tileX, tileY, at.Height)) return false;

        // Level 1 pool tiles are identified by an Arry 9 grid value below 0x10.
        if (at.Height == 1 && LotRoomMaps.TryGetValue(1, out var roomMap))
        {
            var groundClass = roomMap.WaterGridByteAt(tileX, tileY);
            var flags = unchecked((ushort)item[ObjectData.PlacementFlags]);
            if ((flags & 0x0800) == 0 && groundClass < 0x10)
            {
                LastPlacementFailureCode = 0x1d;
                return false;
            }
            if ((flags & 0x1000) != 0 && groundClass >= 0x10)
            {
                LastPlacementFailureCode = 0x1e;
                return false;
            }
        }

        if (!hasRelativeObject && item is not XPerson && item.Definition[(int)ObjdField.Type] != XPerson.PersonType &&
            (placementFlags & 0x0103) != 0 && (placementFlags & 0x0100) == 0 && LotTerrain is { } terrain)
        {
            var corners = terrain.Corners(tileX, tileY);
            if (!(corners[0] == corners[1] && corners[0] == corners[2] && corners[0] == corners[3]))
            {
                LastPlacementFailureCode = 0x11;
                return false;
            }
        }

        // AllowOnFloor (0x01) covers floors and pool deck (Arry 9 == 0x10).
        if (!hasRelativeObject && item is not XPerson && item.Definition[(int)ObjdField.Type] != XPerson.PersonType &&
            (placementFlags & 0x0003) != 0 &&
            LotRoomMaps.TryGetValue(at.Height, out var floorRoomMap) && floorRoomMap.HasAuthoritativeOutsideRooms &&
            floorRoomMap.TryGetFloorGridWord(tileX, tileY, out var rawFloorWord))
        {
            var floorWord = rawFloorWord >= 65534 ? (ushort)0 : rawFloorWord;
            var groundByte = at.Height == 1 ? floorRoomMap.WaterGridByteAt(tileX, tileY) : (byte)0xff;
            var isPoolOrWater = (at.Height == 1 && groundByte < 0x10) || HasPlacementEligibilityAt(tileX, tileY, at.Height);
            if (!isPoolOrWater)
            {
                if ((placementFlags & 0x0001) == 0 && (floorWord != 0 || (at.Height == 1 && groundByte == 0x10)))
                {
                    LastPlacementFailureCode = 0x13;
                    return false;
                }
                if ((placementFlags & 0x0002) == 0 && at.Height == 1 && floorWord == 0)
                {
                    LastPlacementFailureCode = 0x14;
                    return false;
                }
            }
        }

        if (!hasRelativeObject)
        {
            var roomPlacement = item[ObjectData.RoomPlacement];
            var managerBit = (BuildModeType6PlacementFlagsAt(tileX, tileY, at.Height) & 0x04) != 0 ||
                (LotRoomMaps.TryGetValue(at.Height, out var rpMap) &&
                 rpMap.HasAuthoritativeOutsideRooms &&
                 RoomIsOutside(RoomAtTile(tileX, tileY, at.Height)));
            if (roomPlacement == 1 && !managerBit)
            {
                LastPlacementFailureCode = 9;
                return false;
            }
            if (roomPlacement == 2 && managerBit)
            {
                LastPlacementFailureCode = 10;
                return false;
            }
        }

        var key = TileValueAt(tileX, tileY, at.Height);
        if (!hasRelativeObject && (placementFlags & 1) == 0 &&
            key != 0 && key != item.ClockManagerIndex && key != relativeObjectClockManagerIndex &&
            (key > short.MaxValue || ObjectTableEntry((short)key) is not { } rootObj || !PlacementNeighborCallbackFilters(item, rootObj)))
        {
            LastPlacementFailureCode = 0x0b;
            return false;
        }
        if (!hasRelativeObject && !PassesFootprintCollisionCheck(item, at, checkStack)) return false;

        if (!hasRelativeObject && (item[ObjectData.AllowedHeightFlags] & 1) == 0)
        {
            LastPlacementFailureCode = 0x18;
            return false;
        }
        return true;
    }

    private bool PassesFootprintCollisionCheck(XObject candidate, ObjectPosition at, TreeStack? checkStack)
    {
        var candidatePerson = candidate.Definition[(int)ObjdField.Type] == XPerson.PersonType
            ? candidate as XPerson ?? throw new InvalidOperationException("Person placement requires an XPerson instance.")
            : null;
        if (candidatePerson is not null &&
            ((candidatePerson[PersonData.IsGhost] & 1) != 0 || (candidatePerson[PersonData.IsLivingGhost] & 1) != 0))
        {
            var hasSecondSlotObject = candidatePerson.Slots.Count > 1 &&
                candidatePerson.ObjectTableEntry(candidatePerson.Slots[1]) is not null;
            var hasParentObject = HasGhostPlacementParentContext(candidatePerson);
            if (!hasSecondSlotObject && !hasParentObject) return true;
        }

        var bounds = candidatePerson?.FootprintBoundsAt(at) ?? PlacementFootprintBounds(candidate, at);
        if (at.Height <= 2)
        {
        foreach (var other in WalkOrder)
        {
            if (ReferenceEquals(candidate, other) || other.Position.Height != at.Height) continue;
            if (other[ObjectData.ParentId] > 0 && other[ObjectData.SlotHierNumber] > 0) continue;
            if (PlacementNeighborCallbackFilters(candidate, other)) continue;

            FootprintBounds otherBounds;
            if (candidatePerson is not null)
            {
                var otherFlags = other[ObjectData.Flags];
                var checksOverlap = (otherFlags & 4) == 0
                    ? (otherFlags & 0x10) == 0
                    : (otherFlags & 2) != 0;
                if (!checksOverlap) continue;
                if (other is XPerson neighborPerson)
                {
                    neighborPerson.RefreshFootprintBounds();
                    otherBounds = neighborPerson.FootprintBounds;
                }
                else otherBounds = PlacementFootprintBounds(other, other.Position);
            }
            else if (other.Definition[(int)ObjdField.Type] == XPerson.PersonType)
            {
                var person = (XPerson)other;
                var candidateFlags = candidate[ObjectData.Flags];
                var checksPersonOverlap = (candidatePerson is not null &&
                                           (candidatePerson[PersonData.IsLivingGhost] & 1) != 0) ||
                                          ((candidateFlags & 4) == 0
                    ? (candidateFlags & 0x10) == 0
                    : (candidateFlags & 2) != 0);
                if ((person[PersonData.IsGhost] & 1) != 0 || !checksPersonOverlap) continue;
                person.RefreshFootprintBounds();
                otherBounds = person.FootprintBounds;
            }
            else
            {
                var candidateFlags = candidate[ObjectData.Flags];
                var otherFlags = other[ObjectData.Flags];
                var sharesRootTile = (other.Position.X >> 4) == (at.X >> 4) &&
                                     (other.Position.Y >> 4) == (at.Y >> 4) &&
                                     (((candidateFlags | otherFlags) & 4) != 0);
                if (sharesRootTile &&
                    (candidate[ObjectData.ExclusivePlacementFlags] & other[ObjectData.ExclusivePlacementFlags] & 1) != 0)
                {
                    LastPlacementFailureCode = 0x0b;
                    return false;
                }
                var candidateBuildModeType = candidate.TypeRecord?.AutonomyAlternativeTypeFlag is > 0 and var candidateAlt
                    ? candidateAlt
                    : candidate.Definition[(int)ObjdField.BuildModeType];
                var otherBuildModeType = other.TypeRecord?.AutonomyAlternativeTypeFlag is > 0 and var otherAlt
                    ? otherAlt
                    : other.Definition[(int)ObjdField.BuildModeType];
                if (sharesRootTile && (candidateFlags & 4) != 0 && (otherFlags & 4) != 0 &&
                    ((candidateBuildModeType == 2) == (otherBuildModeType == 2)))
                {
                    var useLegacyObjectIdField = candidate[ObjectData.WallPlacementFlags] == 0 &&
                        other[ObjectData.WallPlacementFlags] == 0 &&
                        (candidate[ObjectData.ObjectId] != candidate.ClockManagerIndex ||
                         other[ObjectData.ObjectId] != other.ClockManagerIndex);
                    var candidateManagerState = PlacementManagerState(candidate, useLegacyObjectIdField);
                    var otherManagerState = PlacementManagerState(other, useLegacyObjectIdField);
                    if (candidateManagerState != 0 && candidateManagerState == otherManagerState)
                    {
                        LastPlacementFailureCode = 0x16;
                        return false;
                    }
                }
                if ((candidateFlags & 4) != 0 || (otherFlags & 4) != 0) continue;
                otherBounds = PlacementFootprintBounds(other, other.Position);
            }

            if (otherBounds.MinX < bounds.MaxX && bounds.MinX < otherBounds.MaxX &&
                otherBounds.MinY < bounds.MaxY && bounds.MinY < otherBounds.MaxY &&
                !PlacementFunctionFiveAllowsOverlap(candidate, other, checkStack))
            {
                LastPlacementFailureCode = 0x0b;
                LastPlacementBlockingObjectId = other.ClockManagerIndex;
                return false;
            }
        }
        }
        if ((unchecked((ushort)candidate[ObjectData.PlacementFlags]) & 0x0400) == 0 &&
            FootprintIntersectsWall(bounds, at.Height))
        {
            LastPlacementFailureCode = 7;
            return false;
        }
        return true;
    }

    private bool PlacementNeighborCallbackFilters(XObject candidate, XObject other)
    {
        if (candidate is XPerson) return ReferenceEquals(candidate, other);

        var nextId = candidate.MultiTileMasterId == 0 ? candidate.Id : candidate.MultiTileMasterId;
        var visited = new HashSet<short>();
        while (nextId != 0 && visited.Add(nextId))
        {
            if (nextId == other.Id) return true;
            nextId = ObjectById(nextId)?.MultiTileNextId ?? 0;
        }
        return false;
    }

    private static int PlacementManagerState(XObject item, bool useLegacyObjectIdField = false)
    {
        var flags = useLegacyObjectIdField ? item[ObjectData.ObjectId] : item[ObjectData.WallPlacementFlags];
        var state = (flags & 5) switch
        {
            1 => 2,
            4 => 8,
            _ => 0,
        };
        if (state == 0) return 0;

        var rotation = (item[ObjectData.Direction] & 7) >> 1;
        return ((state << rotation) & 0xf) | (state >> (4 - rotation));
    }

    private static bool HasGhostPlacementParentContext(XPerson person)
    {
        XObject current = person;
        var visited = new HashSet<short>();
        while (current[ObjectData.SlotHierNumber] == 0 && visited.Add(current.ClockManagerIndex))
        {
            var parent = person.ObjectTableEntry(current[ObjectData.ParentId]);
            if (parent is null) break;
            current = parent;
        }

        return person.ObjectTableEntry(current[ObjectData.ParentId]) is not null;
    }

    private bool PlacementFunctionFiveAllowsOverlap(XObject candidate, XObject other, TreeStack? checkStack)
    {
        if (checkStack is null) return false;

        var previous = SelfRemovalEndsRun;
        SelfRemovalEndsRun = false;
        try
        {
            var candidateTree = FunctionTreeId(candidate, 5);
            if (candidateTree != 0 && candidate.TypeRecord?.BehaviorScope is { } candidateScope &&
                checkStack.RunToReturn(candidateScope, [], true, candidateTree, other.StackObjectKey)) return true;
            var otherTree = FunctionTreeId(other, 5);
            return otherTree != 0 && other.TypeRecord?.BehaviorScope is { } otherScope &&
                TreeRunner.RunWithParameters(this, other, otherScope, otherTree, candidate.StackObjectKey, other.Temporaries);
        }
        finally
        {
            SelfRemovalEndsRun = previous;
        }
    }

    internal static FootprintBounds PlacementFootprintBounds(XObject item, ObjectPosition at)
    {
        var span = item.Definition[(int)ObjdField.TileWidth];
        if (span == 0) span = 16;
        var half = span / 2;
        var mask = item.TypeRecord?.FootprintMask ?? 0;
        Span<int> extents = stackalloc int[4];
        for (var index = 0; index < extents.Length; index++) extents[index] = (mask >> (index * 4)) & 0xf;
        var direction = item[ObjectData.Direction] & 7;
        var rotation = (8 - direction) / 2;
        return new FootprintBounds(
            at.X + half - extents[(rotation + 1) % 4],
            at.Y + half - extents[(rotation + 2) % 4],
            at.X - half + extents[(rotation + 3) % 4],
            at.Y - half + extents[rotation % 4]);
    }

    internal bool FootprintIntersectsWall(FootprintBounds bounds, int level)
    {
        if (!LotRoomMaps.TryGetValue(level, out var roomMap)) return false;
        for (var tileY = Math.Max(0, bounds.MinY >> 4); tileY <= (bounds.MaxY - 1) >> 4; tileY++)
        for (var tileX = Math.Max(0, bounds.MinX >> 4); tileX <= (bounds.MaxX - 1) >> 4; tileX++)
        {
            var walls = roomMap.ExpandedWallAt(tileX, tileY);
            if (walls is null) continue;
            var mask = walls.Value.UInt32At(0);
            ReadOnlySpan<uint> segments = [1, 2, 0x10, 0x20];
            foreach (var segment in segments)
            {
                if ((mask & segment) == 0) continue;
                var category = walls.Value.WallCategory(segment);
                if (category is 3 or 5 or 6 or 15 or 23) continue;
                var crosses = segment switch
                {
                    1 => StrictlyBetween(tileX * 16, bounds.MinX, bounds.MaxX),
                    2 => StrictlyBetween(tileY * 16, bounds.MinY, bounds.MaxY),
                    0x10 => StrictlyBetween((tileX + tileY + 1) * 16,
                        bounds.MinX + bounds.MinY, bounds.MaxX + bounds.MaxY),
                    _ => StrictlyBetween((tileY - tileX) * 16,
                        bounds.MinY - bounds.MaxX, bounds.MaxY - bounds.MinX),
                };
                if (crosses) return true;
            }
        }
        return false;

        static bool StrictlyBetween(int value, int first, int second) =>
            first < value && value < second || second < value && value < first;
    }

    private bool PassesWallPlacementCheck(XObject item, int tileX, int tileY, int level)
    {
        if (!LotRoomMaps.TryGetValue(level, out var roomMap)) return true;
        var walls = roomMap.ExpandedWallAt(tileX, tileY);
        if (walls is null) return true;
        var wallSegments = walls.Value.UInt32At(0);
        var flags = unchecked((ushort)item[ObjectData.WallPlacementFlags]);
        var direction = item[ObjectData.Direction] & 7;
        var rotation = direction >> 1;

        ReadOnlySpan<uint> localMasks = [2, 1, 4, 8];
        ReadOnlySpan<ushort> requiredFlags = [0x0001, 0x0008, 0x0002, 0x0004];
        ReadOnlySpan<ushort> clearFlags = [0x0100, 0x0800, 0x0200, 0x0400];
        for (var index = 0; index < localMasks.Length; index++)
        {
            var wallBit = localMasks[index];
            wallBit = RotatePlacementWallBit(wallBit, rotation);
            if ((flags & clearFlags[index]) != 0 && (wallSegments & wallBit) != 0) return false;
            if ((flags & requiredFlags[index]) == 0) continue;
            if ((wallSegments & wallBit) == 0) return false;
            var category = walls.Value.WallCategory(wallBit);
            if (category is 2 or 12 or 13 or 14) return false;
        }

        var hasDiagonal = (wallSegments & 0x30) != 0;
        if ((flags & 0x40) != 0 && !hasDiagonal) return false;
        if ((flags & 0x80) == 0 && hasDiagonal) return false;
        return true;
    }

    public static uint RotatePlacementWallBit(uint bit, int turns)
    {
        for (var turn = 0; turn < turns; turn++) bit = bit == 8 ? 1u : bit << 1;
        return bit;
    }

    public void PlaceObject(XObject item, ObjectPosition at, TreeStack? checkStack = null,
        XObject? placementContainer = null, short placementSlotNumber = 0,
        MultiTilePlacementCursorGroup? cursorGroup = null) =>
        PlaceObjectCore(item, at, checkStack, placementContainer, placementSlotNumber, directClassCallback: false, cursorGroup);

    public MultiTilePlacementCursorGroup CreatePlacementCursorGroup(XObject item)
    {
        ArgumentNullException.ThrowIfNull(item);
        return MultiTilePlacementCursorGroup.Create(item, MultiTileMembers(item));
    }

    public EditorPlacementResult PreviewEditorMove(XObject item, ObjectPosition at, byte directionFlag,
        TreeStack? checkStack = null)
    {
        ArgumentNullException.ThrowIfNull(item);
        var members = MultiTileMembers(item);
        var original = members.ToDictionary(member => member,
            member => (member[ObjectData.Direction], member.SavedMultiTileState));
        try
        {
            ApplyEditorFacing(item, members, directionFlag);
            var tiles = EditorTiles(item, at, members);
            var valid = CanPlaceObjectFromEditor(item, at, out var referenceObject, out var referenceSlot, checkStack);
            return new EditorPlacementResult(valid, valid ? "Success" : "Blocked", tiles, referenceObject, referenceSlot);
        }
        finally
        {
            RestoreEditorFacing(original);
        }
    }

    public bool MoveObjectFromEditor(XObject item, ObjectPosition at, byte directionFlag, TreeStack checkStack)
    {
        ArgumentNullException.ThrowIfNull(item);
        ArgumentNullException.ThrowIfNull(checkStack);
        if (!CanPickUpObject(item)) return false;
        var members = MultiTileMembers(item);
        var original = members.ToDictionary(member => member,
            member => (member[ObjectData.Direction], member.SavedMultiTileState));
        var placed = false;
        try
        {
            ApplyEditorFacing(item, members, directionFlag);
            if (!CanPlaceObjectFromEditor(item, at, out var referenceObject, out var referenceSlot, checkStack)) return false;
            var cursorGroup = MultiTilePlacementCursorGroup.Create(item, members);
            var slotNumber = referenceObject is not null && referenceSlot >= 0 ? checked((short)(referenceSlot + 1)) : (short)0;
            var detachedContainers = new List<XObject>();
            foreach (var member in members)
            {
                var oldContainer = ResolveParentContainer(member) ??
                    (member[ObjectData.ContainerId] > 0
                        ? member.ObjectTableEntry(member[ObjectData.ContainerId]) ?? ObjectTableEntry(member[ObjectData.ContainerId]) ?? ObjectById(member[ObjectData.ContainerId])
                        : member[ObjectData.ParentId] > 0 && member[ObjectData.SlotHierNumber] != 0
                            ? member.ObjectTableEntry(member[ObjectData.ParentId]) ?? ObjectTableEntry(member[ObjectData.ParentId]) ?? ObjectById(member[ObjectData.ParentId])
                            : null);
                RunFunctionToCompletion(member, 10);
                if (oldContainer is not null && !ReferenceEquals(oldContainer, member))
                {
                    UnplaceObjectFromGridOrSlot(member);
                    member[ObjectData.ContainerId] = 0;
                    member[ObjectData.SlotNumber] = -1;
                    member[ObjectData.ParentId] = 0;
                    member[ObjectData.SlotHierNumber] = -1;
                    if (!detachedContainers.Contains(oldContainer))
                        detachedContainers.Add(oldContainer);
                }
            }
            foreach (var oldContainer in detachedContainers)
                RunFunctionToCompletion(oldContainer, 9);
            if (item.RuntimeClass == SimsEngine.Formats.ObjectClass.Portal)
            {
                RestoreEditorFacing(original);
                foreach (var member in members) RefreshPortalWallStyleOverlay(member, resetToDefault: true);
                ApplyEditorFacing(item, members, directionFlag);
            }
            PlaceObject(item, at, checkStack, placementContainer: referenceObject, placementSlotNumber: slotNumber, cursorGroup: cursorGroup);
            RunEditorUserPlacementCallbacks(members);
            WakeSimulateOnPauseObjects();
            placed = true;
            return true;
        }
        finally
        {
            if (!placed) RestoreEditorFacing(original);
        }
    }

    public bool CanPlaceObjectFromEditor(XObject item, ObjectPosition at, out XObject? referenceObject, out int referenceSlot,
        TreeStack? checkStack = null)
    {
        ArgumentNullException.ThrowIfNull(item);
        referenceObject = null;
        referenceSlot = -1;
        checkStack ??= TreeRunner.CreateTransientStack(this, item);
        if (CanPlaceObject(item, at, checkStack)) return true;
        if (LastPlacementFailureCode != 0x0b || item.Definition[(int)ObjdField.MasterId] != 0) return false;

        var tileX = at.X >> 4;
        var tileY = at.Y >> 4;
        foreach (var candidate in ObjectsAtTile(tileX, tileY, at.Height))
        {
            if (ReferenceEquals(candidate, item)) continue;
            for (var slotIndex = 0; slotIndex < candidate.FootprintSlots.Count; slotIndex++)
            {
                var heightCode = candidate.FootprintSlots[slotIndex].HeightCode;
                var allowedHeightFlags = unchecked((ushort)item[ObjectData.AllowedHeightFlags]);
                if (heightCode == 0 ||
                    (allowedHeightFlags & (1 << ((heightCode - 1) & 0x1f))) == 0) continue;

                var slotAccepted = CanUserPlaceReferencedSlot(item, at, candidate, slotIndex);
                if (!slotAccepted) continue;

                referenceObject = candidate;
                referenceSlot = slotIndex;
                return true;
            }
        }
        var allowedMask = unchecked((ushort)item[ObjectData.AllowedHeightFlags]);
        LastPlacementFailureCode = allowedMask != 0 && (allowedMask & 0xfff7) == 0 ? 0x24 : 0x0b;
        return false;
    }

    private void ApplyEditorFacing(XObject item, IReadOnlyList<XObject> members, byte directionFlag)
    {
        var targetDirection = directionFlag switch
        {
            1 => 0,
            4 => 2,
            16 => 4,
            64 => 6,
            _ => throw new ArgumentOutOfRangeException(nameof(directionFlag), "Direction must be 1, 4, 16 or 64."),
        };
        var delta = (targetDirection - item[ObjectData.Direction] + 8) & 7;
        foreach (var member in members)
        {
            member[ObjectData.Direction] = (short)((member[ObjectData.Direction] + delta) & 7);
            RotateContainedSlotChildren(member, delta);
        }
        if (delta != 0 && item.RuntimeClass is Formats.ObjectClass.MultiTileObject or Formats.ObjectClass.Portal)
            RefreshMultiTileOffsetsAfterRotation(item);
    }

    public void FaceCreatedObject(XObject root, IReadOnlyList<XObject> members, short direction)
    {
        var delta = (direction - root[ObjectData.Direction] + 8) & 7;
        if (delta == 0) return;
        foreach (var member in members)
        {
            member[ObjectData.Direction] = (short)((member[ObjectData.Direction] + delta) & 7);
            RotateContainedSlotChildren(member, delta);
        }
        if (root.RuntimeClass is Formats.ObjectClass.MultiTileObject or Formats.ObjectClass.Portal)
            RefreshMultiTileOffsetsAfterRotation(root);
    }

    public void RotateObjectForPlacement(XObject item, int quarterSteps)
    {
        var notches = item[ObjectData.RotationNotches];
        var delta = ((quarterSteps * notches) % 8 + 8) & 7;
        if (delta == 0) return;
        var members = MultiTileMembers(item);
        foreach (var member in members)
        {
            member[ObjectData.Direction] = (short)((member[ObjectData.Direction] + delta) & 7);
            RotateContainedSlotChildren(member, delta);
        }
        var lead = item.MultiTileMasterId == 0 ? item : ObjectById(item.MultiTileMasterId) ?? item;
        if (lead.RuntimeClass is Formats.ObjectClass.MultiTileObject or Formats.ObjectClass.Portal)
            RefreshMultiTileOffsetsAfterRotation(lead);
    }

    private void RestoreEditorFacing(
        IReadOnlyDictionary<XObject, (short Direction, MultiTileState? State)> original)
    {
        foreach (var (member, saved) in original)
        {
            var delta = (saved.Direction - member[ObjectData.Direction] + 8) & 7;
            member[ObjectData.Direction] = saved.Direction;
            member.SavedMultiTileState = saved.State;
            if (delta != 0) RotateContainedSlotChildren(member, delta);
        }
    }

    private void RotateContainedSlotChildren(XObject member, int delta)
    {
        if (delta == 0) return;
        foreach (var child in EnumerateContainedSlotChildren(member))
        {
            if (child.Definition is not { Length: > (int)ObjdField.MasterId } ||
                child.Definition[(int)ObjdField.MasterId] == 0)
            {
                if (child[ObjectData.RotationNotches] is 0 or 2)
                    child[ObjectData.Direction] = (short)((child[ObjectData.Direction] + delta) & 7);
            }
            RotateContainedSlotChildren(child, delta);
        }
    }

    public IEnumerable<XObject> EnumerateContainedSlotChildren(XObject member)
    {
        var yielded = new HashSet<XObject>(ReferenceEqualityComparer.Instance);
        for (var slotIndex = 1; slotIndex < member.Slots.Count; slotIndex++)
        {
            var slotKey = member.Slots[slotIndex];
            if (slotKey <= 0) continue;
            var child = member.ObjectTableEntry(slotKey) ?? ObjectTableEntry(slotKey) ?? ObjectById(slotKey);
            if (child is not null && !ReferenceEquals(child, member) && yielded.Add(child))
                yield return child;
        }
        for (var i = 0; i < member.FootprintSlots.Count; i++)
        {
            var slotKey = member.FootprintSlots[i].OccupantObjectId;
            if (slotKey <= 0) continue;
            var child = member.ObjectTableEntry(slotKey) ?? ObjectTableEntry(slotKey) ?? ObjectById(slotKey);
            if (child is not null && !ReferenceEquals(child, member) && yielded.Add(child))
                yield return child;
        }
    }

    internal XObject? ResolveParentContainer(XObject item)
    {
        var current = item;
        var visited = new HashSet<XObject>(ReferenceEqualityComparer.Instance) { current };
        while (current[ObjectData.SlotHierNumber] == 0 && current[ObjectData.ParentId] > 0)
        {
            var next = current.ObjectTableEntry(current[ObjectData.ParentId]) ?? ObjectTableEntry(current[ObjectData.ParentId]);
            if (next is null || !visited.Add(next)) break;
            current = next;
        }
        var containerKey = current[ObjectData.SlotHierNumber] > 0 && current[ObjectData.ParentId] > 0
            ? current[ObjectData.ParentId]
            : item[ObjectData.ContainerId];
        if (containerKey <= 0) return null;
        var container = current.ObjectTableEntry(containerKey) ?? ObjectTableEntry(containerKey) ?? ObjectById(containerKey);
        return container is not null && !ReferenceEquals(container, item) ? container : null;
    }

    private List<EditorPlacementTile> EditorTiles(XObject item, ObjectPosition requested, IReadOnlyList<XObject> members)
    {
        var lead = item.MultiTileMasterId == 0 ? item : ObjectById(item.MultiTileMasterId) ?? item;
        var requestedOffset = MultiTileOffset(item);
        var leadOffset = MultiTileOffset(lead);
        var delegated = ReferenceEquals(item, lead)
            ? requested
            : new ObjectPosition(requested.X - requestedOffset.X, requested.Y - requestedOffset.Y,
                requested.Height - requestedOffset.Height);
        var root = new ObjectPosition(delegated.X - leadOffset.X, delegated.Y - leadOffset.Y,
            delegated.Height - leadOffset.Height);
        return members.Select(member =>
        {
            var offset = MultiTileOffset(member);
            return new EditorPlacementTile((root.X + offset.X) >> 4, (root.Y + offset.Y) >> 4,
                root.Height + offset.Height);
        }).ToList();
    }

    private void PlaceObjectCore(XObject item, ObjectPosition at, TreeStack? checkStack,
        XObject? placementContainer, short placementSlotNumber, bool directClassCallback,
        MultiTilePlacementCursorGroup? cursorGroup = null)
    {
        ArgumentNullException.ThrowIfNull(item);
        var multiTileCallback = item.RuntimeClass == SimsEngine.Formats.ObjectClass.MultiTileObject;
        var groupCallback = item.RuntimeClass is SimsEngine.Formats.ObjectClass.MultiTileObject or SimsEngine.Formats.ObjectClass.Portal;
        if (!multiTileCallback && placementContainer is not null && placementSlotNumber > 0 &&
            placementSlotNumber <= placementContainer.FootprintSlots.Count)
        {
            while (placementContainer.Slots.Count <= placementSlotNumber)
                placementContainer.Slots.Add(0);
        }
        if (!multiTileCallback && placementContainer is not null &&
            (placementSlotNumber < 0 || placementSlotNumber >= placementContainer.Slots.Count))
            throw new InvalidOperationException("The accepted placement request names no allocated parent slot.");
        var members = groupCallback ? MultiTileMembers(item) : [item];
        var originalPositions = members.ToDictionary(member => member, member => member.Position);
        var placementPosition = !multiTileCallback && placementContainer is not null
            ? placementContainer.Position
            : at;
        var containerTree = multiTileCallback || placementContainer is null ? (short)0 : FunctionTreeId(placementContainer, 9);
        var containerScope = placementContainer?.TypeRecord?.BehaviorScope;
        foreach (var member in members)
        {
            var tree = FunctionTreeId(member, 9);
            var scope = member.TypeRecord?.BehaviorScope;
            var runsMemberFunctionNine = tree != 0 && member.Definition[(int)ObjdField.MasterId] == 0;
            var runsTrailingFunctionNine = groupCallback && tree != 0;
            var runsFunctionSix = FunctionTreeId(member, 6) != 0;
            if (((runsMemberFunctionNine || runsTrailingFunctionNine || runsFunctionSix) && scope is null) ||
                (placementContainer is not null && containerTree != 0 && containerScope is null) ||
                ((runsMemberFunctionNine || runsTrailingFunctionNine || runsFunctionSix ||
                  (placementContainer is not null && containerTree != 0)) && checkStack is null))
                throw new NotSupportedException("Placing this object requires its placement BHAV and active stack.");
        }

        var priorContainers = new List<XObject>();
        var memberContainer = multiTileCallback ? null : placementContainer;
        var memberSlot = multiTileCallback ? (short)0 : placementSlotNumber;
        void RecordPriorContainer(XObject oldContainer)
        {
            if (!priorContainers.Contains(oldContainer))
                priorContainers.Add(oldContainer);
        }

        void ApplyMemberCallbacks(XObject member)
        {
            RefreshPlacementWallAdjacency(member, checkStack);
            var tree = FunctionTreeId(member, 9);
            if (tree != 0 && member.Definition[(int)ObjdField.MasterId] == 0)
            {
                if (item.RuntimeClass == SimsEngine.Formats.ObjectClass.Portal && placementContainer is not null)
                    TreeRunner.RunWithParameters(this, placementContainer, member.TypeRecord?.BehaviorScope, tree, 0, []);
                else if (checkStack is not null && checkStack.GetType().DeclaringType != typeof(TreeRunner))
                    checkStack.RunToReturn(member.TypeRecord?.BehaviorScope, [], false, tree, 0);
                else
                    TreeRunner.RunWithParameters(this, member, member.TypeRecord?.BehaviorScope, tree, 0, []);
            }
            if (!multiTileCallback && placementContainer is not null && containerTree != 0)
            {
                TreeRunner.RunWithParameters(this, placementContainer, containerScope, containerTree, 0, []);
            }
            if (originalPositions.TryGetValue(member, out var original) &&
                (original.X != member.Position.X || original.Y != member.Position.Y))
                member.PositionRefreshPending = true;
        }

        var placedMembers = PlaceObjectOrMultiTileGroup(item, placementPosition,
            groupCallback ? ApplyMemberCallbacks : null, placementSlotNumber, checkStack, directClassCallback,
            cursorGroup, memberContainer, memberSlot, RecordPriorContainer);
        if (groupCallback)
        {
            foreach (var member in placedMembers)
            {
                var tree = FunctionTreeId(member, 9);
                if (tree != 0)
                {
                    if (checkStack is not null && checkStack.GetType().DeclaringType != typeof(TreeRunner))
                        checkStack.RunToReturn(member.TypeRecord?.BehaviorScope, [], false, tree, 0);
                    else
                        TreeRunner.RunWithParameters(this, member, member.TypeRecord?.BehaviorScope, tree, 0, []);
                }
            }
        }
        else ApplyMemberCallbacks(item);
        foreach (var oldContainer in priorContainers)
            RunFunctionToCompletion(oldContainer, 9);
        if (item.RuntimeClass == SimsEngine.Formats.ObjectClass.Portal)
        {
            foreach (var member in placedMembers) RefreshPortalWallStyleOverlay(member);
            foreach (var portal in WalkOrder.Where(candidate => candidate.RuntimeClass == SimsEngine.Formats.ObjectClass.Portal))
                portal.ResetAllocatedPortalRouteCosts();
        }
    }

    public void RefreshSavedPortalWallStyles()
    {
        foreach (var portal in WalkOrder.Where(item => item.RuntimeClass == SimsEngine.Formats.ObjectClass.Portal).ToArray())
        {
            RefreshPortalWallStyleOverlay(portal);
        }
    }

    private void RefreshPortalWallStyleOverlay(XObject member, bool resetToDefault = false)
    {
        var sourceWallStyle = member.Definition[(int)ObjdField.WallStyle];
        if (sourceWallStyle == 0) return;
        var wallStyle = resetToDefault ? (ushort)1 : unchecked((ushort)sourceWallStyle);
        var localMask = member[ObjectData.WallPlacementFlags] & 5;
        var wallBit = localMask switch { 1 => 2u, 4 => 8u, _ => 0u };
        if (wallBit == 0) return;
        wallBit = RotatePlacementWallBit(wallBit, (member[ObjectData.Direction] & 7) / 2);
        var tileX = member.Position.X >> 4;
        var tileY = member.Position.Y >> 4;
        if (tileX <= 0 || tileY <= 0 || !LotRoomMaps.TryGetValue(member.Position.Height, out var roomMap) ||
            tileX >= roomMap.Width - 1 || tileY >= roomMap.Height - 1) return;
        var walls = roomMap.ExpandedWallAt(tileX, tileY);
        if (walls is not { } expanded) return;
        var refreshedWall = expanded.WithWallStyleOverlay(wallStyle, wallBit);
        roomMap.ApplyWallStyleOverlay(tileX, tileY, wallStyle, wallBit, refreshedWall);
        if (resetToDefault)
        {
            MarkPortalWallRefreshRequested(member.Position.Height, tileX, tileY);
        }
        else
        {
            MarkPortalGeometryRefreshRequested(member.Position.Height);
        }
    }

    private void RefreshPlacementWallAdjacency(XObject item, TreeStack? checkStack)
    {
        var tree = FunctionTreeId(item, 6);
        if (tree == 0) return;
        var flags = unchecked((ushort)item[ObjectData.WallAdjacencyFlags]) & 0xffc0;
        var position = item.Position;
        if (LotRoomMaps.TryGetValue(position.Height, out var current) &&
            (position.X >> 4) > 0 && (position.Y >> 4) > 0 &&
            (position.X >> 4) < current.Width - 1 && (position.Y >> 4) < current.Height - 1)
        {
            var tileX = position.X >> 4;
            var tileY = position.Y >> 4;
            var direction = item[ObjectData.Direction] & 7;
            var rotation = ((-direction / 2) & 3);
            var walls = current.ExpandedWallAt(tileX, tileY);
            if (walls is not null)
            {
                var localWalls = walls.Value.WithRotatedSides(rotation);
                foreach (var (localBit, resultFlag) in new (uint Bit, ushort Flag)[]
                         { (1, 1), (2, 4), (4, 2), (8, 8) })
                {
                    if ((localWalls.UInt32At(0) & localBit) == 0) continue;
                    var category = localWalls.WallCategory(localBit);
                    if (category is not (2 or 12 or 13 or 14)) flags |= resultFlag;
                }

                if (position.Height < 1 && LotRoomMaps.TryGetValue(position.Height + 1, out var above))
                {
                    var upperWalls = above.ExpandedWallAt(tileX, tileY);
                    if (upperWalls is not null)
                    {
                        var localUpperWalls = upperWalls.Value.WithRotatedSides(rotation);
                        foreach (var (localBit, resultFlag) in new (uint Bit, ushort Flag)[] { (1, 0x10), (4, 0x20) })
                        {
                            if ((localUpperWalls.UInt32At(0) & localBit) == 0) continue;
                            var category = localUpperWalls.WallCategory(localBit);
                            if (category is not (2 or 12 or 13 or 14)) flags |= resultFlag;
                        }
                    }
                }
            }
        }

        if (flags == unchecked((ushort)item[ObjectData.WallAdjacencyFlags])) return;
        if (checkStack is null) throw new NotSupportedException("Placement wall-adjacency refresh requires the active tree stack.");
        item[ObjectData.WallAdjacencyFlags] = unchecked((short)flags);
        checkStack.RunToReturn(item.TypeRecord?.BehaviorScope, [], false, tree, 0);
    }

    public void PlaceCreatedObject(XObject created, ObjectPosition at)
    {
        ArgumentNullException.ThrowIfNull(created);
        PlaceObjectOrMultiTileGroup(created, at);
    }

    public void PlaceCreatedObjectFromEditor(XObject created, ObjectPosition at, XObject? referenceObject = null, int referenceSlot = -1)
    {
        ArgumentNullException.ThrowIfNull(created);
        var members = MultiTileMembers(created);
        var checkStack = TreeRunner.CreateTransientStack(this, created);
        var cursorGroup = MultiTilePlacementCursorGroup.Create(created, members);
        var slotNumber = referenceObject is not null && referenceSlot >= 0 ? checked((short)(referenceSlot + 1)) : (short)0;
        PlaceObject(created, at, checkStack, placementContainer: referenceObject, placementSlotNumber: slotNumber, cursorGroup: cursorGroup);
        RunEditorUserPlacementCallbacks(members);
        WakeSimulateOnPauseObjects();
    }

    private void RunEditorUserPlacementCallbacks(IReadOnlyList<XObject> members)
    {
        var callerLocation = CaptureExecutionLocation();
        try
        {
            foreach (var member in members)
            {
                RunUserPlacementCallbackOnObject(member);
                foreach (var child in EnumerateContainedSlotChildren(member))
                    RunUserPlacementCallbackOnObject(child);
            }
        }
        finally
        {
            RestoreExecutionLocation(callerLocation);
        }

        void RunUserPlacementCallbackOnObject(XObject target)
        {
            var tree = FunctionTreeId(target, 11);
            var scope = target.TypeRecord?.BehaviorScope;
            if (tree == 0 || scope is null) return;
            TreeRunner.RunWithParameters(this, target, scope, tree, 0, []);
        }
    }

    public void WakeSimulateOnPauseObjects()
    {
        const short sleepOpcode = 0;
        const short idleForInputOpcode = 0x11;
        foreach (var item in WalkOrder)
        {
            if (item.ClockManagerIndex <= 0) continue;
            var simulateOnPause = item[ObjectData.SimulateOnPause] != 0 ||
                                  (ClockManager.FlagsAt(item.ClockManagerIndex) & 0x00020000u) != 0;
            if (!simulateOnPause) continue;
            switch (WaitInstructionOpcode(item))
            {
                case sleepOpcode:
                    ClearWaitCounter(item);
                    ClockManager.SetWaitTicksAt(item.ClockManagerIndex, 0);
                    break;
                case idleForInputOpcode:
                    ClearWaitCounter(item);
                    break;
            }
        }
    }

    private const uint WeatherControlGuid = 0xE4B85D21;
    private const uint DyingObjectFlag = 0x40u;

    public bool PlaceCreatedObjectInHand(XObject holder, XObject created)
    {
        ArgumentNullException.ThrowIfNull(holder);
        ArgumentNullException.ThrowIfNull(created);
        if (ReferenceEquals(holder, created) || created[ObjectData.ContainerId] != 0 ||
            holder[ObjectData.ContainerId] == created.ClockManagerIndex) return false;
        return TryPlaceInFirstRealSlot(holder, created);
    }

    // Places into hierarchy slot 1 while intentionally leaving ObjectData.SlotNumber at 0.
    public bool TryPlaceInFirstRealSlot(XObject holder, XObject item)
    {
        ArgumentNullException.ThrowIfNull(holder);
        ArgumentNullException.ThrowIfNull(item);
        if (ReferenceEquals(holder, item) || IsInSlotSubtree(holder, item)) return false;
        if (holder.Slots.Count <= 1) return false;

        var heldKey = item.ClockManagerIndex;
        if (holder.Slots.Count > 1 && holder.Slots[1] == heldKey &&
            item[ObjectData.ContainerId] == holder.ClockManagerIndex &&
            item[ObjectData.ParentId] == holder.ClockManagerIndex &&
            item[ObjectData.SlotHierNumber] == 1) return true;
        if (holder.Slots.Count > 1 && holder.Slots[1] != 0) return false;

        var visited = new HashSet<short> { holder.ClockManagerIndex };
        XObject? ancestor = holder;
        while (ancestor is { } current && current[ObjectData.ParentId] != 0)
        {
            var slotHier = current[ObjectData.SlotHierNumber];
            ancestor = ObjectByStackObject(current, current[ObjectData.ParentId]);
            var isTileOverlap = slotHier == 0 && ancestor is not null &&
                                ancestor.Slots.Count > 0 && ancestor.Slots[0] == current.ClockManagerIndex;
            if (ancestor is null || !visited.Add(ancestor.ClockManagerIndex) ||
                (!isTileOverlap && ReferenceEquals(ancestor, item)))
                return false;
        }

        if (item[ObjectData.ParentId] != 0)
        {
            var priorContainer = ObjectByStackObject(item, item[ObjectData.ParentId]);
            var priorSlot = item[ObjectData.SlotHierNumber];
            if (priorContainer is null || priorSlot < 0 || priorSlot >= priorContainer.Slots.Count ||
                priorContainer.Slots[priorSlot] != heldKey) return false;
        }

        UnplaceObjectFromGridOrSlot(item);
        holder.Slots[1] = heldKey;
        item[ObjectData.ContainerId] = holder.ClockManagerIndex;
        item[ObjectData.ParentId] = holder.ClockManagerIndex;
        item[ObjectData.SlotNumber] = 0;
        item[ObjectData.SlotHierNumber] = 1;
        SetObjectPosition(item, holder.Position);
        return true;
    }

    private List<XObject> PlaceObjectOrMultiTileGroup(XObject item, ObjectPosition at,
        Action<XObject>? placementCallback = null, short sourceParam5 = 0,
        TreeStack? checkStack = null, bool directClassCallback = false,
        MultiTilePlacementCursorGroup? cursorGroup = null,
        XObject? placementContainer = null, short placementSlotNumber = 0,
        Action<XObject>? onPriorContainerDetached = null)
    {
        if (item.RuntimeClass is not (SimsEngine.Formats.ObjectClass.MultiTileObject or SimsEngine.Formats.ObjectClass.Portal))
        {
            if (!directClassCallback) UpdateMultiTileMoveRequest(item, at, sourceParam5);
            MoveTileRoot(item, at, placementContainer, placementSlotNumber, onPriorContainerDetached);
            placementCallback?.Invoke(item);
            return [item];
        }

        var lead = item.MultiTileMasterId == 0 ? item : ObjectById(item.MultiTileMasterId);
        if (lead is null)
        {
            UpdateMultiTileMoveRequest(item, at, sourceParam5);
            MoveTileRoot(item, at, placementContainer, placementSlotNumber, onPriorContainerDetached);
            placementCallback?.Invoke(item);
            return [item];
        }

        var wrapperRoot = !directClassCallback && ReferenceEquals(item, lead);
        if (wrapperRoot) UpdateMultiTileMoveRequest(lead, at, sourceParam5);

        if (wrapperRoot)
            lead.MultiTileMoveFlag1B0 = lead.MultiTileMoveAssociatedObject is null ? (short)1 : (short)0;
        var associatedMove = cursorGroup?.AssociatedObjectFor(lead) ?? lead.MultiTileMoveAssociatedObject;
        if (wrapperRoot && !_activeAssociatedPlacementCallbacks.Contains(lead.Id) &&
            associatedMove is { } associated)
        {
            if (TryApplyAssociatedPlacement(lead, associated, at, checkStack, out var referenceObject,
                    out var referenceSlot))
            {
                var associatedValue = associated.Definition[(int)ObjdField.MasterId] == 0
                    ? 0
                    : associated.TypeRecord?.AlternativeObjectPrice ?? 0;
                var placementContextValue = FamilyBudget?.ReadFamilyBudget() ?? 0;
                if (placementContextValue < associatedValue && associatedValue != 0 &&
                    (cursorGroup?.HasError15Gate(lead) ?? false))
                    LastPlacementFailureCode = 0x15;
                else
                    lead.MultiTileMoveFlag1B0 = 1;
                _activeAssociatedPlacementCallbacks.Add(lead.Id);
                try
                {
                    if (associated is XPerson)
                        PlaceObjectCore(associated, at, checkStack, referenceObject,
                            referenceObject is not null && referenceSlot >= 0
                                ? checked((short)(referenceSlot + 1))
                                : (short)0,
                            directClassCallback: true, cursorGroup);
                    else
                        PlaceObjectCore(associated, at, checkStack,
                            referenceObject is not null && referenceSlot >= 0 ? referenceObject : null,
                            referenceObject is not null && referenceSlot >= 0
                                ? checked((short)(referenceSlot + 1))
                                : (short)0,
                            directClassCallback:
                            associated.RuntimeClass is SimsEngine.Formats.ObjectClass.MultiTileObject or SimsEngine.Formats.ObjectClass.Portal,
                            cursorGroup);
                }
                finally
                {
                    _activeAssociatedPlacementCallbacks.Remove(lead.Id);
                }
                RefreshAssociatedPlacementHelper(associated);
            }
        }

        var requestedOffset = MultiTileOffset(item);
        var delegatedTarget = ReferenceEquals(item, lead)
            ? at
            : new ObjectPosition(at.X - requestedOffset.X, at.Y - requestedOffset.Y,
                at.Height - requestedOffset.Height);
        var leadOffset = MultiTileOffset(lead);
        var visited = new HashSet<short>();
        var movedParts = new List<XObject>();
        var delegatedTileX = delegatedTarget.X >> 4;
        var delegatedTileY = delegatedTarget.Y >> 4;
        var targetInLot = delegatedTileX is > 0 and < LotGeometry.LotDimension - 1 &&
                          delegatedTileY is > 0 and < LotGeometry.LotDimension - 1;
        for (var part = lead; part is not null && visited.Add(part.Id);)
        {
            var nextId = part.MultiTileNextId;
            var partOffset = MultiTileOffset(part);
            var destination = new ObjectPosition(
                delegatedTarget.X - leadOffset.X + partOffset.X,
                delegatedTarget.Y - leadOffset.Y + partOffset.Y,
                delegatedTarget.Height - leadOffset.Height + partOffset.Height);
            if (targetInLot)
            {
                MoveTileRoot(part, destination, placementContainer, placementSlotNumber, onPriorContainerDetached);
                placementCallback?.Invoke(part);
            }
            else
                BeginObjectRemoval(part, 1);
            movedParts.Add(part);
            part = nextId == 0 ? null : ObjectById(nextId);
        }

        if (wrapperRoot)
        foreach (var part in movedParts)
        {
            part.MultiTileMovePositionState = part.Position;
            part.MultiTileMoveFlag1B0 = lead.MultiTileMoveFlag1B0;
            part.MultiTileMoveValue1C0 = -1.0f;
        }
        return movedParts;
    }

    private bool TryApplyAssociatedPlacement(XObject mover, XObject associated, ObjectPosition requested,
        TreeStack? checkStack, out XObject? referenceObject, out int referenceSlot)
    {
        referenceObject = ObjectTableEntry(mover.MultiTileMoveValue1C4);
        referenceSlot = mover.MultiTileMoveValue1C6;
        var accepted = referenceObject is null
            ? CanPlaceObject(associated, requested, checkStack)
            : CanUserPlaceReferencedSlot(associated, requested, referenceObject, referenceSlot);
        if (accepted) return true;

        if (LastPlacementFailureCode != 0x0b || associated.Definition[(int)ObjdField.MasterId] != 0)
            return false;

        var tileX = requested.X >> 4;
        var tileY = requested.Y >> 4;
        foreach (var candidate in ObjectsAtTile(tileX, tileY, requested.Height))
        {
            for (var slotIndex = 0; slotIndex < candidate.FootprintSlots.Count; slotIndex++)
            {
                var heightCode = candidate.FootprintSlots[slotIndex].HeightCode;
                var allowedHeightFlags = unchecked((ushort)associated[ObjectData.AllowedHeightFlags]);
                if (heightCode == 0 ||
                    (allowedHeightFlags & (1 << ((heightCode - 1) & 0x1f))) == 0) continue;

                var slotAccepted = CanUserPlaceReferencedSlot(associated, requested, candidate, slotIndex);
                if (!slotAccepted) continue;

                mover.MultiTileMoveValue1C4 = candidate.ClockManagerIndex;
                mover.MultiTileMoveValue1C6 = checked((short)slotIndex);
                referenceObject = candidate;
                referenceSlot = slotIndex;
                if (associated[ObjectData.RotationNotches] != 0)
                {
                    var candidateDirection = AssociatedPlacementDirection(candidate, requested);
                    var directionDelta = candidateDirection - associated[ObjectData.Direction];
                    var adjustment = directionDelta / associated[ObjectData.RotationNotches];
                    ApplyAssociatedPlacementAdjustment(mover, adjustment, checkStack);
                }
                return true;
            }
        }
        var allowedMask = unchecked((ushort)associated[ObjectData.AllowedHeightFlags]);
        LastPlacementFailureCode = allowedMask != 0 && (allowedMask & 0xfff7) == 0 ? 0x24 : 0x0b;
        return false;
    }

    private int AssociatedPlacementDirection(XObject candidate, ObjectPosition requested)
    {
        var originalDirection = candidate[ObjectData.Direction] & 7;
        if (candidate.Definition[(int)ObjdField.MasterId] == 0) return originalDirection;
        var direction = originalDirection;
        var clearSteps = 0;
        for (var attempt = 0; attempt < 4; attempt++)
        {
            var (x, y) = direction switch
            {
                0 => (-1, 0), 1 => (-1, 1), 2 => (0, 1), 3 => (1, 1),
                4 => (1, 0), 5 => (1, -1), 6 => (0, -1), _ => (-1, -1),
            };
            var adjacent = new ObjectPosition(candidate.Position.X + (x << 4),
                candidate.Position.Y + (y << 4), requested.Height);
            if (!IsAssociatedOffsetTileClear(adjacent)) break;
            direction = (direction + 2) & 7;
            clearSteps++;
        }
        return clearSteps == 4 ? originalDirection : direction;
    }

    private bool IsAssociatedOffsetTileClear(ObjectPosition position)
    {
        foreach (var item in ObjectsAtTile(position.X >> 4, position.Y >> 4, position.Height))
        {
            var flags = unchecked((ushort)item[ObjectData.Flags]);
            var clear = (flags & 0x0004) == 0 ? (flags & 0x0010) != 0 : (flags & 0x0002) == 0;
            if (!clear) return false;
        }
        return true;
    }

    private void ApplyAssociatedPlacementAdjustment(XObject mover, int directionDelta, TreeStack? checkStack)
    {
        var group = MultiTileMembers(mover);
        var savedPosition = mover.Position;

        foreach (var member in group)
        {
            var tree = FunctionTreeId(member, 10);
            if (tree == 0) continue;
            if (checkStack is null || member.TypeRecord?.BehaviorScope is not { } scope)
                throw new NotSupportedException("Associated multi-tile adjustment requires function 10's active tree stack.");
            checkStack.RunToReturn(scope, [], false, tree, 0);
        }
        foreach (var member in group)
        {
            if (member.Definition[(int)ObjdField.MasterId] == 0 && FunctionTreeId(member, 10) is var tree && tree != 0)
            {
                if (checkStack is null || member.TypeRecord?.BehaviorScope is not { } scope)
                    throw new NotSupportedException("Associated multi-tile adjustment requires function 10's active tree stack.");
            }
            BeginObjectRemoval(member, 1);
        }
        RefreshInteractionAfterObjectRemoval(mover);

        var rotation = (unchecked((ushort)mover[ObjectData.RotationNotches]) * directionDelta) & 7;
        if (rotation == 0) return;
        foreach (var member in group)
        {
            member[ObjectData.Direction] = (short)((member[ObjectData.Direction] + rotation) & 7);
            SetObjectPosition(member, member.Position);
        }
        RefreshMultiTileOffsetsAfterRotation(mover);

        if (!CanPlaceObject(mover, savedPosition, checkStack) &&
            !IsInsidePlacementLot(savedPosition))
        {
            foreach (var member in group)
            {
                member[ObjectData.Direction] = (short)((member[ObjectData.Direction] - rotation) & 7);
                SetObjectPosition(member, member.Position);
            }
            RefreshMultiTileOffsetsAfterRotation(mover);
        }
        if (CanPlaceObject(mover, savedPosition, checkStack))
            PlaceObjectCore(mover, savedPosition, checkStack, placementContainer: null,
                placementSlotNumber: 0, directClassCallback: true);
    }

    private void RefreshMultiTileOffsetsAfterRotation(XObject item)
    {
        var lead = item.MultiTileMasterId == 0 ? item : ObjectById(item.MultiTileMasterId) ?? item;
        var leadState = lead.SavedMultiTileState;
        if (leadState is null) return;
        var direction = lead[ObjectData.Direction] & 7;
        foreach (var member in MultiTileMembers(lead))
        {
            if (member.SavedMultiTileState is not { } state) continue;
            var x = state.Value0x194 - leadState.Value0x194;
            var y = state.Value0x198 - leadState.Value0x198;
            (x, y) = direction switch
            {
                0 => (x, y),
                2 => (-y, x),
                4 => (-x, -y),
                6 => (y, -x),
                _ => (0, 0),
            };
            member.SavedMultiTileState = state with
            {
                Value0x1A0 = x,
                Value0x1A4 = y,
                Value0x1A8 = state.Value0x19C - leadState.Value0x19C,
            };
        }
    }

    private static bool IsInsidePlacementLot(ObjectPosition position)
    {
        var x = position.X >> 4;
        var y = position.Y >> 4;
        return x > 0 && y > 0 && x < LotGeometry.LotDimension - 1 && y < LotGeometry.LotDimension - 1;
    }

    private static void RefreshAssociatedPlacementHelper(XObject associated)
    {
        associated.AssociatedPlacementHelper?.RefreshAfterMove();
    }

    private static void UpdateMultiTileMoveRequest(XObject item, ObjectPosition requested, short sourceParam5)
    {
        if (item.MultiTileMovePositionState is { } previous && previous == requested)
            item.MultiTileMoveValue1C6 = sourceParam5;
        else
        {
            item.MultiTileMoveValue1C4 = 0;
            item.MultiTileMoveValue1C6 = 0;
        }
    }

    public List<XObject> MultiTileMembers(XObject item)
    {
        var lead = item.MultiTileMasterId == 0 ? item : ObjectById(item.MultiTileMasterId) ?? item;
        var members = new List<XObject>();
        var visited = new HashSet<short>();
        for (var part = lead; part is not null && visited.Add(part.Id);)
        {
            members.Add(part);
            part = part.MultiTileNextId == 0 ? null : ObjectById(part.MultiTileNextId);
        }
        return members;
    }

    private static ObjectPosition MultiTileOffset(XObject part)
    {
        var state = part.SavedMultiTileState;
        return new ObjectPosition((state?.Value0x1A0 ?? 0) << 4, (state?.Value0x1A4 ?? 0) << 4, state?.Value0x1A8 ?? 0);
    }

    public List<ThreadError> ThreadErrors { get; } = [];
    public List<InteractionGuardError> InteractionGuardErrors { get; } = [];
    public bool CaptureExecutionTrace { get; set; }
    public List<SimulationTraceEntry> ExecutionTrace { get; } = [];
    public List<AutonomyAttemptDiagnostic> AutonomyAttemptTrace { get; } = [];
    public List<SimulationPrimitiveResultTrace> PrimitiveResultTrace { get; } = [];
    public List<SimulationRouteCandidateTrace> RouteCandidateTrace { get; } = [];
    internal string LastRouteCandidateFailureReason { get; set; } = string.Empty;
    public List<SimulationNativeRouteTrace> NativeRouteTrace { get; } = [];
    public List<SimulationRouteSearchTrace> RouteSearchTrace { get; } = [];
    public List<SimulationTreeCallTrace> TreeCallTrace { get; } = [];
    public List<SimulationNamedTreeLookupTrace> NamedTreeLookupTrace { get; } = [];
    public List<SimulationInteractionTestTrace> InteractionTestTrace { get; } = [];

    // STR# language ID (1 = English).
    public byte Language { get; set; } = 1;

    public string? StringTableEntry(XObject? stackObject, XObject me, short table, int index)
    {
        foreach (var candidate in new[] { stackObject?.TypeRecord?.BehaviorScope, me.TypeRecord?.BehaviorScope })
        {
            if (candidate is not Content.BehaviorScope scope) continue;
            foreach (var file in new[] { scope.Private, scope.SemiGlobal, scope.Global })
            {
                if (file is null) continue;
                var chunk = file.Find(ResourceType.Str, unchecked((ushort)table));
                if (chunk is null) continue;
                var strings = StringTable.Read(file, chunk).ForLanguage(Language);
                return index >= 0 && index < strings.Count ? strings[index] : null;
            }
        }
        return null;
    }

    public short NeighborObjectKey(short oneBasedIndex)
    {
        var neighbor = NeighborManagerEntry(oneBasedIndex);
        if (neighbor is null || neighbor.TypeRecordKey == 0) return 0;
        foreach (var item in WalkOrder)
            if (item.TypeRecord?.Key == neighbor.TypeRecordKey) return item.ClockManagerIndex;
        return 0;
    }

    public short NeighborBelongsToHouse(short oneBasedIndex)
    {
        var neighbor = NeighborManagerEntry(oneBasedIndex);
        if (neighbor is null || NeighborInteractionManagerTypeKeys.Count == 0) return 0;
        return NeighborInteractionManagerTypeKeys.Contains(neighbor.TypeRecordKey) ? (short)1 : (short)0;
    }

    public short NeighborWordE8(short oneBasedIndex) =>
        NeighborManagerEntry(oneBasedIndex) is { } neighbor ? neighbor.PersonData[58] : (short)0;

    public short NeighborFriendCount(short oneBasedIndex)
    {
        var subject = NeighborManagerEntry(oneBasedIndex);
        if (subject is null) return 0;
        if (subject.RelationshipsChangedFlag24)
        {
            var count = 0;
            foreach (var candidate in NeighborWalkOrder)
            {
                if (candidate is null || ReferenceEquals(candidate, subject)) continue;
                if (candidate.FriendEligibilityObjectFlagsB4 is not { } flags || (flags & 0xC) != 4) continue;
                if (candidate.PersonData[61] == 0) continue;
                if (subject.Relationships.Count(candidate.Id) == 0 || candidate.Relationships.Count(subject.Id) == 0) continue;
                if (subject.Relationships.Get(candidate.Id, 0) < FriendshipThreshold ||
                    candidate.Relationships.Get(subject.Id, 0) < FriendshipThreshold) continue;
                count++;
            }
            subject.FriendCountWord20 = count;
        }
        return unchecked((short)subject.FriendCountWord20);
    }

    public short NeighborInteractionValue(short oneBasedIndex)
    {
        if (NeighborhoodFamilies is { } families && NeighborManagerEntry(oneBasedIndex) is { } neighborState)
            return families.HouseNumberForMember(neighborState.TypeRecordKey);
        var neighbor = NeighborTableEntry(oneBasedIndex);
        if (neighbor is null) return 0;
        foreach (var item in InteractionLookupOrder)
            if (item.HasNeighborSubobjectReference(neighbor))
                return unchecked((short)item.Position.Height);
        return 0;
    }

    public short NeighborInteractionFlag(short oneBasedIndex, int flagBit)
    {
        if (flagBit is not (0 or 1)) throw new ArgumentOutOfRangeException(nameof(flagBit));
        var neighbor = NeighborManagerEntry(oneBasedIndex);
        if (neighbor is null || neighbor.PersonData[61] == 0) return 0;
        var familyNumber = neighbor.PersonData[61];
        if (NeighborhoodFamilies is { } families && families.Exists(familyNumber))
            return families.HouseNumber(familyNumber) != 0 ? (short)((families.Flags(familyNumber) >> flagBit) & 1) : (short)0;
        var interactionObject = FindInteractionObjectByTableWord(familyNumber);
        if (interactionObject is null || interactionObject.Position.Height == 0) return 0;
        return (short)((interactionObject.NeighborInteractionFlagsWord138 >> flagBit) & 1);
    }

    public short NeighborInteractionCount(short oneBasedIndex)
    {
        if (NeighborhoodFamilies is { } families && NeighborManagerEntry(oneBasedIndex) is { } neighborState)
        {
            var familyNumber = neighborState.PersonData[61];
            if (familyNumber == 0 || !families.Exists(familyNumber)) return 0;
            return unchecked((short)CountFamilyFriends(families, familyNumber));
        }
        var neighbor = NeighborTableEntry(oneBasedIndex);
        if (neighbor is null || neighbor.NeighborInteractionTargetWordEE == 0) return 0;
        var interactionObject = FindInteractionObjectByTableWord(neighbor.NeighborInteractionTargetWordEE);
        if (interactionObject is null) return 0;
        if (interactionObject.NeighborInteractionStateByte124 != 0)
        {
            interactionObject.NeighborInteractionCountWord120 = CountNeighborInteractions(interactionObject);
            interactionObject.NeighborInteractionStateByte124 = 0;
        }
        return unchecked((short)interactionObject.NeighborInteractionCountWord120);
    }

    public int CountFamilyFriends(INeighborhoodFamilies families, short familyNumber)
    {
        var memberGuids = families.MemberGuids(familyNumber);
        if (memberGuids.Count == 0) return 0;
        var count = 0;
        foreach (var candidate in NeighborWalkOrder)
        {
            if (candidate is null || families.HasMember(familyNumber, candidate.TypeRecordKey) ||
                candidate.PersonData[61] == 0) continue;

            foreach (var memberGuid in memberGuids)
            {
                var memberNeighbor = NeighborWalkOrder.FirstOrDefault(item => item is not null && item.TypeRecordKey == memberGuid);
                if (memberNeighbor is null) continue;
                if (candidate.Relationships.Count(memberNeighbor.Id) <= 0 ||
                    memberNeighbor.Relationships.Count(candidate.Id) <= 0) continue;
                if (candidate.Relationships.Get(memberNeighbor.Id, 0) < FriendshipThreshold ||
                    memberNeighbor.Relationships.Get(candidate.Id, 0) < FriendshipThreshold ||
                    candidate.PersonData[65] >= 2) continue;

                count++;
                break;
            }
        }
        return count;
    }

    public static int CountFamilyFriends(Family family, Neighbors neighbors, int friendshipThreshold = 50)
    {
        ArgumentNullException.ThrowIfNull(family);
        ArgumentNullException.ThrowIfNull(neighbors);
        return CountFamilyFriends(family.Members, neighbors.Entries, friendshipThreshold);
    }

    public static int CountFamilyFriends(IReadOnlyList<uint> familyMemberGuids, IReadOnlyList<Neighbor> neighbors,
        int friendshipThreshold = 50)
    {
        ArgumentNullException.ThrowIfNull(familyMemberGuids);
        ArgumentNullException.ThrowIfNull(neighbors);
        if (familyMemberGuids.Count == 0 || neighbors.Count == 0) return 0;

        var memberSet = new HashSet<uint>(familyMemberGuids);
        var membersByGuid = new Dictionary<uint, Neighbor>();
        foreach (var entry in neighbors)
        {
            if (memberSet.Contains(entry.Guid) && !membersByGuid.ContainsKey(entry.Guid))
                membersByGuid[entry.Guid] = entry;
        }

        var enforceFamilyNumber = neighbors.Any(entry => entry.PersonData is { Count: > 61 } pd && pd[61] != 0);
        var hasMemberSideRelationships = neighbors.Any(entry => memberSet.Contains(entry.Guid) && entry.Relationships.Count > 0);
        var hasCandidateSideRelationships = neighbors.Any(entry => !memberSet.Contains(entry.Guid) && entry.Relationships.Count > 0);
        var requireMutual = hasMemberSideRelationships && hasCandidateSideRelationships;

        var count = 0;
        foreach (var candidate in neighbors)
        {
            if (memberSet.Contains(candidate.Guid)) continue;
            if (enforceFamilyNumber && (candidate.PersonData is not { Count: > 61 } familyPd || familyPd[61] == 0))
                continue;
            if (candidate.PersonData is { Count: > 65 } speciesPd && speciesPd[65] >= 2)
                continue;

            foreach (var memberGuid in familyMemberGuids)
            {
                if (!membersByGuid.TryGetValue(memberGuid, out var member)) continue;
                var hasCandidateToMember = candidate.Relationships.TryGetValue(member.NeighborId, out var cToM) &&
                                           cToM.Count > 0 && cToM[0] >= friendshipThreshold;
                var hasMemberToCandidate = member.Relationships.TryGetValue(candidate.NeighborId, out var mToC) &&
                                           mToC.Count > 0 && mToC[0] >= friendshipThreshold;
                var isFriend = requireMutual
                    ? hasCandidateToMember && hasMemberToCandidate
                    : hasCandidateToMember || hasMemberToCandidate;
                if (!isFriend) continue;

                count++;
                break;
            }
        }

        return count;
    }

    public int CountFamilyFriends(Family family)
    {
        ArgumentNullException.ThrowIfNull(family);
        if (family.Members.Count == 0) return 0;
        var memberSet = new HashSet<int>(family.Members.Select(guid => unchecked((int)guid)));
        var roster = NeighborWalkOrder.Count > 0
            ? NeighborWalkOrder.Where(n => n is not null).Select(n => n!).ToArray()
            : Neighbors.Values.ToArray();
        if (roster.Length == 0) return 0;

        var enforceFamilyNumber = roster.Any(n => n.PersonData[61] != 0);
        var hasMemberSide = roster.Any(n => memberSet.Contains(n.TypeRecordKey) && n.Relationships.Snapshot().Count > 0);
        var hasCandidateSide = roster.Any(n => !memberSet.Contains(n.TypeRecordKey) && n.Relationships.Snapshot().Count > 0);
        var requireMutual = hasMemberSide && hasCandidateSide;
        var threshold = FriendshipThreshold > 0 ? FriendshipThreshold : 50;

        var count = 0;
        foreach (var candidate in roster)
        {
            if (memberSet.Contains(candidate.TypeRecordKey)) continue;
            if (enforceFamilyNumber && candidate.PersonData[61] == 0) continue;
            if (candidate.PersonData[65] >= 2) continue;

            foreach (var memberKey in memberSet)
            {
                var member = roster.FirstOrDefault(n => n.TypeRecordKey == memberKey);
                if (member is null) continue;
                var cToM = candidate.Relationships.Count(member.Id) > 0 &&
                           candidate.Relationships.Get(member.Id, 0) >= threshold;
                var mToC = member.Relationships.Count(candidate.Id) > 0 &&
                           member.Relationships.Get(candidate.Id, 0) >= threshold;
                if (requireMutual ? (cToM && mToC) : (cToM || mToC))
                {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
}
