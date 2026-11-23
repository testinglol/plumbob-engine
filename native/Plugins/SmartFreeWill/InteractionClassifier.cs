using SimsNative.Plugins;

namespace Local.SmartFreeWill;

internal enum SmartObjectKind
{
    General,
    Bed,
    DoubleBed,
    CouchOrRecliner,
    Chair,
    Toilet,
    Shower,
    Tub,
    HotTub,
    Sink,
    Fridge,
    CookingAppliance,
    CaffeineMaker,
    PreparedFood,
    GroupMeal,
    DirtyDish,
    TrashOrAsh,
    TrashReceptacle,
    FloodOrPuddle,
    Bills,
    Mailbox,
    BabyCrib,
    PetFoodOrLitter,
    Carpool,
    SchoolBus,
    Fire,
    Phone,
    PlantOrGarden,
    Fireplace,
    Television,
    Stereo,
    ComputerOrArcade,
    MusicalInstrument,
    SkillObject,
    LeisureObject,
    Person,
}

internal enum SmartActionKind
{
    General,
    SleepInBed,
    Nap,
    DrinkCaffeine,
    UseToilet,
    TakeShower,
    TakeBath,
    UseHotTub,
    WashHandsOrBrush,
    EatPreparedMeal,
    PrepareSingleMeal,
    PrepareGroupMeal,
    HaveSnack,
    CleanOrDispose,
    MakeBed,
    WaterPlant,
    RepairObject,
    PayBills,
    GetMail,
    BoardCarpool,
    BoardSchoolBus,
    CareForBaby,
    CareForPet,
    GreetVisitor,
    SocialFriendly,
    SocialPlayful,
    SocialRomantic,
    SocialHostile,
    PhoneCallFriend,
    WatchTv,
    TurnOnMedia,
    TurnOffMedia,
    SwitchChannelOrStation,
    DanceToMusic,
    PlayComputerOrArcade,
    PlayInstrument,
    TrainSkill,
    StudySchool,
    JoinGroupActivity,
    SitOrRelax,
    LightFire,
    ExtinguishOrPanicFire,
    Leisure,
}

[Flags]
internal enum SkillMask
{
    None = 0,
    Cooking = 1 << 0,
    Mechanical = 1 << 1,
    Logic = 1 << 2,
    Body = 1 << 3,
    Creativity = 1 << 4,
    Charisma = 1 << 5,
    Study = 1 << 6,
}

internal sealed record ClassifiedAction(
    SmartObjectKind ObjectKind,
    SmartActionKind ActionKind,
    SkillMask TrainedSkills,
    bool IsElectricalRepairRisk,
    bool IsStoveFireRisk,
    bool IsBathroomPrivacySensitive);

internal static class InteractionClassifier
{
    public const int MotiveMood = 3;
    public const int MotiveEnergy = 5;
    public const int MotiveComfort = 6;
    public const int MotiveHunger = 7;
    public const int MotiveHygiene = 8;
    public const int MotiveBladder = 9;
    public const int MotiveSleepState = 11;
    public const int MotiveRoom = 13;
    public const int MotiveSocial = 14;
    public const int MotiveFun = 15;

