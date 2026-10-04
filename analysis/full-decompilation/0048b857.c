
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048b857(int *param_1)

{
  float fVar1;
  
  fVar1 = (float)*param_1 * _DAT_00667278;
  if (_DAT_00666578 <= (float)param_1[1] * _DAT_00667278 - (float)(param_1[1] >> 4)) {
    param_1[1] = param_1[1] + 0x10;
  }
  if (_DAT_00666578 <= fVar1 - (float)(*param_1 >> 4)) {
    *param_1 = *param_1 + 0x10;
  }
  FUN_004860a0();
  return;
}

