
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00624d80(double param_1,double param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)param_2;
  if (fVar1 < (float10)_DAT_006669e8) {
    return (fVar1 + (float10)_DAT_00666740) * (float10)param_1 * (float10)_DAT_00667260;
  }
  if ((float10)_DAT_00678118 < fVar1) {
    fVar1 = (float10)_DAT_00678118;
  }
  return ((float10)param_1 * (float10)_DAT_00666740) / ((float10)_DAT_00666740 - fVar1);
}

