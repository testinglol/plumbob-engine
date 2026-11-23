using SimsEngine.Formats;
using SimsEngine.Simulation;

namespace SimsSimulation;

internal sealed class AutonomyHost : ISimulationAutonomyHost
{
    private readonly SimulationWorld world;
    private readonly int lotKey;
    private readonly Func<bool> paused;
    private readonly Func<XPerson, XObject, short, string, float, float>? scoreAutonomy;
    private readonly Func<XPerson, bool>? directsAutonomy;
    private readonly Func<AutonomySelectionContext, IReadOnlyList<AutonomyCandidateSnapshot>, int?>? selectAutonomy;

    public AutonomyHost(SimulationWorld world, IffFile global, int lotKey, Func<bool> paused,
        Func<XPerson, XObject, short, string, float, float>? scoreAutonomy = null,
        Func<XPerson, bool>? directsAutonomy = null,
        Func<AutonomySelectionContext, IReadOnlyList<AutonomyCandidateSnapshot>, int?>? selectAutonomy = null)
    {
        this.world = world ?? throw new ArgumentNullException(nameof(world));
        ArgumentNullException.ThrowIfNull(global);
        this.lotKey = lotKey;
        this.paused = paused ?? throw new ArgumentNullException(nameof(paused));
        this.scoreAutonomy = scoreAutonomy;
        this.directsAutonomy = directsAutonomy;
        this.selectAutonomy = selectAutonomy;
    }

    public float ScoreAutonomy(XPerson person, XObject target, short actionIndex, string actionName, float score) =>
        scoreAutonomy is null ? score : scoreAutonomy(person, target, actionIndex, actionName, score);

    public bool DirectsAutonomy(XPerson person) =>
        directsAutonomy is not null && directsAutonomy(person);

    public int? SelectAutonomyCandidate(AutonomySelectionContext context, IReadOnlyList<AutonomyCandidateSnapshot> candidates) =>
        selectAutonomy is null ? null : selectAutonomy(context, candidates);

    public AutonomyLot AutonomyLotState()
    {
        var homeFamily = world[SimulationGlobal.CurrentFamily] != 0
            ? world[SimulationGlobal.CurrentFamily]
            : world.WalkOrder.OfType<XPerson>()
                .FirstOrDefault(person => person[PersonData.PersonType] == 0)?[PersonData.FamilyNumber] ?? (short)0;
        var activePerson = world.ActivePersonAt(0)
            ?? (world.ActivePersonRecordId(0) is { } activeId ? world.ObjectById(activeId) as XPerson : null)
            ?? world.WalkOrder.OfType<XPerson>().FirstOrDefault(person => person.SelectionWord5CC != 0);
        return new AutonomyLot(world.AutonomyForced ?? false, paused(), false, homeFamily != 0 ? homeFamily : lotKey, homeFamily,
            world.LotTransformParameter, activePerson);
    }

}
