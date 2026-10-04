
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00596037(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  float local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  float local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  fVar1 = *param_1;
  fVar2 = param_1[1];
  local_10 = param_1[2];
  local_24 = fVar1 * fVar1 * _DAT_0066740c;
  local_1c = fVar2 * _DAT_0066740c * fVar2;
  fVar3 = local_10 * _DAT_0066740c;
  local_20 = fVar3 * local_10;
  local_18 = fVar2 * _DAT_0066740c * fVar1;
  local_14 = fVar3 * fVar1;
  local_c = param_1[3] * _DAT_0066740c;
  local_8 = local_c * fVar2;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0x3f800000;
  local_54 = local_14 - local_8;
  local_50 = fVar3 * fVar2 + fVar1 * local_c;
  local_4c = ((float)_DAT_00667280 - local_24) - local_1c;
  local_48 = 0;
  local_64 = local_c * local_10 + local_18;
  local_60 = ((float)_DAT_00667280 - local_24) - local_20;
  local_5c = fVar3 * fVar2 - fVar1 * local_c;
  local_58 = 0;
  local_44 = ((float)_DAT_00667280 - local_1c) - local_20;
  local_40 = local_18 - local_c * local_10;
  local_3c = local_8 + local_14;
  local_38 = 0;
  uVar4 = FUN_00462e7a(&local_44,&local_64,&local_54,&local_34);
  iVar5 = FUN_005c3650(uVar4);
  FUN_00462f2f(iVar5);
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(iVar5 + 0x40);
  FUN_005c4890();
  return;
}

