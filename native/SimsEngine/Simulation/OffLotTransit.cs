using System.Numerics;
using SimsEngine.Character;
using SimsEngine.Content;
using SimsEngine.Formats;

namespace SimsEngine.Simulation;

public sealed class OffLotTransitManager
{
    public const short SyntheticIdBase = 30000;
    private const short SyntheticIdSpan = 2400;

    public readonly record struct VehiclePartSnapshot(
        uint Guid,
        float RelTileX,
        float RelTileY,
        short Direction,
        short Graphic,
        short[] DynamicSpriteFlags);

    public sealed class ApproachingVehicle
    {
        public required short LeadId { get; init; }
        public required int Level { get; init; }
        public required float Fx { get; init; }
        public required float Fy { get; init; }
        public float MinRearProj { get; set; }
        public float MaxFwdProj { get; set; }
        public required HashSet<short> MemberIds { get; init; }
        public required Dictionary<short, (float Dx, float Dy)> MemberOffsets { get; init; }
        public required HashSet<short> HeldPassengerIds { get; init; }
        public float TargetLeadX { get; set; }
        public float TargetLeadY { get; set; }
        public float PrevLeadX { get; set; }
        public float PrevLeadY { get; set; }
        public float CurrentLeadX { get; set; }
        public float CurrentLeadY { get; set; }
        public bool WarmupTickPending { get; set; }
        public bool BrakingStop { get; set; }

        public Vector2 InterpolatedLead(float subTickAlpha) =>
            new(
                PrevLeadX + (CurrentLeadX - PrevLeadX) * Math.Clamp(subTickAlpha, 0f, 1f),
                PrevLeadY + (CurrentLeadY - PrevLeadY) * Math.Clamp(subTickAlpha, 0f, 1f));
    }

    public sealed class DepartingVehicle
    {
        public required short SyntheticObjectId { get; init; }
        public required int Level { get; init; }
        public required float Fx { get; init; }
        public required float Fy { get; init; }
        public required float MinRearProj { get; init; }
        public required VehiclePartSnapshot[] Parts { get; init; }
        public float PrevLeadX { get; set; }
        public float PrevLeadY { get; set; }
        public float CurrentLeadX { get; set; }
        public float CurrentLeadY { get; set; }

        public Vector2 InterpolatedLead(float subTickAlpha) =>
            new(
                PrevLeadX + (CurrentLeadX - PrevLeadX) * Math.Clamp(subTickAlpha, 0f, 1f),
                PrevLeadY + (CurrentLeadY - PrevLeadY) * Math.Clamp(subTickAlpha, 0f, 1f));
    }

    public sealed class ApproachingPerson
    {
        public required short PersonId { get; init; }
        public required float InwardX { get; init; }
        public required float InwardY { get; init; }
        public required float RootDirection { get; init; }
        public required float TilesPerTick { get; init; }
        public required float TargetTileX { get; init; }
        public required float TargetTileY { get; init; }
        public required short SavedDirection { get; init; }
        public required float? SavedRootDirection { get; init; }
        public required int SavedControlState { get; init; }
        public required AvatarAnimationPlayback? SavedPlayback { get; init; }
        public float PrevTileX { get; set; }
        public float PrevTileY { get; set; }
        public float CurrentTileX { get; set; }
        public float CurrentTileY { get; set; }

        public Vector2 InterpolatedTile(float subTickAlpha) =>
            new(
                PrevTileX + (CurrentTileX - PrevTileX) * Math.Clamp(subTickAlpha, 0f, 1f),
                PrevTileY + (CurrentTileY - PrevTileY) * Math.Clamp(subTickAlpha, 0f, 1f));
    }

    public sealed class DepartingPerson
    {
        public required int TransitId { get; init; }
        public required short SyntheticObjectId { get; init; }
        public required XPerson Person { get; init; }
        public required int Level { get; init; }
        public required float OutwardX { get; init; }
        public required float OutwardY { get; init; }
        public required float RootDirection { get; init; }
        public required float TilesPerTick { get; init; }
        public float PrevTileX { get; set; }
        public float PrevTileY { get; set; }
        public float CurrentTileX { get; set; }
        public float CurrentTileY { get; set; }

        public Vector2 InterpolatedTile(float subTickAlpha) =>
            new(
                PrevTileX + (CurrentTileX - PrevTileX) * Math.Clamp(subTickAlpha, 0f, 1f),
                PrevTileY + (CurrentTileY - PrevTileY) * Math.Clamp(subTickAlpha, 0f, 1f));
    }

