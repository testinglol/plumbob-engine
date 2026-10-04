using System.Text.Json;
using FSO.Content;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Engine.Scopes;
using FSO.SimAntics.Marshals;
using FSO.SimAntics.Primitives;
using FSO.Vitaboy;

internal static class NativeAppearanceChecks
{
    internal static object Run(VM vm, string workspace, short house)
    {
        var original = vm.Save();
        var avatar = vm.Entities.OfType<VMAvatar>().First(entity => entity.Position.Level > 0 && entity.Position.x >= 0);
        var id = avatar.ObjectID;
        var directory = Path.Combine(workspace, "analysis", "appearance-check", Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(directory);
        var fixtures = new List<object>();
        var checks = 0;
        void Require(bool condition, string message) { if (!condition) throw new InvalidDataException(message); checks++; }
        try
        {
            var choices = new List<(VMEntity Owner, int Index, string Name, VMSuitScope Scope)>();
            void Find(VMEntity owner, STR? table, VMSuitScope scope)
            {
                if (table == null) return;
                for (var index = 0; index < Math.Min(table.Length, 256); index++)
                {
                    var name = VMAvatar.NormalizeAppearanceName(table.GetString(index));
                    try
                    {
                        var appearance = AvatarGeometry.ResolveAppearance(name);
                        if (appearance.Bindings.Length > 0 && !choices.Any(item => item.Name.Equals(name, StringComparison.OrdinalIgnoreCase)))
                            choices.Add((owner, index, name, scope));
                    }
                    catch { }
                }
            }
            Find(avatar, vm.Context.Globals.Resource.Get<STR>(304), VMSuitScope.Global);
            foreach (var entity in vm.Entities) Find(entity, entity.Object.Resource.Get<STR>(304), VMSuitScope.Object);
            Require(choices.Count > 0, "No original object-script appearance fixture found");
            var choice = choices[0];
            const string customName = "native-attachment-check";
            var sourceAppearance = AvatarGeometry.ResolveAppearance(choice.Name);
            var customFile = Path.Combine(directory, customName + ".cmx");
            using (var output = File.Create(customFile))
                new BCF([], [new Appearance { Name = customName, Type = sourceAppearance.Type, Zero = sourceAppearance.Zero, Bindings = sourceAppearance.Bindings }], []).Write(output, true);
            var customAppearanceLoaded = Content.Get().BCFGlobal.SkinHostBCF.ContainsKey(customName);
            avatar.BoundAppearances.Clear();
            var baseline = AvatarGeometry.Pose(avatar).Bindings.Count;
            var originalAppearanceChecks = 0;
            foreach (var item in choices)
            {
                avatar.BoundAppearances.Clear();
                avatar.BoundAppearances.Add(item.Name);
                var pose = AvatarGeometry.Pose(avatar);
                Require(AvatarGeometry.AppearanceFailures(avatar).Count == 0 && pose.Bindings.Count == baseline + AvatarGeometry.ResolveAppearance(item.Name).Bindings.Length,
                    $"Original appearance did not bind: {item.Name}");
                Require(AvatarGeometry.Build(avatar, new NativeEntityTransform((x, y) => 0)).Count == pose.Bindings.Count,
                    $"Original appearance did not export: {item.Name}");
                originalAppearanceChecks++;
            }
            avatar.BoundAppearances.Clear();
            foreach (var item in choices.Take(2)) avatar.BoundAppearances.Add(item.Name);
            Require(AvatarGeometry.Pose(avatar).Bindings.Count == baseline + choices.Take(2).Sum(item => AvatarGeometry.ResolveAppearance(item.Name).Bindings.Length), "Simultaneous appearances lost bindings");
            avatar.BoundAppearances.Clear();
            var handler = new VMChangeSuitOrAccessory();
            var frame = new VMStackFrame { Thread = avatar.Thread, Caller = avatar, Callee = choice.Owner, CodeOwner = choice.Owner.Object };
            avatar.Thread.TempRegisters[0] = (short)choice.Index;
            var operand = new VMChangeSuitOrAccessoryOperand { SuitData = 0, SuitScope = choice.Scope, Flags = VMChangeSuitOrAccessoryFlags.UseTemp };
            void Execute() => Require(handler.Execute(frame, operand) == VMPrimitiveExitCode.GOTO_TRUE, "Suit primitive failed");
            var exporter = new LotSceneExporter(vm, directory);
            var boundAnimation = Path.Combine(directory, "bound-animation.json");
            void Capture(string name)
            {
                var path = exporter.Snapshot(house, 0, true, fixtures.Count + 1);
                var target = Path.Combine(directory, name + ".json");
                File.Copy(path, target);
                var scene = JsonDocument.Parse(File.ReadAllText(target));
                var parts = scene.RootElement.GetProperty("meshes").EnumerateArray().Count(mesh => mesh.GetProperty("objectID").GetInt16() == id);
                fixtures.Add(new { name, scene = target, parts });
                Require(parts > 0, "Accessory changes removed the rendered Sim");
            }
            Capture("baseline");
            Execute();
            var bound = AvatarGeometry.Pose(avatar);
            var count = bound.Bindings.Count;
            Require(count > baseline && AvatarGeometry.AppearanceFailures(avatar).Count == 0, "Original script appearance was not bound");
            Require(ReferenceEquals(bound, AvatarGeometry.Pose(avatar)), "Unchanged appearance rebuilt the visual avatar");
            Execute();
            Require(AvatarGeometry.Pose(avatar).Bindings.Count == count, "Repeated dress duplicated bindings");
            File.WriteAllText(boundAnimation, JsonSerializer.Serialize(exporter.Animation(1, 1, 0), new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
            Capture("bound");
            avatar.BindAppearance(choice.Name[..^4].ToUpperInvariant());
            Require(avatar.BoundAppearances.Count == 1 && AvatarGeometry.Pose(avatar).Bindings.Count == count, "Mixed script and animation dress duplicated identity");
            avatar.UnbindAppearance(choice.Name[..^4].ToUpperInvariant());
            Require(avatar.BoundAppearances.Count == 0 && AvatarGeometry.Pose(avatar).Bindings.Count == baseline, "Bare undress did not remove script attachment");
            avatar.BindAppearance(choice.Name);
            avatar.BoundAppearances.Add(choice.Name[..^4].ToUpperInvariant());
            Require(AvatarGeometry.Pose(avatar).Bindings.Count == count, "Bare animation appearance duplicated the script attachment");
            avatar.BoundAppearances.Remove(choice.Name);
            Require(AvatarGeometry.Pose(avatar).Bindings.Count == count, "Bare animation appearance was not rendered");
            using var bytes = new MemoryStream();
            using (var writer = new BinaryWriter(bytes, System.Text.Encoding.UTF8, true)) vm.Save().SerializeInto(writer);
            bytes.Position = 0;
            var marshal = new VMMarshal();
            using (var reader = new BinaryReader(bytes, System.Text.Encoding.UTF8, true)) marshal.Deserialize(reader);
            vm.Load(marshal);
            avatar = (VMAvatar)vm.GetObjectById(id);
            Require(AvatarGeometry.Pose(avatar).Bindings.Count == count, "Saved appearance disappeared after load");
            Capture("loaded");
            avatar.BoundAppearances.Clear();
            avatar.BoundAppearances.Add(choice.Name);
            frame = new VMStackFrame { Thread = avatar.Thread, Caller = avatar, Callee = vm.GetObjectById(choice.Owner.ObjectID), CodeOwner = choice.Owner.Object };
            operand.SuitData = (byte)choice.Index;
            operand.Flags = VMChangeSuitOrAccessoryFlags.Remove;
            Execute();
            Require(AvatarGeometry.Pose(avatar).Bindings.Count == baseline, "Undress left stale appearance bindings");
            Capture("removed");
            avatar.BoundAppearances.Add(choice.Name);
            var previousBody = avatar.BodyOutfit;
            avatar.BodyOutfit = VMSuitProvider.GetPersonSuitTS1(avatar, (ushort)VMPersonSuits.DefaultSwimwear);
            Require(AvatarGeometry.Pose(avatar).Bindings.Count >= AvatarGeometry.ResolveAppearance(choice.Name).Bindings.Length && AvatarGeometry.AppearanceFailures(avatar).Count == 0, "Outfit change lost attachment");
            Capture("swimwear");
            avatar.BodyOutfit = previousBody;
            if (customAppearanceLoaded)
            {
                avatar.BoundAppearances.Clear();
                avatar.BoundAppearances.Add(customName);
                Require(AvatarGeometry.Pose(avatar).Bindings.Count == count && AvatarGeometry.AppearanceFailures(avatar).Count == 0, "Pack-defined appearance did not bind");
                Capture("custom");
                avatar.BoundAppearances.Clear();
                avatar.BoundAppearances.Add(choice.Name);
            }
            avatar.BoundAppearances.Add("native-missing-appearance.apr");
            Require(AvatarGeometry.Pose(avatar).Bindings.Count == count && AvatarGeometry.AppearanceFailures(avatar).Count == 1, "Missing appearance hid valid avatar bindings");
            Capture("missing");
            using (var missingScene = JsonDocument.Parse(File.ReadAllText(Path.Combine(directory, "missing.json"))))
                Require(missingScene.RootElement.GetProperty("missingResources").EnumerateArray().Any(value => value.GetString()!.Contains("native-missing-appearance.apr")), "Missing appearance diagnostic was not exported");
            avatar.BoundAppearances.Clear();
            Require(AvatarGeometry.Pose(avatar).Bindings.Count == baseline && AvatarGeometry.AppearanceFailures(avatar).Count == 0, "Appearance clear retained stale bindings or errors");
            return new { avatar = id, choice.Name, originalCandidates = choices.Count, originalAppearanceChecks, customFile, customAppearanceLoaded, boundAnimation, checks, fixtures, serializedSaveLoad = true, livePresentationVerified = false };
        }
        finally { vm.Load(original); }
    }
}
