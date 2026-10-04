
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00473454(float *param_1,float param_2)

{
  float fVar1;
  
  fVar1 = param_1[1];
  if (*param_1 - param_2 <= _DAT_0066657c) {
    fVar1 = -fVar1;
  }
  param_1[2] = fVar1;
  fVar1 = (float)__ftol();
  param_1[3] = fVar1;
  return;
}

