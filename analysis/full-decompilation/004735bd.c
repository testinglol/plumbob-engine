
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004735bd(float *param_1,float param_2)

{
  float10 fVar1;
  
  if ((param_1[6] == 0.0) || ((uint)param_2 < (uint)param_1[5])) {
    fVar1 = (float10)FUN_00636d14((double)(uint)((int)param_2 - (int)param_1[4]) *
                                  *(double *)(param_1 + 2));
    fVar1 = fVar1 * (float10)*param_1;
  }
  else {
    fVar1 = (float10)_DAT_0066657c;
  }
  return fVar1;
}