    public static SmartObjectKind ClassifyObject(PluginObject obj, bool isSim)
    {
        if (isSim)
            return SmartObjectKind.Person;

        var name = obj.Name ?? "";

        if (ContainsAny(name, "fire") && !ContainsAny(name, "fireplace", "firepit", "campfire", "alarm", "truck", "fighter"))
            return SmartObjectKind.Fire;
        if (ContainsAny(name, "schoolbus", "school bus"))
            return SmartObjectKind.SchoolBus;
        if (ContainsAny(name, "carpool", "car -", "car-", "limo", "towncar") && !ContainsAny(name, "toy", "wreck"))
            return SmartObjectKind.Carpool;
        if (ContainsAny(name, "baby") && !ContainsAny(name, "toy", "dragon"))
            return SmartObjectKind.BabyCrib;
        if (ContainsAny(name, "bills") && !ContainsAny(name, "billiard", "billboard"))
            return SmartObjectKind.Bills;
        if (ContainsAny(name, "mailbox", "mail box"))
            return SmartObjectKind.Mailbox;
        if (ContainsAny(name, "flood", "puddle"))
            return SmartObjectKind.FloodOrPuddle;
        if (ContainsAny(name, "espresso", "coffeemaker", "coffee maker", "coffee -"))
            return SmartObjectKind.CaffeineMaker;
        if (ContainsAny(name, "fireplace"))
            return SmartObjectKind.Fireplace;
        if (ContainsAny(name, "phone") && !ContainsAny(name, "phonograph", "saxophone", "xylophone", "megaphone", "microphone"))
            return SmartObjectKind.Phone;
        if (ContainsAny(name, "pet bowl", "food bowl", "dog bowl", "cat bowl", "litterbox", "litter box", "birdcage", "aquarium", "fishbowl"))
            return SmartObjectKind.PetFoodOrLitter;

        if ((obj.FunctionFlags & 0x01) != 0 && ((obj.FunctionSubsort & 0x04) != 0 || obj.RatingEnergy >= 3 || ContainsAny(name, "bed -", "bed_", "heartbed", "igloo", "tent")))
        {
            if (obj.LeadObjectId != obj.ObjectId || ContainsAny(name, "double", "heartbed", "igloo") || (obj.Price >= 900 && ContainsAny(name, "bed")))
                return SmartObjectKind.DoubleBed;
            return SmartObjectKind.Bed;
        }

        if ((obj.FunctionFlags & 0x10) != 0 || (obj.RoomSort & 0x04) != 0)
        {
            if (ContainsAny(name, "hottub", "hot tub", "whirlpool", "spa tub"))
                return SmartObjectKind.HotTub;
            if (obj.RatingBladder > 0 || ContainsAny(name, "toilet", "stall", "out-house", "outhouse", "urinal"))
                return SmartObjectKind.Toilet;
            if (ContainsAny(name, "shower"))
                return SmartObjectKind.Shower;
            if (obj.RatingHygiene >= 4 && ContainsAny(name, "tub", "bath"))
                return SmartObjectKind.Tub;
            if (obj.WashHandsValue > 0 || obj.WashDishValue > 0 || ContainsAny(name, "sink", "dishwasher"))
                return SmartObjectKind.Sink;
        }

        if (ContainsAny(name, "fridge", "refrigerator"))
            return SmartObjectKind.Fridge;
        if (obj.CookValue > 0 || ContainsAny(name, "stove", "oven", "microwave", "toaster", "grill", "barbecue", "bbq"))
            return SmartObjectKind.CookingAppliance;

        if (ContainsAny(name, "trash", "garbage", "rubbish", "ash", "rotten", "flies"))
        {
            if (obj.DisposeValue > 0 || ContainsAny(name, "can", "barrel", "compactor", "chute", "bin"))
                return SmartObjectKind.TrashReceptacle;
            return SmartObjectKind.TrashOrAsh;
        }

        if (ContainsAny(name, "food", "meal", "platter", "pizza", "plate", "snack", "cake", "buffet", "turkey"))
        {
            if (obj.DirtyLevel > 0 || ContainsAny(name, "empty", "dirty", "spoiled"))
                return SmartObjectKind.DirtyDish;
            if (ContainsAny(name, "group", "platter", "serve", "pizza", "buffet", "turkey", "cake"))
                return SmartObjectKind.GroupMeal;
            return SmartObjectKind.PreparedFood;
        }

        if (obj.GardeningValue > 0 || ContainsAny(name, "flower", "plant", "garden", "shrub", "fern", "orchid", "violet"))
            return SmartObjectKind.PlantOrGarden;

        if (ContainsAny(name, "tv", "television", "tele-"))
            return SmartObjectKind.Television;

        if (ContainsAny(name, "stereo", "boombox", "jukebox", "phonograph", "djbooth", "dj booth"))
            return SmartObjectKind.Stereo;

        if (ContainsAny(name, "computer", "pinball", "arcade", "vr ", "videogame"))
            return SmartObjectKind.ComputerOrArcade;

        if (ContainsAny(name, "piano", "guitar", "drum", "karaoke", "saxophone"))
            return SmartObjectKind.MusicalInstrument;

        if ((obj.FunctionFlags & 0x01) != 0)
        {
            if ((obj.FunctionSubsort & 0x02) != 0 || obj.RatingEnergy > 0 || ContainsAny(name, "sofa", "couch", "loveseat", "recliner", "bench", "lounge"))
                return SmartObjectKind.CouchOrRecliner;
            return SmartObjectKind.Chair;
        }

        if ((SkillMask)(obj.SkillFlags & 0x7f) != SkillMask.None)
            return SmartObjectKind.SkillObject;

        if (obj.RatingFun > 0)
            return SmartObjectKind.LeisureObject;

        return SmartObjectKind.General;
    }

