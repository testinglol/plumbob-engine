
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005cf0bd(int param_1)

{
  float fVar1;
  
  fVar1 = _DAT_00666578;
  *(float *)(param_1 + 0x18) = (float)*(uint *)(param_1 + 0x10) * _DAT_00666578;
  *(float *)(param_1 + 0x1c) = (float)*(uint *)(param_1 + 0x14) * fVar1;
  *(undefined4 *)(param_1 + 0x20) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x24) = 0x3f800000;
  return;
}

