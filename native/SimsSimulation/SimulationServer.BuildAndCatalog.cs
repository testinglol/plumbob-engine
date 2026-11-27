using System.Buffers.Binary;
using System.Diagnostics;
using System.Security.Cryptography;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Text.Json.Serialization;
using System.Text.RegularExpressions;
using SimsEngine.Content;
using SimsEngine.Formats;
using SimsEngine.Simulation;
using SimsEngine.World;

namespace SimsSimulation;

internal sealed partial class SimulationServer
{

    private XObject BuyObject(JsonElement request, out int catalogPrice)
    {
        var current = world ?? throw new InvalidOperationException("There is no loaded native lot.");
        if (speed != 0) throw new InvalidOperationException("Pause the simulation before editing objects");
        if (current.HasVisibleBlockingDialog) throw new InvalidOperationException("Answer the active game dialog before editing objects");
        if (current.FamilyBudget is not FamilyBudget budget || (budget.ActiveFamily is null && current[SimulationGlobal.SimlessBuildMode] == 0))
            throw new InvalidOperationException("Object editing requires an active household");

        var guid = request.TryGetProperty("guid", out var guidValue) && guidValue.TryGetUInt32(out var parsedGuid)
            ? parsedGuid : throw new ArgumentException("guid must be an unsigned 32-bit object GUID");
        var entry = registry?.Find(guid) ?? throw new ArgumentException("Object is not in the loaded catalog");
        if (!ObjectCatalog.TryGetEntry(entry, language, CurrentCatalogLotType(), out var catalogItem) || catalogItem is null)
            throw new ArgumentException("Object is not a supported catalog item");

        var price = catalogItem.Price;
        catalogPrice = price;
        var autoPrepFloors = entry.Definition[ObjdField.RoomSort] == 0 && entry.Definition[ObjdField.BuildModeType] is 3 or 5;
        if (!autoPrepFloors && price > budget.ReadFamilyBudget()) throw new InvalidOperationException("Insufficient family funds");
        var x = Coordinate(request, "x");
        var y = Coordinate(request, "y");
        var level = request.TryGetProperty("level", out var levelValue) && levelValue.TryGetInt32(out var parsedLevel)
            ? parsedLevel : throw new ArgumentException("level must be an integer");
        var directionFlag = request.TryGetProperty("direction", out var directionValue) && directionValue.TryGetByte(out var parsedDirection)
            ? parsedDirection : throw new ArgumentException("direction must be 1, 4, 16 or 64");
        var direction = directionFlag switch
        {
            1 => 0,
            4 => 2,
            16 => 4,
            64 => 6,
            _ => throw new ArgumentException("direction must be 1, 4, 16 or 64"),
        };
        if (x < 0 || y < 0 || x >= LotWidth * 16 || y >= LotHeight * 16 || level < 1 || level > Stories)
            throw new ArgumentException("Object position is outside the lot");

        IReadOnlyList<XObject>? group = null;
        XObject? item = null;
        var destination = new ObjectPosition(x, y, level);
        IffFile? previousLotBeforeFireplace = null;
        var lotBeforeBuy = lot;
        using var savedTypes = current.BeginSavedObjectTypeRegistrationScope();
        try
        {
            group = current.ObjectGroupFactory?.Invoke(unchecked((int)guid));
            if (group is { Count: 0 }) throw new ArgumentException("Object group could not be created");
            if (group is { Count: > 0 }) item = group[0];
            else
            {
                if (entry.Definition[ObjdField.MasterId] != 0)
                    throw new ArgumentException("Multi-tile object group creation is unavailable");
                item = current.ObjectFactory?.Invoke(unchecked((int)guid))
                    ?? throw new ArgumentException("Object definition could not be loaded");
                item.Position = new ObjectPosition(-16, -16, level);
                current.Add(item);
                current.InitializeCreatedObject(item);
            }
            var members = group ?? [item];
            current.FaceCreatedObject(item, members, (short)direction);
            var buildMode = ObjectBuildModeType(item);
            if (!current.CanPlaceObjectFromEditor(item, destination, out var referenceObject, out var referenceSlot) &&
                !(buildMode == 3 && TryResolveStairUpperLandingDestination(current, item, members, destination, out destination, out referenceObject, out referenceSlot)))
            {
                if (buildMode is 3 or 5 && lot is { } currentLot &&
                    (TryPrepareFireplaceFloors(current, currentLot, item, members, destination, out var updatedLot, out var netFloorCost) ||
                     (buildMode == 3 && TryResolveStairUpperLandingWithFloorPrep(current, currentLot, item, members, destination, out destination, out updatedLot, out netFloorCost))))
                {
                    if (price + netFloorCost > budget.ReadFamilyBudget())
                        throw new InvalidOperationException("Insufficient family funds");
                    previousLotBeforeFireplace = currentLot;
                    RefreshWorldRoomMaps(current, updatedLot);
                    if (!current.CanPlaceObjectFromEditor(item, destination, out referenceObject, out referenceSlot))
                        throw new InvalidOperationException("Object cannot be placed at that position");
                    lot = updatedLot;
                    price += netFloorCost;
                    previousLotBeforeFireplace = null;
                }
                else
                {
                    if (price > budget.ReadFamilyBudget())
                        throw new InvalidOperationException("Insufficient family funds");
                    throw new InvalidOperationException("Object cannot be placed at that position");
                }
            }
            else if (price > budget.ReadFamilyBudget())
            {
                throw new InvalidOperationException("Insufficient family funds");
            }
            current.PlaceCreatedObjectFromEditor(item, destination, referenceObject, referenceSlot);
            ApplyPortalWallEdits(CapturePortalWallEdits(current, item, resetToDefault: false));
            if ((buildMode == 6 || destination.Height > 2) && lot is { } postBuyLot)
            {
                lot = LotTiles.RefreshStructuralFlags(postBuyLot, current.WalkOrder);
                RefreshWorldRoomMaps(current, lot);
            }
            budget.AlterFamilyBudget(buildMode == 0 ? 6 : 7, price);
            savedTypes.Commit();
            lotValuationEdited = true;
            FlushPendingLotUpdates(current);
            if (buildMode == 0)
            {
                ClearBuildHistory();
            }
            else
            {
                var lead = MultiTileMembers(current, item).FirstOrDefault() ?? item;
                var token = new BuildObjectToken(lead.Id);
                liveTokens[lead.Id] = token;
                undoStack.Push(new BuildBuyEdit(token, guid,
                    destination, directionFlag, price, lotBeforeBuy, lot));
                redoStack.Clear();
            }
            return item;
        }
        catch
        {
            if (previousLotBeforeFireplace is not null)
            {
                lot = previousLotBeforeFireplace;
                RefreshWorldRoomMaps(current, previousLotBeforeFireplace);
            }
            if (group is { Count: > 0 }) current.RemoveCreatedObjectGroup(group[0]);
            else if (item is not null) current.Remove(item.Id);
            throw;
        }
    }

    private object SellObject(JsonElement request)
    {
        var current = world ?? throw new InvalidOperationException("There is no loaded native lot.");
        if (speed != 0) throw new InvalidOperationException("Pause the simulation before editing objects");
        if (current.HasVisibleBlockingDialog) throw new InvalidOperationException("Answer the active game dialog before editing objects");
        if (current.FamilyBudget is not FamilyBudget budget || (budget.ActiveFamily is null && current[SimulationGlobal.SimlessBuildMode] == 0))
            throw new InvalidOperationException("Object editing requires an active household");
        var id = request.TryGetProperty("objectID", out var idValue) && idValue.TryGetInt16(out var parsedId)
            ? parsedId : throw new ArgumentException("objectID must be a 16-bit object id");
        var item = current.ObjectById(id);
        if (item is null || (item is XPerson && !current.CanSellObject(item))) throw new ArgumentException("Object cannot be sold");
        if (!current.CanSellObject(item)) throw new InvalidOperationException("Object cannot be sold");
        var soldMembers = MultiTileMembers(current, item);
        var lead = soldMembers.FirstOrDefault() ?? item;
        var spawnGuid = ResolveCatalogSpawnGuid(lead);
        var leadPosition = lead.Position;
        var leadDirectionFlag = (byte)(1 << (lead[ObjectData.Direction] & 6));
        var savedCurrentValue = lead[ObjectData.CurrentValue];
        var lotBeforeSell = lot;
        var guid = unchecked((uint)(item.TypeRecord?.Key ?? 0));
        var buildMode = ObjectBuildModeType(item);
        var portalEdits = CapturePortalWallEdits(current, item, resetToDefault: true);
        var baseRefund = current.SellObject(item);
        foreach (var member in soldMembers) audio?.RemoveOwner(member.Id);
        audio?.RemoveOwner(item.Id);
        ApplyPortalWallEdits(portalEdits);
        if ((buildMode == 6 || leadPosition.Height > 2) && lot is { } postSellLot)
        {
            lot = LotTiles.RefreshStructuralFlags(postSellLot, current.WalkOrder);
            RefreshWorldRoomMaps(current, lot);
        }
        var refund = SimulationWorld.HandResaleValue(baseRefund, buildMode);
        budget.AlterFamilyBudget(buildMode == 0 ? 6 : 7, -refund);
        lotValuationEdited = true;
        FlushPendingLotUpdates(current);
        if (buildMode == 0)
        {
            ClearBuildHistory();
        }
        else
        {
            if (!liveTokens.Remove(lead.Id, out var token))
                token = new BuildObjectToken(lead.Id);
            undoStack.Push(new BuildSellEdit(token, spawnGuid, leadPosition, leadDirectionFlag,
                savedCurrentValue, -refund, lotBeforeSell, lot));
            redoStack.Clear();
        }
        return new { sold = true, objectID = (int)id, guid, refund, budget = budget.ReadFamilyBudget(), canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0 };
    }

    private uint ResolveCatalogSpawnGuid(XObject lead)
    {
        var tileGuid = unchecked((uint)(lead.TypeRecord?.Key ?? 0));
        if (registry is not null &&
            registry.ByGuid.TryGetValue(tileGuid, out var entry) &&
            entry.Definition[ObjdField.MasterId] is var masterId and not 0 &&
            entry.Definition[ObjdField.SubIndex] != ushort.MaxValue)
        {
            var root = registry.Entries.FirstOrDefault(candidate =>
                ReferenceEquals(candidate.File, entry.File) &&
                candidate.Definition[ObjdField.MasterId] == masterId &&
                candidate.Definition[ObjdField.SubIndex] == ushort.MaxValue);
            if (root is not null) return root.Guid;
        }
        return tileGuid;
    }

    private static List<XObject> MultiTileMembers(SimulationWorld current, XObject item)
    {
        var lead = item.MultiTileMasterId == 0 ? item : current.ObjectById(item.MultiTileMasterId) ?? item;
        var members = new List<XObject>();
        var visited = new HashSet<short>();
        for (var part = lead; part is not null && visited.Add(part.Id);)
        {
            members.Add(part);
            part = part.MultiTileNextId == 0 ? null : current.ObjectById(part.MultiTileNextId);
        }
        return members;
    }

