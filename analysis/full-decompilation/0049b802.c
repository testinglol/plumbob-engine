
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * __fastcall FUN_0049b802(float *param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_0049b828();
  fVar1 = (float10)_DAT_00666748 / fVar1;
  *param_1 = (float)(fVar1 * (float10)*param_1);
  param_1[1] = (float)(fVar1 * (float10)param_1[1]);
  param_1[2] = (float)(fVar1 * (float10)param_1[2]);
  return param_1;
}

