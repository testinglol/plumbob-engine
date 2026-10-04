
void FUN_0053b99f(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int local_48;
  char *local_44;
  char *local_40;
  char *local_3c;
  char *local_38;
  undefined4 local_34;
  char *local_30;
  char *local_2c;
  char *local_28;
  char *local_24;
  undefined4 local_20;
  char *local_1c;
  char *local_18;
  char *local_14;
  char *local_10;
  undefined4 local_c;
  int local_8;
  
  if (param_1 != 0) {
    iVar1 = FUN_004425e2();
    if (param_1 == iVar1) {
      param_1 = 1;
    }
    else {
      iVar1 = FUN_0046d380();
      if (param_1 == iVar1) {
        param_1 = 2;
      }
      else {
        iVar1 = FUN_0046d386();
        param_1 = ((param_1 != iVar1) - 1 & 2) + 1;
      }
    }
  }
  if (param_2 != 0) {
    iVar1 = FUN_004425e2();
    if (param_2 == iVar1) {
      param_2 = 1;
    }
    else {
      iVar1 = FUN_0046d380();
      if (param_2 == iVar1) {
        param_2 = 2;
      }
      else {
        FUN_0046d386();
        param_2 = 3;
      }
    }
  }
  local_8 = 0;
  piVar3 = &local_8;
  if (-1 < param_1) {
    piVar3 = &param_1;
  }
  local_8 = 3;
  param_1 = *piVar3;
  piVar2 = &param_1;
  if (2 < *piVar3) {
    piVar2 = &local_8;
  }
  param_1 = 0;
  piVar3 = &param_1;
  if (-1 < param_2) {
    piVar3 = &param_2;
  }
  param_1 = 3;
  param_2 = *piVar3;
  piVar4 = &param_2;
  if (2 < *piVar3) {
    piVar4 = &param_1;
  }
  local_48 = 0;
  local_44 = s_UI_speed_Pto1_006cd430;
  local_40 = s_UI_speed_Pto2_006cd420;
  local_3c = s_UI_speed_Pto3_006cd410;
  local_38 = s_UI_speed_1toP_006cd400;
  local_34 = 0;
  local_30 = s_UI_speed_1to2_006cd3f0;
  local_2c = s_UI_speed_1to3_006cd3e0;
  local_28 = s_UI_speed_2toP_006cd3d0;
  local_24 = s_UI_speed_2to1_006cd3c0;
  local_20 = 0;
  local_1c = s_UI_speed_2to3_006cd3b0;
  local_18 = s_UI_speed_3toP_006cd3a0;
  local_14 = s_UI_speed_3to1_006cd390;
  local_10 = s_UI_speed_3to2_006cd380;
  local_c = 0;
  if ((&local_48)[*piVar4 + *piVar2 * 4] != 0) {
    FUN_0057a7f7((&local_48)[*piVar4 + *piVar2 * 4],0xfffffffc);
  }
  return;
}