    private static List<(int Level, int OwnerX, int OwnerY, byte Bit, byte Style)> CapturePortalWallEdits(
        SimulationWorld current, XObject item, bool resetToDefault)
    {
        var edits = new List<(int Level, int OwnerX, int OwnerY, byte Bit, byte Style)>();
        if (item.RuntimeClass != ObjectClass.Portal) return edits;
        foreach (var member in MultiTileMembers(current, item))
        {
            if (member.Definition is not { Length: > (int)ObjdField.WallStyle }) continue;
            var sourceWallStyle = member.Definition[(int)ObjdField.WallStyle];
            if (sourceWallStyle == 0) continue;
            var localMask = member[ObjectData.WallPlacementFlags] & 5;
            var wallBit = localMask switch { 1 => 2u, 4 => 8u, _ => 0u };
            if (wallBit == 0) continue;
            wallBit = SimulationWorld.RotatePlacementWallBit(wallBit, (member[ObjectData.Direction] & 7) / 2);
            var tileX = member.Position.X >> 4;
            var tileY = member.Position.Y >> 4;
            var level = member.Position.Height;
            if (level is < 1 or > LotGeometry.MaxSupportedStories || tileX <= 0 || tileY <= 0 || tileX >= LotWalls.Size - 1 || tileY >= LotWalls.Size - 1)
                continue;
            var (ownerX, ownerY, bit) = wallBit switch
            {
                1u => (tileX, tileY, (byte)1),
                2u => (tileX, tileY, (byte)2),
                4u => (tileX + 1, tileY, (byte)1),
                8u => (tileX, tileY + 1, (byte)2),
                _ => (-1, -1, (byte)0),
            };
            if (bit == 0 || ownerX < 0 || ownerY < 0 || ownerX >= LotWalls.Size || ownerY >= LotWalls.Size) continue;
            var style = resetToDefault ? (byte)1 : unchecked((byte)sourceWallStyle);
            edits.Add((level, ownerX, ownerY, bit, style));
        }
        return edits;
    }

    private void ApplyPortalWallEdits(IReadOnlyList<(int Level, int OwnerX, int OwnerY, byte Bit, byte Style)> edits)
    {
        if (edits.Count == 0 || lot is not { } currentLot) return;
        currentLot = ApplyPortalWallEditsToLot(currentLot, edits, out var anyChanged);
        lot = currentLot;
        if (anyChanged && world is { } activeWorld) RefreshWorldRoomMaps(activeWorld, currentLot);
    }

    private static IffFile ApplyPortalWallEditsToLot(
        IffFile currentLot,
        IEnumerable<(int Level, int OwnerX, int OwnerY, byte Bit, byte Style)> edits,
        out bool anyChanged)
    {
        anyChanged = false;
        foreach (var group in edits.GroupBy(edit => edit.Level))
        {
            if (group.Key is < 1 or > LotGeometry.MaxSupportedStories) continue;
            if (!LotWalls.HasStoredArray(currentLot, group.Key)) continue;
            var walls = LotWalls.Read(currentLot, group.Key);
            var changed = false;
            foreach (var (_, ownerX, ownerY, bit, style) in group)
            {
                var cell = walls[ownerX, ownerY];
                if ((cell[0] & bit) == 0) continue;
                var styleIndex = bit == 1 ? 2 : 3;
                if (cell[styleIndex] == style) continue;
                cell[styleIndex] = style;
                changed = true;
            }
            if (changed)
            {
                currentLot = walls.WriteTo(currentLot);
                anyChanged = true;
            }
        }
        return currentLot;
    }

    private sealed class UnconstrainedFamilyBudget : IFamilyBudget
    {
        public int ReadFamilyBudget() => int.MaxValue / 2;
        public void AlterFamilyBudget(int expenseType, int amount) { }
    }

    // Fireplace floor prep: PlacementFlags 0x0001 skips clearing blocking floors; 0x0200 skips adding support floor pattern 1.
    private bool TryPrepareFireplaceFloors(SimulationWorld current, IffFile currentLot, XObject lead,
        IReadOnlyList<XObject> members, ObjectPosition destination, out IffFile updatedLot, out int netFloorCost)
    {
        updatedLot = currentLot;
        netFloorCost = 0;

        var refreshedForFireplace = LotTiles.RefreshStructuralFlags(currentLot, current.WalkOrder);
        var catalog = floorCatalog ??= FloorCatalog.Open(game, language);
        var terrain = LotTerrain.Read(refreshedForFireplace);
        var pool = LotPool.Read(refreshedForFireplace);
        var lotTiles = LotTiles.Read(refreshedForFireplace);
        var water = LotWater.Read(refreshedForFireplace);
        var floorsByLevel = new Dictionary<int, LotFloors>();
        var wallsByLevel = new Dictionary<int, LotWalls>();
        var tempBudget = new UnconstrainedFamilyBudget();
        var toolsByLevel = new Dictionary<int, FloorTool>();

        (LotFloors Floors, FloorTool Tool) EnsureLevelTools(int lvl)
        {
            if (!floorsByLevel.TryGetValue(lvl, out var fl))
            {
                fl = LotFloors.Read(refreshedForFireplace, lvl);
                var wl = LotWalls.Read(refreshedForFireplace, lvl);
                floorsByLevel[lvl] = fl;
                wallsByLevel[lvl] = wl;
                toolsByLevel[lvl] = new FloorTool(current, fl, catalog, tempBudget, terrain, pool, lotTiles, wl, water);
            }
            return (fl, toolsByLevel[lvl]);
        }

        var rootState = lead.SavedMultiTileState;
        var rootOffsetX = (members.Count > 1 ? rootState?.Value0x1A0 ?? 0 : 0) << 4;
        var rootOffsetY = (members.Count > 1 ? rootState?.Value0x1A4 ?? 0 : 0) << 4;
        var rootOffsetLevel = members.Count > 1 ? rootState?.Value0x1A8 ?? 0 : 0;
        var maxPrepStory = Math.Min(LotGeometry.MaxSupportedStories,
            Math.Max(2, LotTiles.BuiltStories(refreshedForFireplace, current.WalkOrder) + (ObjectBuildModeType(lead) == 3 ? 1 : 0)));
        var anyChanged = false;

        foreach (var member in members)
        {
            var state = member.SavedMultiTileState;
            var memberX = (destination.X - rootOffsetX + ((state?.Value0x1A0 ?? 0) << 4)) >> 4;
            var memberY = (destination.Y - rootOffsetY + ((state?.Value0x1A4 ?? 0) << 4)) >> 4;
            var memberLevel = destination.Height - rootOffsetLevel + (state?.Value0x1A8 ?? 0);
            if (memberX < 1 || memberY < 1 || memberX >= LotFloors.Size - 1 || memberY >= LotFloors.Size - 1 || memberLevel < 1)
                return false;

            var placementFlags = unchecked((ushort)member[ObjectData.PlacementFlags]);
            if (memberLevel <= maxPrepStory)
            {
                var (floors, floorTool) = EnsureLevelTools(memberLevel);
                if ((placementFlags & 1) == 0 && floors[memberX, memberY] != 0)
                {
                    if (!floorTool.Tile(memberX, memberY, 0, out var erased) || !erased)
                        return false;
                    anyChanged = true;
                }
                if (memberLevel > 1 && (placementFlags & 0x200) == 0 && floors[memberX, memberY] == 0)
                {
                    if (!lotTiles.Buildable(memberX, memberY, memberLevel) ||
                        !floorTool.Tile(memberX, memberY, 1, out var added) || !added)
                        return false;
                    anyChanged = true;
                }
            }
            else if ((placementFlags & 0x200) == 0)
            {
                return false;
            }
        }

        if (!anyChanged) return false;
        netFloorCost = toolsByLevel.Values.Sum(static t => t.Pending);
        var nextLot = currentLot;
        foreach (var lvl in floorsByLevel.Keys.Order())
        {
            nextLot = wallsByLevel[lvl].WriteTo(floorsByLevel[lvl].WriteTo(nextLot));
        }
        updatedLot = LotTiles.RefreshStructuralFlags(pool.WriteTo(nextLot), current.WalkOrder);
        return true;
    }

    private int ObjectBuildModeType(XObject item)
    {
        if (item.Definition is { Length: > (int)ObjdField.RoomSort } && item.Definition[(int)ObjdField.RoomSort] != 0)
            return 0;
        if (item.Definition is { Length: > (int)ObjdField.BuildModeType } &&
            item.Definition[(int)ObjdField.BuildModeType] is >= 1 and <= 7 and var direct)
            return direct;
        if (item.TypeRecord?.AutonomyAlternativeTypeFlag is >= 1 and <= 7 and var altFlag)
            return altFlag;
        var guid = unchecked((uint)(item.TypeRecord?.Key ?? 0));
        if (registry?.Find(guid) is not { } objectEntry) return 0;
        if (objectEntry.Definition[ObjdField.RoomSort] != 0) return 0;
        var buildMode = (int)objectEntry.Definition[ObjdField.BuildModeType];
        if (buildMode is >= 1 and <= 7) return buildMode;
        var master = objectEntry.Definition[ObjdField.MasterId];
        if (master != 0 && registry.FindAlternativeType(objectEntry) is { } alt && alt.Definition[ObjdField.RoomSort] == 0)
            buildMode = alt.Definition[ObjdField.BuildModeType];
        return buildMode is >= 1 and <= 7 ? buildMode : 0;
    }

    private ObjectEntry? ResolveCatalogEntry(SimulationWorld current, XObject item)
    {
        if (registry is null) return null;
        var lead = MultiTileMembers(current, item).FirstOrDefault() ?? item;
        var guid = unchecked((uint)(lead.TypeRecord?.Key ?? item.TypeRecord?.Key ?? 0));
        if (registry.Find(guid) is not { } entry) return null;
        return registry.FindAlternativeType(entry) ?? entry;
    }

    private string ObjectCatalogName(SimulationWorld current, XObject item)
    {
        if (ResolveCatalogEntry(current, item) is { } masterEntry &&
            masterEntry.CatalogString(0, language) is { Length: > 0 } catalogTitle)
            return catalogTitle;
        var lead = MultiTileMembers(current, item).FirstOrDefault() ?? item;
        if (lead.TypeRecord?.CatalogName is { Length: > 0 } leadName) return leadName;
        if (item.TypeRecord?.CatalogName is { Length: > 0 } itemName) return itemName;
        return "";
    }

    private object? ObjectDisposePreview(SimulationWorld current, XObject item)
    {
        if (ResolveCatalogEntry(current, item) is { } masterEntry &&
            ObjectCatalog.CatalogPreview(masterEntry, SceneDirectory) is { } preview)
            return preview;
        if (registry is not null)
        {
            var guid = unchecked((uint)(item.TypeRecord?.Key ?? 0));
            if (registry.Find(guid) is { } entry &&
                ObjectCatalog.CatalogPreview(entry, SceneDirectory) is { } fallbackPreview)
                return fallbackPreview;
        }
        return images?.ItemIcon(unchecked((uint)(item.TypeRecord?.Key ?? 0)));
    }

    private void FlushPendingLotUpdates(SimulationWorld current)
    {
        for (var pass = 0; pass < 2; pass++)
        {
            current.AdvanceSimulationTick(new SimulationClockControl(0, 0, 0), 0, current.Clock.Ticks);
            LogNewThreadErrors();
        }
    }

    private bool TryResolveStairUpperLandingDestination(
        SimulationWorld current,
        XObject lead,
        IReadOnlyList<XObject> members,
        ObjectPosition hoveredDestination,
        out ObjectPosition resolvedDestination,
        out XObject? referenceObject,
        out int referenceSlot)
    {
        resolvedDestination = hoveredDestination;
        referenceObject = null;
        referenceSlot = -1;
        if (hoveredDestination.Height < 2 || members.Count < 2)
            return false;

        var rootState = lead.SavedMultiTileState;
        var rootOffsetX = rootState?.Value0x1A0 ?? 0;
        var rootOffsetY = rootState?.Value0x1A4 ?? 0;
        var rootOffsetLevel = rootState?.Value0x1A8 ?? 0;

        foreach (var member in members)
        {
            var state = member.SavedMultiTileState;
            if (state is null) continue;
            var relLevel = (state.Value0x1A8 ?? 0) - rootOffsetLevel;
            if (relLevel != 1) continue;
            var placementFlags = unchecked((ushort)member[ObjectData.PlacementFlags]);
            if ((placementFlags & 2) != 0) continue;

            var dx = (state.Value0x1A0 - rootOffsetX) << 4;
            var dy = (state.Value0x1A4 - rootOffsetY) << 4;
            var candidate = new ObjectPosition(
                hoveredDestination.X - dx,
                hoveredDestination.Y - dy,
                hoveredDestination.Height - 1);
            if (candidate.X < 0 || candidate.Y < 0 || candidate.X >= LotWidth * 16 || candidate.Y >= LotHeight * 16)
                continue;
            if (current.CanPlaceObjectFromEditor(lead, candidate, out referenceObject, out referenceSlot))
            {
                resolvedDestination = candidate;
                return true;
            }
        }

        return false;
    }