    private sealed record LiveVehicleState(
        short LeadId,
        int Level,
        short Direction,
        float LeadTileX,
        float LeadTileY,
        float MinRearProj,
        VehiclePartSnapshot[] Parts);

    private sealed record LiveBorderPersonState(
        XPerson Person,
        int Level,
        float TileX,
        float TileY);

    private bool _baselineCaptured;
    private int _nextTransitSeq;
    private readonly HashSet<short> _seenVehicleLeads = [];
    private readonly HashSet<short> _seenVisiblePeople = [];
    private readonly HashSet<short> _baselinePeople = [];
    private readonly HashSet<short> _prevVisiblePeople = [];
    private readonly Dictionary<short, ApproachingVehicle> _approachingVehicles = new();
    private readonly Dictionary<short, short> _approachingVehicleByMember = new();
    private readonly HashSet<short> _heldPassengers = [];
    private readonly List<DepartingVehicle> _departingVehicles = [];
    private readonly Dictionary<short, LiveVehicleState> _liveVehicles = new();
    private readonly Dictionary<short, ApproachingPerson> _approachingPeople = new();
    private readonly List<DepartingPerson> _departingPeople = [];
    private readonly Dictionary<short, LiveBorderPersonState> _liveBorderPeople = new();

    public IReadOnlyCollection<ApproachingVehicle> ApproachingVehicles => _approachingVehicles.Values;
    public IReadOnlyList<DepartingVehicle> DepartingVehicles => _departingVehicles;
    public IReadOnlyCollection<ApproachingPerson> ApproachingPeople => _approachingPeople.Values;
    public IReadOnlyList<DepartingPerson> DepartingPeople => _departingPeople;

    public bool HasActiveVehicleTransit => _approachingVehicles.Count > 0 || _departingVehicles.Count > 0;
    public bool HasActivePersonTransit => _approachingPeople.Count > 0 || _departingPeople.Count > 0;

    private short NextSyntheticObjectId()
    {
        int seq = _nextTransitSeq++;
        return (short)(SyntheticIdBase + (seq % SyntheticIdSpan));
    }

    public void CaptureBaseline(SimulationWorld world)
    {
        _baselineCaptured = true;
        _seenVehicleLeads.Clear();
        _seenVisiblePeople.Clear();
        _baselinePeople.Clear();
        _prevVisiblePeople.Clear();
        _approachingVehicles.Clear();
        _approachingVehicleByMember.Clear();
        _heldPassengers.Clear();
        _departingVehicles.Clear();
        _liveVehicles.Clear();
        _approachingPeople.Clear();
        _departingPeople.Clear();
        _liveBorderPeople.Clear();

        foreach (var item in world.WalkOrder)
        {
            if (item is XPerson person)
            {
                _baselinePeople.Add(person.Id);
                if (IsVisibleOnLot(person))
                {
                    _seenVisiblePeople.Add(person.Id);
                    _prevVisiblePeople.Add(person.Id);
                }
            }
            else if (IsCarGlobalsLead(world, item) && IsVisibleOnLot(item))
            {
                _seenVehicleLeads.Add(item.Id);
            }
        }
    }

    public void EnsureBaseline(SimulationWorld world)
    {
        if (!_baselineCaptured)
            CaptureBaseline(world);
    }

    public bool ShouldHoldObjectTick(XObject item)
    {
        if (_heldPassengers.Contains(item.Id))
            return true;
        if (item is XPerson && _approachingPeople.ContainsKey(item.Id))
            return true;
        if (_approachingVehicleByMember.TryGetValue(item.Id, out short leadId) &&
            _approachingVehicles.TryGetValue(leadId, out var veh))
        {
            return !veh.WarmupTickPending;
        }
        return false;
    }

    public bool IsHiddenVehiclePassenger(short personId) => _heldPassengers.Contains(personId);

    public bool IsApproachingVehicleMember(short objectId) => _approachingVehicleByMember.ContainsKey(objectId);

    public bool TryGetApproachingPersonVisual(short personId, float subTickAlpha, out Vector2 tilePos, out float rootDirection)
    {
        if (_approachingPeople.TryGetValue(personId, out var app))
        {
            tilePos = app.InterpolatedTile(subTickAlpha);
            rootDirection = app.RootDirection;
            return true;
        }
        tilePos = default;
        rootDirection = 0f;
        return false;
    }

