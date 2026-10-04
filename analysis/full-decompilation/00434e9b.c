
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00434e9b(float *param_1)

{
  if ((DAT_00703e98 & 1) == 0) {
    DAT_00703e98 = DAT_00703e98 | 1;
    _DAT_00703e9c = (float)(SQRT((float10)_DAT_00666dc0) + SQRT((float10)_DAT_00666dc0));
  }
  return (float10)_DAT_00703e9c * (float10)*param_1;
}