    private bool TryResolveStairUpperLandingWithFloorPrep(
        SimulationWorld current,
        IffFile currentLot,
        XObject lead,
        IReadOnlyList<XObject> members,
        ObjectPosition hoveredDestination,
        out ObjectPosition resolvedDestination,
        out IffFile updatedLot,
        out int netFloorCost)
    {
        resolvedDestination = hoveredDestination;
        updatedLot = currentLot;
        netFloorCost = 0;
        if (hoveredDestination.Height < 2 || members.Count < 2)
            return false;

        var rootState = lead.SavedMultiTileState;
        var rootOffsetX = rootState?.Value0x1A0 ?? 0;
        var rootOffsetY = rootState?.Value0x1A4 ?? 0;
        var rootOffsetLevel = rootState?.Value0x1A8 ?? 0;

        foreach (var member in members)
        {
            var state = member.SavedMultiTileState;
            if (state is null) continue;
            var relLevel = (state.Value0x1A8 ?? 0) - rootOffsetLevel;
            if (relLevel != 1) continue;
            var placementFlags = unchecked((ushort)member[ObjectData.PlacementFlags]);
            if ((placementFlags & 2) != 0) continue;

            var dx = (state.Value0x1A0 - rootOffsetX) << 4;
            var dy = (state.Value0x1A4 - rootOffsetY) << 4;
            var candidate = new ObjectPosition(
                hoveredDestination.X - dx,
                hoveredDestination.Y - dy,
                hoveredDestination.Height - 1);
            if (candidate.X < 0 || candidate.Y < 0 || candidate.X >= LotWidth * 16 || candidate.Y >= LotHeight * 16)
                continue;
            if (!TryPrepareFireplaceFloors(current, currentLot, lead, members, candidate, out var candLot, out var candCost))
                continue;
            try
            {
                RefreshWorldRoomMaps(current, candLot);
                if (current.CanPlaceObjectFromEditor(lead, candidate, out _, out _))
                {
                    resolvedDestination = candidate;
                    updatedLot = candLot;
                    netFloorCost = candCost;
                    return true;
                }
            }
            finally
            {
                RefreshWorldRoomMaps(current, currentLot);
            }
        }

        return false;
    }

    private IReadOnlyDictionary<int, RoomMap> ReadRoomMaps(IffFile currentLot)
    {
        var minLevels = Math.Min(LotGeometry.MaxSupportedStories,
            Math.Max(2, LotTiles.BuiltStories(currentLot, world?.WalkOrder) + 1));
        if (world is { } current)
        {
            current.RoomManagerRecordsLoaded = false;
            current.LotRoomMaps.Clear();
            current.LotRoomLightMaps.Clear();
            current.PersonRoomMotiveEntries.Clear();
            var simVersion = Math.Max(current.SavedSimulationState?.Version ?? 0, 0x35);
            current.PlacementEligibilityGrids[1] = SavedLotObjectLoader.ReadPlacementEligibilityGrid(currentLot, simVersion);
        }
        return SavedLotObjectLoader.ReadRoomMaps(currentLot, world?.SavedSimulationState?.Version ?? 0, minLevels);
    }

    private void RefreshWorldRoomMaps(SimulationWorld current, IffFile currentLot)
    {
        current.LotTerrain = currentLot.Find(ResourceType.Parse("Arry"), 0) is not null
            ? LotTerrain.Read(currentLot)
            : null;
        current.LotTileFlags = EffectiveLotTiles(currentLot, current);
        current.LoadRoomMaps(ReadRoomMaps(currentLot));
        current.RefreshSavedPortalWallStyles();
        if (viewLevel > Stories)
        {
            viewLevel = Stories;
            ClearCutaway();
        }
    }

    private FloorCatalog? floorCatalog;
    private WallCatalog? wallCatalogCache;
    private WallpaperCatalog? wallpaperCatalogCache;

    private static (int EffectivePattern, Dictionary<ushort, string>? UpdatedMap) ResolveDynamicLotMaterial(
        IffFile currentLot,
        ResourceType mapType,
        int requestedPattern,
        IReadOnlyList<DynamicMaterialEntry> catalogEntries,
        Action<int>? ensureDynamicPrice)
    {
        if (requestedPattern is < 256 or >= 65534)
            return (requestedPattern, null);

        var entry = catalogEntries.FirstOrDefault(e => e.PatternId == requestedPattern);
        if (entry is null)
            return (requestedPattern, null);

        var map = SceneExporter.ReadLotMaterialMap(currentLot, mapType);
        foreach (var (existingId, existingName) in map)
        {
            if (string.Equals(existingName, entry.FileName, StringComparison.OrdinalIgnoreCase))
            {
                ensureDynamicPrice?.Invoke(existingId);
                return (existingId, map);
            }
        }

        ushort chosenId;
        if (!map.ContainsKey((ushort)requestedPattern))
        {
            chosenId = (ushort)requestedPattern;
        }
        else
        {
            ushort candidate = 256;
            while (candidate < 65534 && (map.ContainsKey(candidate) || catalogEntries.Any(c => c.PatternId == candidate && map.ContainsKey(candidate))))
                candidate++;
            chosenId = candidate;
            ensureDynamicPrice?.Invoke(chosenId);
        }

        map[chosenId] = entry.FileName;
        return (chosenId, map);
    }

    private object Architecture(JsonElement request) => ArchitectureCommand(request);

    internal interface IBuildHistoryEntry
    {
        int Charge { get; }
    }

    private sealed class BuildObjectToken(short currentId)
    {
        public short CurrentId { get; set; } = currentId;
    }

    private sealed record DemolishedOpeningRecord(BuildObjectToken Token, uint Guid, ObjectPosition Position,
        byte DirectionFlag, short SavedCurrentValue,
        IReadOnlyList<(int Level, int OwnerX, int OwnerY, byte Bit, byte Style)> ResetWallEdits);

    private sealed record ArchitectureEdit(IffFile Before, IffFile After, int Charge, string? StrokeId = null,
        IReadOnlyList<DemolishedOpeningRecord>? DemolishedOpenings = null) : IBuildHistoryEntry;
    private sealed record BuildBuyEdit(BuildObjectToken Token, uint Guid, ObjectPosition Position, byte DirectionFlag,
        int Charge, IffFile? LotBefore, IffFile? LotAfter) : IBuildHistoryEntry;
    private sealed record BuildMoveEdit(BuildObjectToken Token, ObjectPosition OldPosition, byte OldDirectionFlag,
        ObjectPosition NewPosition, byte NewDirectionFlag, IffFile? LotBefore, IffFile? LotAfter) : IBuildHistoryEntry
    {
        public int Charge => 0;
    }
    private sealed record BuildSellEdit(BuildObjectToken Token, uint Guid, ObjectPosition Position, byte DirectionFlag,
        short SavedCurrentValue, int Charge, IffFile? LotBefore, IffFile? LotAfter) : IBuildHistoryEntry;

    private readonly Stack<IBuildHistoryEntry> undoStack = new();
    private readonly Stack<IBuildHistoryEntry> redoStack = new();
    private readonly Dictionary<short, BuildObjectToken> liveTokens = new();

    private void ClearBuildHistory()
    {
        undoStack.Clear();
        redoStack.Clear();
        liveTokens.Clear();
    }

    private XObject CreateAndPlaceBuildObject(SimulationWorld current, uint guid, ObjectPosition destination,
        byte directionFlag, IffFile? lotWithFloors)
    {
        var direction = directionFlag switch
        {
            1 => 0,
            4 => 2,
            16 => 4,
            64 => 6,
            _ => throw new ArgumentException("direction must be 1, 4, 16 or 64"),
        };
        IReadOnlyList<XObject>? group = null;
        XObject? item = null;
        var previousLot = lot;
        using var savedTypes = current.BeginSavedObjectTypeRegistrationScope();
        try
        {
            group = current.ObjectGroupFactory?.Invoke(unchecked((int)guid));
            if (group is { Count: 0 }) throw new ArgumentException("Object group could not be created");
            if (group is { Count: > 0 }) item = group[0];
            else
            {
                item = current.ObjectFactory?.Invoke(unchecked((int)guid))
                    ?? throw new ArgumentException("Object definition could not be loaded");
                item.Position = new ObjectPosition(-16, -16, destination.Height);
                current.Add(item);
                current.InitializeCreatedObject(item);
            }
            var members = group ?? [item];
            current.FaceCreatedObject(item, members, (short)direction);
            // Validate against current lot first so portal wall state stays intact; only swap lotWithFloors if placement fails.
            if (!current.CanPlaceObjectFromEditor(item, destination, out var referenceObject, out var referenceSlot))
            {
                if (lotWithFloors is not null && !ReferenceEquals(lot, lotWithFloors))
                {
                    lot = lotWithFloors;
                    RefreshWorldRoomMaps(current, lotWithFloors);
                    if (!current.CanPlaceObjectFromEditor(item, destination, out referenceObject, out referenceSlot))
                        throw new InvalidOperationException("Object cannot be placed at that position");
                }
                else
                {
                    throw new InvalidOperationException("Object cannot be placed at that position");
                }
            }
            current.PlaceCreatedObjectFromEditor(item, destination, referenceObject, referenceSlot);
            ApplyPortalWallEdits(CapturePortalWallEdits(current, item, resetToDefault: false));
            savedTypes.Commit();
            return item;
        }
        catch
        {
            if (previousLot is not null && !ReferenceEquals(lot, previousLot))
            {
                lot = previousLot;
                RefreshWorldRoomMaps(current, previousLot);
            }
            if (group is { Count: > 0 }) current.RemoveCreatedObjectGroup(group[0]);
            else if (item is not null) current.Remove(item.Id);
            throw;
        }
    }

    private object RoofSettings(JsonElement request)
    {
        var current = world ?? throw new InvalidOperationException("There is no loaded native lot.");
        var currentLot = lot ?? throw new InvalidOperationException("There is no loaded native lot.");
        if (speed != 0) throw new InvalidOperationException("Pause the simulation before editing architecture");
        if (current.FamilyBudget is not FamilyBudget budget || (budget.ActiveFamily is null && current[SimulationGlobal.SimlessBuildMode] == 0))
            throw new InvalidOperationException("Architecture editing requires an active household");
        var roof = LotRoof.Read(currentLot);
        var styles = LotRoof.Styles(game);
        var changed = false;
        if (request.TryGetProperty("style", out var styleValue))
        {
            string? name = styleValue.ValueKind switch
            {
                JsonValueKind.Number when styleValue.TryGetInt32(out var index) && index >= 0 && index < styles.Count => styles[index],
                JsonValueKind.String => styles.FirstOrDefault(item => string.Equals(item, styleValue.GetString(), StringComparison.OrdinalIgnoreCase)),
                _ => null,
            };
            if (name is null) throw new ArgumentException("Roof style is not installed");
            changed |= roof.SetStyle(name);
        }
        if (request.TryGetProperty("pitch", out var pitchValue))
        {
            if (pitchValue.ValueKind != JsonValueKind.Number || !pitchValue.TryGetSingle(out var pitch) || !float.IsFinite(pitch))
                throw new ArgumentException("Roof pitch must be a finite number");
            changed |= roof.SetPitch(pitch);
        }
        if (changed)
        {
            var updated = roof.WriteTo(currentLot);
            undoStack.Push(new ArchitectureEdit(currentLot, updated, 0));
            redoStack.Clear();
            lot = updated;
            lotValuationEdited = true;
        }
        var styleIndex = styles.ToList().FindIndex(style => string.Equals(style, roof.Style, StringComparison.OrdinalIgnoreCase));
        return new { applied = true, changed, roofStyle = roof.Style, roofStyleIndex = styleIndex >= 0 ? styleIndex : 0, roofPitch = roof.Pitch, canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0 };
    }