    public static ClassifiedAction Classify(
        PluginObject obj,
        bool targetIsSim,
        string interactionName,
        string? englishName,
        bool joinInteraction,
        ReadOnlySpan<float> deltas)
    {
        var objectKind = ClassifyObject(obj, targetIsSim);
        var label = !string.IsNullOrWhiteSpace(englishName) ? englishName! : interactionName;
        var skills = InferSkills(obj, label);

        var dEnergy = Delta(deltas, MotiveEnergy);
        var dComfort = Delta(deltas, MotiveComfort);
        var dHunger = Delta(deltas, MotiveHunger);
        var dHygiene = Delta(deltas, MotiveHygiene);
        var dBladder = Delta(deltas, MotiveBladder);
        var dRoom = Delta(deltas, MotiveRoom);
        var dSocial = Delta(deltas, MotiveSocial);
        var dFun = Delta(deltas, MotiveFun);

        var electricalRepairRisk = obj.RepairState != 0 &&
            ((obj.FunctionFlags & (0x04 | 0x08 | 0x80)) != 0 ||
             objectKind is SmartObjectKind.Television or SmartObjectKind.Stereo or SmartObjectKind.ComputerOrArcade ||
             ContainsAny(obj.Name, "tv", "television", "computer", "stereo", "espresso", "compactor", "dishwasher", "lamp", "pinball", "robot"));

        var stoveFireRisk = objectKind == SmartObjectKind.CookingAppliance &&
            !ContainsAny(obj.Name, "microwave") &&
            ContainsAny(obj.Name, "stove", "oven", "grill", "toaster", "barbecue", "bbq");

        if (objectKind == SmartObjectKind.Carpool || ContainsAny(label, "go to work", "carpool"))
            return new(objectKind, SmartActionKind.BoardCarpool, SkillMask.None, false, false, false);

        if (objectKind == SmartObjectKind.SchoolBus || ContainsAny(label, "go to school"))
            return new(objectKind, SmartActionKind.BoardSchoolBus, SkillMask.None, false, false, false);

        if (objectKind == SmartObjectKind.Fire || ContainsAny(label, "extinguish", "put out fire", "fire!"))
            return new(objectKind, SmartActionKind.ExtinguishOrPanicFire, SkillMask.None, false, false, false);

        if (objectKind == SmartObjectKind.BabyCrib)
            return new(objectKind, SmartActionKind.CareForBaby, SkillMask.None, false, false, false);

        if (objectKind == SmartObjectKind.Bills || ContainsAny(label, "pay bill", "pay all bills"))
            return new(objectKind, SmartActionKind.PayBills, SkillMask.None, false, false, false);

        if (objectKind == SmartObjectKind.Mailbox && ContainsAny(label, "get mail", "pay"))
            return new(objectKind, ContainsAny(label, "pay") ? SmartActionKind.PayBills : SmartActionKind.GetMail, SkillMask.None, false, false, false);

        if (ContainsAny(label, "repair", "fix", "unclog", "plunge") || (obj.RepairState != 0 && !ContainsAny(label, "call", "view", "dispose")))
            return new(objectKind, SmartActionKind.RepairObject, skills | SkillMask.Mechanical, electricalRepairRisk, false, objectKind is SmartObjectKind.Toilet or SmartObjectKind.Shower or SmartObjectKind.Tub);

        if (objectKind == SmartObjectKind.FloodOrPuddle || ContainsAny(label, "mop", "clean", "wash dish", "empty trash", "take out trash", "dispose", "recycle", "clear", "sweep"))
        {
            if (objectKind is SmartObjectKind.Bed or SmartObjectKind.DoubleBed || ContainsAny(label, "make bed"))
                return new(objectKind, SmartActionKind.MakeBed, SkillMask.None, false, false, false);
            if (!ContainsAny(label, "clean self", "wash hands", "brush"))
                return new(objectKind, SmartActionKind.CleanOrDispose, SkillMask.None, false, false, false);
        }

        if (ContainsAny(label, "make bed"))
            return new(objectKind, SmartActionKind.MakeBed, SkillMask.None, false, false, false);

        if (objectKind == SmartObjectKind.PlantOrGarden && (ContainsAny(label, "water", "tend", "weed", "harvest") || dRoom > 0))
            return new(objectKind, SmartActionKind.WaterPlant, SkillMask.None, false, false, false);

        if (objectKind == SmartObjectKind.PetFoodOrLitter && ContainsAny(label, "fill", "feed", "clean"))
            return new(objectKind, SmartActionKind.CareForPet, SkillMask.None, false, false, false);

        if (objectKind == SmartObjectKind.Fireplace && ContainsAny(label, "light"))
            return new(objectKind, SmartActionKind.LightFire, SkillMask.None, false, true, false);

        if (targetIsSim)
        {
            if (ContainsAny(label, "greet", "welcome", "invite in"))
                return new(objectKind, SmartActionKind.GreetVisitor, SkillMask.None, false, false, false);
            if (ContainsAny(label, "flirt", "kiss", "romantic", "propose", "serenade", "sweet talk", "make out", "caress", "cuddle", "compliment"))
                return new(objectKind, SmartActionKind.SocialRomantic, SkillMask.None, false, false, false);
            if (ContainsAny(label, "insult", "slap", "attack", "fight", "scare", "tease", "nag", "brag", "annoy", "poke"))
                return new(objectKind, SmartActionKind.SocialHostile, SkillMask.None, false, false, false);
            if (ContainsAny(label, "joke", "entertain", "tickle", "play", "dance", "splash", "tag", "cheer", "puppet"))
                return new(objectKind, SmartActionKind.SocialPlayful, SkillMask.None, false, false, false);
            return new(objectKind, SmartActionKind.SocialFriendly, SkillMask.None, false, false, false);
        }

        if (objectKind == SmartObjectKind.Phone && (ContainsAny(label, "call", "talk", "invite") && !ContainsAny(label, "service", "pizza", "maid", "repair", "gardener", "police", "fire", "cab", "vacation")))
            return new(objectKind, SmartActionKind.PhoneCallFriend, SkillMask.None, false, false, false);

        if (objectKind == SmartObjectKind.CaffeineMaker || ContainsAny(label, "espresso", "coffee"))
            return new(objectKind, SmartActionKind.DrinkCaffeine, SkillMask.None, false, false, false);

        if (objectKind is SmartObjectKind.Television or SmartObjectKind.Stereo)
        {
            if (ContainsAny(label, "turn off", "shut off"))
                return new(objectKind, SmartActionKind.TurnOffMedia, SkillMask.None, false, false, false);
            if (ContainsAny(label, "switch to", "change channel", "next song"))
                return new(objectKind, SmartActionKind.SwitchChannelOrStation, SkillMask.None, false, false, false);
            if (objectKind == SmartObjectKind.Stereo && ContainsAny(label, "dance", "join"))
                return new(objectKind, SmartActionKind.DanceToMusic, SkillMask.None, false, false, false);
            if (objectKind == SmartObjectKind.Television && ContainsAny(label, "watch", "join"))
                return new(objectKind, SmartActionKind.WatchTv, SkillMask.None, false, false, false);
            if (ContainsAny(label, "turn on"))
                return new(objectKind, objectKind == SmartObjectKind.Television ? SmartActionKind.WatchTv : SmartActionKind.TurnOnMedia, SkillMask.None, false, false, false);
        }

        if (objectKind == SmartObjectKind.ComputerOrArcade)
        {
            if ((skills & SkillMask.Study) != 0 && ContainsAny(label, "study", "homework"))
                return new(objectKind, SmartActionKind.StudySchool, skills, false, false, false);
            if (ContainsAny(label, "find a job", "look for job"))
                return new(objectKind, SmartActionKind.General, SkillMask.None, false, false, false);
            return new(objectKind, SmartActionKind.PlayComputerOrArcade, skills, false, false, false);
        }

        if (objectKind == SmartObjectKind.MusicalInstrument && !ContainsAny(label, "watch", "listen"))
            return new(objectKind, SmartActionKind.PlayInstrument, skills | SkillMask.Creativity, false, false, false);

        if (objectKind is SmartObjectKind.Bed or SmartObjectKind.DoubleBed)
        {
            if (ContainsAny(label, "sleep") || dEnergy >= 30f)
                return new(objectKind, SmartActionKind.SleepInBed, SkillMask.None, false, false, false);
            if (ContainsAny(label, "nap", "relax", "daydream", "vibrate"))
                return new(objectKind, SmartActionKind.Nap, SkillMask.None, false, false, false);
        }

        if (ContainsAny(label, "nap", "doze") || (objectKind == SmartObjectKind.CouchOrRecliner && dEnergy >= 12f))
            return new(objectKind, SmartActionKind.Nap, SkillMask.None, false, false, false);

        if (objectKind == SmartObjectKind.Toilet || (dBladder >= 25f && dHygiene <= 15f))
        {
            if (ContainsAny(label, "flush"))
                return new(objectKind, SmartActionKind.CleanOrDispose, SkillMask.None, false, false, true);
            return new(objectKind, SmartActionKind.UseToilet, SkillMask.None, false, false, true);
        }

        if (objectKind == SmartObjectKind.HotTub || (dHygiene >= 10f && dFun >= 15f && dSocial >= 10f))
            return new(objectKind, SmartActionKind.UseHotTub, SkillMask.None, false, false, false);

        if (objectKind == SmartObjectKind.Shower || (dHygiene >= 30f && ContainsAny(label, "shower")))
            return new(objectKind, SmartActionKind.TakeShower, SkillMask.None, false, false, true);

        if (objectKind == SmartObjectKind.Tub || (dHygiene >= 30f && (dComfort >= 15f || ContainsAny(label, "bath", "soak"))))
            return new(objectKind, SmartActionKind.TakeBath, SkillMask.None, false, false, true);

        if (objectKind == SmartObjectKind.Sink || (dHygiene is > 3f and < 30f && ContainsAny(label, "wash hands", "brush teeth", "freshen")))
            return new(objectKind, SmartActionKind.WashHandsOrBrush, SkillMask.None, false, false, false);

        if (objectKind is SmartObjectKind.GroupMeal or SmartObjectKind.PreparedFood || ContainsAny(label, "grab a plate", "eat"))
        {
            if (objectKind is SmartObjectKind.DirtyDish || ContainsAny(label, "clean", "dispose"))
                return new(objectKind, SmartActionKind.CleanOrDispose, SkillMask.None, false, false, false);
            return new(objectKind, SmartActionKind.EatPreparedMeal, SkillMask.None, false, false, false);
        }

        if (objectKind is SmartObjectKind.Fridge or SmartObjectKind.CookingAppliance || dHunger >= 20f)
        {
            if (ContainsAny(label, "serve", "group meal", "make dinner", "make lunch", "make breakfast"))
                return new(objectKind, SmartActionKind.PrepareGroupMeal, skills, false, stoveFireRisk, false);
            if (ContainsAny(label, "snack", "quick", "juice", "candy") || (dHunger is > 5f and <= 28f && !ContainsAny(label, "have ", "cook")))
                return new(objectKind, SmartActionKind.HaveSnack, SkillMask.None, false, false, false);
            return new(objectKind, SmartActionKind.PrepareSingleMeal, skills, false, stoveFireRisk, false);
        }

        if ((skills & SkillMask.Study) != 0 && ContainsAny(label, "study", "school", "homework", "read"))
            return new(objectKind, SmartActionKind.StudySchool, skills, false, false, false);

        if ((skills & ~SkillMask.Study) != SkillMask.None)
            return new(objectKind, SmartActionKind.TrainSkill, skills, false, false, false);

        if (joinInteraction || ContainsAny(label, "join"))
            return new(objectKind, SmartActionKind.JoinGroupActivity, skills, false, false, false);

        if (objectKind is SmartObjectKind.Chair or SmartObjectKind.CouchOrRecliner && dComfort > 5f && dFun <= 5f)
            return new(objectKind, SmartActionKind.SitOrRelax, SkillMask.None, false, false, false);

        if (dFun > 5f || objectKind == SmartObjectKind.LeisureObject)
            return new(objectKind, SmartActionKind.Leisure, skills, false, false, false);

        return new(objectKind, SmartActionKind.General, skills, electricalRepairRisk, stoveFireRisk, false);
    }

