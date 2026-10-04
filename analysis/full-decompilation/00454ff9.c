
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00454ff9(undefined4 *param_1,float *param_2)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((DAT_00703e78 & 1) == 0) {
    _DAT_00703e7c = _DAT_00666a54 / _DAT_00667240;
    DAT_00703e78 = DAT_00703e78 | 1;
  }
  fVar1 = _DAT_00703e7c * param_2[2];
  if ((float)_DAT_006669e8 <= fVar1) {
    FUN_006369f9((double)(fVar1 + _DAT_00666578));
  }
  else {
    FUN_00636ac8((double)(fVar1 - _DAT_00666578));
  }
  fVar1 = _DAT_00703e7c * *param_2;
  if ((float)_DAT_006669e8 <= fVar1) {
    FUN_006369f9((double)(fVar1 + _DAT_00666578));
  }
  else {
    FUN_00636ac8((double)(fVar1 - _DAT_00666578));
  }
  uVar2 = __ftol();
  uVar3 = __ftol();
  *param_1 = uVar3;
  param_1[1] = uVar2;
  return;
}

