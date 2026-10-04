
void __thiscall FUN_0050c54c(float *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  float *pfVar1;
  undefined1 local_18 [4];
  float local_14;
  float local_10;
  uint local_c;
  undefined4 uStack_8;
  
  param_1[1] = (float)(param_2 >> 8 & 0xff);
  param_1[2] = (float)(param_2 & 0xff);
  *param_1 = (float)(param_2 >> 0x10 & 0xff);
  local_c = param_3 & 0xff;
  local_14 = (float)(param_3 >> 8 & 0xff);
  uStack_8 = 0;
  local_10 = (float)local_c;
  param_1[4] = local_14;
  param_1[3] = (float)(param_3 >> 0x10 & 0xff);
  param_1[5] = local_10;
  pfVar1 = (float *)FUN_0049b849(local_18,param_1 + 3,param_1);
  param_1[6] = *pfVar1;
  param_1[7] = pfVar1[1];
  param_1[8] = pfVar1[2];
  FUN_004734bd(0,0x3f800000,param_4,DAT_006e5490);
  return;
}

