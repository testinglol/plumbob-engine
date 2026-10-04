
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_005c6fa0(float *param_1,float *param_2,float *param_3)

{
  while ((param_1 != param_2 &&
         ((_DAT_0067343c < ABS(*param_1 - *param_3) ||
          (_DAT_0067343c < ABS(param_1[1] - param_3[1])))))) {
    param_1 = param_1 + 2;
  }
  return param_1;
}

