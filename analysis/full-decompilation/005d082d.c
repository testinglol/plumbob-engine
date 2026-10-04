
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_005d082d(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  float *pfVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  float10 fVar5;
  undefined1 local_10 [12];
  
  param_1[1] = 0;
  param_1[2] = param_2;
  *param_1 = &PTR_LAB_006734fc;
  _memset(param_1 + 10,0,0x50);
  param_1[10] = 0x50;
  uVar2 = _DAT_00666a60;
  param_1[0xb] = param_3;
  param_1[0x1e] = uVar2;
  param_1[0x1f] = uVar2;
  param_1[0x20] = 0;
  uVar2 = _DAT_0066674c;
  param_1[0x21] = _DAT_0066674c;
  param_1[0x22] = uVar2;
  param_1[0x23] = 0;
  FUN_0049b802();
  param_1[7] = 0x3f800000;
  param_1[6] = 0x3f800000;
  param_1[5] = 0x3f800000;
  param_1[4] = 1.0;
  param_1[8] = 0x3f800000;
  param_1[0x10] = param_1[0x1e];
  param_1[0x11] = param_1[0x1f];
  param_1[0x12] = param_1[0x20];
  puVar4 = (undefined4 *)FUN_005d0c16(local_10,param_1 + 0x21);
  uVar3 = _DAT_006734f0;
  param_1[0x13] = *puVar4;
  param_1[0x14] = puVar4[1];
  param_1[0x15] = puVar4[2];
  fVar5 = (float10)FUN_00636264(uVar3);
  param_1[0x16] = (float)fVar5;
  pfVar1 = (float *)(param_1 + 0xc);
  param_1[0x17] = 0;
  param_1[0x18] = 0x3f800000;
  *pfVar1 = (float)param_1[4];
  param_1[0x19] = 0;
  param_1[0xd] = param_1[5];
  param_1[0x1a] = 0;
  param_1[0x1b] = 0x3ecccccd;
  param_1[0x1c] = 0x3f000000;
  param_1[0xe] = param_1[6];
  param_1[0xf] = param_1[7];
  param_1[3] = 0;
  param_1[9] = 0;
  param_1[0x1d] = 3;
  *pfVar1 = *pfVar1 * (float)param_1[8];
  param_1[0xd] = (float)param_1[0xd] * (float)param_1[8];
  param_1[0xe] = (float)param_1[0xe] * (float)param_1[8];
  param_1[0xf] = (float)param_1[0xf] * (float)param_1[8];
  return param_1;
}

