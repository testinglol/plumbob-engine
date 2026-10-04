
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00612b70(double param_1,double param_2,double param_3)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = SQRT((float10)param_2 * (float10)param_2 + (float10)param_1 * (float10)param_1);
  fVar2 = (float10)fcos(fVar1 * (float10)_DAT_00677678);
  return fVar2 / (fVar1 * fVar1 * (float10)param_3 + (float10)_DAT_00667280);
}