    private object ArchitectureHistory(bool undo)
    {
        var current = world ?? throw new InvalidOperationException("There is no loaded native lot.");
        if (speed != 0) throw new InvalidOperationException("Pause the simulation before editing architecture");
        if (current.FamilyBudget is not FamilyBudget budget || (budget.ActiveFamily is null && current[SimulationGlobal.SimlessBuildMode] == 0))
            throw new InvalidOperationException("Architecture editing requires an active household");
        var source = undo ? undoStack : redoStack;
        if (source.Count == 0) return new { applied = false, command = undo ? "UNDO" : "REDO", canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0, budget = budget.ReadFamilyBudget() };
        var edit = source.Peek();
        var charge = undo ? -edit.Charge : edit.Charge;
        if (charge > 0 && charge > budget.ReadFamilyBudget())
            return new { applied = false, command = undo ? "UNDO" : "REDO", insufficientFunds = true, canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0, budget = budget.ReadFamilyBudget() };
        switch (edit)
        {
            case ArchitectureEdit arch:
                if (!undo && arch.DemolishedOpenings is { Count: > 0 } redoDemolish)
                {
                    foreach (var rec in redoDemolish)
                    {
                        if (current.ObjectById(rec.Token.CurrentId) is { } portal)
                        {
                            current.DemolishObject(portal, runCleanup: true);
                            liveTokens.Remove(rec.Token.CurrentId);
                        }
                    }
                }
                lot = undo ? arch.Before : arch.After;
                lotValuationEdited = true;
                RefreshWorldRoomMaps(current, lot);
                if (undo && arch.DemolishedOpenings is { Count: > 0 } undoRestore)
                {
                    foreach (var rec in undoRestore)
                    {
                        ApplyPortalWallEdits(rec.ResetWallEdits);
                        var created = CreateAndPlaceBuildObject(current, rec.Guid, rec.Position, rec.DirectionFlag, null);
                        var lead = MultiTileMembers(current, created).FirstOrDefault() ?? created;
                        lead[ObjectData.CurrentValue] = rec.SavedCurrentValue;
                        rec.Token.CurrentId = lead.Id;
                        liveTokens[lead.Id] = rec.Token;
                    }
                    lot = arch.Before;
                    RefreshWorldRoomMaps(current, lot);
                }
                if (arch.DemolishedOpenings is { Count: > 0 })
                    FlushPendingLotUpdates(current);
                if (charge != 0) budget.AlterFamilyBudget(7, charge);
                break;
            case BuildBuyEdit buy:
                if (undo)
                {
                    var item = current.ObjectById(buy.Token.CurrentId) ?? throw new InvalidOperationException("Build-mode object is no longer on the lot");
                    current.DemolishObject(item, runCleanup: true);
                    liveTokens.Remove(buy.Token.CurrentId);
                    if (buy.LotBefore is not null && !ReferenceEquals(lot, buy.LotBefore))
                    {
                        lot = buy.LotBefore;
                        RefreshWorldRoomMaps(current, lot);
                    }
                }
                else
                {
                    var created = CreateAndPlaceBuildObject(current, buy.Guid, buy.Position, buy.DirectionFlag, buy.LotAfter);
                    var lead = MultiTileMembers(current, created).FirstOrDefault() ?? created;
                    buy.Token.CurrentId = lead.Id;
                    liveTokens[lead.Id] = buy.Token;
                    if (buy.LotAfter is not null && !ReferenceEquals(lot, buy.LotAfter))
                    {
                        lot = buy.LotAfter;
                        RefreshWorldRoomMaps(current, lot);
                    }
                }
                lotValuationEdited = true;
                if (charge != 0) budget.AlterFamilyBudget(7, charge);
                FlushPendingLotUpdates(current);
                break;
            case BuildMoveEdit move:
            {
                var item = current.ObjectById(move.Token.CurrentId) ?? throw new InvalidOperationException("Build-mode object is no longer on the lot");
                var targetPos = undo ? move.OldPosition : move.NewPosition;
                var targetDir = undo ? move.OldDirectionFlag : move.NewDirectionFlag;
                var targetLot = undo ? move.LotBefore : move.LotAfter;
                if (!current.MoveObjectFromEditor(item, targetPos, targetDir, TreeRunner.CreateTransientStack(current, item)))
                    throw new InvalidOperationException("Object cannot be placed at that position");
                if (targetLot is not null && !ReferenceEquals(lot, targetLot))
                {
                    lot = targetLot;
                    RefreshWorldRoomMaps(current, lot);
                }
                lotValuationEdited = true;
                FlushPendingLotUpdates(current);
                break;
            }
            case BuildSellEdit sell:
                if (undo)
                {
                    var created = CreateAndPlaceBuildObject(current, sell.Guid, sell.Position, sell.DirectionFlag, sell.LotBefore);
                    var lead = MultiTileMembers(current, created).FirstOrDefault() ?? created;
                    lead[ObjectData.CurrentValue] = sell.SavedCurrentValue;
                    sell.Token.CurrentId = lead.Id;
                    liveTokens[lead.Id] = sell.Token;
                    if (sell.LotBefore is not null && !ReferenceEquals(lot, sell.LotBefore))
                    {
                        lot = sell.LotBefore;
                        RefreshWorldRoomMaps(current, lot);
                    }
                }
                else
                {
                    var item = current.ObjectById(sell.Token.CurrentId) ?? throw new InvalidOperationException("Build-mode object is no longer on the lot");
                    current.DemolishObject(item, runCleanup: true);
                    liveTokens.Remove(sell.Token.CurrentId);
                    if (sell.LotAfter is not null && !ReferenceEquals(lot, sell.LotAfter))
                    {
                        lot = sell.LotAfter;
                        RefreshWorldRoomMaps(current, lot);
                    }
                }
                lotValuationEdited = true;
                if (charge != 0) budget.AlterFamilyBudget(7, charge);
                FlushPendingLotUpdates(current);
                break;
        }
        source.Pop();
        (undo ? redoStack : undoStack).Push(edit);
        return new { applied = true, command = undo ? "UNDO" : "REDO", charge, canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0, budget = budget.ReadFamilyBudget() };
    }

    private object ArchitectureBatch(JsonElement request)
    {
        var current = world ?? throw new InvalidOperationException("There is no loaded native lot.");
        var currentLot = lot ?? throw new InvalidOperationException("There is no loaded native lot.");
        if (speed != 0) throw new InvalidOperationException("Pause the simulation before editing architecture");
        if (current.HasVisibleBlockingDialog) throw new InvalidOperationException("Answer the active game dialog before editing architecture");
        if (current.FamilyBudget is not FamilyBudget budget || (budget.ActiveFamily is null && current[SimulationGlobal.SimlessBuildMode] == 0))
            throw new InvalidOperationException("Architecture editing requires an active household");
        if (!request.TryGetProperty("commands", out var list) || list.ValueKind != JsonValueKind.Array || list.GetArrayLength() > 4096)
            throw new ArgumentException("commands must be an array of at most 4096 entries");
        var catalog = floorCatalog ??= FloorCatalog.Open(game, language);
        var price = catalog.TerrainPrice();
        var terrain = LotTerrain.Read(currentLot);
        var grass = LotGrass.Read(currentLot);
        var lotTiles = EffectiveLotTiles(currentLot, current);
        var builtStoriesCount = LotTiles.BuiltStories(currentLot, current.WalkOrder);
        var allFloors = Enumerable.Range(1, builtStoriesCount).Select(lvl => LotFloors.Read(currentLot, lvl)).ToArray();
        var allWalls = Enumerable.Range(1, builtStoriesCount).Select(lvl => LotWalls.Read(currentLot, lvl)).ToArray();
        var tool = new TerrainTool(current, terrain, budget, price, lotTiles, LotPool.Read(currentLot),
            allFloors, allWalls,
            LotWater.Read(currentLot));
        var changed = 0;
        var grassCost = 0;
        var insufficient = false;
        foreach (var item in list.EnumerateArray())
        {
            int Number(string name) => item.TryGetProperty(name, out var value) && value.ValueKind == JsonValueKind.Number && value.TryGetInt32(out var parsed)
                ? parsed : throw new ArgumentException($"{name} must be an integer");
            var command = item.TryGetProperty("command", out var commandValue) ? commandValue.GetString() : null;
            switch (command)
            {
                case "TERRAIN_RAISE":
                {
                    var smooth = item.TryGetProperty("pattern", out var patEl) && patEl.ValueKind == JsonValueKind.Number && patEl.TryGetInt32(out var patVal) && patVal != 0;
                    if (smooth)
                    {
                        var tx = Number("x");
                        var ty = Number("y");
                        var targetHeight = Math.Clamp((short)Number("style"), (short)0, (short)TerrainTool.MaximumHeight);
                        var currentHeight = (uint)tx < LotWalls.Size && (uint)ty < LotWalls.Size ? terrain.Height(tx, ty) : (byte)0;
                        var stepDelta = Math.Sign(targetHeight - currentHeight);
                        if (stepDelta == 0) break;
                        changed += tool.SmoothRaise(tx, ty, stepDelta);
                    }
                    else
                    {
                        changed += tool.Raise(Number("x"), Number("y"), (short)Number("style"));
                    }
                    break;
                }
                case "TERRAIN_FLATTEN":
                    changed += tool.Level(Number("x"), Number("y"), Number("x") + Number("x2") + 1, Number("y") + Number("y2") + 1, (short)Number("style"));
                    break;
                case "GRASS_DOT":
                {
                    var x = Number("x");
                    var y = Number("y");
                    var delta = (short)Number("pattern");
                    if (!terrain.EditableTile(x, y)) throw new ArgumentException("Grass tile is outside the lot");
                    if (!lotTiles.InsideLot(x, y)) break;
                    var state = grass[x, y];
                    var next = Math.Clamp(state + delta, 0, 255);
                    var cost = (Math.Abs(next - state) + 63) / 64 * price;
                    if (next != state && tool.Pending + grassCost + cost <= budget.ReadFamilyBudget())
                    {
                        grass[x, y] = next;
                        grassCost += cost;
                        changed++;
                    }
                    else if (next != state) insufficient = true;
                    break;
                }
                default:
                    throw new NotSupportedException($"Native terrain command '{command}' is not implemented");
            }
            insufficient |= tool.InsufficientFunds;
        }
        var strokeId = request.TryGetProperty("strokeId", out var strokeValue) &&
            strokeValue.ValueKind == JsonValueKind.String &&
            strokeValue.GetString() is { Length: > 0 } parsedStroke
            ? parsedStroke : null;
        var charge = tool.Pending + grassCost;
        if (changed > 0)
        {
            tool.Commit();
            if (grassCost > 0) budget.AlterFamilyBudget(TerrainTool.ExpenseCategory, grassCost);
            var updated = grass.WriteTo(terrain.WriteTo(currentLot));
            if (strokeId is not null &&
                undoStack.TryPeek(out var topEntry) &&
                topEntry is ArchitectureEdit prev &&
                string.Equals(prev.StrokeId, strokeId, StringComparison.Ordinal))
            {
                undoStack.Pop();
                undoStack.Push(new ArchitectureEdit(prev.Before, updated, prev.Charge + charge, strokeId));
            }
            else
            {
                undoStack.Push(new ArchitectureEdit(currentLot, updated, charge, strokeId));
            }
            redoStack.Clear();
            lot = updated;
            lotValuationEdited = true;
            RefreshWorldRoomMaps(current, lot);
        }
        return new { applied = true, changed, charge = changed > 0 ? charge : 0, insufficientFunds = insufficient, refused = tool.Refused, canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0, budget = budget.ReadFamilyBudget() };
    }