    public bool IsEntityOutsideLotBounds(SimulationWorld world, short objectId)
    {
        if (objectId >= SyntheticIdBase)
            return true;
        if (_heldPassengers.Contains(objectId))
            return true;
        int dim = world.ActiveLotDimension;
        if (_approachingPeople.TryGetValue(objectId, out var appPerson))
        {
            return appPerson.CurrentTileX < 1.1f || appPerson.CurrentTileY < 1.1f ||
                   appPerson.CurrentTileX > dim - 1.1f || appPerson.CurrentTileY > dim - 1.1f;
        }
        if (_approachingVehicleByMember.TryGetValue(objectId, out short leadId) &&
            _approachingVehicles.TryGetValue(leadId, out var appVeh))
        {
            var (dx, dy) = appVeh.MemberOffsets.GetValueOrDefault(objectId);
            float mx = appVeh.CurrentLeadX + dx;
            float my = appVeh.CurrentLeadY + dy;
            return mx < 1f || my < 1f || mx > dim - 1f || my > dim - 1f;
        }
        return false;
    }

    public static bool IsCarGlobalsLead(SimulationWorld world, XObject item)
    {
        if (item is XPerson || item.MultiTileMasterId != 0)
            return false;
        if (item.TypeRecord?.BehaviorScope is BehaviorScope scope &&
            scope.SemiGlobal?.Source is { } src &&
            src.Contains("CarGlobals", StringComparison.OrdinalIgnoreCase))
        {
            return true;
        }
        uint guid = unchecked((uint)(item.TypeRecord?.Key ?? 0));
        if (guid != 0 && world.ObjectRegistry?.Find(guid) is { } entry &&
            string.Equals(entry.SemiGlobal, "CarGlobals", StringComparison.OrdinalIgnoreCase))
        {
            return true;
        }
        return false;
    }

    private static bool IsVisibleOnLot(XObject item) =>
        item.Position.X >= 0 && item.Position.Y >= 0 && item.Position.Height >= 1 && item[ObjectData.Hidden] == 0;

    private static (float Fx, float Fy) ForwardVector(short direction) => (direction & 6) switch
    {
        0 => (0f, -1f),
        2 => (1f, 0f),
        4 => (0f, 1f),
        _ => (-1f, 0f),
    };

    private static List<(int TileX, int TileY)> CollectBorderPedestrianPortals(SimulationWorld world, int lotDim)
    {
        List<(int TileX, int TileY)> portals = [];
        foreach (var obj in world.WalkOrder)
        {
            if (obj is XPerson || obj.Position.X < 0 || obj.Position.Y < 0)
                continue;
            int tx = obj.Position.X >> 4;
            int ty = obj.Position.Y >> 4;
            if (tx > 3 && ty > 3 && tx < lotDim - 4 && ty < lotDim - 4)
                continue;
            uint guid = unchecked((uint)(obj.TypeRecord?.Key ?? 0));
            string? name = obj.TypeRecord?.Name;
            if (guid == 0x81E6BEF9u ||
                (name is not null && (name.Contains("Portal - Pedestrian", StringComparison.OrdinalIgnoreCase) ||
                                      name.Contains("Ped Marker", StringComparison.OrdinalIgnoreCase))))
            {
                portals.Add((tx, ty));
            }
        }
        return portals;
    }

    private static bool HasCarPortal(SimulationWorld world)
    {
        foreach (var obj in world.WalkOrder)
        {
            if (unchecked((uint)(obj.TypeRecord?.Key ?? 0)) == 0x865A6812u)
                return true;
        }
        return false;
    }

