using System.Reflection;

/// <summary>Calls the server's private handlers from checks, filling optional parameters the caller leaves out.</summary>
internal static class NativeServerReflection
{
    internal static object? Invoke(SimulationServer server, string method, object[] args)
    {
        var info = typeof(SimulationServer).GetMethod(method, BindingFlags.Instance | BindingFlags.NonPublic)!;
        var parameters = info.GetParameters();
        if (args.Length < parameters.Length)
            args = args.Concat(parameters.Skip(args.Length).Select(parameter => parameter.HasDefaultValue ? parameter.DefaultValue : throw new TargetParameterCountException(method))).ToArray();
        return info.Invoke(server, args);
    }
}
