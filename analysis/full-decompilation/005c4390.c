
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005c4390(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = _DAT_00666748 /
          (param_2[7] * param_1[1] + param_2[0xb] * param_1[2] + param_2[3] * *param_1 +
          param_2[0xf]);
  *param_3 = (*param_1 * *param_2 + param_2[4] * param_1[1] + param_2[8] * param_1[2] + param_2[0xc]
             ) * fVar1;
  param_3[1] = (param_2[5] * param_1[1] + param_2[9] * param_1[2] + param_2[1] * *param_1 +
               param_2[0xd]) * fVar1;
  param_3[2] = (param_2[6] * param_1[1] + param_2[10] * param_1[2] + param_2[2] * *param_1 +
               param_2[0xe]) * fVar1;
  return;
}