    private object ArchitectureCommand(JsonElement request)
    {
        var current = world ?? throw new InvalidOperationException("There is no loaded native lot.");
        var currentLot = lot ?? throw new InvalidOperationException("There is no loaded native lot.");
        if (speed != 0) throw new InvalidOperationException("Pause the simulation before editing architecture");
        if (current.HasVisibleBlockingDialog) throw new InvalidOperationException("Answer the active game dialog before editing architecture");
        if (current.FamilyBudget is not FamilyBudget budget || (budget.ActiveFamily is null && current[SimulationGlobal.SimlessBuildMode] == 0))
            throw new InvalidOperationException("Architecture editing requires an active household");
        var command = request.TryGetProperty("command", out var commandValue) ? commandValue.GetString() : null;
        if (command is "TERRAIN_RAISE" or "TERRAIN_FLATTEN" or "GRASS_DOT")
        {
            using var batchDoc = JsonSerializer.SerializeToDocument(new { commands = new[] { request } });
            return ArchitectureBatch(batchDoc.RootElement);
        }
        if (command is not ("FLOOR_RECT" or "FLOOR_FILL" or "FLOOR_FILL_ERASE" or "POOL_RECT" or "POOL_ERASE" or "WATER_RECT" or "WATER_ERASE" or "WALL_LINE" or "WALL_RECT" or "WALL_ERASE" or "WALL_STROKE" or "PATTERN_DOT" or "PATTERN_ERASE" or "PATTERN_FILL" or "PATTERN_FILL_ERASE")) throw new NotSupportedException($"Native architecture command '{command}' is not implemented");
        int Number(string name) => request.TryGetProperty(name, out var value) && value.ValueKind == JsonValueKind.Number && value.TryGetInt32(out var parsed)
            ? parsed : throw new ArgumentException($"{name} must be an integer");
        bool IsWaterBuildModeObject(int guid)
        {
            if (registry?.Find(unchecked((uint)guid)) is not { } objectEntry) return false;
            if (objectEntry.Definition[ObjdField.RoomSort] != 0) return false;
            if (objectEntry.Definition[ObjdField.BuildModeType] == 7) return true;
            var masterId = objectEntry.Definition[ObjdField.MasterId];
            if (masterId == 0) return false;
            if (registry.FindAlternativeType(objectEntry) is { } alt && alt.Definition[ObjdField.RoomSort] == 0 && alt.Definition[ObjdField.BuildModeType] == 7) return true;
            return objectEntry.File.OfType(ResourceType.Objd)
                .Select(chunk => Objd.Read(objectEntry.File, chunk))
                .Any(def => def[ObjdField.MasterId] == masterId && def[ObjdField.SubIndex] == ushort.MaxValue && def[ObjdField.RoomSort] == 0 && def[ObjdField.BuildModeType] == 7);
        }
        var isFloorPond = command == "FLOOR_RECT" && request.TryGetProperty("pattern", out var floorPatternProp)
            && floorPatternProp.ValueKind == JsonValueKind.Number && floorPatternProp.TryGetInt32(out var floorPatternVal) && floorPatternVal == 65534;
        if (command is "WATER_RECT" or "WATER_ERASE" || isFloorPond)
        {
            var waterLevel = Number("level");
            if (waterLevel != 1) throw new ArgumentException("Water can only be edited on the ground floor");
            var waterCatalog = floorCatalog ??= FloorCatalog.Open(game, language);
            var waterFloors = LotFloors.Read(currentLot, 1);
            var waterLayer = LotWater.Read(currentLot);
            var waterPools = LotPool.Read(currentLot);
            var waterTiles = LotTiles.Read(currentLot);
            var waterTool = new WaterTool(current, waterLayer, waterFloors, waterPools, waterTiles, LotTerrain.Read(currentLot),
                LotWalls.Read(currentLot, 1), waterCatalog, budget, IsWaterBuildModeObject);
            var waterX = Number("x");
            var waterY = Number("y");
            var waterDeltaX = Number("x2");
            var waterDeltaY = Number("y2");
            if (Math.Abs((long)waterDeltaX) > 128 || Math.Abs((long)waterDeltaY) > 128)
                throw new ArgumentException("Water rectangle extent is outside the lot");
            var waterErase = command == "WATER_ERASE";
            var waterResult = waterTool.Rectangle(waterX, waterY, checked(waterX + waterDeltaX), checked(waterY + waterDeltaY), waterErase);
            if (waterResult.Applied)
            {
                var updated = waterLayer.WriteTo(waterFloors.WriteTo(currentLot));
                undoStack.Push(new ArchitectureEdit(currentLot, updated, waterResult.Charge));
                redoStack.Clear();
                lot = updated;
                lotValuationEdited = true;
                RefreshWorldRoomMaps(current, lot);
            }
            return new { applied = waterResult.Applied, command, changed = waterResult.Changed, charge = waterResult.Charge, insufficientFunds = waterResult.InsufficientFunds, refused = waterResult.Refused, canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0, budget = budget.ReadFamilyBudget() };
        }
        if (command is "POOL_RECT" or "POOL_ERASE")
        {
            var poolLevel = Number("level");
            if (poolLevel != 1) throw new ArgumentException("Pools can only be edited on the ground floor");
            var poolCatalog = floorCatalog ??= FloorCatalog.Open(game, language);
            if (!poolCatalog.Contains(65535)) throw new InvalidDataException("Build.iff has no pool price");
            var poolFloors = LotFloors.Read(currentLot, 1);
            var poolLayer = LotPool.Read(currentLot);
            var poolTiles = LotTiles.Read(currentLot);
            var poolTool = new PoolTool(current, poolFloors, poolLayer, poolTiles, LotTerrain.Read(currentLot), LotWalls.Read(currentLot, 1), poolCatalog, budget,
                IsWaterBuildModeObject, LotWater.Read(currentLot));
            var poolX = Number("x");
            var poolY = Number("y");
            var poolDeltaX = Number("x2");
            var poolDeltaY = Number("y2");
            if (Math.Abs((long)poolDeltaX) > 128 || Math.Abs((long)poolDeltaY) > 128)
                throw new ArgumentException("Pool rectangle extent is outside the lot");
            var poolResult = poolTool.Rectangle(poolX, poolY, checked(poolX + poolDeltaX), checked(poolY + poolDeltaY), command == "POOL_ERASE");
            if (poolResult.Applied)
            {
                var updated = poolLayer.WriteTo(poolFloors.WriteTo(currentLot));
                undoStack.Push(new ArchitectureEdit(currentLot, updated, poolResult.Charge));
                redoStack.Clear();
                lot = updated;
                lotValuationEdited = true;
                RefreshWorldRoomMaps(current, lot);
            }
            return new { applied = poolResult.Applied, command, changed = poolResult.Changed, charge = poolResult.Charge, insufficientFunds = poolResult.InsufficientFunds, refused = poolResult.Refused, canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0, budget = budget.ReadFamilyBudget() };
        }
        if (command is "FLOOR_FILL" or "FLOOR_FILL_ERASE")
        {
            var fillLevel = Number("level");
            if (fillLevel < 1 || fillLevel > BuildableStories) throw new ArgumentException($"level must be between 1 and {BuildableStories}");
            var fillErase = command == "FLOOR_FILL_ERASE";
            var fillPattern = fillErase ? 0 : Number("pattern");
            var fillCatalog = floorCatalog ??= FloorCatalog.Open(game, language);
            if (fillPattern != 0 && !fillCatalog.Contains(fillPattern)) throw new ArgumentException($"Floor pattern {fillPattern} is not in the build catalog");
            var basePrice = fillPattern is >= 256 and < 65534 ? fillCatalog.Price(fillPattern) : 0;
            var (effectiveFillPattern, updatedFloorMap) = ResolveDynamicLotMaterial(
                currentLot,
                ResourceType.Parse("FLRm"),
                fillPattern,
                FloorCatalog.DynamicEntries(game),
                id => fillCatalog.SetDynamicPrice(id, basePrice));
            var fillFloors = LotFloors.Read(currentLot, fillLevel);
            var fillWalls = LotWalls.Read(currentLot, fillLevel);
            var fillTiles = EffectiveLotTiles(currentLot, current);
            var fillPool = LotPool.Read(currentLot);
            var fillTool = new FloorTool(current, fillFloors, fillCatalog, budget, LotTerrain.Read(currentLot), fillPool, fillTiles, fillWalls, LotWater.Read(currentLot));
            var fillRooms = RoomMap.Build(currentLot, fillLevel, LotWidth, LotHeight);
            var fillHalf = request.TryGetProperty("half", out _) ? Number("half") : 0;
            var filled = fillTool.Fill(fillRooms, Number("x"), Number("y"), effectiveFillPattern, fillHalf);
            var fillInsufficient = fillTool.InsufficientFunds;
            var fillCharge = fillTool.Commit();
            if (filled > 0)
            {
                var updated = fillWalls.WriteTo(fillFloors.WriteTo(currentLot));
                if (updatedFloorMap is not null)
                    updated = SceneExporter.WriteLotMaterialMap(updated, ResourceType.Parse("FLRm"), "mRLF", updatedFloorMap);
                if (fillLevel == 1) updated = fillPool.WriteTo(updated);
                updated = LotTiles.RefreshStructuralFlags(updated, current.WalkOrder);
                undoStack.Push(new ArchitectureEdit(currentLot, updated, fillCharge));
                redoStack.Clear();
                lot = updated;
                lotValuationEdited = true;
                RefreshWorldRoomMaps(current, lot);
            }
            return new { applied = true, command, changed = filled, charge = fillCharge, insufficientFunds = fillInsufficient, canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0, budget = budget.ReadFamilyBudget() };
        }
        if (command is "PATTERN_FILL" or "PATTERN_FILL_ERASE")
        {
            var fillLevel = Number("level");
            if (fillLevel < 1 || fillLevel > BuildableStories) throw new ArgumentException($"level must be between 1 and {BuildableStories}");
            var fillErase = command == "PATTERN_FILL_ERASE";
            var fillPattern = fillErase ? 0 : Number("pattern");
            var fillCatalog = wallpaperCatalogCache ??= WallpaperCatalog.Open(game, language);
            var baseWallPrice = fillPattern is >= 256 and < 65534 ? fillCatalog.Price(fillPattern) : 0;
            var (effectiveFillPattern, updatedWallMap) = ResolveDynamicLotMaterial(
                currentLot,
                ResourceType.Parse("WALm"),
                fillPattern,
                WallpaperCatalog.DynamicEntries(game),
                id => fillCatalog.SetDynamicPrice(id, baseWallPrice));
            var fillWalls = LotWalls.Read(currentLot, fillLevel);
            var fillTool = new WallpaperTool(fillWalls, fillCatalog, budget, EffectiveLotTiles(currentLot, current));
            var fillRooms = RoomMap.Build(currentLot, fillLevel, LotWidth, LotHeight);
            var filled = fillTool.Fill(fillRooms, Number("x"), Number("y"), effectiveFillPattern, fillErase, request.TryGetProperty("half", out _) ? Number("half") : 0);
            var fillInsufficient = fillTool.InsufficientFunds;
            var fillError = fillTool.Error;
            var fillCharge = fillTool.Commit();
            if (filled > 0)
            {
                var updated = fillWalls.WriteTo(currentLot);
                if (updatedWallMap is not null)
                    updated = SceneExporter.WriteLotMaterialMap(updated, ResourceType.Parse("WALm"), "mLAW", updatedWallMap);
                undoStack.Push(new ArchitectureEdit(currentLot, updated, fillCharge));
                redoStack.Clear();
                lot = updated;
                lotValuationEdited = true;
                RefreshWorldRoomMaps(current, lot);
            }
            return new { applied = true, command, changed = filled, charge = fillCharge, insufficientFunds = fillInsufficient, error = fillError, canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0, budget = budget.ReadFamilyBudget() };
        }
        if (command is "PATTERN_DOT" or "PATTERN_ERASE")
        {
            var dotLevel = Number("level");
            if (dotLevel < 1 || dotLevel > BuildableStories) throw new ArgumentException($"level must be between 1 and {BuildableStories}");
            var erase = command == "PATTERN_ERASE";
            var dotPattern = erase ? 0 : Number("pattern");
            var patternCatalog = wallpaperCatalogCache ??= WallpaperCatalog.Open(game, language);
            var baseDotPrice = dotPattern is >= 256 and < 65534 ? patternCatalog.Price(dotPattern) : 0;
            var (effectiveDotPattern, updatedDotWallMap) = ResolveDynamicLotMaterial(
                currentLot,
                ResourceType.Parse("WALm"),
                dotPattern,
                WallpaperCatalog.DynamicEntries(game),
                id => patternCatalog.SetDynamicPrice(id, baseDotPrice));
            var patternWalls = LotWalls.Read(currentLot, dotLevel);
            var patternTool = new WallpaperTool(patternWalls, patternCatalog, budget, EffectiveLotTiles(currentLot, current));
            var dotEdge = request.TryGetProperty("edge", out _) ? Number("edge") : (1 << Number("x2"));
            var painted = patternTool.Dot(Number("x"), Number("y"), dotEdge, request.TryGetProperty("side", out _) ? Number("side") : 0, effectiveDotPattern, erase);
            var patternInsufficient = patternTool.InsufficientFunds;
            var patternError = patternTool.Error;
            var patternCharge = patternTool.Commit();
            if (painted)
            {
                var updated = patternWalls.WriteTo(currentLot);
                if (updatedDotWallMap is not null)
                    updated = SceneExporter.WriteLotMaterialMap(updated, ResourceType.Parse("WALm"), "mLAW", updatedDotWallMap);
                undoStack.Push(new ArchitectureEdit(currentLot, updated, patternCharge));
                redoStack.Clear();
                lot = updated;
                lotValuationEdited = true;
                RefreshWorldRoomMaps(current, lot);
            }
            return new { applied = true, command, changed = painted ? 1 : 0, charge = patternCharge, insufficientFunds = patternInsufficient, error = patternError, canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0, budget = budget.ReadFamilyBudget() };
        }
        if (command != "FLOOR_RECT")
        {
            var wallLevel = Number("level");
            if (wallLevel < 1 || wallLevel > BuildableStories) throw new ArgumentException($"level must be between 1 and {BuildableStories}");
            var wallStyle = request.TryGetProperty("style", out _) ? Number("style") : 1;
            var wallPattern = request.TryGetProperty("pattern", out _) ? Number("pattern") : 0;
            var wallCatalog = wallCatalogCache ??= WallCatalog.Open(game, language);
            var walls = LotWalls.Read(currentLot, wallLevel);
            var wallFloors = LotFloors.Read(currentLot, wallLevel);
            var wallTool = new WallTool(current, walls, LotTerrain.Read(currentLot), wallCatalog, budget, LotPool.Read(currentLot), EffectiveLotTiles(currentLot, current), LotWater.Read(currentLot), wallFloors);
            var beforePortals = current.WalkOrder
                .Where(item => item is not XPerson &&
                               item.Definition[(int)ObjdField.Type] == 8 &&
                               item.Position.Height == wallLevel &&
                               (item.MultiTileMasterId == 0 || item.MultiTileMasterId == item.Id))
                .Select(lead => (
                    Lead: lead,
                    Guid: ResolveCatalogSpawnGuid(lead),
                    Position: lead.Position,
                    DirectionFlag: (byte)(1 << (lead[ObjectData.Direction] & 6)),
                    SavedCurrentValue: lead[ObjectData.CurrentValue],
                    ResetWallEdits: CapturePortalWallEdits(current, lead, resetToDefault: true)))
                .ToArray();
            var segments = 0;
            var wallInsufficient = false;
            if (command == "WALL_STROKE")
            {
                if (!request.TryGetProperty("segments", out var path) || path.ValueKind != JsonValueKind.Array || path.GetArrayLength() > 128)
                    throw new ArgumentException("Wall stroke must contain at most 128 segments");
                foreach (var segment in path.EnumerateArray())
                {
                    if (segment.ValueKind != JsonValueKind.Object || !segment.TryGetProperty("command", out var actionValue))
                        throw new ArgumentException("Wall stroke segment is invalid");
                    var action = actionValue.GetString();
                    if (action is not ("WALL_LINE" or "WALL_RECT" or "WALL_ERASE")) throw new ArgumentException("Wall stroke action is invalid");
                    int SegmentNumber(string name) => segment.TryGetProperty(name, out var value) && value.ValueKind == JsonValueKind.Number && value.TryGetInt32(out var parsed)
                        ? parsed : throw new ArgumentException($"Wall stroke {name} must be an integer");
                    var segmentStyle = SegmentNumber("style");
                    var segmentPattern = SegmentNumber("pattern");
                    var changedInSegment = action == "WALL_RECT"
                        ? wallTool.Rectangle(SegmentNumber("x"), SegmentNumber("y"), SegmentNumber("x2"), SegmentNumber("y2"), segmentStyle, segmentPattern)
                        : wallTool.Line(SegmentNumber("x"), SegmentNumber("y"), SegmentNumber("x2"), SegmentNumber("y2"), segmentStyle, segmentPattern, action == "WALL_ERASE");
                    segments += changedInSegment;
                    wallInsufficient |= wallTool.InsufficientFunds;
                }
            }
            else
            {
                segments = command == "WALL_RECT"
                    ? wallTool.Rectangle(Number("x"), Number("y"), Number("x2"), Number("y2"), wallStyle, wallPattern)
                    : wallTool.Line(Number("x"), Number("y"), Number("x2"), Number("y2"), wallStyle, wallPattern, command == "WALL_ERASE");
                wallInsufficient = wallTool.InsufficientFunds;
            }
            var wallCharge = wallTool.Commit();
            if (segments > 0)
            {
                List<DemolishedOpeningRecord>? demolishedOpenings = null;
                foreach (var portal in beforePortals)
                {
                    if (current.ObjectById(portal.Lead.Id) is not null) continue;
                    if (!liveTokens.Remove(portal.Lead.Id, out var token))
                        token = new BuildObjectToken(portal.Lead.Id);
                    demolishedOpenings ??= [];
                    demolishedOpenings.Add(new DemolishedOpeningRecord(
                        token, portal.Guid, portal.Position, portal.DirectionFlag, portal.SavedCurrentValue,
                        portal.ResetWallEdits));
                }
                if (demolishedOpenings is { Count: > 0 })
                {
                    FlushPendingLotUpdates(current);
                    foreach (var rec in demolishedOpenings)
                    {
                        foreach (var (editLevel, ownerX, ownerY, bit, style) in rec.ResetWallEdits)
                        {
                            if (editLevel != wallLevel) continue;
                            var cell = walls[ownerX, ownerY];
                            if ((cell[0] & bit) == 0) continue;
                            var styleIndex = bit == 1 ? 2 : 3;
                            if (cell[styleIndex] != style) cell[styleIndex] = style;
                        }
                    }
                }
                var updated = wallFloors.WriteTo(walls.WriteTo(currentLot));
                if (demolishedOpenings is { Count: > 0 })
                {
                    var crossLevelEdits = demolishedOpenings
                        .SelectMany(rec => rec.ResetWallEdits)
                        .Where(edit => edit.Level != wallLevel)
                        .ToArray();
                    if (crossLevelEdits.Length > 0)
                        updated = ApplyPortalWallEditsToLot(updated, crossLevelEdits, out _);
                }
                updated = LotTiles.RefreshStructuralFlags(updated, current.WalkOrder);
                undoStack.Push(new ArchitectureEdit(currentLot, updated, wallCharge, DemolishedOpenings: demolishedOpenings));
                redoStack.Clear();
                lot = updated;
                lotValuationEdited = true;
                RefreshWorldRoomMaps(current, lot);
            }
            return new { applied = true, command, changed = segments, charge = wallCharge, insufficientFunds = wallInsufficient, refused = wallTool.Refused, error = wallTool.Error, canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0, budget = budget.ReadFamilyBudget() };
        }
        var x = Number("x");
        var y = Number("y");
        var level = Number("level");
        var width = Number("x2");
        var depth = Number("y2");
        var pattern = Number("pattern");
        if (level < 1 || level > BuildableStories) throw new ArgumentException($"level must be between 1 and {BuildableStories}");
        if (x < 0 || y < 0 || x >= LotWidth || y >= LotHeight) throw new ArgumentException("Architecture command is outside the lot");
        if (Math.Abs((long)width) > 128 || Math.Abs((long)depth) > 128) throw new ArgumentException("Architecture extent is outside the lot");
        var catalog = floorCatalog ??= FloorCatalog.Open(game, language);
        if (pattern != 0 && !catalog.Contains(pattern)) throw new ArgumentException($"Floor pattern {pattern} is not in the build catalog");
        var rectBasePrice = pattern is >= 256 and < 65534 ? catalog.Price(pattern) : 0;
        var (effectiveRectPattern, updatedRectFloorMap) = ResolveDynamicLotMaterial(
            currentLot,
            ResourceType.Parse("FLRm"),
            pattern,
            FloorCatalog.DynamicEntries(game),
            id => catalog.SetDynamicPrice(id, rectBasePrice));
        var floors = LotFloors.Read(currentLot, level);
        var floorWalls = LotWalls.Read(currentLot, level);
        var floorLotTiles = EffectiveLotTiles(currentLot, current);
        var floorPool = LotPool.Read(currentLot);
        var tool = new FloorTool(current, floors, catalog, budget, LotTerrain.Read(currentLot), floorPool, floorLotTiles, floorWalls, LotWater.Read(currentLot));
        var half = request.TryGetProperty("half", out _) ? Number("half") : 0;
        var changed = tool.Rectangle(x, y, x + width, y + depth, effectiveRectPattern, half);
        var insufficient = tool.InsufficientFunds;
        var charge = tool.Commit();
        if (changed > 0)
        {
            var updated = floorWalls.WriteTo(floors.WriteTo(currentLot));
            if (updatedRectFloorMap is not null)
                updated = SceneExporter.WriteLotMaterialMap(updated, ResourceType.Parse("FLRm"), "mRLF", updatedRectFloorMap);
            if (level == 1) updated = floorPool.WriteTo(updated);
            updated = LotTiles.RefreshStructuralFlags(updated, current.WalkOrder);
            undoStack.Push(new ArchitectureEdit(currentLot, updated, charge));
            redoStack.Clear();
            lot = updated;
            lotValuationEdited = true;
            RefreshWorldRoomMaps(current, lot);
        }
        return new { applied = true, command, changed, charge, insufficientFunds = insufficient, canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0, budget = budget.ReadFamilyBudget() };
    }

