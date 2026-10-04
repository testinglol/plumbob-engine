
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ca6b6(float *param_1,float *param_2,float *param_3,undefined4 param_4)

{
  float10 fVar1;
  float fVar2;
  float10 fVar3;
  
  if ((DAT_00703e70 & 1) == 0) {
    DAT_00703e70 = DAT_00703e70 | 1;
    _DAT_00703e74 = DAT_00668988;
  }
  fVar2 = _DAT_00703e74 * *param_2;
  fVar3 = (float10)FUN_00454f69(param_4);
  fVar1 = (float10)DAT_00668988;
  *param_1 = _DAT_00703e74 * *param_3;
  param_1[2] = fVar2;
  param_1[1] = (float)(fVar3 * fVar1);
  return;
}

