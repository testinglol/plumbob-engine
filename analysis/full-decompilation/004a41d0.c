
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004a41d0(undefined4 *param_1)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)(*(code *)param_1[1])(0);
  fVar2 = (float10)(*(code *)*param_1)(0);
  if (ABS(fVar2 - (float10)(float)fVar1) <= (float10)_DAT_0067343c) {
    fVar1 = (float10)(*(code *)param_1[2])(0);
    fVar2 = (float10)(*(code *)param_1[1])(0x3f800000);
    if (ABS(fVar2 - (float10)(float)fVar1) <= (float10)_DAT_0067343c) {
      fVar1 = (float10)(*(code *)param_1[3])(0x3f800000);
      fVar2 = (float10)(*(code *)param_1[2])(0x3f800000);
      if (ABS(fVar2 - (float10)(float)fVar1) <= (float10)_DAT_0067343c) {
        fVar1 = (float10)(*(code *)*param_1)(0x3f800000);
        fVar2 = (float10)(*(code *)param_1[3])(0);
        if (ABS(fVar2 - (float10)(float)fVar1) <= (float10)_DAT_0067343c) {
          return 1;
        }
      }
    }
  }
  return 0;
}

