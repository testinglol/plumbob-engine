
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005939a0(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  
  if ((_DAT_006720e0 <= *param_1) || (*param_1 <= _DAT_00666a4c)) {
    if ((float)_DAT_006720d0 < ABS(*param_1 - _DAT_00666748)) {
      if (ABS(*param_1) <= (float)_DAT_006720d0) {
        fVar1 = *param_3;
        param_4[1] = param_3[1];
        fVar2 = param_3[3];
        param_4[2] = param_3[2];
        *param_4 = fVar1;
        param_4[3] = fVar2;
      }
    }
    else {
      fVar1 = *param_2;
      param_4[1] = param_2[1];
      fVar2 = param_2[2];
      *param_4 = fVar1;
      param_4[2] = fVar2;
      param_4[3] = param_2[3];
    }
  }
  else {
    fVar1 = (float)_DAT_00667280 - *param_1;
    if (param_3[1] * param_2[1] +
        param_2[2] * param_3[2] + param_2[3] * param_3[3] + *param_2 * *param_3 <
        (float)_DAT_006669e8) {
      fVar1 = -fVar1;
    }
    *param_4 = *param_1 * *param_2 + fVar1 * *param_3;
    param_4[1] = *param_1 * param_2[1] + fVar1 * param_3[1];
    param_4[2] = fVar1 * param_3[2] + param_2[2] * *param_1;
    param_4[3] = fVar1 * param_3[3] + param_2[3] * *param_1;
    fVar3 = (float10)FUN_005c48a0();
    if ((float10)_DAT_006720d8 < ABS(fVar3 - (float10)_DAT_00666748)) {
      if (ABS(fVar3) <= (float10)_DAT_006720d8) {
        param_4[2] = 0.0;
        param_4[1] = 0.0;
        *param_4 = 0.0;
        fVar3 = (float10)1;
      }
      else {
        fVar3 = (float10)_DAT_00666748 / SQRT(fVar3);
        *param_4 = (float)(fVar3 * (float10)*param_4);
        param_4[1] = (float)(fVar3 * (float10)param_4[1]);
        param_4[2] = (float)(fVar3 * (float10)param_4[2]);
        fVar3 = fVar3 * (float10)param_4[3];
      }
      param_4[3] = (float)fVar3;
    }
  }
  return;
}

