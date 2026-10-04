
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005c47e0(float *param_1,float *param_2)

{
  float fVar1;
  
  fVar1 = _DAT_00666748 / *param_2;
  *param_1 = fVar1 * *param_1;
  param_1[1] = fVar1 * param_1[1];
  param_1[2] = fVar1 * param_1[2];
  return;
}

