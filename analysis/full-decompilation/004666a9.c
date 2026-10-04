
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004666a9(void)

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
  fVar3 = (float10)FUN_004132b3(s_object_light_contribution_factor_006c496c,_DAT_00667660,1);
  _DAT_006c4758 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_area_clip_to_score_006c4958,_DAT_00666a10,1);
  _DAT_006e53d4 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_area_score_for_zero_tiles_006c493c,_DAT_0066765c,1);
  _DAT_006e53d0 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_area_score_for_clip_tile_006c4920,_DAT_00667660,1);
  *(float *)(unaff_EBP + -0x10) = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_light_score_for_0_0_006c490c,_DAT_00667658,1);
  _DAT_006e53c8 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_light_score_for_1_0_006c48f8,_DAT_00667654,1);
  *(float *)(unaff_EBP + -0x14) = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_room_impact_effective_area_min_006c48d8,_DAT_00667364,1);
  _DAT_006e53c0 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_room_impact_effective_area_max_006c48b8,_DAT_00667430,1);
  _DAT_006e53bc = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_room_impact_multiplier_006c48a0,_DAT_00667364,1);
  _DAT_006e53b8 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_outdoor_room_impact_factor_006c4884,_DAT_0066740c,1);
  _DAT_006e53b4 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_outdoor_good_object_count_factor_006c4860,0x3f800000,1);
  _DAT_006e53b0 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_outdoor_object_divisor_006c4848,_DAT_00666ccc,1);
  _DAT_006e53ac = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_outdoor_daylight_bonus_006c4830,0,1);
  _DAT_006e53a8 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_outdoor_dawn_dusk_bonus_006c4818,_DAT_00667658,1);
  _DAT_006e53a4 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_outdoor_nighttime_bonus_006c4800,_DAT_00667650,1);
  _DAT_006e53a0 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_floor_score_for_0__006c47ec,_DAT_0066764c,1);
  _DAT_006e5398 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_floor_score_for_100__006c47d4,0,1);
  *(float *)(unaff_EBP + -0x18) = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_wall_score_for_0__006c47c0,_DAT_0066764c,1);
  _DAT_006e5390 = (float)fVar3;
  fVar3 = (float10)FUN_004132b3(s_wall_score_for_100__006c47ac,0,1);
  _DAT_006e53cc = *(float *)(unaff_EBP + -0x10) - _DAT_006e53d0;
  _DAT_006e53c4 = *(float *)(unaff_EBP + -0x14) - _DAT_006e53c8;
  _DAT_006e5394 = (float)(fVar3 - (float10)_DAT_006e5390);
  _DAT_006e539c = *(float *)(unaff_EBP + -0x18) - _DAT_006e5398;
  if (iVar1 != 0) {
    FUN_004133a5(iVar1,uVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00421179();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

