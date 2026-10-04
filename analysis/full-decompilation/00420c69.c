
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00420c69(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *extraout_ECX;
  int iVar6;
  int unaff_EBP;
  float10 fVar7;
  
  FUN_00634c24();
  uVar4 = (**(code **)*extraout_ECX)();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
  iVar6 = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  do {
    FUN_0046ea4d();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar6 == 1) {
      *(undefined4 *)(unaff_EBP + -0x10) = 5;
    }
    else if (iVar6 == 2) {
      *(undefined4 *)(unaff_EBP + -0x10) = 6;
    }
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      FUN_0041337c(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x10));
    }
    fVar7 = (float10)FUN_004132b3(s_energy_span_006c23dc,_DAT_00666a58,1);
    (&DAT_006e49dc)[iVar6] = (float)fVar7;
    FUN_004132b3(s_wake_hours_006c23d0,_DAT_00666a54,1);
    uVar5 = __ftol();
    uVar4 = _DAT_00666a50;
    (&DAT_006e49d0)[iVar6] = uVar5;
    FUN_004132b3(s_wake_hour_006c23c4,uVar4,1);
    uVar5 = __ftol();
    uVar4 = _DAT_00666a4c;
    (&DAT_006e49a0)[iVar6] = uVar5;
    fVar7 = (float10)FUN_004132b3(s_energy_drift_006c23b4,uVar4,1);
    (&DAT_006e4988)[iVar6] = (float)fVar7;
    fVar7 = (float10)FUN_004132b3(s_hunger_to_bladder_multiplier_006c2394,_DAT_00666a48,1);
    (&DAT_006e497c)[iVar6] = (float)fVar7;
    fVar7 = (float10)FUN_004132b3(s_comfort_decrement_active_006c2378,_DAT_00666a44,1);
    *(float *)(unaff_EBP + -0x24) = (float)fVar7;
    *(float *)(unaff_EBP + -0x3c + iVar6 * 4) = (float)fVar7;
    fVar7 = (float10)FUN_004132b3(s_comfort_decrement_lazy_006c2360,_DAT_00666a40,1);
    *(float *)(unaff_EBP + -0x1c) = (float)fVar7;
    *(float *)(unaff_EBP + -0x48 + iVar6 * 4) = (float)fVar7;
    fVar7 = (float10)FUN_004132b3(s_hunger_decrement_ratio_006c2348,_DAT_00666a3c,1);
    (&DAT_006e4958)[iVar6] = (float)fVar7;
    fVar7 = (float10)FUN_004132b3(s_social_decrement_base_006c2330,_DAT_00666a38,1);
    (&DAT_006e494c)[iVar6] = (float)fVar7;
    fVar7 = (float10)FUN_004132b3(s_social_decrement_multiplier_006c2314,_DAT_00666a34,1);
    (&DAT_006e4940)[iVar6] = (float)fVar7;
    fVar7 = (float10)FUN_004132b3(s_ent_decrement__awake_006c22fc,_DAT_00666a48,1);
    (&DAT_006e4934)[iVar6] = (float)fVar7;
    fVar7 = (float10)FUN_004132b3(s_ent_multiplier__asleep_006c22e4,_DAT_00666578,1);
    (&DAT_006e4928)[iVar6] = (float)fVar7;
    fVar7 = (float10)FUN_004132b3(s_hyg_decrement__awake_006c22cc,_DAT_00666a30,1);
    (&DAT_006e491c)[iVar6] = (float)fVar7;
    fVar7 = (float10)FUN_004132b3(s_hyg_decrement__asleep_006c22b4,_DAT_00666a38,1);
    (&DAT_006e4910)[iVar6] = (float)fVar7;
    fVar7 = (float10)FUN_004132b3(s_bladder_decrement__awake_006c2298,_DAT_00666a2c,1);
    (&DAT_006e4904)[iVar6] = (float)fVar7;
    fVar7 = (float10)FUN_004132b3(s_bladder_decrement__asleep_006c227c,_DAT_00666a28,1);
    iVar3 = (&DAT_006e49d0)[iVar6];
    (&DAT_006e48f8)[iVar6] = (float)fVar7;
    (&DAT_006e4994)[iVar6] = (&DAT_006e49a0)[iVar6] + iVar3;
    *(int *)(unaff_EBP + -0x20) = 0x18 - iVar3;
    *(int *)(unaff_EBP + -0x18) = iVar3;
    iVar3 = *(int *)(unaff_EBP + -0x20);
    (&DAT_006e49c4)[iVar6] = (float)iVar3;
    fVar1 = _DAT_006e49e8;
    if ((iVar6 == 1) || (iVar6 == 2)) {
      (&DAT_006e49b8)[iVar6] = -((float)(&DAT_006e49dc)[iVar6] / _DAT_006e49e8);
      (&DAT_006e49ac)[iVar6] = (float)*(int *)(unaff_EBP + -0x18) / fVar1;
    }
    else {
      (&DAT_006e49b8)[iVar6] =
           -(((float)(&DAT_006e49dc)[iVar6] / (float)*(int *)(unaff_EBP + -0x18)) / _DAT_006e49e8);
      (&DAT_006e49ac)[iVar6] = ((float)(&DAT_006e49dc)[iVar6] / (float)iVar3) / fVar1;
    }
    fVar1 = *(float *)(unaff_EBP + -0x24);
    fVar2 = *(float *)(unaff_EBP + -0x1c);
    iVar3 = *(int *)(unaff_EBP + -0x14);
    (&DAT_006e4970)[iVar6] = *(undefined4 *)(unaff_EBP + -0x1c);
    (&DAT_006e4964)[iVar6] = (fVar1 - fVar2) * _DAT_00666a24;
    if (iVar3 != 0) {
      FUN_004133a5(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + -0x10));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00421179();
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3);
  DAT_006e49ec = 1;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

