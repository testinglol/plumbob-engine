
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c9cba(float *param_1)

{
  float10 fVar1;
  
  if ((uint)DAT_006e5490 < (uint)param_1[3]) {
    fVar1 = (float10)FUN_00473496(DAT_006e5490);
  }
  else {
    param_1[8] = 0.0;
    fVar1 = (float10)*param_1;
  }
  if (fVar1 < (float10)_DAT_0066657c) {
    __ftol();
    return;
  }
  __ftol();
  return;
}

