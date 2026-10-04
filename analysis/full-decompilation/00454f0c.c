
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00454f0c(float *param_1,float *param_2,float *param_3,undefined4 param_4)

{
  float10 fVar1;
  float fVar2;
  float10 fVar3;
  
  if ((DAT_00703e90 & 1) == 0) {
    _DAT_00703e94 = _DAT_00667240 * _DAT_00667278;
    DAT_00703e90 = DAT_00703e90 | 1;
  }
  fVar2 = _DAT_00703e94 * *param_2;
  fVar3 = (float10)FUN_00454f69(param_4);
  fVar1 = (float10)_DAT_00667240;
  *param_1 = _DAT_00703e94 * *param_3;
  param_1[2] = fVar2;
  param_1[1] = (float)(fVar3 * fVar1);
  return;
}

