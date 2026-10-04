
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0061f110(double param_1,double param_2,double param_3)

{
  float10 fVar1;
  
  fVar1 = (float10)param_3;
  if (fVar1 < (float10)_DAT_006669e8) {
    do {
      fVar1 = fVar1 + (float10)_DAT_00677778;
    } while (fVar1 < (float10)_DAT_006669e8);
  }
  if ((float10)_DAT_00677778 <= fVar1) {
    do {
      fVar1 = fVar1 - (float10)_DAT_00677778;
    } while ((float10)_DAT_00677778 <= fVar1);
  }
  if (fVar1 < (float10)_DAT_00677dd8) {
    return ((float10)param_2 - (float10)param_1) * fVar1 * (float10)_DAT_00677df8 + (float10)param_1
    ;
  }
  if (fVar1 < (float10)_DAT_00677df0) {
    return (float10)param_2;
  }
  if (fVar1 < (float10)_DAT_00677de8) {
    return ((float10)_DAT_00677de8 - fVar1) * ((float10)param_2 - (float10)param_1) *
           (float10)_DAT_00677df8 + (float10)param_1;
  }
  return (float10)param_1;
}

