
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_004732bf(undefined4 *param_1)

{
  float10 fVar1;
  
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 0x19) = 0;
  param_1[5] = 0;
  if (_DAT_006e5478 < _DAT_00667280) {
    fVar1 = (float10)FUN_004732f4();
    _DAT_006e5478 = (double)fVar1;
  }
  *param_1 = 0;
  return param_1;
}

