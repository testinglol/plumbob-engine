
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00463da6(int param_1,short param_2)

{
  float fVar1;
  
  fVar1 = _DAT_0066657c;
  if (0 < param_2) {
    if ((uint)(int)param_2 <= (uint)(*(int *)(param_1 + 0x1b0) - *(int *)(param_1 + 0x1ac) >> 2)) {
      fVar1 = *(float *)(*(int *)(param_1 + 0x1ac) + -4 + param_2 * 4);
    }
  }
  return (float10)fVar1;
}

