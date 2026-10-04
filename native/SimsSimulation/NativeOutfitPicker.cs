using System.Text.Json;
using FSO.SimAntics;
using FSO.SimAntics.Model;
using FSO.SimAntics.Primitives;
using FSO.SimAntics.Utils;
using FSO.Vitaboy;

/// <summary>
/// Data side of the original wardrobe (TS1Clothes) and pet-choice (TS1PetChoice) dialogs. Both return the index of an
/// entry in <see cref="VMTS1PurchasableOutfitHelper.GetValidOutfits"/> as the numeric response, with response code 1 for a
/// selection and 0 for cancel (the engine's dialog primitive then stores the index in a temp register).
/// </summary>
internal static class NativeOutfitPicker
{
    internal sealed record Choice(int Index, string Name);
    internal sealed record Context(VMAvatar Subject, short OutfitType, bool Pet);

    public static Context? Find(VM vm)
    {
        var holder = vm.GlobalBlockingDialog;
        if (holder?.Thread.BlockingState is not VMDialogResult { Type: VMDialogType.TS1Clothes or VMDialogType.TS1PetChoice } state) return null;
        if (state.Type == VMDialogType.TS1Clothes)
            return holder is VMAvatar sim ? new Context(sim, holder.Thread.TempRegisters[0], false) : null;
        var pet = holder.Thread.Stack.LastOrDefault()?.StackObject as VMAvatar;
        return pet == null ? null : new Context(pet, (short)(pet.IsCat ? -2 : -1), true);
    }

    private static Tuple<string, string>[] Outfits(Context context) =>
        VMTS1PurchasableOutfitHelper.GetValidOutfits(context.Pet ? null : context.Subject, context.OutfitType);

    public static Choice[] Choices(Context context) =>
        Outfits(context).Select((outfit, index) => new Choice(index, outfit.Item1.Split(',')[0])).Take(256).ToArray();

    /// <summary>Dresses the subject in an outfit only long enough to export its geometry, then restores it.</summary>
    public static object Preview(string session, Context context, int index)
    {
        var outfits = Outfits(context);
        if (index < 0 || index >= outfits.Length) throw new ArgumentException("Outfit index is out of range");
        var parts = outfits[index].Item1.Split(',');
        var texture = parts.Select(part => part.StartsWith("BODY=", StringComparison.OrdinalIgnoreCase) ? part[5..] : null).FirstOrDefault(value => value != null)
            ?? throw new InvalidDataException("The outfit has no body texture");
        var subject = context.Subject;
        var previous = subject.BodyOutfit;
        try
        {
            var outfit = new Outfit { TS1AppearanceID = parts[0] + ".apr", TS1TextureID = texture };
            if (!context.Pet)
            {
                // Sims carry a literal hand group matching the outfit's hand texture, as Simitone's picker builds it.
                var bodyStrings = subject.Object.Resource.Get<FSO.Files.Formats.IFF.Chunks.STR>(subject.Object.OBJ.BodyStringID);
                var simType = bodyStrings.GetString(1).Substring(4);
                simType = simType[..simType.IndexOf('_')];
                var code = simType[1] == 'a' ? simType[0] : 'u';
                var hand = outfits[index].Item2;
                Gesture Gesture(string name, string prefix) => new() { Name = $"h{code}{name}.apr", TexName = prefix + hand };
                outfit.LiteralHandgroup = new HandGroup
                {
                    TS1HandSet = true,
                    LightSkin = new HandSet
                    {
                        LeftHand = new Hand { Idle = Gesture("lo", "huao"), Pointing = Gesture("lp", "huap"), Fist = Gesture("lc", "huac") },
                        RightHand = new Hand { Idle = Gesture("ro", "huao"), Pointing = Gesture("rp", "huap"), Fist = Gesture("rc", "huac") }
                    }
                };
            }
            subject.BodyOutfit = new VMOutfitReference(outfit);
            var geometry = AvatarGeometry.Build(subject, new NativeEntityTransform((_, _) => 0), new NativeLotCamera(0, 128, 128));
            if (geometry.Count == 0) throw new InvalidDataException("The outfit produced no preview geometry");
            return NativeHouseholdAppearancePreview.Write(session, geometry);
        }
        finally { subject.BodyOutfit = previous; }
    }

    /// <summary>
    /// Exercises the picker data for a household Sim and for a cat and a dog: each has outfits, every sampled preview exports
    /// geometry, and the subject's own outfit is restored afterwards. Preview files go to <paramref name="output"/> for rendering.
    /// </summary>
    public static object Check(VM vm, string output)
    {
        var family = vm.TS1State.CurrentFamily ?? throw new InvalidDataException("Outfit picker check has no active household");
        var sim = vm.Entities.OfType<VMAvatar>().First(entity => entity.GetPersonData(VMPersonDataVariable.TS1FamilyNumber) == family.ChunkID &&
            entity.GetPersonData(VMPersonDataVariable.PersonsAge) >= 18);
        var results = new List<object>();
        object Exercise(string label, Context context)
        {
            var choices = Choices(context);
            if (choices.Length == 0) throw new InvalidDataException($"{label} has no outfits to choose from");
            var before = context.Subject.BodyOutfit;
            var sampled = new List<int> { 0, choices.Length / 2, choices.Length - 1 }.Distinct().ToArray();
            var directory = Path.Combine(output, label);
            Directory.CreateDirectory(directory);
            foreach (var index in sampled)
            {
                var written = JsonSerializer.SerializeToElement(Preview(directory, context, index));
                if (written.GetProperty("meshes").GetInt32() == 0) throw new InvalidDataException($"{label} outfit {index} exported no meshes");
            }
            if (!ReferenceEquals(before, context.Subject.BodyOutfit)) throw new InvalidDataException($"{label} preview left the subject in a different outfit");
            File.WriteAllText(Path.Combine(directory, "choices.json"), JsonSerializer.Serialize(choices.Select(choice => choice.Name)));
            return new { label, outfits = choices.Length, previewed = sampled, firstOutfits = choices.Take(3).Select(choice => choice.Name).ToArray(), directory };
        }
        results.Add(Exercise("wardrobe", new Context(sim, 0, false)));
        foreach (var (label, guid, type) in new[] { ("cat", 0x7BEA0977u, (short)-2), ("dog", 0x4A70DF92u, (short)-1) })
        {
            var instance = vm.Context.CreateObjectInstance(guid, FSO.LotView.Model.LotTilePos.OUT_OF_WORLD, FSO.LotView.Model.Direction.NORTH)?.BaseObject as VMAvatar
                ?? throw new InvalidDataException($"The {label} template object is not installed");
            try { results.Add(Exercise(label, new Context(instance, type, true))); }
            finally { instance.Delete(true, vm.Context); }
        }
        return new { result = "passed", pickers = results };
    }
}
