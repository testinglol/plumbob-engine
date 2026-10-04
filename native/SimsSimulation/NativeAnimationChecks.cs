using System.Text.Json;
using FSO.Content;
using FSO.Files.Utils;
using FSO.Files.Formats.IFF.Chunks;
using FSO.SimAntics;
using FSO.SimAntics.Engine;
using FSO.SimAntics.Engine.Primitives;
using FSO.SimAntics.Engine.Scopes;
using FSO.SimAntics.Marshals;
using FSO.SimAntics.Model;
using FSO.Vitaboy;
using Microsoft.Xna.Framework;

internal static class NativeAnimationChecks
{
    internal static object Run(VM vm, string workspace, short house)
    {
        int checks = 0;
        void Require(bool condition, string message) { if (!condition) throw new InvalidDataException(message); checks++; }
        foreach (var count in new[] { 0, 1, 2, 17, 65535, 65536, 65537 })
        {
            var source = new Animation
            {
                TranslationCount = (uint)count, RotationCount = (uint)count,
                Translations = Enumerable.Range(0, count).Select(index => new Vector3(index < count / 2 ? 1.25f : -2.5f, 0, 3)).ToArray(),
                Rotations = Enumerable.Repeat(new Quaternion(0, 0, 0, 1), count).ToArray()
            };
            var curves = new CFP();
            curves.CompressAnim(source);
            var decoded = new Animation { TranslationCount = (uint)count, RotationCount = (uint)count };
            curves.EnrichAnim(decoded);
            Require(decoded.Translations.SequenceEqual(source.Translations) && decoded.Rotations.SequenceEqual(source.Rotations), "CFP channel resets or repeat boundary changed exact values");
        }
        var moving = new Animation
        {
            TranslationCount = 200, RotationCount = 200,
            Translations = Enumerable.Range(0, 200).Select(index => new Vector3((float)Math.Sin(index * 0.2), index * 0.0001f, index * 1.25f)).ToArray(),
            Rotations = Enumerable.Range(0, 200).Select(index => Quaternion.CreateFromYawPitchRoll(index * 0.03f, 0, 0)).ToArray()
        };
        var encoded = new CFP();
        encoded.CompressAnim(moving);
        var read = new Animation { TranslationCount = 200, RotationCount = 200 };
        encoded.EnrichAnim(read);
        for (var index = 0; index < 200; index++)
        {
            var translationError = moving.Translations[index] - read.Translations[index];
            var rotationError = moving.Rotations[index] - read.Rotations[index];
            Require(new[] { translationError.X, translationError.Y, translationError.Z, rotationError.X, rotationError.Y, rotationError.Z, rotationError.W }.All(value => Math.Abs(value) <= CFP.MaximumEncodingError + 0.000001f), "CFP encoding exceeded channel error bound");
        }
        foreach (var bytes in new[] { new byte[] { 0xFD }, new byte[] { 0xFF }, new byte[] { 0xFE, 1, 0 }, new byte[] { 0xFF, 0, 0, 0xC0, 0x7F } })
        {
            var invalid = new Animation { TranslationCount = 1 };
            try { new CFP { Data = bytes }.EnrichAnim(invalid); throw new Exception("Invalid CFP was accepted"); }
            catch (Exception error) when (error is InvalidDataException or EndOfStreamException)
            {
                Require(invalid.Translations == null && invalid.Rotations == null, "Failed CFP decode cached partial arrays");
            }
        }
        var names = Content.Get().BCFGlobal.ListAllAnimations().Where(name => !name.Equals("native-authoring-wave.anim", StringComparison.OrdinalIgnoreCase)).Order(StringComparer.Ordinal).ToArray();
        var originals = new List<string>();
        var missing = new List<string>();
        foreach (var name in names.Where((_, index) => index % Math.Max(1, names.Length / 200) == 0).Take(200))
        {
            var animation = Content.Get().AvatarAnimations.Get(name);
            if (animation == null) { missing.Add(name); continue; }
            Require(animation.Translations.Length == animation.TranslationCount && animation.Rotations.Length == animation.RotationCount, "Original CFP arrays differ from their metadata");
            originals.Add(name);
        }
        const string customName = "native-authoring-wave";
        var custom = Content.Get().AvatarAnimations.Get(customName + ".anim") ?? throw new InvalidDataException("Compile and mount the native authoring animation fixture first");
        var original = vm.Save();
        var table = vm.Context.Globals.Resource.Get<STR>(128);
        var oldName = table.GetString(1);
        var avatar = vm.Entities.OfType<VMAvatar>().First(entity => entity.Position.Level > 0 && entity.Position.x >= 0);
        var id = avatar.ObjectID;
        var directory = Path.Combine(workspace, "analysis", "animation-check", Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(directory);
        var fixtures = new List<object>();
        try
        {
            table.SetString(1, customName);
            var frame = new VMStackFrame { Caller = avatar, Callee = avatar, CodeOwner = avatar.Object, Thread = avatar.Thread };
            var primitive = new VMAnimateSim();
            var operand = new VMAnimateSimOperand { AnimationID = 1, Source = VMAnimationScope.Global, Mode = 1 };
            Require(primitive.Execute(frame, operand) == VMPrimitiveExitCode.GOTO_TRUE && avatar.CurrentAnimationState.Anim == custom, "Original animate primitive did not resolve pack animation");
            Require(avatar.CurrentAnimationState.TimePropertyLists.Select(item => item.ID).SequenceEqual(new[] { 0, 33, 900 }), "Animation event order was not stable chronological order");
            var exporter = new LotSceneExporter(vm, directory);
            void Capture(string name)
            {
                var path = exporter.Snapshot(house, 0, true);
                var target = Path.Combine(directory, name + ".json");
                File.Copy(path, target);
                fixtures.Add(new { name, scene = target, frame = avatar.CurrentAnimationState.CurrentFrame });
            }
            void SuppressBehavior()
            {
                avatar.Thread.ThreadBreak = VMThreadBreakMode.Active;
                avatar.Thread.IsCheck = true;
                avatar.Thread.QueueDirty = false;
                avatar.Thread.Stack.Clear();
            }
            Capture("start");
            SuppressBehavior();
            avatar.Tick();
            Require(avatar.CurrentAnimationState.EventQueue.SequenceEqual(new short[] { 11, 12 }), "Out-of-order authored events were not executed at their times");
            while (avatar.CurrentAnimationState.CurrentFrame < 15) avatar.Tick();
            var animationPath = Path.Combine(directory, "middle-animation.json");
            File.WriteAllText(animationPath, JsonSerializer.Serialize(exporter.Animation(1, 1, 0), new JsonSerializerOptions { PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));
            Capture("middle");
            using var memory = new MemoryStream();
            using (var writer = new BinaryWriter(memory, System.Text.Encoding.UTF8, true)) vm.Save().SerializeInto(writer);
            memory.Position = 0;
            var marshal = new VMMarshal();
            using (var reader = new BinaryReader(memory, System.Text.Encoding.UTF8, true)) marshal.Deserialize(reader);
            var savedFrame = avatar.CurrentAnimationState.CurrentFrame;
            vm.Load(marshal);
            avatar = (VMAvatar)vm.GetObjectById(id);
            Require(avatar.CurrentAnimationState.Anim.Name == customName && avatar.CurrentAnimationState.CurrentFrame == savedFrame && avatar.CurrentAnimationState.EventQueue.SequenceEqual(new short[] { 11, 12 }), "Custom animation state failed serialized save/load");
            avatar.CurrentAnimationState.Load(avatar.CurrentAnimationState.Save());
            Require(avatar.CurrentAnimationState.TimePropertyLists.Count == 1 && avatar.CurrentAnimationState.TimePropertyLists[0].ID == 900, "Animation reload duplicated or replayed timed events");
            Capture("loaded");
            SuppressBehavior();
            while (avatar.CurrentAnimationState.CurrentFrame < 27) avatar.Tick();
            Require(avatar.CurrentAnimationState.EventQueue.SequenceEqual(new short[] { 11, 12, 13 }), "Saved animation skipped its pending event");
            Capture("end");
            frame = new VMStackFrame { Caller = avatar, Callee = avatar, CodeOwner = avatar.Object, Thread = avatar.Thread };
            operand = new VMAnimateSimOperand { AnimationID = 1, Source = VMAnimationScope.Global, Mode = 1, PlayBackwards = true };
            Require(primitive.Execute(frame, operand) == VMPrimitiveExitCode.GOTO_TRUE, "Backwards animate primitive failed");
            avatar.CurrentAnimationState.Loop = false;
            for (var tick = 0; tick < 100 && !avatar.CurrentAnimationState.EndReached; tick++) avatar.Tick();
            Require(avatar.CurrentAnimationState.EventQueue.SequenceEqual(new short[] { 13, 12, 11 }), "Backwards animation did not execute events in reverse time order");
            return new { checks, originalAnimationsDecoded = originals.Count, originalMissingCurves = missing, compiledAnimation = customName, frames = custom.NumFrames,
                avatar = id, fixtures, animation = animationPath, serializedSaveLoad = true, backwardsEvents = true, livePresentationVerified = false };
        }
        finally { table.SetString(1, oldName); vm.Load(original); }
    }
}