    private object MoveObject(JsonElement request)
    {
        var current = world ?? throw new InvalidOperationException("There is no loaded native lot.");
        if (speed != 0) throw new InvalidOperationException("Pause the simulation before editing objects");
        if (current.HasVisibleBlockingDialog) throw new InvalidOperationException("Answer the active game dialog before editing objects");
        if (current.FamilyBudget is not FamilyBudget budget || (budget.ActiveFamily is null && current[SimulationGlobal.SimlessBuildMode] == 0))
            throw new InvalidOperationException("Object editing requires an active household");
        var id = request.TryGetProperty("objectID", out var idValue) && idValue.TryGetInt16(out var parsedId)
            ? parsedId : throw new ArgumentException("objectID must be a 16-bit object id");
        var x = Coordinate(request, "x");
        var y = Coordinate(request, "y");
        var level = request.TryGetProperty("level", out var levelValue) && levelValue.TryGetInt32(out var parsedLevel)
            ? parsedLevel : throw new ArgumentException("level must be an integer");
        var directionFlag = request.TryGetProperty("direction", out var directionValue) && directionValue.TryGetByte(out var parsedDirection)
            ? parsedDirection : throw new ArgumentException("direction must be 1, 4, 16 or 64");
        if (directionFlag is not (1 or 4 or 16 or 64)) throw new ArgumentException("direction must be 1, 4, 16 or 64");
        if (x < 0 || y < 0 || x >= LotWidth * 16 || y >= LotHeight * 16 || level < 1 || level > Stories)
            throw new ArgumentException("Object position is outside the lot");
        var item = current.ObjectById(id);
        if (item is null || (item is XPerson && !current.CanPickUpObject(item))) throw new ArgumentException("Object cannot be moved");
        if (!current.CanPickUpObject(item)) throw new InvalidOperationException("Object cannot be moved");
        var lead = MultiTileMembers(current, item).FirstOrDefault() ?? item;
        var oldPosition = lead.Position;
        var oldDirectionFlag = (byte)(1 << (lead[ObjectData.Direction] & 6));
        var lotBeforeMove = lot;
        var oldPortalEdits = CapturePortalWallEdits(current, item, resetToDefault: true);
        var moveDestination = new ObjectPosition(x, y, level);
        var buildMode = ObjectBuildModeType(lead);
        if (!current.MoveObjectFromEditor(item, moveDestination, directionFlag,
                TreeRunner.CreateTransientStack(current, item)))
        {
            var movedViaUpperLanding = false;
            if (buildMode == 3 && moveDestination.Height >= 2)
            {
                var members = MultiTileMembers(current, lead);
                var savedFacing = members.ToDictionary(m => m, m => (m[ObjectData.Direction], m.SavedMultiTileState));
                var targetDir = directionFlag switch { 1 => 0, 4 => 2, 16 => 4, _ => 6 };
                current.FaceCreatedObject(lead, members, (short)targetDir);
                var resolvedValid = TryResolveStairUpperLandingDestination(current, lead, members, moveDestination, out var altDest, out _, out _);
                foreach (var (m, (dir, st)) in savedFacing)
                {
                    m[ObjectData.Direction] = dir;
                    m.SavedMultiTileState = st;
                }
                if (resolvedValid && current.MoveObjectFromEditor(item, altDest, directionFlag, TreeRunner.CreateTransientStack(current, item)))
                    movedViaUpperLanding = true;
            }
            if (!movedViaUpperLanding)
                throw new InvalidOperationException("Object cannot be placed at that position");
        }
        ApplyPortalWallEdits(oldPortalEdits);
        ApplyPortalWallEdits(CapturePortalWallEdits(current, item, resetToDefault: false));
        FlushPendingLotUpdates(current);
        if ((buildMode == 6 || oldPosition.Height > 2 || lead.Position.Height > 2) && lot is { } postMoveLot)
        {
            lot = LotTiles.RefreshStructuralFlags(postMoveLot, current.WalkOrder);
            RefreshWorldRoomMaps(current, lot);
        }
        if (buildMode == 0)
        {
            ClearBuildHistory();
        }
        else
        {
            if (!liveTokens.TryGetValue(lead.Id, out var token))
            {
                token = new BuildObjectToken(lead.Id);
                liveTokens[lead.Id] = token;
            }
            undoStack.Push(new BuildMoveEdit(token, oldPosition, oldDirectionFlag,
                lead.Position, directionFlag, lotBeforeMove, lot));
            redoStack.Clear();
        }
        return new { moved = true, objectID = (int)id, x = item.Position.X / 16f, y = item.Position.Y / 16f, level = item.Position.Height, canUndo = undoStack.Count > 0, canRedo = redoStack.Count > 0 };
    }

