
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0049c12a(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)_DAT_00667280 / (param_3 * param_3);
  fVar2 = (float)_DAT_006683b0 / ((float)_DAT_00667280 / (param_2 * param_2) - fVar1);
  *param_1 = fVar2;
  param_1[1] = -(fVar2 * fVar1);
  return;
}

