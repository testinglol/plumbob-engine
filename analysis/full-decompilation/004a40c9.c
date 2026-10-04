
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004a40c9(float *param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar1 = *param_1;
  fVar2 = param_1[1];
  fVar3 = (float10)(*(code *)param_2[1])(fVar2);
  fVar4 = (float10)(*(code *)*param_2)(fVar1);
  fVar5 = (float10)(*(code *)param_2[3])(fVar2);
  fVar6 = (float10)(*(code *)param_2[2])(fVar1);
  fVar3 = (float10)_DAT_00667280 -
          (fVar6 * (float10)fVar2 +
          (float10)(float)(fVar5 * (float10)fVar1 +
                          (float10)(float)(((float10)1 - (float10)fVar2) * fVar4 +
                                          (float10)(float)(((float10)1 - (float10)fVar1) * fVar3))))
          * (float10)_DAT_00667270;
  if ((float10)_DAT_0066657c <= fVar3) {
    if ((float10)_DAT_00666748 < fVar3) {
      fVar3 = (float10)1;
    }
  }
  else {
    fVar3 = (float10)0;
  }
  return fVar3;
}

