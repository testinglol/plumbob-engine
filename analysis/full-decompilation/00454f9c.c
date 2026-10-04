
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00454f9c(float *param_1,int *param_2,undefined4 param_3)

{
  float10 fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  
  if ((DAT_00703e80 & 1) == 0) {
    _DAT_00703e84 = _DAT_00667240 * _DAT_00667278;
    DAT_00703e80 = DAT_00703e80 | 1;
  }
  fVar2 = (float)param_2[1] * _DAT_00703e84;
  fVar4 = (float10)FUN_00454f69(param_3);
  fVar1 = (float10)_DAT_00667240;
  fVar3 = (float)*param_2 * _DAT_00703e84;
  param_1[2] = fVar2;
  *param_1 = fVar3;
  param_1[1] = (float)(fVar4 * fVar1);
  return;
}

