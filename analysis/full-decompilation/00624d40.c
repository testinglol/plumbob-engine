
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00624d40(double param_1,double param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)param_2 * (float10)_DAT_00678110 + (float10)param_1 + (float10)_DAT_00678108;
  if (fVar1 < (float10)_DAT_006669e8) {
    return (float10)_DAT_006669e8;
  }
  if ((float10)_DAT_006683b0 < fVar1) {
    fVar1 = (float10)_DAT_006683b0;
  }
  return fVar1;
}