    public static SkillMask InferSkills(PluginObject obj, string label)
    {
        var mask = (SkillMask)(obj.SkillFlags & 0x7f);
        if (ContainsAny(label, "study cooking", "cookbook"))
            mask = (mask & ~(SkillMask.Mechanical | SkillMask.Study)) | SkillMask.Cooking;
        else if (ContainsAny(label, "study mechanical"))
            mask = (mask & ~(SkillMask.Cooking | SkillMask.Study)) | SkillMask.Mechanical;
        else if (ContainsAny(label, "study for school", "homework", "study"))
        {
            if (!ContainsAny(label, "cooking", "mechanical"))
                mask |= SkillMask.Study;
        }
        else if (ContainsAny(label, "practice speech", "charisma"))
            mask |= SkillMask.Charisma;
        else if (ContainsAny(label, "work out", "exercise"))
            mask |= SkillMask.Body;
        else if (ContainsAny(label, "chess", "telescope", "stargaze", "make potion"))
            mask |= SkillMask.Logic;
        else if (ContainsAny(label, "paint", "play piano", "play guitar", "practice music"))
            mask |= SkillMask.Creativity;
        else if (ContainsAny(label, "read a book", "read book"))
            mask &= ~(SkillMask.Cooking | SkillMask.Mechanical | SkillMask.Study);
        return mask;
    }

    public static float Delta(ReadOnlySpan<float> deltas, int motive) =>
        motive >= 0 && motive < deltas.Length ? deltas[motive] : 0f;

    public static bool ContainsAny(string? source, params ReadOnlySpan<string> needles)
    {
        if (string.IsNullOrEmpty(source))
            return false;
        foreach (var needle in needles)
        {
            if (source.Contains(needle, StringComparison.OrdinalIgnoreCase))
                return true;
        }
        return false;
    }
}
