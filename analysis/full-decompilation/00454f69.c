
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00454f69(float *param_1)

{
  if ((DAT_00703e88 & 1) == 0) {
    DAT_00703e88 = DAT_00703e88 | 1;
    _DAT_00703e8c =
         (float)((float10)_DAT_00667280 /
                (SQRT((float10)_DAT_00666dc0) + SQRT((float10)_DAT_00666dc0)));
  }
  return (float10)_DAT_00703e8c * (float10)*param_1;
}

