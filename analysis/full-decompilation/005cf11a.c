
undefined4 __thiscall FUN_005cf11a(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_44 = *(undefined4 *)(param_1 + 0x18);
  local_24 = (float)*(uint *)(param_1 + 8) + *(float *)(param_1 + 0x18);
  local_20 = (float)*(uint *)(param_1 + 0xc) + *(float *)(param_1 + 0x1c);
  local_1c = 0;
  local_18 = 0x3f800000;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  uStack_8 = 0;
  local_34 = 0;
  local_30 = -*(float *)(param_1 + 0x1c);
  local_2c = 0;
  local_28 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  uVar1 = FUN_00462e7a(&local_44,&local_34,&local_14,&local_24);
  FUN_005c3650(uVar1);
  return param_2;
}

