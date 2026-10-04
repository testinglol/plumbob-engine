
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c9cf3(int param_1)

{
  float10 fVar1;
  
  if (DAT_006e5490 < *(uint *)(param_1 + 0x1c)) {
    fVar1 = (float10)FUN_00473496(DAT_006e5490);
  }
  else {
    *(undefined4 *)(param_1 + 0x20) = 0;
    fVar1 = (float10)*(float *)(param_1 + 0x10);
  }
  if (fVar1 < (float10)_DAT_0066657c) {
    __ftol();
    return;
  }
  __ftol();
  return;
}

