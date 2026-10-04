
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00513ade(int param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)(*(int *)(param_1 + 0x194) + 0x32) * (float10)_DAT_00667420;
  if ((float10)_DAT_0066657c <= fVar1) {
    if ((float10)_DAT_00666748 < fVar1) {
      fVar1 = (float10)1;
    }
  }
  else {
    fVar1 = (float10)0;
  }
  return (float10)1 - fVar1;
}