    private object PreviewObject(JsonElement request, bool cursor = false)
    {
        var current = world ?? throw new InvalidOperationException("There is no loaded native lot.");
        if (speed != 0) throw new InvalidOperationException("Pause the simulation before editing objects");
        if (current.HasVisibleBlockingDialog) throw new InvalidOperationException("Answer the active game dialog before editing objects");
        if (current.FamilyBudget is not FamilyBudget budget || (budget.ActiveFamily is null && current[SimulationGlobal.SimlessBuildMode] == 0))
            throw new InvalidOperationException("Object editing requires an active household");

        var hasGuid = request.TryGetProperty("guid", out var guidValue);
        var hasObject = request.TryGetProperty("objectID", out _);
        if (hasGuid == hasObject && !cursor) throw new ArgumentException("Supply either a catalog GUID or an object ID");
        XObject? existing = null;
        if (hasObject && !cursor)
        {
            existing = RequestObject(request, "objectID");
            if (!current.CanPickUpObject(existing)) throw new InvalidOperationException("Object cannot be moved");
        }
        var guid = existing is not null ? unchecked((uint)(existing.TypeRecord?.Key ?? 0))
            : hasGuid && guidValue.TryGetUInt32(out var parsedGuid)
                ? parsedGuid : throw new ArgumentException("guid must be an unsigned 32-bit object GUID");
        if (cursor && guid is not (WallCursorGuid or TerrainCursorGuid)) throw new ArgumentException("Invalid build cursor");
        var entry = registry?.Find(guid) ?? throw new ArgumentException("Object is not in the loaded catalog");
        ObjectCatalogEntry? catalogItem = null;
        if (!cursor && existing is null && (!ObjectCatalog.TryGetEntry(entry, language, CurrentCatalogLotType(), out catalogItem) || catalogItem is null))
            throw new ArgumentException("Object is not a supported catalog item");

        var tileX = Coordinate(request, "x");
        var tileY = Coordinate(request, "y");
        var x = tileX;
        var y = tileY;
        short graphic = 0;
        var centered = false;
        if (cursor)
        {
            graphic = request.TryGetProperty("graphic", out var graphicValue) && graphicValue.TryGetInt16(out var parsedGraphic) && parsedGraphic is >= 0 and <= 3
                ? parsedGraphic : throw new ArgumentException("graphic must be an integer from 0 through 3");
            centered = request.TryGetProperty("centered", out var centeredValue) && centeredValue.GetBoolean();
            x = x * 16 + (centered ? 8 : 0);
            y = y * 16 + (centered ? 8 : 0);
        }
        var level = request.TryGetProperty("level", out var levelValue) && levelValue.TryGetInt32(out var parsedLevel)
            ? parsedLevel : throw new ArgumentException("level must be an integer");
        var directionFlag = request.TryGetProperty("direction", out var directionValue) && directionValue.TryGetByte(out var parsedDirection)
            ? parsedDirection : throw new ArgumentException("direction must be 1, 4, 16 or 64");
        var direction = directionFlag switch
        {
            1 => 0,
            4 => 2,
            16 => 4,
            64 => 6,
            _ => throw new ArgumentException("direction must be 1, 4, 16 or 64"),
        };
        if (x < 0 || y < 0 || x >= LotWidth * 16 || y >= LotHeight * 16 || level < 1 || level > Stories)
            throw new ArgumentException("Object position is outside the lot");

