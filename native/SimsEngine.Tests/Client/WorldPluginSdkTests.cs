using SimsEngine.Formats;
using SimsEngine.Simulation;
using Xunit;

namespace SimsEngine.Tests.Client;

public sealed class WorldPluginSdkTests
{
    [Fact]
    public void PluginWorldAllowsReadingAndWritingBaseGameObjectAttributesAndDefinedInteractions()
    {
        var chunk = new ChunkBuilder().S16(1).S16(8);
        chunk.U16(4096).U16(0).S32(0).U32(0).S32(0).U32(0).F32(0).U32(0).S32(0);
        var (file, resource) = chunk.InFile("TTAB");
        var table = InteractionTable.Read(file, resource).WithNames(static _ => "Water Flowers");

        var world = new SimulationWorld();
        var flower = world.Add(new XObject(10, PrimitiveTestWorld.Definition(), attributes: 4)
        {
            TypeRecord = new TypeRecord(0x11223344) { Interactions = table },
        });
        flower.Attributes[0] = 25;

        var pluginWorld = new SimsSimulation.PluginWorld(
            () => world,
            () => 1,
            () => null,
            () => null,
            () => false);

        var described = Assert.Single(pluginWorld.Objects);
        Assert.False(described.IsPerson);
        Assert.Equal(4, described.AttributeCount);
        Assert.Equal(["Water Flowers"], pluginWorld.GetDefinedInteractions(flower.Id));

        Assert.Equal(25, pluginWorld.GetObjectAttribute(flower.Id, 0));
        pluginWorld.SetObjectAttribute(flower.Id, 0, 100);
        Assert.Equal(100, flower.Attributes[0]);
    }

    [Fact]
    public void GlobalSubroutineInterceptorOverridesSimAnticsGlobalCall()
    {
        var world = new SimulationWorld();
        var igloo = world.Add(new XObject(5, PrimitiveTestWorld.Definition())
        {
            TypeRecord = new TypeRecord(unchecked((int)0xE8B4C5C2u)),
        });

        var globalTree = PrimitiveTestWorld.Tree(0,
            (2, BhavInstruction.ReturnFalse, BhavInstruction.ReturnFalse, PrimitiveTestWorld.Expression(0, 1, 2)));
        var callerTree = PrimitiveTestWorld.Tree(0,
            (428, BhavInstruction.ReturnTrue, BhavInstruction.ReturnFalse, [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF]));

        var table = new TreeTable((428, globalTree));
        Assert.False(TreeRunner.Run(new TreeContext(world, igloo, new StackFrame(igloo.Id, [], [])), callerTree, table: table));

        ushort interceptedId = 0;
        world.GlobalSubroutineInterceptor = (subId, me, _, _) =>
        {
            interceptedId = subId;
            return subId == 428 && unchecked((uint)(me.TypeRecord?.Key ?? 0)) == 0xE8B4C5C2u ? true : null;
        };

        Assert.True(TreeRunner.Run(new TreeContext(world, igloo, new StackFrame(igloo.Id, [], [])), callerTree, table: table));
        Assert.Equal((ushort)428, interceptedId);
    }
}