    public void StepAfterTick(SimulationWorld world)
    {
        EnsureBaseline(world);
        int lotDim = world.ActiveLotDimension;
        if (lotDim <= 6 || world[SimulationGlobal.CurrentHouse] == 99)
            return;

        bool hasCarPortal = HasCarPortal(world);
        var borderPortals = CollectBorderPedestrianPortals(world, lotDim);

        HashSet<short> currentVisibleVehicles = [];
        List<XObject> newVehicles = [];
        foreach (var item in world.WalkOrder)
        {
            if (!IsCarGlobalsLead(world, item) || !IsVisibleOnLot(item))
                continue;
            currentVisibleVehicles.Add(item.Id);
            if (hasCarPortal && _seenVehicleLeads.Add(item.Id))
                newVehicles.Add(item);
        }

        HashSet<short> currentVisiblePeople = [];
        foreach (var p in world.WalkOrder.OfType<XPerson>())
        {
            if (IsVisibleOnLot(p))
                currentVisiblePeople.Add(p.Id);
        }

        foreach (var lead in newVehicles)
        {
            var (fx, fy) = ForwardVector(lead[ObjectData.Direction]);
            float leadTileX = lead.Position.X / 16f;
            float leadTileY = lead.Position.Y / 16f;
            HashSet<short> memberIds = [];
            Dictionary<short, (float Dx, float Dy)> offsets = new();
            float maxFwdProj = 0f;
            float minRearProj = 0f;
            foreach (var m in world.MultiTileMembers(lead))
            {
                memberIds.Add(m.Id);
                float dx = (m.Position.X - lead.Position.X) / 16f;
                float dy = (m.Position.Y - lead.Position.Y) / 16f;
                offsets[m.Id] = (dx, dy);
                float proj = dx * fx + dy * fy;
                if (proj > maxFwdProj)
                    maxFwdProj = proj;
                if (proj < minRearProj)
                    minRearProj = proj;
            }

            float startX = fx > 0.5f
                ? 1f - maxFwdProj - 34f
                : fx < -0.5f
                    ? (lotDim - 2f) - maxFwdProj + 34f
                    : leadTileX;
            float startY = fy > 0.5f
                ? 1f - maxFwdProj - 34f
                : fy < -0.5f
                    ? (lotDim - 2f) - maxFwdProj + 34f
                    : leadTileY;

            float startProj = startX * fx + startY * fy;
            foreach (var existing in _approachingVehicles.Values)
            {
                if (MathF.Abs(existing.Fx - fx) > 0.1f || MathF.Abs(existing.Fy - fy) > 0.1f)
                    continue;
                float existingRearProj = (existing.CurrentLeadX * fx + existing.CurrentLeadY * fy) + existing.MinRearProj;
                float maxAllowedStartProj = existingRearProj - 2.5f - maxFwdProj;
                if (startProj > maxAllowedStartProj)
                {
                    float shift = startProj - maxAllowedStartProj;
                    startX -= fx * shift;
                    startY -= fy * shift;
                    startProj = maxAllowedStartProj;
                }
            }

            HashSet<short> heldPassengers = [];
            foreach (var p in world.WalkOrder.OfType<XPerson>())
            {
                if (!currentVisiblePeople.Contains(p.Id) || _prevVisiblePeople.Contains(p.Id))
                    continue;
                if (!_baselinePeople.Contains(p.Id))
                    continue;
                float px = p.Position.X / 16f;
                float py = p.Position.Y / 16f;
                if (MathF.Abs(px - leadTileX) <= 8f && MathF.Abs(py - leadTileY) <= 8f)
                {
                    heldPassengers.Add(p.Id);
                    _heldPassengers.Add(p.Id);
                }
            }

            float entryDist = EntryBorderDistance(leadTileX, leadTileY, fx, fy, lotDim);
            var appVeh = new ApproachingVehicle
            {
                LeadId = lead.Id,
                Level = Math.Max(1, lead.Position.Height),
                Fx = fx,
                Fy = fy,
                MinRearProj = minRearProj,
                MaxFwdProj = maxFwdProj,
                MemberIds = memberIds,
                MemberOffsets = offsets,
                HeldPassengerIds = heldPassengers,
                TargetLeadX = leadTileX,
                TargetLeadY = leadTileY,
                PrevLeadX = startX,
                PrevLeadY = startY,
                CurrentLeadX = startX,
                CurrentLeadY = startY,
                WarmupTickPending = true,
                BrakingStop = entryDist > 12f,
            };
            _approachingVehicles[lead.Id] = appVeh;
            foreach (short mid in memberIds)
                _approachingVehicleByMember[mid] = lead.Id;
        }

        foreach (var (leadId, appVeh) in _approachingVehicles.ToArray())
        {
            var leadObj = world.ObjectById(leadId);
            if (leadObj is null || leadObj.Position.X < 0 || leadObj.Position.Y < 0)
            {
                ReleaseApproachingVehicle(leadId, appVeh);
                continue;
            }

            if (appVeh.WarmupTickPending)
            {
                var (fx, fy) = ForwardVector(leadObj[ObjectData.Direction]);
                float newTargetX = leadObj.Position.X / 16f;
                float newTargetY = leadObj.Position.Y / 16f;
                appVeh.TargetLeadX = newTargetX;
                appVeh.TargetLeadY = newTargetY;
                appVeh.MemberOffsets.Clear();
                foreach (var m in world.MultiTileMembers(leadObj))
                {
                    appVeh.MemberIds.Add(m.Id);
                    _approachingVehicleByMember[m.Id] = leadId;
                    appVeh.MemberOffsets[m.Id] = ((m.Position.X - leadObj.Position.X) / 16f, (m.Position.Y - leadObj.Position.Y) / 16f);
                }
                if (MathF.Abs(fx) > 0.5f)
                {
                    appVeh.CurrentLeadY = newTargetY;
                    appVeh.PrevLeadY = newTargetY;
                }
                else
                {
                    appVeh.CurrentLeadX = newTargetX;
                    appVeh.PrevLeadX = newTargetX;
                }
                appVeh.BrakingStop = EntryBorderDistance(newTargetX, newTargetY, appVeh.Fx, appVeh.Fy, lotDim) > 12f;
                appVeh.WarmupTickPending = false;
            }

            appVeh.PrevLeadX = appVeh.CurrentLeadX;
            appVeh.PrevLeadY = appVeh.CurrentLeadY;
            float rem = (appVeh.TargetLeadX - appVeh.CurrentLeadX) * appVeh.Fx +
                        (appVeh.TargetLeadY - appVeh.CurrentLeadY) * appVeh.Fy;
            float step = appVeh.BrakingStop
                ? Math.Clamp(0.11f + 0.37f * Math.Clamp(rem / 6.5f, 0f, 1f), 0.11f, 0.48f)
                : 0.375f;
            if (rem <= step + 0.001f)
            {
                ReleaseApproachingVehicle(leadId, appVeh);
            }
            else
            {
                float proposedProj = (appVeh.CurrentLeadX * appVeh.Fx + appVeh.CurrentLeadY * appVeh.Fy) + step + appVeh.MaxFwdProj;
                foreach (var other in _approachingVehicles.Values)
                {
                    if (other.LeadId == leadId || MathF.Abs(other.Fx - appVeh.Fx) > 0.1f || MathF.Abs(other.Fy - appVeh.Fy) > 0.1f)
                        continue;
                    float myTargetProj = appVeh.TargetLeadX * appVeh.Fx + appVeh.TargetLeadY * appVeh.Fy;
                    float otherTargetProj = other.TargetLeadX * appVeh.Fx + other.TargetLeadY * appVeh.Fy;
                    if (otherTargetProj <= myTargetProj)
                        continue;
                    float otherRear = (other.CurrentLeadX * appVeh.Fx + other.CurrentLeadY * appVeh.Fy) + other.MinRearProj;
                    float allowedStep = (otherRear - 2.0f) - ((appVeh.CurrentLeadX * appVeh.Fx + appVeh.CurrentLeadY * appVeh.Fy) + appVeh.MaxFwdProj);
                    if (proposedProj > otherRear - 2.0f)
                        step = MathF.Max(0f, MathF.Min(step, allowedStep));
                }
                appVeh.CurrentLeadX += appVeh.Fx * step;
                appVeh.CurrentLeadY += appVeh.Fy * step;
            }
        }

        foreach (var (leadId, snap) in _liveVehicles.ToArray())
        {
            if (currentVisibleVehicles.Contains(leadId))
                continue;
            _liveVehicles.Remove(leadId);
            _seenVehicleLeads.Remove(leadId);

            var (fx, fy) = ForwardVector(snap.Direction);
            float exitDist = ExitBorderDistance(snap.LeadTileX, snap.LeadTileY, fx, fy, lotDim);
            if (exitDist <= 12f)
            {
                float nextX = snap.LeadTileX + fx * 0.375f;
                float nextY = snap.LeadTileY + fy * 0.375f;
                _departingVehicles.Add(new DepartingVehicle
                {
                    SyntheticObjectId = NextSyntheticObjectId(),
                    Level = snap.Level,
                    Fx = fx,
                    Fy = fy,
                    MinRearProj = snap.MinRearProj,
                    Parts = snap.Parts,
                    PrevLeadX = snap.LeadTileX,
                    PrevLeadY = snap.LeadTileY,
                    CurrentLeadX = nextX,
                    CurrentLeadY = nextY,
                });
            }
        }

        foreach (var item in world.WalkOrder)
        {
            if (!currentVisibleVehicles.Contains(item.Id) || _approachingVehicles.ContainsKey(item.Id))
                continue;
            var (fx, fy) = ForwardVector(item[ObjectData.Direction]);
            float lx = item.Position.X / 16f;
            float ly = item.Position.Y / 16f;
            var members = world.MultiTileMembers(item);
            var parts = new List<VehiclePartSnapshot>(members.Count);
            float minRear = 0f;
            foreach (var m in members)
            {
                if (m.Definition[(int)ObjdField.SubIndex] < 0 && m.Definition[(int)ObjdField.MasterId] != 0)
                    continue;
                uint mGuid = unchecked((uint)(m.TypeRecord?.Key ?? 0));
                if (mGuid == 0)
                    continue;
                float rx = (m.Position.X - item.Position.X) / 16f;
                float ry = (m.Position.Y - item.Position.Y) / 16f;
                float proj = rx * fx + ry * fy;
                if (proj < minRear)
                    minRear = proj;
                parts.Add(new VehiclePartSnapshot(
                    mGuid,
                    rx,
                    ry,
                    m[ObjectData.Direction],
                    m[ObjectData.Graphic],
                    m.DynamicSpriteFlags.Length == 0 ? [] : (short[])m.DynamicSpriteFlags.Clone()));
            }
            if (parts.Count > 0)
            {
                _liveVehicles[item.Id] = new LiveVehicleState(
                    item.Id,
                    Math.Max(1, item.Position.Height),
                    item[ObjectData.Direction],
                    lx,
                    ly,
                    minRear,
                    [.. parts]);
            }
        }

        for (int i = _departingVehicles.Count - 1; i >= 0; i--)
        {
            var dep = _departingVehicles[i];
            dep.PrevLeadX = dep.CurrentLeadX;
            dep.PrevLeadY = dep.CurrentLeadY;
            dep.CurrentLeadX += dep.Fx * 0.375f;
            dep.CurrentLeadY += dep.Fy * 0.375f;
            float rearX = dep.CurrentLeadX + dep.Fx * dep.MinRearProj;
            float rearY = dep.CurrentLeadY + dep.Fy * dep.MinRearProj;
            bool pastScreen = (dep.Fx > 0.5f && rearX > lotDim - 2f + 44f) ||
                              (dep.Fx < -0.5f && rearX < 1f - 44f) ||
                              (dep.Fy > 0.5f && rearY > lotDim - 2f + 44f) ||
                              (dep.Fy < -0.5f && rearY < 1f - 44f);
            if (pastScreen)
                _departingVehicles.RemoveAt(i);
        }

        if (borderPortals.Count > 0)
        {
            foreach (var p in world.WalkOrder.OfType<XPerson>())
            {
                if (!currentVisiblePeople.Contains(p.Id))
                    continue;
                if (!_seenVisiblePeople.Add(p.Id))
                    continue;
                if (_heldPassengers.Contains(p.Id) || _baselinePeople.Contains(p.Id))
                    continue;

                int ptx = p.Position.X >> 4;
                int pty = p.Position.Y >> 4;
                if (!IsNearAnyPortal(ptx, pty, borderPortals, maxChebyshev: 2))
                    continue;

                var (inX, inY, inDir) = InwardBorderDirection(ptx, pty, lotDim);
                float targetX = p.Position.X / 16f;
                float targetY = p.Position.Y / 16f;
                float startX = targetX - inX * 22f;
                float startY = targetY - inY * 22f;
                float rootDir = AvatarDirection.Toward(inX, inY);

                short savedDir = p[ObjectData.Direction];
                float? savedRootDir = p.AnimatorRootDirection;
                int savedControlState = p.AnimatorControlState;
                var savedPlayback = p.AnimationPlayback;

                p[ObjectData.Direction] = inDir;
                p.AnimatorRootDirection = rootDir;
                float speed = ConfigureWalkLoop(world, p, preserveFrame: false);

                _approachingPeople[p.Id] = new ApproachingPerson
                {
                    PersonId = p.Id,
                    InwardX = inX,
                    InwardY = inY,
                    RootDirection = rootDir,
                    TilesPerTick = speed,
                    TargetTileX = targetX,
                    TargetTileY = targetY,
                    SavedDirection = savedDir,
                    SavedRootDirection = savedRootDir,
                    SavedControlState = savedControlState,
                    SavedPlayback = savedPlayback,
                    PrevTileX = startX,
                    PrevTileY = startY,
                    CurrentTileX = startX,
                    CurrentTileY = startY,
                };
            }
        }

        foreach (var (pid, appP) in _approachingPeople.ToArray())
        {
            var person = world.ObjectById(pid) as XPerson;
            if (person is null || !IsVisibleOnLot(person))
            {
                _approachingPeople.Remove(pid);
                continue;
            }
            appP.PrevTileX = appP.CurrentTileX;
            appP.PrevTileY = appP.CurrentTileY;
            float rem = (appP.TargetTileX - appP.CurrentTileX) * appP.InwardX +
                        (appP.TargetTileY - appP.CurrentTileY) * appP.InwardY;
            if (rem <= appP.TilesPerTick + 0.001f)
            {
                _approachingPeople.Remove(pid);
                if (person.NativeRoute is not null)
                {
                    person[ObjectData.Direction] = appP.SavedDirection;
                    person.AnimatorRootDirection = appP.SavedRootDirection;
                    person.AnimatorControlState = appP.SavedControlState;
                    person.AnimationPlayback = appP.SavedPlayback;
                }
                else
                {
                    person.AnimatorControlState = 3;
                    world.StopCurrentAnimation(person);
                }
            }
            else
            {
                appP.CurrentTileX += appP.InwardX * appP.TilesPerTick;
                appP.CurrentTileY += appP.InwardY * appP.TilesPerTick;
            }
        }

        foreach (var (pid, snap) in _liveBorderPeople.ToArray())
        {
            if (currentVisiblePeople.Contains(pid))
                continue;
            _liveBorderPeople.Remove(pid);
            _seenVisiblePeople.Remove(pid);

            if (world.ObjectById(pid) is XPerson stillOnLot && stillOnLot.Position.X >= 0 && stillOnLot.Position.Y >= 0)
                continue;

            int ltx = (int)MathF.Floor(snap.TileX);
            int lty = (int)MathF.Floor(snap.TileY);
            if (!IsNearAnyPortal(ltx, lty, borderPortals, maxChebyshev: 3))
                continue;
            if (IsNearAnyVehicle(snap.TileX, snap.TileY, _liveVehicles.Values))
                continue;

            var (inX, inY, _) = InwardBorderDirection(ltx, lty, lotDim);
            float outX = -inX;
            float outY = -inY;
            short outDir = AvatarDirection.ToObjectDirection(AvatarDirection.Toward(outX, outY));
            float rootDir = AvatarDirection.Toward(outX, outY);

            var clone = snap.Person;
            clone[ObjectData.Direction] = outDir;
            clone[ObjectData.Hidden] = 0;
            clone.AnimatorRootDirection = rootDir;
            float speed = ConfigureWalkLoop(world, clone, preserveFrame: true);
            world.TickAvatarAnimations(clone);

            int transitSeq = _nextTransitSeq;
            short synId = NextSyntheticObjectId();
            _departingPeople.Add(new DepartingPerson
            {
                TransitId = transitSeq,
                SyntheticObjectId = synId,
                Person = clone,
                Level = snap.Level,
                OutwardX = outX,
                OutwardY = outY,
                RootDirection = rootDir,
                TilesPerTick = speed,
                PrevTileX = snap.TileX,
                PrevTileY = snap.TileY,
                CurrentTileX = snap.TileX + outX * speed,
                CurrentTileY = snap.TileY + outY * speed,
            });
        }

        _liveBorderPeople.Clear();
        if (borderPortals.Count > 0)
        {
            foreach (var p in world.WalkOrder.OfType<XPerson>())
            {
                if (!currentVisiblePeople.Contains(p.Id) || _approachingPeople.ContainsKey(p.Id))
                    continue;
                int tx = p.Position.X >> 4;
                int ty = p.Position.Y >> 4;
                if (IsNearAnyPortal(tx, ty, borderPortals, maxChebyshev: 4))
                {
                    _liveBorderPeople[p.Id] = new LiveBorderPersonState(
                        p,
                        Math.Max(1, p.Position.Height),
                        p.Position.X / 16f,
                        p.Position.Y / 16f);
                }
            }
        }

        for (int i = _departingPeople.Count - 1; i >= 0; i--)
        {
            var dep = _departingPeople[i];
            dep.PrevTileX = dep.CurrentTileX;
            dep.PrevTileY = dep.CurrentTileY;
            dep.CurrentTileX += dep.OutwardX * dep.TilesPerTick;
            dep.CurrentTileY += dep.OutwardY * dep.TilesPerTick;
            world.TickAvatarAnimations(dep.Person);

            bool pastScreen = (dep.OutwardX > 0.5f && dep.CurrentTileX > lotDim - 2f + 30f) ||
                              (dep.OutwardX < -0.5f && dep.CurrentTileX < 1f - 30f) ||
                              (dep.OutwardY > 0.5f && dep.CurrentTileY > lotDim - 2f + 30f) ||
                              (dep.OutwardY < -0.5f && dep.CurrentTileY < 1f - 30f);
            if (pastScreen)
                _departingPeople.RemoveAt(i);
        }

        _prevVisiblePeople.Clear();
        foreach (short pid in currentVisiblePeople)
            _prevVisiblePeople.Add(pid);
    }

