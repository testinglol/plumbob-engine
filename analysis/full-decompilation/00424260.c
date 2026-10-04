
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00424260(void)

{
  int iVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  float10 fVar3;
  
  FUN_00634c24();
  iVar1 = (**(code **)*extraout_ECX)();
  uVar2 = (**(code **)(*extraout_ECX + 4))();
  FUN_0046ea4d();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (iVar1 != 0) {
    FUN_0041337c(iVar1,uVar2);
  }
  fVar3 = (float10)FUN_004132b3(s_architecture_value_multiplier_006c2564,_DAT_00666cd4,1);
  _DAT_006e4a38 = (float)fVar3;
  FUN_004132b3(s_new_family_start_hour_006c254c,_DAT_00666a50,1);
  DAT_006e4a34 = __ftol();
  fVar3 = (float10)FUN_004132b3(s_perfect_family_friend_count_006c2530,_DAT_00666cd0,1);
  _DAT_006e4a30 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_weight_of_house_size_in_overall_s_006c2508,_DAT_00666ccc,1);
  _DAT_006e4a2c = (float)fVar3;
  FUN_004132b3(s_fill_value_for_layout_history_006c24e8,_DAT_00666cc8,1);
  DAT_006e4a28 = __ftol();
  FUN_004132b3(s_money_for_new_family_006c24d0,_DAT_00666cc4,1);
  DAT_006e4a24 = __ftol();
  fVar3 = (float10)FUN_004132b3(s_yard_score_multiplier_006c24b8,_DAT_00666cc0,1);
  _DAT_006e4a20 = (float)fVar3;
  FUN_004132b3(s_upkeep_penalty_per_dirty_object_006c2498,_DAT_00666cbc,1);
  _DAT_006e4a1c = __ftol();
  FUN_004132b3(s_upkeep_penalty_per_broken_object_006c2474,_DAT_00666cd0,1);
  _DAT_006e4a18 = __ftol();
  if (iVar1 != 0) {
    FUN_004133a5(iVar1,uVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00421179();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

