
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045928c(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  float10 fVar3;
  
  FUN_00634c24();
  uVar1 = (**(code **)*extraout_ECX)();
  uVar2 = (**(code **)(*extraout_ECX + 4))();
  FUN_0046ea4d();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0041337c(uVar1,uVar2);
  fVar3 = (float10)FUN_004132b3(s_min_autonomy_score_for_family_006c44f8,_DAT_00666a28,1);
  DAT_006c4374 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_min_autonomy_score_for_visitors_006c44d8,_DAT_00667370,1);
  DAT_006c4378 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_low_attenuation_006c44c8,_DAT_0066736c,1);
  _DAT_006c4d70 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_moderate_attenuation_006c44b0,_DAT_00667368,1);
  _DAT_006c4d74 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_high_attenuation_006c449c,_DAT_00666a38,1);
  _DAT_006c4d78 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_visitor_low_attenuation_006c4484,_DAT_0066736c,1);
  _DAT_006c4d7c = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_visitor_moderate_attenuation_006c4464,_DAT_00667368,1);
  _DAT_006c4d80 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_visitor_high_attenuation_006c4448,_DAT_00666a38,1);
  _DAT_006c4d84 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_min_autonomy_score_for_sitting_006c4428,_DAT_00666a28,1);
  _DAT_006c437c = (float)fVar3;
  FUN_004132b3(s_random_selection_count_006c4410,_DAT_00667364,1);
  DAT_006c4380 = __ftol();
  FUN_004132b3(s_friendship_threshold_006c43f8,_DAT_00667360,1);
  DAT_006c4388 = __ftol();
  fVar3 = (float10)FUN_004132b3(s_functional_distance_attenuation_006c43d8,_DAT_00666ccc,1);
  _DAT_006c4384 = (float)fVar3;
  FUN_004133a5(uVar1,uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  DAT_006e5241 = 1;
  FUN_00421179();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

