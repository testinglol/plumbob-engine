
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00619420(double param_1,double param_2,double param_3)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar2 = (float10)1.4426950408889634 *
          ((((float10)param_2 * (float10)param_2 + (float10)param_1 * (float10)param_1) *
           (float10)_DAT_00667df0) / ((float10)param_3 * (float10)param_3));
  fVar1 = ROUND(fVar2);
  fVar2 = (float10)f2xm1(fVar2 - fVar1);
  fVar1 = (float10)fscale((float10)1 + fVar2,fVar1);
  return ((float10)_DAT_00667280 / ((float10)param_3 * (float10)param_3 * (float10)_DAT_00677b18)) *
         fVar1;
}