        IReadOnlyList<XObject>? group = null;
        XObject? item = null;
        bool valid = false;
        object? ghost;
        object? wallPreview = null;
        var destination = new ObjectPosition(x, y, level);
        IReadOnlyList<object> tiles;
        var effectivePrice = catalogItem?.Price ?? 0;
        try
        {
            var groupGuid = existing is not null && entry.Definition[ObjdField.MasterId] is var masterId and not 0 &&
                entry.Definition[ObjdField.SubIndex] != ushort.MaxValue &&
                registry.Entries.FirstOrDefault(candidate => ReferenceEquals(candidate.File, entry.File) &&
                    candidate.Definition[ObjdField.MasterId] == masterId &&
                    candidate.Definition[ObjdField.SubIndex] == ushort.MaxValue) is { } masterEntry
                ? masterEntry.Guid
                : guid;
            group = current.PlacementPreviewGroupFactory?.Invoke(unchecked((int)groupGuid));
            if (group is { Count: 0 }) throw new ArgumentException("Object group could not be created");
            if (group is { Count: > 0 })
            {
                item = existing is not null
                    ? group.FirstOrDefault(member => member.TypeRecord?.Key == existing.TypeRecord?.Key) ?? group[0]
                    : group[0];
            }
            else
            {
                if (entry.Definition[ObjdField.MasterId] != 0)
                    throw new ArgumentException("Multi-tile object preview is unavailable");
                item = (cursor ? current.BuildCursorFactory : current.PlacementPreviewFactory)?.Invoke(unchecked((int)guid))
                    ?? throw new ArgumentException("Object definition could not be loaded");
                item.Position = new ObjectPosition(-16, -16, level);
                current.Add(item);
                current.InitializeCreatedObject(item);
            }
            var members = group ?? [item];
            if (cursor) foreach (var member in members) member[ObjectData.Graphic] = graphic;
            else if (existing is not null)
            {
                var existingMembers = MultiTileMembers(current, existing);
                foreach (var member in members)
                {
                    var source = existingMembers.FirstOrDefault(candidate => candidate.TypeRecord?.Key == member.TypeRecord?.Key) ?? existing;
                    member[ObjectData.Graphic] = source[ObjectData.Graphic];
                    for (var flagIndex = 0; flagIndex < Math.Min(member.DynamicSpriteFlags.Length, source.DynamicSpriteFlags.Length); flagIndex++)
                        member.DynamicSpriteFlags[flagIndex] = source.DynamicSpriteFlags[flagIndex];
                }
            }
            int? hoveredWallDir = request.TryGetProperty("wallDirection", out var hoveredWallDirEl) &&
                hoveredWallDirEl.ValueKind == JsonValueKind.Number &&
                hoveredWallDirEl.TryGetInt32(out var parsedHoveredWallDir) &&
                parsedHoveredWallDir is >= 0 and <= 3
                ? parsedHoveredWallDir
                : null;
            current.FaceCreatedObject(item, members, (short)direction);
            XObject? previewReferenceObject = null;
            int previewReferenceSlot = -1;
            if (existing is not null)
            {
                var move = current.PreviewEditorMove(existing, destination, directionFlag,
                    TreeRunner.CreateTransientStack(current, existing));
                if (!move.Valid && !cursor && hoveredWallDir is not null)
                {
                    var altDir = (direction + 4) & 7;
                    var altDirFlag = (byte)(1 << altDir);
                    current.FaceCreatedObject(item, members, (short)altDir);
                    var altMove = current.PreviewEditorMove(existing, destination, altDirFlag,
                        TreeRunner.CreateTransientStack(current, existing));
                    if (altMove.Valid)
                    {
                        direction = altDir;
                        directionFlag = altDirFlag;
                        move = altMove;
                    }
                    else
                    {
                        current.FaceCreatedObject(item, members, (short)direction);
                    }
                }
                valid = move.Valid;
                tiles = move.Tiles.Select(tile => (object)new { x = tile.X, y = tile.Y, level = tile.Level }).ToArray();
                previewReferenceObject = move.ReferenceObject;
                previewReferenceSlot = move.ReferenceSlot;
            }
            else
            {
                valid = cursor
                    ? current.CanPlaceObject(item, destination)
                    : current.CanPlaceObjectFromEditor(item, destination, out previewReferenceObject, out previewReferenceSlot);
                if (!valid && !cursor && ObjectBuildModeType(item) == 3 &&
                    TryResolveStairUpperLandingDestination(current, item, members, destination, out var stairAltDestination, out var stairRefObj, out var stairRefSlot))
                {
                    destination = stairAltDestination;
                    previewReferenceObject = stairRefObj;
                    previewReferenceSlot = stairRefSlot;
                    valid = true;
                }
                if (!valid && !cursor && hoveredWallDir is not null)
                {
                    var altDir = (direction + 4) & 7;
                    var altDirFlag = (byte)(1 << altDir);
                    current.FaceCreatedObject(item, members, (short)altDir);
                    if (current.CanPlaceObjectFromEditor(item, destination, out var altRefObj, out var altRefSlot))
                    {
                        direction = altDir;
                        directionFlag = altDirFlag;
                        valid = true;
                        previewReferenceObject = altRefObj;
                        previewReferenceSlot = altRefSlot;
                    }
                    else
                    {
                        current.FaceCreatedObject(item, members, (short)direction);
                    }
                }
                if (!valid && !cursor && ObjectBuildModeType(item) is 3 or 5 && lot is { } currentPreviewLot &&
                    (TryPrepareFireplaceFloors(current, currentPreviewLot, item, members, destination, out var previewUpdatedLot, out var previewFloorCost) ||
                     (ObjectBuildModeType(item) == 3 && TryResolveStairUpperLandingWithFloorPrep(current, currentPreviewLot, item, members, destination, out destination, out previewUpdatedLot, out previewFloorCost))))
                {
                    try
                    {
                        RefreshWorldRoomMaps(current, previewUpdatedLot);
                        valid = current.CanPlaceObjectFromEditor(item, destination, out previewReferenceObject, out previewReferenceSlot);
                        if (valid) effectivePrice += previewFloorCost;
                    }
                    finally
                    {
                        RefreshWorldRoomMaps(current, currentPreviewLot);
                    }
                }
                tiles = PlacementTiles(item, group, destination);
            }
            PositionPreviewMembers(current, item, members, destination, previewReferenceObject, previewReferenceSlot);
            ghost = null;
            if (lot is not null && registry is not null)
            {
                try
                {
                    var exportLot = lot;
                    LotWalls? previewWalls = null;
                    HashSet<(int X, int Y, int Level, int Direction)>? changedWalls = null;
                    IffFile? previewMaterialLot = null;
                    if (cursor && guid == WallCursorGuid && graphic == 2 && centered &&
                        request.TryGetProperty("pattern", out var cursorPatternProp) &&
                        cursorPatternProp.ValueKind == JsonValueKind.Number &&
                        cursorPatternProp.TryGetUInt16(out var cursorPattern) &&
                        level >= 1 && level <= Stories)
                    {
                        var cursorWallDir = request.TryGetProperty("wallDirection", out var wallDirProp) && wallDirProp.TryGetInt32(out var parsedWallDir)
                            ? parsedWallDir : 0;
                        if (cursorWallDir is < 0 or > 3) throw new ArgumentException("Invalid wallpaper direction");
                        var cursorFill = request.TryGetProperty("fill", out var fillProp) &&
                            fillProp.ValueKind is JsonValueKind.True or JsonValueKind.False && fillProp.GetBoolean();
                        var wallpaperCatalog = wallpaperCatalogCache ??= WallpaperCatalog.Open(game, language);
                        if (cursorPattern == 0 || wallpaperCatalog.Contains(cursorPattern))
                        {
                            var baseCursorPrice = cursorPattern is >= 256 and < 65534 ? wallpaperCatalog.Price(cursorPattern) : 0;
                            var (effectiveCursorPattern, previewWallMap) = ResolveDynamicLotMaterial(
                                lot,
                                ResourceType.Parse("WALm"),
                                cursorPattern,
                                WallpaperCatalog.DynamicEntries(game),
                                id => wallpaperCatalog.SetDynamicPrice(id, baseCursorPrice));
                            if (previewWallMap is not null)
                                previewMaterialLot = SceneExporter.WriteLotMaterialMap(lot, ResourceType.Parse("WALm"), "mLAW", previewWallMap);
                            var originalWalls = LotWalls.Read(lot, level);
                            previewWalls = LotWalls.Read(lot, level);
                            var previewTool = new WallpaperTool(previewWalls, wallpaperCatalog, new UnconstrainedFamilyBudget(), EffectiveLotTiles(lot, current));
                            var erase = cursorPattern == 0;
                            int edge;
                            int side;
                            if (request.TryGetProperty("wallEdge", out var edgeProp) && edgeProp.ValueKind == JsonValueKind.Number && edgeProp.TryGetInt32(out var parsedEdge))
                            {
                                edge = parsedEdge;
                                side = request.TryGetProperty("wallSide", out var sideProp) && sideProp.ValueKind == JsonValueKind.Number && sideProp.TryGetInt32(out var parsedSide)
                                    ? parsedSide : 0;
                            }
                            else
                            {
                                var seg = tileX >= 0 && tileX < LotWalls.Size && tileY >= 0 && tileY < LotWalls.Size
                                    ? (previewWalls[tileX, tileY][0] & 0x30)
                                    : 0;
                                if (seg is 0x10 or 0x20)
                                {
                                    edge = seg;
                                    (_, side) = SceneExporter.DiagonalFacingSlotAndSide(seg, cameraOrientation);
                                }
                                else { edge = 1 << cursorWallDir; side = 0; }
                            }
                            if (cursorFill)
                            {
                                var previewRooms = RoomMap.Build(lot, level, LotWidth, LotHeight);
                                previewTool.Fill(previewRooms, tileX, tileY, effectiveCursorPattern, erase, side);
                            }
                            else
                            {
                                previewTool.Dot(tileX, tileY, edge, side, effectiveCursorPattern, erase);
                            }
                            changedWalls = new HashSet<(int X, int Y, int Level, int Direction)>();
                            for (var sy = 0; sy < LotWalls.Size; sy++)
                            for (var sx = 0; sx < LotWalls.Size; sx++)
                            {
                                var newCell = previewWalls[sx, sy];
                                if ((newCell[0] & 0x30) != 0)
                                {
                                    if (previewWalls.GetPattern(sx, sy, 6) != originalWalls.GetPattern(sx, sy, 6) ||
                                        previewWalls.GetPattern(sx, sy, 7) != originalWalls.GetPattern(sx, sy, 7))
                                    {
                                        for (var d = 0; d < 4; d++) changedWalls.Add((sx, sy, level, d));
                                    }
                                }
                                else
                                {
                                    if (previewWalls.GetPattern(sx, sy, 4) != originalWalls.GetPattern(sx, sy, 4)) changedWalls.Add((sx, sy, level, 0));
                                    if (previewWalls.GetPattern(sx, sy, 5) != originalWalls.GetPattern(sx, sy, 5)) changedWalls.Add((sx, sy, level, 1));
                                    if (previewWalls.GetPattern(sx, sy, 7) != originalWalls.GetPattern(sx, sy, 7)) changedWalls.Add((sx, sy, level, 2));
                                    if (previewWalls.GetPattern(sx, sy, 6) != originalWalls.GetPattern(sx, sy, 6)) changedWalls.Add((sx, sy, level, 3));
                                }
                            }
                        }
                    }

                    var sceneDir = SceneDirectory;
                    var usedFastPath = false;
                    var ghostIds = new HashSet<short>();
                    var ghostEntities = new List<XObject>(members.Count);
                    foreach (var member in members)
                    {
                        if (ghostIds.Add(member.Id))
                            ghostEntities.Add(member);
                    }
                    var savedSlotChildren = new List<(XObject Child, ObjectPosition Position, short Direction, short ContainerId, short ParentId)>();
                    string? scenePath = null;
                    try
                    {
                        if (!cursor && existing is not null)
                        {
                            var existingMembers = MultiTileMembers(current, existing);
                            foreach (var existingMember in existingMembers)
                            {
                                var previewMember = members.FirstOrDefault(candidate => candidate.TypeRecord?.Key == existingMember.TypeRecord?.Key) ?? item;
                                var dirDelta = (previewMember[ObjectData.Direction] - existingMember[ObjectData.Direction]) & 7;
                                foreach (var child in current.EnumerateContainedSlotChildren(existingMember))
                                {
                                    if (!ghostIds.Add(child.Id)) continue;
                                    ghostEntities.Add(child);
                                    savedSlotChildren.Add((child, child.Position, child[ObjectData.Direction], child[ObjectData.ContainerId], child[ObjectData.ParentId]));
                                    child.Position = previewMember.Position;
                                    if ((child.Definition is not { Length: > (int)ObjdField.MasterId } ||
                                         child.Definition[(int)ObjdField.MasterId] == 0) &&
                                        child[ObjectData.RotationNotches] is 0 or 2)
                                    {
                                        child[ObjectData.Direction] = (short)((child[ObjectData.Direction] + dirDelta) & 7);
                                    }
                                    if (child[ObjectData.ContainerId] == existingMember.ClockManagerIndex && previewMember.ClockManagerIndex > 0)
                                        child[ObjectData.ContainerId] = previewMember.ClockManagerIndex;
                                    if (child[ObjectData.ParentId] == existingMember.ClockManagerIndex && previewMember.ClockManagerIndex > 0)
                                        child[ObjectData.ParentId] = previewMember.ClockManagerIndex;
                                }
                            }
                        }

                        if (cursor && existing is null && members.Count == 1 && level == viewLevel &&
                            SceneExporter.TryBuildCursorGhost(registry, current, house, animationState, revision, sceneDir,
                                guid, item.Id, graphic, destination, direction, cameraOrientation, LotWidth,
                                item.DynamicSpriteFlags, out ghost))
                        {
                            if (changedWalls is { Count: > 0 } && previewWalls is not null)
                            {
                                usedFastPath = SceneExporter.TryBuildWallPaintGhost(
                                    previewMaterialLot ?? lot, current, game, sceneDir, animationState, revision, level, wallMode,
                                    previewWalls, changedWalls, cameraOrientation, LotWidth, out wallPreview);
                                if (!usedFastPath)
                                {
                                    ghost = null;
                                    wallPreview = null;
                                }
                            }
                            else
                            {
                                usedFastPath = true;
                            }
                        }
                        else if (!cursor && (changedWalls is null || changedWalls.Count == 0) &&
                            SceneExporter.TryBuildPlacementGhost(registry, current, house, animationState, revision, sceneDir,
                                ghostEntities, level, cameraOrientation, LotWidth, out ghost))
                        {
                            usedFastPath = true;
                        }

                        if (!usedFastPath)
                        {
                            if (changedWalls is { Count: > 0 } && previewWalls is not null)
                                exportLot = previewWalls.WriteTo(lot);

                            scenePath = SceneExporter.Export(exportLot, current, registry, game, sceneDir, house,
                                1_000_000 + ++previewRevision, level, wallMode, cameraOrientation, cutawayTile, roofsVisible,
                                cutawayRooms: cutawayRooms, cutawaySim: CutawaySimTile(), cutawayZoom: cutawayZoom,
                                showLoweredPortals: true, raiseHoveredWalls: wallpaperBuildToolActive);
                            var referenceScenePath = Path.Combine(sceneDir, $"scene-{revision}.json");
                            ghost = SceneExporter.PlacementGhost(scenePath, ghostIds, referenceScenePath);
                            if (changedWalls is { Count: > 0 })
                                wallPreview = SceneExporter.WallPaintGhost(scenePath, changedWalls, referenceScenePath);
                        }
                    }
                    finally
                    {
                        foreach (var saved in savedSlotChildren)
                        {
                            saved.Child.Position = saved.Position;
                            saved.Child[ObjectData.Direction] = saved.Direction;
                            saved.Child[ObjectData.ContainerId] = saved.ContainerId;
                            saved.Child[ObjectData.ParentId] = saved.ParentId;
                        }
                        if (scenePath is not null)
                        {
                            SimsSimulation.InMemorySessionAssets.DeleteFile(scenePath);
                            if (File.Exists(scenePath)) File.Delete(scenePath);
                        }
                    }
                }
                catch (IOException) { }
                catch (InvalidDataException) { }
            }
        }
        finally
        {
            if (group is { Count: > 0 }) current.RemoveCreatedObjectGroup(group[0]);
            else if (item is not null) current.Remove(item.Id);
        }
        if (!cursor && viewerMode == 2) EnsureTileCursor(current);
        var status = valid && catalogItem is not null && effectivePrice > budget.ReadFamilyBudget() ? "InsufficientFunds" : valid ? "Success" : "CannotPlace";
        return new
        {
            schemaVersion = 1,
            valid = status == "Success",
            status,
            direction = (int)directionFlag,
            tiles,
            ghost,
            wallPreview,
        };
    }

    private const uint WallCursorGuid = 0x439u;
    private const uint TerrainCursorGuid = 0x2F39B7A6u;
    private const int TileCursorGuid = 0x437;
    private XObject? tileCursor;

    private void EnsureTileCursor(SimulationWorld current)
    {
        if (tileCursor is not null && current.ObjectById(tileCursor.Id) is not null) return;
        var cursorObject = current.BuildCursorFactory?.Invoke(TileCursorGuid);
        if (cursorObject is null) return;
        cursorObject.Position = new ObjectPosition(-16, -16, 1);
        current.Add(cursorObject);
        current.InitializeCreatedObject(cursorObject);
        tileCursor = cursorObject;
    }
}
