
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00611360(double param_1)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)param_1 * (float10)_DAT_00677628;
  if (fVar1 != (float10)_DAT_006669e8) {
    fVar2 = (float10)fsin(fVar1);
    return fVar2 / fVar1;
  }
  return (float10)_DAT_00667280;
}

