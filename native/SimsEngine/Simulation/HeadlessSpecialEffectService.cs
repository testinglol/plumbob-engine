namespace SimsEngine.Simulation;

public readonly record struct HeadlessSpecialEffectDispatch(int CallerId, int StackObjectId, SpecialEffectRequest Request);

public sealed class HeadlessSpecialEffectService
{
    private readonly List<HeadlessSpecialEffectDispatch> _dispatches = [];

    public IReadOnlyList<HeadlessSpecialEffectDispatch> Dispatches => _dispatches;

    public bool TryStart(XObject caller, XObject stackObject, SpecialEffectRequest request)
    {
        ArgumentNullException.ThrowIfNull(caller);
        ArgumentNullException.ThrowIfNull(stackObject);
        _dispatches.Add(new HeadlessSpecialEffectDispatch(caller.Id, stackObject.Id, request));
        return true;
    }
}
