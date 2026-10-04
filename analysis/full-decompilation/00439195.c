
void FUN_00439195(uint param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *param_2;
  fVar2 = *param_3;
  *param_3 = 0.0;
  param_1 = param_1 & 7;
  *param_2 = 0.0;
  if (param_1 == 0) {
    *param_2 = fVar1;
    *param_3 = fVar2;
    return;
  }
  if (param_1 != 2) {
    if (param_1 == 4) {
      *param_2 = -fVar1;
    }
    else {
      if (param_1 != 6) {
        return;
      }
      *param_2 = fVar2;
      fVar2 = fVar1;
    }
    *param_3 = -fVar2;
    return;
  }
  *param_3 = fVar1;
  *param_2 = -fVar2;
  return;
}