    private void ReleaseApproachingVehicle(short leadId, ApproachingVehicle appVeh)
    {
        _approachingVehicles.Remove(leadId);
        foreach (short mid in appVeh.MemberIds)
            _approachingVehicleByMember.Remove(mid);
        foreach (short pid in appVeh.HeldPassengerIds)
            _heldPassengers.Remove(pid);
    }

    private static float ConfigureWalkLoop(SimulationWorld world, XPerson person, bool preserveFrame)
    {
        short styleIndex = person[ObjectData.WalkStyle] == 1 ? (short)21 : (short)20;
        var clip = RouteExecutor.ResolveWalkAnimation(world, person, styleIndex)
                ?? RouteExecutor.ResolveWalkAnimation(world, person, 20);
        if (clip is null)
            return 0.0625f;

        person.AnimatorControlState = 0;
        if (preserveFrame && person.AnimationPlayback is { } cur &&
            string.Equals(cur.Clip.Name, clip.Name, StringComparison.OrdinalIgnoreCase))
        {
            var next = new AvatarAnimationPlayback(clip, backwards: false, loop: true, startedAtMils: person.AnimatorMilliseconds);
            next.SetFrame(cur.Frame);
            person.AnimationPlayback = next;
        }
        else
        {
            person.AnimationPlayback = new AvatarAnimationPlayback(clip, backwards: false, loop: true, startedAtMils: person.AnimatorMilliseconds);
        }

        if (clip.DurationMilliseconds > 0f && clip.StandardDistance > 0f)
        {
            float rawStep = RouteExecutor.RouteStepDistance(clip.StandardDistance, clip.DurationMilliseconds, 1f, 42f);
            return Math.Clamp(rawStep / 16f, 0.045f, 0.14f);
        }
        return 0.0625f;
    }

    private static float EntryBorderDistance(float tx, float ty, float fx, float fy, int lotDim)
    {
        if (fx > 0.5f) return tx - 1f;
        if (fx < -0.5f) return (lotDim - 2f) - tx;
        if (fy > 0.5f) return ty - 1f;
        return (lotDim - 2f) - ty;
    }

    private static float ExitBorderDistance(float tx, float ty, float fx, float fy, int lotDim)
    {
        if (fx > 0.5f) return (lotDim - 2f) - tx;
        if (fx < -0.5f) return tx - 1f;
        if (fy > 0.5f) return (lotDim - 2f) - ty;
        return ty - 1f;
    }

    private static bool IsNearAnyPortal(int tx, int ty, List<(int TileX, int TileY)> portals, int maxChebyshev)
    {
        for (int i = 0; i < portals.Count; i++)
        {
            var p = portals[i];
            if (Math.Max(Math.Abs(tx - p.TileX), Math.Abs(ty - p.TileY)) <= maxChebyshev)
                return true;
        }
        return false;
    }

    private static bool IsNearAnyVehicle(float tx, float ty, IEnumerable<LiveVehicleState> vehicles)
    {
        foreach (var v in vehicles)
        {
            if (MathF.Abs(tx - v.LeadTileX) <= 6f && MathF.Abs(ty - v.LeadTileY) <= 6f)
                return true;
        }
        return false;
    }

    private static (float InX, float InY, short InDir) InwardBorderDirection(int tx, int ty, int lotDim)
    {
        int dLeft = Math.Abs(tx - 1);
        int dRight = Math.Abs((lotDim - 2) - tx);
        int dTop = Math.Abs(ty - 1);
        int dBottom = Math.Abs((lotDim - 2) - ty);
        int best = Math.Min(Math.Min(dLeft, dRight), Math.Min(dTop, dBottom));
        if (best == dTop) return (0f, 1f, 4);
        if (best == dBottom) return (0f, -1f, 0);
        if (best == dLeft) return (1f, 0f, 2);
        return (-1f, 0f, 6);
    }
}
